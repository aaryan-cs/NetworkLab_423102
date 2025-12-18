def numberOfParityBits(data):
    m = len(data)
    for r in range(64):
        if(pow(2,r) >= m+r+1):
            return r

def getParityPositions(r):
    return [pow(2, i) for i in range(r)]

def hamming_code():
    original_data = str(input("Enter sender data : "))
    m = len(original_data)
    r = numberOfParityBits(original_data)
    total_len = m + r
    codeword = ['0'] * (total_len + 1) 
    parity_positions = getParityPositions(r)
    data_idx = 0
    for i in range(1, total_len + 1):
        if i not in parity_positions:
            codeword[i] = original_data[data_idx]
            data_idx += 1
    for p_pos in parity_positions:
        parity_val = 0
        for i in range(1, total_len + 1):
            if i & p_pos:
                if i != p_pos: 
                     parity_val ^= int(codeword[i])
        codeword[p_pos] = str(parity_val)

    sent_codeword_str = "".join(codeword[1:])
    print(f"Generated Codeword: {sent_codeword_str}")

    received_list = list(codeword)
    error_pos_to_flip = 5
    
    current_bit = received_list[error_pos_to_flip]
    received_list[error_pos_to_flip] = '0' if current_bit == '1' else '1'
    
    received_codeword_str = "".join(received_list[1:])
    print(f"Received (Error at pos 5): {received_codeword_str}")

    syndrome = 0
    for i in range(r):
        p_pos = pow(2, i)
        parity_check = 0
        for k in range(1, total_len + 1):
            if k & p_pos:
                parity_check ^= int(received_list[k])
        
        if parity_check == 1:
            syndrome += p_pos
    print("RESULTS:")
    print(f"1. Syndrome: Decimal={syndrome}, Binary={bin(syndrome)[2:]}")
    if syndrome > 0:
        print(f"   (Error detected at position {syndrome}")
        bad_bit = received_list[syndrome]
        received_list[syndrome] = '0' if bad_bit == '1' else '1'
    corrected_codeword = "".join(received_list[1:])
    print(f"2. Corrected Codeword: {corrected_codeword}")
    extracted_data = ""
    for i in range(1, total_len + 1):
        if i not in parity_positions:
            extracted_data += received_list[i]
    print(f"3. Extracted Original Data: {extracted_data}")
hamming_code()