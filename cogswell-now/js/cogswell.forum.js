$(document).ready(function() {
  //Initial Forum page
  $.cookie("page-forum", 0);

  // Load forum
  loadforum();
  loadForumCount();
  updateButtons();

  // Button prev forum
  $("#forum-prev").click(function() {
    var page = parseInt($.cookie("page-forum"));
    if(page != 0)
    {
      page -= 1;
      $.cookie("page-forum", page);
      loadforum();
    }
    updateButtons();
  });

  // Button next forum
  $("#forum-next").click(function() {
    var page = parseInt($.cookie("page-forum"));
    var count = parseInt($.cookie("forum-count"));
    if((page+1)*10 < count)
    {
      page += 1;
      $.cookie("page-forum", page);
      loadforum();
    }
    updateButtons();
  });

  function updateButtons()
  {
    // Disable buttons
    if($.cookie("page-forum") == 0)
    {
      $("#forum-prev").removeClass("active");
      $("#forum-prev").addClass("disabled");
    }
    else
    {
      $("#forum-prev").removeClass("disabled");
      $("#forum-prev").addClass("active");
    }
    if(($.cookie("page-forum")+1)*10 >= parseInt($.cookie("forum-count")))
    {
      $("#forum-next").removeClass("active");
      $("#forum-next").addClass("disabled");
    }
    else
    {
      $("#forum-next").removeClass("disabled");
      $("#forum-next").addClass("active");
    }
  }

  // Button post forum
  $("#btn-forum-submit").click(function() {
    var payload = $("#form-forum-post").serializeObject();
    payload['form-forum-author'] = $.cookie("first")+" "+$.cookie("last");
    payload['form-forum-owner'] = $.cookie("owner");
    var error = 0;

    // Clear the error alert
    $("#form-forum-error").html("<B>Error!</B> please fix the following: ");

    // Check for valid data
    if(payload["form-forum-title"] == "")
    {
      error += 1;
      $("#form-forum-error").append("Title");
    }
    if(payload["form-forum-body"] == "")
    {
      error += 1;
      if(error > 1)
        $("#form-forum-error").append(", ");
      $("#form-forum-error").append("Body");
    }

    // Check to see if user is logged in
    if($.cookie("login") == 0 || !($.cookie("first")) || !($.cookie("last")) || !($.cookie("owner")))
    {
      error += 1;
      $("#form-forum-error").html("<B>You must be logged-in in order to post");
    }

    // If there is an error
    if(error > 0)
    {
      $("#form-forum-error").append(". ");
      $("#form-forum-error").visible();
    }
    else
    {
      $("#form-forum-error").invisible();
      var url = "http://"+window.location.host+"/post.forum.post";
      $.post(url, payload, function(data){
        if(data.response == "failure")
        {
          $("#form-forum-error").html("<b>Failed.<b>");
          $("#form-forum-error").visible();
        }
        else if(data.response == "success")
        {
          $("#form-forum-error").invisible();
          $("#form-forum-error").html("<B>Post successful!</B> redirecting...");
          $("#form-forum-error").removeClass("alert-error");
          $("#form-forum-error").addClass("alert-success");
          $("#form-forum-error").visible();
          var redirect = function() {
            window.location = "/forum/";
          };
          setTimeout(redirect, 1500);
        }
      },"json");
    }
  });

  // Button dynamic comment
  $("#forum").delegate(".btn-forum-comment", "click", function() {
    var post = $(this).parents(".forum-post");
    var title = post.find(".forum-title");
    var id = $(this).attr('id');
    $("#form-forum-comment-title").val(title[0].innerHTML);
    $("#form-forum-comment-id").val(id);
    $("#forum-modal-comment-label").html("Comment: "+title[0].innerHTML);
    $("#form-forum-comment-error").invisible();
    $("#forum-modal-comment").modal('show');
  });

  // Button dynamic comment show
  $("#forum").delegate(".btn-forum-comment-show", "click", function() {
    $(this).parent().next(".forum-comments").toggle();

    var change = $(this).parent().find(".btn-forum-comment-show").text();
    var show = '<i class="icon-plus-sign icon-white"></i> show';
    var hide = '<i class="icon-minus-sign icon-white"></i> hide';
    if(change == ' show')
    {
      $(this).parent().find(".btn-forum-comment-show").html(hide);
    }
    if(change == ' hide')
    {
      $(this).parent().find(".btn-forum-comment-show").html(show);
    }
  });

  // Button dynamic delete post
  $("#forum").delegate(".btn-forum-comment-del", "click", function() {
    var post = $(this).parents(".forum-post");
    var title = post.find(".forum-title");
    var owner = post.find(".forum-owner");
    var payload = {
      owner: owner[0].innerHTML,
      title: title[0].innerHTML
    };

    $("#form-forum-delete-title").val(title[0].innerHTML);
    $("#form-forum-delete-owner").val(owner[0].innerHTML);
    $("#forum-modal-delete-label").html("Post: "+title[0].innerHTML.substring(0,17)+"...");
    $("#forum-modal-delete").modal('show');
  });

  // Button dynamic delete comment
  $("#forum").delegate(".btn-forum-comment-del-comment", "click", function() {
    var post = $(this).parents(".forum-comment");
    var body = post.find(".forum-body");
    var owner = post.find(".forum-owner");
    var parent = $(this).parents(".forum-post");
    var pTitle = parent.find(".forum-title");
    var pOwner = parent.find(".forum-owner");

    var payload = {
      owner: owner[0].innerHTML,
      body: body[0].innerHTML,
      pTitle: pTitle[0].innerHTML,
      pOwner: pOwner[0].innerHTML
    };

    $("#form-forum-delete-comment-body").val(body[0].innerHTML);
    $("#form-forum-delete-comment-owner").val(owner[0].innerHTML);
    $("#form-forum-delete-parent-title").val(pTitle[0].innerHTML);
    $("#form-forum-delete-parent-owner").val(pOwner[0].innerHTML);
    $("#forum-modal-delete-comment-label").html("Comment: "+body[0].innerHTML.substring(0,17)+"...");
    $("#forum-modal-delete-comment").modal('show');
  });

  // Button delete submit
  $("#btn-forum-del").click(function() {
    var payload = $("#form-forum-delete").serializeObject();

    var url = "http://"+window.location.host+"/del.forum.post";
    $.post(url, payload, function(data){
      if(data.response == "failure")
      {
        $("#form-forum-delete-error").html("<b>Failed.<b>");
        $("#form-forum-delete-error").visible();
      }
      else if(data.response == "success")
      {
        $("#form-forum-delete-error").invisible();
        $("#form-forum-delete-error").html("<B>Delete successful!</B> redirecting...");
        $("#form-forum-delete-error").removeClass("alert-error");
        $("#form-forum-delete-error").addClass("alert-success");
        $("#form-forum-delete-error").visible();
        var redirect = function() {
          window.location = "/forum/";
        };
        setTimeout(redirect, 1500);
      }
    });
  });

  // Button delete comment submit
  $("#btn-forum-del-comment").click(function() {
    var payload = $("#form-forum-delete-comment").serializeObject();

    var url = "http://"+window.location.host+"/del.forum.comment";
    $.post(url, payload, function(data){
      if(data.response == "failure")
      {
        $("#form-forum-delete-comment-error").html("<b>Failed.<b>");
        $("#form-forum-delete-comment-error").visible();
      }
      else if(data.response == "success")
      {
        $("#form-forum-delete-comment-error").invisible();
        $("#form-forum-delete-comment-error").html("<B>Delete successful!</B> redirecting...");
        $("#form-forum-delete-comment-error").removeClass("alert-error");
        $("#form-forum-delete-comment-error").addClass("alert-success");
        $("#form-forum-delete-comment-error").visible();
        var redirect = function() {
          window.location = "/forum/";
        };
        setTimeout(redirect, 1500);
      }
    });
  });

  // Button comment submit
  $("#btn-forum-comment").click(function() {
    var payload = $("#form-forum-comment").serializeObject();
    payload['form-forum-comment-author'] = $.cookie("first")+" "+$.cookie("last");
    payload['form-forum-comment-owner'] = $.cookie("owner");
    var error = 0;

    // Clear the error alert
    $("#form-forum-comment-error").html("<B>Error!</B> please fix the following: ");

    // Check for valid data
    if(payload["form-forum-comment-body"] == "")
    {
      error += 1;
      $("#form-forum-comment-error").append("Body");
    }

    // Check to see if user is logged in
    if($.cookie("login") == 0 || !($.cookie("first")) || !($.cookie("last")) || !($.cookie("owner")))
    {
      error += 1;
      $("#form-forum-comment-error").html("<B>You must be logged-in in order to post");
    }

    // If there is an error
    if(error > 0)
    {
      $("#form-forum-comment-error").append(". ");
      $("#form-forum-comment-error").visible();
    }
    else
    {
      $("#form-forum-comment-error").invisible();
      var url = "http://"+window.location.host+"/post.forum.comment";
      $.post(url, payload, function(data){
        if(data.response == "failure")
        {
          $("#form-forum-comment-error").html("<b>failed.<b>");
          $("#form-forum-comment-error").visible();
        }
        else if(data.response == "success")
        {
          $("#form-forum-comment-error").html("<B>Post successful!</B> redirecting...");
          $("#form-forum-comment-error").removeClass("alert-error");
          $("#form-forum-comment-error").addClass("alert-success");
          $("#form-forum-comment-error").visible();
          var redirect = function() {
            window.location = "/forum/";
          };
          setTimeout(redirect, 1500);
        }
      },"json");
    }
  });

  // Load forum
  function loadforum()
  {
    var page = {page: $.cookie("page-forum")};
    var url = "http://"+window.location.host+"/get.forum";
    $.get(url, page, function(data){
      $("#forum").html("");
      for(var i in data)
      {
        $("#forum").append(buildForumEntry(data[i]));
      }
    }, "json");
  }

  // Load forum count
  function loadForumCount()
  {
    var date = new Date();
    var minutes = 60;
    date.setTime(date.getTime()+(minutes * 60 * 1000));

    var url = "http://"+window.location.host+"/get.forum.count";
    $.get(url, function(data){
      $.cookie("forum-count", data.count, {expires: date, path: '/'});
    }, "json");
  }

  // Builds the forum entry
  function buildForumEntry(post)
  {
    var titleAndType = '<div><span class="forum-title">'+post.title+'</span>'+buildType(post.type)+'</div>';
    var author =  '<div class="forum-author">By: '+post.author+' on '+formatDate(post.date)+'</div>';
    var owner =  '<div class="forum-owner">'+post.owner+'</div>';
    var body =    '<pre>'+post.body+'</pre>';
    var comment = '';
    var commentBtn = '<div class="btn-group"><a class="btn btn-mini btn-primary btn-forum-comment" id=""><i class="icon-comment icon-white"></i> comment</a></div>';
    var expandBtn = '<div class="btn-group"><a class="btn btn-mini btn-inverse btn-forum-comment-show" id=""><i class="icon-plus-sign icon-white"></i> show</a></div>';
    var deleteBtn = '';
    var footer =  '<hr style="border-top: 1px dotted #b0b0b0;border-bottom: 0px">';
    var entry;
    if(post.owner == $.cookie("owner"))
    {
      deleteBtn = '<div class="btn-group"><a class="btn btn-mini btn-danger btn-forum-comment-del" id=""><i class="icon-remove-sign icon-white"></i> delete</a></div>';
    }
    if(post.comments.length > 0)
    {
      comment = buildComments(post.comments);
      entry = '<div class="forum-post">'+titleAndType+author+owner+body+deleteBtn+commentBtn+expandBtn+comment+footer+'</div>';
    }
    else
    {
      entry = '<div class="forum-post">'+titleAndType+author+owner+body+deleteBtn+commentBtn+footer+'</div>';
    }
    return entry;
  }

  // Builds the type labal
  function buildType(type)
  {
    var str;
    if(type == "Discussion")
      str = '<span class="forum-type label label-forum-Discussion">'+type+'</span>';
    if(type == "Academic help")
      str = '<span class="forum-type label label">'+type+'</span>';
    if(type == "Lost & found")
      str = '<span class="forum-type label label-forum-lost">'+type+'</span>';
    if(type == "Help wanted")
      str = '<span class="forum-type label label-forum-help">'+type+'</span>';
    if(type == "Selling")
      str = '<span class="forum-type label label-forum-selling">'+type+'</span>';
    if(type == "Event")
      str = '<span class="forum-type label label-forum-event">'+type+'</span>';
    return str;
  }

  // Builds the comments
  function buildComments(data)
  {
    var entry = '';
    var comment = '';
    var deleteBtn = '';
    for(var i in data)
    {
      var author = '<div class="forum-author">By: '+data[i].author+' on '+formatDate(data[i].date)+'</div>';
      var owner =  '<div class="forum-owner">'+data[i].owner+'</div>';
      var body = '<pre class="forum-body">'+data[i].body+'</pre>';

      if(data[i].owner == $.cookie("owner"))
      {
        deleteBtn = '<div class="btn-group"><a class="btn btn-mini btn-danger btn-forum-comment-del-comment" id=""><i class="icon-remove-sign icon-white"></i> delete</a></div>';
      }
      comment = author+owner+body+deleteBtn;
      entry += '<div class="forum-comment">'+comment+'</div>';
    }
    return '<div class="forum-comments" style="display:none">'+entry+'</div>';
  }

  // Formats date
  function formatDate(ISODate)
  {
    d = new Date(ISODate);
    return d.toLocaleString();
  }

  $.fn.invisible = function()
  {
    return this.each(function() {
      $(this).css("visibility", "hidden");
    });
  };

  $.fn.visible = function()
  {
    return this.each(function() {
      $(this).css("visibility", "visible");
    });
  };
});
