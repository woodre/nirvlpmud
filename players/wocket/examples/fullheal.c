id(str) {
  return str=="heal" || str=="potion";
}

reset() {}

long() { write("The bottle seems to be filled with a shining bright liquid.\n"); }

short() { return "A potion of full healing"; }

init() {
    add_action("cast","cast");
    add_action("cast","drink");
    add_action("heal","heal");
    add_action("drop_object","drop");
}

cast(arg) {
    if (arg=="heal"||arg=="potion") {
        heal();
        return 1;
    } else {
        return 0;

    }
}

heal(arg) {
    say(call_other(this_player(),"query_name") + " drinks a potion.\n");
    write("You drink the potion and feel whole.\n");
    call_other(this_player(),"heal_self",400);
    write("The heal is used up.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 5000; }

drop_object(str) {
    if (str == "all") {
        drop_object("heal");
        return 0;    }
    if (!str || !id(str))
        return 0;
    write("The bottle shatters.\n");
    say(call_other(this_player(), "query_name") + " shatters a potion on the ground as he drops it\n");
    destruct(this_object());
    return 1;
}
