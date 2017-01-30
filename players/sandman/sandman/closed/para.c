
int start_time;

query_auto_load() {
    return "players/sandman/closed/para:" + start_time;
}

start(ob) {
    move_object(this_object(), ob);
    start_time = time();
    tell_object(ob, "Your muscles seize up for some reason.\n");
}

id(str) {
    return str == "para";
}

long() {
    return 0;
}

drop() { return 1; }

init() {
    add_action("not");  add_xverb("");
}

not() {
    if (time() < start_time + 1000) {
	say(call_other(this_player(), "query_name") +
	    " twitches.\n");
	return 1;
    } else {
	destruct(this_object());
	return 0;
    }
}

init_arg(str) {
    sscanf(str, "%d", start_time);
}

short() {
    return 0;
}
