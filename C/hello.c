#include <stdio.h>
#include <string.h>

#define MAX 100

void capitalize(char *str);
int is_whitespace(char c);

int main() {
	char str[MAX] = "ciao mondo	prova";
	
	printf("%s\n", str);
	
	if(!is_whitespace(str[0])) {
		capitalize(&str[0]);
	}
	for (int i = 1; i < MAX; ++i) {
		if (is_whitespace(str[i]) && !is_whitespace(str[i+1])) {
			capitalize(&str[i+1]);
		}
	}
	
	printf("%s\n", str);
	
	return 0;
}

void capitalize(char *c) {
	if((*c>96) && (*c<123)) {
		*c = *c - 32;
	}
}

int is_whitespace(char c) {
	if (c == ' ' || c == '\t' || c == '\n') {
		return 1;
	} else {
		return 0;
	}
}
