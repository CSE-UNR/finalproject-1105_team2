//Authors: Logan Wehr & Jorden Kang
//Date: 5/5/2024
//Purpose: Image Editor

#include <stdio.h> 
#define DATASIZE 5000

int displayMenu();
int runSelection(char Selection, int* End, int editChoice);
void loadImage(int imagedata[], int size, int* endslot, int* rows);
void editImage();

int main(){
	int running; // Variable that tells program to keep looping or end
	while(running == 0){
		int Selection;

		Selection = displayMenu(); // Gets Selection
		int End;
		runSelection(Selection, &End); // Runs Whatever Selection User Chose
		running = End;
		
		
	}
	return 0;
}

int displayMenu(){
	printf("\n***IMAGE EDITOR***\n");
	printf("Select an option: ");
	printf("[1] Load New Image\n");
	printf("[2] Display Current Image\n");
	printf("[3] Edit the Current Image\n");
	printf("[4] Exit\n");
	char Selection;
	printf("\nSelection: ");
	
	scanf(" %c", &Selection);
	
	
	
	return Selection;
}

int runSelection(char Selection, int* End, int editChoice){ // Runs whatever selection was inputted and gives an error if needed
	int imagedata[DATASIZE], endslot, rows;
	
	switch(Selection){ 
	
	case '1': // Load Image
		loadImage(imagedata, DATASIZE, &endslot, &rows); //Runs the image loader function
		
		break;
		
	case '2': // Display Image
		
		if(imagedata[0] != 1){ //error if no file. Image data array first digit must be a 1 to get passed error
			printf("\n! No image file loaded !\n");
		} else { //Image Processor
			printf("\n");
			int j = 0;
			for(int i = 1; i < endslot; i++){ //Prints a new line after each row
				if(j < rows){
					j++;
				} else {
					j = 0;
					printf("\n");
				}
				if(imagedata[i] != -38){ //Prints. (Reason for if statement checking for -38 is it
							 //prevents program from printing the ASCII number for an "enter/return" character.
					switch(imagedata[i]){ //Prints characters from numerical values
						case 1:
							printf(" ");
							break;
						case 2:
							printf(".");
							break;
						case 3:
							printf("o");
							break;
						case 4:
							printf("O");
							break;
						case 5:
							printf("0");
							break;
						case 6:
							printf("8");
							break;
					}
					//printf("%d",imagedata[i]);
				}
			}
			printf("\n");
		}
		break;
		
	case '3': 
	printf("\n***Edit Menu***\n");
	printf("Select an option: ");
        printf("[1] Crop\n");
        printf("[2] Dim\n");
        printf("[3] Brighten\n");
        printf("[4] Return to main menu\n");
        scanf("%d", &editChoice);
        return editChoice;
		break;
		
	case '4': // Exit
		*End = 1;
		break;
	default: // Error (Input is out of range)
		printf("\n! Invalid Selection !\n");
	}
}

void loadImage(int imagedata[], int size, int* endslot, int* rows){ //Loads Image From Properly Formatted File. Formatting allows for any sized image to be inputted from the file as long as the DATASIZE definition is large enough. Image dimensions are also loaded from the file itself for proper display to terminal later.
	printf("\nInput File Name: ");
	char fileName[100];  //File name
	scanf(" %s",fileName); //Gets user inputted name
	FILE *fp;
	fp = fopen(fileName, "r"); //Attempt to open file name
	if(fp == NULL){ //Failure to open file 
		printf("\n! Couldn't open/find file !\n");
	} else { //File is loadable
		char loadedData[DATASIZE];
		double end; 
		end = 0;
		for(int k = 0; k < DATASIZE; k++){
			loadedData[k] = '0';
		}
		for(int i = 0; i < DATASIZE; i++){
			fscanf(fp, "%c", &loadedData[i]); //Read every character in file
			
			if(loadedData[i] == 'E'){  //if file read reaches "END" stop running read
				i = DATASIZE + 1;
			}
			end++;
		}
		fclose(fp); //Close file
		if(loadedData[8] == 'A'){ //Check if file has correct format heading ("Format: A") (Actually checks for the A character)
			
			for(int j = 38; j < end; j++){ //Convert data character array to more easily changeable data array
				imagedata[j-37] = loadedData[j] - '0';
			}
			printf("\nFile Successfully Loaded\nImage Size: %c%c%cW x %c%c%cH\n", loadedData[22], loadedData[23], loadedData[24], 		 
			loadedData[28], loadedData[29], loadedData[30]); //Print image size using file data
			//printf("test:%c,%lf,%c", loadedData[38], end, loadedData[110]);
			imagedata[0] = 1;
			*rows = ((loadedData[22] - '0') * 100) + ((loadedData[23] - '0')*10) + ((loadedData[24] - '0'));
		} else {
			printf("\n! File is in incorrect format !\n"); //If format heading is missing reject data and send error	
		}
		if(end != 0){
			*endslot = end - 38; //Send the length of the data array
		}
	}
}

void editImage();

switch(editChoice) {

	case 1: // Crop Image
	break;
	
	case 2: // Dim Image
	break;
	
	case 3: // Brighten Iamge
	break;
	
	case 4: // Return to main menu
	break;


}



