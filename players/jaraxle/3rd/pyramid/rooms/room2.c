#include "/players/jaraxle/define.h"
inherit "/players/jaraxle/room.c";
int SAND, OPEN;
reset(arg) {
SAND = 0;
OPEN = 0;
  if(arg) return;
set_light(-1);

long_desc =
        ""+BLK+BOLD+"  Columns lay broken down on the floor of the pyramid.\n"+
        "The floor is dusted lightly with sand.  The air is thick\n"+
        "and smells of rotting flesh.  There are no walls around\n"+
        "this room, just passageways in many directions."+NORM+"\n";

items = ({
  "pyramid","A large structure made from clay stone",
  "sand","blah",
  "floor","The ground of the pyramid is covered with sand",
  "columns","Thick columns laying on the ground.  Broken and deteriorating",
});

dest_dir = ({
  "/players/jaraxle/3rd/pyramid/rooms/room.c","south",
  "/players/jaraxle/3rd/pyramid/rooms/roome2.c","east",
  "/players/jaraxle/3rd/pyramid/rooms/roomw2.c","west",
  "/players/jaraxle/3rd/pyramid/rooms/roome.c","southeast",
  "/players/jaraxle/3rd/pyramid/rooms/roomw.c","southwest",
  "/players/jaraxle/3rd/pyramid/rooms/roome3.c","northeast",
  "/players/jaraxle/3rd/pyramid/rooms/room3.c","north",
});

MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
MOCO("/players/jaraxle/3rd/pyramid/items/statue.c"),TO);
}
short(){ return ""+BOLD+""+BLK+"Dark Pyramid"+NORM+""; }
realm() { return "NT"; }

init(){
    ::init();
  add_action("sift","sift");
  add_action("open","open");  
  add_action("enter","enter");}

long(arg)
{
    if(arg == "sand")
    {
      string mod;

      if(SAND == 1)
        mod = "has beed sifted";
      else
        mod = "can be sifted";

      write("The sand is very smooth to the touch, and light tan in color.\n" +
            "It looks as though the sand "+mod+".\n");

      return;
    }

   ::long(arg);
}

sift(arg){          
  if(SAND == 1){ write("The sand has been sifted already.\n"); return 1; }
  if(arg == "sand"){
    write("You sift through the sand and find a door in the floor\n"+
          "You can open the door.\n");        
SAND +=1;return 1; }
    write("Sift what?\n");
return 1; }

open(arg){      
  if(SAND == 0){ write("Open what?\n"); return 1; }
  if(OPEN == 1){ write("The door has already been opened.\n"); return 1; }
  if(arg == "door"){      
    write("You open the door.\n"+
          "There is a room below you can "+HIW+"enter"+NORM+".\n");
OPEN +=1;
return 1; }
    write("Open what?\n");  
return 1; }

enter(arg){
  if(SAND == 0){ write("Enter what?\n"); return 1; }
  if(OPEN == 0){ write("Enter what?\n"); return 1; }   

  if(arg == "room"){
    write("You drop down into the dark room.\n");
    say(TPN+" disappears into the floor!\n");
 move_object(this_player(), "/players/jaraxle/3rd/pyramid/rooms/drop_room.c");  
return 1; }
    write("Enter what?\n");
return 1; }
