/*
 *  How to get out of a mini guilds (v2.0)
 *
 */

static object OBJ;

kender_bye()  {
  OBJ = present("hoopak",this_player());
  OBJ->set_is_kender(0);
  write("You drop your hoopak and shed your innocent smile.\n");
  call_out("gone",1);
  return 1;
        }
