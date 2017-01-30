#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("vishra"))  {
move_object(clone_object("/players/saber/monsters/hero/scorp.c"),this_object());  }
 if(!arg){
  set_light(0);
short_desc="Tower of Heros";
long_desc=
 "You stand in a hot, dry chamber constructed from old stone.  The air\n"+
 "is stale and smells slightly of death.  From all directions you hear \n"+
 "the faint sounds of a slow, rhythmic breathing.\n";

items=({
 "stone","The stone is worn and old",
 "breathing","You can not see the source of the breathing",
 "death","Your death waits for you here",
 });

  dest_dir=({
 "/players/saber/ryllian/hero3.c","down",
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
