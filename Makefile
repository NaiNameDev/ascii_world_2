app.elf: main.c
	gcc main.c -o app.elf -lncurses

.PHONY: ct c

ct: app.elf
	./app.elf
	rm app.elf

c:
	rm app.elf
