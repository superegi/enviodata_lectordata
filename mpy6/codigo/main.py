print("main.py: Hello")


from machine import Pin
import dht

# Use GPIO14 (D5 - NodeMCU)
my_dht = dht.DHT22(Pin(14, Pin.IN, Pin.PULL_UP))

my_dht.measure()
b = my_dht.temperature()
c = my_dht.humidity()

print(b)
print(c)



import greenhouse
greenhouse.do_connect()
print("Greenhouse module up. Running...")
greenhouse.do_run()