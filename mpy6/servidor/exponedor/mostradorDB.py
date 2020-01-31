import sqlite3
 
con = sqlite3.connect('greenhouse.db')
 
cursor = con.cursor()
cursor.execute("SELECT name FROM sqlite_master WHERE type='table';")
print(cursor.fetchall())

cursor.execute("SELECT * FROM readings")
rows = cursor.fetchall()
for row in rows:
    print (row)
