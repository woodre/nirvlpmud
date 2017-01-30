#include "../tasks.h"
/*
* IGNITE (curse) spell for the Shardak guild
* Prevents other people from picking up "cursed" items
*/
#pragma strict_types
#include "../std.h"
#include "../def.h"
#include "../macros.h"
#define COST 15

inherit CMD;

status
main(string arg)
{
   object ob, it;
   
   needrank(7);
   needmana(COST);
   needtask(FLAMES_TASK);
    if(!arg) return (notify_fail("Ignite what?\n"), 0);
   if (!(ob = present(arg, this_player())) &&
         !(ob = present(arg, environment(this_player()))))
   return (notify_fail("You do not have that.\n"), 0);
   
   /* check if it has been done already */
      if (ob->shardak_curse(0)) {
      write("It has already been ignited.\n");
      return 1;
   }
   
   /* do the thang */
   it = clone_object(OBJDIR + "heavyness");
   if (it->shardak_curse(ob)) {
      write("\
         You make some arcane gestures at the " + arg + ".\n"+
         "Flames explode all over it!\n");
      say(this_player()->query_name() + " \
makes some arcane gestures at the " + arg + ".\n" +
         "Flames explode all over it!\n");
   }
   else 
      {
      write(
         "You make some arcane gestures at the " + arg + ".\n"+
         "But, the flames cannot get a grip on this item.\n");
      say(this_player()->query_name() + " makes some gestures at the " +
         arg + ", but nothing happens.\n");
      destruct(it);
   }
   this_player()->add_spell_point(-COST);
   return 1;
}
