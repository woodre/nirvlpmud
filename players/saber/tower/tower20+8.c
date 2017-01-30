#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("he Who Must Wait")){
move_object(clone_object("/players/saber/monsters/guardian.c"),this_object());  }
 if(!arg){
  set_light(1);
 short_desc="Mountain Cliffs";
long_desc=
 "You stand atop an icy cliff, with the mountain peek looming to the west.\n"+
 "The wind howls like a banshee, and you feel an icy sensation creeping\n"+
 "into the depths your heart.  The trail continues towards the mountain\n"+
 "peek to the west, while to the north is the beginning of a small animal\n"+
 "path.\n";

items=({
 "clouds","Dark, ominous looking storm clouds",
 "path","A small animal path leading to the north",
 "trail","The trail runs west towards the mountain peak",
 "cliff","You stand at the top of a large cliff.\n"+
       "Looking down you see a large icy plain far below you",
 "mountain","The peak of the mountain looms above you to the west",
 "peak","The peak of the mountain looms above you to the west",
 "ice","Large chunks of frozen ice",
 "ground","The ground is covered with great chunks of frozen ice",
 });

  dest_dir=({
 "/players/saber/tower/tower20+9.c","north",
 "/players/saber/tower/tower20+11.c","west",
 "/players/saber/tower/tower20+71.c","down",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
  write("You find nothing.\n");
say (tp +" searches the area\n");
 return 1;  }
