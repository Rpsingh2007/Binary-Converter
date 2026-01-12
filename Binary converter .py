def num_to_binary():
    
    #code to convert decimal numbers to binary
    def decimal_to_binary(decimal_num):
        if decimal_num == 0:
            return "0"

        binary_representation = ""
        while decimal_num > 0:
            remainder = decimal_num % 2
            binary_representation+=str(remainder) 
            decimal_num //= 2  # Integer division
        return binary_representation[::-1]  # Reverse the string to get the correct binary representation
            

    # code to convert octal numbers to binary
    def octal_to_binary(octal_num):
        dict1={'0':'000','1':'001','2':'010','3':'011','4':'100','5':'101','6':'110','7':'111'} #dictionary to map octal to binary
        binary_representation=""
        for digit in str(octal_num):
            if digit in dict1:
                binary_representation+=dict1[digit]
            else:
                return "Invalid octal number"
        return binary_representation.lstrip('0')  # Remove leading zeros
        
    # code to convert hexadecimal numbers to binary

    def hexadecimal_to_binary(hexadecimal_num): 
        dict2={'0':'0000','1':'0001','2':'0010','3':'0011','4':'0100','5':'0101','6':'0110','7':'0111',
                '8':'1000','9':'1001','A':'1010','B':'1011','C':'1100','D':'1101','E':'1110','F':'1111'} #dictionary to map hexadecimal to binary
        binary_representation=""
        for digit in str(hexadecimal_num).upper():
            if digit in dict2:
                binary_representation+=dict2[digit]
            else:
                return "Invalid hexadecimal number"
        return binary_representation.lstrip('0')  # Remove leading zeros
    

    # Get input from the user
    def input_main():
        while True:
            operation = input("1 For Decimal to Binary\n"\
                              "2 For Octal to Binary\n"\
                              "3 For Hexadecimal to Binary\n"\
                              "q to quit \n"\
                              "Choose the operation (1 to 3 or 'q'): ")
            if operation.lower()=="q":
                print("Exiting the program.") 
                print(40*"=")  
                break
            try:
                number_input = int(input("Enter a  number: "))
            except ValueError:
                print("Invalid input. Please enter an integer.")
            if operation == '1':
                binary_result = decimal_to_binary(number_input)       # Call the function
                print("The binary representation of ",number_input,"is:",binary_result)   
            elif operation == '2':
                binary_result = octal_to_binary(number_input)       # Call the function
                print("The binary representation of octal ",number_input,"is:",binary_result)

            elif operation == '3':
                binary_result = hexadecimal_to_binary(number_input)       # Call the function
                print("The binary representation of hexadecimal ",number_input,"is:",binary_result)
            
            else:
                print("Invalid operation selected. Please choose 1 ,2 ,3 or 'q'.")
            
            
    input_main() 


def binary_to_number():

    #code to convert decimal numbers to binary
    def binary_to_decimal(binary_num):
        if binary_num == 0:
            return "0"

        decimal_representation = 0
        if "1" in binary_num:
            reverse=binary_num[::-1]  # Reverse the binary number string
            for i in range(len(reverse)):
                if reverse[i] == '1':
                    decimal_representation += 2**i
           
            
        return decimal_representation
    # code to convert binary to octal number

    def binary_to_octal(binary_num):
        dict1={'0':'000','1':'001','2':'010','3':'011','4':'100','5':'101','6':'110','7':'111'} #dictionary to map octal to binary
        octal_representation=""
        L=[]
        a=binary_num[::-1]  # Reverse the binary number string
        while len(a)%3!=0:  # Pad with leading zeros to make length a multiple of 3
            a=a+'0'
        for i in range(0,len(a),3): 
            L.append(a[i:i+3][::-1])  # Group into chunks of 3 and reverse each chunk
        L=L[::-1]  # Reverse the list to restore original order 
        for j in range(len(L)):
            for key,value in dict1.items():
                if L[j]==value:
                    octal_representation+=key  # Map each binary chunk to its octal digit
                    break
        return octal_representation 
    
    # code to convert binary to hexadecimal number
    def binary_to_hexadecimal(binary_num): 
        dict2={'0':'0000','1':'0001','2':'0010','3':'0011','4':'0100','5':'0101','6':'0110','7':'0111',
                '8':'1000','9':'1001','A':'1010','B':'1011','C':'1100','D':'1101','E':'1110','F':'1111'} #dictionary to map hexadecimal to binary
        hexadecimal_representation=""
        L=[]
        a=binary_num[::-1]  # Reverse the binary number string
        while len(a)%4!=0:  # Pad with leading zeros to make length a multiple of 4
            a=a+'0'
        for i in range(0,len(a),4): 
            L.append(a[i:i+4][::-1])  # Group into chunks of 4 and reverse each chunk
        L=L[::-1]  # Reverse the list to restore original order 
        for j in range(len(L)):
            for key,value in dict2.items():
                if L[j]==value:
                    hexadecimal_representation+=key  # Map each binary chunk to its octal digit
                    break
        
        return hexadecimal_representation

    # Get input from the user
    def input_main():
        while True:
            operation = input("1 Binary to Decimal\n"\
                              "2 Binary to octal\n"\
                              "3 Binary to Hexadecimal\n"\
                              "q to quit \n"\
                              "Choose the operation (1,2,3 or 'q' ): ")
            if operation.lower()=="q":
                print("Exiting the program.") 
                print(40*"=")  
                break
            number_input = input("Enter a binary number: ")
            for i in number_input:
                    if i not in "01":
                        print("Invalid input. Please enter a valid binary number.")
                        return
            if operation == '1':
                
                decimal_result = binary_to_decimal(number_input)       # Call the function
                print("The decimal representation binary of  ",number_input,"is:",decimal_result)
            elif operation == '2':
                
                octal_result = binary_to_octal(number_input)       # Call the function
                print("The octal representation binary of  ",number_input,"is:",octal_result)
            elif operation == '3':
                
                hexadecimal_result = binary_to_hexadecimal(number_input)       # Call the function
                print("The  Hexadecimal representation binary of  ",number_input,"is:",hexadecimal_result)
            
            else:
                print("Invalid operation selected. Please choose 1,2,3or 'q'.")
            
    input_main()
while True:
    op=input("1 To convert Number to Binary \n"\
             "2 To convert  Binary to Number  \n"\
             "q to quit \n"\
             "Choose the operation (1 or 2 or q): ")
    print(40*"=")
    if op=="1":
        num_to_binary()
    elif op=="2":
        binary_to_number()
    elif op=="q":
        print("Exiting the program.")   
        exit()
    else:
        print("Invalid operation selected. Please choose 1 or 2.") 
    