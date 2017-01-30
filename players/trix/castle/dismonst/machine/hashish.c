id(str) { return str == "joint"; }

reset() {}

long() { write("This is big conic cigarette. It smells strange , try to smoke it.\n"); }

short() { return "A joint of hashish"; }

init() {
   add_action("smoke", "smoke");
    return 1;
}


smoke(arg) {
    if (arg!="joint") {  return 0; }
    say(call_other(this_player(),"query_name") + " smokes a joint of hashish and starts laughing.\n");
    write("You smoke a joint of hashish.\n");
    call_other(this_player(),"heal_self",20);
    write("You feel better , everything's happier , you fall down laughing.\n");
    destruct(this_object());
    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}
