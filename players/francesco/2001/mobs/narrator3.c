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
   if(x<8) call_out("narrate",16);
   else { play = 0; x = 0; }
   return 1; }

narrate_it() {
   string lyric1,lyric2,lyric3,lyric4,lyric5;
   switch(x) {        
      case 0: lyric1 = "\n   The Base at Clavius was the first American Lunar Settlement\n"+
                       "that could, in an emergency, be entirely self-supporting.  Water\n"+
                       "and all the necessities of life for its eleven hundred men,\n";
              lyric2 = "women and children were produced from the Lunar rocks, after\n"+
                       "they had been crushed, heated and chemically processed.\n";
              lyric3 = "";
              lyric4 = "\n";break;
      case 1: lyric1 = "   The laws of Earth aesthetics did not apply on the Moon.  This\n"+
                       "world had been shaped and molded by other than terrestrial forces\n"+
                       "operating over eons of time unknown to the young verdant Earth,\n";
              lyric2 = "with its fleeting Ice-Ages, with its swiftly rising and falling\n"+ 
                       "seas, with its mountain ranges dissolving like mists before the\n"+
                       "dawn.  Here was age inconceivable - but not death - for the Moon\n";
              lyric3 = "had never lived until now.\n";
              lyric4 = "\n";break;
      case 2: lyric1 = "   One of the attractions of life on the Moon was undoubtedly the\n"+
                       "low gravity which produced a sense of general well-being. The\n"+
                       "personnel of the Base at Clavius and their children were the\n";
              lyric2 = "forerunners of new nations, of new cultures that would ultimately\n"+
                       "spread out across the solar system.  They  no longer thought of \n"+
                       "Earth as home.  The time was fast approaching when Earth, like\n";
              lyric3 = "mothers, must say farewell to her children.\n";
              lyric4 = "\n";break;
      case 3: lyric1 = "   A hundred million miles beyond Mars,  in the cold lonliness \n"+
                      "where no man had yet travelled, Deep-Space-Monitor-79 drifts slowly\n"+
                      "among the tangled orbits of the asteroids.  Radiation detectors\n";
              lyric2 = "noted and analyzed incoming cosmic rays from the galaxy and\n"+
                       "points beyond.  Neutron and x-ray telescopes kept watch on strange\n"+
                       "stars that no human eye would ever see.  Magnetometers observed\n";
              lyric3 = "the gusts and hurricanes of the solar winds, as the sun breathed\n"+
                       "million mile-an-hour blasts of plasma into the faces of its\n"+
                       "circling children.\n";
              lyric4 = "\n";break;
      case 4: lyric1 = "   All these things and many others were patiently noted by the\n"+
                       "Deep-Space-Monitor-79, and recorded in its crystalline memory.\n"+
                       "But now it had noted something strange - the faint yet\n";
              lyric2 = "unmistakable disturbance rippling across the solar system, and\n"+
                       "quite unlike any natural phenomena it had ever observed in the\n"+
                       "past.\n";
              lyric3 = "";
              lyric4 = "\n";break;  
      case 5: lyric1 = "   It was also observed by OrbiterM-15, circling Mars twice a\n";
              lyric2 = "day.  And by High Inclination Probe-21, climbing slowly above\n"+
                       "the planet of the ecliptic.  And even by artificial Comet-5, \n"+
                       "heading far into the cold wastes beyond Pluto, along an orbit\n";
              lyric3 = "whose far point it would not reach for a thousand years.\n";
              lyric4 = "\n";break;
      case 6: lyric1 = "   All noticed the peculiar burst of energy that leaped from the\n"+
                       "face of the Moon and moved across the solar system, throwing off\n"+
                       "a spray of radiation like the wake of a racing speedboat.\n";
              lyric2 = "";
              lyric3 = "";
              lyric4 = "\n";break;
      case 7: lyric1 = HIR+"The Narrator closes his eyes and returns to his deep thoughts.\n";
              lyric2 = "";
              lyric3 = "";
              lyric4 = "\n";break;}

      tell_room(environment(this_player()),HIW+lyric1+NORM);
      tell_room(environment(this_player()),HIW+lyric2+NORM);
      tell_room(environment(this_player()),HIW+lyric3+NORM);
      tell_room(environment(this_player()),HIW+lyric4+NORM);

   return 1; }


