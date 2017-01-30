#define MAX_WEIGHT	3
int local_weight;

long() {
    write("A trophy case. ");
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0;
}

query_weight() {
    return 3;
}

add_weight(w) {
    if (local_weight + w > MAX_WEIGHT)
	return 0;
    local_weight += w;
    return 1;
}

short() {
    return "A Trophy Case";
}

id(str) {
    return str == "trophy case";
}

query_value() {
    return 4000;
}

can_put_and_get() { return 1; }

get() {
  if(!environment()) return;
    if (!present("Trophy guard", environment(this_object()))) {
       return 1;
    }
    write("The guard says: Hands off!\n");
    return 0;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the bag.\n");
	return 1;
    }
    return 0;
}
