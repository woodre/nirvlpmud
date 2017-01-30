
/*
 * SCROLL OF PROTECTION FROM GOOD (3/19/94)
 */

reset(arg) {
   if(arg)
     return;
}

id(str) { return str == "scroll"; }

query_value() { return 500; }

init() { 
   add_action("protection","protection");
}

short() { return "A scroll of protection from good"; }

get() { return 1; }

long() {
   write("An eloquently written scroll on fine parchment.\n");
   write("This scroll will give you added protection from good monsters.\n");
   write("Usage: protection from good\n");
}

protection(str) {
   object shadow;
   
   if(!str || str != "from good")
     return;
   if(this_player()->query_protected()) {
     write("You are already under a protection spell!\n");
     return 1;
   }
   write("You are now protected from good.\n");
   tell_room(environment(this_player()),
       capitalize(this_player()->query_name())+" recites a scroll.\n");
   shadow = clone_object("players/molasar/rowan/magic/obj/pr_shad");
   shadow->start_protection_from(this_player(),"good");
   destruct(this_object());
   return 1;
}

