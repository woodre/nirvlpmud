#define MAX_WEIGTH	6
int local_weight;

long() {
write("This is a small plastic bag, lavishly decorated with loud colors\n"+
"and graphics. There is something written on it..\n");
write("\n");
write("Acme Products. Made in Taiwan.\n");
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
    return 1;
}

add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
	return 0;
    local_weight += w;
    return 1;
}

short() {
	return "A small plastic goodie bag";
}

id(str) {
    return str == "bag";
}

query_value() {
    return 12;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the bag.\n");
	return 1;
    }
    return 0;
}
