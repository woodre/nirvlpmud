#include "../daemons.h"
#include "/players/vertebraker/ansi.h"

/*
* GT command for the Shardak guild
* free guild channel tell
* revamped by verte
*/
#pragma strict_types
#include "../std.h"
#include "../def.h"
inherit CMD;

status
main(string str)
{
   string          msg;
   string          history;
   if (!str) {
      notify_fail("Tell fellow guild members what?\n");
      return 0;
   }
   if (previous_object()->Muffled()) {
      notify_fail("You are not listening to the Servants' channel.\n");
      return 0;
   }
   if(str == "history" || str == "-h")
      {
      history = (string) "/obj/user/chistory"->query_history("{Servants}");
      write(history+"\n");
      return 1;
   }
   if(str[0..0] == ":") return command("gpe " + str[1..strlen(str)-1], this_player());
   msg = capitalize((string) this_player()->query_real_name()) +
   " speaks: " + str + "\n";
    msg = (string)COLOURD->c_decode(msg);
   CHANNELD->broadcast(msg, 1, "{Servants}");
   return 1;
}
