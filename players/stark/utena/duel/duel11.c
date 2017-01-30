inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC11.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #11 - Black Rose 4\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel12.c", "next"
});

  song = ({
"",
"A philosophical existence",
"The domain of mainstream magic's Grand Guignol",
"A normal sigh, a heavy sigh, an anxious sigh, ",
"a grieving sigh, a pleasured sigh... ",
"I gather my breath, store up my breath,",
"through a magnifying glass. ",
"",
"Heavy sighs and normal sighs and",
"anxious sighs and grieving sighs, ",
"Pleasured sighs and heavy sighs and",
"normal sighs and anxious sighs, ",
"Grieving sighs and pleasured sighs and",
"heavy sighs and normal sighs, ",
"Anxious sighs and grieving sighs and ",
"pleasured sighs and heavy sighs. ",
"Hahahah!",
"Energy does not exist, in any form!",
"Useless energy does not exist at all!",
"Ubermensch - mechanism drawing breath",
"Ubermensch - flesh model of humanity",
"Ubermensch - analysis of endless layers",
"Ubermensch - transcendent synthesis",
"",
"Ah! Ah! Celestial revolution.",
"Ah! Ah! Existence composition.",
"The birth of a new species?",
"Or the limit of human potential?",
"",
"Everywhere, clocks are ticking. ",
"Even here, my heart is pounding. ",
"A hammer that strikes time; Bam! Bam!",
"Bam! Bam!",
"I, the time traveler, will open the door!",
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
