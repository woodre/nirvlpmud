short() {
    return "A list of the top players" ;
}

long() {
  switch( random(3) ) {
    case 2:
      cat("/SORT_LEVEL");
      break;
    case 1:
      cat("/SORT_PRES");
      break;
    default:
      cat("/SORT_QP");
  }
      
}

init() {
#if 0 /* Rumplemintz */
    add_action("read"); add_verb("read");
#else
  add_action("read", "read");
#endif
}

id(str) {
    return str == "list" || str == "top" || str == "top players" ||
	str == "list of top players" || str == "top list";
}

read(str) {
    if (!id(str))
	return 0;
    say(call_other(this_player(), "query_name") + " reads the top list.\n");
    long();
    return 1;
}

query_weight() { return 1; }

get() { return 1; }

query_value() { return 5; }
