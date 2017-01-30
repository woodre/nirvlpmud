#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_short("A dark catacomb");
   set_long(
      "     Darkness seems to wrap itself around you in this short tunnel.\n"+
      "A thin rope ladder appears to lead to the surface above you.\n"+
      "Some crumbling rock seems to have fallen on the ground beneath you,\n"+
      "chipped away from the rock walls over time.\n");
   add_item(({"ladder","rope ladder"}),
      "This thinly bunched rope ladder scales its way up the wall to a\n"+
      "small glimpse of light.\n");
   add_item("rock","Crumbling bits of rock have fallen from the walls");
   add_item(({"rock walls","walls"}),
      "Thick rock walls hewn from granite line the sides of this short,\n"+
      "dank tunnel");
   add_exit(VILLAGE+"path6","up"); 
   add_exit(VILLAGE+"tun2","south"); }

init()
{
   ::init();
   if(TP && TPRN == "overkill" &&
      present("DarkRangerCommunicator",TP))
     present("DarkRangerCommunicator",TP)->restore_ranger();
}
