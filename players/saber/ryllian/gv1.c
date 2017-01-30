#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Green Valley";
long_desc=
 "You are traveling through a green valley of pleasantly warm climate,\n"+
 "sheltered as it is from the cold sea breezes by its high mountain walls.\n"+
 "The stars above gleam softly, dimly covering the valley in their pale\n"+
 "celestial illuminance.\n";

items=({
 "mountain", "The valley is sheltered by tall, snow covered mountains",
 "ground","The valley floor is covered with lush green grass",
 "stars","Softly gleaming stars are visible overhead",
 "valley","A luscious green valley with a pleasantly warm climate",
 "walls","The valley is sheltered by tall, snow covered mountains",
 });

  dest_dir=({
 "/players/saber/ryllian/gv2.c","west",
 "/players/saber/ryllian/ryllian1.c","east",
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
