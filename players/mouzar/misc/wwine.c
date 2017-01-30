int full;

id(str) {
    if (str == "wine" && full)
        return 1;
    return str == "bottle";
}

short() {
    if (full)
        return "Glass of Red Wine";
    return "empty bottle";
}

long() {
    write("The wine glass if made of Crystal and has Mouzar & Brittany's\n"+
	  "Wedding printed on it.  The wine is red and is suited for a\n"+
	  "Queen to drink.\n");
}

reset(arg) {
    if (arg)
        return;
    full = 1;
}

drink(str)
{
    if (str && str != "beer" && str != "from bottle")
        return 0;
    if (!full)
        return 0;
    if (!call_other(this_player(), "drink_alcohol", 1))
        return 1;
    full = 0;
    write("It is very good wine!\n");
    say(call_other(this_player(), "query_name", 0) +
        " sips down a glass of wine.\n");
    destruct_object(this_object());
    write("The glass disappears when you are finished.\n");
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
