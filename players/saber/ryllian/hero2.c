#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("yuki"))  {
move_object(clone_object("/players/saber/monsters/hero/yuki.c"),this_object());  }
 if(!arg){
  set_light(0);
short_desc="Tower of Heros";
long_desc=
"You stand in a dark temple, lit only by a sea of votive candles which whisper\n"+
"out the light to an otherwise shadowed sanctum.  You have a feeling that you\n"+
"should not be here.  There is a staircase in the corner.\n";

items=({
 "temple","You're in a tower, not a temple..",
 "sanctum","You're in a large chamber that somehow reminds you of a temple",
 "staircase","A staircase leading both up and down",
 "candle","A LOT of votice candles",
 "candles","A LOT of votive candles",
 });

  dest_dir=({
 "/players/saber/ryllian/hero3.c","up",
 "/players/saber/ryllian/hero1.c","down",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }
