from socket import AF_INET, SOCK_STREAM, socket
from threading import Thread, Lock
import time

class Client:
  '''
    For communication with the server
  '''
  PORT = 50000
  SERVER_IP = 'localhost'
  BUFSIZ = 1024
  ADDR = (SERVER_IP, PORT)
  messages = []

  def __init__(self, name):
    '''
    Initialize the object and convey the name to the server
    :param name: str
    :return None
    '''
    self.client_socket = socket(AF_INET, SOCK_STREAM)
    self.client_socket.connect(self.ADDR) 
    self.receive_thread = Thread(target=self.receive_message)
    self.receive_thread.start()
    self.send_message(name)
    self.lock = Lock()
    pass

  def receive_message(self):
    '''
    receive message from server
    :param none
    :return: None
    '''
    while True:
      try:
        msg = self.client_socket.recv(self.BUFSIZ).decode("utf8")
        self.lock.acquire()
        self.messages.append(msg)
        self.lock.release()
        print(msg)
      except Exception as e:
        print("[Exception111]",e)
        break
    pass

  def send_message(self, msg):
    try:
      self.client_socket.send(bytes(msg, "utf8"))
      if msg == "{quit}":

        self.client_socket.close()
    except Exception as e:
      self.client_socket = socket(AF_INET, SOCK_STREAM)
      self.client_socket.connect(self.ADDR) 
      print("Exception : " + e) 

  def get_messages(self):
    '''
    :returns a list of string messages
    '''
    messages_copy = self.messages[:]
    # safe writing to global varialbes
    self.lock.acquire()
    self.messages = []
    self.lock.release()
    return messages_copy

  def disconnect(self):
    self.send_message("{quit}")
    self.client_socket.close()