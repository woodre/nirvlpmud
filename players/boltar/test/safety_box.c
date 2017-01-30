int local_weight;
int box_is_open;
string name_of_box;

query_name() { return name_of_box; }

set_name(n) {
    name_of_box = n + "'s box";
}

id(str) {
    string b_name;
    b_name = call_other(this_player(),"query_name",0) + "'s box";
    return b_name == name_of_box;
}

short() {
    return name_of_box;
}

long() {
    write(call_other(this_player(),"query_name",0) + "'s safety deposit box.\n");
    recalc_carry();
    if (first_inventory(this_object()))
	write("There is something in it.\n");
    else
	write("You can put things in it.\n");
}

get() { return 0; }

can_put_and_get() { return 1;}

add_weight(w) {
    if (local_weight + w > 20)
	return 0;
    local_weight += w;
    return 1;
}

reset(arg) {
    if (arg)
	return;
    local_weight = 0;
}

/* This makes sure the amount we claim to be carrying is correct. */
recalc_carry() {
    object ob, next_ob;

    local_weight = 0;
    ob = first_inventory(this_object());
    while (ob) {
	next_ob = next_inventory(ob);
	local_weight += call_other(ob, "query_weight");
	ob = next_ob;
    }
}

