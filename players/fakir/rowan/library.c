
#include "/room/clean.c"

#define SPEAK(x) write("Sage says: "+x);
#define WRITE(x) write("           "+x);

reset(arg) {
   if(!arg)
     set_light(1);
   extra_reset();
}

extra_reset() {
   object sage;
   if(!present("sage")) {
     sage = clone_object("obj/monster");
     sage->set_name("sage");
     sage->set_short("The Sage of Rowan");
     sage->set_long("The Sage of Rowan is a well respected member of the\n"+
           "town of Rowan.  It is said he knows everything about the areas\n"+
           "surrounding the town.  Even the forbidden areas.\n");
     sage->set_level(9);
     sage->set_wc(14); 
     sage->set_ac(5);
     sage->set_hp(250);
     sage->set_al(200);
     sage->set_chance(60);
     sage->set_spell_mess1("The sage waves his hands in a tight circle.");
     sage->set_spell_mess2("You are hit by a cone of frost!\n");
     sage->set_spell_dam(30);
     move_object(sage, this_object());
   }
}

id(str) { return str == "books" || str == "maps" || str == "map" ||
                 str == "desk"; }

short() { return "The Library of Rowan  [ne]"; }

long(str) {
   if(str == "map" || str == "maps") {
     write("There are a few maps which you may find of interest.\n");
     write("You may view these by typing 'map <region>'.\n");
     write("Regions which have been mapped are:\n");
     write("   Rowan, Drakeshore, Mountain\n");
     return 1;
   }
   if(str == "books") {
     write("After you looking at a couple you find that they are written\n");
     write("in a language unfamiliar to you.\n");
     return 1;
   }
   if(str == "desk") {
     write("The desk is covered in numerous inkstains and scriblings.\n");
     write("Other than that, there is nothing of interest.\n");
     return 1;
   }
   write("You are in the Library of Rowan.  Many rows of books and maps\n");
   write("extend in all directions.  A faint musty smell lingers about the\n");
   write("room.  A small desk lies against the western wall.\n");
   write("The town sage is knowledgable about the history and surrounding\n");
   write("areas of Rowan.\n");
   write("COMMANDS:  ask, map\n");
   write("     There is one obvious exit:  northeast\n");
}

init() {
   add_action("northeast","northeast");
   add_action("ask","ask");
   add_action("map","map");
}

map(str) {
   if(!str) {
     write("You must specify a region: Drakeshore, Rowan, Mountain\n");
     return 1;
   }
   str = lower_case(str);
   if(str == "rowan") {
     cat("/players/molasar/rowan/text/rowan.map");
     return 1;
   }
   if(str == "drakeshore") {
     cat("/players/molasar/rowan/text/drake.map");
     return 1;
   }
   if(str == "mountain") {
      cat("/players/molasar/rowan/text/mount.map");
      return 1;
   }
   write("There is no map of the region: "+str+"\n");
   return 1;
}

ask(str) {
  if(!str) {
   write("The Sage of Rowan is knowledgable about the history of Rowan\n");
   write("and the surrounding areas. You may ask him about the following:\n");
   write("\n");
   write("[History] of the founding of Rowan\n");
   write("[Mordrake] the Great\n");
   write("The [Age] of Peace\n");
   write("The [Overfiend]\n"); 
   write("The [Battle] of Lights.\n");
   write("The [dragon], Andriakas\n");
   write("[Paladins]\n");
   write("[Deadwood] forest\n");
   write("[Hollows] to the south of Rowan\n");
   write("The Silver [Sea] to the west\n");
   write("The [geography] of the area around Rowan\n");
   write("[Recent] town events\n");
   write("\n");
   write("Usage: ask [topic]\n");
   write("\n");
   return 1;
  }
  if(!present("sage")) {
    write("The sage is not here at the moment.  Come back later.\n");
    return 1;
  }
  str = lower_case(str);
  if(str == "history") {
    recite_history();
    return 1;
  }
  if(str == "mordrake") {
    recite_mordrake();
    return 1;
  }
  if(str == "battle") {
    recite_battle();
    return 1;
  }
  if(str == "age") {
    recite_age();
    return 1;
  }
  if(str == "dragon" || str == "andriakas") {
    recite_dragon();
    return 1;
  }
  if(str == "paladins") {
    recite_paladins();
    return 1;
  }
  if(str == "hollows") {
    recite_hollows();
    return 1;
  }
  if(str == "sea") {
    recite_sea();
    return 1;
  }
  if(str == "deadwood") {
    recite_deadwood();
    return 1;
  }
  if(str == "overfiend") {
    recite_overfiend();
    return 1;
  }
  if(str == "geography") {
    recite_geography();
    return 1;
  }
  if(str == "recent") {
    recite_recent();
    return 1;
  }
  SPEAK("I do not know anything about "+str+".\n");
  return 1;
}

northeast() {
   this_player()->move_player("northeast#players/molasar/rowan/w_twn_sq");
   return 1;
}

/*****************************************************************************/
/*  What the sage knows of the surrounding areas/history of Rowan            */
/*****************************************************************************/

/*
 * History of Rowan
 */

recite_history() {
SPEAK("Ah....yes...Rowan's history is one of greatness and sadness.\n");
get_attitude("fond");
SPEAK("Before the coming of Mordrake the Great, the Town of Rowan was\n"); 
WRITE("little more than a village, even less than that. Most of the\n");
WRITE("inhabitants were traders, craftsmen, and farmers. Situatued at\n");
WRITE("the crossroads between many different kingdoms, Rowan was the\n");
WRITE("perfect place for their trades.\n");
get_attitude("remorse");
SPEAK("As with all things...evil also found the town perfect for their\n");
WRITE("trade: pillaging...rape...murder. The few that could leave did,\n");
WRITE("many stayed. They depended on the crossroads to the west for their\n");
WRITE("livelihood, their only means of support. So they banded together\n"); 
WRITE("and created a militia. Poorly armed and poorly trained, they were\n"); 
WRITE("no match for the brigands that attacked. Quickly, their numbers\n");
WRITE("dwindled until only a handful were left. Then came Mordrake.\n");
get_attitude("joy");
SPEAK("He taught them to make good weapons, weapons of iron and steel.\n");
WRITE("He taught them to fight, to build defenses..to protect themselves.\n");  
WRITE("Over the next year, the numbers of the villagers grew and the \n");
WRITE("bandit attacks dwindled. Thus began the Age of Peace.\n");
get_attitude("end");
return 1;
}

recite_age() {
   get_attitude("smoke");
   SPEAK("With the purging of the bandits, the town of Rowan entered\n");
   WRITE("an age of prosperity. Trade increased, the town grew and\n");
   WRITE("became the largest trade center for hundreds of miles.\n");
   WRITE("During this time, Mordrake established the local guild\n");
   WRITE("temple of the Paladins. Roads were built, and a mighty\n");
   WRITE("seaport was built to the west which greatly increased the\n");
   WRITE("towns area of influence.\n");
   return 1;
}

recite_geography() {
   write("\n");
   SPEAK("The town of Rowan is situated at the center of a large open\n");
   WRITE("platuea between many different kingdoms. The\n");
   WRITE("crossroads to the west of the town is the meeting point of\n");
   WRITE("roadways from all over the realm. North of the crossroads\n");
   WRITE("lies the largely unexplored areas of the Deadwood Forest and\n");
   WRITE("the Hollows. To the west lies the Silver Sea and the ruins\n");
   WRITE("of the once magnificent seaport of Drakeshore. The Elkhorn\n");
   WRITE("mountains lie to the south.\n");
   return 1;
}

recite_overfiend() {
get_attitude("sad");
SPEAK("The coming of the Overfiend marks the ending of the Age of Peace.\n");
WRITE("Little is known about whence he came or where he got his powers,\n");  
WRITE("except that he was the most powerful being this land has ever\n");
WRITE("seen. He came in the winter. Almost overnight his black tower\n");
WRITE("sprang up from an isle off the coast of the Salorian Sea, now\n");
WRITE("known as the Silver Sea. The governor of the seaport of Drakeshore\n");  
WRITE("sent men to investigate. He awoke one night to find their\n");
WRITE("mutilated corpses hung from his ceiling.\n");
return 1;
}

recite_battle() {
SPEAK("Word was sent word to Mordrake informing him of the Overfiend.\n");
WRITE("In response Mordrake dispatched a company of Paladins commanded\n");
WRITE("by Baldrek. They were ambushed on the way to Drakeshore by the\n"); 
WRITE("Overfiend's minions. No survivors were found. To punish the\n");
WRITE("'insolent' people, the Overfiend created the dragon\n"); 
WRITE("Andriakas, a most powerful magical beast, to exact punishment.\n");
WRITE("The first night, the entire seaport of Drakeshore was leveled\n");
WRITE("by the Dragons magical breath. Most were killed instantly.\n");
WRITE("The few that survived escaped to the town of Rowan. Mordrake,\n");  
WRITE("fearing that Rowan would be the dragon's next target, discovered\n");
WRITE("its lair and led a company of Paladins to slay the winged-demon.\n");
WRITE("Mordrake returned, alone, a week later, victorious. Gathering all\n");
WRITE("the battle-hardy people he found he set off for the Overfiend's\n"); 
WRITE("dark tower. What ensued next is left to the storytellers, little\n");
WRITE("factual information is known. Throughout the entire night the sky\n");
WRITE("was lit up by their combat. It ended abruptly at the break of\n"); 
WRITE("dawn...a huge explosion which blew apart the upper half of\n"); 
WRITE("the Overfiend's tower. The wind carried the fire and debris to\n"); 
WRITE("the south, setting alight the forest. That was the last anyone saw\n"); 
WRITE("of the Overfiend or Mordrake.\n");
return 1;
}

recite_paladins() {
   write("\n");
   SPEAK("The Paladins are an extremely strict order of fighters\n");
   WRITE("trained to the highest degree in weaponry. They tend to\n");
   WRITE("distrust magic, using only the few spells granted to them.\n");
   WRITE("The Paladins Temple at Rowan was established by Mordrake \n");
   WRITE("during the Age of Peace. It flourished for many years, \n");
   WRITE("and served as the protectors of Rowan.  It is only a small \n");
   WRITE("glimmer of what it was before the coming of the Overfiend.\n");
   WRITE("I recommend you go to the Paladin's Guild if your wish to\n");
   WRITE("know more of their founding.\n");
   return 1;
}

recite_dragon() {
   write("\n");
   SPEAK("The Great Dragon Andriakas, perhaps the most foul beast\n");
   WRITE("to ever live, was created by the Overfiend to harass the\n");
   WRITE("town of Rowan. He was eventually defeated by a band of Paladins\n"); 
   WRITE("led by Mordrake at his lair in the Elkhorn Mountains. There\n"); 
   WRITE("were reports among some of the agents of the Overfiend\n");
   WRITE("that the dragon was given the power to return to this\n");
   WRITE("plane of existence after being destroyed.  These are most\n");
   WRITE("likely rumours invented to frighten children.\n");
   return 1;
}

recite_deadwood() {
   write("\n");
   SPEAK("It was once a lush and green forest. When the tower of the\n");
   WRITE("Overfiend was destroyed it caused the forest to blaze. All\n");
   WRITE("life within was destroyed, only evil from the Hollows dwell\n");
   WRITE("there now.  Few men or beasts dare enter.\n");
   return 1;
}

recite_hollows() {
   write("\n");
   get_attitude("smoke");
   SPEAK("Little is known about the Hollows, the spawning ground of the\n");
   WRITE("Overfiend. It is a placed filled with evil and vile\n");
   WRITE("creatures, creatures which can place curses on mortals or\n");
   WRITE("suck the life from them.  None who have entered ever returned.\n");
   return 1;
}

recite_sea() {
   write("\n");
   SPEAK("The Salorian Sea, as it was originally known, was the purest\n");
   WRITE("water in the realm. It was widely known for it's bounty of\n");
   WRITE("of freshwater game. It is now polluted and stained with evil\n");
   WRITE("as with all things that have come in contact with the\n"); 
   WRITE("Overfiend.  To eat of its food, or drink of i's water\n");
   WRITE("means death.\n");
   return 1;
}

recite_mordrake() {
   write("\n");
   get_attitude("fond");
   SPEAK("It is known that he came from a land far across the sea and\n");
   WRITE("that he had some of his training under the legendary\n");
   WRITE("founder of the Paladins, Gil-Estel. After running off the\n");
   WRITE("bandits he was elected mayor for three terms. During this\n");
   WRITE("time he increased trade and relations with the surrounding\n");
   WRITE("kingdoms, built the seaport Drakshore, and established\n");
   WRITE("this library, the largest collection of information in the\n");
   WRITE("entire realm. What became of him after the battle with the\n");
   WRITE("Overfiend is unknown. Some believe he lies in wait, waiting\n");
   WRITE("to re-emerge and restore the town to its lost glory.\n");
   get_attitude("sad");
   return 1;
}

recite_recent() {
   write("\n");
   SPEAK("After the coming and death of the Overfiend, relations\n");
   WRITE("with the neighboring kingdoms began to dwindle. Just\n");
   WRITE("recently communication has stopped completely. The\n");
   WRITE("dangers seperating us have become too great.\n");
   WRITE("There have been strange reports from all over the land.\n");
   WRITE("Rumors of half men/half dragons in the mountains to the\n");
   WRITE("south. Strange noises and sights coming from lands to the\n");
   WRITE("north. A large increase in banditry has also been noted.\n");
   WRITE("Officials have been sent to investigate, but they have found\n");
   WRITE("nothing.  Some say that the Overfiend is not dead, but\n");
   WRITE("rebuilding his forces. If this were to be true, or if some\n");
   WRITE("beast has risen to assume the Overfiend's identity...\n");
   WRITE("It would spell doom for the people of Rowan.\n");
   return 1;
}

/*****************************************************************************/
/*                    Get the attitude of the Sage                           */
/*****************************************************************************/

get_attitude(str) {
   if(str == "fond") {
     write("The sage leans back against his desk.  A smile plays across "+
           "his face.\n");
   }
   if(str == "joy") {
     write("The sage's eyes light up and he clasps his hands together.\n");
   }
   if(str == "smoke") {
     write("The sage produces a pipe and begins to puff on it.\n");
   }
   if(str == "remorse") {
     write("The sage falls quiet.  A frown spreads across his face as he "+
           "remembers.\n");
   }
   if(str == "end") {
     write("With the story completed, the sage returns to his work.\n");
   }
   if(str == "sad") {
     write("The sage seems to stare off into space his eyes filled "+
           "with sadness.\n");
   }
   if(str == "anger") {
     write("The sages brow deepens and his hands clench uncontrollably at "+
           "his sides.\n");
   }
   return 1;
}

