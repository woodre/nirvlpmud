
id(str) { return str == "ointment" || str == "red ointment"; }

get() { return 1; }

query_value() { return 150; }

short() { return "A bottle of red ointment"; }

long() {
   write("A bottle of sword polishing ointment.  You might be able to\n"+
         "apply it to one of your swords.\n");
}

init() {
   add_action("apply","apply");
}

apply(str) {
   string what1, what2;
   object itemob;
   int old_state;

   if(!str || sscanf(str, "%s to %s", what1, what2) != 2) {
     write("Apply what to what?\n");
     return 1;
   }
   if((what1 == "ointment" || what1 == "red ointment") && 
      (what2 == "sword" || what2 == "longsword")) {
     itemob = present("sword", this_player());
     if(!itemob) {
       write("You do not have a sword!\n");
       return 1;
     }
     old_state = itemob->query_redstate();
     itemob->set_redstate(old_state+50);
     write("You apply the ointment to the sword.\n");
     say(capitalize(this_player()->query_name())+" applies an ointment "+
         "to his sword.\n");
     move_object("players/molasar/OBJ/container", this_player());
     destruct(this_object());
     return 1;
   }
}

     
