#include "ansi.h"
inherit "room/room";

int king;
reset(arg) {
   king = 0;
   
   if (arg) return;
   set_light(1);
   short_desc = HIC+"Kandy Castle"+NORM;
   items = ({
         "towers","Waffle cone towers loom overhead",
         "sprinkles","Small particles of rainbow colored candy",
         "chocolate","Dark, syrupy chocolate sauce",
         "peppermint","Hard red and white round candies",
         "peanut butter","Thick, creamy peanut buttery paste",
         "caramel","Light brown and gooey caramel drizzle",
         "cone","A light and sugary waffle cone",
         "waffle cone","Sugary, light brown waffle cones",
         "walls","Syrup steams and candy decorations adorn the walls",
         "castle","Waffle cones, candy, and syrup make up this tasty castle",
         "candy","Tasty candy treats adorn the castle walls"});
   
   long_desc = 
   "   Ice cream cone towers with sprinkles on top. Chocolate, peppermint,\n\
   peanut butter and caramel cover the outside of the waffle cone castle.\n\
   Every kind of candy imaginable can be found in and on this castle.  This\n\
   is the heart of Candy Land!  If you look close enough, you may be able to\n\
   find the King hidden here in his own castle!\n";
   dest_dir = ({"players/martha/area/rooms/bridge", "south"});
}

search_castle(str){
   if(king >=1){
      write("You search around, but it seems as though someone already found the King!\n");
      return 1; }
   
   if(str == "castle" || str == "land" || str == "towers" || str == "tower"){
      write("King Kandy appears before your eyes!\n");
      say(this_player()->query_name()+" has found King Kandy!\n");
      move_object(clone_object("/players/martha/area/mobs/kingk.c"), this_object());
      king +=1;
      return 1; }
   return 1;
}

init()
{
   ::init();
   add_action("search_castle", "search");
}
