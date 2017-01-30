/*
	db_funs.c - A collection of simple database (stored in a 2 dimentional
	            mapping) functions
				
	functions: get_db_from_file(), print_db()
	
	author: Quicksilver @ Nirvana
	
	history: v1.0 - 20-May-2004
*/

#include "/players/quicksilver/std/std.h"
#define DEBUG 0

mapping get_db_from_file(string file, string *separator) {
	mapping map_data;
	string file_text;
	string *arr_inner, *arr_outer;
	int i, j;
	
	if(!(file_text = read_file(file))) return 0;  /* open failed */
	if(DEBUG) write(file+" opened.\n");
	
	/* init vars */
	map_data = ([ ]);
	if(!separator) separator = ({ "*|", "|" });
	
	/* store outer mapping (still array, for now), sep. by separator[0] */
	arr_outer = explode(file_text, separator[0]);
	if(DEBUG) {
		write("arr_outer:\n");
		for(i = 0; i < sizeof(arr_outer); i++)
			write(i + ": " + arr_outer[i] + "\n");
	}

	/* outer loop extracts key, builds outer map */
	for(i = 0; i < sizeof(arr_outer); i++) {
		arr_inner = explode(arr_outer[i], separator[1]);
		if(DEBUG) {
			write("arr_inner:\n");
			for(j = 0; j < sizeof(arr_inner); j++) write(j+": "+arr_inner[j]+"\n");
		}
		
		if(!arr_inner) return 0;  /* bad format...?! */
		if(!arr_inner[i] || (arr_inner[i] == "")) continue;  /* skip nulls */
		
		/* arr_inner[0] is always the key for map_data.  if there's an
		   inner mapping, we need to store it; otherwise, just toss
		   it in map_data */
		if(sizeof(arr_inner) > 2) {
			/* init inner map */
			map_data[arr_inner[0]] = ([ ]);
			
			/* build inner map */
			for(j = 1; j < sizeof(arr_inner); j = j + 2) {
				/* records should be saved as follows (assuming default
				   separators):
				   *|db_key|key1|val1|key2|val2...|keyN|valN */
				map_data[arr_inner[0]] += ([ arr_inner[j]:
				                             arr_inner[j + 1] ]);
				if(DEBUG) 
					write(j + ": map_data[" + arr_inner[0] +
					      "] += ([ map_data[" + arr_inner[j] + "]: " +
						  arr_inner[j + 1] + " ])\n");
			}
		} else map_data[arr_inner[0]] = arr_inner[1];
	}
	return map_data;
}

int print_db(mixed data, int indent) {
	int i;
	string *keys;
	
	if(!data) { write("Null db mapping: Nothing to print.\n"); return 1; }
	
	if(!indent) {
		keys = m_indices(data);
		if(!sizeof(keys)) { write("Empty db: Nothing to print.\n"); return 1; }
		write("([\n");
	} else {
		if(pointerp(data)) {
			write("({\n");
			for(i = 0; i < sizeof(data); i++) write(data[i] + "\n");
			write("})\n");
		} else {
			write("([\n");
			keys = m_indices(data);
		}
	}
	for(i = 0; i < sizeof(keys); i++) {
		write(keys[i] + ": ");
		if(pointerp(data[keys[i]]) || mapp(data[keys[i]])) {
			print_db(data[keys[i]], (indent + strlen(keys[0]) + 2));
		}
		else {
			write(data[keys[i]] + "\n");
		}
	}
	write("])\n");
	return 1;
}