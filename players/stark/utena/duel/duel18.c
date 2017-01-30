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
"Dueling Arena-\n  Fight #18 - Ohtori Akio Saga #4\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel19.c", "next"
});

  song = ({
"",
"An ode to my face, my neck, my hair",
"An ode to my nails and my torso",
"An ode to my hands and my feet",
"This is an ode to all the parts of my body",
"",
"In other words, a crest;",
"This is the heraldry of the human body",
"",
"That figure in the mirror",
"Performs delicate work in a complex situation",
"Charge argent on field sable; courtly ettiquette",
"Charge sable on field argent; shield-shaped design",
"",
"People arrayed in impenetrable symbol",
"The historical art of the Baroque",
"",
"The Salamander",
"The Dragon and the Urchin",
"The hidden miracle of the Eucharist",
"Creed and virtue",
"Kept in confinement,",
"The miracle of the rose",
"Human-beast-flower",
"Pearl and jewel",
"The age of man",
"Floral diamond and cross",
"",
"Or, Argent, Purpure, Vert, Gules, Azure, Sable",
"Or, Argent, Purpure, Vert, Gules, Azure, Sable",
"",
"Alhambra",
"Ispahan",
"Caserta",
"Linderhof",
"Cheval",
"Bomartzo",
"Flora",
"Mathias",
"Versailles",
"Obelisk",
"Sahmekh",
"Isola Bella",
"Amphiteatro",
"The Grotto of Orpheus",
"Neuschwanstein",
"Santa Maria della Concezione",
"",
"The cave, the statue, the fountain, the gardens, the palace",
"The bronze mural, the imaginary castle, the villa",
"",
"Far and near",
"I am all the Mysteries",
"From near and far",
"I am all the Mysteries",
"I am all the Mysteries in Creation",
"I am all the Mysteries in the World",
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
