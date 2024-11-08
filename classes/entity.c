typedef struct {
	tileMapObject* self;
	tileMapLayer* self_map;
} entity;

entity new_entity(tileMapObject* self, tileMapLayer* self_map) {
	entity new;
	new.self = self;
	new.self_map = self_map;
	return new;
}

void move_entity(entity* ent, vec2 new_pos) {
	if (search_colide(ent->self_map, new_pos) == false) {
		if (search_id(ent->self_map, new_pos, 0) == true) {
			ent->self = move_cell(ent->self_map, new_pos, *ent->self);
		}
	}
}

typedef struct {
	int count;
	object self;
} item;
item new_item(object obj, int cnt) {
	item new;
	new.self = obj;
	new.count = cnt;
	return new;
}
#define null_item new_item(new_object(-1, "", '.', 0, 0), 0);

typedef struct {
	int size;
	int chosen_slot;
	item* arr;
} inventory;

void init_inv(inventory* inv, int size) {
	inv->size = size;
	inv->chosen_slot = 0;
	inv->arr = malloc(sizeof(item) * size);

	for (int i = 0; i < size; i++) {
		inv->arr[i] = null_item;
	}
}
void add_to_inv(inventory* inv, item itm) {
	for (int i = 0; i < inv->size; i++) {
		if (inv->arr[i].self.id == itm.self.id) {
			inv->arr[i].count += itm.count;
			return;
		}
	}
	for (int i = 0; i < inv->size; i++) {
		if (inv->arr[i].self.symbol == '.') {
			inv->arr[i] = itm;
			return;
		}
	}
}
void set_to_inv(inventory* inv, int index, item itm) {
	inv->arr[index] = itm;
}
void read_inv(inventory* inv, WINDOW* win) {
	wclear(win);
	box(win, 0, 0);
	wmove(win, 0, 2);
	wprintw(win, "inventory");
	wmove(win, 1, 6);
	
	for (int i = 0; i < inv->size; i++) {
		if (i != inv->chosen_slot) {
			wattron(win, COLOR_PAIR(inv->arr[i].self.pollete_id));
			waddch(win, inv->arr[i].self.symbol);
			wattroff(win, COLOR_PAIR(inv->arr[i].self.pollete_id));
			waddch(win, ' ');
		}
		else {
			wattron(win, COLOR_PAIR(chosen_slot_color));
			waddch(win, inv->arr[i].self.symbol);
			wattroff(win, COLOR_PAIR(chosen_slot_color));
			waddch(win, ' ');
		}
	}
	wmove(win, 2, 6);
	wprintw(win, inv->arr[inv->chosen_slot].self.name.str);
	if (inv->arr[inv->chosen_slot].count > 1) { wprintw(win, " X%d", inv->arr[inv->chosen_slot].count); }
	wrefresh(win);
}
