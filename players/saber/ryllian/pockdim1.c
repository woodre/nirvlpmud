#define tp this_player()->query_name()
inherit "room/room";
int t;
reset(int arg){
if(!present("thug"))  {
move_object(clone_object("/players/saber/monsters/thug.c"),this_object());        }
if(!present("machine"))  {
move_object(clone_object("/players/trix/castle/recharger.c"),this_object());        }
 if(!arg){
  set_light(1);
short_desc = "A pocket dimension";
long_desc=
  "You are in a featureless black pocket dimension which\n"+
  "echos faintly with the sounds of techno music.\n";

items=({
 });

  dest_dir=({
 "/players/saber/ryllian/ms8.c","out",
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
