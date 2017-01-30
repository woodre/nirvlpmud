inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC15.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #15 - Ohtori Akio Saga #1\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel16.c", "next"
});

  song = ({
"",
"Ancient times, perfect, solitude in the desert",
"Air, atoms, the planet of causality",
"",
"Yes, a native child",
"Conception",
"The embryo of philosophy",
"",
"Egg, perfect, the origin in the nest",
"A stamen, a pistil, one seed",
"",
"Yes, a native child",
"Growth",
"The child of philosophy",
"",
"And Lunar Heaven, Mercurial Heaven, Venusian Heaven",
"Solar Heaven, Martian Heaven, Jovian Heaven",
"Saturnian Heaven, Sidereal Heaven, Motive Heaven",
"",
"Further circular infinity without end",
"",
"One organic system",
"One perpetual motion device",
"",
"Ah, it is an empty movement",
"That is an empty movement. It is.",
"",
"   ~~~  ~~ ~ S ~ ~~ ~~~",
  });
  max = sizeof(song);

  call_out("playsong",3);
}


playsong(){
	/*wockets jukebox*/
  if(i == max) i = 0;
  tell_room(this_object(),song[i]+"\n");
  i++;
  call_out("playsong",3);
}
