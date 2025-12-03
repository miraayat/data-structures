#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
int n;
printf("Enter number of people in the group: ");
scanf("%d", &n);

int connections[n][n];
int informed[n];
int newly_informed[n];

srand(time(0)); // for random connections

// Generate random connection matrix (0s and 1s)
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
if (i == j)
connections[i][j] = 0; // no self connection
else
connections[i][j] = rand() % 2; // random 0 or 1
}
}

printf("\nGenerated Connection Matrix:\n");
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++)
printf("%d ", connections[i][j]);
printf("\n");
}

int start;
printf("\nEnter the starting person (0 to %d): ", n - 1);
scanf("%d", &start);

// Initialize informed array
for (int i = 0; i < n; i++) informed[i] = 0;
informed[start] = 1;

int total_informed = 1, round = 1;

printf("\n--- Information Diffusion Simulation ---\n");

// Repeat until everyone knows
while (total_informed < n) {
for (int i = 0; i < n; i++) newly_informed[i] = 0;

printf("\nRound %d:\n", round);

for (int i = 0; i < n; i++) {
if (informed[i]) {
for (int j = 0; j < n; j++) {
if (connections[i][j] == 1 && !informed[j]) {
newly_informed[j] = 1;
printf("Person %d informed Person %d\n", i, j);
}
}
}
}

int new_count = 0;
for (int i = 0; i < n; i++) {
if (newly_informed[i]) {
informed[i] = 1;
new_count++;
}
}

if (new_count == 0) {
printf("No new people informed this round. Information stopped spreading.\n");
break;
}

total_informed += new_count;
round++;
}

printf("\nTotal rounds: %d\n", round - 1);
printf("People informed: ");
for (int i = 0; i < n; i++)
if (informed[i]) printf("%d ", i);
printf("\n");

return 0;
}
