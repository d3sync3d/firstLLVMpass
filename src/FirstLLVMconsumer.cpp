#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"

#include "Pass.h"

using namespace llvm;

int main(int argv, char** argc) {
	cl::opt<std::string> InputFileName(cl::Positional, cl::Required, cl::desc("<input file>"), cl::value_desc("filename"));
	cl::ParseCommandLineOptions(argv, argc, "LLVM everything bitch\n");

	LLVMContext Context;
	SMDiagnostic Err;

	std::unique_ptr<Module> moduleObj = parseIRFile(InputFileName, Err, Context);

	if (!moduleObj) {
		errs() << "Failed to get module\n";
		return 1;
	}
	
	PassBuilder PB;
	ModuleAnalysisManager MAM;
	PB.registerModuleAnalyses(MAM);

	PassManager<Module> PM;
	PM.addPass(MyFirstPass());
	PM.run(*moduleObj, MAM);

	return 0;
}