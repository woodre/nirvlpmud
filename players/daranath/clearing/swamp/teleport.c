#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
   short_desc="You shouldn't be here";
long_desc=
  "A teleport chmber that is made to summon RG monsters.\n";

items=({
 "floor","The floor is covered with broken furniture and broken people",
 });

  dest_dir=({
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
