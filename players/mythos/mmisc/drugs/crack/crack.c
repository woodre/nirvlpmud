id(str) { return str == "crack"; }

reset() {}

long() { write("A gram of free-base: crack- you may 'smoke' this.\n"); }
   
short() { return "A gram of crack"; }

get() { return 1; }

query_weight() { return 1; }

query_value() { return 0; }

drop() {
    return 0;
}


init() {
    add_action("smoke", "smoke");
}


smoke(str) {
    if (str!="crack") {  return 0; }
    say(call_other(this_player(),"query_name") + " sniffs a 1 gram strip of cocaine and jumps nervously.\n");
    write("You sniff a strip of cocaine.\n");
    call_other(this_player(),"heal_self",1000);
    write("You feel a ferocious wave of energy pumping all over your body making you feel\n"+
      "TOUGH AND ANGRY!!!\n");
    move_object(clone_object("/players/mythos/mmisc/drug/crack/sterm.c"),this_player());
    
    destruct(this_object());
    return 1;
}
