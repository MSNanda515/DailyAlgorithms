

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


window.onload = function (){
  var update_loop = setInterval(update, 100);
  update()
};


function update() {
  fetch('/get_messages')
    .then((response) => response.json())
    .then(function(text) {
      // console.log('GET response text: ');
      // console.log(text);
      test = document.getElementById("testPara");
      test.innerHTML = '';
      for (let i = 0; i < text.messages.length; i++) {
        test.innerHTML += text.messages[i] + "<br />"
        // console.log(text[i])
      }
    })
    .catch((e) => {
      console.log("Exception:" + e)
    });
}


