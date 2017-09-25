/* Cogswell Now webservice
* Author: Jared De La Cruz
*/

//------------------------------Setup
//---MongoDB
console.log('Initializing MongoDB...');
var mongoose = require('mongoose');
mongoose.connect('mongodb://localhost/cogswell');
var options = {
  user: 'nodejitsu',
  pass: '4886906eccf5fd8012c3c8486691a8b1'
};
//mongoose.connect('mongodb://nodejitsu:4886906eccf5fd8012c3c8486691a8b1@paulo.mongohq.com:10073/nodejitsudb2829246723', options);

var db = mongoose.connection;
db.on('error', console.error.bind(console, 'connection error:'));
db.once('open', function callback () {
  console.log('MongoDB connected.');
});

var userSchema = mongoose.Schema({
  email: {type: String, required: true, unique: true},
  password: {type: String, required: true},
  program: {type: String},
  type: {type: String, required: true, default: 'user'},
  first: {type: String, required: true},
  last: {type: String, required: true},
  updated: {type: Date, default: Date.now},
  created: {type: Date, required: true},
});
var User = mongoose.model('User', userSchema);

var blogSchema = mongoose.Schema({
  title:  {type: String, required: true},
  author: {type: String, required: true},
  body:   {type: String, required: true},
  owner:  {type: String, required: true},
  comments: [{owner: String, author: String, body: String, date: Date}],
  date: {type: Date, default: Date.now},
  votes: {type: String},
  type: {type: String},
  tags: [{type: String}]
});
var Blog = mongoose.model('Blog', blogSchema);

var forumSchema = mongoose.Schema({
  title:  {type: String, required: true},
  author: {type: String, required: true},
  body:   {type: String, required: true},
  owner:  {type: String, required: true},
  comments: [{owner: String, author: String, body: String, date: Date}],
  date: {type: Date, default: Date.now},
  votes: {type: String},
  type: {type: String},
  tags: [{type: String}]
});
var Forum = mongoose.model('Forum', forumSchema);

//---ExpressJS
console.log('Initializing Express...');
var express = require('express');
var app = express();

//---Middleware: Allows cross-domain requests (CORS)
var allowCrossDomain = function(req, res, next){
  res.header('Access-Control-Allow-Origin', '*');
  res.header('Access-Control-Allow-Methods', 'GET,PUT,POST,DELETE');
  res.header('Access-Control-Allow-Headers', 'Content-Type');
  next();
};

///---MemoryStore
//var MemoryStore = express.session.MemoryStore;

//---App config
app.configure(function() {
  var pub_dir = __dirname + '/public';
  app.set('views', __dirname + '/views');
  app.set('view engine', 'jade');
  app.set("trust proxy", true);
  app.use(express.favicon(__dirname+'/favicon.ico'));
  app.use(express.compress());
  app.use(express.bodyParser());
  app.use(express.cookieParser());
  app.use(express.session({secret: 'cogswell'}));
  app.use(express.methodOverride());
  app.use(allowCrossDomain);
  app.use(app.router);
  app.use(express.static(__dirname));
});

//------------------------------Endpoints
//---GET
app.get('/get.blog', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  getBlog(req, res);
});
app.get('/get.blog.count', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  getBlogCount(req, res);
});
app.get('/get.forum', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  getForum(req, res);
});
app.get('/get.forum.count', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  getForumCount(req, res);
});
app.get('/get.account', function (req, res, nex){
  console.log('Request to: '+req.path+' from: '+req.ip);
  getAccount(req, res);
});
//---POST
app.post('/post.user', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  postUser(req, res);
});
app.post('/post.login', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  postLogin(req, res);
});
app.post('/post.blog.post', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  postBlogPost(req, res);
});
app.post('/post.forum.post', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  postForumPost(req, res);
});
app.post('/post.forum.comment', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  postForumComment(req, res);
});
app.post('/del.forum.post', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  delForumPost(req, res);
});
app.post('/del.forum.comment', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  delForumComment(req, res);
});
app.post('/post.account', function (req, res, next){
  console.log('Request to: '+req.path+' from: '+req.ip);
  postAccount(req, res);
});

//---Start listening
var port = 8080;
app.listen(port);
console.log('Webservice started on port: '+port);
initialSetup();

//------------------------------Functions
function createHash()
{
  //---Cryptography
  var crypto = require('crypto');
  var sha256 = crypto.createHash('sha256');
  var salt = 'cogswell';
  return sha256;
}

function getBlog(req, res)
{
  var pageLimit = 10;
  var page = req.query.page;

  Blog.find().sort({$natural: -1}).skip(page*pageLimit).limit(pageLimit).exec(function (err, results) {
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err.err);
    }
    else
    {
      res.json(results);
    }
  });
}

function getBlogCount(req, res)
{
  Blog.count({}, function(err, count){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err.err);
    }
    else
    {
      res.json(200, {response: "success", count: count});
    }
  });
}

function getForum(req, res)
{
  var pageLimit = 10;
  var page = req.query.page;

  Forum.find().sort({$natural: -1}).skip(page*pageLimit).limit(pageLimit).exec(function (err, results) {
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err.err);
    }
    else
    {
      res.json(results);
    }
  });
}

function getForumCount(req, res)
{
   Forum.count({}, function(err, count){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err.err);
    }
    else
    {
      res.json(200, {response: "success", count: count});
    }
  });
}

function getAccount(req, res)
{
  User.findOne({
    email: req.query.email,
  }, function (err, results){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err);
    }
    else
    {
      var response = {response: "success"};
      response.email = results.email;
      response.first = results.first;
      response.last = results.last;
      response.program = results.program;
      response.updated = results.updated;
      response.created = results.created;
      res.json(200, response);
    }
  });
}

function postAccount(req, res)
{
  User.update({
    email: req.body['form-account-email']
    }, {$set: {
      first: req.body['form-account-fname'],
      last: req.body['form-account-lname'],
      program: req.body['form-account-program']},
    }, function (err, affected){
      if(err)
      {
        res.json(200, {response: "failure"});
        console.log(err.err);
      }
      else
      {
         var response = {response: "success"};
         res.json(200, response);
      }
    }
  );

}

function postUser(req, res)
{
  //---Cryptography
  var crypto = require('crypto');
  var sha256 = crypto.createHash('sha256');
  var salt = 'cogswell';
  var hashpass = sha256.update(salt+req.body['form-register-pass']).digest("hex");

  var datetime = new Date();
  User.create({
    email: req.body['form-register-email'],
    password: hashpass,
    type: "user",
    first: req.body['form-register-fname'],
    last: req.body['form-register-lname'],
    created: datetime,
  }, function (err, results){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err.err);
    }
    else
    {
      res.json(200, {response: "success"});
      console.log("User registered: "+results.fname+" "+results.lname+" - "+results.email);
    }
  });
}

function postLogin(req, res)
{
  //---Cryptography
  var crypto = require('crypto');
  var sha256 = crypto.createHash('sha256');
  var salt = 'cogswell';
  var hashpass = sha256.update(salt+req.body['form-signin-pass']).digest("hex");

  User.findOne({
    email: req.body['form-signin-email'],
    password: hashpass,
  }, function (err, results){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err.err);
    }
    else if(!results)
    {
      res.json(200, {response: "failure"});
      console.log("Login failed");
    }
    else
    {
      var datetime = new Date();
      User.update({
        email: results.email
      }, {$set: {updated: datetime}
      }, function (err, affected){
          if(err)
          {
            console.log(err);
          }
        }
      );

      var hash = createHash();
      var response = {response: "success"};
      response.email = results.email;
      response.owner = hash.update(results.email).digest("hex");
      response.first = results.first;
      response.last = results.last;
      response.type = results.type;
      response.program = results.program;
      response.updated = datetime;
      response.created = results.created;
      req.session.login = true;
      res.json(200, response);
      console.log("User logged in: "+ results.email);
    }
  });
}

function postBlogPost(req, res)
{
  var datetime = new Date();
  Blog.create({
    title:    req.body['form-blog-title'],
    author:   req.body['form-blog-author'],
    body:     req.body['form-blog-body'],
    owner:    req.body['form-blog-owner'],
    date:     datetime,
    tags:     req.body['form-blog-tags'],
    type:     req.body['form-blog-type']
  }, function (err, results){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err);
    }
    else
    {
      res.json(200, {response: "success"});
      console.log("Blog posted: \""+results.title+"\" from: "+results.author);
    }
  });
}

function postForumPost(req, res)
{
  var datetime = new Date();
  Forum.create({
    title:    req.body['form-forum-title'],
    author:   req.body['form-forum-author'],
    body:     req.body['form-forum-body'],
    owner:     req.body['form-forum-owner'],
    date:     datetime,
    type:     req.body['form-forum-type']
  }, function (err, results) {
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err);
    }
    else
    {
      res.json(200, {response: "success"});
      console.log("Forum posted: \""+results.title+"\" from: "+results.author);
    }
  });
}

function postForumComment(req, res)
{
  var datetime = new Date();
  Forum.update({
    title: req.body['form-forum-comment-title'],
  },{$push: {comments: {
        author: req.body['form-forum-comment-author'],
        body: req.body['form-forum-comment-body'],
        owner: req.body['form-forum-comment-owner'],
        date: datetime
      }
    }
  }, function (err, affected){
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err);
    }
    else
    {
      res.json(200, {response: "success"});
      console.log("Forum comment posted: \""+req.body['form-forum-comment-title']+"\" from: "+req.body['form-forum-comment-author']);
    }
  });
}

function delForumPost(req, res)
{
  Forum.findOne({
    title: req.body['form-forum-delete-title'],
    owner: req.body['form-forum-delete-owner'],
  }, function (err, results) {
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err);
    }
    else
    {
      results.remove();
      res.json(200, {response: "success"});
      console.log("Removing post: "+results.title);
    }
  });
}

function delForumComment(req, res)
{
  Forum.update({
    title: req.body['form-forum-delete-parent-title'],
    owner: req.body['form-forum-delete-parent-owner']
  },{$pull: {comments: {
        body: req.body['form-forum-delete-comment-body'],
        owner: req.body['form-forum-delete-comment-owner'],
      }
    }
  }, function (err, affected) {
    if(err)
    {
      res.json(200, {response: "failure"});
      console.log(err);
    }
    else
    {
      res.json(200, {response: "success"});
      console.log("Removing comment from post: "+req.body['form-forum-delete-parent-title']);
    }
  });
}

function initialSetup()
{
  var datetime = new Date();
  var blogBody = 'Welcome to Cogswell Now!\r\n\r\nCogswell Now is a site where students can post and have access to student websites, news, events, and forum. This site will allow students who do not have a web space to place their school related website and have it hosted by Cogswell Now! It is also a great way to stay updated with clubs and events.\r\n\r\nDirectory: A place where all the student websites will be listed.\r\n\r\nBlog: The blog is a place where the latest news is posted. ASB notices, club notices and events are updated on the blog. If you are a club leader you are allowed to post directly to the student blog.\r\n\r\nForum: The forum is a place where students can post anything from discussions, academic help, help wanted, even things for sale!\r\n\r\nHave fun!';
  var forumBody = 'This is the student forum, where any student can post information with the option to add tags!';
  Blog.findOne(function (err, results) {
    if(results == null)
    {
      console.log('Inserting welcome blog');
      var datetime = new Date();
      Blog.create({
        title:    'Cogswell Now',
        author:   'Cogswell Now',
        body:     blogBody,
        owner:    'Cogswell Now',
        date:     datetime,
        tags:     'ALL',
        type:     'ASB Notice'
      }, function (err, results){
        if(err)
        {
          console.log(err);
        }
        else
        {
          console.log("Blog posted: \""+results.title+"\" from: "+results.author);
        }
      });
    }
  });
  Forum.findOne(function (err, results) {
    if(results == null)
    {
      console.log('Inserting forum post');
      Forum.create({
        title:    'Welcome to the forum!',
        author:   'Cogswell Now',
        body:     forumBody,
        owner:    'Cogswell Now',
        date:     datetime,
        type:     'Discussion'
      }, function (err, results) {
        if(err)
        {
          console.log(err);
        }
        else
        {
          console.log("Forum posted: \""+results.title+"\" from: "+results.author);
        }
      });
        }
  });
}

//db.users.update({email: 'jdelacruz@cogswell.edu'}, {$set: { type: 'admin'}})
