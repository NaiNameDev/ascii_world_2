void def_gen(tileMapLayer *lay) {
	for (int i = 0; i < lay->size.x; i++) {
		for (int j = 0; j < lay->size.y; j++) {
			for (int o = 0; o < lay->size.z; o++) {
			}
			if (i * j  < lay->size.x * 8) {
				set_cell(lay, new_vec3(i, j, 0), new_tile_map_object(grass_id));
			}
			else {
				set_cell(lay, new_vec3(i, j, 0), new_tile_map_object(water_id));
			}
		}
	}
}
