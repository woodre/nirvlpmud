
/*
 * AMULET OF TELEPORTING (3/19/94)
 * Can set destination to teleport to.
 * AC 1  TYPE amulet  
 */

#define TELL(x) tell_room(environment(this_player()), x)

inherit "obj/armor";

reset(arg) {
   if(arg)
     return;
   set_name("amulet");
   set_short("An amulet of teleporting");
   set_long("You may set a destination which you can teleport to.\n"+
            "COMMANDS: set_dest, teleport\n");
   set_value(500);
   set_type("amulet");
}

init() {
   add_action("set_dest","set_dest");
   add_action("teleport","teleport");
   ::init();
}

object where;

set_dest() {
   string junk1, junk2;

   if(!worn) {
     write("You must wear the amulet first.\n");
     return 1;
   }
   where = environment(this_player());
   if(where->realm() == "NT") {
     write("You cannot teleport to this room.\n");
     where = 0;
     return 1;
   }
   if(sscanf(file_name(where), "%sroom/%s", junk1, junk2) != 2) {
     write("You may only set destinations in the village area!\n");
     where = 0;
     return 1;
   }
   write("Destination set to: "+where->short()+"\n");
   return 1;
}

teleport() {
   if(!worn) {
     write("You must wear the amulet first.\n");
     return 1;
   }
   if(!where) {
     write("You have no destination set!\n");
     return 1;
   }
   if(environment(this_player())->realm() == "NT") {
     write("The amulet starts to glow, then darkens.\n");
     return 1;
   }
   TELL(this_player()->query_name()+" shimmers, then disappears.\n");
   move_object(this_player(), where);
   TELL(this_player()->query_name()+" appears from the folds of space.\n");
   this_player()->look();
   return 1;
}

