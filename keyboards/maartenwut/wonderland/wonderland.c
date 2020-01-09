#include "wonderland.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	matrix_init_user();
	led_init_ports();
};

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)
	matrix_scan_user();
};

void led_init_ports(void) {
    // * Set our LED pins as output
    setPinOutput(B1);
    setPinOutput(B2);
    setPinOutput(B3);
	writePinHigh(B1);		//?
}

void led_set_kb(uint8_t usb_led) {
	if (IS_LED_ON(usb_led, USB_LED_NUM_LOCK)) {
      //  writePinLow(B1);
    } else {
      //  writePinHigh(B1);
    }

    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        writePinLow(B2);
    } else {
        writePinHigh(B2);
    }

    if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
        writePinLow(B3);
    } else {
        writePinHigh(B3);
    }
	led_set_user(usb_led);
}

uint32_t layer_state_set_user(uint32_t state) {
  switch (biton32(state)) {
    case _BASE:
		writePinHigh(B1);
		break;
    case _FN:
		writePinLow(B1);
		break;
  }
  return state;
}