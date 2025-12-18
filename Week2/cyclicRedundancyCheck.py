def appendZeros(data, key):
    appendedData = data
    for i in range(len(key) - 1):
        appendedData += '0'
    return appendedData
def appendString(a,b):
    return a+b
def findXor(a, b):
    n = len(b)
    result = ""
    for i in range(1,n):
        result += '0' if a[i] == b[i] else '1'
    return result
def modulo2division(appendedData, key):
    n = len(appendedData)
    m = len(key)
    temp = appendedData[:m]
    while m < n:
        # print(f"Current temp = {temp}")
        if(temp[0] == '1'):
            temp = findXor(key, temp) + appendedData[m]
        else:
            temp = findXor('0'*m,temp) + appendedData[m] 
        m+=1
    if(temp[0] == '1'):
        temp = findXor(key,temp)
    else:
        temp = findXor('0'*m, temp)
    return temp
def checkZero(a):
    isZero = True
    for i in range(len(a)):
        if(a[i] == '1'):
            isZero = False
            break
    return isZero
def main():
    data = str(input("Enter data bits: "))
    key = str(input("Enter generator key(in binary): "))
    print("SENDER'S SIDE")
    appendedData = appendZeros(data,key)
    print(f"Data appended with k-1 zeros : {appendedData}")
    remainder = modulo2division(appendedData,key)
    print(f"Remainder is : {remainder}")
    sender_data = appendString(appendedData,remainder)
    print(f"Sender is sending : {sender_data}")
    print("RECEIVER'S SIDE")
    received_data = str(input("Enter received data: "))
    received_remainder = modulo2division(received_data,key)
    if(checkZero(received_remainder)):
        print(f"Data is correct(No errors detected)")
    else:
        print(f"Data is incorrect(ERROR DETECTED!)")

main()
# print(findXor("1001","1101")+"0" )
# a = appendZeros("100100","1101")
# print(f"Apppended data is {a}")
# remainder = modulo2division(a,"1101")
# print(f"Remainder is {remainder}")


