/*
* SeTRaNK for the Shardak guild (guild wizards and LAW only)
* Set the rank of a guild member
*/
#pragma strict_types
#include "../people.h"
#include "../def.h"
#include "../std.h"
#define WIZARD 20
inherit CMD;

status
main(string arg)
{
   string      who, msg;
   int         rank, prev;
   object      p;
   
   if ((int) this_player()->query_level() < 20 &&
         member_array(this_player()->query_real_name(), LAW) < 0)
   return 0;
   
   if (!arg || sscanf(arg, "%s %d", who, rank) != 2) {
      notify_fail("Usage: setrank <who> <number>\n");
      return 0;
   }
   if (rank < 0) {
      write("The new rank cannot be less than zero.\n");
      return 1;
   }
   if (rank > 8 && ((int) this_player()->query_level() < WIZARD)) {
      write("The new rank cannot be greater than eight.\n");
      return 1;
   }
   
   p = find_player(who);
   if (!p) {
      write("That person isn't around.\n");
      return 1;
   }
/*
   if (p != this_player() && (int) p->query_level() >= WIZARD) {
      write("Wizards are immune to setrank.\n");
      return 1;
   }
*/
   if (!present(OBJID, p)) {
      write(who); write(" does not bear the mark of Shardak.\n");
      return 1;
   }
   
   prev = (int) p->query_guild_rank();
   p->add_guild_rank(rank - prev);
   
   /* broadcast and log the command */
   msg = (prev > rank) ? " has been degraded to rank "
   : " has been promoted to rank ";
   CHANNELD->broadcast(capitalize(who) + msg + rank + ".\n",
      0, "{Servants}");
   
   write_file(LOGDIR + "setrank", this_player()->query_real_name() +
      " did setrank(" + arg + ")\n");
   return 1;    
}
