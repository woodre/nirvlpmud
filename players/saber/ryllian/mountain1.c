#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
 if(!arg){
  set_light(1);
 short_desc="Spine of the Moon";
long_desc=
 "You stand in the foothills of the Spine of the Moon mountain range.  To\n"+
 "the north and northeast you see massive crags of towering rock and stone\n"+
 "ascending towards the heavens.  To the south you see a green valley and\n"+
 "the road which runs to the city of Ryllian.  Beyond Ryllian can be seen\n"+
 "the deep blue hue of the Sea of Stars.\n";

items=({
 "stars","Softly gleaming stars are visible overhead",
 "mountain","Massive crags of towering rock loom over you",
 "mountains","Massive crags of towering rock loom over you",
 "crags","Massive crags of towering rock loom over you",
 "stone","Massive crags of towreing rock loom over you",
 "valley","To the south is a plesant green valley",
 "road","The road leads to the city of Ryllian",
 "sea","The Sea of Stars lies south beyond the city of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/mountain2.c","up",
 "/players/saber/ryllian/ryllian1.c","south",
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
