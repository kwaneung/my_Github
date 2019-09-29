import RPi.GPIO as gpio
import time, datetime
from threading import Thread

GPIO_RBUTTON = 16
GPIO_YBUTTON = 20
GPIO_GBUTTON = 21
TOGGLE_BUTTON = 6

GPIO_RED = 13
GPIO_YLW = 19
GPIO_GRN = 26

R = 0
Y = 0
G = 0
T = 0

gpio.setmode(gpio.BCM)
gpio.setup(GPIO_RBUTTON, gpio.IN)
gpio.setup(GPIO_YBUTTON, gpio.IN)
gpio.setup(GPIO_GBUTTON, gpio.IN)
gpio.setup(TOGGLE_BUTTON, gpio.IN)
gpio.setup(GPIO_RED, gpio.OUT)
gpio.setup(GPIO_YLW, gpio.OUT)
gpio.setup(GPIO_GRN, gpio.OUT)

def allOff():
	gpio.output(GPIO_RED, False)
	gpio.output(GPIO_YLW, False)
	gpio.output(GPIO_GRN, False)
	
def redOn():
	gpio.output(GPIO_RED, True)
	gpio.output(GPIO_YLW, False)
	gpio.output(GPIO_GRN, False)
	
def ylwOn():
	gpio.output(GPIO_RED, False)
	gpio.output(GPIO_YLW, True)
	gpio.output(GPIO_GRN, False)
	
def grnOn():
	gpio.output(GPIO_RED, False)
	gpio.output(GPIO_YLW, False)
	gpio.output(GPIO_GRN, True)
	
def ryOn():
	gpio.output(GPIO_RED, True)
	gpio.output(GPIO_YLW, True)
	gpio.output(GPIO_GRN, False)
	
def rgOn():
	gpio.output(GPIO_RED, True)
	gpio.output(GPIO_YLW, False)
	gpio.output(GPIO_GRN, True)
	
def ygOn():
	gpio.output(GPIO_RED, False)
	gpio.output(GPIO_YLW, True)
	gpio.output(GPIO_GRN, True)
	
def allOn():
	gpio.output(GPIO_RED, True)
	gpio.output(GPIO_YLW, True)
	gpio.output(GPIO_GRN, True)

def manualMod(args):
	global T
	while True:
		if not gpio.input(TOGGLE_BUTTON):
			if T == 1:
				T = 0
				print("swapping Normal Mode...")
				allOn()
				time.sleep(0.2)
				allOff()
				time.sleep(0.2)
				allOn()
				time.sleep(0.2)
				allOff()
				time.sleep(0.2)
			else:
				T = 1
				print("swapping Manual Mode...")
				allOn()
				time.sleep(0.2)
				allOff()
				time.sleep(0.2)
				allOn()
				time.sleep(0.2)
				allOff()
				time.sleep(0.2)
		time.sleep(0.5)
			
thrd = Thread(target = manualMod, args=('a'))
thrd.start()

try:
	while True:
		if T:
			if not gpio.input(GPIO_RBUTTON):
				if R == 0:
					R = 1
				else:
					R = 0
			elif not gpio.input(GPIO_YBUTTON):
				if Y == 0:
					Y = 1
				else:
					Y = 0
			elif not gpio.input(GPIO_GBUTTON):
				if G == 0:
					G = 1
				else:
					G = 0

			if R == 0 and Y == 0 and G == 0:
				allOff()
			if R == 1 and Y == 0 and G == 0:
				redOn()
			if R == 0 and Y == 1 and G == 0:
				ylwOn()
			if R == 0 and Y == 0 and G == 1:
				grnOn()
			if R == 1 and Y == 1 and G == 0:
				ryOn()
			if R == 0 and Y == 1 and G == 1:
				ygOn()
			if R == 1 and Y == 0 and G == 1:
				rgOn()
			if R == 1 and Y == 1 and G == 1:
				allOn()
			time.sleep(0.5)

		else:
			time.sleep(1)
			if T == 0:
				redOn()
			time.sleep(2)
			if T == 0:
				ylwOn()
			time.sleep(0.5)
			if T == 0:
				grnOn()
			time.sleep(2)

except KeyboardInterrupt:
    pass
finally:
    gpio.cleanup()