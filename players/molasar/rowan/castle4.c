
/*
 * CASTLE ROOM 4
 */

#define OWNER "beez"

reset(arg) {
   if(!arg)
     set_light(1);
   "/players/sandman/paladin/castles/master"->get_castle(OWNER);
}

short() { return "Castle grounds of "+capitalize(OWNER); }

long() {
   object castle;
   
   castle = present("castle");
   write("You have entered the castle grounds of "+capitalize(OWNER)+".\n"); 
   if(castle && castle->query_grounds_desc())
     write(castle->query_grounds_desc());
   write("   There is one obvious exit:  northwest\n");
}

init() {
   add_action("northwest","northwest");
}

northwest() {
   this_player()->move_player("northwest#players/molasar/rowan/clearing");
   return 1;
}

