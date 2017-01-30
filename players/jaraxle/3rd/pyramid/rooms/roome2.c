#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
int CHEST;
reset(arg) {
CHEST = 0;
  if(arg) return;
set_light(-1);

long_desc =
        ""+BLK+""+BOLD+"  The pyramid walls block you in on the eastern side of the room.\n"+
        "There are large columns on the west side making a hallway through\n"+
        "the room for you to pass through.  A chest sits in the center of\n"+
        "room.  Dust and sand covers everything in the area."+NORM+"\n";


items = ({
  "chest", "blah", /* just to add the id */
  "sand","Tan colored sand covers the pyramid floor",
  "dust","Clouds of dust floating around the room, kicked up by visitors",
  "pyramid","A large structure made from clay stone",
  "ground","The ground of the pyramid is coverd with sand and dust",
  "columns","Thick columns of stacked clay cylinder blocks on the west side of the room",
  "walls","Thick walls made of clay stone stacks",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/room2.c","west",
  "/players/jaraxle/3rd/pyramid/rooms/roome.c","south",
  "/players/jaraxle/3rd/pyramid/rooms/room.c","southwest",
  "/players/jaraxle/3rd/pyramid/rooms/roome3.c","north",
  "/players/jaraxle/3rd/pyramid/rooms/room3.c","northwest",
});
MOCO("/players/jaraxle/3rd/pyramid/mon/revenant.c"),TO);
}

short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("open","open");
  add_action("close","close");
}

long(arg)
{
    if(arg == "chest")
    {
      string mod;

      if(CHEST == 1)
        mod = "open";
      else
        mod = "closed";

      write("A large chest about four feet long.\n" +
            "The chest is " + HIW + "[" + NORM + mod + HIW + "]" + NORM
            +".\n");

      return;
    }

    ::long(arg);
}

close(arg){
if(arg == "chest"){
write("The chest is stuck open.\n");
return 1; }
write("Close what?\n");
return 1; }

open(arg){
  if(arg == "chest"){      
if(CHEST >= 1){ write("The chest has already been opened.\n");
return 1; }
switch(random(11)){

case 0..4:
  write("You open the chest and take some items!\n");
MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),TP);
MOCO("/players/jaraxle/3rd/pyramid/items/prize3.c"),TP);
CHEST += 1;
break;

case 5..10:
  write(MAG+"As you try to open the chest, acid squirts out over your face!\n"+NORM);
  TP->add_hit_point(-1-random(10));

break;

}
return 1; }                         
write("Open what?\n");  
return 1; }

