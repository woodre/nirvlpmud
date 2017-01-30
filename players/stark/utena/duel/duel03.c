inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC03.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #3";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel04.c", "next"
});

  song = ({
"",
"The Theatre,",
"gifted spirits,",
"a collective phenomenon.",
"The Theatre,",
"gifted characters,",
"a phantasmic reality.",
"Operating table,",
"a shipwreck,",
"pure drama... spira mirabilis",
"Still spiraling,",
"transforming,",
"in the vortex. spira mirabilis",
"in Scipio's dream.",
"",
"The theatre",
"illusory spirits,",
"movement of immortality.",
"The theatre,",
"illusory characters,",
"structure of immortality.",
"Ammonite,",
"alchemy,",
"scarab... spira mirabilis.",
"Dying just to live once more.",
"Spira mirabilis.",
"In the vortex of miracles.",
"",
"Mai mai mai mai.",
"Mai mai mai mai.",
"Never-ending theatre.",
"",
"On the geometric stage",
"of life and the mystery of death,",
"Exeunt, all!",
"Death rebirth death rebirth death rebirth death rebirth",
"Death rebirth death rebirth death rebirth death rebirth",
"Death rebirth death rebirth death rebirth!",
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
