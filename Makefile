app.elf: main.c
	gcc main.c -o app.elf -lpanel -lncurses

.PHONY: ct c

ct: app.elf
	./app.elf
	rm app.elf

c:
	rm app.elf
