inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC07.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #7";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel08.c", "next"
});

  song = ({
"",
"No one has anything to tell",
"There is nothing to be told",
"Only in the sealed darkness known as yesterday,",
"Only in the glint of a mere",
"split-second known as now,",
"Only in the darkness waiting for the",
"light known as tomorrow, in the theater.",
"I can become anyone",
"I can become anything",
"Only in the sealed darkness known as memory",
"Only in the glint of a mere",
"split-second of creation",
"Only in the darkness waiting for the",
"light known as tomorrow, in the theater.",
"Ah, dance! Ancient continental theatre of",
"the actors who wore the mask of Time.",
"Ah, dance! Admiration of you that come from the",
"Milky Way railroad, three of the Seven Ancient Wonders.",
"Like a star,",
"Like a firefly,",
"Shining during birth, we'll shine and disappear.",
"Shining during birth, we'll shine and disappear.",
"All of us will be born, then disappear.",
"Shining during birth, now shine and disappear!",
"Be born and disappear! I, the jewel",
"Shining during birth, I shone then disappeared",
"Born, then disappeared, the star that is me.",
"The Evening Star, Ego Star",
"Shine and disappear, Firefly Star!",
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
