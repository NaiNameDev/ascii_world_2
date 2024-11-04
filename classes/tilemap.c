typedef struct {
	tileMapObject* map;
	vec3 size;
} tileMapLayer;

size_t vec3_to_size(vec3 pos, vec3 size) {
	return (size.x * size.y * pos.z) + (pos.x * size.y + pos.y); // hello from ascii_world 1 :)
}

#define air new_tile_map_object(0)
tileMapLayer new_tile_map_layer(vec3 size) {
	tileMapLayer new;
	new.size = size;
	new.map = malloc((size.x * size.y * size.z) * sizeof(tileMapObject));

	for (int i = 0; i < size.x; i++) {
		for (int j = 0; j < size.y; j++) {
			for (int o = 0; o < size.z; o++) {
				new.map[vec3_to_size(new_vec3(i, j, o), new.size)] = air;
				new.map[vec3_to_size(new_vec3(i, j, o), new.size)].position = new_vec3(i, j, o);
			}
		}
	}
	return new;
}

void set_free_cell(tileMapLayer* tmp, vec3 position, tileMapObject obj) {
	obj.position = position;
	tmp->map[vec3_to_size(position, tmp->size)] = obj;
}
tileMapObject* set_cell(tileMapLayer* tmp, vec3 position, tileMapObject obj) {
	obj.position = position;
	tmp->map[vec3_to_size(position, tmp->size)] = obj;
	return &tmp->map[vec3_to_size(position, tmp->size)];
}
tileMapObject* get_cell(tileMapLayer* lay, vec3 position){
	return &lay->map[vec3_to_size(position, lay->size)];
}
tileMapObject* get_last_cell(tileMapLayer map, vec2 position) {
	tileMapObject* to_ret = &map.map[vec3_to_size(vec2_to_vec3(position, 0), map.size)];

	for (int i = 0; i < map.size.z; i++) {
		if (map.map[vec3_to_size(vec2_to_vec3(position, i), map.size)].id > 0) {
			to_ret = &map.map[vec3_to_size(vec2_to_vec3(position, i), map.size)];
		}
	}
	return to_ret;
}
tileMapObject* get_free_space(tileMapLayer *map, vec2 position) {
	for (int i = 0; i < map->size.z; i++) {
		if (get_cell(map, vec2_to_vec3(position, i))->id <= 0) {
			return get_cell(map, vec2_to_vec3(position, i));
		}
	}
	return get_cell(map, vec2_to_vec3(position, 0));
}
tileMapObject* move_cell(tileMapLayer* map, vec2 to, tileMapObject obj) {
	if (to.x >= 0 && to.y >= 0 && to.x < map->size.x && to.y < map->size.y) {
		set_free_cell(map, obj.position, air);
		set_free_cell(map, get_free_space(map, to)->position, obj);
		return get_last_cell(*map, to);
	}
	return get_cell(map, obj.position);
}

void read_layer(tileMapLayer rid, vec3 from, vec3 to) {
	int scx, scy; getmaxyx(stdscr, scx, scy);
	clear();
	vec3 real_size = vec3_minus(to, from);

	move((scx / 2) - (real_size.x / 2), (scy / 2) - (real_size.y / 2));
	int cnt = 0;
	for (int i = from.x; i < to.x; i++) {
		for (int j = from.y; j < to.y; j++) {
			if (i >= 0 && j >= 0 && i < rid.size.x && j < rid.size.y) {
				object obj = get_by_id(now_lvl, get_last_cell(rid, new_vec2(i, j))->id);
				attron(COLOR_PAIR(obj.pollete_id));
				addch(obj.symbol);
				attroff(COLOR_PAIR(obj.pollete_id));
				addch(' ');
			}
			else {
				addch(' ');
				addch(' ');
			}
		}
		cnt++;
		move(cnt + scx / 2 - real_size.x / 2, scy / 2 - real_size.y / 2);
	}
}
