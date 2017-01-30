inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC19.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #19 - Ohtori Akio Saga #5\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel20.c", "next"
});

  song = ({
"",
"The natural compatriots' palace perspective:",
"An expanding sphere",
"Surface condensation",
"The creation of the world",
"",
"Sorcery, aesthetics, and astronomy",
"The naturology of you-and-me (yeah!)",
"",
"The natural compatriots' palace perspective:",
"A realistic imagination",
"The imitation of form",
"A natural fantasy",
"",
"Sorcery, esthetics, and astronomy",
"The naturology of you-and-me (yeah!)",
"",
"The orbit of Saturn - Plato - a circumscribed circle",
"The orbit of Jupiter - Plato - an inscribed circle",
"The orbit of Earth - Plato - a circumscribed circle",
"The orbit of Venus - Plato - an inscribed circle",
"The orbit of Me - Plato - a circumscribed circle",
"The orbit of You - Plato - an inscribed circle",
"",
"Ah...!",
"",
"My children, astronomical planets",
"Five solid bodies are",
"My descendants",
"",
"Your children, the mysterious Nasca",
"Imaginary bodies are",
"Your descendants",
"",
"Me, you, and nature...",
"Nature...nature...freely self-existant",
"",
"Me, you, and nature...",
"Nature...nature...freely self-existant",
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
