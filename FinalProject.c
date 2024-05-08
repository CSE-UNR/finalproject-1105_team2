//Authors: Logan Wehr
//Date: 5/5/2024
//Purpose: Image Editor

#include <stdio.h> 
#define DATASIZE 5000

int displayMenu(); 
int savetofile();
int displayEditMenu(); 
int runSelection(char Selection, int* End); //End means end program
void writetofile(int imagedata[], int size, int endslot, int rows);
void brighten(int imagedata[], int size, int endslot, int rows);
void dim(int imagedata[], int size, int endslot, int rows);
void crop(int imagedata[], int size, int endslot, int rows, int collumns);
void displayImage(int imagedata[], int size, int endslot, int rows);
void loadImage(int imagedata[], int size, int* endslot, int* rows, int* collumns); //endslot is the size of the array. (I prob should rename these to make it less confusing at some point).

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
	printf("\nSave to file?\n");
	printf("Select an option:\n");
	printf("[y] Yes\n");
	printf("[n] No\n");
	char Selection;
	printf("\nSelection: ");
	scanf(" %c", &Selection);
	return Selection;
}

int displayEditMenu(){ //Displays options and asks for user input
	printf("\nEdit Options:\n");
	printf("Select an option:\n");
	printf("[1] Brighten\n");
	printf("[2] Dim\n");
	printf("[3] Crop\n");
	printf("[4] Back\n");
	char Selection;
	printf("\nSelection: ");
	scanf(" %c", &Selection);
	return Selection;
		
}

int runSelection(char Selection, int* End){ // Runs whatever selection was inputted and gives an error if needed
	int imagedata[DATASIZE], endslot, rows, collumns;
	
	switch(Selection){ 
	
	case '1': // Load Image
		loadImage(imagedata, DATASIZE, &endslot, &rows, &collumns); //Runs the image loader function
		
		break;
		
	case '2': // Display Image
		
		if(imagedata[0] != 1){ //error if no file. Image data array first digit must be a 1 to get passed error
			printf("\n! No image file loaded !\n");
		} else { //Image Processor
			displayImage(imagedata, DATASIZE, endslot, rows);
		}
		break;
		
	case '3': // Edit Image
		if(imagedata[0] != 1){ //error if no file. Image data array first digit must be a 1 to get passed error
			printf("\n! No image file loaded !\n");
		} else {
			switch(displayEditMenu()){
			case '1'://brighten
			        brighten(imagedata, DATASIZE, endslot, rows);
				break;
			case '2'://dim
				dim(imagedata, DATASIZE, endslot, rows);
				break;
				
			case '3'://crop
				crop(imagedata, DATASIZE, endslot, rows, collumns);
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


void loadImage(int imagedata[], int size, int* endslot, int* rows, int* collumns){ //Loads Image From Properly Formatted File. Formatting allows for any sized image to be inputted from the file as long as the DATASIZE definition is large enough. Image dimensions are also loaded from the file itself for proper display to terminal later.
	printf("\nInput File Name: ");
	char fileName[100];  //File name
	
	
	scanf(" %s",fileName); //Gets user inputted name
	FILE *fp;
	fp = fopen(fileName, "r"); //Attempt to open file name
	if(fp == NULL){ //Failure to open file 
		printf("\n! Couldn't open/find file !\n");
	} else { //File is loadable
		char loadedData[DATASIZE];
		for(int b = 0; b < DATASIZE; b++){
			
			loadedData[b] = 'A';
		}
		int rowcheck, rowcount, collumncount, end, end2;
		rowcheck = 0;
		collumncount = 1;
		rowcount = 0;
		for(int b = 0; b < DATASIZE; b++){
			imagedata[b] = 0;
			
			
			
		}
		
		end = 0;
		end2 = 0;
		
		
		
		for(int i = 0; i < DATASIZE; i++){
			
			
			fscanf(fp, "%c", &loadedData[i]); //Read every character in file
			if(loadedData[i] == 10){
				collumncount++;
			}
			if(collumncount == 1){
				rowcount++;
			}
			
			
			if(loadedData[i] == 'A'){  //if file read reaches a space stop running read
				
				i = DATASIZE + 50;
				
				
			}
			end++;
			
		}
		end = end - 1;
		
		fclose(fp); //Close file
		int l;
		
		imagedata[0] = 1;
		l = 0;
		for(int j = 0; j < end; j++){
			if(loadedData[j] != 10){
				imagedata[l+1] = loadedData[j] - '0';
				l++;
				end2++;
			}
		}
		l = 0;
		for(int f = 0; f <= end2; f++){
			//printf("%d", imagedata[f]);	
			
		}
		for(int i = 0; i <= end2; i++){
			imagedata[i] = imagedata[i];
		}
		
		collumncount--;
		printf("%dW x %dH\n", rowcount, collumncount);
		*rows = rowcount;
		*endslot = end2;
		*collumns = collumncount;
	}
}

void displayImage(int imagedata[], int size, int endslot, int rows){
	printf("\n");
	int j = 0;
	for(int i = 1; i <= endslot; i++){ //Prints a new line after each row
		if(j < rows){
			j++;
		} else {
			j = 1;
			printf("\n");
		}
		
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
					printf("X");
					break;
				
			//printf("%d",imagedata[i]);
			
		}
		
	}
	printf("\n");
}

void writetofile(int imagedata[], int size, int endslot, int rows){
	//for(int i = 1; i < endslot + 1; i++){
		//printf("%d",imagedata[i]);
	//}
	printf("\nInput File Name: ");
	char fileName[100];  //File name
	scanf(" %s",fileName); //Gets user inputted name
	FILE *fw;
	fw = fopen(fileName, "w"); //Attempt to open file name
	
	int j = 0;
	int cutcollumn = 0;
	for(int i = 1; i <= endslot; i++){ //Prints a new line after each row
		if(j < rows){
			j++;
			if(imagedata[i] == 6){
				cutcollumn++;
			}
		} else {
			if(j != cutcollumn){
				fprintf(fw, "\n");
			}
			j = 1;
			cutcollumn = 1;
			
		}
		if(imagedata[i] != -38 && imagedata[i] != 6){ //Prints. (Reason for if statement checking for -38 is it
					 //prevents program from printing the ASCII number for an "enter/return" character.
			fprintf(fw, "%d", imagedata[i]); 
			
		}
		
	}
	
	fclose(fw);
	
	
	
	
}

void brighten(int imagedata[], int size, int endslot, int rows){
	for(int i = 0; i < endslot; i++){
		if(imagedata[i+1] != -38 && imagedata[i+1] < 5){
			imagedata[i+1] = imagedata[i+1] + 1;
		}
	}
	displayImage(imagedata, DATASIZE, endslot, rows);
	switch(savetofile()){
	default:
		printf("\n! Invalid Selection !\n");	
	case 'y':
		writetofile(imagedata, DATASIZE, endslot, rows);
		break;
	case 'n':
		break;
	}
}

void dim(int imagedata[], int size, int endslot, int rows){
	for(int i = 0; i < endslot; i++){
		if(imagedata[i+1] > 1){
			imagedata[i+1] = imagedata[i+1] - 1;
		}
	}
	displayImage(imagedata, DATASIZE, endslot, rows);
	switch(savetofile()){
	default:
		printf("\n! Invalid Selection !\n");	
	case 'y':
		writetofile(imagedata, DATASIZE, endslot, rows);
		break;
	case 'n':
		break;
	}
}
void crop(int imagedata[], int size, int endslot, int rows, int collumns){
	int leftcollumn, rightcollumn, toprow, bottomrow, error;
	error = 0;
	toprow = 0;
	printf("\nEnter top row limit \nSelection: \n");
	scanf(" %d", &toprow);
	//if(error = 0){
	if(toprow >= 0 && toprow < collumns){
		for(int i = 1; i < endslot + 1; i++){ 
			if((i <= ((rows * (toprow))))){
				imagedata[i] = 6;
					
			}	
		}
	} else {
		printf("\n! Error. Result Would Be a Blank Image or your selection is invalid!\n");
		error = 1;
	}
	
	printf("\nEnter bottom row limit \nSelection: \n");
	scanf(" %d", &bottomrow);
	
	
	if(bottomrow >= 0 && bottomrow < collumns){
		for(int i = 1; i < endslot + 1; i++){
			if(i > (rows * (collumns - bottomrow + 1))){
				imagedata[i] = 6;
			}
		}
	} else {
		printf("\n! Error. Result Would Be a Blank Image or your selection is invalid!\n");
		error = 1;
	}
	bottomrow = 0;
	
	printf("\nEnter left collumn limit \nSelection: \n");
	scanf(" %d", &leftcollumn);
	
	
	if(leftcollumn >= 0 && leftcollumn < rows){
		for(int i = 1; i <= leftcollumn; i++){
			//printf(" %d", i);
			for(int j = 0; j < collumns; j++){
				//printf(" %d", j+(j*(rows-1))+i);
				imagedata[j+(j*(rows-1))+i] = 6;
				
			}
		}
	} else {
		printf("\n! Error. Result Would Be a Blank Image or your selection is invalid!\n");
		error = 1;
	}
	leftcollumn = 0;
	
	printf("\nEnter right collumn limit \nSelection: \n");
	scanf(" %d", &rightcollumn);
	
	
	if(rightcollumn >= 0 && rightcollumn < rows){
		for(int i = rows; i > (rows - rightcollumn); i--){
			//printf(" %d", i);
			for(int j = 0; j < collumns; j++){
				//printf(" %d", j+(j*(rows-1))+i);
				imagedata[j+(j*(rows-1))+i] = 6;
				
			}
		}
	} else {
		printf("\n! Error. Result Would Be a Blank Image or your selection is invalid!\n");
		error = 1;
	}
	rightcollumn = 0;
		
	//printf("%d", rows);
	displayImage(imagedata, DATASIZE, endslot, rows);
		switch(savetofile()){
		default:
			printf("\n! Invalid Selection !\n");	
		case 'y':
			writetofile(imagedata, DATASIZE, endslot, rows);
			break;
		case 'n':
			break;
		}
	//}
}
	
	
	
	
		
	
	

