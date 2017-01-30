/*
  charity_item.h
*/

#include "defs.h"

/* -------- Send item to guild junk room for other members use ---------- */
charity_item(str) {
  object obj, target_obj;
  string str1, str2, str3, str4;
  int n, weight;
  if (!str) {
    n=0;
    call_other(GUILD_CHARITY, "???", 0);
    target_obj=find_object(GUILD_CHARITY);
    obj=first_inventory(target_obj);
    while (obj) {
      if (obj->short()) {
        if (!n) write("Contents of the Guild Charity Room:\n");
        write(obj->short()+"\n");
        n=1;
      }
      obj=next_inventory(obj);
    }
    if (!n) write("The Guild Charity Room is empty.\n");
    return 1;
  }
  target_obj=present(str, MY_PLAYER);
  if (!target_obj) {
    write("You don't have '"+str+"' to send to the junk room.\n");
    return 1;
  }
  if (MY_ROOM->realm()=="NT") {
    write("You can't do that in this area.\n");
    return 1;
  }
  call_other(GUILD_CHARITY, "???", 0);
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
  move_object(target_obj, GUILD_CHARITY);
  MY_FANGS->tell_my_room(
               MY_NAME_CAP+" concentrates for a moment and sends '"+str+
               "' somewhere.");
  write("You concentrate for a moment and feel your load lighten as the\n"+
        str+" is transported to the guild's hall.\n");
  target_obj = find_object(GUILD_CHARITY);
  tell_room(target_obj,
        "You hear a loud snap, crackle and pop.  As you look around for the\n"+
        "source of the noises, you notice that a '"+str+"' is now laying\n"+
        "in front of you.\n");
  return 1;
}
