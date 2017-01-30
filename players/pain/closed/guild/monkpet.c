#define HOME "/players/hawkeye/closed/guild/guild_room"
#define MAX_WEIGTH	20
int local_weight;


reset(arg) {
    if (arg)
	return;
    local_weight = 0;
move_object(this_object(),HOME);
}

query_weight() {
    return 1;
}

drop() {return 1;}
add_weight(w) {
    if (local_weight + w > MAX_WEIGTH)
	return 0;
    local_weight += w;
    return 1;
}


id(str) {
   return str == "garyspetobj" || str == "monk bag" || str == "monk_obj";
}

query_value() {
    return 1;
}

can_put_and_get() { return 1; }

get() {
    return 1;
}

