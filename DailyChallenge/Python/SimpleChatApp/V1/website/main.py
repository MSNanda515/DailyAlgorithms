from flask import Flask, render_template, url_for, redirect, request, session, jsonify
from client.client import Client
from threading import Thread
import time


NAME_KEY = 'name'

client = None
messages = []

app = Flask(__name__)
app.secret_key = "hello"


def disconnect():
  '''
  call this before the client disconnects
  '''
  global client
  if client:
    client.disconnect()
    client = None

@app.route("/login", methods=["POST", "GET"])
def login():
  '''
    displays the login page and handles saving user info in session
    :exception: POST
    :return None
  ''' 
  disconnect()
  if request.method == "POST":
    session[NAME_KEY] = request.form["inputName"]
    return redirect(url_for("home"))
  return render_template("login.html", **{"session": session})

@app.route("/logout")
def logout():
  '''
    Logs the user out by popping name from session list
    :returns: None
  '''
  session.pop(NAME_KEY, None)
  return redirect(url_for("login"))


@app.route("/home")
@app.route("/")
def home():
  '''
    Displays Home page if logged in
    :return none
  '''
  global client
  if NAME_KEY not in session:
    return redirect(url_for("login"))
  client = Client(session[NAME_KEY])
  return render_template("index.html", **{"login": True, "session": session})

@app.route("/send_message/", methods=["GET"])
def send_message():
  '''
    Called from jquery to send message
  '''
  global client
  msg = request.args.get("val")
  if client != None:
    client.send_message(msg)
  
  return "none"


@app.route("/get_messages")
def get_messages():
    return jsonify({"messages": messages})


def update_message():
  '''
    Updates the list of local messages
    :return: None
  '''
  global messages
  run = True
  while run:
    if not client: continue
    time.sleep(0.1)
    new_messages = client.get_messages()
    messages.extend(new_messages)

    for msg in new_messages:
      print (msg)

      if msg == "{quit}":
        run = False
        break




if __name__ == "__main__":
  Thread(target=update_message).start()
  app.run(debug=True)