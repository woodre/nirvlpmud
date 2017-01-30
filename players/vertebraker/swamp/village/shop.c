#include "../define.h"
inherit ROOM;

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Sardka's Fine Jewelry");
   set_long(
"     Many pieces of fine jewelry are on all sides of you in glass\n"+
"display cases.  This place seems oddly out of place in such a\n"+
"run-down village and you wonder if somehow the business has suffered\n"+
"as a result.  A large list of prices is on the wall that you may look\n"+
"at, or you can exit the hut back to the village.\n");
   add_object(NPC_DIR+"sardka");
   add_item(({"pieces","jewelry","fine jewelry","cases",}),
      "Diamond rings...\nEmerald bracelets...\nPearl necklaces...\nOh my");
   add_item(({"list","prices","wall"}),"You can \"read\" the list");
   add_item("village","The village path lies outside this hut");
   add_exit(VILLAGE+"path2","exit"); }

init() {
   ::init();
   add_action("purchase","purchase");
   add_action("purchase","buy");
   add_action("read","read"); }

read(str) {
   if(str == "wall" || str == "list" || str == "the list" || str == "prices") {
      write(
         "\n\n\t\t"+HIG+"!!!"+NORM+"SARDKA'S FINE JEWELRY"+HIG+"!!!"+NORM+"\n\n"+
         "\t1]   Pearl Necklace    - 500 coins\n"+
         "\t2]   Emerald Bracelet  - 700 coins\n"+
         "\t3]   Diamond Ring      - 1500 coins\n"+
         "\t4]   Golden Earring    - SOLD OUT!!\n\n"+
         "\t\t"+HIG+"!!!"+NORM+"Usage: purchase [1-4]"+HIG+"!!!"+NORM+"\n\n");
      say(TPN+" reads the prices.\n");
      return 1; }
}

purchase(str) {
   if(!present("sardka",TO)) {
      write("You can't purchase if Sardka isn't here!\n");
      return 1; }
   if(str == "1") {
      if(TP->query_money() < 500) {
         FAIL("You don't have enough money for that purchase!\n");
         return 0; }
      if(!TP->add_weight(1)) {
         FAIL("You can't carry that!\n");
         return 0; }
      write("You purchase a pearl necklace from Sardka.\n");
      say(TPN+" purchases a pearl necklace from Sardka.\n");
      TP->add_money(-500);
      MO(CO(OBJ_DIR+"necklace"),TP);
      return 1; }
   if(str == "2") {
      if(TP->query_money() < 700) {
         FAIL("You don't have enough money for that purchase!\n");
         return 0; }
      if(!TP->add_weight(1)) {
         FAIL("You can't carry that!\n");
         return 0; }
      write("You purchase an emerald bracelet from Sardka.\n");
      say(TPN+" purchases an emerald bracelet from Sardka.\n");
      MO(CO(OBJ_DIR+"bracelet"),TP);
      TP->add_money(-700);
      return 1; }
   if(str == "3") {
      if(TP->query_money() < 1500) {
         FAIL("You don't have enough money for that purchase!\n");
         return 0; }
      if(!TP->add_weight(1)) {
         FAIL("You can't carry that!\n");
         return 0; }
      write("You purchase a diamond ring from Sardka.\n");
      TP->add_money(-1500);
      say(TPN+" purchases a diamond ring from Sardka.\n");
      MO(CO(OBJ_DIR+"ring"),TP);
      return 1; }
   if(str == "4") {
      tell_room(TO,"Sardka says: \"I'm sorry.. We aren't carrying that at this time.\"\n");
      write("Sardka leans over and says: \"I do believe Juribel carries one though...\n"+
         "He winks at you slyly.\n");
      return 1; }
   write("Sardka says: \"We don't carry that.  Use the numbers please!\"\n");
   return 1; }
