

$(function() {
  $('#sendBtn').bind('click', function() {
      var msg = document.getElementById("msg")
      var value = msg.value
      msg.value = ""

      $.getJSON('/send_message',
          {val:value},
          function(data) {

          });
  });
});


function validate(name) {
  if (name.length >= 2) {
    return true;
  }
  return false;
}



fetch('/get_messages')
  .then(() => response.text)
  .then(function() {
    console.log('GET response text: ');
    console.log(text);
  });