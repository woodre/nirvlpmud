#include "defs.h"

inherit MONSTER;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("balin");
  set_alt_name("sakadi");
  set_short("Balin Sakadi");
  set_long(
"Balin Sakadi is the middle of the three Sakadi brothers, and\n"+
"has the honor of being the second least incompetent of them.\n"+
"He manages this store for his elder brother, Abdullah Sakadi.\n"+
"He has a cleft chin, and wears the fine silks and turban of\n"+
"an upper class merchant.\n"
  );
  set_gender("male");
  set_race("human");
  set_level(10);
  set_wc(14);
  set_ac(8);
  set_hp(150);
  set_al(150);
  set_chat_chance(5);
  load_chat("Balin gives you a strained smile.\n");
  load_chat("Balin says through gritted teeth: How can I help you?\n");
  load_chat("Balin mutters something to himself.\n");
  set_a_chat_chance(4);
  load_a_chat("Balin shouts for help!\n");
  load_a_chat("Balin yells: Help!  HELP!\n");
  load_a_chat("Balin yells: Guards!  Guards!\n");
  add_money(450);
  add_talk("abdullah",
           "Balin says: My brother lives nearby.  If you wish to see him, knock\n"+
           "  on his door and say: And hit the Sultan's cat.\n");  
  add_talk("calis",
           "Balin says: My younger brother is a fool.  He wants to be a            warrior.\n"+
"  Can you imagine a Sakadi as a warrior?  What nonsense!\n");
  add_talk("sultan", "Balin says: I have never seen the Sultan.\n");
  add_talk("sudakan", "Balin says: It is a good city for trading.\n");
  add_talk("jikhal", "Balin says: He runs a mercenary company here.  Scary fellow.\n");
  add_talk("brigands", "Balin says: I know that brigands have been a problem lately,\n"+
                       "  but I rarely venture outside of the city.\n");
  add_talk("gods", "Balin says: Superstitious nonsense.\n");
  add_talk("statues", "Balin says: They are as old as the city.  Perhaps they are of\n"+
                      "  Majiri manufacture.\n");
  add_talk("majiri", "Balin says: The Majiri civilization collapsed hundreds of years\n"+
                     "  ago.  They built this city shortly before their civilization\n"+
                     "  died.  Nobody knows why.\n");
  add_talk("sakadi", "Balin says: We are a family of traders, going back four generations.\n"+
                     "  My brother, Abdullah and I have turned our business into an empire,\n"+
                     "  trading from Chalynsta to the Far Isles.\n");
  add_talk("bottle", "Balin says: The bottle is a rare artifact of unusual beauty, found in\n"+
                     "  an excavation deep in the desert.  It is a bargain, I assure you.\n");
}
