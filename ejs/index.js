/**
 * Module dependencies.
 */
require('dotenv').load();
var express = require('../');
var path = require('path');
var Twilio = require('twilio');

var app = module.exports = express();

// Register ejs as .html. If we did
// not call this, we would need to
// name our views foo.ejs instead
// of foo.html. The __express method
// is simply a function that engines
// use to hook into the Express view
// system by default, so if we want
// to change "foo.ejs" to "foo.html"
// we simply pass _any_ function, in this
// case `ejs.__express`.

app.engine('.html', require('ejs').__express);

// Optional since express defaults to CWD/views

app.set('views', path.join(__dirname, 'views'));

// Path to our public directory

app.use(express.static(path.join(__dirname, 'public')));

// Without this you would need to
// supply the extension to res.render()
// ex: res.render('users.html').
app.set('view engine', 'html');

var dht11 = { temperature: 10, humidity: '0' };

const accountSid = process.env.accountSid;
const authToken = process.env.authToken;
const serviceSid = process.env.serviceSid;

const client = new Twilio(accountSid, authToken);
const service = client.sync.services(serviceSid);

app.get("/create-document", function(request, response) {
  service.documents
    .create({
      uniqueName: 'dht11',
      data: {
        temperature: '0',
        humidity: '0'
     }
    })
    .then(response => {
      console.log(response);
    })
    .catch(error => {
      console.log(error);
    });
  response.end("Your device document has been created!");
});

app.get("/delete-document", function(request, response) {
  service
    .documents('dht11')
    .remove()
    .then(response => {
      console.log(response);
    })
    .catch(error => {
      console.log(error);
    });
  response.end("Your device document has been deleted!");
});

app.get("/retrieve-document", function(request, response) {
 service
   .documents('dht11')
   .fetch()
   .then(response => {
     console.log(response);
   })
   .catch(error => {
    console.log(error);
   });
 response.end("Your device document has been retrieved!");
});

app.get('/', function(req, res){
    service
      .documents('dht11')
      .fetch()
      .then(response => {
      dht11 = response.data;
      console.log("Rendering T & H the first time.", dht11.temperature, dht11.humidity);
      res.render('dht11', {
        SessionState: 0,
        dht11: dht11,
        title: "EJS example",
        header: "Some users"
      });
    })
    .catch(error => {
      console.log(error);
    });
});

app.post('/', function(req, res){
  service
//      .documents('BoardLED')
  .documents('dht11')
  .fetch()
  .then(response => {
    dht11 = response.data;
    console.log("Rendering T & H every 1 min.", dht11.temperature, dht11.humidity);
    res.render('dht11', {
      SessionState: 1,
      dht11: dht11,
      title: "EJS example",
      header: "Some users"
    });
  })
 .catch(error => {
  console.log(error);
  });
});

/* istanbul ignore next */
if (!module.parent) {
  app.listen(3000);
  console.log('Express started on port 3000');
}
