id(str) { return str == "acid"; }

reset() {}

long() { write("A strange black pill on which is drawn a little dragon, try to swallow it.\n"); }

short() { return "An acid"; }

init() {
    add_action("swallow","swallow");
    return 1;
}


swallow(arg) {
    if (arg!="acid") {  return 0; }
    say(call_other(this_player(),"query_name") + " swallows a dragon and stares at everyone with vacuous eyes.\n");
    write("You swallow an acid.\n");
    write("You feel a bomb exploding in your brain , you've been acid-bombed.\n");
    destruct(this_object());
    return 1;
}
 
get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}
