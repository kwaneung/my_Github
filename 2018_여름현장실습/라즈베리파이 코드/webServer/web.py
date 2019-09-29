from flask import Flask, render_template, request
import datetime
from pyowm import OWM

API_key = 'e69e237ffdd34e7c19cdbb4adfa08a61'
owm = OWM(API_key)

app = Flask(__name__)

strTime = datetime.datetime.now().strftime("%y-%m-%d %H:%M")
 

@app.route('/')
@app.route('/', methods=['POST'])
def main():
	
	templateData = {
	'title' : 'Local Time',
	'time' : strTime
	}
 
	return render_template('main.html', **templateData)
	

def check_locale(password):

	if password=="1111":
		return True
	else:
		return False
		
		
@app.route('/weather', methods=['POST'])
def do_weather():

	city = request.form.get('city')
	
	obs = owm.weather_at_place(city)
	w = obs.get_weather()
	
	weatherData = {
		'city' : city,
		'status' : w.get_status(),
		'temp' : w.get_temperature(unit='celsius')['temp'],
		'title' : 'Local Time',
		'time' : strTime
	}
	
	return render_template('weather.html', **weatherData)

		
if __name__=="__main__":
	app.run(host='0.0.0.0', port=8888, debug=True)