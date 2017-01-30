#include "/players/jareel/define.h"
inherit "obj/treasure.c";

reset(arg)
{
if(arg) return;
no_clean = 1;
set_short("A wooden sign");
set_alias("sign");
set_long("A small sign depicting the types of wares the shop sells, maybe you could read it.\n");
set_read(
 "You look over the stores inventory....\n\n"+
  "________________________________________________________  \n"+
  "*************    "+HIY+"Ye Ole Smithy"+NORM+"    **************\n"+
  "________________________________________________________  \n"+
  "      Item:                                     Cost:\n"+
  "   1. Bastard Sword.............................9500\n"+
  "   2. Battle Axe................................9500\n"+
  "   3. Spear.....................................3000\n"+
  "   4. Maul......................................3000\n"+
  "   5. Dagger....................................600\n"+
  "   6. Short Sword...............................600\n"+
  "________________________________________________________\n"+
  "   You may 'buy #'\n"+
  "\n");
return 1;
}
get() { return 0; }
