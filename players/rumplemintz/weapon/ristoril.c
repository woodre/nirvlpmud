/*
**  Ristoril, champion bastard sword
 */

#include <ansi.h>

inherit "obj/weapon";

int paint_blade(object attacker);

void reset(status arg) {
  ::reset(arg);
  if (arg)
    return;
  set_name("ristoril");
  set_alias("sword");
  set_short(BLU + "Ristoril" + NORM);
  set_long(BLU + "Ristoril" + NORM + ", a champion bastard sword.\n");
  set_class(20);
  set_weight(0);
  set_value(10000);
  set_hit_func(this_object());
}

int query_wear() { return 1; }
int weapon_breaks() { return 1; }

int weapon_hit(object attacker) {
  if (this_player() != environment())
    return 0;
  if (attacker && attacker->query_hp() > 57)
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
    paint_blade(attacker);
  return 0;
}

int paint_blade(object attacker) {
  string what, how;
  object *ob;
  int i, mi;

  if (!attacker)
    return 1;
  ob = all_inventory(environment(this_player()));
  if (attacker && attacker->query_hp() > 57)
    attacker->hit_player(57, "other|renshai");
  mi = random(8);
  switch(mi) {
  case 0: break;
  case 1: how = " to small fragments"; what = "massacre"; break;
  case 2: how = " with a bone crushing sound"; what = "smashed"; break;
  case 3: how = " very hard"; what = "hit"; break;
  case 4: how = " hard"; what = "hit"; break;
  case 5: how = ""; what = "hit"; break;
  case 6: how = ""; what = "grazed"; break;
  case 7: how = " in the stomach"; what = "tickled"; break;
  }
  if (attacker) {
    tell_object(attacker, this_player()->query_name() + " " + what + " you" +
                          how + ".\n");
    if (mi > 0) {
      tell_object(this_player(), "You " + what + " " + attacker->query_name() +
                                 how + ".\n");
      for (i=0;i<sizeof(ob);i++) {
        if (ob[i] != this_player() && ob[i] != attacker && living(ob[i]))
          tell_object(ob[i], this_player()->query_name() + " " + what + " " +
                      attacker->query_name() + how + ".\n");
      }
    }
    else {
      tell_object(this_player(), "You missed.\n");
      for (i=0;i<sizeof(ob);i++) {
        if (ob[i] != this_player() && ob[i] != attacker && living(ob[i]))
          tell_object(ob[i], this_player()->query_name() + " missed " +
                      attacker->query_name() + ".\n");
      }
    }
  }
  return 1;
}

void init() {
  ::init();
  if (environment(this_object()) != this_player())
    return;
  if ((string)this_player()->query_real_name() != "rump" &&
      (string)this_player()->query_real_name() != "paven" &&
      (string)this_player()->query_real_name() != "rumplemintz") {
    write("Foolish child, this is not yours!\n");
    destruct(this_object());
    return;
  }
}
