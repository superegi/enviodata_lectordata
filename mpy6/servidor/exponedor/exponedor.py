from flask import Flask
app = Flask(__name__)

@app.route('/')




def connect():
	cnx = sqlite3.connect('greenhouse.db')
	df = pd.read_sql_query("SELECT * FROM readings", cnx)

def mostrar():
	df.info()

def hello_world():
    return 'Hello, World!'

if __name__ == '__main__':
    app.run()
