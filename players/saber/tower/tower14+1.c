#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
   short_desc="Eternal Bar Fight Rift";
long_desc=
 "A strange rift is open here, drawing in bar\n"+
 "patrons from other dimensions.\n";

items=({
 "floor","The floor is covered with broken furniture and broken people",
 "pub","The common room of a nameless Inn",
 "rift","A rift open to bars across the known universe",
 "chamber","The common room of a nameless Inn",
 });

  dest_dir=({
 "/players/saber/tower/tower14.c","west",
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
