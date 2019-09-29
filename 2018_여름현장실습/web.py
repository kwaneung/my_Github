from flask import Flask, render_template, request
import datetime

app = Flask(__name__)


@app.route('/')
@app.route('/', methods=['POST'])
def main():
	return render_template('main.html')

		
if __name__=="__main__":
	app.run(host='0.0.0.0', port=8888, debug=True)