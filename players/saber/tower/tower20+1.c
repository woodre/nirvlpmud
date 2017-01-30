#define tp this_player()->query_name()
inherit "room/room";
int i;
string search_count;
reset(int arg){
if(!present("corpse")) {
move_object(clone_object("/players/saber/stuff/corpse2.c"),this_object());
}
if(!present("thunder")) {
move_object(clone_object("/players/saber/effects/thunder2.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Mountain Clearing";
long_desc=
 "You are in a small snow covered clearing.  To the east a faint\n"+
 "trail disappears around the edge of the mountain, while to the\n"+
 "west it continues on towards the peak.  Clashing horrifically\n"+
 "against the soft white snow are crimson stained tracks leading\n"+
 "north.  It has begun to snow.\n";

items=({
 "trail","A thin, icy trail covered with a fresh layer of virgin snow",
 "clearing","A large, snow filled clearing",
 "clouds","Dark, ominous looking storm clouds",
 "mountain","You can't see it because of the clouds",
 "peak","You can't see it because of the clouds",
 "footprints","Large, blood stained footprints left in the snow",
 "tracks","Large, blood stained footprints left in the snow",
 "snow","A fresh layer of virgin snow coveres the ground",
 "ground","A fresh layer of virgin snow coveres the ground",
 });

  dest_dir=({
 "/players/saber/tower/tower20+2.c","north",
 "/players/saber/tower/tower20+02.c","east",
 "/players/saber/tower/tower20+3.c","west",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
if(search_count == 1){
move_object(clone_object("/players/saber/weapons/broadsword.c"),this_player());
write("You find a sword buried in the snow.\n");
say(tp+" picks up a sword.\n");
search_count = search_count + 1;
return 1;
}
search_count = search_count + 1;
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

