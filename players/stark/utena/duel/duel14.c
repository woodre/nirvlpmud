inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC14.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #14 - Black Rose 7\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel15.c", "next"
});

  song = ({
"",
"Incandescent darkness and birthed puppets",
"Are named, anthropoperipherism",
"",
"Pulling the strings of the world is a single existence",
"For the others, an imaginary puppet-craft",
"",
"Subzero darkness and birthed creatures",
"Correlated, anthropoperipherism",
"",
"On the natural stage are the units of existence",
"Comprised of an imaginary creature-craft",
"",
"Words are born, the encounter, then a hesitation",
"Knowledge is born, the encounter, then a void",
"O where am I, when am I",
"",
"Spell, incantation, mystery, prayer, myself",
"Stage destiny magic mirror",
"",
"Full moon, mysterious and transmutable, ",
"I'm an imaginary living body come to its end",
"Full moon, mysterious and transmutable, ",
"I'm an imaginary destined body come to its end",
"Seeking time, without rest",
"Living on, a speleomorph",
"",
"Seeking land, armless, legless",
"Still existing I am, transparent,",
"intangible, a faint sigh...",
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
