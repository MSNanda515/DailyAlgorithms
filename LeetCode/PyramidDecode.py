def parse_message(message_file):
    """Parses the message and retrieves the mapping for the numbers to their corresponding strings"""
    code_words = {}
    code_lines = message_file.split('\n')
    max_code = 0
    for line in code_lines:
        if len(line) < 2: continue # ignores empty line at end if any
        code_num, code_str = line.split(" ", 1)
        code_num = int(code_num)
        code_words[code_num] = code_str
        max_code = max(max_code, code_num)
    return code_words, max_code



def decode(message_file):
    """Decodes the message"""
    code_words, max_code = parse_message(message_file)
    code_ptr = 1 # Pointer to the end of the pyramid for a row
    ptr_inc = 2 # The increment for the pointer for the end of the pyramid
    decoded_messag = ""
    while code_ptr <= max_code:
        print(code_ptr, end=" ")
        decoded_messag += code_words[code_ptr] + " "
        code_ptr += ptr_inc
        ptr_inc += 1
    return decoded_messag



testInput="""3 love\n6 computers\n2 dogs\n4 cats\n1 I\n5 you"""

def get_input():
    message = ""
    while True:
        try:
            # Read input from the user
            message += input() + "\n"
        except EOFError:
            break  # exit the loop when EOFError occurs (file closed)
    return message
    

def sol():
    """
    The method that finds the solution
    """
    message_file = get_input()
    print(decode(message_file))
    pass

if __name__ == "__main__":
    sol()