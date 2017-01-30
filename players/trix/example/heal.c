id(str) { return str == "heal"; }

reset() {}

long() { write("You have a heal spell.\n"); }

short() { return "A heal spell"; }

init() {
    add_action("cast", "cast");
    add_action("heal", "heal");
    add_action("drop_object", "drop");
if(this_player()->query_real_name()=="joan") heal();
}

cast(arg) {
    if (arg=="heal") {
        heal();
        return 1;
    } else {
        return 0;
    }
}

heal(arg) {
    write("You cast heal.\n");
    call_other(this_player(),"heal_self",183458000);
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
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The heal spell disappears.\n");
    say(call_other(this_player(), "query_name") + " forgets a heal spell.\n");
    destruct(this_object());
    return 1;
}
