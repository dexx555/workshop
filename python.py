    #exercice 1 TD1
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
print("7) fréquence dapparition de chaque valeur sous la forme dun dictionnaire : ")               
print(frequence)        
max_fréquente_value=None
max_fréquente_key=0
for i,j in frequence.items():
    if(j >= max_fréquente_key):
        max_fréquente_value = j
        max_fréquente_key = i
print("8) la valeur la plus fréquente ainsi que sa fréquence.")
print(max_fréquente_value) 
print(max_fréquente_key) 
equal_frequence = {}
for i, j in frequence.items():
    if j == max_fréquente_value:
            equal_frequence[i] = j
print("9) ")
print(equal_frequence)
#Q10 a returne


    #exercice 2 TD1

controle1 = [12, 15, 17, 9, 14, 18, 11, 15]
controle2 = [14, 13, 17, 10, 16, 18, 11, 12]
controle3 = [15, 14, 18, 8, 17, 16, 13, 15]
notes = []
notes.extend(controle1 + controle2 + controle3)
print("1) une liste contenant l’ensemble des notes obtenues aux trois contrôles. :")
print(notes)
diff_notes = set()
diff_notes.update(controle1 , controle2 , controle3)
print("2) un ensemble contenant toutes les notes différentes. :")
print(diff_notes)
comm_notes = []
for i in range(len(controle1)):
    if controle1[i] in controle2 and controle1[i] in controle3:
        comm_notes.append(controle1[i])
print("3) les notes communes aux trois contrôles. :")
print(comm_notes)  
unique_controle1_notes = []      
for i in range(len(controle1)):
    if controle1[i] not in controle2 and controle1[i] not in controle3:
       unique_controle1_notes.append(controle1[i])
print("3) les notes présentes dans le premier contrôle mais absentes des deux autres. :")
print(unique_controle1_notes)        