/*                                                                   
 *    File:             /players/jareel/general_stuff/alc_shop_sign.c                                     
 *    Author(s):        Jareel                               
 *    Change History:   Switched desc of items, they did not match item descs   
 *                      Angel 07-18-09
 */

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
  "   1. Elixir of Vitality..............  ........6000\n"+
  "   2. Elixir of Vitality[HIGH TOX]..............4000\n"+
  "   3. Elixir of Vitality[LOW TOX]...............10000\n"+
  "   4. Elixir of Health..........................6000\n"+
  "   5. Elixir of Health [HIGH TOX]...............4000\n"+
  "   6. Elixir of Health [LOW TOX]................10000\n"+
  "   7. Elixir of Power...........................6000\n"+
  "   8. Elixir of Power [HIGH TOX]................4000\n"+
  "   9. Elixir of Power [LOW TOX].................10000\n"+
  "________________________________________________________\n"+
  "   You may 'buy #'\n"+
  "\n");
}
get() { return 0; }