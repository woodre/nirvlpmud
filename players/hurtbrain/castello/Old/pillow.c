id(str) { return str == "pill"; }

reset() {}

long() { write("This is a futuristic pill. Eat it to heal.\n"); }

short() { return "A strange looking pill"; }

init() {
    add_action("heal","eat");
}

heal(arg) {
        if (arg != "pill"){
                notify_fail("What do you want to eat?\n");
                return 0;
                }
    say(call_other(this_player(),"query_name") + " eats a pill.\n");
    write("You eat the pill. You feel Superman now!\n");
    call_other(this_player(),"heal_self",350);
    destruct(this_object());
    return 1;
}
get() { return 1; }

drop() { return 0; }
query_weight() { return 0; }

query_value() { return 5000; }
