$(document).ready(function(){
  var apiKey = 'AIzaSyAav7qkljVCBY9lA0Gjua1x49rpgEo6udg';
  var today = new Date();
  var url = 'https://www.googleapis.com/calendar/v3/calendars/cogswellasb%40gmail.com/events?orderBy=startTime&singleEvents=true&timeMin='+today.toISOString()+'&key='+apiKey;

  $.get(url, function(data){
    for(var i = 0 ; i < 10;i++)
    {
      $("#calendar-div ul").append(buildCalendarEntry(data.items[i]));
    }
    $("a").tooltip({
      'placement': 'right'
    });
  },"json");


  function buildCalendarEntry(data)
  {
    var info = buildInfo(data);
    var entry = '<li><a href="'+data.htmlLink+'" data-toggle="tooltip" title="'+info+'" target="_blank"><i class="icon-calendar"></i>'+data.summary+'</a></li>';
    return entry;
  }

  function buildInfo(data)
  {
    var info = '';
    if(data.start.date)
    {
      info += 'Start: '+data.start.date+'';
    }
    if(data.end.date)
    {
      info += '  End: '+data.end.date;
    }

    if(data.start.dateTime)
    {
      var d = new Date(data.start.dateTime);
      info += 'Start: '+d.toLocaleString();
    }
    if(data.end.dateTime)
    {
      var d = new Date(data.end.dateTime);
      info += ' End: '+d.toLocaleString();
    }
    if(data.location)
    {
      info += ' Location: '+data.location;
    }
    return info;
  }
});

/*
https://www.googleapis.com/calendar/v3/calendars/calendarId/events/eventId
Key for browser apps (with referers)
API key:  
AIzaSyAav7qkljVCBY9lA0Gjua1x49rpgEo6udg
Referers:   
Any referer allowed
Activated on:   Jun 26, 2013 4:34 PM
Activated by:   cogswellasb@gmail.com – you 
https://www.google.com/calendar/feeds/cogswellasb@gmail.com/public/basic?sortorder=descending
*/
