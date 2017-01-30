
string who;



string long_desc;
string player;
object ob, dest;
int len;


set_who(str) {
       who = str;
}


id(str) {
    return (str == "statue");
}


init() {
    if(call_other(this_player(), "query_real_name") == who) {
#ifndef __LDMUD__
    add_action("no"), add_xverb("");
#else
    add_action("no", "", 3);
#endif
    }
}

no() {
    write("How can you do that as a statue.\n");
    return 1;
    }


done() {
    move_object(first_inventory(this_object()),environment(this_object()));
    say("The statue crumbles to dust.\n");
    destruct(this_object());
    return 1;
}
get() {
   return 0;
}

drop() {
   destruct(this_object());
}

