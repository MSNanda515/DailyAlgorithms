class Person:
  '''
    Represents a person. Stores information about their name, ip, and socket client
  '''
  def __init__(self, addr, client):
    self.addr = addr
    self.name = None
    self.client = client
  
  def __repr__ (self):
    return f"Person({self.addr}), ({self.name})"

  def set_name(self, name):
    self.name = name