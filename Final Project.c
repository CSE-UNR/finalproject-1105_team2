// Author:
// Date:
// Purpose:

#include <stdio.h>
#define MAX_WIDTH 100
#define MAX_HEIGHT 100

int loadImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int* width, int* height, const char* filename);
void displayImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void editImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int* width, int* height);
void cropImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int* width, int* height, int x, int y, int width_crop, int height_crop);
void dimImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void brightenImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height);
void saveImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height, const char* filename);



int main(){
	int currentImage[MAX_HEIGHT][MAX_WIDTH];
	char filename[100];
	int width = 0, height = 0;
	int choice;
	
	do{
		printf("\nMenu\n");
		printf("1. Load a new image\n");
		printf("2. Display current image\n");
		printf("3. Edit current iamge\n");
		printf("4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		
		
	switch(choice){
	
		case 1:
			printf("Enter filename: ");
			scanf("%s",filename);
			if(loadImage(currentImage, &width, &height, filename))
				printf("Image loaded\n");
			else
				printf("Error loading image\n");
		break;
		
		case 2:
			if (width > 0 && height > 0)
				displayImage(currentImage, width, height);
			else
				printf("No image loaded\n");
		break;
		
		case 3:
			if (width > 0 && height > 0)
				editImage(currentImage, &width, &height);
			else
				printf("No image loaded\n");
		break;
		
		case 4:
			printf("Leaving\n");
		break;
		
		default:
		 	printf("Invlid");
	}
} while(choice != 4);

return 0;
}

int loadImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int* width, int* height, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return 0;
    }

    fscanf(file, "%d %d", width, height);

    for (int i = 0; i < *height; i++) {
        for (int j = 0; j < *width; j++) {
            fscanf(file, "%d", &pixels[i][j]);
        }
    }

    fclose(file);
    return 1;
}

