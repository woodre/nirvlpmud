#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
 if(!arg){

set_light(1);
short_desc = "The Temple of Arate";
long_desc=
"     ==        == \n"+
"     ==        ==           Think tapestries depicting grotesque scenes \n"+
"     ==        =======      of forbidden magiks cover the walls, muting\n"+
"     ==                     the nearby sounds of chanting.  The incense\n"+
"     ==                     haze hangs heavy in your lungs, ebbing tiny\n"+
"     ==        =======      currents of strength from your body. To the\n"+
"     ==        ==           south you see the flicker of fire, and hear\n"+
"     ==        ==           screams of pain.\n";

items=({
 "tapestries","The tapestries depict grotesque scenes of forbidden magiks\n"+
              "You think you see a concealed door behind them to the west",
 "incense","The incense seems to be drifting in from the west",
 "corridor","The corridor is filled with a haze of incense smoke",
 "fire","You see a flicker of fire to the south.\n"+
        "You think it must be a torch",
 "scream","You hear screams of pain from the south",
 "chanting","You source of the chanting is to the west",
 });

dest_dir=({
 "/players/saber/closed/quest/arate/arate14.c","north",
 "/players/saber/closed/quest/arate/arate21.c","east",
 "/players/saber/closed/quest/arate/arate24.c","south",
           });
  }   }

init(){
 ::init();
  add_action("search","search");
  add_action("west","west");
}

search() {
 write("You find a concealed door leading west.\n");
 say (tp +" searches the area.\n");
 return 1;  }

west()  {
  call_other(this_player(), "move_player",
       "through the tapestries#players/saber/closed/quest/arate/arate19.c");
  return 1;
         }

realm()  { return "NT"; }
arate()  { return "YES"; }
