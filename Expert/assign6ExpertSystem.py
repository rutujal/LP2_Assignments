print('\n\tWelcome to Employee Perfomance Evauation Expert system')
scoreCnt=0
print("\nU=>Unsatisfactory F=>Fair S=>Satisfactory G=>Good E=>Excellent NA=>Not applicable")
print()
questionSet=["Arrives for work on time","Arrives for meetings on time","Meets work deadlines",
"Identifies problems and Proposes solutions to problems","Uses office hrs effectivly",
"Possess required job skills","Consults with supervisors and coworkers as necessary",
"Demonstrates effective leadership skills as appropriate","Positive atitude towards job and company",
"Deals effectively and professionally with employees in other areas","Responds appropriately to"
 "feedback on job performance"]
for i in range(11):
    print(questionSet[i])
    print()
    ans=input()
    if(ans=="S" or "s"):
        scoreCnt+=1
    elif(ans=="U" or "u"):
        scoreCnt-=1
    elif(ans=="G" or "g"):
        scoreCnt+=2
    elif(ans=="E" or "e"):
        scoreCnt+=3
    elif(ans=="F" or "f"):
        scoreCnt+=1
    elif(ans=="NA" or "na"):
        continue
print("Evaluation score: ",scoreCnt)
if(scoreCnt<=5):
    print("Poor Performer!")
elif(scoreCnt>5 and scoreCnt<=15):
    print("Average Performer!")
elif(scoreCnt>15 and scoreCnt<=25):
    print("Good Performer!")
elif(scoreCnt>25):
    print("Exellent Performer!")


