
echo = C:\msys64\usr\bin\echo.exe


Compiler = ../ti-cgt-msp430_18.12.4.LTS

Source = ${SOURCEPATH}/*.c
CMD = ${SOURCEPATH}/Cmd/*.cmd
Libs = ${SOURCEPATH}/Libs/*.lib
Dep = ${SOURCEPATH}/Dep

TargetPath = ../../Target/bin
ObjPath = ../../Target/obj

ORDERED_OBJS += \
"$(ObjPath)/*.obj" \
"$(Libs)" \
"$(CMD)" \
-llibc.a \

all: OBJS_C OBJS_ASM
	@$(MAKE) "Bachelor_Praxisprojekt.out"
	
OBJS_C: ${SOURCEPATH}/*.c
	@$(echo) 'Compiling C- Files'
	@$(echo) 'Invoking: MSP430 Compiler'
	"$(Compiler)/bin/cl430" -vmsp --use_hw_mpy=16 --include_path="${MSP430_INCLUDE}" \
	--include_path="C:/Users/Philipp/workspace_v9/MC_Praktikum" \
	--include_path="$(Compiler)/include" --advice:power=all \
	--define=__MSP430F1611__ -g --printf_support=full --diag_warning=225 \
	--obj_directory=$(ObjPath) --diag_wrap=off --display_error_number \
	--preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "${SOURCEPATH}/*.c"
	@$(echo) 'Finished building C-Files'
	@$(echo) ' '
	
OBJS_ASM: ${SOURCEPATH}/*.asm
	@$(echo) 'Compiling Asm- Files'
	@$(echo) 'Invoking: MSP430 Compiler'
	"$(Compiler)/bin/cl430" -vmsp --use_hw_mpy=16 --include_path="${MSP430_INCLUDE}" --include_path="C:/Users/Philipp/workspace_v9/MC_Praktikum" --include_path="$(Compiler)/include" --advice:power=all --define=__MSP430F1611__ -g --printf_support=minimal --diag_warning=225 --obj_directory=$(ObjPath) --diag_wrap=off --display_error_number --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "${SOURCEPATH}/*.asm"
	@$(echo) 'Finished building Asm-Files'
	@$(echo) ' '


Bachelor_Praxisprojekt.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(echo) 'Invoking: MSP430 Linker'
	"$(Compiler)/bin/cl430" -vmsp --use_hw_mpy=16 --advice:power=all \
	--define=__MSP430F1611__ -g --printf_support=minimal --diag_warning=225 \
	--diag_wrap=off --display_error_number -z -m"$(TargetPath)/Bachelor_Praxisprojekt.map" \
	--heap_size=80 --stack_size=80 --cinit_hold_wdt=on -i"${MSP430_INCLUDE}" \
	-i"$(Compiler)/lib" -i"$(Compiler)/include" --reread_libs --diag_wrap=off \
	--display_error_number --warn_sections --xml_link_info="$(TargetPath)/Bachelor_Praxisprojekt_linkInfo.xml" \
	--use_hw_mpy=16 --rom_model -o "$(TargetPath)/Bachelor_Praxisprojekt.out" $(ORDERED_OBJS)
	@$(echo) 'Finished building target: "$@"'
	@$(echo) ' '

