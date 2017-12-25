target_score,runs,overs,wickets=map(int,input("enter the team 1 total score and team 2 runs overs and wickets ").split())
fp = open("resource.txt")    
for i, line in enumerate(fp,1):
    if i == overs:        
        resource_left=100.00-float(line.split()[wickets])
        target=round((resource_left/100)*target_score)                   
        result=runs - target
        if result>0:
            print("team 2 won by",int(result))
        else:
            print("team 1 won by %d",int(result))
    elif i > 50:
        break
fp.close()


