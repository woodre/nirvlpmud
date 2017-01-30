short() {
    return "A newspaper" ;
}

long() {
    cat("/NEWS");
}

init() {
#if 0 /* Rumplemintz */
    add_action("read"); add_verb("read");
#else
  add_action("read", "read");
#endif
}

id(str) {
    return str == "newspaper" || str == "paper" || str == "news";
}

read(str) {
    if (!id(str))
	return 0;
    say(call_other(this_player(), "query_name") + " reads the newspaper.\n");
    long();
    return 1;
}

query_weight() { return 1; }

get() { return 1; }

query_value() { return 5; }
