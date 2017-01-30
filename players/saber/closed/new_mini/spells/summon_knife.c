/*
 *  The succubus (version 2.0) ability to summon a Succubus Knife.
 *
 */

summon_knife()  {

  object knife;

  if(spell(-2000,1,40) ==-1)  return 0;

  move_object(clone_object("/players/saber/closed/new_mini/succ.c"),this_player());

  write("A small imp flies in and presents you with a gleaming knife.\n");
  say("A small imp flies in and presents "+TP->query_name()+" with "+
    "a gleaming knife.\n");

  call_other(this_player(), "add_spell_point", -40);
  return 1;
        }
