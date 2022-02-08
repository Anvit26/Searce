#reading from file

fileName = 'text.txt'
# fileHead = open('text.txt')
# fileName = input('Enter file name:')

try:
    fileHead = open(fileName)
except:
    print('Can not open file: ', fileName)
    quit()

count = 0
for line in fileHead:
    line = line.rstrip()
    print(line)
    count=count+1
print('total lines in file: ',count)

#searching in file
print('Find in file')
fileHead = open('text.txt')
for line in fileHead:
    if(line.startswith('Each')):
        print(line)

#list
a=[3,2,1]
b=[4,5,3]
c=a+b
c.append(6)
print(c)
print(3 in a)
print(1 in b)
c.sort()
print(c)
print(sum(c))

#string
line = 'hello world from searce'
words = line.split()
print(words)
print(words[0])

# dictionaries
month = dict()
month['jan'] = 31
month['fab'] = 28
month['mar'] = 31
month['apr'] = 30
print(month)

#count words
count = dict()
fileHead = open(fileName)

for line in fileHead:
    words=line.split()
    for word in words:
        count[word] = count.get(word,0)+1
print('Counts',count)

largest = -1
larWord = None
for i,j in count.items():
    print(i,j)
    if(j>largest):
        largest=j
        larWord=i
    
print(largest,larWord)