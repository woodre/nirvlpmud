/*
 *  The update ability of the succubus.  (v2.0)
 *
 */

succubus_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/succubus.c");
  ob2 = present("succubus_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("The ruby reflects your perfect features.\n");
  return 1;
        }
