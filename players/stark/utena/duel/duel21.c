inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC21.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #21 - Apocalypse Saga #2\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

  song = ({
"",
"An image of Death rocks my mind",
"I pull the cord; toll the bells",
"The cock beats its wings; when the window opens",
"The twelve disciples are mere dolls",
"Unblinking, a grand parade",
"",
"The old orrery (clock of astronomy)",
"An automatic mechanism",
"The twelve constellations of the ecliptic me:",
"The zodiac",
"I,",
"The zodiac",
"",
"Within my body, from olden times,",
"One hundred towers rise above",
"A visceral landscape; Utopia",
"In the cemetary, a church, a cloister",
"",
"Eye of Earth; motive specimen",
"Intellectual organ of stone; the sign of Motive Power",
"Unfinished embryo; the secrets of Death",
"The theater, the hospital, the historical museum",
"",
"Artificial flesh; grotta; Labyrinth; illusionary construction; marble",
"Artificial clock; weight; spring; spinning and turning; individual time",
"",
"From the ancient city to me,",
"It ends with that day, quotidian clock",
"The sun in daytime; the moon at night",
"The natural clock of a day",
"",
"Bong bong, ding dong ding,",
"Bong bong, ding dong ding.",
"",
"The corporeal city and the Mystery of the clock",
"Geometric law, puritanical construction",
"Monotony; eternity",
"The present; perpetuity",
"All Creation is reality",
"Monotonous",
"Infinitely changing",
"",
"I will take the form of a corporeal city",
"I shall take the form of a suspended clock",
"",
"Municipal clock, a discovery",
"Municipal clock, an understanding",
"Municipal clock...",
"",
"Annihilation!",
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
