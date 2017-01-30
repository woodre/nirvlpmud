/*
 *  How to get out of a mini guilds (v2.0)
 *
 */


i_am_no_canine() {
  OBJ = present("tattered collar",this_player());
  OBJ->set_is_canine(0);
/* shread=shred */
write("You shred up your collar.\n");
  call_out("gone",1);
  return 1;
        }
