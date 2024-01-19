#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Passes/PassBuilder.h"
#include "llvm/Passes/PassPlugin.h"
#include "llvm/IR/LegacyPassManager.h"

using namespace llvm;

struct MyFirstPass : public PassInfoMixin<MyFirstPass> {
	PreservedAnalyses run(Module& M, ModuleAnalysisManager&) {
		errs() << "Name of module " << M.getName() << "\n";
		return PreservedAnalyses::all();
	}
};