$(function() {
  $('a#test').bind('click', function() {
    $.getJson('/run',
      function(data) {
      console.log("test")
    });
    return false;
  });
});