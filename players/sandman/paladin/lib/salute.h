
/*
 * SALUTE (2/11/94)
 * Paladin greeting
 */

salute(str) {
   object target;
   int level;
   string title, me, pos;

   if(!verify_use())
     return 1;
   if(!str) 
     notify_fail("Who do you wish to salute?");
   target = find_player(str);
   if(!target || !present(target, environment(this_player()))) 
     notify_fail(capitalize(str)+" is not here.\n");
   if(target == this_player()) 
     notify_fail("You cannot salute yourself.\n");
   if(!present("guild_medal", target)) 
     notify_fail(capitalize(str)+" is not a Paladin!\n");
   me = capitalize(this_player()->query_real_name());
   pos = this_player()->query_possessive();
   level = target->query_level();
   if(level > 20) level = 20;
   level -= 1;
  if(target->query_gender() == "female")
    title = PALGUILD->get_new_title(level,str,1);
  else
    title = PALGUILD->get_new_title(level,str);
   TELL(me+" raises "+pos+" hand in a salute.\n");
   TELL(me+" says:  Greetings "+capitalize(str)+", "+title+"!\n");
   TELL(me+" says:  Aik seun illuminae pardes oueverts de Gil-Estel!\n");
   return 1;
}
