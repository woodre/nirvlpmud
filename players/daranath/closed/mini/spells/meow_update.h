/*
 *  The update ability of the felines.  (v2.0)
 *
 */

meow_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/feline.c");
  ob2 = present("meow_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("You bat at your ball of string.\n");
  return 1;
        }
