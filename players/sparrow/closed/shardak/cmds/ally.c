/*
 * ALLY command for senior servants and up
 * Balowski@Nirvana, Sept' 95
 * Fixed by verte to reflect power rangers + healers
 * also added log
*/
#include <security.h>
#include "../std.h"
#include "../def.h"
#include "../people.h"
inherit CMD;

status
main(string arg)
{
   object who, aob, *list;
   string gname;

   if (previous_object()->GuildClass() < C_SENIOR)
      return 0;

   if (!arg || !(who = find_player(arg)) ||
   (who->query_invis() && (who->query_level() >= APPRENTICE))) {
      notify_fail("Make who an ally?\n");
      return 0;
   }
   if (who->query_level() >= APPRENTICE) {
      write("Wizards cannot be made allies.\n");
      return 1;
   }

   gname = (string) who->query_guild_name();
   if (gname == GUILDNAME) {
      write("Your fellow guild members are already your allies.\n");
      return 1;
   }
   if (present("allymark", who)) {
      write("That person is already an ally.\n");
      return 1;
   }
   if(!gname) gname = "";
   gname = lower_case(gname);
   if (gname == "knights templar" || gname == "healer" ||
       gname == "ranger" || present("honor_ranger_communicator", who)) {
      write("You hear Shardak's voice, \
\"Do not offend me. That is an enemy.\"\n");
      return 1;
   }
   if(present("ally_ask_ob", who))
   {
     write("You are currently asking "+capitalize(arg)+".\n");
     return 1; 
   }
   write("Asking "+capitalize(arg)+" ... time out in 60 seconds.\n");
   tell_object(who,
     "  " + (string)this_player()->query_name() + " has requested you to join \
ranks as an Ally of the Servants of Shardak.\n\
Type 'y' if you wish to become brethren with the darkest of forces.\n\
>>");
   aob=clone_object(OBJDIR+"ally_ask");
   move_object(aob, who);
   aob->ask(this_player()->query_real_name());
   return 1;
}

