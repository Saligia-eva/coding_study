one=6-pthread-cond

main:
	gcc -E ${one}.c -o ${one}.i
	gcc -S ${one}.i -o ${one}.s
	gcc -c ${one}.s -o ${one}.o
	gcc  ${one}.o -lpthread -o ${one}.out
	@echo "===========OK==============="
clean:
	rm -rf ${one}.i
	rm -rf ${one}.s
	rm -rf ${one}.o
	@echo "++++++++++OK++++++++++++" 
