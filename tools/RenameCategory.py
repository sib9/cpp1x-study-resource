#/usr/bin/env python

import os

def get_posts_name_and_path(dir_path):
    posts_path = []
    for file_name in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file_name)
        posts_path.append(file_path)

    return posts_path

def rename_category(file_path, old, new):
    file_in = open(file_path, 'r')
    content = []
    while True:
        line = file_in.readline()
        if not line:
            break
        content.append(line)
    file_in.close()

    if content[0].split('|')[1] == old:
        content[0] = content[0].replace(old, new)
        print content[0]

    file_out = open(file_path, 'w')
    for line in content:
        file_out.write(line)
    file_out.close()
    
def main():
    posts_path = get_posts_name_and_path('../posts')
    for item in posts_path:
        rename_category(item, 'Document', 'Language')

if __name__ == '__main__':
    main()
