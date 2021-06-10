from client import Client
import time

c1 = Client("John")
c2 = Client("Evan")

c1.send_messages("Hello from 1")
time.sleep(1)
c2.send_messages("Hello from 2")
time.sleep(1)
c2.send_messages("How are you")
time.sleep(1)
c1.send_messages("I am good")
time.sleep(1)
c2.send_messages("What's up")
