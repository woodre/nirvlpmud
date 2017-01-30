inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC10.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #10 - Black Rose 3\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel11.c", "next"
});

  song = ({
"",
"Twin relationships are the capricious,",
"heartless lies of desires propagating endlessly",
"in the interval between two mirrors.",
"Ah, man does not exist.",
"Ah, within the darkness",
"Ah, the sound of the waves",
"",
"Even light casts shadows, making a pair out of me and me.",
"Isolation outbreak, that's the reason",
"making a pair out of me and me. ",
"",
"Twins, twins-in-law,",
"Scheming twins, absent twins...",
"",
"Since we see the invisible,",
"The contrived world rises to the surface.",
"Amusement apparatus and optical illusions,",
"Then contrived world rises to the surface.",
"",
"Earth is a contrivance of personalities",
"Earth is a toybox of personalities",
"Earth is a department store of",
"personalities",
"Earth is an exhibition of personalities",
"Earth is a museum of personalities",
"Earth is a curio box of personalities",
"",
"Earth is...",
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
