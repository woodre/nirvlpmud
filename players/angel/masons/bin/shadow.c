#include "defs.h"

status main(string str, int glevel) {
   
  write("Disabled - this is now the 'follow' command.\n-Earwax\n");
  return 1;
/*
   if(guild_rank < 3) {
      write("You must have a guild ranking of 3 to use this command.\n");
      return 1;
   }
   if(this_player()->query_spell_point() < 15) {
      write("You do not have enough spell points for this power.\n");
      return 1;
   }
   if(!str) {
      write("Usage: shadow <player name> or <off>.\n");
      return 1;
   }
   womble = present(str, environment(this_player()));
   if(!womble || str == "off" || !str) {
      write("You are not following anyone.\n");
      shadow = 0;
      return 1;
   }
   if(womble->query_level() >= 20) {
      write("You may not follow wizards.\n");
      return 1;
   }
   write("You are now following "+womble->query_name()+".\n");
   shadow = 1;
   this_player()->add_spell_point(-15);
   return 1;
*/
}
