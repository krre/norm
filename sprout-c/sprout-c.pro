QT += core sql
QT -= gui

TARGET = ../../sprout/build/sproutc

CONFIG += c++11

TEMPLATE = lib

win32 {
    release: DESTDIR = $$OUT_PWD
    debug:   DESTDIR = $$OUT_PWD
}

SOURCES += \
    src/sproutc.cpp \
    src/defines.cpp

HEADERS += \
    src/sproutc.h \
    src/defines.h \
    src/macro.h

INCLUDEPATH += ../sprout-db/src
INCLUDEPATH += ../../LLVM/include

win32: LIBS += "-L../../sprout/build"
!win32: LIBS += -L../../sprout/build

LIBS += -lsproutdb

win32: LIBS += "-L../../LLVM/lib"
!win32: LIBS += -L../../LLVM/lib
#LIBS += -lLLVMCore -lLLVMSupport
LIBS += -lLLVMMCJIT -lLLVMDebugInfoDWARF -lLLVMDebugInfoPDB -lLLVMOrcJIT -lLLVMLTO -lLLVMObjCARCOpts -lLLVMLinker -lLLVMBitWriter -lLLVMXCoreDisassembler -lLLVMXCoreCodeGen -lLLVMXCoreDesc -lLLVMXCoreInfo -lLLVMXCoreAsmPrinter -lLLVMX86Disassembler -lLLVMX86AsmParser -lLLVMSystemZDisassembler -lLLVMSystemZCodeGen -lLLVMSystemZAsmParser -lLLVMSystemZDesc -lLLVMSystemZInfo -lLLVMSystemZAsmPrinter -lLLVMSparcDisassembler -lLLVMSparcCodeGen -lLLVMSparcAsmParser -lLLVMSparcDesc -lLLVMSparcInfo -lLLVMSparcAsmPrinter -lLLVMPowerPCDisassembler -lLLVMPowerPCCodeGen -lLLVMPowerPCAsmParser -lLLVMPowerPCDesc -lLLVMPowerPCInfo -lLLVMPowerPCAsmPrinter -lLLVMNVPTXCodeGen -lLLVMNVPTXDesc -lLLVMNVPTXInfo -lLLVMNVPTXAsmPrinter -lLLVMMSP430CodeGen -lLLVMMSP430Desc -lLLVMMSP430Info -lLLVMMSP430AsmPrinter -lLLVMMipsDisassembler -lLLVMMipsCodeGen -lLLVMMipsAsmParser -lLLVMMipsDesc -lLLVMMipsInfo -lLLVMMipsAsmPrinter -lLLVMHexagonDisassembler -lLLVMHexagonCodeGen -lLLVMHexagonDesc -lLLVMHexagonInfo -lLLVMCppBackendCodeGen -lLLVMCppBackendInfo -lLLVMBPFCodeGen -lLLVMBPFDesc -lLLVMBPFInfo -lLLVMBPFAsmPrinter -lLLVMARMDisassembler -lLLVMARMCodeGen -lLLVMARMAsmParser -lLLVMARMDesc -lLLVMARMInfo -lLLVMARMAsmPrinter -lLLVMAMDGPUCodeGen -lLLVMAMDGPUAsmParser -lLLVMAMDGPUUtils -lLLVMAMDGPUDesc -lLLVMAMDGPUInfo -lLLVMAMDGPUAsmPrinter -lLLVMAArch64Disassembler -lLLVMAArch64CodeGen -lLLVMAArch64AsmParser -lLLVMAArch64Desc -lLLVMAArch64Info -lLLVMAArch64AsmPrinter -lLLVMAArch64Utils -lLLVMX86CodeGen -lLLVMX86Desc -lLLVMX86Info -lLLVMMCDisassembler -lLLVMX86AsmPrinter -lLLVMX86Utils -lLLVMSelectionDAG -lLLVMAsmPrinter -lLLVMIRReader -lLLVMLineEditor -lLLVMPasses -lLLVMipo -lLLVMVectorize -lLLVMTableGen -lLLVMInterpreter -lLLVMExecutionEngine -lLLVMRuntimeDyld -lLLVMLibDriver -lLLVMOption -lLLVMMIRParser -lLLVMCodeGen -lLLVMScalarOpts -lLLVMProfileData -lLLVMObject -lLLVMMCParser -lLLVMBitReader -lLLVMInstCombine -lLLVMInstrumentation -lLLVMTransformUtils -lLLVMipa -lLLVMAsmParser -lLLVMTarget -lLLVMMC -lLLVMAnalysis -lLLVMCore -lLLVMSupport
win32: LIBS += -limagehlp
!win32: LIBS += -ldl -ltinfo
