/*
 *  The update ability of the kender.  (v2.0)
 *
 */

kender_update()  {
  object ob, ob2;
  ob = clone_object("/players/saber/closed/new_mini/kender.c");
  ob2 = present("kender_obj", this_player());
  move_object(ob, this_player());
  destruct(ob2);
  write("You clean your hoopak.\n"+
    "It gleams with a mischevious light...\n");
  return 1;
        }
