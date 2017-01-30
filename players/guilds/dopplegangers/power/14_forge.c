/*
 * Forge
 * Doppleganger spell to forge a weapon
 *          20sp / 100 coins - dagger
 *          30sp / 200 coins - mace
 *          40sp / 300 coins - sword
 *          50sp / 500 coins - axe
 * Rumplemintz
 */

int main(string str) {
  int val, cost, class;
  object ob;

  if ((int)this_player()->query_guild_rank() < 14) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  switch(str) {
    case "dagger":
      val = 100; cost = 20; class = 6; break;
    case "mace":
      val = 200; cost = 30; class = 8; break;
    case "sword":
      val = 300; cost = 40; class = 10; break;
    case "axe":
      val = 500; cost = 50; class = 13; break;
    default:
      write("You can:\n" +
            "  forge dagger : 20 sp, 100 coins\n" +
            "  forge mace   : 30 sp, 200 coins\n" +
            "  forge sword  : 40 sp, 300 coins\n" +
            "  forge axe    : 50 sp, 500 coins\n");
      return 1;
  }

  if ((int)this_player()->query_money() < val) {
    write("You do not have enough coins for that.\n");
    return 1;
  }

  if ((int)this_player()->query_sp() < cost) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }

  ob = clone_object("/obj/weapon");
  ob->set_id(str);
  ob->set_alias(str);
  ob->set_short("A Barbarian's " + str);
  ob->set_long("This is a " + str + " made by a mighty barbarian.\n");
  ob->set_value(val);
  ob->set_weight(( cost/10) - 1);
  ob->set_class(class);
  
  this_player()->add_spell_point(-cost);
  this_player()->add_money(-val);
  move_object(ob, this_player());
  write("You gather the needed elements and forge a " +
        capitalize(str) + ".\n");
  say(this_player()->query_name() + " forges a " +
      capitalize(str) + ".\n");
  return 1;
}

