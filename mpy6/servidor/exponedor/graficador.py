import pandas as pd
from datetime import datetime
import numpy as np
import matplotlib.pyplot as plt
from matplotlib import interactive
import sqlite3
import time


interactive(True)




# Create your connection.
cnx = sqlite3.connect('greenhouse.db')
df = pd.read_sql_query("SELECT * FROM readings", cnx)


df.info()
print(df.head())

df.timestamp = pd.to_datetime(df.timestamp)
df.source = df.source.str.replace('84:0d:8e:b0:f4:5c', 'TipoA')
df.source = df.source.str.replace('dc:4f:22:5f:4b:27', 'TipoB')

BD = df[['source', 'timestamp','airtemp', 'humidity']]


print('ss')


print(BD.humidity.describe())
print(BD.airtemp.describe())

print(BD)





time.sleep(2)

