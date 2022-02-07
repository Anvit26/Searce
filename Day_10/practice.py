from os import ftruncate
from turtle import clear

print("hello world")

#loop
n = 5
while(n>0):
    print(n)
    n=n-1
print('done')

#conditional

if n<10:
    print('small')
if n>20:
    print('large')


# print float(99)/100
i=42
type(i)

f= float(i)

print (1+2*float(3)/4-5)

#function

def add(a,b):
    print('addition of ',a,b)
    c = a+b
    return c

print(add(1,3))

# while True:
#     line = input('> ')
#     if line == 'done':
#         break
#     print(line)
# print('Done')

for i in [1,'Hello','World','From','Searce']:
    print(i)
print('Done')

#string
str1 = 'hello'
str2 = 'world'
str12 = str1+' '+str2
print(str12)

str3 = '234'
v = int(str3)+1
print(v)

fruit = 'solving for better'
letter = fruit[1]
print(letter)

q=3
w=fruit[q-1]
print(w)

try:
    print(fruit[6])
except:
    print('index out of bound')

print('length of strig is: ',len(fruit) )

print(fruit[8:11])

print(fruit[:7])

print(fruit[7:])

print(fruit.upper())

print(fruit.find('for'))   

print(fruit.replace('better','improvers'))