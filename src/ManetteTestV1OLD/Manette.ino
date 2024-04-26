#include "ManetteTest.h"

byte psxButtonToIndex(PsxButtons psxButtons) {
	byte i;

	for (i = 0; i < PSX_BUTTONS_NO; ++i) {
		if (psxButtons & 0x01) {
			break;
		}

		psxButtons >>= 1U;
	}

	return i;
}

FlashStr getButtonName(PsxButtons psxButton) {
	FlashStr ret = F("");

	byte b = psxButtonToIndex(psxButton);
	if (b < PSX_BUTTONS_NO) {
		PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr(&(psxButtonNames[b])));
		ret = PSTR_TO_F(bName);
	}

	return ret;
}

void dumpButtons(PsxButtons psxButtons) {
	static PsxButtons lastB = 0;

	if (psxButtons != lastB) {
		lastB = psxButtons;     // Save it before we alter it

		Serial.print(F("Pressed: "));

		for (byte i = 0; i < PSX_BUTTONS_NO; ++i) {
			byte b = psxButtonToIndex(psxButtons);
			if (b < PSX_BUTTONS_NO) {
				PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr(&(psxButtonNames[b])));
				Serial.print(PSTR_TO_F(bName));
			}

			psxButtons &= ~(1 << b);

			if (psxButtons != 0) {
				Serial.print(F(", "));
			}
		}

		Serial.println();
	}
}

void dumpAnalog(const char* str, const byte x, const byte y) {
	Serial.print(str);
	Serial.print(F(" analog: x = "));
	Serial.print(x);
	Serial.print(F(", y = "));
	Serial.println(y);
}
void testDump(){
  Serial.print("X : ");
  Serial.print(getX());
  Serial.print(" Y : ");
  Serial.print(getY());
  Serial.print(" Z : ");
  Serial.println(getZ());
}


