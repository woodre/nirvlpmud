#include "../define.h"
inherit SWAMP

reset(arg) {
   if(arg) return;
   ::reset();
   set_long(
"    Knee-deep in swamp waters, you splash around while you try to\n"+
"move.  Small birds flap overhead, and then disappear back into the\n"+
"thick horizon above your head. Leeches and other disgusting swamp\n"+
"vermin crawl up your leg, diving down into the muck as you bat\n"+
"them away from your body.\n");
   add_exit(ROOM_DIR+"s2","west");
   add_exit(ROOM_DIR+"s16","northeast");
   add_exit(ROOM_DIR+"s3","south");
   add_item(({"leeches","vermin","swamp vermin"}),
      "Disgusting little puddles of goo that think they\n"+
      " can suck your blood ...");
   add_item(({"birds","small birds"}),
      "These small birds soar overhead, and then dive in\n"+
      " occasionally to snatch a fish");
   add_item("waters","The murky, green swamp waters are rich with amphibious\n"+
      " life.  It is deep enough here to splash around"); }

init() {
   ::init();
   add_action("splash","splash"); }

splash(str) {
   object ob;
   string gen;
   if(!str) {
      switch(TP->query_gender()) {
         case "male": gen = "himself"; break;
         case "female": gen = "herself"; break;
         case "neuter": gen = "itself"; break;
      }
      write("You splash some cool, [although green] water upon yourself.\n"+
         "  It feels pretty slimy...\n");
      say(TPN+" splashes some green water on "+gen+"!\n");
      return 1; }
   str = LOWER(str);
   ob = present(str,TO);
   if(!living(ob)) {
      FAIL("You can't splash water upon "+str+", they aren't here!\n");
      return 0; }
   tell_object(ob,TPN+" splashes murky green water all over you!\n"+
      " It feels bizarre...\n");
   say(TPN+" splashes murky green water all over "+CAP(str)+"!\n",ob);
   write("You reach out a hand and splash\n"+
      " the murky green water all over\n"+
      " "+CAP(str)+"!\n");
   return 1; }
