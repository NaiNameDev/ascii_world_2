#define def_color 0

#define wood_color 1
#define rock_color 2
#define grass_color 3
#define water_color 4
#define player_color 5

#define chosen_slot_color 255

#define pass false //passabe
#define unpass true //unpassable

#define log_id 1
#define log new_object(unpass, "log", 'O', log_id, wood_color)

#define rock_id 2
#define rock new_object(unpass, "rock", 'R', rock_id, rock_color)

#define grass_id 3
#define grass new_object(pass, "grass", ',', grass_id, grass_color)

#define water_id 4
#define water new_object(pass, "water", '~', water_id, water_color)

#define player_id 5
#define player_obj new_object(unpass, "player", 'Y', player_id, player_color)

#define other_player_id 6
#define other_player new_object(unpass, "other_player", 'P', other_player_id, player_color)

void init_pollete() {
	init_pair(chosen_slot_color, COLOR_BLACK, COLOR_WHITE); //inventory chosen slot color
	
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(wood_color, COLOR_YELLOW, COLOR_BLACK);
	init_pair(rock_color, COLOR_WHITE, COLOR_BLACK);
	init_pair(grass_color, COLOR_GREEN, COLOR_BLACK);
	init_pair(water_color, COLOR_CYAN, COLOR_BLACK);
	init_pair(player_color, COLOR_CYAN, COLOR_MAGENTA);
}

void init_objects() {
	append_object_level(&now_lvl, log);
	append_object_level(&now_lvl, rock);
	append_object_level(&now_lvl, grass);
	append_object_level(&now_lvl, water);
	append_object_level(&now_lvl, player_obj);
	append_object_level(&now_lvl, other_player);
}
