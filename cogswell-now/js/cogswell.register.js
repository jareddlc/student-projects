$(document).ready(function(){
  // Alert initialization
  $(".alert").alert();

  // Button register
  $("#btn-register").click(function() {
    var payload = $("#form-register").serializeForm();
    var error = 0;
    var error_email = 0;

    // Clear the error alert
    $("#alert-error").html("");

    // Check for valid data
    for(var i in payload)
    {
      // If blank
      if(payload[i]["value"] == "")
      {
        error += 1;

        if(error > 1 && error <= Object.keys(payload).length+1)
          $("#alert-error").append(", ");

        $("#alert-error").append(payload[i]["placeholder"]);
      }

      // Check email for valid data
      if(payload[i]["name"] == "form-register-email")
      {
        var email = payload[i]["value"];
        var regex = /@cogswell.edu/gi;

        // Incorrect email
        if(email.search(regex) < 0)
        {
          error_email += 1;
        }
      }
    }

    // If there is an error
    if(error > 0)
    {
      $("#alert-error").append(". ");
      $("#form-register-error").visible();
    }
    else if(error_email > 0)
    {
      $("#alert-error").append("<b>You must register with a Cogswell email address.<b>");
      $("#form-register-error").visible();
    }
    else
    {
      $("#form-register-error").invisible();
      var payload = $("#form-register").serializeObject();

      // POST JSON
      var url = "http://"+window.location.host+"/post.user";
      $.post(url, payload, function(data){
        if(data.response == "failure")
        {
          $("#alert-error").append("<b>Email already exists.<b>");
          $("#form-register-error").visible();
        }
        else if(data.response == "success")
        {
          $("#form-register-error").invisible();
          $("#form-register-error").html("<B>Registration successful!</B> redirecting...");
          $("#form-register-error").removeClass("alert-error");
          $("#form-register-error").addClass("alert-success");
          $("#form-register-error").visible();
          var redirect = function() {
            window.location = "/";
          }
          setTimeout(redirect, 1500);
        }
      },"json");
    }

  });
  // Creates array
  $.fn.serializeForm = function()
  {
    var form = {};
    var element = this[0]['id'];
    var elements = document.getElementById(element);

    for(var i = 0; i < elements.length-1; i++)
    {
      var temp = [];
      temp['name'] = elements[i]['name'];
      temp['value'] = elements[i].value;
      temp['placeholder'] = elements[i]['placeholder'];
      form[i] = temp;
    }
    return form;
  }

  // Creates JSON array
  $.fn.serializeObject = function()
  {
    var o = {};
    var a = this.serializeArray();
    $.each(a, function() {
      if (o[this.name] !== undefined) {
        if (!o[this.name].push) {
          o[this.name] = [o[this.name]];
        }
        o[this.name].push(this.value || '');
      }
      else {
        o[this.name] = this.value || '';
      }
    });
    return o;
  }

  $.fn.invisible = function()
  {
    return this.each(function() {
      $(this).css("visibility", "hidden");
    });
  }

  $.fn.visible = function()
  {
    return this.each(function() {
      $(this).css("visibility", "visible");
    });
  }
});
