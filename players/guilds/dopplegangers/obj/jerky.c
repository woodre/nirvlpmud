/*
 * jerky.c
 * Corpse jerky!  Dopplegangers use spell to make this from corpses
 */

inherit "/obj/treasure";

string nme, spice_level;
int jerk;

void reset(int arg) {
  if(arg) return;
  nme = "Nothing";
  jerk = 5;
  spice_level = "";
  set_alias("jerky");
  set_weight(1);
  set_long("This is a rough jerky made from the corpse of " +
           capitalize(nme) + ".\n");
}

int set_nme(string str) {
  nme = str;
  return 1;
}

void init() {
  ::init();
  add_action("eat","eat");
}

int eat(string str) {
  if(!str || str != "jerky")
    return 0;
  this_player()->add_hit_point(jerk);
  say(this_player()->query_name() + " east a strip of jerky.\n");
  switch(jerk) {
    case 1..5:
      write("You eat some jerky and feel better.\n");
      break;
    case 6..10:
      write("You eat some jerky and wipe the tears from your eyes.\n");
      break;
    case 11..15:
      write("You eat some jerky and wipe the sweat from your brow.\n");
      break;
    default:
      write("You eat some jerky and smoke begins wafting from your ears.\n");
      break;
  }
  destruct(this_object());
  return 1;
}

string short() {
  return capitalize(nme) + " Jerky";
}

void long() {
  write("This is rough jerky made from the corpse of a " + capitalize(nme) +
        ".\n");
  write(jerk > 5 ? "Spice Level " + spice_level + "\n" : "");
}

int add_jerk(int x) {
  int i;

  jerk = jerk + x;

/*  for (i=5; i<jerk; i+4) {
    spice_level == spice_level + "+";
  }
*/
  spice_level += "*";

  return 1;
}

int query_jerk() { return jerk; }

