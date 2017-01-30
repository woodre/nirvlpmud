int full;

id(str) {
    if (str == "beer" && full)
        return 1;
    return str == "bottle";
}

short() {
    if (full)
        return "Frosted Mug of Beer";
    return "empty bottle";
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
    if (str && str != "beer" && str != "from bottle")
        return 0;
    if (!full)
        return 0;
    if (!call_other(this_player(), "drink_alcohol", 2))
        return 1;
    full = 0;
    write("It is really good beer!\n");
    say(call_other(this_player(), "query_name", 0) +
        " drinks a bottle of beer.\n");
    destruct_object(this_object());
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
