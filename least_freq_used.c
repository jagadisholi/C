
#include <stdio.h>

#define MAX_FRAMES 10 
#define MAX_REF_STR_LEN 100

int findLFU(int freq[], int n) {
    int min = freq[0], pos = 0;

    for (int i = 1; i < n; i++) {
        if (freq[i] < min) {
            min = freq[i];
            pos = i;
        }
    }

    return pos;
}

int main() {
    int frames[MAX_FRAMES], freq[MAX_FRAMES], ref_str[MAX_REF_STR_LEN];
    int n, no_of_frames, page_faults = 0;
    int i, j, k, found, pos;

    // Initialize frames and frequencies
    for (i = 0; i < MAX_FRAMES; i++) {
        frames[i] = -1;
        freq[i] = 0;
    }

    printf("Enter number of frames: ");
    scanf("%d", &no_of_frames);

    printf("Enter length of reference string: ");
    scanf("%d", &n);

    printf("Enter the reference string: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &ref_str[i]);
    }

    // LFU page replacement simulation
    for (i = 0; i < n; i++) {
        found = 0;

        // Check if the page is already in one of the frames
        for (j = 0; j < no_of_frames; j++) {
            if (frames[j] == ref_str[i]) {
                found = 1;
                freq[j]++;
                break;
            }
        }

        if (!found) {
            // Page not found, so we have a page fault
            page_faults++;

            // Find the position to replace
            if (i < no_of_frames) {
                pos = i; // Initially, fill the frames
            } else {
                pos = findLFU(freq, no_of_frames); // Find LFU page position
            }

            frames[pos] = ref_str[i];
            freq[pos] = 1;
        }

        // Display the current status of frames
        printf("\nFrames: ");
        for (k = 0; k < no_of_frames; k++) {
            if (frames[k] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[k]);
            }
        }
    }

    printf("\n\nTotal Page Faults: %d\n", page_faults);

    return 0;
}