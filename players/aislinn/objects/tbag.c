#define MAX_WEIGTH	15
int local_weight;

long() {
    write("A tennis racquet bag.");
    if (first_inventory(this_object()))
	write("There apears to be something in it.\n");
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
    return "racquet bag";
}

id(str) {
    return (str == "bag" || str == "racquet bag");
}

query_value() {
    return 150;
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
