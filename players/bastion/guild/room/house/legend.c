
inherit "/room/room.c";

int locked;
string *new_long_desc;

reset ( int arg ) {
   if ( arg ) return;
    restore_object("players/bastion/guild/room/house/legend");
   if ( !new_long_desc ) 
      long_desc = "You are in a bare room with white walls.\n";
   else
      long_desc = implode(new_long_desc, "\n") + "\n";
   if ( !short_desc ) 
      short_desc = "Legend's bedroom";
   dest_dir = ({ "/players/bastion/guild/room/house/bastion", "east",
                 "/players/bastion/guild/room/house/sitting", "south", });
}

void init () {
   ::init();
   if ( locked && (string)this_player()->query_real_name() != "bastion" ) {
      write("The room is locked at the moment.\n");
      move_object(this_player(), "/room/church");
      return;
   }
   add_action("set_long", "edit");
   add_action("lock_room", "lock");
   add_action("lock_room", "unlock");
   say(this_player()->query_name() + " enters the room.\n");
}

int set_long () {
   string who;
   who = (string)this_player()->query_real_name();
   write("WHO: " + who + "\n");
   if ( who != "bastion" && who != "legend" ) {
      return 0;
   }
   write("Editing long description of your room.\n");
   write("Type \".\" on a blank line to exit and save.\n");
   new_long_desc = ({ });
   write(">>*\b");
   input_to("loop");
   return 1;
}

void loop ( string str ) {
   if ( str == "." ) {
      save_object("players/bastion/guild/room/house/legend");
      long_desc = implode(new_long_desc, "\n") + "\n";
      write("Long description saved.\n");
      return;
   }
   new_long_desc = new_long_desc + ({ str });
   write(">>*\b");
   input_to("loop");
}

int lock_room ( string arg ) {
   string who;
   if ( !arg || arg != "room" ) {
      notify_fail("Lock what?\n");
      return 0;
   }
   who = (string)this_player()->query_real_name();
   if ( who != "legend" && who != "bastion" ) {
      notify_fail("You don't have a key.\n");
      return 0;
   }
   if ( query_verb() == "unlock" ) locked = 0;
   else locked = 1;
   write("The room is now " + (locked ? "locked" : "unlocked") + ".\n");
   return 1;
}
