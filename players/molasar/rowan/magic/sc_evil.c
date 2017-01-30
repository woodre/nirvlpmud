
/*
 * SCROLL OF PROTECTION FROM EVIL (3/19/94)
 */

reset(arg) {
   if(arg)
     return;
}

id(str) { return str == "scroll"; }

init() { 
   add_action("protection","protection");
}

short() { return "A scroll of protection from evil"; }

get() { return 1; }

long() {
   write("This scroll will give you added protection from evil monsters.\n");
   write("Usage: protection from evil\n");
}

protection(str) {
   object shadow;
   
   if(!str || str != "from evil")
     return;
   if(this_player()->query_protected()) {
     write("You are already under a protection spell!\n");
     return 1;
   }
   write("Your are now protected from evil.\n");
   tell_room(environment(this_player()),
       capitalize(this_player()->query_name())+" recites a scroll.\n");
   shadow = clone_object("players/molasar/rowan/magic/obj/pr_shad");
   shadow->start_protection_from(this_player(),"evil");
   destruct(this_object());
   return 1;
}

