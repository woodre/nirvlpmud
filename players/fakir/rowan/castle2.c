
/*
 * CASTLE ROOM 2
 */

#define OWNER "traff"

reset(arg) {
   if(!arg)
     set_light(1);
}

short() { return "Castle grounds of "+capitalize(OWNER); }

long() {
   object castle;
   
   castle = present("castle");
   write("You have entered the castle grounds of "+capitalize(OWNER)+".\n"); 
   if(castle && castle->query_grounds_desc())
     write(castle->query_grounds_desc());
   write("   There is one obvious exit:  north\n");
}

init() {
   add_action("north","north");
}

north() {
   this_player()->move_player("north#players/molasar/rowan/clearing");
   return 1;
}

