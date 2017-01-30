/* Gash spell for Shardak guild - (tm) Dragnar/John
 * Gash spell is (c) Balowski/Rasmus, January 28th 1995.
 * Last change: Jan 28th '95 - Bal
 */
#define WOUNDOBJ "players/dragnar/guild/test/woundobj"

prepare_spell(str, cost) {
  object ob;

  if (this_player()->query_ghost()) {
    write( "You fail.\n");
    return 0;
  }

  if (str) {
    ob = present(str, environment(this_player()));
    if (!ob) {
      write( capitalize( str) + " is not here.\n");
      return 0;
    }
    if (!living(ob)) {
      write( "Only a foolish warrior would try to kill something that is not alive.\n");
      return 0;
    }
    if (ob == this_player()) {
      write("What? Attack yourself?\n");
      return 0;
    }
  }
  else
    ob= this_player()->query_attack();

  if (!ob) {
    write( "Who do you want to wound?\n");
    return 1;
  }

  if (ob->is_player()) {
    write("Shardak does not allow you to use your powers against a player.\n");
    return 0;
  }

  if (this_player()->query_sp() < cost) {
    write("You do not have enough spell points to sacrifice!\n");
    return 0;
  }

  this_player()->add_spell_point( -cost);
  this_player()->attack_object( ob);
  return ob;
}


gash( string who) {
  object victim, wound;
  int depth;
  string msg;

  victim= prepare_spell( who, 25);
  if (!victim)
    return 1;

  wound= present( "shardakgash", victim);
  if (!wound) {
    wound= clone_object( WOUNDOBJ);
    wound->set_victim( victim);
    move_object( wound, victim);
  }

  depth= random( 30);

  /* gory message */
  if (depth > 20)
    msg= " trenches a huge gaping wound in ";
  else if (depth > 10)
    msg= " claws a gory gash in ";
  else
    msg= " rakes a wound in ";

  say( format(
this_player()->query_name() + " whispers slithering words of magic and " +
possessive( this_player()) + " left hand grows scaly and clawlike.\n\
With effortless ease " + subjective( this_player()) + msg +
victim->query_name() + ".\n"));

  print( "As you whisper the magic formula, your left hand grow scaly and \
clawlike. With a will of its own, it" + msg + victim->query_name() + ".\n");

  wound->add_wound( this_player()->query_name(), 20 + depth);
  return 1;
}
