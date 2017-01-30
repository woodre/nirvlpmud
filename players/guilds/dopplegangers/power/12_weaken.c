/*
 * Weaken 
 * Doppleganger spell to lower AC of attacker for a bit - 40sp
 * Rumplemintz
 */

int main(string str) {
  object ob, weaken_ob;
  int realac;

  if ((int)this_player()->query_guild_rank() < 12) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_spell_point() < 40) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str && !this_player()->query_attack()) {
    write("What do you want to cast weaken on?\n");
    return 1;
  }

  if (this_player()->query_attack())
    ob = (object)this_player()->query_attack();
  else
    ob = present(str, environment(this_player()));
  if (!ob) {
    write("What do you want to cast weaken on?\n");
    return 1;
  }

  if (!ob->query_npc()) {
    write("You cannot cast weaken on players.\n");
    return 1;
  }

  if (present("mystic_weaken_ob", ob)) {
    write(ob->query_name() + " is already being weakened.\n");
    return 1;
  }

  write("You cast weaken on " + ob->query_name() + ", crippling it.\n");
  say(this_player()->query_name() + " casts weaken on " + ob->query_name() +
      ", crippling it.\n");
  this_player()->add_spell_point(-40);
  if (!this_player()->query_attack())
    ob->attacked_by(this_player());

  weaken_ob = clone_object("/players/guilds/dopplegangers/obj/weaken_obj");
  move_object(weaken_ob, ob);
  weaken_ob->original();
  weaken_ob->set_duration(this_player()->query_guild_rank());
  weaken_ob->ac_mod();
  return 1;
}
