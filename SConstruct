#!python
import os, subprocess

# define our target
target_path = 'bin/'
target_name = 'libdiscord'

# Local dependency paths, adapt them to your setup
godot_headers_path = "godot-cpp/godot_headers/"
cpp_bindings_path = "godot-cpp/"
discord_rpc_path = "discord-rpc/"
cpp_library = "godot-cpp"
rpc_library = "discord-rpc"

target = ARGUMENTS.get("target", "debug")
platform = ARGUMENTS.get("platform", "windows")
bits = ARGUMENTS.get("bits", 64)

# This makes sure to keep the session environment variables on windows, 
# that way you can run scons in a vs 2017 prompt and it will find all the required tools
env = Environment()
if platform == "windows":
    env = Environment(ENV = os.environ)

if ARGUMENTS.get("use_llvm", "no") == "yes":
    env["CXX"] = "clang++"

def add_sources(sources, directory):
    for file in os.listdir(directory):
        if file.endswith('.cpp'):
            sources.append(directory + '/' + file)

if platform == "osx":
    env.Append(CCFLAGS = ['-g','-O3', '-arch', 'x86_64'])
    env.Append(LINKFLAGS = ['-arch', 'x86_64'])
    target_path += 'osx/'
    cpp_library += '.osx.64'
    rpc_library += '.osx.64'

elif platform == "linux":
    env.Append(CCFLAGS = ['-fPIC', '-g','-O3', '-std=c++14'])
    target_path += 'x11/'
    cpp_library += '.linux.64'
    rpc_library += '.linux.64'

elif platform == "windows":
    if target == "debug":
        env.Append(CCFLAGS = ['-EHsc', '-D_DEBUG', '-MDd'])
    else:
        env.Append(CCFLAGS = ['-O2', '-EHsc', '-DNDEBUG', '-MD'])
    target_path += 'win' + str(bits) + '/'
    cpp_library += '.windows.' + str(bits)
    rpc_library += '.windows.' + str(bits)

env.Append(CPPPATH=[
	'.', 'src/', godot_headers_path, cpp_bindings_path + 'include/', cpp_bindings_path + 'include/core/', cpp_bindings_path + 'include/gen/', 'discord-rpc/src',
	discord_rpc_path + "include/", discord_rpc_path + "src/",
])
env.Append(LIBPATH=[cpp_bindings_path + 'bin/', discord_rpc_path + "/lib"])
env.Append(LIBS=[cpp_library, rpc_library])

sources = []
add_sources(sources, "src")

library = env.SharedLibrary(target=target_path + target_name, source=sources)
Default(library)
