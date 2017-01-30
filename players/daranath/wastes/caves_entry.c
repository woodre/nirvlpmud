/* Large random number of monsters represents the fact that this is the main cave
   of the complex, with the highest amount of traffic */

#include <ansi.h>
#define tp this_player()->query_name()
#define ROOT "/players/daranath/wastes/"
inherit "room/room";

reset(int arg){
if(!present("cavemon")) {
  int a, b; a = 0; b = (random(5)+2);
while(a<b){
  int c; c = random(20);
if(c == 0) move_object(clone_object(ROOT+"mon/goblin6.c"),this_object());
if(c == 1) move_object(clone_object(ROOT+"mon/goblin5.c"),this_object());
if(c == 2) move_object(clone_object(ROOT+"mon/sledge.c"),this_object());
if(c == 3) move_object(clone_object(ROOT+"mon/goblin4.c"),this_object());
if(c == 4) move_object(clone_object(ROOT+"mon/lurker.c"),this_object());
if(c == 5) move_object(clone_object(ROOT+"mon/lurker.c"),this_object());
if(c == 6) move_object(clone_object(ROOT+"mon/chul.c"),this_object());
if(c == 7) move_object(clone_object(ROOT+"mon/chul.c"),this_object());
if(c == 8) move_object(clone_object(ROOT+"mon/maw.c"),this_object());
if(c == 9) move_object(clone_object(ROOT+"mon/maw.c"),this_object());
if(c ==10) move_object(clone_object(ROOT+"mon/mudman.c"),this_object());
if(c ==11) move_object(clone_object(ROOT+"mon/mudman.c"),this_object());
if(c ==12) move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
if(c ==13) move_object(clone_object(ROOT+"mon/goblin3.c"),this_object());
if(c ==14) move_object(clone_object(ROOT+"mon/goblin2.c"),this_object());
if(c ==15) move_object(clone_object(ROOT+"mon/goblin2.c"),this_object());
if(c > 15) move_object(clone_object(ROOT+"mon/goblin1.c"),this_object());
  a++; }
}
  if(!arg){
    
set_light(1);
short_desc= (BLK+BOLD+"Gundar Caves"+NORM);
long_desc=
"The darkness of the caves engulf you while you explore the outer boundries of\n"+
"the rocky opening. Footprints and tracks run all across the sandy floor, while\n"+
"the cave has several passages running from the main chamber, including a \n"+
"larger one heading north. The rocky walls loom all about you, like\n"+
"someone watching over your shoulder.\n";

items=({
"darkness","The everpresent darkness within the caves is intimidating",
"cave","You stand within a large cave, giving you some shelter from the rocky\n"+
     "wastes. The caves itself looks natural, while natural tunnels run\n"+
     "north, east and west from here",
"caves","Many caves line the rocky outcroppings with the Gundar Wastes",
"rock","The rock within the cave grows darker the further you explore inwards",
"sand","A thin layer of sand runs across the cave floor",
"floor","The cave floor is covered in a thin layer of sand",
"passage","Tunnels run north, east and west from your position",
"walls","The natural rock walls grow darker the further into the cave you look",
"wall","The natural rock walls grow darker the further into the cave you look",
    });

    dest_dir=({
  ROOT+"caves1.c","north",
  ROOT+"caves6.c","east",
  ROOT+"caves4.c","west",
  ROOT+"north_path3.c","exit",
    });

    }
  }

init(){
  ::init();
add_action("search","search");
}

search(){
write("The thin layer of sand contains dozens of tracks, mostly made by goblins.\n"+
      "Brushing aside the sand reveals a smooth, natural slate flooring.\n");
  say(tp +" searches the area.\n");
 return 1;
}

realm() {return "NT"; }

