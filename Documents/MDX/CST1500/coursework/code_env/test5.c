// Headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void main(void)
{
	//Here we define our variables to be initialized later in the code
    int i, x, y, z, dictIndex, resultLength, dict[] = {4, 5, 6, 7};
	FILE* ptr;
    char wordLength, dictString[20], word[50], *wordList[500], *specialList[10];
	
	//We use this function for our rand functions to generate different values upon every execution 
	//time takes the parameter null set to current time
	srand(time( NULL ));

	// we generate a number betweeen 0 - 4, to use to index the dict array
	dictIndex = rand() % 4;

	//because fopen expects its first parameter to be a string, we must convert the value we get above and store it in the dictString variable 
	sprintf( dictString, "%d", dict[dictIndex] );

	// We use this to read/write from a file, it returns a pointer
	ptr = fopen( dictString, "r" );

	//Optional Password LEngth Selector
	// printf("How long do you want your password? \n");
	// scanf("%s", &wordLength);

	// if(wordLength == '4' || wordLength == '5' || wordLength == '6' || wordLength == '7' ){
		
	// 	ptr = fopen(&wordLength, "r");
		
		printf( "How many password results would you like to see?" );
		scanf( "%d", &resultLength );

		//Number of results constraint
		if( resultLength > 2 && resultLength < 5 ){
			
			//Handle Errors opening file
			if( NULL == ptr ) {
				printf("file can't be opened");
			}

			//Loop to handle the reading of each file line and append it to our previously defined array
			i = 0;
			while ( fgets( word, 50, ptr ) != NULL ) {
				//To avoid newline that fgets generates we use the strcspn function to get index on newline character and replace with null
				z = strcspn(word, "\n");
				word[z] = '\0';
				wordList[i] = strdup(word);
				i++;
			}

			//Loop to randomize word from dictionary array and append it to another predefined list
			for( x=0; x<resultLength; x++ ){
				y = rand() % 499;
				specialList[x] = strdup(wordList[y]);
			}

			//Loop to output all each element of our list in the requested format
			printf("Generating password\n");
			for( x=0; x<resultLength; x++ ){
				printf("%d %s \n", x, specialList[x]);
				if( x!=resultLength-1 ){
					printf("\n");
				}				
			}

			printf( "Your e-t-r password is:" );
			for( x=0; x<resultLength; x++ ){
				printf( "%s",specialList[x] );
				if( x!=resultLength-1 ){
					printf("-");
				}
			}
			//Function to close file
			fclose( ptr );
		}
		else{
			fclose( ptr );
			printf( "Password results must be between 2 and 5! \n" );
		}
	// }
	// else{
	// 	fclose(ptr);
	// 	printf("Password length must be either 4, 5 or 6! \n");
	// }


}
