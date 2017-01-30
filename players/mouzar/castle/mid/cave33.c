#include "/players/feldegast/closed/ansi.h"
 
inherit"/room/room";
int i;
int found;
reset(arg) {
monster();
if(!arg) {
 
           set_light(1);
short_desc = "A dark cave";
long_desc = "This cave leads deeper in to the mountain.  It is hard to see\n" +
           "where you are going cause the only light source is from the\n" +
           "glowing fungus on the walls.  You are suddenly attacked by flying\n" +
           "snakes.  You can see some nests in the upper corners of the walls\n" +
             "of the room.  They are not happy that you have entered the room.\n" +
                 "They seem to be protecting some sort of nest.\n";
          
dest_dir = ({
           "/players/mouzar/castle/mid/cave31","northwest",
                      });
           }
       }
 
 
 
monster() {
int count;
object creature;
 
if(!present("snake")) {
while (i<9) {
    creature = clone_object("/players/mouzar/castle/monsters/fsnake.c");
    move_object(creature, this_object());
 i++;
 }
 i=0;
 }
 }
 

init() {
  ::init();
  add_action("cmd_search", "search");
}

cmd_search(str) {
  object gem;
  if(str!="nest") {
    notify_fail("Search what?\n");
    return 0;
  }
  if(found) {
    write("There is nothing there.\n");
    return 1;
  }
  if(present("snake")) {
    write("A snake blocks your way.\n");
    return 1;
  }
  gem=clone_object("/obj/treasure.c");
  gem->set_id("ruby");
  gem->set_short(RED+"Ruby"+NORM);
  gem->set_long("A precious red ruby.\n");
  gem->set_weight(1);
  gem->set_value(600);
  move_object(gem,this_object());
  gem=clone_object("/obj/treasure.c");
  gem->set_id("emerald");
  gem->set_short(GRN+"Emerald"+NORM);
  gem->set_long("A precious green emerald.\n");
  gem->set_weight(1);
  gem->set_value(450);
  move_object(gem,this_object());
  gem=clone_object("/obj/treasure.c");
  gem->set_id("opal");
  gem->set_short(YEL+"Opal"+NORM);
  gem->set_long("A pretty jewel.\n");
  gem->set_weight(1);
  gem->set_value(300);
  move_object(gem,this_object());
  write("You find a handful of gems in the fire snake nest.\n");
  say(this_player()->query_name()+" searches the flying snake nest.\n");
  found = 1;
  return 1;
}
