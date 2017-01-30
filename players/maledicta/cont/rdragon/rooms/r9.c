#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";
#include "/players/maledicta/ansi.h"
int peeps;



reset(arg) {
if(!present("cont_dragon", this_object())){
move_object(clone_object("/players/maledicta/cont/mobs/rdragon4.c"), this_object());
move_object(clone_object("/players/maledicta/cont/mobs/rdragon4.c"), this_object());
}

  if(arg) return;
set_light(1);

short_desc = "The Caves of the "+HIR+"Red "+NORM+RED+"Dragon Clan"+NORM;
long_desc =
"  Just beyond a sharp turn in the tunnel you find yourself in\n"+
"a large open chamber. Huge black pillars rise up to the high\n"+
"ceiling overhead. Large holes cover the floor, flames shooting\n"+
"from each of them in steady streams. A large dais rise up in\n"+
"center of the room, a 200 foot wide opening directly above\n"+
"it. To the east the tunnel twists and turns back towards\n"+
"the main chambers.\n"; 

items = ({
"walls",
"Black stone walls made from volcanic rock",
"pillars",
"Large pillars of black stone that rise all the way to the\n"+
"ceiling",
"holes",
"Great holes that seem to run deep into the earth. Long\n"+
"flames lick out at its rim",
"flames",
"Long flames that enter the room through the holes in the floor",
"stone",
"A smooth volcanic stone",
"dais",
"A huge raised platform of volcanic rock. It has seven steps,\n"+
"each about two feet tall that lead to the top of the dais",
"opening",
"A huge opening directly above the dais. You see a glow coming\n"+
"from within it",
});

dest_dir = ({
  "/players/maledicta/cont/rdragon/rooms/r8.c","east",
});

if(!present("king", this_object())){
move_object(clone_object("/players/maledicta/cont/mobs/rdragon5.c"), this_object());
 }
}

init(){
  ::init();
  peeps++;
  if(find_call_out("flames") == -1)
   call_out("flames", random(10) + 3);

add_action("climb_it", "climb");
}

/* Thanks Feldegast for providing an easy template for messages */

void exit() {
  peeps--;
  if(peeps <= 0)
    while(remove_call_out("flames") != -1) ;
  }

void flames() {
  object ob,next;
  string msg;

  switch(random(4)) {
    case 0: msg= HIR+"Fire"+NORM+" scorches the room as it jets from a nearby hole.\n"; break;
    case 1: msg= "Black smoke curls up along the ceiling, twisting and writhing gently.\n"; break;
    case 2: msg= "A nearby hole crackles as fire streams from it.\n"; break;
    case 3: msg= "The fire light bounces off of the walls illuminating the dais.\n"; break;
    }
  tell_room(this_object(),msg);
  call_out("flames", random(10) + 3); 
  }


climb_it(str){
if(!str){
write("climb what?\n");
return 1;
}

if(str == "pillar" || str == "pillars"){
  write("You attempt to climb the pillar...\n");
 if(present("cont_dragon", environment(this_player()))){
   write("You attempt to climb, but the dragon stops you!\n");
   return 1;
   } 
 if(this_player()->query_attrib("ste") + random(100) < random(70)){
   write("\n\n"+HIR+"YOU FALL!!!"+NORM+"\n\n");
   this_player()->hit_player(random(25));
   return 1;
   }
 if(this_player()->query_attack()){
   write("\n\n"+HIR+"You attempt to escape!\nYOU FALL!!!"+NORM+"\n\n");
   this_player()->hit_player(random(25));
   return 1;
   }
  tell_object(this_player(),
  "You successfully climb the pillar up to the hole and enter.\n");
  tell_room(environment(this_player()),
  tpn+" climbs a pillar.\n");
  move_object(this_player(), "/players/maledicta/cont/rdragon/rooms/r10.c");
  tell_room(environment(this_player()),
  this_player()->query_name()+" arrives through the hole in the floor.\n", ({ this_player() }));
  command("look", this_player());
  return 1; 
  }
  write("Climb what?\n");
  return 1;
  }

query_first_room(){ return 1; }
