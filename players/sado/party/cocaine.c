id(str) { return str == "cocaine"; }

reset() {}

long() { write("A little transparent plastic packet containing 1 gram of cocaine , you could\n" +
   "sniff it.\n"); }
short() { return "1 gram of cocaine"; }

init() {
    add_action("sniff","sniff");
    return 1;
}


sniff(arg) {
    if (arg!="cocaine") {  return 0; }
    say(call_other(this_player(),"query_name") + " sniffs a 1 gram strip of cocaine and jumps nervously.\n");
    write("You sniff a strip of cocaine.\n");
    write("You feel a ferocious wave of energy pumping all over your body making you feel\n"+
      "TOUGH AND ANGRY!!!\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}
