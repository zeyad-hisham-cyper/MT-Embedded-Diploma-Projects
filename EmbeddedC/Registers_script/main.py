import PyPDF2 as pdf
import re

file_name = "Registers.pdf"
output_name = "registers.txt"
header_file_name = "registers.h"

def clean_bit_name(bit_name):
    #Function to clean bit name if the bit is reserved by the name '-'
    clean_name = re.sub(r'[^A-Za-z0-9]', '', bit_name.strip())
    return clean_name if clean_name else "Bit"

def generate_8bit_typedef(register_name):
    #function to generate the data type of 8-bit data registers 
    typedef = f"typedef union {{\n"
    typedef += f"\tuint8 Byte;\n"
    typedef += f"\tstruct{{\n"
    for i in range(8):
        typedef += f"\t\tuint8 Bit{i}:1;\n"
    typedef += f"\t}} Bits;\n"
    typedef += f"}} {register_name}_Type;\n"
    return typedef

def generate_16bit_typedef(register_name):
    #function to generate the data type of 16-bit data registers
    typedef = f"typedef union {{\n"
    typedef += f"\tuint16 TwoBytes;\n"
    typedef += f"\tstruct{{\n"
    for i in range(16):
        typedef += f"\t\tuint16 Bit{i}:1;\n"
    typedef += f"\t}} Bits;\n"
    typedef += f"}} {register_name}_Type;\n"
    return typedef

def generate_control_typedef(register_name, bits):
    #function to generate the data type of control data registers 
    typedef = f"typedef union {{\n"
    typedef += f"\tuint8 Byte;\n"
    typedef += f"\tstruct{{\n"
    for bit in bits:
        clean_bit = clean_bit_name(bit)
        if clean_bit != "Bit":
            typedef += f"\t\tuint8 {clean_bit}_Bit:1;\n"
        else:
            typedef += f"\t\tuint8 {clean_bit}:1;\n"
    typedef += f"\t}} Bits;\n"
    typedef += f"}} {register_name}_Type;\n"
    return typedef

with open(file_name, 'rb') as file:
    reader = pdf.PdfReader(file)
    text = "".join([page.extract_text() for page in reader.pages])

data_registers_8bit = []
data_registers_16bit = []
control_registers = []

for line in text.splitlines():
    if line.startswith('$'):
        try:
            line_parts = line.split()
            main_address = line_parts[0].replace('$', '')
            secondary_address = line_parts[1].strip('()').replace('$', '')
            register_name = line_parts[2]
            bits = line_parts[3:11]

            if bits and bits[-1].isdigit():
                bits.pop()

            if register_name == "UBRRH" or (len(bits) == 8 and not (bits[0].lower().startswith('timer') or bits[0].lower().startswith('counter'))):
                control_registers.append({'Main': main_address, 'Second': secondary_address, 'Name': register_name, 'Bits': bits})
            elif register_name.endswith('L') and any(r['Name'] == register_name[:-1] + 'H' for r in data_registers_8bit):
                high_reg = next(r for r in data_registers_8bit if r['Name'] == register_name[:-1] + 'H')
                data_registers_8bit.remove(high_reg)
                data_registers_16bit.append({
                    'Main': main_address,
                    'Second': secondary_address,
                    'Name': register_name[:-1],
                    'Bits': bits
                })
            else:
                data_registers_8bit.append({'Main': main_address, 'Second': secondary_address, 'Name': register_name, 'Bits': bits})
        except IndexError:
            continue



"""
# Printing the Registers Data in .txt file
with open(output_name, 'w') as output_file:
    output_file.write("Control Registers (8 bits):\n")
    output_file.write(f"{'Main Address':<20} {'Second Address':<20} {'Name':<20} {'Bits':<40}\n")
    output_file.write("=" * 100 + "\n") 

    for reg in control_registers:
        bits_str = ', '.join(reg['Bits'])
        output_file.write(f"{reg['Main']:<20} {reg['Second']:<20} {reg['Name']:<20} {bits_str:<40}\n")

    output_file.write("\n16-Bit Data Registers (High and Low Byte):\n")
    output_file.write(f"{'Main Address':<15} {'Second Address':<15} {'Name':<15} {'Bits':<40}\n")
    output_file.write("=" * 100 + "\n") 

    for reg in data_registers_16bit:
        bits_str = ', '.join(reg['Bits'])
        output_file.write(f"{reg['Main']:<20} {reg['Second']:<20} {reg['Name']:<20} {bits_str:<20}\n")

    output_file.write("\n8-Bit Data Registers:\n")
    output_file.write(f"{'Main Address':<20} {'Second Address':<20} {'Name':<20} {'Bits':<40}\n")
    output_file.write("=" * 100 + "\n") 

    for reg in data_registers_8bit:
        bits_str = ', '.join(reg['Bits'])
        output_file.write(f"{reg['Main']:<20} {reg['Second']:<20} {reg['Name']:<20} {bits_str:<40}\n")

print(f"Data saved to {output_name}")
print(f"Total 16-bit Registers: {len(data_registers_16bit)}")
print(f"Total 8-bit Registers: {len(data_registers_8bit)}")
"""

with open(header_file_name, 'w') as header_file:
    header_file.write("/*\n")
    header_file.write("============================================================================================\n")
    header_file.write("Name        : registers.h\n")
    header_file.write("Author      : Eng. Zeyad Hisham\n")
    header_file.write("Description : All ATmega32 Registers data types and defintion \n")
    header_file.write("============================================================================================\n")
    header_file.write("*/\n")
        
    header_file.write("typedef unsigned char uint8;\n")
    header_file.write("typedef unsigned short uint16;\n")
    
    header_file.write("\n\n/* Register Data Types */\n\n")
    header_file.write("/*======================*/\n")
    header_file.write("/* Data Registers 8-Bit*/\n")
    header_file.write("/*======================*/\n")
    for reg in data_registers_8bit:
        typedef = generate_8bit_typedef(reg['Name'])
        header_file.write(typedef)
 
    header_file.write("/*======================*/\n")
    header_file.write("/* Data Registers 16-Bit*/\n")
    header_file.write("/*======================*/\n")
    for reg in data_registers_16bit:
        typedef = generate_16bit_typedef(reg['Name'])
        header_file.write(typedef)

    header_file.write("/*======================*/\n")
    header_file.write("/*   Control Registers  */\n")
    header_file.write("/*======================*/\n")
 
    for reg in control_registers:
        typedef = generate_control_typedef(reg['Name'], reg['Bits'])
        header_file.write(typedef)
    
    header_file.write("\n\n/* Registers Difintions */\n\n")
    header_file.write("/*====================================*/\n")
    header_file.write("/*====================================*/\n")
    header_file.write("/* Definitions of Data Registers 8-Bit*/\n")
    header_file.write("/*====================================*/\n")
    for reg in data_registers_8bit:
        header_file.write(f"#define {reg['Name']}_REG (*(volatile {reg['Name']}_Type*)0x{reg['Second']})\n")
    
    header_file.write("/*=====================================*/\n")
    header_file.write("/* Definitions of Data Registers 16-Bit*/\n")
    header_file.write("/*=====================================*/\n")
    for reg in data_registers_16bit:
        header_file.write(f"#define {reg['Name']}_REG (*(volatile {reg['Name']}_Type*)0x{reg['Second']})\n")

    header_file.write("/*==================================*/\n")
    header_file.write("/* Definitions of Control Registers */\n")
    header_file.write("/*==================================*/\n")
    for reg in control_registers:
        header_file.write(f"#define {reg['Name']}_REG (*(volatile {reg['Name']}_Type*)0x{reg['Second']})\n")
