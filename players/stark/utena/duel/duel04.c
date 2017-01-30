inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC04.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #4";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel05.c", "next"
});

  song = ({
"",
"Nature's light",
"Mosaic light",
"Child of daybreak; the angel Lucifer",
"Apocalyptic light",
"Michael's light",
"Child of darkness; androgynous",
"Fire's light",
"Heavenly light",
"Hierarchia of the heavens",
"Illusory light",
"Eternal light",
"Phantasmic deception; capricious birth",
"",
"Nyx",
"Erebus",
"Uranus",
"Thanatos",
"",
"Shining bodies, all of them spherical, gynous",
"just as if born with every miracle, gynous.",
"The pleasure principle, the Nirvana principle",
"Death's inevitability, dubbed \"the light\"",
"Without having to have lived,",
"Phenomenon of mobile life",
"In the cerebral universe",
"Shape of floating life",
"Glory, ephemery, hope for eternity!",
"Incomplete returning to the primitive beginnings.",
"",
"Male/female, positive/negative are the two of me.",
"Up/down, left/right are the two of me.",
"Front/back, Heaven/Earth are the two of me.",
"Angel and devil are the two of me.",
"The center is hollow hollow hollow",
"hollow...",
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
