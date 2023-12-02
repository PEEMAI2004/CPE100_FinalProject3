import csv
import random
import string
import csv
import random
import string


def generate_phones(model_file_path, phone_file_path, n):
    # Generate new phones and save to csv file
    with open(model_file_path, 'r') as model_file, open(phone_file_path, 'w', newline='') as phone_file:
        model_reader = csv.reader(model_file)
        phone_writer = csv.writer(phone_file)
        
        # Skip the header row in NewModel.csv
        next(model_reader)
        
        # Write the header row in Newphone.csv
        phone_writer.writerow(['SN', 'MN', 'VC', 'Purchase-Price'])
        
        # Loop through each row in NewModel.csv
        for row in model_reader:
            vendor_code = row[0]
            model_number = row[1]
            manufacture = row[2]
            model_name = row[3]
            color = row[4]
            storage = row[5]
            sell_price = int(row[6])
            
            # Generate n phones per vendor code
            for _ in range(n):
                # Generate random SN using 2 first letters of Vendor-Code and 13 random numbers
                sn = vendor_code[:2] + ''.join(random.choices(string.digits, k=13))
                
                # Write the phone details to Newphone.csv
                phone_writer.writerow([sn, model_number, vendor_code, sell_price - 5000])
# ask user for number of phones to generate and path to read and write files
n = int(input("Enter number of phones to generate per vendor code: "))
model_file_path = input("Enter path to read file: ")
phone_file_path = input("Enter path to create file: ")
generate_phones(model_file_path, phone_file_path, n)