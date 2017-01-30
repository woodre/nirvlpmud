#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("priestess"))  {
move_object(clone_object("/players/saber/closed/new_mini/agents/larn.c"),this_object());  }
 if(!arg){
  set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "The Church of Larn is not yet open.\n";

items=({
 });

  dest_dir=({
 "/players/saber/ryllian/ryll5.c","east",
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
