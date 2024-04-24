#include <stdio.h>
#include <string.h>

#define NULL 0

void UIntToHexStr(unsigned int uiValue, char pcStr[]) {
	
	unsigned char ucNibbleCounter;
	unsigned char ucCurrentNibble;

	pcStr[0] = '0';
	pcStr[1] = 'x';
	pcStr[6] = NULL;

	for (ucNibbleCounter = 0; ucNibbleCounter < 4; ucNibbleCounter++) {
		ucCurrentNibble = (uiValue >> ((ucNibbleCounter) * 4)) & 0x0F;
		if (ucCurrentNibble < 10) {
			pcStr[5 - ucNibbleCounter] = '0' + ucCurrentNibble;
		} else {
			pcStr[5 - ucNibbleCounter] = 'A' + (ucCurrentNibble - 10);
		}
	}
}



unsigned int uiValue = 65000;
char pcStr[] = "qwertyu";

void TestOf_UIntToHexStr(void) {
	UIntToHexStr(uiValue, pcStr);

}

int main(void) {
	TestOf_UIntToHexStr();
}
