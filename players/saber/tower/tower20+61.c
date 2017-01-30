#define tp this_player()->query_name()
inherit "room/room";
int i;
reset(int arg){
if(!present("ogre")){
for(i=0;i<2;i++){
move_object(clone_object("/players/saber/monsters/ogre.c"),this_object()); }
}
if(!present("big ogre")){
for(i=0;i<2;i++){
move_object(clone_object("/players/saber/monsters/ogre2.c"),this_object()); }
}
if(!present("ogre chieftan")){
move_object(clone_object("/players/saber/monsters/ogrechief.c"),this_object());  }
 if(!arg){
  set_light(0);
 short_desc="Mountain Cave";
long_desc=
 "You are in a small, cold cave.  Several\n"+
 "creatures seem to have taken refuge here.\n";

items=({
 "cave","A small, cold cave",
 "ground","The floor of the cave is dark stone",
 });

  dest_dir=({
 "/players/saber/tower/tower20+6.c","out",
           });
  }   }
init(){
 ::init();
  add_action("search","search");
}

search() {
  write("You find large footprints leading to the east.\n");
say (tp +" searches the area\n");
 return 1;  }
