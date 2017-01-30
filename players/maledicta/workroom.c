/* Thanks to Eurale for providing this code. */
/* Maledicta 1999                            */

#include "/players/maledicta/ansi.h"
#define TP this_player()
#define NAME "maledicta"
inherit "room/room";
int numero;
int shield;
string *lyrics;

reset(arg) {
  if(arg) return;
/* move_object(clone_object("players/boltar/templar/board"), this_object()); */
numero = 0;

set_light(1);

lyrics = ({
"0",
"I have brought you",
"to the seat of sweet", 
"music's throne...",
"to this kingdom",
"where all must pay",
"homage to music...",
"music...",
"You have come here,",
"for one purpose,",
"and one alone...",
"Since the moment",
"I first heard you sing,", 
"I have needed", 
"you with me,",
"to serve me, to sing,",
"for my music...",
"my music...",
"Night-time sharpens,",
"heightens each sensation...",
"Darkness stirs and",
"wakes imagination...",
"Silently the senses",
"abandon their defences...",
"Slowly, gently",
"night unfurls their splendour...",
"Grasp it, sense it -", 
"tremulous and tender...",
"Turn your face away",
"from the garish light of day,",
"turn your thoughts away",
"from cold, unfeeling light-",
"and listen to", 
"the music of the night...",
"Close your eyes",
"and surrender to your",
"darkest dreams!",
"Purge your thoughts",
"of the life",
"you knew before!",
"Close your eyes,",
"let your spirit",
"start to soar!",
"And you'll live",
"as you've never",
"lived before...",
"Softly, deftly,",
"music shall surround you...",
"Feel it, hear it,",
"closing in around you...",
"Open up your mind,",
"let your fantasies unwind,",
"in this darkness which", 
"you know you cannot fight -",
"the darkness of", 
"the music of the night...",
"Let your mind", 
"start a journey through a",
"strange, new world!",
"Leave all thoughts",
"of the world",
"you knew before!",
"Let your soul",
"take you where you",
"long to be!",
"Only then",
"can you belong",
"to me...",
"Floating, falling,",
"sweet intoxication!",
"Touch me, trust me,",
"savour each sensation!",
"Let the dream begin,",
"let your darker side give in",
"to the power of",
"the music that I write -",
"the power of",
"the music of the night...",
"You alone",
"can make my song take flight -",
"help me make the music of the night...",});

dest_dir = ({
  "room/adv_inner.c","advance",
  "players/maledicta/workroom2.c", "east",
  "players/zeus/workroom.c","zeus",
  "players/dragnar/workroom.c","dragnar",
});

}

short(){
numero += 1;
if(numero >= sizeof(lyrics)) numero = 1;
return HIW+lyrics[numero]+NORM;
}


long(){ write(
"\n\n\n\n                  "+BOLD+"- "+HIW+"Serene Darkness"+NORM+BOLD+" - "+NORM+"\n\n\n\n\n");
return 1;
}


init() {
  ::init();
  add_action("move_cyb","cyber");
add_action("on", "on");
add_action("post", "post");
add_action("off", "off");
  add_action("ruins", "ruins");
  add_action("movecastle", "castle");
  add_action("town", "town");

if(this_player()->query_real_name() != NAME && shield == 1) {
  write("Your body impacts suddenly against a solid energy barrier!\n"+
        ""+BYEL+"              ZZZZZZAAAAAAPPPPPPP "+NORM+"\n"+
        "You rebound off of the shield and find yourself somewhere else.\n");
  say(this_player()->query_name()+" has just been sent to the church.\n");
  this_player()->move_player("off the shields#room/church");
  return 1; }
 }

move_cyb() {
  TP->move_player("cyberninja#players/dune/closed/guild/rooms/guildhall.c");
  command("look",this_player());
  return 1; }

static on() {
  write("You "+BOLD+"activate"+NORM+" the shield.\n");
  shield = 1;
  return 1; }

static off() {
if(TP->query_real_name() != NAME) {
  write("You are not allowed to do that!!!!!!!\n");
  return 1; }
  write("You "+BOLD+"deactivate"+NORM+" the shield.\n");
  shield = 0;
  return 1; }

post(){
  TP->move_player("post office#room/post.c");
  return 1; }

ruins(){
  TP->move_player("ruins#players/maledicta/ruins/rooms/r1.c");
  return 1; }

town(){
  TP->move_player("ruins#players/maledicta/town/rooms/t1.c");
  return 1; }
    	
movecastle(){
  TP->move_player("ruins#players/maledicta/castle/rooms/m1.c");
  return 1; }  
  
  
no_hunter(){ return 1; }
