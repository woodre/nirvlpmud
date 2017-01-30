/*
 *  The update ability of the blades.  (v2.0)
 *
 */

blade_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/blade.c");
  ob2 = present("blade_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("You look up with a sparkle in your eyes\n"+
    "   And a dream in your heart...\n");
  return 1;
        }
