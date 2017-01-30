#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
  short_desc="Under a table";
long_desc=
  "You are under a table.\n"+
  "All around you rages the eternal bar fight.\n";

items=({
 "floor","The floor is covered with broken furniture and broken people",
 "pub","The common room of a nameless Inn",
 "table","You are under a table",
 "chamber","The common room of a nameless Inn",
 });

  dest_dir=({
 "/players/saber/tower/tower14.c","up",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
write("You don't find anything worth keeping.\n");
say (tp +" searches the area\n");
 return 1;  }
