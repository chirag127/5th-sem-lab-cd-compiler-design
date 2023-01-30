# extract zip file cd.zip

import zipfile
import os

def extract_zip(zip_file, extract_path):
    if not os.path.exists(extract_path):
        os.mkdir(extract_path)
    zip_file = zipfile.ZipFile(zip_file)
    for names in zip_file.namelist():
        zip_file.extract(names, extract_path)
    zip_file.close()

if __name__ == '__main__':
    extract_zip('cd.zip', 'extract')