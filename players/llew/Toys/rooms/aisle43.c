#define NQC room

inherit "room/room";

reset(arg) {
   if(arg) return;
   set_light(1);
   short_desc="S.K. Toys 'n Stuff";
   long_desc=
      "    The back wall of the store is pasted with games\n"+
      "of all types, capturing the childrens anticipation, \n"+
      "anxious to spend thier hours in competition. Strategy\n"+
      "games of old and board games of chance are displayed \n"+
      "with their traits of entertainment.  The spin of the\n"+
      "wheel and the roll of the dice rattle in the childrens'\n"+
      "minds as they gaze upward at the marvel of games.\n";
   dest_dir=({
      "/players/llew/Toys/rooms/aisle33","north",
      "/players/llew/Toys/rooms/aisle42","east",
      "/players/llew/Toys/rooms/aisle53","south",
   });
   items=({
      "children",
         "The minds of the youth race with the strategy and fun ahead",
      "games",
         "Chess, checkers, Monopoly, Chutes 'n Ladders, Risk, Candyland,\n"+
         "card games, Yachtzee, and all games imaginable are spread the\n"+
         "length of the wall",
   });
}

