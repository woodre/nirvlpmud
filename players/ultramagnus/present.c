#define MAX_WEIGTH	6
int local_weight;

long() {
    write("A Wonderful Looking Box Wrapped in Red and Green Paper. ");
       write("It must me a Christmas Present for : Airwoman ...!!!!");
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
    return "A Present";
}

id(str) {
    return str == "present";
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
	write("You can't when there are things in the box.\n");
	return 1;
    }
    return 0;
}
