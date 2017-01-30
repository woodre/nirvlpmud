/*
 * Forgearmor
 * Doppleganger spell to forge armor
 *          30sp / 100 coins - leather
 *          40sp / 200 coins - ringmail
 *          50sp / 300 coins - chain
 *          70sp / 500 coins - plate
 * Rumplemintz
 */

int main(string str) {
  int val, cost, class;
  object ob;

  if ((int)this_player()->query_guild_rank() < 15) {
    write("You are not high enough level to do that.\n");
    return 1;
  }

  switch(str) {
    case "leather":
      val = 100; cost = 30; class = 2; break;
    case "ringmail":
      val = 200; cost = 40; class = 3; break;
    case "chain":
      val = 300; cost = 50; class = 3; break;
    case "plate":
      val = 500; cost = 70; class = 4; break;
    default:
      write("You can:\n" +
            "  forgearmor leather    : 30 sp, 100 coins\n" +
            "  forgearmor ringmail   : 40 sp, 200 coins\n" +
            "  forgearmor chain      : 50 sp, 300 coins\n" +
            "  forgearmor plate      : 70 sp, 500 coins\n");
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

  ob = clone_object("/obj/armor");
  ob->set_name(str);
  ob->set_alias("armor");
  ob->set_short("A Barbarian's " + str + " armor");
  ob->set_long("This is a suit of " + str +
               " armor, made by a mighty barbarian.\n");
  ob->set_type("armor");
  ob->set_value(val);
  ob->set_weight(( cost/10) - 1);
  ob->set_ac(class);
  
  this_player()->add_spell_point(-cost);
  this_player()->add_money(-val);
  move_object(ob, this_player());
  write("You gather the needed elements and forge a suit of " +
        capitalize(str) + ".\n");
  say(this_player()->query_name() + " forges a suit of " +
      capitalize(str) + ".\n");
  return 1;
}

