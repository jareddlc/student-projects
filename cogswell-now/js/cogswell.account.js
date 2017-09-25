$(document).ready(function(){
  var payload = {email: $.cookie("email")};

  var url = "http://"+window.location.host+"/get.account";
  $.get(url, payload, function(data){
    // Update form
    $("#form-account-fname").val(data.first);
    $("#form-account-lname").val(data.last);
    $("#form-account-program").val(data.program);
    $("#form-account-email").html(data.email);
    $("#form-account-created").html(formatDate(data.created));
    $("#form-account-updated").html(formatDate(data.updated));
  },"json");

	$("#btn-account-submit").click(function(){
    var payload = $("#form-account").serializeObject();
    payload['form-account-email'] = $.cookie("email");

    var url = "http://"+window.location.host+"/post.account";
    $.post(url, payload, function(data){
      if(data.response == "failure")
      {
        $("#form-account-error").visible();
      }
      else if(data.response == "success")
      {
        $.cookie("first", payload['form-account-fname']);
        $.cookie("last", payload['form-account-lname']);
        $.cookie("program", payload['form-account-program']);

        // Display success message
        $("#form-account-error").invisible();
        $("#form-account-error").html("<B>Account saved!</B> redirecting...");
        $("#form-account-error").removeClass("alert-error");
        $("#form-account-error").addClass("alert-success");
        $("#form-account-error").visible();
        var redirect = function() {
          window.location = "/";
        }
        setTimeout(redirect, 1500);
        }
    });
  });

  // Formats date
  function formatDate(ISODate)
  {
    d = new Date(ISODate);
    return d.toLocaleString();
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
