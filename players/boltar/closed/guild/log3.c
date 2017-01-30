#include "/obj/user/shout_only.c"
#include "/obj/clean.c"
short() { return "A log";
  }
id(str){
   return str == "log";
   }
get() { 
  write("It's big, It's heavy, It's wood!\n");
  return 0;
  }
weight() { return 10000; }
long(){
  write("It's log, It's Log....\n"+
  "It rolls down stairs, alone or in pairs\n"+
  "or over your neighbor's dog.\n"+
  "Its great for a snack, it fits on your back,\n"+
  "It's log, log, log.\n"+
  "It's log, It's log\n"+
  "It's Big, It's Heavy, It's Wood.\n"+
  "It's Better than Bad, ITS GOOD!\n"+
  "\n It's Log..... from Blammo!\n");
write("\n\nTo use type 'roll playername'\n");
/* Added by: OMEGA  Reason: Goes with the spell point modification below.
 */
   write("(costs 20 spell points per roll.)\n");
/* End segment by OMEGA */
 return 1;
 }
init()
 {
    add_action("roll","roll");
}
roll(str) {
   object who;
/* Edited by: OMEGA   Reason: To prevent abusive players who roll the log 10
 * or twenty times at each other (charges 20 spell points per roll.)
 * e.g. Tyro and Flaw had a 'log war'.
 */
  if(this_player()->query_spell_point() < 20) {
      write("It costs 20 spell points per 'roll', which you don't have.\n");
      return 1;
   }
   this_player()->add_spell_point(-20);
/* End segment by OMEGA */
   who=find_player(str);
  if(!who) {
   write("There is no player "+str+" in the area.\n");
   return 1;
   }
  if(who->query_level() > 20) {
  write("You can't roll logs at wizards.\n");
   return 1;
   }
   chan_msg("You hear the rumbling of a log rolling.\n");
    chan_msg("It rolls down stairs, alone or in pairs, and runs over "+str+"\n");
   tell_object(who, "A log rolls over you! OUCH!\n");
   move_object(this_object(),environment(who));
   return 1;
}
