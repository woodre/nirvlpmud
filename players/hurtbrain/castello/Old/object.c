id(str) { return str == "object"; }

reset() {}

long(){write("This is a strange looking object. Polish it and you'll heal!\n");}

short() { return "A red glowing object"; }

init() {
    add_action("heal","polish");
}

heal(arg) {
        if (arg != "object"){
                notify_fail("What do you want to polish?\n");
                return 0;
                }
    say(call_other(this_player(),"query_name") + " polishes an object.\n");
    write("You polish the object. It disappears.\n");
    call_other(this_player(),"heal_self",40);
    destruct(this_object());
    return 1;
}
get() { return 1; }

drop() { return 0; }
query_weight() { return 0; }

query_value() { return 1200; }
