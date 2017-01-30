/*
 * Mystic Bag (mb)
 * Doppleganger spell to create a bag
 */

status main(string str) {
  object bag;

  if (str) return 0;
  if (this_player()->query_guild_rank() < 10) {
    write("You are not high enough level to do that yet.\n");
    return 1;
  }
  if (this_player()->query_spell_point() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  write("You conjur up a magical bag.\n");
  say(this_player()->query_name() + " conjures up a magical bag.\n");
  this_player()->add_spell_point(-20);
  bag = clone_object("/players/guilds/dopplegangers/obj/bag");
  bag->set_max_weigth(20 +
       (((int)this_player()->query_guild_rank() -9) * 2) );
  bag->set_short("A Mystic bag. (Created by " + this_player()->query_name() +
                 ")");
  bag->set_long("A Mystic bag. (Created by " + this_player()->query_name() +
                ")\n" +
                "This is a magical bag used by the Mystic faction of the " +
                "Dopplegangers guild.\n");
  move_object(bag, this_player());
  return 1;
}
