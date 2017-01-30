#include "/players/pavlik/guild/mages/macs"
#include "/players/pavlik/guild/mages/rooms/ROOMS"
inherit "room/room";
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="Yshir's Chambers";
long_desc=
"You are in the main room of Yshir's chambers.  You hear quiet\n"+
"classical music playing in the backround.  The walls are decorated\n"+
"with a wide variety of classical art works.  The only furniture\n"+
"in the room is a long plush couch and a baby grand piano in the\n"+
"northwest corner.  You realize that the piano is from where the\n"+
"music is emanating, although noone is seated on its bench.\n";

items=({
"wall",
"The walls are decorated with a tastleful collection of classical\n"+
"art works, each of which is priceless",
"couch",
"A fine plush couch invites you into its comfortable cushions.  The\n"+
"pillows are made of fine silk and inlaid with intricate golden\n"+
"weavings.  Although the couch is obviously a priceless artifact, you\n"+
"feel welcome to sit upon it",
"piano",
"The piano is a sleek black baby grand.  The piano plays along\n"+
"quietly, even though there is noone seated at its bench.  There\n"+
"is some sheet music on top of the instrument",
"sheet music",
"Several pages of music are neatly stacked on the piano.  There\n"+
"is some writing on the top of the last page:\n"+
"  Welcome Mage.  If you need my assistance please have a\n"+
"  seat and be comfortable.  I will be with your shortly.\n"+
"                       -Yshir",
"music",
"Several pages of music are neatly stacked on the piano.  There\n"+
"is some writing on the top of the last page:\n"+
"  Welcome Mage.  If you need my assistance please have a\n"+
"  seat and be comfortable.  I will be with your shortly.\n"+
"                       -Yshir",
});


dest_dir=({
 "/players/pavlik/guild/mages/rooms/spell_masters", "south",
 "/players/pavlik/guild/mages/rooms/BLAH", "north",
});

if(!present("couch", this_object()))
  move_object(clone_object("players/pavlik/guild/mages/obj/yshir_couch"), this_object());


  }
}

query_mguild(){ return "Yshir's"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("north","north");
  add_action("play_piano","play");
  mage_check();
}

play_piano(str){
  if(str == "piano"){
   write(
   "You carefully sit yourself at the piano and admire the magnificent\n"+
   "instrument.  You begin to play, tentativly at first, but the keys\n"+
   "work magic under your fingers and your brilliant music soon fills\n"+
   "the room!\n");
   say(ME+" makes wonderful music at the piano.\n");
   return 1;
   }
}

north(){
  write(
  "You take a few steps towards the north door and the piano\n"+
  "suddenly plays a few menacing chords.\n"+
  "You think better of the idea and leave the north door alone.\n");
  return 1;
}


