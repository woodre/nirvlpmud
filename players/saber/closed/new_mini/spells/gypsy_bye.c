/*
 *  How to get out of a mini guilds (v2.0)
 *
 */

static object OBJ;

gypsy_bye()  {
  OBJ = present("gypsy medallion",this_player());
  OBJ->set_is_gypsy(0);
  write("You renounce your gypsy heritage.\n");
  call_out("gone",1);
  return 1;
        }
