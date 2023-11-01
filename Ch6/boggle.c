/*
	Input : 
	1
	URLPM
	XPRET
	GIAET
	XTNZY
	XOQRS
	6
	PRETTY
	GIRL
	REPEAT
	KARA
	PANDORA
	GIAZAPX
	
	Output : 
	PRETTY YES
	GIRL YES
	REPEAT YES
	KARA NO
	PANDORA NO
	GIAZAPX YES
*/

#include <stdio.h>
#include <stdlib.h>

// Word board
char board[5][6];

int hasWord(int x, int y, char word[], int idx);

int main(void) {
	// For testcase
	int T, _t;
	
	// For solve
	char word[10][15];
	int i, words, x, y, flag;
	
	scanf(" %d", &T); // Input Testcase
	for(_t = 0; _t < T; _t++) {

		// Input word board
		for(i = 0; i < 5; i++)
			scanf(" %s", board[i]);
			
		scanf(" %d", &words);
		// Input words
		for(i = 0; i < words; i++)
			scanf(" %s", word[i]);
			
		// Check Input
		/*for(i = 0; i < 5; i++)
			printf("%s\n", board[i]);
		for(i = 0; i < words; i++)
			printf("%s\n", word[i]);*/
			
		for(i = 0; i < words; i++) { 
			flag = 0;
			for(y = 0; y < 5; y++) {
				for(x = 0; x < 5; x++) {
					if(hasWord(x, y, word[i], 0) == 1) { // if has word
						flag = 1;
						break;
					}
				}
				if(flag)
					break;
			}	
			if(flag == 0)
				printf("%s NO\n", word[i]);
			else
				printf("%s YES\n", word[i]);
		}
		
		return 0;
	}
}

// Directions
int dx[] = {0, 0, 1, -1, -1, 1, 1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

int hasWord(int x, int y, char word[], int idx) {
	int i;
	
	if(x >= 5 || x < 0 || y >= 5 || y < 0) return 0; // Check range
	
	if(board[y][x] != word[idx]) return 0; // Incorrect
	if(strlen(word)-1 == idx) return 1; // Correct
	
	for(i = 0; i < 8; i++) { // 8 Directions
		if(hasWord(x + dx[i], y + dy[i], word, idx+1) == 1)
			return 1;
	}
	return 0;
}
