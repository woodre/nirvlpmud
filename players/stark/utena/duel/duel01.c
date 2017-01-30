inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC01.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #1";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel02.c", "next"
});


  song = ({
"",
"When Where Who Which",
"When Where Who Which",
"",
"Flow of blood from the cage of my memory,",
"In the cradle of a thousand years of bliss.",
"And I, an actor cast eternally",
"as the Sphinx in the desert winter,",
"Phinx.",
"",
"Now you know the sadness",
"of the stillborn flesh.",
"And I, a holy actor, cast eternally",
"as a dark shining Margineaux, cast into Hell.",
"",
"Glow!",
"Burn!",
"Cool down,",
"and sing!",
"Born in this world,",
"born in an instant,",
"born all over again.",
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
