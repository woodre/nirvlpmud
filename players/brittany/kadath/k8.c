#include "/players/brittany/ansi"
#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

int mob;
reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc = MAG+"Kadath"+NORM;
   long_desc =
   "     The steps are made out of stone and twist downward out of sight.\n"+
   "Mounted on the walls are some handrails made out of twisted rope.  A\n"+
   "small lantern sits in the corner of the steps\n";
   
   items = ({
         "steps","The steps are wide and made of stone, a small\n"+
         "lantern sits in the corner",
         "lantern","A candle is encased into a dome shaped case,\n"+
         "there is a switch on the bottom",
         "case","The case is made of brass and domed shaped",
         "candle","The candle is white and has a short stem",
         "switch","The switch is round and written on one side\n"+
         "is the word: LIGHT, maybe you should 'turn' it",
         "walls","The walls are made of basalt and are warm to the touch",
         "handrails","The handrails are made of twisted rope",
         "rope","The rope is twisted and mounted on the walls for handrails",
         "twisted rope","The rope is twisted and mounted on the walls for handrails",
});
   
   dest_dir = ({
         "/players/brittany/kadath/k7.c","up",
         "/players/brittany/kadath/k9.c","down",
});
}
init(){
   ::init();
   add_action("down","down");
   add_action("up","up");
   add_action("turn","turn");
   add_action("search","search");
}

down(str){
   write("A chill rushes the air...\n\n"+
      
      "You continue down the steps.  Then, as in a dream, everything\n"+
      "pauses and changes its course.  The dream vaguely calls up\n"+
      "glimpses of a long forgotten first youth, when wonder and\n"+
      "pleasure existed.\n\n");
   say(tpn+"  continues down the steps.\n");
   tp->move_player("down#/players/brittany/kadath/k9.c");
   return 1; }

up(str){
   write("You walk up the steps.  You are back in the small\n"+
      "cavern room at the top of the stairs.\n\n");
   say(tpn+"  walks up the steps.\n");
   tp->move_player("up#/players/brittany/kadath/k7.c");
   return 1; }

search(){
   notify_fail("You find nothing of interest.\n");
   return 0;
}

turn(str) {
   if(!str || str != "switch") {
      notify_fail("What do you want to turn?\n");
      return 0; }
   write(
      "The lantern sparks then lights up the stairs.\n");
   say(tpn+"  lights the lantern.\n");
   if(!mob) { move_object(clone_object("/players/brittany/kadath/NPC/cavewight.c"), this_object()); mob = 1; }
   return 1;
}
