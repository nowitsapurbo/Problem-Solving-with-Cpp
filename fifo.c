#include <stdio.h>

void fifo(int pages[], int n, int frames) {
    int frame[frames], index = 0, faults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            faults++;
        }
    }

    printf("\nFIFO Page Faults: %d\n", faults);
}

void lru(int pages[], int n, int frames) {
    int frame[frames], time[frames], faults = 0, count = 0;

    for (int i = 0; i < frames; i++) {
        frame[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                time[j] = ++count;
                break;
            }
        }

        if (!found) {
            int lruIndex = 0;
            for (int j = 1; j < frames; j++) {
                if (time[j] < time[lruIndex])
                    lruIndex = j;
            }
            frame[lruIndex] = pages[i];
            time[lruIndex] = ++count;
            faults++;
        }
    }

    printf("\nLRU Page Faults: %d\n", faults);
}

void optimal(int pages[], int n, int frames) {
    int frame[frames], faults = 0;

    for (int i = 0; i < frames; i++)
        frame[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int replaceIndex = -1, farthest = i + 1;
            for (int j = 0; j < frames; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frame[j] == pages[k])
                        break;
                }
                if (k > farthest) {
                    farthest = k;
                    replaceIndex = j;
                }
                if (frame[j] == -1) {
                    replaceIndex = j;
                    break;
                }
            }

            if (replaceIndex == -1)
                replaceIndex = 0;

            frame[replaceIndex] = pages[i];
            faults++;
        }
    }

    printf("\nOptimal Page Faults: %d\n", faults);
}

int main() {
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4};
    int n = 8, frames = 3;
    int choice;

    while (1) {
        printf("\n--- Page Replacement Menu ---\n");
        printf("1. FIFO\n");
        printf("2. LRU\n");
        printf("3. Optimal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                fifo(pages, n, frames);
                break;
            case 2:
                lru(pages, n, frames);
                break;
            case 3:
                optimal(pages, n, frames);
                break;
            case 4:
                printf("Exiting program...\n");
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
}
