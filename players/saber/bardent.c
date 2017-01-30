#define tp this_player()->query_name()
inherit "room/room";
object light;
int t;
reset(int arg){
if(!present("scroll"))  {
move_object(clone_object("/players/saber/stuff/flier.c"),this_object());  }
if(!present("silus")) {
move_object(clone_object("/players/saber/monsters/bardman.c"),this_object());
}

 if(!arg){
  set_light(1);
  short_desc="Bard Corner";
  long_desc=
"You are in a pleasantly green park.  A path leads north back to\n"+
"the city.  There is also a rift here which leads to the city of\n"+
"Ryllian.\n";

items=({
 "road","A road that leads back to the city",
 "ground","The ground is covered with lush green grass",
  "rift","A rift in time and space",
 "park","You're in a park!  Honest",
  "city","The seaport of Ryllian",
 });

  dest_dir=({
 "/players/saber/ryllian/rift.c","rift",
 "/room/southroad3.c","north",
           });
        }
        }
init(){
 ::init();
  add_action("search","search");
}

search() {
 write("You find nothing\n");
say (tp +" searches the area\n");
 return 1;  }

