int injected;

id(str) { return str == "virus"; }

short() { return "A virus"; }

long() { write("It is quite lethal.\n"); }

init() {
    add_action("inject", "inject");
    add_action("drop_object", "drop");
}

query_name() { return "lethal virus"; }


drop_object(str)
{
    if (injected || !str || !id(str)) return 0;
    write("The virus disappears.\n");
    return 1;
}

inject(str) {
    object ob, player;

    if (!str || injected) return 0;
    player = find_player(str);
    if (!player)
        return 0;
    injected = 1;
    move_object(this_object(), player);
    tell_object(player, "You are suddenly feeling very ill.\n");
    call_out("kill_player", 10, player);
    return 1;
}

kill_player(player)
{
    object ob;

    ob = this_player();
    set_this_player(player);
    call_other(player,"reduce_hit_point", call_other(player,"query_hp") - 1);
    call_other(player, "hit_player", 10000);
    set_this_player(ob);
}

