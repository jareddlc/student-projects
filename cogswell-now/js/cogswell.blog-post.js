$(document).ready(function(){
  // Button post blog
  $("#btn-blog-submit").click(function() {
    var payload = $("#form-blog-post").serializeObject();
    var values = $('input:checkbox:checked.form-blog-checkbox').map(function(){return this.value;}).get();
    payload['form-blog-tags'] = values;
    payload['form-blog-author'] = $.cookie("first")+" "+$.cookie("last");
    payload['form-blog-owner'] = $.cookie("owner");
    var error = 0;

    // Clear the error alert
    $("#alert-error").html("");

    // Check for valid data
    if(payload["form-blog-title"] == "")
    {
      error += 1;
      $("#alert-error").append("Title");
    }
    if(payload["form-blog-body"] == "")
    {
      error += 1;
      if(error > 1)
        $("#alert-error").append(", ");
      $("#alert-error").append("Body");
    }

    // Check to see if user is logged in
    if($.cookie("login") == 0 || !($.cookie("first")) || !($.cookie("last")))
    {
      error += 1;
      $("#form-forum-error").html("<B>You must be logged-in in order to post");
    }

    // If there is an error
    if(error > 0)
    {
      $("#alert-error").append(". ");
      $("#form-blog-post-error").visible();
    }
    else
    {
      $("#form-blog-post-error").invisible();
      var url = "http://"+window.location.host+"/post.blog.post";
      $.post(url, payload, function(data){
        if(data.response == "failure")
        {
          $("#alert-error").append("<b>failed.<b>");
          $("#form-blog-post-error").visible();
        }
        else if(data.response == "success")
        {
          $("#form-blog-post-error").invisible();
          $("#form-blog-post-error").html("<B>Post successful!</B> redirecting...");
          $("#form-blog-post-error").removeClass("alert-error");
          $("#form-blog-post-error").addClass("alert-success");
          $("#form-blog-post-error").visible();
          var redirect = function() {
            window.location = "/";
          }
          setTimeout(redirect, 1500);
        }
      },"json");
    }
  });

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
