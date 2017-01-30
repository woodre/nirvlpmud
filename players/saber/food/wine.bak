int full;

id(str) {
    if (str == "wine" && full)
	return 1;
    return str == "bottle";
}

short() {
    if (full)
     return "A bottle of wine";
    return "An empty bottle";
}

/* The shop only buys empty bottles ! */

query_value()
{
    if (!full) return 5;
    return 150;
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
    if (str && str != "wine" && str != "from bottle")
	return 0;
    if (!full)
	return 0;
    if (!call_other(this_player(), "drink_alcohol", 21))
	return 1;
    full = 0;
     write("You finish off the bottle of wine.\n"+
          "That was quite good.\n");
    say(call_other(this_player(), "query_name", 0) +
    " finishes off a bottle of wine.\n");
    return 1;
}

init() {
    add_action("drink"); add_verb("drink");
}

get() {
    return 1;
}

query_weight() {
    return 1;
}
