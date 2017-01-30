/*
 * Crypt
 * Send a coprse to the guild hall (Mystic)
 * Rumplemintz
 */

int main(string str) {
  object corpseob, roomob;

  if (this_player()->query_guild_rank() < 11) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if (this_player()->query_sp() < 30) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  corpseob = present("corpse", this_player());
  if (!corpseob) corpseob = present("corpse", environment(this_player()));
  if (!corpseob) {
    write("There is no corpse present.\n");
    return 1;
  }

  roomob = find_object("/players/guilds/dopplegangers/room/mystic_guildhall");
  if (!roomob) roomob->xxx();
  write("You send the corpse back to your crypt.\n");
  say(this_player()->query_name() + " sends a corpse to the crypt.\n");
  move_object(corpseob, roomob);
  this_player()->add_spell_point(-30);
  return 1;
}

