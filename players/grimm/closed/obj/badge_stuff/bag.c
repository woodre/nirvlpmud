int local_weight;
int MAX_WEIGTH;

long() {
    write("A Mystic's bag. ");
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0;
    MAX_WEIGTH = 6;
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
    return "bag";
}

id(str) {
    return str == "bag";
}

query_value() {
    return 500;
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

set_max_weigth(x) { MAX_WEIGTH = x; }