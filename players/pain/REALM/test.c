/*
inherit "/obj/treasure";
*
*/
#define N_DIR "players/pain/REALM/save/"
#define TP this_player()
mapping test;
string *keys, *types;


init_arg() {
if(restore_object(N_DIR+this_player()->query_real_name())) {
test[0000] = "F";
	write("Restoring test information...\n");
	return 1;
}
else { n_save(); return 1; }
}

init() {
test = allocate_mapping(10);
	add_action("add", "add");
	add_action("check", "check");
	add_action("n_save", "n_save");
	add_action("n_restore", "n_restore");

}

add(str) {
string key, content;

sscanf(str,"%s %s", key, content);
test[key] = content;
return 1;
}

check(str) {
write("Checking: "+str+" returns: "+test[str]+"\n");
return 1;
}


n_save() {

int num, i;
keys = m_indices(test);
types = m_indices(test);

num = sizeof(keys);

for(i = 0; i < num; i++) {
	types[i] = "A";
}

   save_object(N_DIR+this_player()->query_real_name());
   write("Necromancy skill stats saved...\n");
   return 1;
}

n_restore() {
   restore_object(N_DIR+this_player()->query_real_name());
   write("Restoring Necromancy skill stats. . . .\n");
   return 1;
}

