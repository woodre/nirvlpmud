/* Slowly regens a player by 5 hps every other hb while raising 
 * intox by 1 pt every other time. Lasts for 30x's
 * 30 hb's x 5 hps = 150 hps, 1pt(intox) x 15 = 15 total tox
 * Cost is supposed to be 3300 - 1/3(heals hps only), but I set
 * it at 3000 coins.  I used wockets idea of just using the
 * same object instead of desting this one and cloning another
 * to handle the regening
 */

/* Did some formatting so I could read it better and made some minor
   changes (ansi bleed, etc...)
   - Rump
 */

#include "/players/jaraxle/define.h"

#define USER environment()

int duration, used, count, count2;

int id(string str) { 
  if (!used)
    return str == "potion" ||
           str == "flask" ||
           str == "flask of regeneration" ||
           str == "regen" ||
           str == "elixir";
  else return str == "regen_object_jar";
}

status get() { return 1; }

status drop() {
  if (used) return 0;
  else return 1;
}

int query_weight() {
  if (!used) return 1;
  else return 0;
}

int query_value() {
  if (!used) return 1000;
  else return 0;
}

int query_save_flag() { return 1; }

string short() {
  if (!used) return "Flask of " + HBYEL + MAG + "Regeneration" + NORM;
  else return 0;
}

void long() {
  if (!used)
    write(
       "This is a powerful elixir that imbues the drinker\n" +
       "with the regeneration ability similar to that of\n" +
       "a Bard, wounds literally closing over and healing\n" +
       "as you watch. The effect lasts for about 30 turns.\n");
  else return;
}

void reset(status arg) {
  if(arg) return;
  duration = 60;
}

void init() {
  add_action("use_kit", "drink");
}

int use_kit(string str) {
  if (id(str)) {
    if (environment(this_object()) != this_player()) return 0;
    if (present("regen_object_jar", this_player())) {
      write("You are already regenerating!\n");
      return 1;
    }
    used = 1;
    count = 1;
    set_heart_beat(1);
    tell_object(USER, "You drink the regeneration elixir...\n");
    tell_room(environment(USER),
              USER->query_name() + " drinks a potion.\n", ({ USER }));
    this_object()->set_weight(0);
    return 1;
  }
  return 0;
}

status heart_beat() {
  if (environment()->query_ghost()) {
    USER->recalc_carry();
    destruct(this_object());
    return 1;
  }
  if (!duration) {
    USER->recalc_carry();
    tell_object(USER, "The regeneration ends...\n");
    destruct(this_object());
    return 1;
  }
  count++;
  count2++;
  if (count == 2) {
    if (USER->query_intoxination() > USER->query_level() + 3) {
      tell_object(USER,
        "You feel that your body cannot handle the regeneration...\n");
    }
    else {
      tell_object(USER,
                  HIC + "~~" + NORM +
                  " You feel a healing energy flow through your veins...\n");
      USER->add_hit_point(5);
      if (count2 == 4) {
        USER->drink_alcohol(1);
        count2 = 0;
      }   
    }
    count = 0;
  }   
  duration -= 1;
}

