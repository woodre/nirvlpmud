#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("dragon"))  {
move_object(clone_object("/players/saber/monsters/hero/rdragon.c"),this_object());  }
 if(!arg){
  set_light(0);
short_desc="Tower of Heros";
long_desc=
"You stand in a large, dark chamber.  There is a staircase in the corner\n"+
"leading to the higher points of the tower.  This place somehow reminds\n"+
"you of a large cave...";

items=({
 "cave","You're in a tower, not a cave..",
 "chamber","You're in a large chamber that somehow reminds you of a cave",
 "staircase","A staircase leading up",
 });

  dest_dir=({
 "/players/saber/ryllian/hero.c","south",
 "/players/saber/ryllian/hero2.c","up",
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
