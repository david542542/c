import re
# syn keyword StorageClass char 
from sys import argv
syntax_file = '/home/ubuntu/.vim/after/syntax/c.vim'
typedef_format = 'syn keyword StorageClass %s\n'
typedefs = re.findall(r'typedef\s+struct\s+([^\s{]+).+}\s*\1\s*;', open(argv[-1]).read(), re.DOTALL)
with open(syntax_file, 'r') as f: existing=f.read()
with open(syntax_file, 'a') as f:
    for typedef in typedefs:
        print(typedef)
        format_string = typedef_format % typedef
        if format_string not in existing: f.write(format_string)

