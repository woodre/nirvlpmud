inherit "/players/jareel/room";
#include "/players/jareel/define.h"

reset(arg) {
    if(arg) return;
    set_light(1);

short_desc=(BLU+"Orlanth "+NORM+"Temple");

long_desc=
"     This appears to be the main shrine of the Orlanthi temple.  The\n"+
"crystal blue sky embraces the room with a whipping whistling wind.  A \n"+
"small ornate shrine rests in the center of this auditorium, surrounded\n"+
"by several wooden benches.  Doors rest on the south, west and east walls.\n";

items = ({
  "shrine","The alter in the middle of the floor is designed with a few runes",
  "runes","The runes of the Air and Motion decorate the alter",
  "door","The doors on the southern, eastern and western walls are slightly ajar",
  "benches","Small wooden benches to sit on",
  "altar","The small altar is very ornate and looks more like a podium",
  "bench","Small wooden benches to sit on",
  "wooden benches","Small wooden benches to sit on",
  "wooden bench","Small wooden benches to sit on",
  "ornate shrine","The alter in the middle of the floor is designed with a few runes",
  "pillar","The pillars are ornately covered in runes of Motion and Air",
  "runes","The runes seem to signify the god to whom this temple worships",
  "pillars","The pillars are ornately covered in runes of Motion and Air",
  "sky","The light crystal blue sky lies over head",
  "flagstone","Large flat gray stones line the floor",
  "floor","Large gray flat stones line the floor.",
  "temple","The temple is rather small and unimpressive",
  "blue","The color of the sky",
  "room","The room is the main meeting place of the temples worshipers",
  "wind","The wind whistles around the room",
  "auditorium","Benches surround the shrine in the middle of the room",
});

dest_dir = ({
"/players/jareel/areas/orlanthi_temple/foyer","west",
"/players/jareel/areas/orlanthi_temple/rune_lord_quarters","east",
"/players/jareel/areas/orlanthi_temple/initiate_quarters","south",
});
}

int peeps;void init() { 
   ::init();
add_action("Search","search");
   peeps++;
   if(find_call_out("wind") == -1) 
   call_out("wind", random(10) + 3);
   }void exit() {
   peeps--;
   if(peeps <= 0) 
   while(remove_call_out("wind") != -1) ; 
   }void wind() { 
   object ob,next; 
   string msg;  switch(random(2)) {
   case 0: msg= "The wind howls as it races in the temple.\n";
   break; 
   case 1: msg= "The wind whistles in your ear.\n";
   break;
   }  tell_room(this_object(),msg);
   call_out("wind", random(10) + 3);
   }

Search(str) {
if(!str) { write("Search what?\n"); return 1; }
  write("You search the "+str+" but find nothing special.\n");
  say(this_player()->query_name()+" searches around for something.\n");
  return 1;
}
