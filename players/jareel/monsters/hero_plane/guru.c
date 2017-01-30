#include "/players/jareel/ansi.h"
inherit "obj/monster.c";
  
reset(arg)  {

  string str;
  object gold;
    ::reset(arg);
  if(arg) return;

  set_name("darkbeard");
  set_alias("smith");
  set_alt_name("blacksmith");
  set_race("dwarf");
  set_short("Darkbeard - The Blacksmith.");
  set_long(
    "\n"+
    "\n"+
    "\n"+
    "\n"+
    "\n"+
    "\n");  
  set_level(20);
  set_hp(800);
  set_al(0);
  set_wc(50);
  set_ac(52);
  set_aggressive(0);
  set_heart_beat(1);
  set_chat_chance(5);
    load_chat("Darkbeard says: You needs a Matrix?  You have come to the right place.\n");
    load_chat("Darkbeard wipes his brow.\n");
    load_chat("Darkbeard says: Ill fix that weapon.\n");
  gold = clone_object("obj/money");
  gold->set_money(random(2000) + 1000);
  move_object(gold,this_object());
}

init(){
  ::init();
    add_action("ask_me", "ask");
    add_action("askme2", "ask");
    add_action("askme3", "ask");
}



ask_me(str){
  if(!str){ 
    write("Ask who?\n");
  return 1;
  }

  if(str == "darkbeard" || str == "smith" || str == "dwarf"){
    write(
      "Darkbeard says,\n"+
  HIK+"   'You may ask me about any of the quests on the hero plane.\n\n"+
      "    You may also ask me about what it may "+HIW+"cost"+HIK+" you to perform\n"+
      "    one of these mythical quests.'\n\n"+
      "\n"+NORM); 
    return 1;
    }
    write("What are you asking?\n");
    return 1;
}

askme2(str){
  if(!str){ 
    write("Ask who?\n");
  return 1;
  }

  if(str == "dragon" || str == "oroboros" || str == "quest 1"){
    write(
      "Darkbeard says,\n"+
  HIK+"   'The Dragon will fuck you up.\n\n"+
      "    \n"+
      "    \n"+
      "\n"+NORM); 
    return 1;
    }
    write("What are you asking?\n");
    return 1;
}

askme3(str){
  if(!str){ 
    write("Ask who?\n");
  return 1;
  }

  if(str == "cost"){
    write(
      "Darkbeard says,\n"+
  HIK+"   'The shit this will cost ya.\n\n"+
      "    \n"+
      "    \n\n"+
      "\n"+NORM); 
    return 1;
    }
    write("What are you asking?\n");
    return 1;
}

