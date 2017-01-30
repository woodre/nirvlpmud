#define tp this_player()->query_name()
inherit "room/room";
object light;
int t;
reset(int arg){
 if(!present("bugs")){
move_object(clone_object("/players/saber/monsters/bedbugs.c"),this_object());
}
 if(!arg){
  set_light(0);
  short_desc="A small cave";
long_desc=
 "A small dark cave, just big enough for two very friendly people\n";

items=({
 "cave", "A small dark cave, just big enough for two very friendly people",
 "ground","The bottom of the cave",
      });

 dest_dir=({
 "/players/saber/ryllian/gv3.c","out",
 });
  }   }
init(){
 ::init();
  add_action("search","search");
   }

search() {
  write("You think you might hear something...\n");
say (tp +" searches the area\n");
 return 1;  }

