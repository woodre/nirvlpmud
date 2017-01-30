/*
  sew_skins.h
*/

#include "defs.h"

/* --------------- Sew skins to make armor --------------- */
sew_skins(str) {
  object skin_obj, armor_obj;
  int skin_strength, required_strength, random_nbr, success_chance;
  if (MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if(!str ||
     (str != "tuxedo" && str != "silk shirt" && str != "top hat" &&
      str != "boots" && str != "linen gloves" && str != "silk tie" &&
      str != "ruby ring")) {
    write("Use:  sew [tuxedo/silk shirt/top hat/boots/linen gloves\n"+
          "           silk tie/ruby ring]\n");
    return 1;
  }
  skin_obj = present("skin", MY_PLAYER);
  if (!skin_obj) {
    write("You don't have any skins.\n");
    return 1;
  }
  skin_strength = skin_obj->query_skin_strength();
  if (str=="tuxedo") required_strength=20;
  if (str=="silk shirt") required_strength=14;
  if (str=="top hat") required_strength=12;
  if (str=="boots") required_strength=10;
  if (str=="linen gloves") required_strength=6;
  if (str=="silk tie") required_strength=4;
  if (str=="ruby ring") required_strength=2;
  if (MY_GUILD_EXP==666) success_chance=10;
  if (MY_GUILD_EXP==667) success_chance=20;
  if (MY_GUILD_EXP==668) success_chance=30;
  if (MY_GUILD_EXP==669) success_chance=40;
  if (MY_GUILD_EXP==670) success_chance=50;
  if (MY_GUILD_EXP==671) success_chance=60;
  if (MY_GUILD_EXP==672) success_chance=70;
  success_chance=success_chance+25;
  random_nbr=random(100);
  if (skin_strength < required_strength) {
    write("That skin doesn't have enough strength to make "+str+".\n");
    return 1;
  }
  if (random_nbr > success_chance) {
    MY_PLAYER->add_weight(- skin_obj->query_weight());
    destruct(skin_obj);
    write("You attempt to sew the skin into a "+str+
          ", but fail and ruin the skin.\n");
    return 1;
  }
  MY_PLAYER->add_weight(- skin_obj->query_weight());
  destruct(skin_obj);
  if (str=="tuxedo") armor_obj=clone_object(VAMPIRE_TUXEDO);
  if (str=="silk shirt") armor_obj=clone_object(VAMPIRE_SILK_SHIRT);
  if (str=="top hat") armor_obj=clone_object(VAMPIRE_TOP_HAT);
  if (str=="boots") armor_obj=clone_object(VAMPIRE_BOOTS);
  if (str=="linen gloves") armor_obj=clone_object(VAMPIRE_LINEN_GLOVES);
  if (str=="silk tie") armor_obj=clone_object(VAMPIRE_SILK_TIE);
  if (str=="ruby ring") armor_obj=clone_object(VAMPIRE_RUBY_RING);
  move_object(armor_obj, MY_ROOM);
  write("You've successfully sewn your skins into a "+str+".\n"+
        "It's sitting on the ground in front of you.\n");
  return 1;
}
