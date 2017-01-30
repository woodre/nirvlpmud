#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";
   object gold;
int x, play;
reset(arg){
   ::reset(arg);
   set_name("narrator");
   set_race("human");
   set_alias("narrator");
      set_short("The Narrator");
     set_long("The Narrator is an old man, with glasses and a notebook on his\n"+
              "hand.  He looks very wise and you might 'ask' him his thoughts.\n"+
              "Once upon a time he also used to 'trade' any item.\n");
   set_level(10);
   set_hp(150);
   set_al(0);
   set_wc(14);
   set_ac(8);
}


init() {
   ::init();
   add_action("ask","ask");
}

ask(str) {
   if(play) { write("Shhhhhh, he is already narrating...\n"); return 1; }
   if(!str) {write("Ask whom?\n"); return 1;}
   if (str!="narrator") {write("Ask whom?\n"); return 1;}
   tell_room(environment(this_player()),HIR+"The narrator clears his throat."+NORM+"\n");
   play = 1; call_out("narrate",3);
   return 1; }

narrate(){
   narrate_it();
   x += 1;
   if(x<5) call_out("narrate",16);
   else { play = 0; x = 0; }
   return 1; }

narrate_it() {
   string lyric1,lyric2,lyric3,lyric4,lyric5;
   switch(x) {      
      case 0: lyric1 = "\n   They started training  about a hundred of crews since they were\n"+
                       "looking for the really best members.  Several different training\n"+
                       "centers had been established, each with a different goal. After\n";
              lyric2 = "about one year of training, six members were choosen and divided\n"+
                       "into three crews.  They were supposed to travel for about five\n"+
                       "years in the deep interplanetary spaces and thus the hibernating\n";
              lyric3 = "techniques were deeply investigated and developped.\n\n";break;
      case 1: lyric1 = "   The technology state-of-the-art Discovery Spacecraft was choosen\n"+
                       "for the trip.  It was equipped with the most modern computers\n"+
                       "and with  the most energy-saving equipments best suited for long\n";
              lyric2 = "term functioning without any maintenance.\n";
              lyric3 = "\n";break;
      case 2: lyric1 = "   The spacecratf was duplicated in the Langley Space Center and it\n"+
                       "was filled with the same equipments and with those crews which\n"+
                       "resulted to be in the same ranking than the choosen ones.  What\n";
              lyric2 = "would have be done on the Spacecraft would have been done in the\n"+
                      "same way on the Earth.  Transmission systems were developped which\n"+
                      "might cut the communication delay,  even at millions miles away.\n";
              lyric3 = "\n";break;
      case 3: lyric1 = "   Several months of trip passed away without any small incident.\n";
              lyric2 = " ";
              lyric3 = "\n";break;
      case 4: lyric1 = HIR+"The Narrator closes his eyes and returns to his deep thoughts.\n";
              lyric2 = "";
              lyric3 = "\n";break;}

      tell_room(environment(this_player()),HIW+lyric1+NORM);
      tell_room(environment(this_player()),HIW+lyric2+NORM);
      tell_room(environment(this_player()),HIW+lyric3+NORM);
return 1; }

