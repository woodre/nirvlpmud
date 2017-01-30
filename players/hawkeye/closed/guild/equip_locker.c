#define MAX_WEIGTH	100000
int local_weight;

long() {
    if (first_inventory(this_object()))
write("The Guild Locker.\n");
    else
 write("The Guild Locker is currently Empty.\n");
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
  return "The Guild Storage Locker";
}

id(str) {
    return str == "locker";
}

query_value() {
    return 50;
}

can_put_and_get() { return 1; }

get() {
  return;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the bag.\n");
	return 1;
    }
    return 0;
}
