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
LIBS += -lLLVMIRReader -lLLVMAsmParser -lLLVMInstrumentation -lLLVMLTO -lLLVMObjCARCOpts -lLLVMLinker -lLLVMBitWriter -lLLVMMCJIT -lLLVMDebugInfo -lLLVMTableGen -lLLVMInterpreter -lLLVMExecutionEngine -lLLVMRuntimeDyld -lLLVMLineEditor -lLLVMXCoreDisassembler -lLLVMXCoreCodeGen -lLLVMXCoreDesc -lLLVMXCoreInfo -lLLVMXCoreAsmPrinter -lLLVMX86Disassembler -lLLVMX86AsmParser -lLLVMX86CodeGen -lLLVMX86Desc -lLLVMX86Info -lLLVMX86AsmPrinter -lLLVMX86Utils -lLLVMSystemZDisassembler -lLLVMSystemZCodeGen -lLLVMSystemZAsmParser -lLLVMSystemZDesc -lLLVMSystemZInfo -lLLVMSystemZAsmPrinter -lLLVMSparcDisassembler -lLLVMSparcCodeGen -lLLVMSparcAsmParser -lLLVMSparcDesc -lLLVMSparcInfo -lLLVMSparcAsmPrinter -lLLVMR600CodeGen -lLLVMipo -lLLVMVectorize -lLLVMR600AsmParser -lLLVMR600Desc -lLLVMR600Info -lLLVMR600AsmPrinter -lLLVMPowerPCDisassembler -lLLVMPowerPCCodeGen -lLLVMPowerPCAsmParser -lLLVMPowerPCDesc -lLLVMPowerPCInfo -lLLVMPowerPCAsmPrinter -lLLVMNVPTXCodeGen -lLLVMNVPTXDesc -lLLVMNVPTXInfo -lLLVMNVPTXAsmPrinter -lLLVMMSP430CodeGen -lLLVMMSP430Desc -lLLVMMSP430Info -lLLVMMSP430AsmPrinter -lLLVMMipsDisassembler -lLLVMMipsCodeGen -lLLVMMipsAsmParser -lLLVMMipsDesc -lLLVMMipsInfo -lLLVMMipsAsmPrinter -lLLVMHexagonDisassembler -lLLVMHexagonCodeGen -lLLVMHexagonDesc -lLLVMHexagonInfo -lLLVMCppBackendCodeGen -lLLVMCppBackendInfo -lLLVMARMDisassembler -lLLVMARMCodeGen -lLLVMARMAsmParser -lLLVMARMDesc -lLLVMARMInfo -lLLVMARMAsmPrinter -lLLVMAArch64Disassembler -lLLVMMCDisassembler -lLLVMAArch64CodeGen -lLLVMSelectionDAG -lLLVMAsmPrinter -lLLVMCodeGen -lLLVMScalarOpts -lLLVMProfileData -lLLVMObject -lLLVMBitReader -lLLVMInstCombine -lLLVMTransformUtils -lLLVMipa -lLLVMAnalysis -lLLVMTarget -lLLVMCore -lLLVMAArch64AsmParser -lLLVMMCParser -lLLVMAArch64Desc -lLLVMAArch64Info -lLLVMAArch64AsmPrinter -lLLVMMC -lLLVMAArch64Utils -lLLVMOption -lLLVMSupport

win32: LIBS += -limagehlp -lpsapi -lshell32
!win32: LIBS += -lrt -ldl -ltinfo -lpthread -lz -lm
