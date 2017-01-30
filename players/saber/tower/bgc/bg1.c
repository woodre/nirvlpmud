#define tp this_player()->query_name()

inherit "room/room";
int i;

reset(int arg){

if(!present("guy")) {
  for(i=0;i<2;i++)  {
 move_object(clone_object("/players/saber/monsters/dancerm.c"),this_object());
        }
        }
if(!present("girl"))  {
  for(i=0;i<3;i++)  {
move_object(clone_object("/players/saber/monsters/dancer.c"),this_object());
        }
        }

  if(!arg){

  set_light(1);
  short_desc="Hot Legs Dance Club";
  long_desc=
"The music cascades over your senses as you enter 'Hot Legs' dance club.\n"+
"Bright lights flash, and the music courses through your system.  The deep bass\n"+
"pumps through your body like a second heartbeat.  Weaving your way through the\n"+
"masses of gyrating bodies as you cross the dance floor you can feel their body\n"+
"heat and smell their sweat.  Playing up upon the stage to the west is the band\n"+
"'Priss and The Replicants.'\n";

items=({
 "club","You are in the infamous 'Hot Legs' dance club",
 "light","The room is illuminated by lights flashing to the rhythm of the music",
 "masses","The room is full of dancing people",
 "bodies","The room is full of dancing people",
 "floor","The dance floor is filled by masses of dancing people",
 "stage","To the south is the stage where the band is playing",
 "band","To the south is the stage where the band is playing",
 "priss","You see Priss singing to the south",
 "replicants","The Replicants are playing to the south",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg2.c","east",
 "/players/saber/tower/bgc/bg6.c","stage",
           });
    }    }


init(){
 ::init();
  add_action("search","search");
        }

search() {
 write("You find nothing\n");
 say (tp +" searches the area\n");
 return 1;  }
