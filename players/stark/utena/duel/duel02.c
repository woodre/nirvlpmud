inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC02.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #2";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel03.c", "next"
});

  song = ({
"",
"Astrologic eras,",
"Primeval oceans,",
"Erosion and sediment",
"Three billion years,",
"Genesis of life,",
"Geologic eras",
"Cambrian,",
"Ordovician,",
"Silurian,",
"Devonian,",
"Stromatolite,",
"Bacteria,",
"Collenia.",
"Triassic, Jurassic, Cretaceous.",
"",
"Lycopsida,",
"Selaginella,",
"Pleuromeia.",
"Caytonia",
"Bennetites,",
"Ammonite.",
"Oceanic Rose,",
"Oceanic Lily,",
"Oceanic Apple",
"Oceanic Flower Buds.",
"Oceanic Angel,",
"Oceanic Mirror,",
"Oceanic Gate,",
"Oceanic Haze.",
"Carboniferous, Permian, Paleozoic.",
"",
"The Oceanic You,",
"The Oceanic Me,",
"Are the Paleozoic within the body.",
"Continuing to live,",
"Continuing to die,",
"The Paleozoic telling the story.",
"",
"Just like the whale, I go",
"Just like the dolphin, I go",
"Just like the seal, I go",
"To the bottom of the sea, the oceanic me.",
"At the bottom of the sea, a grand history.",
"To the bottom of the sea, where I will be Me.",
"",
"Am... mo... nite!",
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
