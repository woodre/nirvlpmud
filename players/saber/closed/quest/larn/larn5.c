#define tp this_player()->query_name()
inherit "room/room";

reset(int arg){
if(!present("altar"))  {
move_object(clone_object("/players/saber/closed/quest/larn/altar.c"),this_object());  }
 if(!arg){

set_light(1);
short_desc = "The Church of Larn";
long_desc=
 "The church sanctum is shadowed in the dusk of twilight, lit ever\n"+
 "so faintly by the soft glow from the multi-colored stained glass\n"+
 "windows facing west towards the silver moon.  The great Altar of\n"+
 "Larn rests here.  There are arches leading both east and west.\n";

items=({
 "church","You are in the sanctum of the Church of Larn",
 "windows","The stained glass windows take your breath away.\n"+
    "They depict scenes of a silver clad warrior slaying demons",
 "window","The stained glass windows take your breath away.\n"+
    "They depict scenes of a silver clad warrior slaying demons",
 "moon","You can't see the moon through the window",
 });

dest_dir=({
 "/players/saber/closed/quest/larn/larn6.c","east",
 "/players/saber/closed/quest/larn/larn4.c","west",
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

realm()  { return "NT"; }
