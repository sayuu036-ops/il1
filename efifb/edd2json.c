#include <stdio.h>
#include <stdlib.h>
#define FILENAME "test.i"

void escape_dq(char* line);
void indent(int nest);


int main(void)
{
        FILE * fp;
        char * line = NULL;
        size_t len = 0;
        ssize_t read;

        fp = fopen(FILENAME, "r");
        if (fp == NULL)
                exit(EXIT_FAILURE);
	int i = 0;
	int prev = 1;
	bool isprev = false;
	int nest = 0;
	printf("========================================================================================\n");
        while ((read = getline(&line, &len, fp)) != -1) {
		i++;
#ifdef TEST
		if(i < 1000) continue;
		if(i > 2000) break;
#endif
		if(read == 1) continue;
		if(*line == '#' && *(line + sizeof(char)) == ' '){
			char l = *(line + sizeof(char) * (read - 2));
			if(l == '1'){
				if(prev == 0){
					printf("\n");
					indent(nest);
					printf("]},");
				}
				if(prev == 1){}
				if(prev == 2){}
				nest++;
				printf("\n");
				indent(nest);
				printf("{from: \"");
				escape_dq(line);
				printf("\", content: [");
				prev = 1;
				isprev = true;
			} else if(l == '2'){
				if(prev == 0){
					printf("\n");
					indent(nest);
					printf("]}");
				}
				if(prev == 1){}
				if(prev == 2){}
				printf("\n");
				indent(nest);
				printf("]}");
				prev = 2;
				isprev = true;
				nest--;
			} else {
				if(prev == 0){
					printf("\n");
					indent(nest);
					printf("]}");
				}
				if(prev == 1){}
				if(prev == 2){}
				printf("\n");
				indent(nest);
				printf("{from: \"");
				escape_dq(line);
				printf("\", content: [");
				prev = 0;
				isprev = true;
			}
		}else{
			if(!isprev){printf(", ");}
			printf("\n");
			indent(nest);
			printf("  \"");
			escape_dq(line);
			printf("\"");
			isprev = false;
		}

        }
	printf("\n]}");
        fclose(fp);
        if (line)
                free(line);
        exit(EXIT_SUCCESS);
}

void escape_dq(char* line)
{
	while(*line){
		if(*line == '\"'){
			printf("\\\"");
			line++;
		} else if(*line != '\n') {
			printf("%c", *(line++));
		} else {
			return;
		}
	}
}

void indent(int nest)
{
	int n = nest;
	while(n--){
		printf("	");
	}
	return;
}
