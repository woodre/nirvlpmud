
/*
 * INVITE (2/15/94)
 * Invites player into guild
 */

invite(str) {
   object target, scroll;

   if(!str)
     notify_fail("Who do you wish to recruit?");
   if(this_player()->query_level() < 19)
     notify_fail("You must be level 19 to recruit into the guild.");
   target = find_player(str);
   if(!target || !present(target, environment(this_player())))
     notify_fail("Noone by that name is here.");
   TELL(capitalize(this_player()->query_name())+" hands "+
       capitalize(str)+" a scroll.\n");
   tell_object(target, capitalize(this_player()->query_name())+
       " has invited you into the Paladins guild.\n"+
       "Look at the scroll for more information about the guild,\n"+
       "its special abilities and how to join.\n");
   scroll = clone_object("players/sandman/paladin/obj/scroll");
   move_object(scroll, target);
   return 1;
}

