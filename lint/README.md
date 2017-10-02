# lint
My first node.js project. This application extends basic CRUD operations on a MySQL database. It allows the user to interact with the MySQL database via the web UI to create new databases, tables, columns, and rows.

### Dependencies

##### Node.js
Node.js® is a JavaScript runtime built on Chrome's V8 JavaScript engine. Node.js uses an event-driven, non-blocking I/O model that makes it lightweight and efficient.

##### MySQL 5.5
MySQL is the world's most popular open source database. Whether you are a fast growing web property, technology ISV or large enterprise, MySQL can cost-effectively help you deliver high performance, scalable database applications.

```
$ docker run --name some-mysql -e MYSQL_ALLOW_EMPTY_PASSWORD=yes -e MYSQL_DATABASE=lint -p 3306:3306 -d mysql:5.5
```

### Install

```
$ npm install
```

### Running

```
$ npm start
```

* Open `index.html` in a browser to access the web UI
