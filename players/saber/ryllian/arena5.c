#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("issiac")) {
move_object(clone_object("/players/saber/monsters/issiac.c"),this_object());  }
if(!present("rock")) {
move_object(clone_object("/players/saber/monsters/rock.c"),this_object()); }
 if(!arg){
  set_light(1);
   short_desc="Arena Pit";
long_desc=
 "You stand upon the dirt floor of the arena, surrounded by towering walls\n"+
 "of dark black stone.  The noise from the crowd fills the air to an almost\n"+
 "tangible aura, echoing and reverberating until you are almost deaf.  You\n"+
 "notice dark crimson stains upon the ground.\n";

items=({
 "arena","An imposing looking structure of colossal proportions",
 "pit","The arena where the gladiators duel",
 "ground","The floor is covered with dirt",
 "stone","The walls are constructed of dark stone",
 "floor","The ground is covered with dirt",
 "stains","There are dark crimson stains upon the ground",
 });

  dest_dir=({
 "/players/saber/ryllian/arena4.c","north",
 "/players/saber/ryllian/arena8.c","east",
 "/players/saber/ryllian/arena6.c","south",
 "/players/saber/ryllian/arena1.c","west",
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
