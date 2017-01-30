#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

int RING;
reset(arg) {
RING == 0;
  if(arg) return 0;
set_light(-1);

long_desc =
  ""+BLK+BOLD+"  A room laid with spikes of different lengths.  The walls\n"+
  "make the room into a square and each one is wallpapered with\n"+
  "sharp spikes.  There is a rope dangling from the trap door\n"+
  "up above.  A "+NORM+"ring on a chain"+BLK+BOLD+" is attached to each wall.\n"+NORM+"";
items = ({
  "spikes","Sharp steel spikes cover the floor and the walls",
  "walls","Each wall is covered from floor to ceiling with spikes.\nA ring on a chain is attacked to each wall",
  "ring on a chain","A steel ring connected to the wall with a chain.\nYou can pull on the ring",
  "rope","A thick rope hanging from the trap door.\nIt can be used to climb out of here",
  "trap door","A wooden trap door in the ceiling",
  "ceiling","The ceiling closes you into the room.\nThere is a trap door in the middle",
});
MOCO("/players/jaraxle/3rd/pyramid/items/skeleton.c"), TO);
MOCO("/players/jaraxle/3rd/pyramid/items/skeleton.c"), TO);
MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/items/sphere.c"),TO);

}

short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("pull","pull");
  add_action("climb","climb");
}

pull(arg){
if(RING >= 1){ write("The ring has been pulled.\n"); return 1; }
if(arg == "ring" || arg == "ring on a chain" || arg == "ring on chain"){
write("You pull hard on the ring.\nThe sound of gears turning escapes from the walls.\n");
say(TPN+" pulls hard on the ring.\nThe sound of gears turning escapes from the walls.\n");
RING += 1;
call_out("crush_me", 4);
call_out("crush_me2", 7);
call_out("crush_me3", 10);
call_out("crush_me4", 13);
call_out("kill_me", 20);
return 1; }
write("Pull what?\n");
return 1; }

climb(arg){
  if(arg == "rope"){      
  write("You pull yourself out of the room, using the rope.\n");
  say(TPN+" climbs out of the room.\n");
 move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/stair_room.c");
  say(TPN+" arrives.\n");
return 1; }                         
write("Climb what?\n");  
return 1; }

crush_me(){
say("The walls slowly close the room in.\n");
}
crush_me2(){
say("The walls continue to close the room in.\n");
}
crush_me3(){
say("The walls are dangerously close to you!\n");
}
crush_me4(){
say("You feel the spikes prick your skin!!\n");
say(HIY+"YOU BETTER CLIMB OUT BEFORE YOU GET HURT!!!\n"+NORM);
}
kill_me(){
object *inv, k;
int i, s;
inv = all_inventory();
s = sizeof(inv);
     say("The walls slam shut crushing everything in the room!\n");
RING -= 1;
   for(i= 0; i < s; i++)
  {
    if (living(inv[i])) 
    {
      inv[i]->add_hit_point(-150);
           if(inv[i]->query_hp() < 1){ /* if the ob should be dead .. */
           k = clone_object("/obj/monster");
           k->set_name(BLK+BOLD+ "Spike Trap" + NORM);
               /* with the name spike trap */
             move_object(k, environment(inv[i]));
               /* move it to the ob */
              inv[i]->attacked_by(k);
              inv[i]->death();
            destruct(k);
        }
      }
    }
say("The walls quickly slide back to their original position.\n");
  return 0;
}
