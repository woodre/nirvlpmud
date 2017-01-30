inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC08.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #8 - Black Rose 1\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel09.c", "next"
});

  song = ({
"",
"They can be divine spirits,",
"they can be evil spirits",
"Ah, even if Heaven's vapors were brought here...",
"Secret thoughts can also be virtue!",
"They can also be vice!",
"Ah, even if Hell's bewitching",
"atmosphere were carried here...",
"As long as such suspicious forms do come,",
"they shall have a dialogue!",
"",
"On a moonlight night already severely cold,",
"might a spirit leave its body!",
"A mystery beyond the ken of humans,",
"and humanity, dwarfed by their Creator,",
"is made to tremble in fear at the sight!",
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
