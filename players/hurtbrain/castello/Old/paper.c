id(str) { return str == "paper"; }

reset() {}

long() { write("This is a parchment of healing. Read it if you want to heal\n");
 }

short() { return "A parchment paper"; }

init() {
    add_action("heal","read");
}

heal(arg) {
        if (arg != "paper"){
                notify_fail("What do you want to read?\n");
                return 0;
                }
    say(call_other(this_player(),"query_name") + " reads the paper.\n");
    write("You read the parchment.\n");
    call_other(this_player(),"heal_self",20);
    destruct(this_object());
    return 1;
}
get() { return 1; }

drop() { return 0; }

query_weight() { return 0; }

query_value() { return 600; }
