import Options
from os import unlink, symlink, popen
from os.path import exists

srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
    opt.tool_options("compiler_cxx")

def configure(conf):
    conf.check_tool("compiler_cxx")
    conf.check_tool("node_addon")

    #conf.check_cfg(package='scws', args='--cflags --libs', uselib_store='libscws')

def build(bld):
    obj = bld.new_task_gen("cxx", "shlib", "node_addon")
    obj.target = "node_scws"
    obj.source = "scws.cpp"
    obj.cxxflags = ["-D_FILE_OFFSET_BITS=64", "-D_LARGEFILE_SOURCE"]
    obj.lib = [ 'scws' ]

def shutdown():
    if Options.commands['clean']:
        if exists('node_scws.node'): unlink('node_scws.node')
    else:
        if exists('build/default/noe_scws.node') and not exists('node_scws.node'):
            symlink('build/default/node_scws.node', 'node_scws.node')
