/*
  charity.h
*/

#include "/players/nooneelse/Alchemist/lib/defs.h"

/* -------- Send item to guild junk room for other members use ---------- */
charity_item(str) {
  object obj, target_obj;
  string str1, str2, str3, str4;
  int n, weight;

  if (present(ALCHEMIST_PENANCE_MARK, this_player())) {
    write(NORM+CYN+"You cannot use that skill while you are doing penance.\n"+NORM);
    return 1;
  }
  if (MY_PLAYER->query_ghost()) {
    write(NORM+CYN+"How can you do anything? You are a ghost!\n"+NORM);
    return 1;
  }
  if (!str) {
    n=0;
    call_other(ALCHEMIST_DONATION, "???", 0);
    target_obj=find_object(ALCHEMIST_DONATION);
    obj=first_inventory(target_obj);
    while (obj) {
      if (obj->short()) {
        if (!n) write(NORM+CYN+"Contents of the Guild Donation Room:\n"+NORM);
        write(NORM+CYN+obj->short()+"\n"+NORM);
        n=1;
      }
      obj=next_inventory(obj);
    }
    if (!n) write(NORM+CYN+"The Guild Donation Room is empty.\n"+NORM);
    return 1;
  }
  if (MY_GUILD_RANK < 60) {
    write(NORM+CYN+"You can't use that abilitiy yet.\n"+NORM);
    return 1;
  }
  target_obj=present(str, MY_PLAYER);
  if (!target_obj) {
    write(NORM+CYN+"You don't have '"+str+"' to send to the junk room.\n"+NORM);
    return 1;
  }
  if (MY_ROOM->realm()=="NT") {
    write(NORM+CYN+"You can't do that in this area.\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("arrow") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (arrow).\n"+NORM);
    return 1;
  }
  if (MY_POUCH->query_quantity("mercury") < 1) {
    write(NORM+CYN+"You don't have the appropriate component (mercury).\n"+NORM);
    return 1;
  }
  if (MY_SPELL_POINTS < 50) {
    write(NORM+CYN+"You don't have enough spell points.\n"+NORM);
    return 1;
  }
  MY_POUCH->subtract_quantity("arrow", 1);
  MY_POUCH->subtract_quantity("mercury", 1);
  MY_PLAYER->add_spell_point(- 50);
  call_other(ALCHEMIST_DONATION, "???", 0);
  str1=target_obj->short();
  str1=str1+"...";
  str2=0;
  str3=0;
  if (str1 && sscanf(str1, "%sworn%s", str2, str4)==2)
    target_obj->remove(str);
  if (str1 && sscanf(str1, "%swielded%s", str3, str4)==2)
    target_obj->stopwield(str);
  weight=target_obj->query_weight();
  if (!weight) weight=0;
  MY_PLAYER->add_weight(-weight);
  move_object(target_obj, ALCHEMIST_DONATION);
  MY_FANGS->tell_my_room(
               NORM+CYN+MY_NAME_CAP+" concentrates for a moment and sends '"+str+
               "' somewhere."+NORM);
  write(NORM+CYN+"You concentrate for a moment and feel your load lighten as the\n"+
        str+" is transported to the guild's hall.\n"+NORM);
  target_obj = find_object(ALCHEMIST_DONATION);
  tell_room(target_obj,
        NORM+CYN+
        "You hear a loud snap, crackle and pop!  As you look around for the\n"+
        "source of the noises, you notice that a '"+str+"' is now laying\n"+
        "in front of you.\n"+NORM);
  return 1;
}
