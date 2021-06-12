from socket import AF_INET, socket, SOCK_STREAM
from threading import Thread
import time

from person import Person
# .. will be a multithreaded application so that things don't hang 
#  Will have concurrent things executing

# Initialize the socket for server connection
# GLOBAL CONSTANTS
HOST = 'localhost'
PORT = 50000
BUFSIZ = 1024
ADDR = (HOST, PORT)
MAX_CONNECTIONS = 10

# GLOBAL VARIABLES
people = []

SERVER = socket(AF_INET, SOCK_STREAM)
SERVER.bind(ADDR) # Set up server


def broadcast(msg, name):
  '''
    send the new message received to all clients
    :param msg: bytes["utf8"]
    :param name: string
    :return 
  '''
  for person in people:
    client = person.client
    client.send(bytes(name + ": " + msg, "utf8" ))
  pass


def client_communication(person):
  '''
    Thread to handle all messages from client
    :param person: Person
    :return None
  '''
  run = True
  client = person.client
  addr = person.addr

  # Get client's name
  name = client.recv(BUFSIZ).decode("utf8")
  person.set_name(name)
  msg = f"{name} has joined the chat!"  # broadcast welcome message

  broadcast(msg, "")
  while run:
    try: 
      msg = client.recv(BUFSIZ).decode("utf8")
      print(f"{name}: ", msg)
      if msg == "{quit}":
        msg = f"{name} has left the chat"
        people.remove(person)
        broadcast(msg, "")
        # client.send(bytes("{quit}", "utf8"))
        # people.remove(person)
        client.close()
      else:
        broadcast(msg, name)
    except Exception as e:
      print("[Exception222]", e)
  pass


def wait_for_connection(SERVER):
  '''
    Waits for a connection from clients, start new thread once connected
    :param SERVER: SOCKET
    :return None
  '''
  run = True
  while run:
    try:
      client, addr = SERVER.accept()
      person = Person(addr, client)
      people.append(person)
      print(f"[CONNECTION] {addr} connected to the server at {time.ctime(time.time())}")
      Thread(target=client_communication, args=(person,)).start()
    except Exception as e:
      print("[FAILURE]", e)
      run = False
  pass


if __name__ == "__main__":
  SERVER.listen(MAX_CONNECTIONS)
  print("Waiting for connection")
  ACCEPT_THREAD = Thread(target=wait_for_connection, args=(SERVER,))
  ACCEPT_THREAD.start()
  ACCEPT_THREAD.join()
  pass

