short() {
    return "A poster" ;
}

long() {
    write("A handwritten poster, which says:  STOLEN!!!  2 scalpels from\n");
    write("this building three nights ago.  Exceptionally sharp and\n");
    write("potentially lethal in the wrong hands.\n\n");
}

init() {
#ifndef __LDMUD__ /* Rumplemintz */
    add_action("read"); add_verb("read");
#else
  add_action("read", "read");
#endif
}

id(str) {
    return str == "poster";
}

read(str) {
    if (!id(str))
	return 0;
    say(call_other(this_player(), "query_name") + " looks at the poster.\n");
    long();
    return 1;
}

query_weight() { return 1; }

get() { return 1; }

query_value() { return 8; }
