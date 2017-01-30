#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
   short_desc="Arena Pit";
long_desc=
 "You stand in the far corner of the gladiator arena, surrounded by large\n"+
 "walls of dark stone.  To the east is the fighting pit, while below you\n"+
 "is a tunnel leading down into the shadowy depths of the arena dungeon.\n";

items=({
 "arena","An imposing looking structure of colossal proportions",
 "pit","The arena where the gladiators duel",
 "ground","The floor is covered with dirt",
 "stone","The walls are constructed of dark stone",
 "floor","The ground is covered with dirt",
 "walls","The walls of the arena are constructed from dark stone",
 "dungeon","The dungeon lies below the arena",
 });

  dest_dir=({
 "/players/saber/ryllian/arena8.c","west",
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
