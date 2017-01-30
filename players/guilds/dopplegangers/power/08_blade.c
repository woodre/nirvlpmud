/*
 * Blade
 * Doppleganger damage spell - 20sp 20damage
 */

status main(string str) {
  object target;

  if (this_player()->query_guild_rank() < 8) {
    write("You are not high enough level to do that.\n");
    return 1;
  }
  if (this_player()->query_sp() < 20) {
    write("You do not have enough spell points for that.\n");
    return 1;
  }
  if (!str && !this_player()->query_attack()) {
    write("Send bladestorm at what?\n");
    return 1;
  }
  if (this_player()->query_attack())
    target = (object)this_player()->query_attack();
  else
    target = present(str, environment(this_player()));
  if (!target) {
    write("Send bladestorm at what?\n");
    return 1;
  }
  if (!this_player()->query_attack()) this_player()->attack_object(target);
  switch(random(100)) {
    case 0..49:
      write("The bladestorm engulfs your prey!\n");
      say(this_player()->query_name() + " sends a bladestorm at " +
          target->query_name() + ", tearing it to shreds!\n");
      target->hit_player(20);
      break;
    case 50..74:
      write("The bladestorm partially engulfs your prey.\n");
      say(this_player()->query_name() + " sends a bladestorm at " +
          target->query_name() + ", but only partially engulfs it.\n");
      target->hit_player(15);
      break;
    default:
      write("The bladestorm tears into your prey.\n");
      say(this_player()->query_name() + " sends a bladestorm at " +
          target->query_name() + ", sending a fine red mist from it.\n");
      target->hit_player(25);
      break;
  }
  this_player()->add_spell_point(-20);
  return 1;
}
