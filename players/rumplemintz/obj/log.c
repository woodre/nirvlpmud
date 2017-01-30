/* Log - by Blammo! - Original by Boltar
                      Modded by Rumplemintz
 */

#include "/obj/user/shout_only.c"
#include "/obj/clean.c"

int nomove;

string short() { return "A log"; }

int id(string str) { return str == "log"; }

int get() {
  write("It's big, It's heavy, It's wood!\n");
  return 0;
}

int weight() { return 10000; }

void long() {
  write("It's log, It's Log....\n"+
        "It rolls down stairs, alone or in pairs\n"+
        "or over your neighbor's dog.\n"+
        "It's great for a snack, it fits on your back,\n"+
        "It's log, log, log.\n"+
        "It's log, It's log\n"+
        "It's Big, It's Heavy, It's Wood.\n"+
        "It's Better than Bad, ITS GOOD!\n\n"+
        "It's Log..... from Blammo!\n\n\n"+
        "To use type 'roll playername'\n");
  return;
}

void init() {
  add_action("roll","roll");
}

int roll(string str) {
  object where, who;

  if (!str)
    return 0;
  who = find_player(str);
  if (!who) {
    write("There is no player "+capitalize(str)+" in the area.\n");
    return 1;
  }
  if (who->query_level() > 20 &&
      this_player()->query_level() < 20) {
    write("You can't roll logs at wizards.\n");
    return 1;
  }
  where = environment(this_object());
  chan_msg("You hear the rumbling of a log rolling.\n");
  chan_msg("It rolls down stairs, alone or in pairs, and runs over " +
           capitalize(str) + "!\n");
  tell_object(who, "A log rolls over you! OUCH!\n");
  move_object(this_object(),environment(who));
  if (environment(this_object()) == where) {
    nomove++;
    if (nomove > 3) {
      write("The log rolls off at a high rate of speed.\n");
      move_object(this_object(),"/room/slope");
      if (random(5) < 2)
        move_object(this_object(),"/room/forest9");
    }
  }
  else
    nomove = 0;
  return 1;
}

