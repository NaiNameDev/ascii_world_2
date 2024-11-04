#define define_dynamic(T) typedef struct {\
	T* arr;\
	int size;\
} dynamic;

#define define_init_dynamic void init_dynamic(dynamic* arr, int size) {\
	arr->size = size;\
	arr = malloc(size * sizeof(dynamic));\
}

#define define_append(T) void append_##T(dynamic* dyn, T to_add) {\
	dyn->size += 1;\
	dyn = realloc(dyn, dyn->size * sizeof(T));\
	dyn->arr[dyn->size] = to_add;\
}

#define define_reappend(T) void reappend_##T(dynamic* dyn) {\
	dyn->size -= 1;\
	dyn = realloc(dyn, dyn->size * T);\
}

//#define define_free_dynamic(T) free_dinamic(T)
