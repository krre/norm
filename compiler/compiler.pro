QT += core sql
QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = sprout

SOURCES += \
    src/main.cpp \
    src/compiler.cpp

HEADERS += \
    src/defines.h \
    src/macro.h \
    src/compiler.h

target.path += $$(SPROUT_HOME)/bin
INSTALLS += target

INCLUDEPATH += ../sproutlib/src
INCLUDEPATH += $$(LLVM_HOME)/include

LIBS += -L$$(SPROUT_HOME)/bin

CONFIG(debug, debug|release) {
    LIBS += -lsproutd
} else {
    LIBS += -lsprout
}

LIBS += -L$$(LLVM_HOME)/lib
LIBS += -lLLVMIRReader -lLLVMAsmParser -lLLVMInstrumentation -lLLVMLTO -lLLVMObjCARCOpts -lLLVMLinker -lLLVMBitWriter -lLLVMMCJIT -lLLVMDebugInfo -lLLVMTableGen -lLLVMInterpreter -lLLVMExecutionEngine -lLLVMRuntimeDyld -lLLVMLineEditor -lLLVMXCoreDisassembler -lLLVMXCoreCodeGen -lLLVMXCoreDesc -lLLVMXCoreInfo -lLLVMXCoreAsmPrinter -lLLVMX86Disassembler -lLLVMX86AsmParser -lLLVMX86CodeGen -lLLVMX86Desc -lLLVMX86Info -lLLVMX86AsmPrinter -lLLVMX86Utils -lLLVMSystemZDisassembler -lLLVMSystemZCodeGen -lLLVMSystemZAsmParser -lLLVMSystemZDesc -lLLVMSystemZInfo -lLLVMSystemZAsmPrinter -lLLVMSparcDisassembler -lLLVMSparcCodeGen -lLLVMSparcAsmParser -lLLVMSparcDesc -lLLVMSparcInfo -lLLVMSparcAsmPrinter -lLLVMR600CodeGen -lLLVMipo -lLLVMVectorize -lLLVMR600AsmParser -lLLVMR600Desc -lLLVMR600Info -lLLVMR600AsmPrinter -lLLVMPowerPCDisassembler -lLLVMPowerPCCodeGen -lLLVMPowerPCAsmParser -lLLVMPowerPCDesc -lLLVMPowerPCInfo -lLLVMPowerPCAsmPrinter -lLLVMNVPTXCodeGen -lLLVMNVPTXDesc -lLLVMNVPTXInfo -lLLVMNVPTXAsmPrinter -lLLVMMSP430CodeGen -lLLVMMSP430Desc -lLLVMMSP430Info -lLLVMMSP430AsmPrinter -lLLVMMipsDisassembler -lLLVMMipsCodeGen -lLLVMMipsAsmParser -lLLVMMipsDesc -lLLVMMipsInfo -lLLVMMipsAsmPrinter -lLLVMHexagonDisassembler -lLLVMHexagonCodeGen -lLLVMHexagonDesc -lLLVMHexagonInfo -lLLVMCppBackendCodeGen -lLLVMCppBackendInfo -lLLVMARMDisassembler -lLLVMARMCodeGen -lLLVMARMAsmParser -lLLVMARMDesc -lLLVMARMInfo -lLLVMARMAsmPrinter -lLLVMAArch64Disassembler -lLLVMMCDisassembler -lLLVMAArch64CodeGen -lLLVMSelectionDAG -lLLVMAsmPrinter -lLLVMCodeGen -lLLVMScalarOpts -lLLVMProfileData -lLLVMObject -lLLVMBitReader -lLLVMInstCombine -lLLVMTransformUtils -lLLVMipa -lLLVMAnalysis -lLLVMTarget -lLLVMCore -lLLVMAArch64AsmParser -lLLVMMCParser -lLLVMAArch64Desc -lLLVMAArch64Info -lLLVMAArch64AsmPrinter -lLLVMMC -lLLVMAArch64Utils -lLLVMOption -lLLVMSupport

win32: LIBS += -limagehlp -lpsapi -lshell32
!win32: LIBS += -lrt -ldl -ltinfo -lpthread -lz -lm
