#include "/players/francesco/univ/ansi.h"
inherit "obj/monster";
   object gold;
int x, play ;
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
   if(x<6) call_out("narrate",15);
   else { play = 0; x = 0; }
   return 1; }

narrate_it() {
   string lyric1,lyric2,lyric3;
   switch(x) {      
      case 0: lyric1 = "\n   By the year 2001, overpopulation had replaced the problem of\n"+
                       "starvation but this was ominously offset by the absolute and\n"+
                       "utter perfection of the weapons.  Hundreds of giant bombs had\n";
              lyric2 = "been placed in perpetual orbit above  the Earth.  They were\n"+
                       "capable of incinerating the entire Earth's surface from an\n"+
                       "altitude of 100 miles.\n";
              lyric3 = " \n";break;
      case 1: lyric1 = "   Matters were further complicated by the presence of twenty \n"+
                       "seven nations in the nuclear club.  There had been no deliberate\n"+
                       "or accidental use of nuclear weapons since World War II and some\n";
              lyric2 = "people felt secure in this knowledge.  But to others, the \n"+
                       "situation seemed comparable to an airline with a perfect safety\n"+ 
                       "record, in showed admirable care and skill, even though no one\n";
              lyric3 = "could reasonably expect it to last forever.\n\n";break;
      case 2: lyric1 = "   Space Shuttle 5 had been used in the past also for interplanetary\n"+
                       "voyages which eventually could last several months.  It was later\n"+
                       "replaced by more recent vehicles which were designed with different\n";
              lyric2 = "concepts according to the natural evolution of the technology.\n";
              lyric3 = "\n";break;        
      case 3: lyric1 = "   Space Shuttle 5 had then become the standard Earth to Moon\n"+
                       "vehicle.  It was powered  by low-thrust plasma jets which would\n"+
                       "continue  the mild acceleration for fifteen minutes.  Then the\n";
              lyric2=  "ship would break the bonds of gravity and be like a free and\n"+
                       "independent planet, travelling the space.  It would then land\n"+
                       "the Moon under pilot's control but without the thrust of the\n";
              lyric3 = "engines.\n\n";break;
      case 4: lyric1 = "   The internal layout of the transporter allowed for great \n"+
                       "relax and enjoyment during the travel.  The lounge was equipped\n"+
                       "with comfortable couches and the bar was stocked with both new\n";
              lyric2 = "beverages and fresh foods on a weekly basis.  The crew was \n"+
                       "choosen within the people with the most polite and efficient\n"+
                       "characteristics from the best restaurants and hotels. Therefore,\n";
              lyric3 = "all this led to a great pleasure for the travellers during\n"+
                       "the trip.\n\n";break;
      case 5: lyric1 = HIR+"The Narrator closes his eyes and returns to his deep thoughts.";
              lyric2 = "";
              lyric3 = "\n";break;}

      tell_room(environment(this_player()),HIW+lyric1+NORM);
      tell_room(environment(this_player()),HIW+lyric2+NORM);
      tell_room(environment(this_player()),HIW+lyric3+NORM);
   return 1; }
