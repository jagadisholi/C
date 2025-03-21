#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 100

typedef struct {
    int page;
    int referenceBit;
} Frame;

int main() {
    Frame frames[MAX_FRAMES];
    int pages[MAX_PAGES];
    int numFrames, numPages, pageFaults = 0;
    int i, j, k, pointer = 0, found;

    // Initialize frames
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i].page = -1;  // Empty frames initially
        frames[i].referenceBit = 0;  // Reference bit set to 0
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    printf("Enter the reference string (pages): ");
    for (i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    // Second-Chance Page Replacement
    for (i = 0; i < numPages; i++) {
        found = 0;

        // Check if the page is already in one of the frames
        for (j = 0; j < numFrames; j++) {
            if (frames[j].page == pages[i]) {
                found = 1;
                frames[j].referenceBit = 1;  // Set the reference bit since page is accessed
                break;
            }
        }

        if (!found) {
            // Page not found, so we have a page fault
            pageFaults++;

            // Find a frame to replace using the Second-Chance algorithm
            while (1) {
                if (frames[pointer].referenceBit == 0) {
                    frames[pointer].page = pages[i];  // Replace the page
                    frames[pointer].referenceBit = 1;  // Set reference bit to 1
                    pointer = (pointer + 1) % numFrames;  // Move pointer
                    break;
                } else {
                    frames[pointer].referenceBit = 0;  // Give second chance by clearing reference bit
                    pointer = (pointer + 1) % numFrames;  // Move pointer
                }
            }
        }

        // Display the current state of frames
        printf("\nFrames: ");
        for (k = 0; k < numFrames; k++) {
            if (frames[k].page == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k].page);
            }
        }
    }

    printf("\n\nTotal Page Faults: %d\n", pageFaults);
return 0;
}
