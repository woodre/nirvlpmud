#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
  if(arg) return;
  no_clean = 1;
  set_short("A wooden sign");
  set_alias("sign");
  set_long("This sign has the heal prices on it, you could read it to mull it over.\n");
  set_read( 
  "You look over the stores inventory....\n\n"+
  "________________________________________________________  \n"+
  "*************    "+HIY+"The Healing Salve"+NORM+"    **************\n"+
  "________________________________________________________  \n"+
  "      Item:                                     Cost:\n"+
  "   1. Potent berries............................2400\n"+
  "   2. Potent potion.............................2400\n"+
  "   3. Berries...................................1600\n"+
  "   4. Potion....................................1600\n"+
  "   5. Hybrid berries............................1200\n"+
  "   6. Diluted potion............................1200\n"+
  "________________________________________________________\n"+
  "   You may 'buy #'\n"+
  "\n");
}
get() { return 0; }
