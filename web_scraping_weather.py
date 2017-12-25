import re
import urllib.request


#print(data1)
try:
    print("enter the city for weather report")
    city=input()
    url="http://www.weather-forecast.com/locations/"+city+"/forecasts/latest"
    data=urllib.request.urlopen(url).read()
    data1=data.decode("utf-8")
    a=re.search('<span class="phrase">',data1)    
    report_start=a.start()+21
    report_end=a.start()+300
    report=data1[report_start:report_end]    
    b=re.search('.</span>',report)    
    report_end=b.start()
    final_report=city+" weather report :- "+report[:report_end]
    print(final_report)
except:
    print("invalid entry")
    
