#define tp this_player()->query_name()
inherit "room/room";
int i;
object OBJ;
reset(int arg){
if(!present("wind")) {
  OBJ = clone_object("/players/saber/effects/WIND.c");
  move_object(OBJ, this_object());
  destruct(OBJ);
        }
 if(!arg){
  set_light(1);
 short_desc="Mountain Wilderness";
long_desc=
 "A stark, snow covered mountain landscape near the top of the world.  Looking\n"+
 "around, you believe that you can probably see forever.  Overhead loom ominous\n"+
 "looking storm clouds.  To the west is a barely discernible trial leading\n"+
 "towards the peak of the mountain.\n"+
 "A portal stands here.\n";

items=({
 "portal","A dark stone portal filled with a hazy blue aura",
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clouds","It looks like it might snow soon",
 "mountain","You are near the peak of a snow covered mountain",
 "landscape","You are near the peak of a snow covered mountain",
 "snow","A fresh layer of virgin snow coveres the ground",
 "ground","A fresh layer of virgin snow coveres the ground",
 "world","You are in the world of the Shadow of the Sun",
 });

  dest_dir=({
 "/players/saber/tower/tower6.c","portal",
 "/players/saber/tower/tower20+01.c","west",
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
