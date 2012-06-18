env = Environment()

env['CCFLAGS'] = '-g3 -O0'
env['LIBS'] = ['unwind', 'unwind-x86_64']

env.Program(['test/test.cpp', 'test/Foo.cpp', 'src/newdelete.cpp', 'src/stacktrace.cpp'])
