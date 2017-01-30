/*
 *  The update ability of the servants of larn.  (v2.0)
 *
 */

larn_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/larn.c");
  ob2 = present("larn_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("Your holy symbol shines like new.\n");
  return 1;
        }
