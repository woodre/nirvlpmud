#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
if(!present("priest")){
move_object(clone_object("/players/wocket/turtleville/NPC/priest.c"),this_object());
}
  if(arg) return;
set_light(1);
dest_dir = ({
  "/players/wocket/turtleville/twpath1.c","north",
});
short_desc = HIG+"The Turtleville Cathedral"+NORM;
long_desc = "   High arching stain glassed windows reach for the ceiling filling\n"+
            "the room with a plethora of colored light.  Hardwood floors echo every\n"+
            "slight movement through the cathedral.  A grand pipe organ is built into\n"+
            "the southwest corner with pipes growing along the walls and down into\n"+ 
            "floor.  The hard wooden pews are ornately decorated, handcarved by many\n"+
            "bored monks.\n";
items = ({
    "windows","They are very colorful stained glass",
    "ceiling","Rafters stretch beyond the sky it seems.  Paintings of angels cover the roof",
    "floors","They are inlade with many different woods echoing every slight movement",
    "organ","An ornate pipe organ",
    "pipes","Many brass pipes that seem to crawl along the walls",
    "pews","They are wooden with many ornate carvings",
    "walls","The southeastern wall is covered with pipes while the others hold windows,\npainting and statues",
    "carvings","They are very ornate with detailed carvings of angels, jesus, and other holy stories",
});

smells = ({
  "default","It smells somewhat dusty",
});

listens = ({
  "default","The sound of the a thousand angels singing can softly be heard",
});

}


init(){
  ::init();
  add_action("newsay","say");
}

newsay(str){
  write("You say, \""+str+"\"\n");
  say(this_player()->query_name()+" says, \""+str+"\"\n");
  return 1;
}
