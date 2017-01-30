#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("thunder")) {
move_object(clone_object("/players/saber/effects/thunder.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Mountain Trail";
long_desc=
 "You are traveling along a thin, icy trail.  The mountain peak\n"+
 "looming overhead has become lost amidst a host of dark storm clouds.\n";

items=({
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clouds","Dark, ominous looking storm clouds",
 "mountain","You can't see it because of the clouds",
 "peak","You can't see it because of the clouds",
 "snow","A fresh layer of virgin snow coveres the ground",
 "ground","A fresh layer of virgin snow coveres the ground",
 });

  dest_dir=({
 "/players/saber/tower/tower20+01.c","east",
 "/players/saber/tower/tower20+1.c","west",
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
