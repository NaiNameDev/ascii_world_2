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
	if (get_last_cell())
	ent->self = move_cell(ent->self_map, new_pos, *ent->self);
}
