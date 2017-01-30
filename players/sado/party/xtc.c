id(str) { return str == "xtc"; }

reset() {}

long() { write("A nice pink little pill , try to swallow it.\n"); }

short() { return "An xtc"; }

init() {
    add_action("swallow","swallow");
    return 1;
}


swallow(arg) {
    if (arg!="xtc") {  return 0; }
    say(call_other(this_player(),"query_name") + " swallows an ecstasy and flies around the room.\n");
    write("You swallow an ecstasy.\n");
    call_other(this_player(),"heal_self",40);
    write("You feel tougher and think you could dance all night long.\n");
    destruct(this_object());
    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}
