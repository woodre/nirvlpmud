#include "../scar.h"
#include <ansi.h>

main(string str) {
   string pre;

   if (!str) {
      notify_fail("Tell what to blood brothers?\n");
      return 0;
   }
  pre = CYN+"<<"+RED+CHANNAME+CYN+">> ";
  if( str[0] == ':' )
    pre += NORM;
  else
    pre += NORM+ capitalize((string) this_player()->query_real_name()) +" ";

  CHANNELD->channel_message( CHANNAME, str, pre );
  /*CHANNELD->broadcast(msg, 0, "Blood");
   "/obj/user/chistory"->add_history("BloodScar", "<<Blood>> " + msg); */
   return 1;
}
