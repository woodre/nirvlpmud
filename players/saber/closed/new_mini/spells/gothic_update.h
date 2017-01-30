/*
 *  The update ability of the goths.  (v2.0)
 *
 */

gothic_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/gothic.c");
  ob2 = present("gothic_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("You feel even more depressed.\n");
  return 1;
        }
