int full;

id(str) {
    if (str == "firebreather" && full)
	return 1;
    return str == "bottle";
}

short() {
    if (full)
        return "a firebreather";
    return "an empty bottle";
}

/* The shop only buys empty bottles ! */

query_value()
{
    if (!full) return 2;
    return 0;
}

long() {
   write("A bottle for holding drinks.\n");
}

reset(arg) {
    if (arg)
        return;
    full = 1;
}

drink(str)
{
    if (str && str != "firebreather" && str != "from bottle")
	return 0;
    if (!full)
	return 0;
    if (!call_other(this_player(), "drink_alcohol", 20))
	return 1;
    full = 0;
    write("A shock wave runs through your body.\n");
    say(call_other(this_player(), "query_name", 0) +
	" drinks a bottle of beer.\n");
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
