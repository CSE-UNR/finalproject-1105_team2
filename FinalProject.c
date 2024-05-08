//Authors: Logan Wehr
//Date: 5/5/2024
//Purpose: Image Editor

#include <stdio.h> 
#define DATASIZE 5000

int displayMenu(); 
int savetofile();
int displayEditMenu(); 
int runSelection(char Selection, int* End); //End means end program
void loadImage(int imagedata[], int size, int* endslot, int* rows); //endslot is the size of the array. (I prob should rename these to make it less confusing at some point).

int main(){
	int running; // Variable that tells program to keep looping or end
	while(running == 0){
		int Selection;

		Selection = displayMenu(); // Gets Selection
		int End;
		runSelection(Selection, &End); // Runs Whatever Selection User Chose
		running = End;
		
		
	}
}

int displayMenu(){ //Displays options and asks for user input
	printf("\n***IMAGE EDITOR***\n");
	printf("Select an option:\n");
	printf("[1] Load New Image\n");
	printf("[2] Display Current Image\n");
	printf("[3] Edit the Current Image\n");
	printf("[4] Exit\n");
	char Selection;
	printf("\nSelection: ");
	scanf(" %c", &Selection);
	return Selection;
}

int savetofile(){ //Displays options and asks for user input
	printf("\n***SAVE TO FILE?***\n");
	printf("Select an option:\n");
	printf("[y] Yes\n");
	printf("[n] No\n");
	char Selection;
	printf("\nSelection: ");
	scanf(" %c", &Selection);
	return Selection;
}

int displayEditMenu(){ //Displays options and asks for user input
	printf("\n**EDIT OPTIONS**\n");
	printf("Select an option:\n");
	printf("[1] Brighten\n");
	printf("[2] Dim\n");
	char Selection;
	printf("\nSelection: ");
	scanf(" %c", &Selection);
	return Selection;
		
}

int runSelection(char Selection, int* End){ // Runs whatever selection was inputted and gives an error if needed
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
		
	case '3': // Edit Image
		if(imagedata[0] != 1){ //error if no file. Image data array first digit must be a 1 to get passed error
			printf("\n! No image file loaded !\n");
		} else {
			switch(displayEditMenu()){
			case '1'://brighten
				for(int i = 1; i < endslot; i++){
					if(imagedata[i+1] != -38 && imagedata[i+1] < 5){
						imagedata[i+1] = imagedata[i+1] + 1;
					}
				}
				switch(savetofile()){
				default:
					printf("\n! Invalid Selection !\n");	
				case '1':
					
					break;
				case '2':
					break;
				}
				break;
			case '2'://dim
				for(int i = 1; i < endslot; i++){
					if(imagedata[i+1] > 1){
						imagedata[i+1] = imagedata[i+1] - 1;
					}
				}
				break;
			default:
				printf("\n! Invalid Selection !\n");
			}
		}
		
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
		int rowcheck, rowcount, collumncount, end;
		rowcheck = 0;
		collumncount = 0;
		rowcount = 0;
		imagedata[0] = 1;
		end = 0;
		for(int k = 0; k < DATASIZE; k++){
			loadedData[k] = '0';
			
		}
		
		for(int i = 0; i < DATASIZE; i++){
			fscanf(fp, "%c", &loadedData[i]); //Read every character in file
			if(loadedData[i] == 10){
				collumncount++;
			}
			if(collumncount == 0){
				rowcount++;
			}
			
			if(loadedData[i] != '1' && loadedData[i] != '2' && loadedData[i] != '3' && loadedData[i] != '4' && loadedData[i] != '5' && loadedData[i] != 10){  //if file read reaches a space stop running read
				i = DATASIZE + 50;
				collumncount++;
				
			}
			end++;
			
		}
		end = end - 1;
		collumncount--;
		fclose(fp); //Close file
		for(int j = 0; j < end; j++){
			imagedata[j+1] = loadedData[j] - '0';
		}
		printf("\nR%dC%dE%d", rowcount, collumncount, end);
		*rows = rowcount;
		*endslot = end;
	}
}
