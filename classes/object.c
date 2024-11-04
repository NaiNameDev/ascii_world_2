typedef struct {
	short int id;
	char symbol;
	short int is_colide;
	short int pollete_id;
	void (*touch) (short int type);
} object;
object new_object(short int id, char sym, short int is_col, short int pollete_id) {
	object new;
	new.id = id;
	new.symbol = sym;
	new.is_colide = is_col;
	new.pollete_id = pollete_id;
	return new;
}

typedef struct {
	short int id;
	vec3 position;
} tileMapObject;

tileMapObject new_tile_map_object(short int id) {
	tileMapObject new;
	new.id = id;
	new.position = new_vec3(0,0,0);
	return new;
}

typedef struct {
	object* arr;
	short int size;
} objectLevel;

#define airobj new_object(0, '.', 0, 0)
objectLevel now_lvl;

void new_object_level(objectLevel* lvl) {
	lvl->size = 1;
	lvl->arr = malloc(sizeof(object));
	lvl->arr[0] = airobj;
}
void append_object_level(objectLevel* lvl, object to_add) {
	lvl->size += 1;
	to_add.id = lvl->size - 1;
	lvl->arr = realloc(lvl->arr, lvl->size * sizeof(object));
	lvl->arr[lvl->size - 1] = to_add;
}
void set_def_object_level(objectLevel lvl) {
	now_lvl = lvl;
}
object get_by_id(objectLevel lvl, short int id) {
	return lvl.arr[id];
}
