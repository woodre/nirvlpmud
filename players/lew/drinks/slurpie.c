int full;

id(str) {
    if (str == "slurpie" && full)
	return 1;
    return str == "cup";
}
query_save_flag() {return 1;}

short() {
    if (full)
	return "A giant slurpie";
    return "empty slurpie cup";
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
    if (str && str != "slurpie" && str != "from cup")
	return 0;
    if (!full)
	return 0;
    if (!call_other(this_player(), "drink_alcohol", 2))
	return 1;
    full = 0;
    write("It is a really good slurpie!\n");
    say(call_other(this_player(), "query_name", 0) +
	" drinks a slurpie.\n");
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
