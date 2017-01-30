id(str) { return str == "potion"; }

reset() {}

long() { write("This is a potion of healing. Type 'quaff potion' to use it.\n"); }

short() { return "A Roman's potion"; }

init() {
    add_action("heal","quaff");
}

heal(arg) {
        if (arg != "potion"){
                notify_fail("What do you want to quaff?\n");
                return 0;
                }
    say(call_other(this_player(),"query_name") + " quaffs a Roman's potion.\n");
    write("You quaff the potion.\n");
    call_other(this_player(),"heal_self",15);
    destruct(this_object());
    return 1;
}

query_weight() { return 0; }

query_value() { return 450; }
get() { return 1; }

drop() { return 0; }
