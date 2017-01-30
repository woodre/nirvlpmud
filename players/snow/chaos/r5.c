/* Emotion room */

inherit "players/snow/chaos/arch.c";
#include "/players/snow/chaos/defs.h"
#include "/players/snow/closed/cyber/color.h"

reset(arg) {
  ::reset();

  if(!arg) {
  short_desc=YELLOW+"C"+OFF+
             MAGENTA+"h"+OFF+
             GREEN+"A"+OFF+
             CYAN+"o"+OFF+
             BLUE+"S"+OFF;
  long_desc=
"  This area shines with an iridescent aura. Everything \n\
is kinda groovy here...\n";
  items=({
    "aura","An insubstantial yet perceptible sort of glow",
      });
  call_out("groovy_feelings",random(15));
  }
}

groovy_feelings() {
  int ran;
  string feeling;
  ran = random(12);
  if(ran == 0) feeling = "happiness!\n";
  if(ran == 1) feeling = "sadness.\n";
  if(ran == 2) feeling = "bewilderment...\n";
  if(ran == 3) feeling = "loneliness.\n";
  if(ran == 4) feeling = "anger!\n";
  if(ran == 5) feeling = "self-pity.\n";
  if(ran == 6) feeling = "euphoria!\n";
  if(ran == 7) feeling = "rage!\n";
  if(ran == 8) feeling = "bogglement..\n";
  if(ran == 9) feeling = "well-being.\n";
  if(ran == 10) feeling = "boredom...\n";
  if(ran == 11) feeling = "excitement!\n";
  TR(TO,"You get a sudden feeling of "+REV_BLUE+feeling+OFF);
  call_out("groovy_feelings",random(30));
  RE;
}
