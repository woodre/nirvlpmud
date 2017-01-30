/*
 * A bless corpse ability for the Servants of Larn.
 *  For version 2.0 of the mini guilds.
 *
 */

bless_corpse()  {

  object corpse;
  int heal;

  heal = 0;

  corpse = present("corpse", environment(this_player()));
  if(!corpse)  {
    corpse = present("corpse",this_player());
        }
  if(!corpse)  {
    write("There is no corpse here to bless.\n");
    return 1;
        }

  heal = corpse->heal_value();
  call_other(this_player(), "heal_self", heal);
  write("You say a blessing over the corpse.\n"+
    "The spirit departs in peace.\n");
  say(tp+" whispers a brief prayer over the corpse.\n");
  destruct(corpse);
    return 1;
        }
