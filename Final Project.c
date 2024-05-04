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
		printf("4. Save Image\n");
		printf(“5 Exit\n”);
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
			if (width > 0 && height > 0);
				editImage(curretnImage, &width, &height);
			else
				printf("No image loaded\n");
		break;
			
case 5:
            if (width > 0 && height > 0) {
            printf("Enter filename to save: ");
            scanf("%s", filename);
            saveImage(current_image, width, height, filename);
        } else {
            printf("No image loaded.\n");
                }
              	  break;

            	case 5:
                		printf("Exiting\n");
                	break;
            
default:
                printf("Invalid choice.\n");
        }
    } while(choice != 5);

    return 0;

		default:
		 	printf("Invalid");
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

void displayImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height);
  printf("Displaying image with dimensions %d x %d.\n", width, height);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            switch(pixels[i][j]) {
                case 0: printf(" "); break;
                case 1: printf("."); break;
                case 2: printf("o"); break;
                case 3: printf("O"); break;
                case 4: printf("0"); break;
                default: printf(" ");
            }
        }
        printf("\n");
    }
}

void editImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int* width, int* height) {
    int edit_choice;
    do {
        printf("\nEdit Menu:\n");
        printf("1. Crop\n");
        printf("2. Dim\n");
        printf("3. Brighten\n");
        printf("4. Return to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &edit_choice);

switch(edit_choice) {
            case 1: {
                int x, y, width_crop, height_crop;
                printf("Enter x, y, width, height for crop: ");
                scanf("%d %d %d %d", &x, &y, &width_crop, &height_crop);
                cropImage(pixels, width, height, x, y, width_crop, height_crop);
                break;
            }
            case 2:
                dimImage(pixels, *width, *height);
                break;
            case 3:
                brightenImage(pixels, *width, *height);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while(edit_choice != 4);
}

void cropImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int* width, int* height, int x, int y, int width_crop, int height_crop);













void dimImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height);













void brightenImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height);












void saveImage(int pixels[MAX_HEIGHT][MAX_WIDTH], int width, int height, const char* filename);
  FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(file, "%d ", pixels[i][j]);
        }
        fprintf(file, "\n");
    }

    fclose(file);
    printf("Image saved to %s\n", filename);
}

