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

void AppendUIntToString(unsigned int uiValue, char pcDestinationStr[]){
	unsigned char ucEndofIndex;
	for(ucEndofIndex=0; pcDestinationStr[ucEndofIndex]!=NULL; ucEndofIndex++){}
		UIntToHexStr(uiValue, &pcDestinationStr[ucEndofIndex]);
}

unsigned int uiValue = 650; 
char pcDestinationStr[10] = "abc";

void TestOf_AppendUIntToString(void) {
	AppendUIntToString(uiValue,pcDestinationStr);

}

int main(void) {
	TestOf_AppendUIntToString();
}
