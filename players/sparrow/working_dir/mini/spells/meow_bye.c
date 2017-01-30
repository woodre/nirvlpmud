/*
 *  How to get out of a mini guilds (v2.0)
 *
 */

static object OBJ;
static object claw;

meow_bye()  {
  OBJ = present("string",this_player());
  OBJ->set_is_feline(0);
  if(this_player()->query_attrib("ste") > 30) this_player()->set_attrib("ste", 30);
  write("You shed your tail and whiskers as you leave the felines.\n");
  if(present("kitty_claws", this_player()))  {
    claw = present("kitty_claws", this_player());
    destruct(claw);
        }
  call_out("gone",1);
  return 1;
        }
