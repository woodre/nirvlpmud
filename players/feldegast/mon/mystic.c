#include "defs.h"

inherit MONSTER;

void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("zytanno");
  set_alt_name("mystic");
  set_alias("man");
  set_short(HIM+"Zytanno"+NORM+" the "+MAG+"Mystic"+NORM);
  set_long(
"Zytanno is a tall, thin man with an impressive demeanor and keen,\n"+
"intelligent eyes.  He wears a turban atop his head and a cape bearing\n"+
"various symbols of the moons and the stars.  For 500 coins, he can tell\n"+
"you your <fortune>.\n");
  set_gender("male");
  set_race("human");
  set_level(10);
  set_hp(140);
  set_wc(14);
  set_ac(8);
  add_money(450);
  set_chat_chance(5);
  load_chat("Zytanno gazes at you dispassionately.\n");
  set_a_chat_chance(5);
  load_a_chat("Zytanno runs about, attempting to flee your blows.\n");
  load_a_chat("Zytanno yells: Help! Help!\n");
}

void init()
{
  ::init();
  add_action("cmd_fortune","fortune");
}

int cmd_fortune(string str)
{
  if(TP->query_money() < 500)
  {
    write("Zytanno says: I do not dispense my services for free.  Come back\nwhen you have some money.\n");
    return 1;
  }
  write("Zytanno holds your hand and closes his eyes...He hums loudly to himself\n"+
        "as passersby watch in vague amusement.  Then, suddenly he opens his\n"+
        "eyes, scratches a note on a piece of paper and folds it into the\n"+
        "shape of a duck.  He hands it to you and suggests you count to your\n"+
        "favorite number before unfolding it to read your fortune.\n");
  TP->remote_say(TPN+" has their fortune read by Zytanno.\n");
  move_object(clone_object("/players/feldegast/obj/origami.c"),TP);
  TP->add_money(-500);
  add_money(500);
  run_away();
  return 1;
}
run_away() {
  int i;
  string str;
  int result;
  for(i=0; i < 9 && result==0; i++) {
    switch(random(8)) {
      case 0: str="sword"; break;
      case 1: str="plow"; break;
      case 2: str="sultan"; break;
      case 3: str="farmer"; break;
      case 4: str="gold"; break;
      case 5: str="ruby"; break;
      case 6: str="temple"; break;
      case 7: str="scroll"; break;
    }
    result=command(str,this_object());
  }
}
