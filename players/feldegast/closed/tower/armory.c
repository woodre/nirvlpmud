#include "defs.h"

inherit ROOM;

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Crystal Tower Armory";
  long_desc=
"  This is the Crystal Tower's armory.  The walls are lined with\n"+
"all kinds of weapons and armor.  A wooden door to the south leads\n"+
"back out.\n"+
"Commands: list, grab\n";
  items=({
  });
  dest_dir=({
    PATH+"tower2.c","north",
  });
}

void init() {
  ::init();
  add_action("cmd_list", "list");
  add_action("cmd_grab", "grab");
}

cmd_list(str) {
  write(
"1. Armor pack (ac8)\n"+
"2. Armor pack (ac12)\n"+
"3. Soulthief\n"+
"4. Summersword\n"+
"5. 2 Nectar, 2 Pie, 1 Zin\n"+
"6. Coins\n"
  );
  return 1;
}

cmd_grab(str) {
  int num;
  if(member_array(TP->query_real_name(),TESTERS)==-1) {
    write(TPRN+", you are not a tester.\n");
    return 1;
  }
  num=atoi(str);
  if(num < 1 || num > 6) {
    write("You can't grab that.\n");
    return 1;
  }
  switch(num) {
    case 1:
      move_object(clone_object(ARM_PATH+"boots.c"),TP);
      move_object(clone_object(ARM_PATH+"helmet.c"),TP);
      move_object(clone_object(ARM_PATH+"gauntlet.c"),TP);
      move_object(clone_object(ARM_PATH+"amulet.c"),TP);
      move_object(clone_object(ARM_PATH+"silv_shield.c"),TP);
      move_object(clone_object(ARM_PATH+"feathercloak.c"),TP);
      move_object(clone_object(ARM_PATH+"mail.c"),TP);
      break;
    case 2:
      move_object(clone_object(ARM_PATH+"boots.c"),TP);
      move_object(clone_object(ARM_PATH+"ghelm.c"),TP);
      move_object(clone_object(ARM_PATH+"gauntlet.c"),TP);
      move_object(clone_object(ARM_PATH+"amulet.c"),TP);
      move_object(clone_object(ARM_PATH+"starshield.c"),TP);
      move_object(clone_object(ARM_PATH+"mcloak.c"),TP);
      move_object(clone_object(ARM_PATH+"wyvern_armor.c"),TP);
      break;
   case 3:
      move_object(clone_object(WEP_PATH+"soulthief.c"),TP);
      break;
   case 4:
      move_object(clone_object(WEP_PATH+"summer.c"),TP);
      break;
   case 5:
      move_object(clone_object(HEAL_PATH+"nectar.c"),TP);
      move_object(clone_object(HEAL_PATH+"pecan_pie.c"),TP);
      move_object(clone_object(HEAL_PATH+"nectar.c"),TP);
      move_object(clone_object(HEAL_PATH+"pecan_pie.c"),TP);
      move_object(clone_object(HEAL_PATH+"zinfandel.c"),TP);
      break;
   case 6:
     this_player()->add_money(80000);
     break;
  }
  write("You withdraw #"+num+" from the armory.\n");
  say(TPN+" withdraws something from the armory.\n");
  return 1;
}


      