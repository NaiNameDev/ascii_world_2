typedef struct {
	short int x;
	short int y;
} vec2;

vec2 new_vec2(short int x, short int y) {
	vec2 new;
	new.x = x;
	new.y = y;
	return new;
}

vec2 vec2_plus(vec2 f, vec2 s) {
	return new_vec2(f.x + s.x, f.y + s.y);
}
vec2 vec2_minus(vec2 f, vec2 s) {
	return new_vec2(f.x - s.x, f.y - s.y);
}

typedef struct {
	short int x;
	short int y;
	short int z;
} vec3;

vec3 new_vec3(short int x, short int y, short int z) {
	vec3 new;
	new.x = x;
	new.y = y;
	new.z = z;
	return new;
}

void vec3_print(vec3 to_pr) {
	printw("Vec3(%d, %d, %d)", to_pr.x, to_pr.y, to_pr.z);
}

vec3 vec3_plus(vec3 f, vec3 s) {
	return new_vec3(f.x + s.x, f.y + s.y, f.z + s.z);
}
vec3 vec3_minus(vec3 f, vec3 s) {
	return new_vec3(f.x - s.x, f.y - s.y, f.z - s.z);
}

vec3 vec2_to_vec3(vec2 vec, short int z) {
	vec3 new;
	new = new_vec3(vec.x, vec.y, z);
	return new;
}
vec2 vec3_to_vec2(vec3 vec) {
	vec2 new;
	new = new_vec2(vec.x, vec.y);
	return new;
}

typedef struct {
	short int x;
	short int y;
	short int z;
	short int w;
} vec4;
