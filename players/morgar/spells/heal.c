/*
  I modified this heal because players were using the Spellbook to
generate up to 60 full heals.  Since no cap was put on the number
of times this spell could be memorized, I made it commesurate with
a level 14 monster.  -Eurale  8/28/97
*/

id(str) { return str == "heal"; }

reset() {}

long() { write("You have memorized a heal spell.\n"); }

short() { return "A memorized heal spell"; }

init() {
    add_action("cast","cast");
    add_action("heal","heal");
    add_action("drop_object","drop");
}

cast(arg) {
    if (arg=="heal") {
        heal();
        return 1;
    } else {
        return 0;
    }
}

heal(arg) {
    say(call_other(this_player(),"query_name") + " casts heal.\n");
    write("You cast heal.\n");
    call_other(this_player(),"heal_self",10);
    write("The memorized heal is used up.\n");
    destruct(this_object());
    return 1;
}

get() { return 1; }

query_weight() { return 0; }

query_value() { return 300; }

drop_object(str) {
    if (str == "all") {
        drop_object("heal");
        return 0;
    }
    if (!str || !id(str))
        return 0;
    write("The heal spell disappears.\n");
    say(call_other(this_player(), "query_name") + " forgets a heal spell.\n");
    destruct(this_object());
    return 1;
}
