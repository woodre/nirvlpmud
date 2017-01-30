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
   else {
    string em, arg, file;
    
    if(sscanf(str, "%s %s", em, arg) != 2) {
      em = str;
    }
    em = implode(explode(em, "."), "");
    if(file_size(file="/bin/soul/_"+em+".c") > 0) {
      return (int)file->guildcast("shardak", arg);
    }
  }
   
   msg = capitalize((string) this_player()->query_real_name()) +" " + str + "\n";
   msg = (string)COLOURD->c_decode(msg);
   CHANNELD->broadcast(msg, 1, "{Servants}");
   return 1;
}
