/*                                                                    *
*    File:             /players/angel/tools/belt.c                   *
*    Function:         room                                          *
*    Author(s):        Angel@Nirvana                                 *
*    Copyright:        Copyright (c) 2007                            *
*                              All Rights Reserved.                  *
*    Source:           07/25/07                                      *
*    Notes:                                                          *
*                     With Earwax's guidance                         *
*                                                                    *
*    Change History:                                                 *
*/

#include "/sys/lib.h"

#include <ansi.h>

inherit "obj/treasure.c";

string coins_held;
/* Changed to string -- Rumplemintz
int coins_held;
*/

reset(arg)
{
   ::reset(arg);
   if(arg) return;
   set_name("belt");
   set_alias("bag");
   set_long(
      " This is a Money belt pack to store extra money so it doesn't\n"+
      "get lost.  This is a small fabric pouch secured with a zipper\n"+
      "and worn at the waist by a strap around the hips.  Belt packs\n"+
      "are used by travelers to secure their money.\n");
   set_weight(0);
   set_value(0);
   set_no_clean(0);
}

short()
{
   if (this_player() != environment(this_object())
         && (int)this_player()->query_level() < 21) 
   return "";
   return HIB+"Money Belt "+NORM+"("+YEL+coins_held+NORM+" coins stashed) (worn)";
}

drop() { return 1; }

string query_auto_load()
{
   return "/players/angel/rewards/belt.c:"+coins_held;
}

void init_arg(string str)
{
   coins_held = str;
}
/* Changed init_arg to use string
* -- Rumplemintz
void init_arg(mixed x)
{
   int i;
   if (!x) return;
   sscanf(x+"", "%d%s", i, x);
   coins_held = i;
}
*/

init(){
   ::init();
   add_action("stash","stash");
   add_action("unstash","unstash");
}

stash(str)
{
   write("You have placed coins in your belt.\n");
   return 1;
}
unstash(str)
{
   write("You have withdrawn coins from your belt.\n");
   return 1;
}
