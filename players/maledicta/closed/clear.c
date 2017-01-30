/* Limited the respawn of Hinotori to 1:30 chance.
   - Maledicta & Daranath
*/

#include "/players/mythos/closed/ansi.h"
#define tp this_player()->query_name()
inherit "room/room";
int done;

reset(arg) {
  if(!arg) {
  set_light(1);
    short_desc = "Clearing";
    long_desc =
    "This area is very odd.  Surrounded by trees and darkness\n"+
    "you stand upon a patch of ground covered by 'sand'.  The clearing is\n"+
    "well lit by a strange light that eminates from the golden sand.\n"+
    "You have heard this place- The Sandy Place,- in stories, but\n"+
    "you thought it a child's tale.  You glance 'up' and notice something odd.\n";
  items = ({
    "back","You can make out the Tower behind",
    "up","The air seems to shimmer oddly.....'Something' seems to be there",
    "sand","The golden sand glitters in the light.  \n"+
            "Perhaps you will find something if you 'sift' through it",     
    "something","You look closer and you see nothing.  \n"+
              "You do get an urg to 'stretch' out your hand",     
     "forest","Out there you see the forest...if you enter you may get lost",   });

  dest_dir = ({
    "/players/mythos/aroom/forest/tower.c","back",
     "/players/mythos/aroom/forest/foresto.c","forest",
  });
} }

init() {
  ::init();
  add_action("sift_sand","sift");
  add_action("stretch","stretch");
}

sift_sand() {
object ob;
  if(this_player()) {
   if(this_player()->is_ghost()) {
      this_player()->move_player("church#room/church.c");
}}
ob=present("sandial");
if(!present("sandial")) {
  int x;
  x = random(30);
  if(x <= 15) {
    move_object(clone_object("/players/mythos/amon/forest/orochi.c"),this_object());
    move_object(clone_object("/players/mythos/amisc/forest/timers.c"),this_object());
    write("You sift through the sand.  Sand flies everywhere.\n"+
    "When it clears you see the dreaded Yamato-no-Oorochi (the\n"+
    "great eight headed serpent) before you!\n");
    say(tp+" sifts through the sand.  Sand flies everywhere.\n"+
    "When it clears you see the dreaded Yamato-no-Oorochi (the great\n"+
    "seven headed serpent) before you!\n");
  return 1; done = 1; }
  else if(x==16) {
    write("You sift through the glittering sand.\n"+
      "You uncover a strange looking egg.\n");
    say(tp+" sifts through the glittering sand and uncovers\n"+
      "a strange looking egg.\n");
    move_object(clone_object("/players/mythos/amisc/forest/pegg.c"),this_object());
    move_object(clone_object("/players/mythos/amisc/forest/timers.c"),this_object());
  return 1; done = 1; }
  else if(x<=29) {
    write("you sift through the sand...all of a sudden\n\n"+HIB+
      "\t\tB  O  O  M\n\n"+NORM+"Thunder sounds and a great wind blows!\n"+
      "Before you two tall figures emerge from the forest.\n"+
      "It is Raiden- the Thunderer- and Fujin- the Wind.\n");
    say(tp+" sifts through the sand. Suddenly...\n\n"+HIB+
      "\t\tB  O  O  M\n\n"+NORM+"Thunder sounds and a great wind blows!\n"+
      "Before you two tall figures emerge from the forest.\n"+
      "It is Raiden- the Thunderer- and Fujin- the Wind.\n");
    move_object(clone_object("/players/mythos/amon/forest/fuji.c"),this_object());
    move_object(clone_object("/players/mythos/amon/forest/raiden.c"),this_object());
    move_object(clone_object("/players/mythos/amisc/forest/timers.c"),this_object());
  return 1; done = 1; }
return 1; }
else if(present("sandial")) {
  write("You sift the sand but nothing happens.\n"+
    "It seems as if the sand's power has faded abit.\n"+
    "In time the power shall return!\n");
  say(tp+" sifts the sand around but nothing happens.\n"+
    "Seems the sand's power has faded a bit.\n"+
    "In time the power shall return!\n");
return 1; }
return 1;
}

stretch() {
object ob2;
ob2=present("timearm");
  if(this_player()) {
   if(this_player()->is_ghost()) {
      this_player()->move_player("church#room/church.c");
}}
if(!present("timearm")) {
  int y;
  y=random(2);
  if(y==4) {
    write("You stretch out a hand and something about the air changes.  Suddenly,\n"+
      "a large black hole comes into existance in the sky.\n"+
       "\n\tA great "+U+HIR+"DRAGON"+NORM+" flies through.\n"+
      "\nThe hole closes up behind the dragon.\n");
    say(tp+" stretches out a hand and something about the air changes.  Suddenly,"+
      "\nA large black hole comes into existance in the sky.\n\n"+
      "\tA great "+U+HIR+"DRAGON"+NORM+" flies through.\n\n"+
      "The hole closes up after the dragon.\n");
    move_object(clone_object("/players/mythos/amon/forest/ryu.c"),this_object());
    move_object(clone_object("/players/mythos/amisc/forest/timea.c"),this_object());
  return 1; }
  else if(y==1) {
    write("You stretch out a hand and nothing happens.\n"+
      "Then.....\n"+
      "A horse like creature steps out of the forest- a Kirin.\n");
    say(tp+" streches out a hand and nothing happens.\n"+
      "Then......\n"+
      "A horse like creature steps out of the forest- a Kirin.\n");
    move_object(clone_object("/players/mythos/amon/forest/kirin.c"),this_object());
    move_object(clone_object("/players/mythos/amisc/forest/timea.c"),this_object());
  return 1; }
  else if(y==0) {
    write("You stretch out a hand...\n"+
      "You hear the flapping of wings...\n"+
      "A winged man flies in from nowhere- a Tengu.\n");
    say(tp+" stretches out a hand....\n"+
      "You hear the flapping of wings....\n"+
      "A winged man flies in from nowhere- a Tengu.\n");
    move_object(clone_object("/players/mythos/amon/forest/tengu.c"),this_object());
    move_object(clone_object("/players/mythos/amisc/forest/timea.c"),this_object());
  return 1; }
return 1; }
  else if(present("timearm")) {
  write("You stretch out an arm but nothing happens.\n"+
    "The air's magic power has dimmed abit.\n"+
    "In time the power shall return!\n");
  say(tp+" stretches out an arm but nothing happens.\n"+
    "The air's magic power has dimmed abit.\n"+
    "In time the power shall return!\n");
  return 1; }
return 1; }
  query_realm() {return "NT";}
