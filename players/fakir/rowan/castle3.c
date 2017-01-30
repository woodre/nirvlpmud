
/*
 * CASTLE ROOM 3
 */

#define OWNER "tristian"

reset(arg) {
   if(!arg)
     set_light(1);
   "/players/sandman/paladin/castles/master"->get_castle(OWNER);
}

short() { return "Castle grounds of "+capitalize(OWNER); }

long(str) {
   object castle;
   
   castle = present("castle");
   write("You have entered the castle grounds of "+capitalize(OWNER)+".\n"); 
   if(castle && castle->query_grounds_desc())
     write(castle->query_grounds_desc());
   write("   There is one obvious exit:  east\n");
}

init() {
   add_action("east","east");
}

east() {
   this_player()->move_player("east#players/molasar/rowan/clearing");
   return 1;
}

