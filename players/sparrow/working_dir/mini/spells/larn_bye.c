/*
 *  How to get out of a mini guilds (v2.0)
 *
 */

static object OBJ;

larn_bye()  {
  OBJ = present("holy symbol",this_player());
  OBJ->set_is_larn(0);
  write("You drop your holy symbol and abandon your faith.\n");
  call_out("gone",1);
  return 1;
        }
