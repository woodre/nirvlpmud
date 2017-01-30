#include "defs.h"

status main(string str, int guild_rank) {
  string who;

/* Bolts feels we shouldn't have this being portable */
  notify_fail("This power has been disabled for reasons of legality.\n-Earwax\n");
  return 0;

/*
     if(guild_rank < 8) {
       write("You must have a guild ranking of 8 to use this command.\n");
       return 1;
     }
     if(!str || sscanf(str, "%s", who) != 1) {
       write("Usage:  spy <player>\n");
       return 1;
     }
     if((int)this_player()->query_spell_point() < 10) {
       write("You are too low on power.\n");
       return 1;
     }
     if(!find_player(who)) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if((int)find_player(who)->query_invis() > 0) {
       write(capitalize(who)+" is not on.\n");
       return 1;
     }
     if((int)find_player(who)->query_level() > 20) {
       write("You cannot spy on wizards.\n");
       return 1;
     }
     call_other(this_player(), "add_spell_point", -SPY_COST);
     write(capitalize(who)+"'s location:\n");
     write(call_other(find_player(who), "look")+"\n");
     return 1;
*/
}
