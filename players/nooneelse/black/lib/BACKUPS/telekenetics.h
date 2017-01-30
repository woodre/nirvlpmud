/*
  telekenetics.h
*/

#include "defs.h"

/* --------------- Pick Locks --------------- */
telekenetics(str) {
  int success_percent;
  object stuff, door_obj;
  string tmp, str2, str3;
  if (MY_LEVEL < 10 || MY_GUILD_EXP < 669) {
    write("You can't use that abilitiy yet.\n");
    return 1;
  }
  /* base chance */
  success_percent = 5 + (MY_LEVEL * 3);
  /* dex & int adjustments */
  if (MY_INT > MY_LEVEL) success_percent += 5;
  if (MY_STE < MY_LEVEL) success_percent -= 2;
  /* if wielding a weapon &/or wearing a shield &/or gauntlets, lower chances */
  stuff=first_inventory(MY_PLAYER);
  while (stuff) {
    tmp=stuff->short();
    str2=0;
    str3=0;
    if (tmp) {
      if (sscanf(tmp, "%sworn", str2) || sscanf(tmp, "%swielded", str3))
        if (tmp == "gloves" || tmp == "shield")
          success_percent -= 5;
    }
    stuff=next_inventory(stuff);
  }
  door_obj=0;
  stuff=first_inventory(MY_ROOM);
  while (stuff) {
    str=0;
    str=stuff->short();
    if (str) {
      sscanf(str, "%sdoor", str2);
      if (str2) {
        if (!door_obj) door_obj=stuff;
      }
    }
    stuff=next_inventory(stuff);
  }
  if (!door_obj) {
    write("Pick the lock on what door?\n");
    return 1;
  }

  /* now do it */
  if (MY_SPELL_POINTS < 5) {
    write("You don't have enough spell points.\n");
    return 1;
  }
  MY_PLAYER->add_spell_point(- 5);
  if (success_percent >= random(100)) {
    door_obj->set_locked(0);
    write("You did it!  You can open it now.\n");
  }
  else {
    write("You failed!  Darn!  You almost had it too!\n");
  }
  return 1;
}
