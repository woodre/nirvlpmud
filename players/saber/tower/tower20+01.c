#define tp this_player()->query_name()
inherit "room/room";
int i;
object OBJ;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Mountain Trail";
long_desc=
"You are traveling along a thin, ice covered trail.  The mountain\n"+
 "peak looms majestically over head, while below you is endless snow.\n";

items=({
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clouds","It looks like it might snow soon",
 "mountain","You are near the peak of a snow covered mountain",
 "peak","You are near the peek of a snow covered mountain",
 "landscape","You are near the peak of a snow covered mountain",
 "snow","A fresh layer of virgin snow coveres the ground",
 "ground","A fresh layer of virgin snow coveres the ground",
 });

  dest_dir=({
 "/players/saber/tower/tower20.c","east",
 "/players/saber/tower/tower20+02.c","west",
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
