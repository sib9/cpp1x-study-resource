#!/usr/bin/env python

import os

def get_posts_name_and_path(dir_path):
    posts_name = []
    posts_path = []
    for file_name in os.listdir(dir_path):
        file_path = os.path.join(dir_path, file_name)
        posts_name.append(file_name)
        posts_path.append(file_path)

    return posts_name, posts_path


def split_header_and_content(file_path):
    try:
        file_handle = open(file_path, 'r')
    except IOError:
        print '%s open failure' % file_path
        return
    
    header = file_handle.readline().strip()
    content = file_handle.read()
        
    file_handle.close()

    return header, content
        
def parse_header(header):
    header_fields = header.split('|')

    url = header_fields[0]
    category = header_fields[1]
    date = header_fields[2]

    if not category:
        print 'empty category'
        
    return url, category, date

def get_yaml_title(file_name):
    return file_name.replace('.md', '')

def generate_yaml_header(title, category):
    yaml_header = '---\n'
    yaml_header += 'layout : post\n'
    yaml_header += 'title : \"%s\"\n' % title
    yaml_header += 'category : \"%s\"\n' % category
    yaml_header += '---\n'

    return yaml_header

def generate_yaml_file_name(based_url, date):
    return date + '-' + based_url + '.md'

def generate_complete_yaml_file(file_full_path, yaml_header, content):
    try:
        file_handle = open(file_full_path, 'w')
    except IOError:
        print '%s open failure' % file_full_path
        return

    file_handle.write(yaml_header)
    file_handle.write(content)

    file_handle.close()

    
def convert_one_to_yaml(old_name, old_path, new_dir):
    title = get_yaml_title(old_name)
    header, content = split_header_and_content(old_path)
    url, category, date = parse_header(header)

    yaml_header = generate_yaml_header(title, category)
    yaml_file_name = generate_yaml_file_name(url, date)

    full_path = os.path.join(new_dir, yaml_file_name)
    generate_complete_yaml_file(full_path, yaml_header, content)
    
def main():
    new_dir = './_posts'
    if not os.path.exists(new_dir):
        os.mkdir(new_dir)
    
    posts_name, posts_path = get_posts_name_and_path('../posts')

    for i in range(0, len(posts_name)):
        print 'convert process %d/%d' % (i+1, len(posts_path))
        convert_one_to_yaml(posts_name[i], posts_path[i], './_posts')

        
if __name__ == '__main__':
    main()
