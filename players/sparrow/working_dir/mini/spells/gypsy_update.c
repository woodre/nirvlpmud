/*
 *  The update ability of the gypsy.  (v2.0)
 *
 */

gypsy_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/gypsy.c");
  ob2 = present("gypsy_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("You polish your gypsy medallion.\n"+
    "The golden runes glow brightly...\n");
  return 1;
        }
