#define MAX_WEIGTH	800
int local_weight;

long() {
  write("This is an ordinary cardboard box you can put things in.\n"+
  "It seems that ammunition for the catapult would go in here.\n");
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

reset(arg) {
  move_object(clone_object("players/mizan/etheriel/items/fake-tiamat.c"), this_object());
    if (arg)
	return;
    local_weight = 0;
}


add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
	return 0;
    local_weight += w;
    return 1;
}

short() {
  return "A big cardboard box";
}

id(str) {
    return str == "box";
}

query_value() {
    return 12;
}

can_put_and_get() { return 1; }


prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the box.\n");
	return 1;
    }
    return 0;
}
