
/*
 * Master object for retrieving castles 
 */

#define RPATH "players/sandman/paladin/castles/"

get_castle(who) {
   object castle;
   
   if(!restore_object(RPATH+who))
     return 1;
   if(!present("castle", previous_object())) {
     castle = clone_object("players/sandman/paladin/castles/castle");
     castle->set_owner(who);
     castle->reset();
     move_object(castle, previous_object());
   }
   return 1;
}

