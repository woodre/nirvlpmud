inherit "obj/clean";
int counter;
id(str) { return str == "cocaine"; }

reset() {
   counter=10;
}

long() { write("A little transparent plastic packet containing "+counter+" gram(s) of cocaine , you could\n" +
   "sniff it.\n"); }
short() { return counter+" gram(s) of cocaine"; }

init() {
   add_action("sniff", "sniff");
    return 1;
}


sniff(arg) {
    if (arg!="cocaine") {  return 0; }
    say(call_other(this_player(),"query_name") + " sniffs a 1 gram strip of cocaine and jumps nervously.\n");
    write("You sniff a strip of cocaine.\n");
    call_other(this_player(),"heal_self",1000);
    write("You feel a ferocious wave of energy pumping all over your body making you feel\n"+
      "TOUGH AND ANGRY!!!\n");
    counter--;
    if(!counter)
        destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}
