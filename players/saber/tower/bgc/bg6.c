#define tp this_player()->query_name()

inherit "room/room";
int a, i;

reset(int arg){

if(!present("priss")) {
 move_object(clone_object("/players/saber/monsters/priss.c"),this_object());
        }

if(!present("girl"))  {
  for(i=0;i<2;i++)  {
move_object(clone_object("/players/saber/monsters/dancerf.c"),this_object());
        }
        }

  if(!arg){

  set_light(1);
  short_desc="Hot Legs Dance Club";
  long_desc=
"You stand upon the stage of the Hot Legs Club, surrounded by musical\n"+
"instruments and walls of speakers.  Bright lights flash at irregular\n"+
"intervals about you.  The bass rocks you to your soul.\n";

items=({
 "club","You are in the infamous 'Hot Legs' dance club",
 "light","The room is illuminated by lights flashing to the rhythm of the music",
 "instruments","There are many high tech musical instruments scattered about",
 "speakers","There is a wall of speakers on each side of the stage,\n"+
  "as well as a multitude of feedback speakers",
 });


  dest_dir=({
 "/players/saber/tower/bgc/bg1.c","north",
 "/players/saber/tower/bgc/bg12.c","backdoor",
           });
    }    }


init(){
 ::init();
  add_action("search","search");
        }

search() {
  if(a < 1)  {
 a = a + 1;
 write("You find an electric guitar!\n");
 say(tp+" picks up an electric guitar!\n");
move_object(clone_object("/players/saber/stuff/elect.c"),this_player());
  return 1;
        }
 write("You find nothing\n");
 say (tp +" searches the area\n");
 return 1;  }
