import RPi.GPIO as gpio
import time, datetime
import sqlite3


GPIO_BUTTON = 21
GPIO_MICRO = 16
GPIO_LED = 20
FLAG = 0


con = sqlite3.connect('test.db')
cur = con.cursor()


cur.execute("drop table if exists log;")
cur.execute("CREATE TABLE LOG (TIME text, STATE text);")


gpio.setmode(gpio.BCM)
gpio.setup(GPIO_BUTTON,gpio.IN)
gpio.setup(GPIO_MICRO,gpio.IN)
gpio.setup(GPIO_LED,gpio.OUT)
gpio.output(GPIO_LED, False)


while True:
	try:
		if gpio.input(GPIO_BUTTON):
			if FLAG:
				FLAG = 0
			else:
				FLAG = 1
				
		if FLAG:
			gpio.output(GPIO_LED, True)
			if not gpio.input(GPIO_MICRO):
				print("It works and detected!!")
				cur.execute("INSERT INTO LOG VALUES(?, ?);", (datetime.datetime.now().strftime("%y-%m-%d %H:%M:%S"), 'detected'))
			else:
				print("It works and not detected!!")
				cur.execute("INSERT INTO LOG VALUES(?, ?);", (datetime.datetime.now().strftime("%y-%m-%d %H:%M:%S"), 'not detected'))
			
		else:
			gpio.output(GPIO_LED, False)
			print("It doesn't works!!")
			cur.execute("INSERT INTO LOG VALUES(?, ?);", (datetime.datetime.now().strftime("%y-%m-%d %H:%M:%S"), 'not works'))
		time.sleep(0.1)
	except KeyboardInterrupt:
		gpio.cleanup()
		print("")
		
		cur.execute("select * from LOG;")
		for row in cur:
			print ("{0}, {1}".format(row[0], row[1]))
		cur.close()
		con.close()