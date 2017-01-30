inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC06.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #6";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel07.c", "next"
});

  song = ({
"",
"Unwritten seal spell",
"iron mask of misfortune",
"blue skies - sea - then the wind blows",
"grassland - rabbits - even the river flows",
"Time, the era does not change.",
"Time, the era is something existent and",
"nonexistent.",
"Man is described by the blood of",
"\"make-believe\"",
"Man also drowns in a flood of \"lessons\"",
"All the word handed down is that a man",
"is a man.",
"Without metamorphosis!",
"In the daytime I can see it, in the",
"nighttime I cannot.",
"In the nighttime I can see it, in the",
"daytime I cannot.",
"Anagram",
"Those puzzle words, those masks of",
"words",
"The source of which is...",
"dich!",
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
