/**
 * Module dependencies.
 */
require('dotenv').load();
var express = require('../');
var path = require('path');
var Twilio = require('twilio');
var Sync = require('twilio-sync');

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

SyncDoc = 'dht11';
SyncControl = 'BoardLED'

/* Function: Create $SyncDoc under $service.
*/
function createSyncControl(service, SyncControl) {
  service.documents
    .create({
      uniqueName: SyncControl,
      data: {
        command: 'no',
        state: 'ready'
     },
      ttl: 0 
    })
    .then(response => {
      console.log(response);
    });
}


/* Function: Create $SyncDoc under $service.
*/
function createSyncDoc(service, SyncDoc) {
  service.documents
    .create({
      uniqueName: SyncDoc,
      data: {
        temperature: '0',
        humidity: '0'
     },
      ttl: 0 
    })
    .then(response => {
//      console.log(response);
     console.log("== createSyncDoc ==");
    });
}

/* Function: Delete the $SyncDoc under $service.
*/
function deleteSyncDoc(service, SyncDoc) {
  service
    .documents(SyncDoc)
    .remove()
    .then(response => {
 //     console.log(response);
    console.log("== deleteSyncDoc =="); 
})
    .catch(error => {
      console.log(error);
    });
}

/* Function: Retrieve the $SyncDoc under $service.
*/
function updateSyncControl(service, SyncControl) {
  service
  .documents(SyncControl)
  .update({
   data: { msg: 'pause' },
 })
 .then(response => {
 //  console.log(response);
 console.log("== updateSyncControl ==");
 })
 .catch(error => {
   console.log(error);
 });   
}

/* Function: Retrieve the $SyncDoc under $service.
*/
function retrieveSyncDoc(service, SyncDoc, dht11) {
  service
    .documents(SyncDoc)
    .fetch()
    .then(response => {
      dht11 = response.data;
//      console.log(response);
     console.log("== retrieveSyncDoc ==");
    })
    .catch(error => {
      console.log(error);
    });
}

/* Function: doing actual rendering.
*/

function rendering(SessionState, res, dht11) {
  res.render('dht11', {
    SessionState: SessionState,
    dht11: dht11,
    title: "EJS example",
    header: "Some users"
   });
}

/* Function: Retrieve and render the $SyncDoc under $service.
*/

function renderSyncDoc(service, SyncDoc, SessionState, SrcLog, res) {

  var data = { temperature: 10, humidity: '0' };
  service
  .documents(SyncDoc)
  .fetch()
  .then(response => {
    
    console.log(SrcLog, 
      response.data.temperature, 
      response.data.humidity,
      dht11.temperature, dht11.humidity);

    if(response.data.temperature === undefined || response.data.humidity === undefined){
      updateSyncControl(service, SyncControl);
      setTimeout(function(){deleteSyncDoc(service, SyncDoc);}, 10000);
      setTimeout(function(){createSyncDoc(service, SyncDoc);}, 30000);
      setTimeout(function(){retrieveSyncDoc(service, SyncDoc, dht11);}, 50000);
      setTimeout(function(){rendering(SessionState, res, dht11);}, 55000);
    }else{
      dht11 = response.data;
      res.render('dht11', {
       SessionState: SessionState,
       dht11: dht11,
       title: "EJS example",
       header: "Some users"
      });
    }
  })
  .catch(error => {
    console.log(error);
  });
}

app.get("/control-test", function(request, response) {
  updateSyncControl(service, SyncControl);
  setTimeout(function(){deleteSyncDoc(service, SyncDoc);}, 20000);
  setTimeout(function(){createSyncDoc(service, SyncDoc);}, 40000);
  setTimeout(function(){retrieveSyncDoc(service, SyncDoc);}, 60000);

  response.end("Your device control was updated. ");
});

app.get("/create-control", function(request, response) {
  createSyncControl(service, SyncDoc);
  response.end("Your device control has been created!");
});

app.get("/retrieve-control", function(request, response) {
  service
  .documents('BoardLED')
  .fetch()
  .then(response => {
    console.log(response);
  })
  .catch(error => {
   console.log(error);
  });
  response.end("Your device control has been retrieved!");
});

app.get("/update-control", function(request, response) {
  service
       .documents(SyncControl)
       .update({
        data: { msg: 'pause' },
      })
      .then(response => {
        console.log(response);
      })
      .catch(error => {
        console.log(error);
      });
  response.end("Your device control has been updated!");
});

app.get("/create-document", function(request, response) {
  createSyncDoc(service, SyncDoc);
  response.end("Your device document has been created!");
});

app.get("/delete-document", function(request, response) {
  deleteSyncDoc(service, SyncDoc);
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
  console.log("== entering get/ ==");
  renderSyncDoc(service, SyncDoc, 0, "Rendering T & H the first time.", res);

});

app.post('/', function(req, res){
  console.log("== entering post/ ==");
  renderSyncDoc(service, SyncDoc, 1, "Rendering T & H every 1 min.", res);

});

/* istanbul ignore next */
if (!module.parent) {
  app.listen(3000);
  console.log('Express started on port 3000');
}
