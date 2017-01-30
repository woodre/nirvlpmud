inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC17.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #17 - Ohtori Akio Saga #3\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel18.c", "next"
});

  song = ({
"",  
"The Pentagram Creation of the Stars",
"Pleasure",
"The Pleasure of Man",
"The Pleaure of the Expression of Reproduction",
"Ideal and Reality",
"Man and Woman",
"",
"Dignity, Purity",
"The Need for Voluptous Flesh",
"The Ancient Times a Model for the Current Me.",
"Seraphitus",
"Both Sexes, Two People",
"In One Body",
"Seraphita",
"",
"Heaven's Mechanisim for Molding Together a Mosaic",
"Two moving into a dream",
"An Odd Number and an Even Number",
"Light and Darkness",
"",
"One Person or Many Persons?",
"Langauge or Things?",
"Suffering with the Questions",
"An Omen of Movement of the Dioscuri",
"All Things in Creation, All Sexes",
"Chaos and Confusion Anima Animusu",
"",
"Spiritual Perfection Suddenly Threatened by the Long Ages",
"Namely, Oneself's Internal Discoveries",
"",
"Right and Left, Two of Me.",
"Heaven and Earth, All Things in Creation, Man and Woman Both Sexes",
"",
"Two Heads, Two Bodies",
"Two Within, Two Outside",
"Two Sexes, Two of Me",
"Two Before, Two After",
"",
"My World Inside The Two's Cemetary.",
"My World Inside The Two's Boundries.",
"In My World There is Only Us.",
"",
"Two of me / Of me, two / Me: two of / Two of me",
"In My World I am Androgynous",
"Aaaa",
"Aaaa",
"Aaaa",
"Hermaphadism",
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
