#include "/players/wocket/closed/ansi.h"
#define MASTER "/players/wocket/caves/mastercr.c"
inherit "/players/wocket/caves/inheritroom.c";


object southroom;

int southexit;

reset(arg){
     
   if(arg) return;
southexit = 1;
MASTER->add_room(file_name(this_object()));
short_desc = MAG+"Dark room"+NORM;
long_desc = ""+
MAG+"   A thick mucus covers everything as it gives off a violet glow.  Small\n"+
    "white plants grow inbetween cracks and rocks of the walls.  Shadows flicker\n"+
    "from the soft light giving movement to the darkness.  There is a large\n"+
    "boulder here blocking the path north.  Dust has settled here and it looks as\n"+
    "if this cavern has not been explored for years.\n"+NORM;
smells = ({
  "default","You smell the musty odor of decay",
});

listens = ({
  "default","You only hear small sounds that echo in the distance",
});

items = ({
    "light","It glows a soft violet",
    "mucus","It covers just about everything.  The slimy substance emminates a soft violet light",
    "plants","They are white and very fragile.  They seem to feed off of the darkness",
    "rocks","They are loose particles that feel from the walls",
    "walls","They are jagged with sharp rocks and covered in a slimy mucus",
    "dust","Thick layers of grey dust",
    "ceiling","Looking much like the walls except with a small hole in it",
    "boulder","A giant round boulder blocking the exit north.  Perhaps if you were strong\nenough you could 'move' it out of the way"
});

dest_dir = ({
  "","south",
});

}

init(){
   add_action("newsouth","south");
   add_action("moveboulder","move");
}

moveboulder(string str){
  if(!str || str != "boulder"){
    notify_fail("What would you like to move?\n");
    return 0;
  }
  if(this_player()->query_attrib("str") < 20){
    write("You try to move the boulder but it does not budge.\n");
    say(this_player()->query_name()+" tries to move the boulder but it does not budge.\n");
  return 1;
  }
  if("/players/wocket/caves/sinjaroom2.c"->query_enter() == 1){
    write("Something is blocking the boulder and it does not move.\n");
    return 1;
 }
write("You push the boulder just enought to slip around it before it comes\ncrashing back in place.\n");
say(this_player()->query_name()+" moves the boulder then slips around it before the boulder rocks back into place.\n");
move_object(this_player(),"/players/wocket/caves/sinjaroom2.c");
say(this_player()->query_name()+" enters.\n");
command("glance",this_player());
"/players/wocket/caves/sinjaroom2.c"->set_enter(1);
return 1;
}
newsouth(){
if(!southexit) return 0;
if(!southroom){
    southroom = clone_object("/players/wocket/caves/croom.c");
    southroom->set_northroom(this_object());
}
move_me(southroom,"south");
return 1;
}

move_me(object room,string way){
  say(this_player()->query_name()+" leaves "+way+".\n");
  move_object(this_player(),room);
  command("glance",this_player());
  say(this_player()->query_name()+" arrives.\n");
}

set_southroom(obj){ southroom = obj; }

