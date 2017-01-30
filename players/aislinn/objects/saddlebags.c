#define MAX_WEIGHT	20
int local_weight;

long() {
    write("Large saddlebags. ");
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
    if (local_weight + w > MAX_WEIGHT)
	return 0;
    local_weight += w;
    return 1;
}

short() {
    return "saddlebags";
}

id(str) {
    return (str == "bag" || str == "saddlebags");
}

query_value() {
    return 17;
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
