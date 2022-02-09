from audioop import add
from email import header
import re
import socket
import urllib.request, urllib.parse, urllib.error 
# from bs4 import BeautifulSoup
# import ssl
import xml.etree.ElementTree as ET
import json

#tuples
x = ('abc','def','ghi')
for ele in x:
    print(ele)

print(max(x))

num=(50,40,44,42,30,1)
print(num)
(a,b) = (1,3)
print(a,b)

c={'a':100,'b':11,'c':22}
print(c)
tmp=list()
for k,v in c.items():
    tmp.append((v,k))

tmp = sorted(tmp,reverse=True)
print(tmp)

#top 5 words in a file
print('top 5')
fhead=open('text.txt')

cnt = dict()
for line in fhead:
    words = line.split()
    for word in words:
        cnt[word] = cnt.get(word,0)+1

x=sorted(cnt.items())
print(x[:5])

tmp = list()
for k,v in cnt.items():
    newTup = (v,k)
    tmp.append(newTup)

tmp=sorted(tmp,reverse=True)

for v,k in tmp[:5]:
    print(k,v)

print('regex')
fhead=open('text.txt')
for line in fhead:
    if re.search('technology',line):
        print(line)


text = 'From anvit.dave@abc.com Wed Feb 9'
host = re.findall('@([^ ]*)',text)
print(text,' host name is ',host)

#Networked Programs
print('\nNetworked Programs\n')

mySocket = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
mySocket.connect(('data.pr4e.org',80))
cmd = 'GET http://data.pr4e.org/romeo.txt HTTP/1.0\n\n'.encode()
mySocket.send(cmd)

while True:
    data = mySocket.recv(512)
    if(len(data)<1):
        break
    print(data.decode())
mySocket.close()

print('using URLlib')
netCall = urllib.request.urlopen('http://data.pr4e.org/romeo.txt')
for line in netCall:
    print(line.decode().strip())

# web scrapping
# url='http://www.dr-chuck.com/page1.htm'
# html=urllib.request.urlopen(url).read()
# soup=BeautifulSoup(html,'html.parser')

# tags=soup('a')
# for tag in tags:
#     print(tag.get('href',None))


print('\nXML')
data = '''
    <persons>
        <person id="1">
            <name>Anvit</name>
            <phone>0123456789</phone>
            <email hide="yes"/>
        </person>
        <person id="2">
            <name>Max</name>
            <phone>3456789012</phone>
            <email hide="yes"/>
        </person>
    </persons>
'''

# print('Name:',tree.find('name').text)
# print('Attribute:',tree.find('email').get('hide'))

tree=ET.fromstring(data)
dta=tree.findall('person')

print('count:',len(dta))

for item in dta:
    print('Name',item.find('name').text)
    print('Phone',item.find('phone').text)

print('\nJSON')
items='''
    [
        {
            "id":"1",
            "name":"Steve"
        },
        {
            "id":"2",
            "name":"Jeff"
        }
    ]
'''

info=json.loads(items)
for item in info:
    print('Name ',item['name'])
    print('Id',item['id'])

serviceUrl = 'http://maps.googleapis.com/maps/api/geocode/json?'

while True:
    address = input('Enter Location: ')
    if(len(address)<1):
        break
    url = serviceUrl + urllib.parse.urlencode({'address':address})
    print('Getting Data From',url)
    uh=urllib.request.urlopen(url)
    data=uh.read().decode()
    print('Retrieved',len(data),'characters')

    try:
        js=json.loads(data)
    except:
        js=None
    
    if not js or 'status' not in js or js['status'] != 'OK':
        print('=====Error Getting Data=====')
        print('Keys missing')
        print(data)
        continue
    
    lat = js["results"][0]["geometry"]["location"]["lat"]
    lng = js["results"][0]["geometry"]["location"]["lng"]
    print('lat',lat,'lng',lng)
    location = js["results"][0]["formatted_address"]
    print(location)

