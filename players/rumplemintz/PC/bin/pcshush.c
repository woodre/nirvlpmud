/* pcshush - Toggle the 'earmuffs' for the Player Channel */

#include <ansi.h>

int pcshush(string str){
   if(!str && str != "on" && str != "off"){
      notify_fail("Usage: pcshush <on|off>\n");
      return 0;
   }
   if(str=="on"){
      present("player_channel", this_player())->set_shush(1);
      write(HIW+"Player Channel has been shushed."+NORM+"\n");
      return 1;
   }
   if(str=="off"){
      present("player_channel", this_player())->set_shush(0);
      write(HIW+"Player Channel shush has been removed."+NORM+"\n");
      return 1;
   }
}
