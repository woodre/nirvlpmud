/*
 *  The update ability of the canine.  (v2.0)
 *
 */

canine_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/canine.c");
  ob2 = present("canine_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
write("You tug on the collar around your neck.\n"+
     "The collar seems to fit much better now...\n");
  return 1;
        }
