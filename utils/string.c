typedef struct {
	int size;
	char* str;
} string;

string init_new_string(char* str) {
	string new;
	new.size = strlen(str) + 1;
	new.str = malloc(sizeof(char) * new.size);

	for (int i = 0; i < new.size - 1; i++) {
		new.str[i] = str[i];
	}
	new.str[new.size] = '\0';
	return new;
}
void init_str(string new, char* str) {
	new.size = strlen(str);
	new.str = malloc(sizeof(char) * new.size);

	for (int i = 0; i < new.size - 1; i++) {
		
	}
	new.str[new.size] = '\0';
}
void string_append(string* str, char* add) {
	int start_point = str->size - 1;
	str->size += strlen(add);
	str->str = realloc(str->str, sizeof(char) * str->size);

	for (int i = 0; i < str->size - 1; i++) {
		str->str[i + start_point] = add[i];
	}
	str->str[str->size] = '\0';
}

void free_str(string* str) {
	free(str->str);
}
