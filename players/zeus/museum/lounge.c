/*  The Museum of Legendary Warriors -- Arena */
/*
// 2005.08.20 -Forbin
//   removed ability to fight classic golem
// 2005.08.23
//   added up exit to lead to arena observation deck
*/
inherit "room/room";
#include "/players/zeus/closed/all.h"
#include "/players/zeus/museum/lounge.h"
string *sucker;
string *monstart;

reset(arg){
	o1=5;  o2=5; o3=5; o4=5; o5=5; o6=5; o7=5; o8=5, o9=5,
	o666=5;
 if(arg) return;
MO("/players/zeus/museum/OBJ/pilld.c", TO);
 opponent = 0;
 
 monstart = ({ });

 monstart = ({ "/players/zeus/museum/arena/ar1.c",
 	             "/players/zeus/museum/arena/ar2.c",
 	             "/players/zeus/museum/arena/ar3.c",
 	             "/players/zeus/museum/arena/ar4.c",
 	             "/players/zeus/museum/arena/ar5.c",
 	             "/players/zeus/museum/arena/ar6.c",
 	             "/players/zeus/museum/arena/ar7.c",
 	             "/players/zeus/museum/arena/ar8.c" });             

 short_desc="The Museum";
 long_desc=
"This is the lounge area of the museum.  Various plush couches rest up\n"+
"against the walls.  A small podium of electronics sits in the center of\n"+
"the room, with a main panel on the top.  To the north is a large clear\n"+
"window that provides an excellent view of outer space.  A ladder leads\n"+
"upward to a small platform.  Hanging on the west wall is a digital\n"+
"display board.  A soft light is emanating from the ceiling.  The hallway\n"+
"continues to the south.\n";
 set_light(1);
 items=({
 	"ladder",
"A metal pole with rods protruding from each side stands off to one corner\n"+
"of the room.  It leads up to some kind of platform above",
  "platform",
"A metal platform floats high above the lounge",  
	"board",
"The digital board hanging on the west wall is displaying the most recent\n"+
"victors in the museum arena.  You may 'read' the results",
	"walls",
"The walls are made of a perfectly clear material, quite similar to glass.\n"+
"Looking through the walls, the infinite blackness of space can be seen",
	"stars",
"Space is scattered with many tiny stars, all millions of miles away",
	"space",
"Outer space is so black and scatted with stars.  It is very beautiful",
	"ceiling",
"The ceiling is glowing softly, providing light for the hallway",
	"couches",
"The couches are black and look very comfortable",
	"podium",
"The podium is sitting in the middle of the room.  On the top is a panel\n"+
"of electronics, with numerous buttons and switches.  For info on how to\n"+
"use the museum arena type 'arena_help'",
	"panel",
"This is the main control panel to control the arena.  For more info\n"+
"on the museum arena type 'arena_help'",
 });
 dest_dir=({  
 	  "/players/zeus/museum/hall3.c", "south",
 	  "/players/zeus/museum/catwalk.c", "up",
 });
}

void init(){
	::init();
	add_action("help_cmd", "arena_help");
	add_action("select_cmd", "select");
	add_action("list_cmd", "list");
	add_action("start_cmd", "start");
	add_action("read_cmd", "read");
    add_action("reclaim_cmd", "reclaim");
}

read_cmd(str){
  if(str != "board" && str != "results") return 0;
  write("The digital board displays the most recent arena winners:\n\n");
  tail("/players/zeus/log/museum");
  write("\n");
  return 1;
}

query(string str){
  if(!sucker || !sizeof(sucker)) return 0;
  if(index(sucker, str) > -1) return str;
  return 0;
}

reclaim_cmd(){
  object *x;
  string mouse;
  int y;
  if(!query((string)this_player()->query_real_name()))
  {
    write("You have nothing to reclaim.\n");
    return 1;
  }
  if(occupied())
  {
    write("The arena is currently in use.\n");
    return 1;
  }
  clean_arena();
  x = all_inventory("/players/zeus/museum/void.c");
  for(y = 0; y < sizeof(x); y++)
  {
    if(!x[y]->is_living() && !x[y]->is_npc())
      move_object(x[y], "/players/zeus/museum/side_room.c");
  }
  this_player()->move_player("in a flash#/players/zeus/museum/side_room.c");
  return 1;
}

status help_cmd(){
	write(
"\n"+
"A window of text is displayed against the window to the north:\n"+
"Welcome to the Museum of Legendary Warriors.  From this room you can\n"+
"choose a warrior to fight and be transported into the arena.  The\n"+
"arena is 3 rooms by 3 rooms, and you start at the opposite end of\n"+
"the arena as your opponent.\n\n"+
"Commands:\n"+
"'list'\t\t\tA list of the warriors you may challenge.\n"+
"'select <opponent>'\tChoose which warrior you wish to challenge.\n"+
"'start arena'\t\tBegin the simulation fight.\n"+
"'reclaim'\t\tReclaim your equipment if you should die.\n\n"+
"Notes:\n"+
"1) You can die in the arena, so be careful.\n"+
"2) The arena is intended for one on one combat only.\n"+
"3) You may not use the arena if it is already occupied.\n"+
"4) If at any time you wish to leave, type 'exit arena'.\n"+
"5) You may not reenter to continue a fight once you've left.\n"+
"6) After every fight the arena will be entirely cleaned.\n"+
"\n");
	return 1;
}

status list_cmd(){
  write(
    BOLD+"\n\t\tThe Museum of Legendary Warriors\n\n"+NORM+
    "              Name                        Prize\n"+
    BOLD+"1.\t"+NORM+pad("Tol'kor the Ogre Warrior", 30)+
    "Battle Axe of Tol'kor\n"+
    BOLD+"2.\t"+NORM+pad("Tolbrehn the Shadowninja", 30)+
    "Heart of the Shadowninja\n"+
    BOLD+"3.\t"+NORM+pad("Heldurabhoricka the Mage", 30)+
    "Robe of Heldurabhoricka\n"+
    BOLD+"4.\t"+NORM+pad("Jerek the Mutant", 30)+
    "Claws of Jerek\n"+
    BOLD+"5.\t"+NORM+pad("Smasher/Devourer", 30)+
    "HyperPulse Chaingun\n"+
    BOLD+"6.\t"+NORM+pad("Granite Golem", 30)+
    "Granite Staff\n"+
    BOLD+"7.\t"+NORM+pad("The Bug Storm", 30)+
    "Ring of Bug Storm\n"+
    BOLD+"8.\t"+NORM+pad("Enchanted Light", 30)+
    "Dagger of Light\n"+
    BOLD+"9.\t"+NORM+pad("Ani", 30)+
    "Cloak of the Night Sky\n"+
    "\n");
  return 1;
}


status select_cmd(string str){  /*  Choose opponent */
  if(!str) return 0;
  if(TP->query_level() < 15)
  {
    write("You must be at least level 15 to operate the arena.\n");
    return 1;
  }
  if(occupied())
  {
    write("The arena is currently in use.\n");
    return 1;
  }
  clean_arena();

  if((str == "1" || str == "tol'kor") && o1){
    write("You select Tol'kor as your opponent.\n");
    say(TP->QN+" selects Tol'kor as "+TP->POS+" opponent.\n");
    opponent = 1;
  }
  else if((str == "2" || str == "tolbrehn") && o2){
    write("You select Tolbrehn as your opponent.\n");
    say(TP->QN+" selects Tolbrehn as "+TP->POS+" opponent.\n");
    opponent = 2;
  }
  else if((str == "3" || str == "heldurabhoricka") && o3){
    write("You select Heldurabhoricka as your opponent.\n");
    say(TP->QN+" selects Heldurabhoricka as "+TP->POS+" opponent.\n");
    opponent = 3;
  }
  else if((str == "4" || str == "jerek") && o4){
    write("You select Jerek as your opponent.\n");
    say(TP->QN+" selects Jerek as "+TP->POS+" opponent.\n");
    opponent = 4;
  }
  else if((str == "5" || str == "smasher/devourer") && o5){
    write("You select Smasher/Devourer as your opponent.\n");
    say(TP->QN+" selects Smasher/Devourer as "+TP->POS+" opponent.\n");
    opponent = 5;
  }
  else if((str == "6" || str == "golem" || str == "granite golem") && o6){
    write("You select Granite Golem as your opponent.\n");
    say(TP->QN+" selects Granite Golem as "+TP->POS+" opponent.\n");
    opponent = 6;
  }
  else if((str == "7" || str == "bug storm" || str == "storm") && o7){
    write("You select The Bug Storm as your opponent.\n");
    say(TP->QN+" selects The Bug Storm as "+TP->POS+" opponent.\n");
    opponent = 7;
  }
  else if((str == "8" || str == "light" || str == "enchanted light") && o8){
    write("You select Enchanted Light as your opponent.\n");
    say(TP->QN+" selects Enchanted Light as "+TP->POS+" opponent.\n");
    opponent = 8;
  }
  else if((str == "9" || str == "ani") && o9){
    write("You select Ani as your opponent.\n");
    say(TP->QN+" selects Ani as "+TP->POS+" opponent.\n");
    opponent = 9;
  }
/*  
  else if((str == "666") && o666){
    write(RED+
      "You select Classic Granite Golem as your opponent.\n"+NORM);
    say(RED+TP->QN+
      " selects Classic Granite Golem as "+TP->POS+" opponent.\n"+NORM);
    opponent = 666;
  }
*/  
  else if(!o1 || !o2 || !o3 || !o4 || !o5 || !o6 || !o7 || !o8 || !o9 || !o666)
    write("You may not select this opponent again at this time.\n");
  else {
    write("That is not a valid selection.\n");
    return 1;
  }
  return 1;
}

status start_cmd(string str){  /*  Start arena */
  string name;
  if(!str) return 0;
  if(str != "arena") return 0;
  if(TP->query_level() < 15)
  {
    write("You must be at least level 15 to operate the arena.\n");
    return 1;
  }
  if(occupied())
  {
    write("The arena is currently in use.\n");
    return 1;
  }
  if(opponent == 0)
    write("You have not selected an opponent.\n");
  else if(opponent == 1){
    MO(CO("/players/zeus/museum/NPC/tol'kor.c"), 
      monstart[random(sizeof(monstart))]);
    o1 -= 1; }
  else if(opponent == 2){
    MO(CO("/players/zeus/museum/NPC/ninja.c"), 
      monstart[random(sizeof(monstart))]);
    o2 -= 1; }
  else if(opponent == 3){
    MO(CO("/players/zeus/museum/NPC/mage.c"), 
      monstart[random(sizeof(monstart))]);
    o3 -= 1; }
  else if(opponent == 4){
    MO(CO("/players/zeus/museum/NPC/mutant.c"), 
      monstart[random(sizeof(monstart))]);
    o4 -= 1; }
  else if(opponent == 5){
    MO(CO("/players/zeus/museum/NPC/sd.c"), 
      monstart[random(sizeof(monstart))]);
    o5 -= 1; }
  else if(opponent == 6){
    MO(CO("/players/zeus/museum/NPC/golem.c"), 
      monstart[random(sizeof(monstart))]);
    o6 -= 1; }
  else if(opponent == 7){
    MO(CO("/players/zeus/museum/NPC/bug_storm.c"), 
      monstart[random(sizeof(monstart))]);
    o7 -= 1; }
  else if(opponent == 8){
    MO(CO("/players/zeus/museum/NPC/light.c"), 
      monstart[random(sizeof(monstart))]);
    o8 -= 1; }
  else if(opponent == 9){
    MO(CO("/players/zeus/museum/NPC/ani.c"), 
      monstart[random(sizeof(monstart))]);
    o9 -= 1; }
/*    
  else if(opponent == 666){
    MO(CO("/players/zeus/museum/NPC/classic_golem.c"), monstart[random(sizeof(monstart))]);
    o666 -= 1; }
*/    
  else
    write("You have not selected an opponent.\n");
  if(opponent)
  {

/********************* logging ********************************/
    if(1 == opponent)
      name = "Tol'kor";
    else if(2 == opponent)
      name = "Tolbrehn";
    else if(3 == opponent)
      name = "Heldurabhoricka";
    else if(4 == opponent)
      name = "Jerek";
    else if(5 == opponent)
      name = "Smasher/Devourer";
    else if(6 == opponent)
      name = "Granite Golem";
    else if(7 == opponent)
      name = "The Bug Storm";
    else if(8 == opponent)
      name = "Enchanted Light";
    else if(9 == opponent)
      name = "Ani";
/*      
    else if(666 == opponent)
      name = "Classic Granite Golem";
*/      

    write_file("/players/zeus/log/museum_chal", ctime(time())+"   "+
      capitalize((string)TP->QRN)+" challenged "+name+".\n");
/*************************************************************/

    write("You start the arena simulation...\n"+
      "A beam of light wraps around you and moves you into the "+
      "arena.\n\n");
    say(TP->QN+" starts the arena simulation...\n"+
      "A beam of light transports "+TP->QN+" into the arena.\n");
    emit_channel("junk","\n(junk) "+HIY+"["+HIW+"Museum Arena"+HIY+"]"+NORM+" "+
      capitalize((string)this_player()->query_real_name())+
      " has entered to do battle with "+name+".\n\n"+NORM);
    MO(TP, "/players/zeus/museum/arena/ar8.c");
   if(!sucker) sucker = ({ });
    sucker += ({ (string)this_player()->query_real_name(), });
    command("look", TP);
    opponent = 0;
    return 1;
  }
  return 1;
}

