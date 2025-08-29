message = input("Enter a message: ")
shift = int(input("Enter the number of shifts: "))
a = [ord(char) for char in message]
a_new=[]
for i in a:
    if (i>90-shift and i<97):
        a_new.append(i-26+shift)
    elif (i>122-shift):
        a_new.append(i-26+shift)
    elif (i==32):
        a_new.append(i)
    else:
        a_new.append(i+shift)
# print(a)
# print(a_new)
c=[chr(num) for num in a_new]
print("The encoded word is:",("".join(c)))
# print(c)
d=[ord(char) for char in c]
# print(d)
d_new=[]
for i in d:
    if (i==32):
        d_new.append(i)
    elif (i<65+shift):
        d_new.append(i+26-shift)
    elif (i<97+shift and i>90):
        d_new.append(i+26-shift)
    else:
        d_new.append(i-shift)
# print(d_new)
e=[chr(num) for num in d_new]
print("The decoded word is:",("".join(e)))
    




    

    
