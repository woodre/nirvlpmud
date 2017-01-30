/* -------- Defile ---------- */
/*
  defile_object.h
*/

#include "defs.h"

defile_object(str) {
  string s1, s2, s3;
  object target_obj;
  if (!str) {
    write("You must name the item to be defiled.\n");
    write("Use: defile <item>\n");
    return 1;
  }
  if (MY_LEVEL < 1 || MY_GUILD_EXP < 666) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  if (MY_SPELL_POINTS < 5) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 5);
  target_obj=present(str, MY_PLAYER);
  if (!target_obj) {
    write("You don't have anything by that name to defile.\n");
    return 1;
  }
  s3=0;
  if (target_obj->short()) s3=target_obj->short();
  if(!s3) s3="gunk and junk";
  if (target_obj->id("holy item") ||
      target_obj->id("cross") ||
      target_obj->id("crucifix") ||
      target_obj->id("garlic") ||
      target_obj->id("holy water") ||
      target_obj->id("bible") ||
      sscanf(s3, "holy %s", s1)==1 ||
      sscanf(s3, "cross %s", s1)==1 ||
      sscanf(s3, "crucifix %s", s1)==1 ||
      sscanf(s3, "garlic %s", s1)==1 ||
      sscanf(s3, "bible %s", s1)==1 ||
      sscanf(s3, "%s holy", s1)==1 ||
      sscanf(s3, "%s cross", s1)==1 ||
      sscanf(s3, "%s crucifix", s1)==1 ||
      sscanf(s3, "%s garlic", s1)==1 ||
      sscanf(s3, "%s bible", s1)==1 ||
      sscanf(s3, "%s holy %s", s1, s2)==2 ||
      sscanf(s3, "%s cross %s", s1, s2)==2 ||
      sscanf(s3, "%s crucifix %s", s1, s2)==2 ||
      sscanf(s3, "%s garlic %s", s1, s2)==2 ||
      sscanf(s3, "%s bible %s", s1, s2)==2) {
    destruct(target_obj);
    write("You scream some gutteral words ant the "+str+"\n"+
          "disappears in a ball of fire.\n");
    MY_FANGS->tell_my_room(
                MY_NAME_CAP+" screams some gutteral words and the "+str+"\n"+
                "disappears in a ball of fire.");
    MY_PLAYER->add_exp(50);
    MY_PLAYER->add_alignment(- 50);
    write("You are granted some experience for this marvelous act!\n");
    return 1;
  }
  write("That's not positively identified as a holy item, "+
        "even if it looks like one.\n");
  return 1;
}
