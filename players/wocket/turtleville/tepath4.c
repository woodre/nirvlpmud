#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;

short_desc = HIG+"A Dirt Path"+NORM;
long_desc = "   This is the dead end of the path.  Back to the northwest the\n"+
            "path winds out of sight.  Many branches are bent or broken here\n"+
            "as travelers have moved carelessly through the bushes.  Mushrooms\n"+
            "can be seen beyond the bushes.\n";
items = ({
    "mushrooms","They are giant with red and white dots",
    "path","An unkept dirt path that winds to the northwest and out of sight",
    "bushes","They have many broken branches which have been 'move'd by many travelers",
    "branches","They have been broken in many places by travelers",
});

smells = ({
  "default","It smells like a fresh day",
});

listens = ({
  "default","You hear the normal sounds of a cheery day",
});

dest_dir = ({
     "/players/wocket/turtleville/tepath2.c","northwest",
});
set_light(1);
}

init(){
  ::init();
add_action("move_bush","move");
}

move_bush(string str){
    if(!str || (str != "bushes" && str != "bush" && str != "branches")){
       notify_fail("What would you like to move?\n");
       return 0;
    }
write("You move back the branches and stumble along a hidden trail.\n");
write("Passing many giant mushrooms you end up in a field with the\n"+
      "trail disappearing behind you.\n");
say(this_player()->query_name()+" moves the bushes and dissappears down a trail.\n");
move_object(this_player(),"/players/wocket/graveyard/gr3.c");
say(this_player()->query_name()+" emerges from a hidden trail.\n");
command("glance",this_player());
return 1;
}
