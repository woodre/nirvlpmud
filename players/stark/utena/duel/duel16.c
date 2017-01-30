inherit "/players/vertebraker/closed/std/room";
#include "/players/stark/defs.h"
string *song;
int max,i;
reset(arg){
    MOCO("/players/stark/utena/duel/NPC16.c"),this_object());
    if(arg) return;
    set_light(1);
    short_desc="Dueling Arena";
    long_desc=
"Dueling Arena-\n  Fight #16 - Ohtori Akio Saga #2\n";

items=({
"blah","blahblah",
"blah2","blah2blah2"
});

dest_dir=({
"/players/stark/utena/duel/duel17.c", "next"
});

  song = ({
"",
"My Existence a Miracle of Alchemy",
"Base Metals, Precious Metals",
"From Right to Left",
"From Beginning to End",
"Destruction, Hunting, the Riot Like Dance of War, and the Celebration Afterwards",
"",
"Born to Invisiblity through Alchemy",
"Artificial Installation, Rearranging",
"From Above to Below",
"Transforming into a Strange Shape",
"Anonymous Books of Self-Indulgence",
"An Insane State of Mind",
"",
"The World Never Changes (And I)",
"Myself, Never Changing",
"Kawara Warazu",
"",
"Everything Comes to an End",
"Birds and Fish",
"Come to an End",
"Spawn of the Cheating Bed",
"Come to an End",
"",
"Dancing Ships and Stagecoaches",
"From Ancient Times",
"Come to an End",
"Oceans and Waterfalls in Endless Circulation",
"",
"Sparkling Vision / Trembilng Imagination",
"Dried Up Fantasy / Unchanging Expression",
"Murmuring Delusion / Flickering Thought",
"Fluttering Originality / Wild Suspiscion",
"",
"Born to Immortal Life through Alchemy",
"Time, Space, Spawn of the Universe",
"Philosophy, The Rose Miracle",
"Purity, Harmony, All is Perspective",
"",
"My Future, My Present, My Past",
"My Future, My Present, My Past",
"",
"Sparkling Origin / Trembling Isolation",
"Crumbling Labrynith / Unchanging Space and Time",
"Rustling Reminiscence / Flickering Memory",
"Fluttering Disappearance /Primitive Immortal Life",
"",
"My Future, My Present, My Past",
"My Future, My Present, My Past",
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
