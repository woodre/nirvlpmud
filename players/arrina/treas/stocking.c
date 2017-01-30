#define MAX_WEIGTH	6
#include <ansi.h> /* 2007-10-29 converted to std ansi.h -vital */
int local_weight;
string short_desc;
long() {
    write(HIR+"A Fuzzy Red Christmas Stocking\n"+NORM);
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
    return short_desc;
}

id(str) {
    return str == "stocking";
}

query_value() {
    return 5;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the stocking.\n");
	return 1;
    }
    return 0;
}
set_short(sh) {
    short_desc = HIR+sh+NORM;
	return 1;
	}
