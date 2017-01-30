#include <ansi.h>
inherit "players/pavlik/armor/armor";
#define ME capitalize(worn_by->query_name())
#define BONUS 3

/*
 * This necklace will heal the player wearing it every time its reset
 * is called.  The necklace does have unlimited charges because the
 * healing function is seldom and because it is a very difficult item
 * to get.  This item is UNIQUE and only 1 can exist at any time.
 *
 * from: ~/monsters/ilstkarn/banshee (10000 hp monster)
 */
/* APPROVED BY SNOW 5/28/98 */

reset(arg) {
 if(arg) {
   heal_me();
   return;
 }
 set_name("the Ralston Necklace");
 set_alias("necklace");
 set_short("the Ralston Necklace "+HIY+"(glowing)"+NORM);
 set_long("the necklace.\n");
 set_ac(2);
 set_type("misc");
 set_weight(1);
 set_value(700);
 set_arm_light(0);
 set_save_flag(1);
 heal_me();
}

/*
 * This function is only called out at reset() and heals the
 * player 30+random(70)
 */
heal_me() {
  if(!worn_by) {
    return 1;
  }
  tell_object(worn_by,
  "The enchanted sapphires of the Ralston Necklace sparkle brilliantly!\n"+
  "The warm tingling of healing magic spreads across your body.\n");
  tell_room(environment(worn_by),
  ME+"'s sapphire necklace sparkles brilliantly.\n");
  worn_by->heal_self(30+random(70));
  return 1;
}

query_guild_bonus(){ return BONUS; }

add_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_wil_bonus(BONUS);
    present("mageobj", this_player())->add_pow_bonus(BONUS);
    present("mageobj", this_player())->add_conj_bonus(BONUS);
    present("mageobj", this_player())->add_illu_bonus(-2);
  }
  return 1;
}

remove_guild_bonus() {
  if(present("mageobj", this_player())) {
    present("mageobj", this_player())->add_wil_bonus(-BONUS);
    present("mageobj", this_player())->add_pow_bonus(-BONUS);
    present("mageobj", this_player())->add_conj_bonus(-BONUS);
    present("mageobj", this_player())->add_illu_bonus(2);
  }
  return 1;
}

