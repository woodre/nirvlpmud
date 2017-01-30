inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC12.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #12 - Black Rose 5\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel13.c", "next"
});

  song = ({
"",
"Oh, the pity! Although the aged man",
"put all his strength",
"into his skillful sword,",
"How pathetic his skill is in his age...",
"He misses his target, sword swishing through the air,",
"staggers and falls, oh, that old man.",
"",
"A shrieking sword swish, Troy's castle tower,",
"and the burning summit was rent asunder, with a thunderclap.",
"",
"Paris was deafened temporarily.",
"",
"Witness!",
"The white-haired old man,",
"raising it as if to cut, holds his sword up in the sky,",
"and Paris is petrified.",
"Paris soon regains his hostility,",
"and brings his blood-stained, dripping blade",
"down upon the aged king!",
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
