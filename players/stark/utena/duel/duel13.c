inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC13.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #13 - Black Rose 6\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel14.c", "next"
});

  song = ({
"",
"Vanish! Fade away! Melt away!",
"Get out of my sight!",
"Any and all people!",
"Vanish! Fade away! Melt away!",
"Get out of my sight!",
"The instant imposters.",
"",
"Betrayed by wishes...",
"Avenged by hope.",
"Periods like this are tedious.",
"",
"I will run away.",
"Everyone, disappear!",
"Even now there's nothing that I want!",
"",
"Straddling an unmanned sidecar,",
"Daydream journey of three thousand leagues,",
"Subway, freeway, runway",
"I'm going! At a hundred kilometers per hour...",
"A hero, a swift wind, a fugitive.",
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
