#define tp this_player()->query_name()
#define lvl this_player()->query_level()
#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "room/room";
#include <ansi.h>
int a, b, c, d;
string msg;

reset(int arg){
if(!present("board")) {
move_object(clone_object("/players/daranath/qualtor/obj/bull_board.c"),this_object());
}
 if(!present("herald")) {
move_object(clone_object(ROOT+"mon/herald.c"),this_object());
}
 if(!arg){

  set_light(1);
short_desc= (BLK+BOLD+"City of Qual'tor "+NORM+"(Central Plaza)");
  long_desc=
"               "+BOLD+"Old Road"+NORM+" (north)\n"+
"               "+BOLD+"East Road"+NORM+" (east)\n"+
"               "+BOLD+"Tiger Lane"+NORM+" (west)\n"+
"The crumbled buildings that surrounded Qual'tors entry have mostly been\n"+
"replaced, although the ruins of the outer wall still remain. Most of the\n"+
"bits of stone are gone, and a newly repaired stone roadway runs\n"+
"north along Old Road. The entry is signifigant to the rebuilding\n"+
"of the city.\n";

items=({
"buildings","The crumbled buildings are being replaced slowly, throughout the City Ward",
"ruins","Many ruins can still be seen through the city",
"stone","Ornate dark grey stone makes up the new roadway",
"roadway","The new roadway has recently been put in place, part of the repairs to City Ward",
"rubble","Most of the rubble has been removed",
"bits","Most of the rubble and bits of stone have been removed",
"wall","The outer wall is still in pieces, and reminder of the warfare from long ago",
"city","City Ward within Qual'tor was the first area reclaimed from the monsters that roamed the city.\n"+
     "It has seen the most repairs, while Ghost Ward and Arena Ward are still in\n"+
     "ruins. The city is yours to explore",
"entry","This is the entrance to Qual'tor. If he is here, ask the herald for more information",
 });

  dest_dir=({
   "/players/daranath/qualtor/old_road1.c","north",
   "/players/daranath/qualtor/wayin2.c","south",
   "/players/daranath/qualtor/east_road1.c","east",
   "/players/daranath/qualtor/merch_way.c","west",
           });
  }   }
init(){
 ::init();
add_action("search","search");
add_action("herald_ask","ask");
add_action("herald_info","info");
add_action("herald_story","story");
add_action("herald_advice","suggest");
/*
add_action("herald_map","map");
*/
}

search() {
write("The area has been cleared of debris, leaving nothing much to search.\n");
say (tp +" searches the area\n");
 return 1;  }

herald_info() {
if(!present("herald")) {
write("I'm sorry, but the Herald of Qual'tor is not currently present.\n");
return 1; }
write(HIB+"(--------------------------------------------)"+NORM+"\n");
write(HIW+"          The Herald of Qual'tor"+NORM+"\n");
write(HIB+"(--------------------------------------------)"+NORM+"\n");
write("\n");
write("You can <"+HIW+"ask"+NORM+"> him for information\n");
write("He can <"+HIW+"suggest"+NORM+"> where you can find adventure\n");
write("He can give you a <"+HIW+"story"+NORM+"> about Qual'tor\n");
/*
write("You can purchase a <"+HIW+"map"+NORM+"> of the city (25 coins)\n");
write(HIY+"         Map Coming Soon   -Dar"+NORM+"\n");
*/
write(HIB+"(--------------------------------------------)"+NORM+"\n");
return 1;
}

herald_story() {
if(!present("herald")) {
write("I'm sorry, but the Herald of Qual'tor is not currently present.\n");
return 1; }
write("The Herald says: The best stories are the one that you make!\n");
return 1;
}

herald_advice() {
if(!present("herald")) {
write("I'm sorry, but the Herald of Qual'tor is not currently present.\n");
return 1; }
say(tp+" gets some advice from the Herald of Qual'tor.\n");
if(lvl < 6) {
  b = random(2);
if(b == 0) {write("\n");
write("The Herald of Qual'tor says: The old stables are infested with Scurry Rats.\n"+
      "     Follow East Road torwards the new market and clean them out.\n");
write("\n");   return 1; }
if(b == 1) {write("\n");
write("The Herald of Qual'tor says: Deep in the DarkenWood, a group of kobolds \n"+
      "     have set up a small village. These evil humanoids must be taken\n"+
      "     care of. Travel southwest of the city to find them.\n");
write("\n");   return 1; }   }
if((lvl > 5) && (lvl < 11)) {
  b = random(3);
if(b == 0) {write("\n");
write("THe Herald of Qual'tor says: The various groups of fanatics that call\n"+
      "     themselves the Children of Qual'tor have gotten out of hand.\n"+
      "     They need to be dealt with.\n");
write("\n");  return 1; }
if(b == 1) {write("\n");
write("The Herald of Qual'tor says: Qual'tors UnderCity has recently been \n"+
      "     rediscovered. Efforts are under way to excavated the remainder of\n"+
      "     it. Head for Scimitar Alley to find it.\n");
write("\n");   return 1;  }
if(b == 2) {write("\n");
write("The Herald of Qual'tor says: A small cave east of the DarkenWood holds\n"+
      "     one of the many enterances to the UnderDark itself. Perhaps you\n"+
      "     can find adventure within its upper levels.\n");
write("\n");   return 1; }    }
if((lvl > 10) && (lvl < 16)) {
  b = random(3);
if(b == 0) {write("\n"); 
write("The Herald of Qual'tor says: Far to the Northeast, the old Arena has\n"+
      "     recently been rediscovered. Follow Shield Street to \n"+
      "     Arena Way far to the north.\n");
write("\n");  return 1; }
if(b == 1) {write("\n"); 
write("The Herald of Qual'tor says: The Garden and Graveyard around the keep\n"+
      "     holds many dangers, only the strong should go there.\n"+
      "     Follow Old Road north to the Ruined Keep in Ghost Ward.\n");
write("\n");  return 1; }
if(b == 2) {write("\n"); 
write("The Herald of Qual'tor says: The lost continent of Gundar exsists within\n"+
      "     the northern realms of the city. Search for the magic portal.\n");
write("\n");  return 1; }   }
if((lvl > 15) && (lvl < 20)) {
  b = random(4);
if(b == 0) {write("\n");
write("The Herald of Qual'tor says: The Red Tower in the northwestern corner of\n"+
      "     Head west to Children's Pathway then follow it northwards.\n");
write("\n");  return 1;  }
if(b == 1) {write("\n");
write("The Herald of Qual'tor says: The ruins of the Crystalline Tower \n"+
      "     hold many evils. Follow old road due north to the ruins.\n");
write("\n");  return 1;  }
if(b == 2) {write("\n");
write("The Herald of Qual'tor says: West of the city stands Storm Mountain\n"+
      "     upon which the old Geomancer Guild used to stand. Other dangers\n"+
      "exsist there, only the hardiest of adventurors should attempt.\n");
write("\n");  return 1;  }
if(b == 3) {write("\n");
write("The Herald of Qual'tor says: The Citadel of the Black Zodiac used to\n"+
      "     stand within the city itself. The warfare that plagued the city\n"+
      "     blocked the citadel from being explored, but rumors have it\n"+
      "being excavated soon.\n");
write("\n");  return 1; }   }
if(lvl > 19) {write("\n");
write("The Herald of Qual'tor looks you over and says: You sure you shouldn't\n"+
      "     be coding something instead of killing stuff in Dar's area?\n");
write("\n");   return 1; }
}

/*
herald_map() {
write("The map is coming soon, when Daranath gets it working properly.\n");
return 1;
}
*/

herald_ask() {
  c = random(17);
if(c == 0) {msg = "The Keeper of the RedTower used to sit\n     on Qual'tors Council, before the downfall of the city."; }
if(c == 1) {msg = "Shou Lung stole the spear Gungir\n     from the halls of Asgard itself."; }
if(c == 2) {msg = "Tauros was the grand champion of Qual'tor Arena\n     before the warfare cause the collapse of the Arena itself."; }
if(c == 3) {msg = "The Ghost Ward is currently overrun\n     with the Undead Coils and Drifters, monsters that make it dangerous\n     to even walk through there."; }
if(c == 4) {msg = "The City Ward was the first ward designated\n     for reconstruction. The Paladins of the city made sure it was\n     clear and currently watch over its borders."; }
if(c == 5) {msg = "Arena Ward is home to the old Arena\n     and ruled by Tauros, the Minotaur Champion."; }
if(c == 6) {msg = "The ruined Geomancer hall still stands\n     deep within Storm Mountain. The Geomancers themselves used to sit\n     upon the council, until the Keeper threw them from the city."; }
if(c == 7) {msg = "The Bone Market is located in the UnderCity.\n     Go find Xion the Scholar for more information as to the mini guild."; }
if(c == 8) {msg = "The Crystalline Tower used to house the council\n     itself, before it was brought down during the warfare\n     that tore apart the city."; }
if(c == 9) {msg = "The Kobold village deep within the DarkenWood\n     is nothing more then an annoyance for seasoned adventurors"; }
if(c == 10){msg = "Storm Mountain sits to the west of Qual'tor\n     A home for monsters both dangerous and deadly,"; }
if(c == 11){msg = "Qual'tors UnderCity consists of the old sewer\n     system and various small chambers built into the walls."; }
if(c == 12){msg = "Monsters abound in the DarkenWood,\n     located southwest of the city itself."; }
if(c == 13){msg = "The Necromancers used to have a strong\n     influence over the ruling council here in Qual'tor. That\n     political muscle is long gone, and they now house themselves within\n     the Dryant Graveyard in a far off place."; }
if(c == 14){msg = "A new tower is being built along the\n     western perimeter of the city. Rumors have a new group\n     of Mages claiming that tower for their home."; }
if(c == 15){msg = "The new MarketPlace here within the city\n     has recently opened for business. Follow the East Road\n     to the Market Pathway to get there."; }
if(c == 16){msg = "The RedTower used to be home to the Lord\n     of Qual'tor, before he had the keep itself built."; }
write("The Herald of Qual'tor says: "+msg+"\n");
return 1; 
}

