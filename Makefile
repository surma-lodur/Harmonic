# See https://github.com/bxparks/EpoxyDuino for documentation about this
# Makefile to compile and run Arduino programs natively on Linux or MacOS.

APP_NAME := HarmonicTest
ARDUINO_LIBS := AUnit
include ../EpoxyDuino/EpoxyDuino.mk

test: clean $(APP_NAME).out run

BOARD=arduino:avr:nano:cpu=atmega328
PORT=/dev/ttyUSB0
BAUD=115200


native_test: compile upload monitor

compile:
	arduino-cli compile \
		-b $(BOARD) \
		--library ../PulsR \
		--library ../Harmonic \
		$(APP_NAME).ino

upload:
	arduino-cli upload \
		-b $(BOARD) \
		-p $(PORT) \
		$(APP_NAME).ino

monitor:
	arduino-cli monitor \
		-b $(BOARD) \
		--config baudrate=$(BAUD) \
		-p $(PORT)
