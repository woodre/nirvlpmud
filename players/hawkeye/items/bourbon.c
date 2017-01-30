int full;

id(str) {
    if (str == "bourbon" && full)
	return 1;
    return str == "bottle";
}

short() {
    if (full)
	return "bottle of bourbon";
    return "empty bottle";
}

/* The shop only buys empty bottles ! */

query_value()
{
    if (!full) return 10;
    return 0;
}

long() {
    write(short() + ".\n");
}

reset(arg) {
    if (arg)
        return;
    full = 1;
}

drink(str)
{
    if (str && str != "bourbon" && str != "from bottle")
	return 0;
    if (!full)
	return 0;
    if (!call_other(this_player(), "drink_alcohol", 2))
	return 1;
    full = 0;
    write("You feel a helluva lot better.\n");
    say(call_other(this_player(), "query_name", 0) +
	" drinks a bottle of bourbon.\n");
    return 1;
}

init() {
    add_action("drink","drink");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
query_save_flag() {
  if(!full) return 1;
}
