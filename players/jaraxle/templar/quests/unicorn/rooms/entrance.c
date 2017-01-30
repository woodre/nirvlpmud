#include "/players/jaraxle/define.h"
#define whok present("KnightTemplar", TP)
#define whob present("bard_obj", TP)
inherit "room/room";

int KNIGHT, BARD;
reset(arg) {
   if(arg) return;
   
   BARD = 0;
   KNIGHT = 0;
   set_light(1);
   short_desc = "Western Coastal Plains";
   long_desc =
   "Western plains.\n";
   
   items = ({
         "blah","blah",
});
   
   dest_dir = ({
         "players/jaraxle/templar/quests/unicorn/rooms/cave2.c","blah",
});
   
}


init() {
   ::init();
   add_action("enter","enter");
}

enter(str) {
   
   if(!str) { write("Enter?\n"); return 1; }
   if(str == "caverns" && whob && BARD ==1){ write("Only one Bard may enter the caverns.\n"); return 1; }
   if(str == "caverns" && whok && KNIGHT ==1){ write("Only one Templar may enter the caverns.\n"); return 1; }
   if(str == "cavern" && !BARD && whob){
      write("You grasp your instrument and bravely enter the cavern.\n");
      say(TPN+" grasps "+POS+" instrument and bravely enters the cavern.\n");
      this_player()->move_player("into the cavern#players/jaraxle/templar/quests/unicorn/rooms/cave1.c");
      BARD = 1;  /*  Bard space is full  */
      return 1; }
      
      if(str == "cavern" && !KNIGHT && whok){
         write("You clutch your weapon bravely and enter the cavern.\n");
         say(TPN+" clutches "+POS+" weapon bravely and enters the cavern.\n");
         this_player()->move_player("into the cavern#players/jaraxle/templar/quests/unicorn/rooms/cave1.c");
         KNIGHT = 1;
         return 1; }
         write("You try to enter the dark cavern but some mysterious\n"+
            "force pushes you back.\n");
         return 1; }

