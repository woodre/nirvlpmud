
/*
 * CASTLE ROOM 5
 */

#define OWNER "wtknight"

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
   write("   There is one obvious exit:  northeast\n");
}

init() {
   add_action("northeast","northeast");
}

northeast() {
   this_player()->move_player("northeast#players/molasar/rowan/clearing");
   return 1;
}

