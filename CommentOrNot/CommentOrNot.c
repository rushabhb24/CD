#include <stdio.h> 
#include <stdbool.h> 
int main() { 
FILE *file = fopen("ABC.c", "r"); // Replace "source_code.c" with your file name 
if (file == NULL) { 
printf("Error opening the file.\n"); 
return 1; 
} 
char line[1000]; 
int line_number = 0; 
while (fgets(line, sizeof(line), file)) { 
line_number++; 
bool in_comment = false; 
for (int i = 0; line[i] != '\0'; i++) { 
if (line[i] == '/' && line[i + 1] == '/') { 
printf("Line %d: Single-line comment\n", line_number); 
break; // Move to the next line 
} 
if (line[i] == '/' && line[i + 1] == '*') { 
in_comment = true; 
} 
if (in_comment && line[i] == '/' && line[i + 1] == '*') { 
printf("Line %d: Multi-line comment\n", line_number); 
in_comment = false; 
} 
} 
} 
fclose(file); 
return 0; 
}
