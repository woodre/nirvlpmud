inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC05.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #5";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel06.c", "next"
});

  song = ({
"",
"Beginning of the earth",
"Stage props",
"the Laplace nebula",
"Spectatorism",
"",
"Unchanging illusion",
"Mystery solving clock",
"Baby carriage of the",
"edge of immortality.",
"",
"My eternal self and",
"the eternal stranger",
"two relations; two births",
"scales of mystery; human constellation",
"",
"Ahhh",
"",
"Ahhh",
"",
"Time is hypothetical, an illusional prop of the beginnings of birth.",
"Destiny, choice, goodbye-ism",
"You and I are the Milky Way",
"Having no past, only the present, having no future, ",
"A single person in the Theatre Cosmic.",
"",
"That's me! Wait! My last evolution",
"Revolution",
"Everlution",
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
