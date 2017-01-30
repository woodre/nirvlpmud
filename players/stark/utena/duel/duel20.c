inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC20.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #20 - Apocalypse Saga #1\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel21.c", "next"
});

  song = ({
"",
"Element, element",
"Element, element",
"",
"Cataclysmos",
"Cataclysmos",
"",
"The end of the World: Lost in reverie,",
"Let's amuse ourselves Selfishly",
"",
"Element, element",
"Element, element",
"",
"Cataclysmos",
"Cataclysmos",
"",
"Lemming of the North Pole / Siberian antelope",
"The Last Judgment of Nature",
"",
"A destiny of dread curiosity / The prophesy of extinction",
"Philosophical revolution / Garden of Paradise, Paradise Lost",
"An unexpectedly epic poem / Cosmic cataclysm",
"One thousand years of terror / Nirvanic thought",
"",
"Human birth / Human wisdom",
"Human knowledge / Human pleasure",
"Human consciousness / Human experience",
"Human revelation / Human emancipation",
"",
"Dante / Rabelais",
"Swift / De Sade",
  "Apocalpyse!",
  "Book of Revelation!",
  "Apocalypse!",
"",
"The beginning of the universe, namely the opening of destiny",
"The creation of heaven and Earth, namely the birth of destiny",
"The legend of Genesis, namely the creation of destiny",
"Natural selection, namely selection by destiny",
"",
"We should know it well",
"It is our mirror",
"Even so That appearance",
"Are we flesh?",
"Even so, Eternity",
"Absence We become",
"Only A fortuity",
"",
"Allegory, allegorier, allegoriest",
"Allegory, allegorier, allegoriest",
"",
"Allegory, allegorier, allegoriest",
"Allegory, allegorier, allegoriest",
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
