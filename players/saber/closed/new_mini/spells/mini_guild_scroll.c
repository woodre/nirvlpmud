/*
 *  Summon a mini guild scroll.  (v2.0);
 *
 */

mini_guild_scroll(str)  {

  if(!str)  {
  if(this_player()->query_sp() < 10) {
    write("You do not have enough energy to clone a miniguild scroll!\n"); return 1; }
  this_player()->add_spell_point(-10);
  write("You summon a mini guild scroll.\n");
  move_object(clone_object("/players/saber/closed/new_mini/scroll.c"),this_player());
  return 1;
        }
        }
