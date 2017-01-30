/*
  cure_diseases.h
*/

#include "/players/eurale/defs.h"

/* -------- Cure diseases in the vampire -------- */
cure_disease(str) {
  if (!str || str != "disease") return 0;

if(TPL < 19 || TPGEXP < 670 || TP->query_attrib("pie") < 19) {
  write("You lack the skills necessary for that ability.\n");
  return 1; }

if(TPSP < 50) {
  write("You lack the magic to cure any diseases.\n");
  return 1; }

  /* make 3 passes in case there's more than one of each */
cure_diseases();
cure_diseases();
cure_diseases();
TP->add_spell_point(- 50);
write("You focus your mind and "+HIC+"CLEANSE YOUR BODY"+NORM+
      " of disease.\n");
return 1;
}

cure_diseases() {
if(present("toxin",TP) || present("toxin3",TP)) {
  write(HIG+"You neutralize the deadly disir poison."+NORM+"\n");
  destruct(present("toxin",TP));
  destruct(present("toxin3",TP));
}

if(present("crotchrot",TP)) {
  write(HIR+"You shiver VIOLENTLY as the blood-born pathogens "+
        "are neutralized."+NORM+"\n");
  destruct(present("crotchrot",TP));
}

if(present("flu", TP)) {
  destruct(present("flu", TP));
  tell_object(TP, "You've just cured yourself of the flu.\n");
}

if(present("headcold", TP)) {
  destruct(present("headcold", TP));
  tell_object(TP, "You've just cured yourself of the flu.\n");
}

if(present("cold", TP)) {
  destruct(present("cold", TP));
  tell_object(TP, "You've just cured yourself of a cold.\n");
}

if(present("disease", TP)) {
  destruct(present("disease", TP));
  tell_object(TP, "You've just cured yourself of a disease.\n");
}
}
