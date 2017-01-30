/* Well making a bag as treasure when standard low-cost bags are at max
 * is somewhat difficult. Since this is a unique item, it should be above
 * standard capacity. Therefore it has a capacity of 40.
 */
#define MAX_WEIGTH	40
int local_weight;

long() {
  write("This appears to be a typical leather bag. However, when you open it you notice that the inside area is nearly twice as large as the outside would suggest. This is a bag of holding.\n\n");
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
    return "A brown leather bag";
}

id(str) {
    return str == "bag";
}

query_value() {
    return 1000;
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

query_save_flag() { return 1; }
