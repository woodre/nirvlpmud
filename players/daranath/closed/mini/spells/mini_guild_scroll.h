/*
 *  Summon a mini guild scroll.  (v2.0);
 *
 */

mini_guild_scroll(str)  {

  if(!str)  {
  write("You summon a mini guild scroll.\n");
  move_object(clone_object("/players/saber/closed/new_mini/scroll.c"),this_player());
  return 1;
        }
        }
