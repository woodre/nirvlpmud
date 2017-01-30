/*
 *  How to get out of a mini guilds (v2.0)
 *
 */


blade_bye()  {
  OBJ = present("scabbard",this_player());
  OBJ->set_is_blade(0);
  write("You break your dueling knife.\n");
  call_out("gone",1);
  return 1;
        }
