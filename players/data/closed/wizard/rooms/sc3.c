#include "../define.h"
#define DOCS "/players/maledicta/closed/w/library/"
#define WRITEIT write(HIG+"You search the library and compile the following information..."+NORM+"\n")
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Hall of the Warriors");
   set_long(
   "This is the library of the tower.  Several large shelves line the\n"+
   "walls of this room, each covered with long lines of books. A table\n"+
   "sits in the center of the room with several candles on it. A door\n"+
   "leads to the west and into the main hall.\n");
   add_property("NT");
   add_item(({"walls","floor","marble"}),
   "A dull polished stone that is well crafted and cared for by the students");
   add_item("door",
   "Made of a heavy oak, it seems almost unbreakable by normal means");
   add_item("shelves",
   "Long wooden shelves that line the walls. Rows of books are stacked in\n"+
   "a neat line along them");
   add_item("books",
   "Several books that teach the ways of the Warrior. You can use the following\n"+
   "commands here to read them:\n"+
   HIW+"topics"+NORM+"       -  List topics available for reading.\n"+
   HIW+"read <topic>"+NORM+" -  Read the topic"); 
   add_item("table",
   "A large wooden table that stands in the center of the library");
   add_item("candles",
   "Small candles that help to illuminate the area at night");
   add_exit(ROOMS+"sc2","west");
   }

init(){
  ::init();
 add_action("topics", "topics");
 add_action("read", "read");
 }


topics(){
  write(
"The following topics are available for research at this library:\n\n"+
HIR+"  Profession Topics:"+NORM+"\n"+
HIW+"  Assassin       Berserker       Knight       Monk\n"+
"  Paladin      \n"+
HIR+"  Warrior Topics:"+NORM+"\n"+  
HIW+"  Advancement    Skills          Rules        Miscellaneous\n"+
"  Weapons        Offensive       Defensive    \n"+
HIR+"  Other Topics:"+NORM+"\n"+
HIW+"  Join"+NORM+"\n");
   return 1;
   }

read(str){
  if(!str){ write("read which topic?\n"); return 1; }
  if(str == "assassin"){
  WRITEIT;
  cat(DOCS+"assassin");
  return 1;
  }
  else if(str == "berserker"){
  WRITEIT;
  cat(DOCS+"berserker");
  return 1;
  }   
  else if(str == "knight"){
  WRITEIT;
  cat(DOCS+"knight");
  return 1;
  }   
  else if(str == "monk"){
  WRITEIT;
  cat(DOCS+"monk");
  return 1;
  }   
  else if(str == "paladin"){
  WRITEIT;
  cat(DOCS+"paladin");
  return 1;
  }   
  else if(str == "advancement"){
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/advancement.warrior");
  return 1;
  }
  else if(str == "skills"){
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/skills.warrior");
  return 1;
  }
  else if(str == "rules"){
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/rules.warrior");
  return 1;
  }
  else if(str == "miscellaneous"){
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/miscellaneous.warrior");
  return 1;
  }
  else if(str == "offensive"){
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/offensive.warrior");
  return 1;
  }
  else if(str == "defensive"){
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/defensive.warrior");
  return 1;
  }
  else if(str == "weapons"){ 
  WRITEIT;
  cat("/players/maledicta/closed/w/doc/weapons.warrior");
  return 1;
  }
  else if(str == "join"){ 
  WRITEIT;
  cat(DOCS+"join");
  return 1;
  }
  else{ write("That topic is not available.\n"); return 1; }
  return 1;
 }

okay_follow() { return 1; }
query_no_fight() { return 1; }