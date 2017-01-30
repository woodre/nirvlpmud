inherit "/players/fred/closed/std/room";
#include <ansi.h>
#include "/players/fred/defines.h"
int grr;

reset(int arg)
{
   if(arg) return;
   set_light(0);
   set_short(BOLD+MAG+"Insane Asylum"+NORM);
   set_long(
      "  Before you is a high stone wall that blocks you from continuing\n"+
      "along the path.  Embedded in the wall is a heavy iron gate with a\n"+
      "a sign hanging loosely from it.  Through the thick iron bars of the\n"+
      "gate you can see a large building that has been abandoned for decades.\n"+
      "    There are two obvious exits: north and south\n");
   add_item("wall","A ten foot high wall made from large rocks and concrete");
   add_item("stone wall","A ten foot high wall made from large rocks and concrete");
   add_item("rocks","Large rocks placed meticulously to form a wall");
   add_item("concrete","A gray colored mixture that holds the rocks in place");
   add_item("gate","A large iron gate that has been closed for years");
   add_item("bars","Thick iron bars that helped keep people in and out");
   add_item("path","A small muddy path that leads up to the Asylum");
   add_item("building","A large run down building that used to be an Insane Asylum");
   add_item("sign",""+BOLD+"Fred's Insane Asylum"+NORM);
   set_chance(5);
   add_msg("A roll of thunder echoes in the distance...\n");
   add_msg("Lighting flashes across the sky...\n");
   add_msg("Raindrops fall softly on your head.\n");
   add_msg("A gust of wind whistles through the tall grass.\n");
   grr = 0;
}

init(){
  ::init();
   add_action("flop","open");
   add_action("polf","north");
   add_action("crap","south");
  }

flop(str){
  if(!str){ write("Open what?\n"); return 1; }
  if(str == "gate"){
    write("You lean your weight against the gate and it slowly pushes open.\n");
    say(TPN+" pushes slowly pushes the gate open.\n");
    grr = 1;
    return 1; 
  }
}

polf(){
 if(grr < 1){ write("The heavy iron gate blocks your path.  Perhaps you could open it.\n");
   return 1;}
 else{
   TP->move_player("north#players/fred/asylum/rooms/r2.c");
   return 1;
 }
}

crap(){
  TP->move_player("south#/players/fred/workroom.c"); return 1; }

