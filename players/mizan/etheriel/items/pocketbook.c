inherit "obj/armor";
#define MAX_WEIGTH	50
int local_weight;

long() {
write("This is a brown leather pocketbook, rather smallish, but you'd be\n"+
"surprised at the amount of stuff you could put in it.\n");
write("You can use 'put item in pb' instead of 'put item in pocketbook'.\n");
    if (first_inventory(this_object()))
	write("It looks like there is stuff in it.\n");
    else
	write("It is currently empty.\n");
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0;
::reset(arg) ;
	set_short("A small brown pocketbook");
	set_weight(3);
	set_value(5000);
	set_ac(1);
	set_type("misc");
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
	if(worn) return "A small brown pocketbook (worn)";
	return "A small brown pocketbook";
}

id(str) {
    return str == "pocketbook" || str == "pb"; 
}

query_value() {
    return 5000;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

prevent_insert() {
    if (local_weight > 0) {
	write("You can't when there are things in the pockets.\n");
	return 1;
    }
    return 0;
}
