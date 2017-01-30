
/*
 * MARK (2/12/94)
 * Will mark a monster with the paladins name.
 * If attacked by another player they will be notified
 * Moves shadowing obj (mark.c) to monster
 */

mark(who) {
   object target, mark;

   if(!who)
     notify_fail("Who do you wish to mark?");
   target = present(who, environment(this_player()));
   if(!target || !living(target))
     notify_fail(capitalize(who)+" is not here.");
   if(!target->query_npc())
     notify_fail("You may not mark players.");
   if(target->query_marked()) 
     notify_fail(capitalize(who)+" has already been marked by "+
           capitalize(target->query_marker())+".");
   mark = clone_object("players/sandman/paladin/obj/mark");
   mark->start_mark(target,this_player()->query_real_name());
   TELL(capitalize(this_player()->query_name())+" marks "+
        capitalize(who)+".\n");
   return 1;
}

