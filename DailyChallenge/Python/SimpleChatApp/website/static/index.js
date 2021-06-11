// $(function() {
//   $('#sendBtn').bind('click', function() {
//     $.getJson('/run',
//       {
//         value: va
//       },
//       function(data) {
//       value = document.getElementById("msg").value
//     });
//     return false;
//   });
// });

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