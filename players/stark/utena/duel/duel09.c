inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC09.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #9 - Black Rose 2\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel10.c", "next"
});

  song = ({
"",
"Time Machine",
"To the past, to the future, whoosh, zip, zoom!",
"Time Machine",
"My childhood when I was so adorable.",
"",
"Making a lotus carpet,",
"Playing with dolls,",
"A mysterious charm, Fi! Fi!",
"Candy",
"I wore a beautiful kimono",
"Children's Festival",
"Oh, my dream machine...",
"Flowerstorm",
"To the faraway ancient me,",
"Ten, two, one, zero... Take off!",
"",
"Time Machine",
"To the past, to the future, whoosh, zip, zoom!",
"Time Machine",
"To the time of all my dreams and wishes",
"",
"Hair tied back,",
"toting a box lunch,",
"A mysterious charm, Fi! Fi!",
"Amusement parks",
"Surprise! Surprise!",
"These are all my soul",
"Oh, my dream machine...",
"Dreamstorm",
"To the faraway ancient me,",
"Ten, two, one, zero... Take off!",
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
