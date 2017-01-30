/*
 * Veil
 * Doppleganger spell to lower WC of attacker for a bit - 50sp
 * Rumplemintz
 */

int main(string str) {
  object ob, veil_ob;
  int realwc;

  if ((int)this_player()->query_guild_rank() < 11) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  if ((int)this_player()->query_spell_point() < 50) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  if (!str && !this_player()->query_attack()) {
    write("What do you want to cast veil on?\n");
    return 1;
  }

  if (this_player()->query_attack())
    ob = (object)this_player()->query_attack();
  else
    ob = present(str, environment(this_player()));
  if (!ob) {
    write("What do you want to cast veil on?\n");
    return 1;
  }

  if (!ob->query_npc()) {
    write("You cannot cast veil on players.\n");
    return 1;
  }

  if (present("mystic_veil_ob", ob)) {
    write(ob->query_name() + " is already being affected by a veil.\n");
    return 1;
  }

  write("You cast a veil on " + ob->query_name() + ", crippling it.\n");
  say(this_player()->query_name() + " casts a veil on " + ob->query_name() +
      ", crippling it.\n");
  this_player()->add_spell_point(-50);
  if (!this_player()->query_attack())
    ob->attacked_by(this_player());

  veil_ob = clone_object("/players/guilds/dopplegangers/obj/veil_obj");
  move_object(veil_ob, ob);
  veil_ob->original();
  veil_ob->set_duration(this_player()->query_guild_rank());
  veil_ob->wc_mod();
  return 1;
}
