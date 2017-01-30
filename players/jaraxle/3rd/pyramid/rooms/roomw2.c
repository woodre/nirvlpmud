#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";

reset(arg) {
  if(arg) return;
set_light(-1);

long_desc =
    ""+BLK+BOLD+"  A long stairway leeds northbound deeper into the pyramid.\n"+
    "The smells of rotting flesh, and blood swarm over the room.\n"+
    "The walls are covered  with large, intricate cobwebs.  Looming\n"+
    "columns line the eastern wall.  Dust has settled effortlessly\n"+
    "on the floor."+NORM+"\n";

items = ({
  "stairway","A stone stairway that leads down, deeper into the pyramid",
  "pyramid","A large structure made from clay stone",
  "walls","Walls made of stone, and clay.\nThe walls are covered in cobwebs",
  "cobwebs","Large, intricate patterns of webbing, made from spiders",
  "columns","Thick columns of stacked clay cylindar blocks",
  "wall","Cobwebs of intence patterns cover the stone wall",
  "dust","Fine grains of sand, unmoved for ages",
  "floor","The hard floor of the pyramid, covered in dust",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/room2.c","east",
  "/players/jaraxle/3rd/pyramid/rooms/room.c","southeast",
  "/players/jaraxle/3rd/pyramid/rooms/roomw.c","south",
  "/players/jaraxle/3rd/pyramid/rooms/room3.c","northeast",
  "/players/jaraxle/3rd/pyramid/rooms/stair_room.c","stairway",
});

}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

