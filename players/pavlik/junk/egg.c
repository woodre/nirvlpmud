#include "/players/pavlik/junk/throw"
#define MAX_WEIGTH	6
int local_weight;

long() {
    write("A colorful Easter egg ");
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
   write("You can put items in the egg and throw it at other\n"+
     "players.  You can: get/put (item) from egg \n"+
   "and you can: egg (player)\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0;
}

query_weight() {
    return 1;
}

add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
	return 0;
    local_weight += w;
    return 1;
}

short() {
    return "Easter egg";
}

id(str) {
    return str == "egg";
}

query_value() {
    return 300;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the egg.\n");
	return 1;
    }
    return 0;
}
init(){
  add_action("throw_it","egg");
}
