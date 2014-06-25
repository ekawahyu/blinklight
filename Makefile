# Default target
all: project.hex

# Compile phase
blinklight.rel : blinklight.c
	sdcc -c -mmcs51 --verbose --model-small blinklight.c
	
led.rel : led.c
	sdcc -c -mmcs51 --verbose --model-small led.c

button.rel : button.c
	sdcc -c -mmcs51 --verbose --model-small button.c
	
interrupt.rel : interrupt.c
	sdcc -c -mmcs51 --verbose --model-small interrupt.c
	
# Link phase
project.hex : blinklight.rel led.rel button.rel interrupt.rel
	sdcc --model-small --code-loc 0x0000 --xram-loc 0x1000 blinklight.rel led.rel button.rel interrupt.rel
	packihx blinklight.ihx > project.hex

# Phony target
.PHONY: clean
clean:
# use rm instead of del
	rm *.rel *.lst *.rst *.hex *.mem *.map *.sym *.lk *.ihx *.asm
