$(function() {
  $('#sendBtn').bind('click', function() {
    $.getJson('/run',
      function(data) {
      console.log("test")
    });
    return false;
  });
});

function validate(name) {
  if (name.length >= 2) {
    return true;
  }
  return false;
}