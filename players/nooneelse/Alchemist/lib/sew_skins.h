/*
  sew_skins.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* --------------- Sew skins to make armor --------------- */
sew_skins(str) {
  object skin_obj, armor_obj;
  int skin_strength, required_strength, random_nbr, success_chance;
  int how_much_thread;

  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 10) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  if(!str ||
     (str != "leather armor" && str != "cloak" && str != "skull cap" &&
      str != "boots" && str != "leather gloves" && str != "amulet" &&
      str != "ruby ring")) {
    write(NORM+CYN+"use:  sew [leather armor/cloak/skull cap/boots/leather gloves\n"+
          "           amulet/ruby ring]\n"+NORM);
    return 1;
  }
  skin_obj = present("skin", MY_PLAYER);
  if (!skin_obj) {
    write(NORM+CYN+"You don't have any skins.\n"+NORM);
    return 1;
  }
  skin_strength = skin_obj->query_skin_strength();
  if (str=="leather armor")
    /* 500 per AC for armor; 250 per AC for others */
    /* make it cost 1@10 for needle; 8@250 per thread; AC 4=2010 gold */
    how_much_thread=8;
  else
    /* make it cost 260 */
    how_much_thread=1;
  if (str=="leather armor") required_strength=20;
  if (str=="cloak") required_strength=14;
  if (str=="skull cap") required_strength=12;
  if (str=="boots") required_strength=10;
  if (str=="leather gloves") required_strength=6;
  if (str=="amulet") required_strength=4;
  if (str=="ruby ring") required_strength=2;
  if (skin_strength < required_strength) {
    write(NORM+CYN+"That skin doesn't have enough strength to make "+str+".\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("needle") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (needle).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("thread") < how_much_thread) {
    write(NORM+CYN+"You don't have enough of the appropriate component (thread).\n"+NORM);
    return 1;
  }
  /*
    cost very little SP because the cost is taken up by the gold cost
    (as described in docs) armor=500 gold per AC; others=250 gold per AC;
    + a negligable 10 for the needle
  */
  if (MY_SPELL_POINTS < 5) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("needle", 1);
  MY_POUCH->subtract_quantity("thread", how_much_thread);
  MY_PLAYER->add_spell_point(- 5);
  MY_PLAYER->add_weight(- skin_obj->query_weight());
  destruct(skin_obj);
  if (str=="leather armor") armor_obj=clone_object(ALCHEMIST_LEATHER_ARMOR);
  if (str=="cloak") armor_obj=clone_object(ALCHEMIST_CLOAK);
  if (str=="skull cap") armor_obj=clone_object(ALCHEMIST_SKULL_CAP);
  if (str=="boots") armor_obj=clone_object(ALCHEMIST_BOOTS);
  if (str=="leather gloves") armor_obj=clone_object(ALCHEMIST_LEATHER_GLOVES);
  if (str=="amulet") armor_obj=clone_object(ALCHEMIST_AMULET);
  if (str=="ruby ring") armor_obj=clone_object(ALCHEMIST_RUBY_RING);
  armor_obj->set_size(armor_obj->find_size(MY_PLAYER));
  move_object(armor_obj, MY_ROOM);
  write(NORM+CYN+"You've successfully sewn your skins into a "+str+".\n"+
        "It's sitting on the ground in front of you."+NORM+"\n");
  MY_POUCH->tell_my_room(NORM+CYN+MY_NAME_CAP+
                      " successfully sews some skins into a "+str+".\n"
  return 1;
}
