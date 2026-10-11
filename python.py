n = [17, -4, 23, 17, 8, 42, -9, 15, 23, 8, 31, 42, 5, -4, 19]
positive=[]
for i in range(len(n)):
    if n[i] > 0 :
        positive.append(n[i])
print("1) nouvelle liste contenant uniquement les valeurs positives. :")        
print(positive)       
re=[]
for i in range(len(n)) :
    if n[i] > 0 :
        re.append(n[i])
    else :
       re.append(0)
print("2) deuxième liste contenant les valeurs négatives remplacées par 0. :")       
print(re)   
max=n[0]       
min=n[0]
for i in range(len(n)):
    if n[i] > max :
        max=n[i]
    elif n[i] < min :
        min=n[i] 
print("3) le minimum et le maximum de la liste. :")           
print(max) 
print(min)     
s=0  
for i in range(len(n)):
    s+=n[i]
moyenne=s/len(n)
print("4) le moyenne arithmétique des éléments. :")
print(moyenne)
deja_trite=[]
d=[]
for i in range(len(n)):
    if n[i] not in deja_trite :
        cmp=0
        for j in range(len(n)):
            if n[i]==n[j]:
                cmp+=1

        if cmp >=2:
            d.append(n[i])

print("5)liste contenant uniquement les valeurs apparaissant au moins deux fois. :")
print(d)              
distinct=[]      
for i in range(len(n)):
    if n[i] not in d :
        distinct.append(n[i])
print("6) liste contenant les valeurs distinctes dans lordre de leur première apparition. :")
print(distinct)  
frequence = {}
for i in range(len(n)):
    cmp=0
    for j in range(len(n)):
        if n[i]==n[j]:
            cmp+=1
    if(cmp >= 2):
        frequence[n[i]]=cmp
    else:
        frequence[n[i]]=1
print("6)fréquence dapparition de chaque valeur sous la forme dun dictionnaire : ")               
print(frequence)        
max_fréquente=0
for i in frequence.values():
    if(i >= max_fréquente):
        max_fréquente = frequence.items()
print("la valeur la plus fréquente ainsi que sa fréquence.")
print(max_fréquente)    