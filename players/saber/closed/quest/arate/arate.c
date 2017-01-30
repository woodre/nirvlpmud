#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("guard"))  {
move_object(clone_object("/players/saber/monsters/baneguard.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc = "The Temple of Arate";
long_desc=
 "The Temple of Arate, god of death and disease, is not yet open.\n";

items=({
 });

  dest_dir=({
 "/players/saber/ryllian/slums1.c","northeast",
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
