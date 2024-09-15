import PyPDF2 as pdf

file_name = "Registers.pdf"
output_name = "registers.txt"

with open(file_name, 'rb') as file:
    reader = pdf.PdfReader(file)
    text = "".join([page.extract_text() for page in reader.pages])

data_registers = []
control_registers = []

for line in text.splitlines():
    if line.startswith('$'):
        data = line.split()
        full_address = "".join(data[0:2])
        addresses = full_address.split('(')
        main_address = addresses[0].strip()
        secondary_address = addresses[1].replace(')', '').strip() if len(addresses) > 1 else None
        name = data[2]
        bits = data[3:11]
        if bits and bits[-1].isdigit():
            bits.pop()
        if len(bits)==8 and not (bits[0].lower().startswith('timer') or bits[0].lower().startswith('counter')):
            control_registers.append({'Main': main_address, 'Second': secondary_address, 'Name': name, 'Bits': bits})
        else:
            data_registers.append({'Main': main_address, 'Second': secondary_address, 'Name': name, 'Bits': bits})

"""
for register in data_registers:
    print(f"{register} -------> {len(register['Bits'])}")

for register in control_registers:
    print(f"{register} -------> {len(register['Bits'])}")
"""

with open(output_name, 'w') as output_file:
    output_file.write("Control Registers (8 bits):\n")
    output_file.write(f"{'Main Address':<15} {'Second Address':<15} {'Name':<15} {'Bits':<40}\n")
    output_file.write("="*85 + "\n") 

    for reg in control_registers:
        bits_str = ', '.join(reg['Bits'])
        output_file.write(f"{reg['Main']:<15} {reg['Second']:<15} {reg['Name']:<15} {bits_str:<40}\n")

    output_file.write("\nData Registers (Other than 8 bits):\n")
    output_file.write(f"{'Main Address':<15} {'Second Address':<15} {'Name':<15} {'Bits':<40}\n")
    output_file.write("="*85 + "\n") 

    for reg in data_registers:
        bits_str = ', '.join(reg['Bits'])
        output_file.write(f"{reg['Main']:<15} {reg['Second']:<15} {reg['Name']:<15} {bits_str:<40}\n")

print(f"Data saved to {output_name}")
print(len(data_registers) + len(control_registers))