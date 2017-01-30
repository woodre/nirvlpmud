/*
 * berserk
 * Doppleganger AoE attack - 30sp per NPC - 30 damage to each
 * 10 second delay on reuse
 */

status main(string str) {
  object ob;
  int count;
  object badge;
  int delay;

  if (this_player()->query_guild_rank() < 5) {
    write("You are not high enough level for that.\n");
    return 1;
  }
  if (!this_player()->query_attack()) {
    write("You must be engaged in combat first.\n");
    return 1;
  }
  if (str) return 0;
  badge = present("V-GUILD", this_player());
  ob = first_inventory(environment(this_player()));
  while (ob) {
    if (ob->query_npc() && !ob->query_pet())
      count++;
    ob = next_inventory(ob);
  }
  if (this_player()->query_sp() < count*30) {
    write("You do not have enough spell points for that many attacks.\n");
    return 1;
  }
  if (badge->query_berserk_delay() > time()) {
    write("You are too tired to try that again.\n");
    return 1;
  }
  ob = first_inventory(environment(this_player()));
  while (ob) {
    if ((ob->query_npc() && !ob->query_pet())) {
      write("You go berserk on " + ob->short() + ".\n");
      say(this_player()->query_name() + " goes berserk!\n");
      if (ob->query_attack() && (object)this_player()->query_attack() != ob)
        ob->stop_fight();
      ob->attack_object(this_player());
      ob->hit_player(30);
    }
    if (!ob) {
      ob = find_object("sdlfkjsdlfkj");
      write("The death soothes your savage onslaught.\n");
    } else
      ob = next_inventory(ob);
  }
  this_player()->add_spell_point(-(count*30));
  badge->set_berserk_delay(time() + 10);
  write("You gasp for breath.\n");
  return 1;
}

