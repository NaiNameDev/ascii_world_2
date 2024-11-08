#include <ncurses.h>
#include <panel.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define true 1
#define false 0

#include "utils/vector.c"

#include "utils/string.c"
#include "classes/object.c"
#include "game/obejcts.c"
#include "classes/tilemap.c"
#include "game/generator.c"
#include "classes/entity.c"

int main(int argc, char *argv[]) {
	initscr();
	start_color();
	noecho();
	curs_set(0);
	
	/*int x,y;
	getmaxyx(stdscr, x, y);
	
	char msg[] = "WELCOME TO ASCII WORLD 2";
	move(x / 2, y / 2 - strlen(msg) / 2);
	for (int i = 0; i < strlen(msg); i++) {
		addch(msg[i]);
		refresh();
		usleep(100000);
	}

	sleep(1);
	*/
	//refresh();

	int x,y; getmaxyx(stdscr, x, y);
	WINDOW* game_win = newwin(18, 34, x / 2 - 9, y / 2 - 16);
	WINDOW* inv_win = newwin(6, 34, x / 2 + 9, y / 2 - 16);
	refresh();
	
	objectLevel objl;
	new_object_level(&objl);
	set_def_object_level(objl);

	init_pollete();
	init_objects();

	tileMapLayer ntm = new_tile_map_layer(new_vec3(32,32,7));
	def_gen(&ntm);

	set_free_cell(&ntm, new_vec3(5,5,1), new_tile_map_object(other_player_id));
	entity player = new_entity(set_cell(&ntm, new_vec3(5,4,1), new_tile_map_object(player_id)), &ntm);

	inventory inv;
	init_inv(&inv, 10);

	int ch;
	while(1) {
		if(ch == 'Q') { break; }
		
		if (ch == 's') {
			move_entity(&player, vec3_to_vec2(vec3_plus(player.self->position, new_vec3(1,0,0))));
		}
		if (ch == 'w') {
			move_entity(&player, vec3_to_vec2(vec3_minus(player.self->position, new_vec3(1,0,0))));
		}
		if (ch == 'd') {
			move_entity(&player, vec3_to_vec2(vec3_plus(player.self->position, new_vec3(0,1,0))));
		}
		if (ch == 'a') {
			move_entity(&player, vec3_to_vec2(vec3_minus(player.self->position, new_vec3(0,1,0))));
		}
		if (ch == '1') {
			inv.chosen_slot -= 1;
		}
		if (ch == '2') {
			inv.chosen_slot += 1;
		}
		if (ch == 'x') {
			add_to_inv(&inv, new_item(get_by_id(now_lvl, get_last_cell(ntm, vec3_to_vec2(vec3_minus(player.self->position, new_vec3(1,0,0))))->id), 1));
			set_free_cell(&ntm, get_last_cell(ntm, vec3_to_vec2(vec3_minus(player.self->position, new_vec3(1,0,0))))->position, air);
		}
		if (ch == 'e') {
			set_free_cell(&ntm, get_free_space(&ntm, vec3_to_vec2(vec3_minus(player.self->position, new_vec3(1,0,0))))->position, new_tile_map_object(inv.arr[inv.chosen_slot].self.id));
		}
		
		//move(x / 2 - 8, y / 2 - 14);
		//printw("ASCII WORLD 2");

		read_layer(ntm, new_vec3(player.self->position.x - 8, player.self->position.y - 8,0), new_vec3(player.self->position.x + 9, player.self->position.y + 9,0), game_win);
		read_inv(&inv, inv_win);
		
		ch = getch();
		usleep(30000);
	}

	endwin();
	return 0;
}
