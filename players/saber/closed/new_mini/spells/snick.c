/*
 *  The claws of the feline mini guild.  (v. 2.0)
 *
 */

snick()  {
  object ob, ob2;

  if(present("kitty_claws", this_player()))  {
    write("You retract your claws.\n");
    say(this_player()->query_name()+" retracts "+this_player()->query_possessive()+" claws.\n");
    ob = present("kitty_claws", this_player());
    command("unwield kitty_claws", this_player());
    destruct(ob);
  return 1;
        }

move_object(clone_object("/players/saber/closed/new_mini/kittyclaws.c"),this_player());
  command("wield kitty_claws", this_player());
    write("You extend your claws.\n");
    tell_room(environment(this_player()), "You hear a 'snick' noise as "+
      this_player()->query_name()+" extends "+this_player()->query_possessive()+" claws.\n");
    return 1;
        }
