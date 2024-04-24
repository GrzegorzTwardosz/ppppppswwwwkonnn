#include <stdio.h>
#include <string.h>

#define NULL 0
enum Result { OK, ERROR };
enum Result eHexStringToUIntFuncRes;

enum Result eHexStringToUInt(char pcStr[],unsigned int *puiValue){
	
	unsigned char ucCharacterCounter;
	unsigned char ucCurrentCharacter;
	
	*puiValue=0;
	if((pcStr[0]!='0') || (pcStr[1]!='x') || (pcStr[2]==NULL)){
		return ERROR;
	}
	
	for(ucCharacterCounter=2; pcStr[ucCharacterCounter] != NULL; ucCharacterCounter++){
        ucCurrentCharacter = pcStr[ucCharacterCounter];
        if(ucCurrentCharacter==6){
            return OK;
        }		
	
		*puiValue = *puiValue << 4;
		if ((ucCurrentCharacter >= '0') && (ucCurrentCharacter <= '9')) {
			ucCurrentCharacter = ucCurrentCharacter - '0';
		} else if ((ucCurrentCharacter >= 'A') && (ucCurrentCharacter <= 'F')) {
			ucCurrentCharacter = ucCurrentCharacter - 'A' + 10;
			} else {
				return ERROR;
				}
		*puiValue = (*puiValue) | ucCurrentCharacter;
	}
	return ERROR;
}



char pcStr[] = "0xabc";
unsigned int uiValue;

void TestOf_eHexStringToUInt(void) {
	eHexStringToUIntFuncRes = eHexStringToUInt(pcStr,&uiValue);

}

int main(void) {
	TestOf_eHexStringToUInt();
}
