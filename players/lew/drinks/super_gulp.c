int full;

id(str) {
    if (str == "big_gulp" && full)
	return 1;
    return str == "cup";
}
query_save_flag() {return 1;}

short() {
    if (full)
        return "A Super Big Gulp";
    return "empty Super Big Gulp cup";
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
    if (str && str != "gulp" && str != "from cup")
	return 0;
    if (!full)
	return 0;
    if (!call_other(this_player(), "drink_alcohol", 4))
	return 1;
    full = 0;
    write("You feal much better.\n");
    say(call_other(this_player(), "query_name", 0) +
        " belches after drinking the Super Big Gulp.\n");
    call_other(this_player(), "heal_self", 50);
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
