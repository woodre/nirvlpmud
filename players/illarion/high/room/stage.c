#pragma strict_types
inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
object ob;
  if(!present("guitarist")) {
    ob=clone_object(HMON+"musician");
    ob->set_name("guitarist");
    ob->set_short("A scrawny guitarist");
    ob->set_long(
"Although slightly scruffy-looking, this musician apparently knows what\n"+
"to do with a guitar.  The rest of the band seems to depend on this\n"+
"member for leadership in starting songs.\n");
    move_object(ob,this_object());
  }
  if(!present("bassist",this_object())) {
    ob=clone_object(HMON+"musician");
    ob->set_name("bassist");
    ob->set_short("A pudgy bassist");
    ob->set_long(
"Although obviously built for sitting down, this musician is good backup\n"+
"for the guitarist's playing, and seems well in tune with the bond any\n"+
"good band must have to play well.\n");
    move_object(ob,this_object());
  }
  if(!present("drummer",this_object())) {
    ob=clone_object(HMON+"musician");
    ob->set_name("drummer");
    ob->set_short("A bald drummer");
    ob->set_long(
"Although good with drumsticks, the drummer seems to be the misfit of the\n"+
"band, occasionally getting slightly out of sync, and forcing the rest\n"+
"of the band to adjust, all the while apparently oblivious.\n");
    move_object(ob,this_object());
  }
  if(!present("singer",this_object())) {
    ob=clone_object(HMON+"musician");
    ob->set_name("singer");
    ob->set_short("A young singer");
    ob->set_long(
"This young and obviously inexperienced member of the band has a nice, if\n"+
"somewhat untrained voice, and also a slight problem with confidence,\n"+
"looking to the guitarist for direction.\n");
    move_object(ob,this_object());
  }
  if(arg) return;
  
  set_light(1);
  set_short("A small stage");
  set_long(
"This small stage is crammed into a corner of Joe's Bar, with just barely\n"+
"enough room for three or four people and their instruments.  A slightly\n"+
"brighter light than the rest of the room gives any musicians enough light\n"+
"to play by.  The only exit is back to the main floor.\n");
  add_item("corner","Small and cramped, but some bands like that.");
  add_item("light","An overhead light hanging from the gloom of the ceiling.");
  add_item("room","The main room of the bar only holds a few tables.");
  add_item("floor","The main area of the bar.");
  
  add_exit("south",HROOM+"bar");
}
