/*
 * Spirits
 * Doppleganger protection spell, 40sp for 20+random(30) hp of protection
 * Rumplemintz
 */

int main(string str) {
  object spiritsob, badge;
  int req_lev, req_sps, abs;
  string fact;

  badge = present("V-GUILD", this_player());

  if (query_verb() == "absorb" && badge->query_faction("barbarian")) {
    req_lev = 15;
    req_sps = 50;
    fact    = "Barbarian";
    abs     = 40 + random(20);
  } else if (query_verb() == "spirits" && badge->query_faction("mystic")) {
    req_lev = 13;
    req_sps = 40;
    fact    = "Mystic";
    abs     = 20 + random(30);
  } else return 0;

  if (str) return 0;

  if ((int)this_player()->query_guild_rank() < req_lev) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if ((int)this_player()->query_sp() < req_sps) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (present("dopple_spirits_ob", this_player())) {
    write("Your spirits are already protecting you.\n");
    return 1;
  }
  spiritsob = clone_object("/players/guilds/dopplegangers/obj/spirits_ob");
  move_object(spiritsob, this_player());
  spiritsob->start_me(abs);
  this_player()->add_spell_point(-req_sps);
  write("The " + fact + " faction spirits begin absorbing damage for you.\n");
  say(this_player()->query_name() + " casts a spell and is suddenly " +
      "surrounded by spirits.\n");
  return 1;
}
