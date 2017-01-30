#define MAX_WEIGTH	25
int local_weight;

long() {
   write("You see a wide band of pure gold, simple and elegant.\n"+
         "\n"+
         "Type "help ring ."\n");
    if (first_inventory(this_object()))
	write("There is something on it.\n");
    else
	write("You can put things on it.\n");
}
id(str)
 { return str == "table"; }

reset(arg) {
move_object(clone_object("/players/daranath/qualtor/obj/gob_cryst.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/wep/brose_dag.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/redwine.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/sm_ruby.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/sil_helm.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/obj/crusader_sh.c"),this_object());
    if (arg)
	return;
    local_weight = 0;
}

query_wieght() { return 1; }

add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
	return 0;
    local_weight += w;
    return 1;
}

short() {
    return "An Ornate Wooden table";
}

query_value() { return 350; }

can_put_and_get() { return 1; }

get() { return 0; }

prevent_insert() {
    if (local_weight > 0) {
   write("There are already too many items on the table.\n");
	return 1;
    }
    return 0;
}
