/*
 *  How to get out of a mini guilds (v2.0)
 *
 */


gothic_bye()  {
  OBJ = present("gothic attitude",this_player());
  OBJ->set_is_gothic(0);
  write("You feel your depression lift as you leave the goths...\n");
  call_out("gone",1);
  return 1;
        }
