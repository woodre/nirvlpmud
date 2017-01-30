#define MAX_WEIGTH	10
int local_weight;

long() {
    write("A light basket crafted from plant fibers. It's used in the\n"+
	      "market to carry all kinds of merchandize.\n");
    if (first_inventory(this_object()))
	write("In it, you can see some items.\n");
    else
	write("it's empty.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 1;
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
    return "Light basket";
}

id(str) {
    return str == "basket";
}

query_value() {
    return 100;
}

can_put_and_get() { return 1; }

get() {
    return 1;
	}