#include "/players/linus/def.h"
inherit "/room/room.c";
  int xyz;
  object player;
  reset(arg){
      if(!arg) {
      set_light(1);
      xyz=1;
      short_desc = "On a deck";
      long_desc =
  "A breeze blows through the leaves of the tree making a soft whistling\n"+
  "sound.  A small house stands to the north, built between the branches\n"+
  "of the tree.  A small window is near the door, and a sign on the door\n"+
  "reads: nok 2 c owl.  A deck stands directly south of the house, and is\n"+
  "built of various scraps of wood.  A small but sturdy railing surrounds\n"+
  "the deck, preventing anyone from falling off.\n";
      items = ({
       "tree","A large maple tree.  Owl's house is built in it",
       "leaves","Green leaves that grow on the maple tree",
       "house","A small white house built between some of the branches of the tree.\n"+
               "A small wooden door leads into the house, and there is a small window\n"+
               "next to the door",
       "sign","A small, yellowed piece of paper with some writing on it",
       "paper","A small, yellowed piece of paper with some writing on it",
       "window","A small, round window.  The frame is painted white to match the house",
       "door","A small wooden door, painted white.  There is a small sign tacked to the door",
       "deck","The deck in front of Owl's house is made up of different types of\n"+
              "wood boards",
       "boards","The boards are made of various types of wood",
       "wood","Various types of wood used to build Owl's deck",
       "railing","A sturdy railing that surrounds the deck"  });
dest_dir = ({ NEWB+"n10.c","down"  });
}
}
init()  {
  ::init();
    add_action("knock_on_door","knock");
    add_action("read_stuff","read");
    add_action("Listen","listen");
}  
knock_on_door(str) {
  if(!str || str!="on door") { notify_fail("Knock ON what?\n"); return 0; }
  write("You knock on the door, the sound echoing throughout the house.\n");
  if(xyz == 1) {
  player = this_player();
  xyz = 0;
  call_out("blah",6); /* Thanks Eurale! */
  return 1; }
  return 1;
}
blah() {
 say("\n\nFrom within the house you hear some shuffling.\n\n\n");
 say("From behind the door a voice says 'be right there!'\n\n");
  call_out("blah1",7);
  return 1; }
blah1() {
  say("The door opens and Owl steps out.\n\n\n");
  MO(CO("players/linus/Newbie/NPC/Owl.c"),TO);
  call_out("blah2",3);
  return 1; }
blah2() {
  command("look",player); return 1;
}   
read_stuff(string str) {
     if(!str || str!="sign" && str!="paper") { notify_fail("Read what?\n"); return 0; }
    if(str=="sign" || str=="paper") {
     write("The writing on the paper reads: Nok 2 C Owl.\n");
    return 1;
}
}
Listen(str) {
    write("The soft whistle of the wind can be heard.\n");
     return 1;
}
