import matplotlib
import matplotlib.pyplot as pt
def calculate(overs):        
    fp = open("resource.txt")    
    for i, line in enumerate(fp,1):
        if i == overs:            
            resource_left=100.00-float(line.split()[wickets])
            target=round((resource_left/100)*target_score)
            fp.close()
            return target
            """print(target)
            result=runs - target
            if result>0:
                print("team 2 won by",int(result))
            else:
                print("team 1 won by %d",int(result))"""
        elif i > 50:
            break

target_score,runs,overs,wickets=map(int,input("enter the team 1 total score and team 2 runs overs and wickets ").split())
x=[overs+i for i in range(10)]
print(x)
y=list(map(calculate,x))
print(y)
fig=pt.figure()
rect=fig.patch
rect.set_facecolor("green")
g1=fig.add_subplot(1,1,1,facecolor='black')
g1.plot(x,y,'red',linewidth=4)
g1.set_title("dl method target")
g1.set_xlabel("overs")
g1.set_ylabel("score")
g1.tick_params(axis='x',color='white')
g1.tick_params(axis='y',color='white')
g1.spines['top'].set_color('w')
g1.spines['left'].set_color('w')
g1.spines['right'].set_color('w')
g1.spines['bottom'].set_color('w')
pt.show()
