//Authors: Logan Wehr
//Date: 5/5/2024
//Purpose: Image Editor

#include <stdio.h> 


int displayMenu();
int runSelection(char Selection, int* End);
int loadImage();

int main(){
	int running;
	while(running == 0){
		int Selection = 0;
		Selection = displayMenu(); // Gets Selection
		int End;
		runSelection(Selection, &End); // Runs Whatever Selection User Chose
		running = End;
		
	}
}

int displayMenu(){
	printf("\n***IMAGE EDITOR***\n");
	printf("Select an option:\n");
	printf("[1] Load New Image\n");
	printf("[2] Display Current Image\n");
	printf("[3] Edit the Current Image\n");
	printf("[4] Exit\n");
	char Selection;
	printf("Selection: ");
	scanf(" %c", &Selection);
	return Selection;
}

int runSelection(char Selection, int* End){ // Runs whatever selection was inputted and gives an error if needed
	switch(Selection){ 
	
	case '1': // Load Image
		loadImage();
		break;
		
	case '2': // Display Image
		break;
		
	case '3': // Edit Image
		break;
		
	case '4': // Exit
		*End = 1;
		break;
	default: // Error (Input is out of range)
		printf("\n! Invalid Selection !\n");
	
	
	}
}

int loadImage(){ //Loads Image From Properly Formatted File
	printf("\nInput File Name: ");
	char fileName;
	scanf(" %c", &fileName);
}
