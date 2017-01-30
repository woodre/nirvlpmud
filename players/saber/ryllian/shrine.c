#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
short_desc = "The Shrine";
long_desc=
  "The Shrine is not yet open.\n";

items=({
 });

  dest_dir=({
 "/players/saber/ryllian/ryll5.c","south",
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
