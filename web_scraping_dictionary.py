import urllib.request
import re
import sys
print("hello")
url="http://www.dictionary.com/browse/"
print("enter the word to get meaning")
word=input()
url=url+word
try:
    data=urllib.request.urlopen(url).read()
    data1=data.decode("utf-8")
    #print(data1)
    m=re.search('meta name="description" content',data1)
    start_content=m.start()
    end_content=start_content+300
    content=data1[start_content:end_content]
    #print(content)
    k=re.search("definition, ",content)
    j=re.search(": ",content)
    if(not j):
        start_content=k.start()+11
        m=re.search("See more.",content)
        end_content=m.start()
        meaning=word+":-"+content[start_content:end_content]
        print(meaning)
    else:        
        start_content=k.start()+11
        end_content=j.start()
        meaning=word+":-"+content[start_content:end_content]
        print(meaning)
        m=re.search("See more.",content)
        ex_start_content=j.start()
        ex_end_content=m.start()
        example="exmaple:-"+content[ex_start_content:ex_end_content]
        print(example)
except:
    print("sorry,your word is not in the dictionary")
    
    
