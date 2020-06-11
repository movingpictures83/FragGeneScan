#include "PluginManager.h"
#include <stdio.h>
#include <stdlib.h>
#include "FragGeneScanPlugin.h"

void FragGeneScanPlugin::input(std::string file) {
 inputfile = file;
}

void FragGeneScanPlugin::run() {}

void FragGeneScanPlugin::output(std::string file) {
std::string outputfile = file;
 std::string myCommand = "";
myCommand +=  "run_FragGeneScan.pl -genome="+inputfile+" -out="+outputfile+" -complete=0 -train=complete -thread=1 1>output.contig.tmp.frag.out 2>output.contig.tmp.frag.err";
 system(myCommand.c_str());
}

PluginProxy<FragGeneScanPlugin> FragGeneScanPluginProxy = PluginProxy<FragGeneScanPlugin>("FragGeneScan", PluginManager::getInstance());
