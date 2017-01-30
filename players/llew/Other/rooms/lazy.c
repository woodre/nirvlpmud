#include "/players/llew/closed/ansi.h"

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc=GRN+"Lazy Llew's Bar"+NORM;
   long_desc="\tA dark room lit dimly from the crackling hearth fire.\n"+
     "A counter spread with benches runs the length of the north wall\n"+
      "of the bar.  Comfortable booths graced with merry patrons beckon\n"+
      "you to sit down and relax.  A lethargic peace is in the air.\n"+
      "Go ahead, order up something to wet your whistle and\n"+
      "sit for a spell.\n";
   dest_dir=({"/room/eastroad4.c","east"});
   items=({
      "fire","A fire sputters in the hearth, giving a warm toasty feeling",
      "counter","The counter is well worn with many merry patrons\n"+
         "drinking and eating their fill of the marvelous food.\n"+
         "The oiled wood shines orange from the light of the fire\n"+
         "and the candles spread behind",
      "wall","The green spread wall personifies a living forest in all\n"+
         "it's summer splendor.  Leafy tapestries and collages\n"+
         "make this dim hostel a comforting solace",
      "benches","Heavy benches smooth with long use and loving care",
      "booths","The booths give plenty of privacy to the weary traveller,\n"+
         "or couple wanting some time together",
      "booth","The booths give plenty of privacy to the weary traveller,\n"+
         "or couple wanting to spend some time together",
      "hearth","The large fireplace provides plenty of warmth to\n"+
         "fill the small bar, the stones carved to perfection in artistic grace",
      "wood","The solid oak wood has aged pleasingly.  It is certainly\n"+
         "very well cared for",
      "candles","The candles flicker in their sconces, licking\n"+
         "with their tendril smoke, the dim room",
      "candle","The candle flickers in its sconce, licking\n"+
         "with its tendril smoke, the dim room",
      "tapestries","One scene provides a view of a forest pool,\n"+
         "and giant oak in a clearing surrounded by sylvan\n"+
         "protection.  Light descends through a leafy canopy gracing\n"+
         "the setting in peace.   The other portrays a rather young,\n"+
         "beautiful, blonde, elven maiden gazing towards the\n"+
         "viewer with mischievous intent, the curly golden crown\n"+
         "drifting in a breeze",
      "tapestry","One scene provides a view of a forest pool and\n"+
         "giant oak in a clearing surrounded by sylvan protection\n"+
         "Light descends through a leafy canopy, gracing the\n"+
         "setting in peace.   The other portrays a rather young,\n"+
         "beautiful, blonde, elven maiden gazing towards the\n"+
         "viewer with mischievous intent, the curly golden crown\n"+
         "drifting in a breeze",
   });
   move_object("/players/llew/Other/monsters/llew",this_object());
   move_object("/players/llew/Other/misc/lazy-sign",this_object());
}

query_no_fight() { return 1; }

init() {
   ::init();
   this_player()->stop_fight();
   this_player()->stop_fight();
   add_action("booth","booth");
   add_action("check","check");
   add_action("east","east");
}

east() {
   call_out("llew_wave",5,this_player()->query_real_name());
}

booth(num) {
   if(!num) {
      write("Which booth would you like to enter?\n");
      return 1;
   }
   switch(num) {
      case "1":
      case "2":
      case "3":
      case "4":
         if(call_other("players/llew/Other/rooms/booth"+num,"query_locked",0) == 1) {
            write("Booth "+num+" is locked by it's occupants.\n"+
               "Please try a different one.  To see what booths\n"+
               "are open, type \"check booths\".\n");
            return 1;
         }
         this_player()->move_player("into booth "+num+"#players/llew/Other/rooms/booth"+num);
         return 1;
   }
   write("Please select booth 1-4.\n");
   return 1;
}

check(str) {
   int x,n,o,so;
   object ai;
   x=0;
   if(!str || str != "booths") {
      notify_fail("Check what?\n");
      return 0;
   }
   while(x < 4) {
      x++;
      ai=all_inventory("players/llew/Other/rooms/booth"+x);
      so=sizeof(ai);
      write(BOLD+"Booth "+x+NORM+":");
      if(("players/llew/Other/rooms/booth"+x)->query_locked() == 1) write(RED+"   Locked"+NORM);
      write("\n");
      for(n=0;so>n;n++) {
         if(ai[n]->is_player()) {
            o++;
            write("\t"+capitalize(ai[n]->query_real_name())+"\n");
         }
      }
      if(!o) {
         write("\tEMPTY\n");
         if(("players/llew/Other/rooms/booth"+x)->query_locked() == 1) {
            write(GRN+"Unlocked\n"+NORM);
            ("players/llew/Other/rooms/booth"+x)->lock();
         }
      }
   o=0;
      write("\n");
   }
return 1;
}

llew_wave(person) {
  if(find_player(person)) 
     tell_object(find_player(person),"Llew waves at you from afar.\n");
}
