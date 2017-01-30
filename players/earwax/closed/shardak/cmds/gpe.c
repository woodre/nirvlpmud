#include "../daemons.h"
#include "/players/vertebraker/ansi.h"

/*
* GE command for the Shardak guild
* free guild emote
* by Dragnar and Balowski
*/
#pragma strict_types
#include "../std.h"
#include "../def.h"
inherit CMD;

status
main(string str)
{
   string          msg;
   
   if (!str) {
      notify_fail("Guild emote what?\n");
      return 0;
   }
   if (previous_object()->Muffled()) {
      notify_fail("You are not listening to the Servants' channel.\n");
      return 0;
   }
   
   msg = capitalize((string) this_player()->query_real_name()) +" " + str + "\n";
   msg = (string)COLOURD->c_decode(msg);
   CHANNELD->broadcast(msg, 1, "{Servants}");
   return 1;
}
