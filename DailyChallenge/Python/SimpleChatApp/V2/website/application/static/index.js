async function  add_messages(msg, scroll) {
  if (typeof msg.name !== "undefined") {
    var date = dateNow()

    if(typeof msg.time !== "undefined") {
      var n = msg.time;
    } else {
      var n = date;
    }
    var global_name = await load_name();

    var content = '<div class="container">' +
      '<b style="color:#000" class="right">' +
      msg.name +
      '</b><p>' + 
      msg.message + 
      '</p><span class="time-right">' + 
      n + 
      '</span></div>'
    if (global_name == msg.name) {
      content = 
        '<div class="container darker">' +
          '<b style="color:#000" class="left">' +
          msg.name +
          "</b><p>" +
          msg.message +
          '</p><span class="time-left">' +
          n +
          "</span></div>";
    }
    // update div
    var messageDiv = document.getElementById("message");
    messageDiv.innerHTML += content;
  }

  if (scroll) {
    scrollSmoothToBottom("messages");
  }
}

async function load_name() {
  return await fetch("/get_name")
    .then(async function (response) {
      return await response.json();
    })
    .then(function (text) {
      return text["name"];
    });
}

async function load_message() {
  return await fetch
}