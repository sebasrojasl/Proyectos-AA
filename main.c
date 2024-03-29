#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int freq[257];
int copyOfFreq[256];

void fileListReader(int argc, char *argv[]){
	//"lee" el archivo
	FILE *file;
	unsigned char buffer[1];
	int decimal;
	for(int i = 2; i < argc; i++){
		file = fopen(argv[i], "rb");
			if(file == NULL)
			{
				printf("\n Error, file not readable or doesn't exist. \n \n");
			}
			else
			{
				printf("\n The %s file was loaded... \n", argv[i]);
				
				while (!feof(file)){
					
					fread(buffer, sizeof(buffer), 1, file); // read 10 bytes to our buffer
					int decimal = buffer[0];
					freq[decimal] =  ++freq[decimal];	
		    	}
				fclose(file);
			}
	}

}
//At the end of the execution, write the frequencies in the frequencies file.
void modifyFreq(FILE *file, const char * filename){
	file = fopen(filename, "w");
	freq[0] = -111;

	fwrite(freq, sizeof(int), 257, file);
	fclose(file);
	
}
//Function that validates if the entered file has the signature that belongs to a frequency file
int validSignat(FILE *file, const char * filename){
	int signature[1];
	int result;
	file = fopen(filename, "rb");
	fread(signature, sizeof(int), 1, file);

	if(signature[0] == -111){
		return 1;
	} else {
		return 0;
	}
}
//Function that creates the Frequency Database File
void createFreq(FILE *file, const char * filename){
	int freq[257];
	freq[0] = -111;
	for(int i = 1; i < 257; i++){
		freq[i] = 0;
	}
	file = fopen(filename, "w");
	fwrite(freq, sizeof(int), 257, file);
	fclose(file);
}

//Function that reads the Frequency Database File
void readFreq(FILE *file, const char * filename){
	file = fopen(filename, "rb");
	if (file == NULL){
		printf("%s\n","Error, can't open file." );
		exit(1);
	}	
	fread(freq, sizeof(int), 257, file);
	printf("============================== Frequencies Table==============================\n");
    printf("\tHex Code\t\t Symbol\t\t\t Frequency\n"); //TABLE TITLES !
    printf("==============================================================================\n");
	for(int i = 1; i < 256; i++){
		printf("\t%hhx\t\t\t", i);
		if((i > 33)&&(i < 127)||(i>161)){
			printf("%c\t\t\t", i);
		}else{
			printf("\t\t\t");
		}
		printf("%d\n", freq[i]);

	}
	printf("\n");
	fclose(file);
}

void loadFreq(FILE *file, const char * filename){
	file = fopen(filename, "rb");
	if (file == NULL){
		printf("%s\n","Error, can't open file." );
		exit(1);
	}	
	fread(freq, sizeof(int), 257, file);
	fclose(file);
}
//Function that validates whether a file exists or not inside the local directory
int fileExists(const char * filename){
    FILE *file;
    if (file = fopen(filename, "r")){
        fclose(file);
        return 1;
    }
    return 0;
}
//Function that takes the freq list and returns the corresponding data.
char dataExtract(int * freq){
	char data[256];
}

///////////Dynamic Array Functions//////////////////////
typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  // a->used is the number of used entries, because a->array[a->used++] updates a->used only *after* the array has been accessed.
  // Therefore a->used can go up to a->size 
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}

void freeArray(Array *a) {
  free(a->array);
  a->array = NULL;
  a->used = a->size = 0;
}
////////////////////////////////////////////////////////

/////////Int to Ascii Character function////////////////
char int2Char(int num){
    char * cad = malloc(12 * sizeof(char));
	sprintf(cad, "%i", num);
	return *cad;
}

int main(int argc ,char *argv[])
{
	FILE *file;
	//If no file argument is entered
	if(argc == 1){
		printf("%s\n", "Error, missing frequency file argument.");
		return 0;
	}
	//If only 1 argument is entered
	else if(argc == 2){
		char* freqFile = argv[1];
		int exist = fileExists(freqFile);
		//If the file entered exists
	    if(exist)
	    {
	        printf("File %s already exists...\n",freqFile);
	        //If the file entered has the "signature" of a frequency file
	        if (validSignat(file, freqFile)){
	        	readFreq(file, freqFile);
	        //If the file doesn't have a "signature".
	        } else {
	        	printf("%s\n", "Error, file is not a valid frequency file");
	        	exit(1);
	        }

	    }

	    //If the file doesn't exist
	    else{
	        printf("File %s does not exist, creating file... \n",freqFile);
	    	
	    	createFreq(file, freqFile);

	    	readFreq(file, freqFile);

	    }
	//If more then 1 file are entered as arguments
	} else {
		char* freqFile = argv[1];
		int exist = fileExists(freqFile);
		//If the frequency file exists
	    if(exist)
	    {
	        printf("File %s already exists...",freqFile);
	        if (validSignat(file, freqFile)){
	        	loadFreq(file, freqFile);
	        	fileListReader(argc, argv);
		        modifyFreq(file, freqFile);
		    	readFreq(file, freqFile);
	        //If the file doesn't have a "signature".
	        } else {
	        	printf("%s\n", "Error, file is not a valid frequency file");
	        	exit(1);
	        }

	    //If the file frequency file doesn't exist
	    } else {
	        printf("File %s does not exist, creating file... \n",freqFile);
	    	createFreq(file, freqFile);
	        fileListReader(argc, argv);
	        modifyFreq(file, freqFile);
	    	readFreq(file, freqFile);

	    }
		
	}
	///-----------------------///////////////////////////Huffman Tree Generation////////////////----------------------///////////////////
	//Loop that copies all but the first number into another array
	for (int i = 0; i < 256; i++)
    {
        copyOfFreq[i] = freq[i+1];
    }

    Array freqArray;
    Array numbers2Ascii;

	initArray(&freqArray, 5);  // initially 5 elements
	initArray(&numbers2Ascii, 5);
	for (int i = 0; i < 256; i++)
		if(copyOfFreq[i] != 0){
  			insertArray(&freqArray, copyOfFreq[i]);
  			insertArray(&numbers2Ascii, i);

 		}

 	char dataArray[numbers2Ascii.used];
 	for(int i = 0; i < numbers2Ascii.used; i++)
 	{
 		dataArray[i] = int2Char(numbers2Ascii.array[i]);
 	}
	freeArray(&freqArray);
	printf("%d\n", dataArray[4]);




  		

	return 0;
}

