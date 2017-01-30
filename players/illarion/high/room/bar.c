#pragma strict_types
inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  object ob;
  int x;
  for(x=1;x<=4;x++)
    if(!present("patron "+x,this_object())) {
      ob=clone_object("obj/monster");
      call_other(HMON+"patron_gen","patron_generator",ob);
      move_object(ob,this_object());
    }
  if(arg) return;
  
  set_light(1);
  set_short("The main room of Joe's Bar");
  set_long(
"Dim, but sufficient lighting from overhead lamps falls across a number of "+
"small tables and chairs.  Everthing looks well-made, as if to deny the "+
"simplicity of the place, such as the unfinished walls.  To the south, "+
"a doorway leads back to the coatroom, to the north is a small wooden "+
"stage, and to the east is the bar itself.\n");
  add_item("lamps","Hanging down from the gloom above them, the lamps shine\n"+
                   "all of their light down toward the tables.");
  add_item("tables","The tables are solid and clean, but not fancy.  A few\n"+
                    "of them are set.");
  add_item("chairs","They're set around the tables for people to sit on.");
  add_item("walls","The walls show bare support beams, but are clean.");
  add_item("coatroom","A small room for keeping coats.");
  add_item("stage","A place for small live bands, possibly the reason for\n"+
                   "the bar's prosperity.");
  add_item("bar","A long wooden table drinks are served over.  This one is\n"+
                 "made of varnished wood and has a few stools in front of it.");
  
  add_exit("south",HROOM+"barcoat");
  add_exit("north",HROOM+"stage");
  add_exit("east",HROOM+"atbar");
}
