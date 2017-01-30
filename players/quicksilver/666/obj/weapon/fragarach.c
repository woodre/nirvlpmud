#include "/players/quicksilver/666/include/std.h"

inherit WEAPON;

reset(arg) {
     ::reset(arg);
     if (arg) return;
     set_name("An Fragarach");
     set_alias("broadsword");
     set_short("a broadsword named 'An Fragarach'");
     set_long("This mighty broadsword is forged from the strongest iron in the land.\n"+
              "Upon it is the mark of Lugh, the master craftsman.");
     set_save_flag(1);
     set_class(18);
     set_weight(5);
     set_value(5000);
     set_hit_func(this_object());
}

static weapon_hit(attacker) {
     object reducer;
     
     if(!broke && !present("quicksilver_ac_reducer", ENVTO->query_attack())) {
          reducer = clone_object(OBJ_DIR + "ac_reducer");
          move_object(reducer, ENVTO->query_attack());
          reducer->reduce_ac();
          wwrite("Your blade sings as it slices through your opponent's armor.\n");          
          wsay(format(capitalize(ENVTO->NAME) + "'s blade slices clean through " + capitalize((ENVTO->query_attack())->NAME) + "'s armor.\n", 75));
     }
     return 1;
}

wield(str) {
     if(!id(str)) return;
     if(ENVTO->query_level() < 14) {
          wwrite("You fumble the weapon clumsily.\n");
          return;
     }
     return ::wield(str);
}
