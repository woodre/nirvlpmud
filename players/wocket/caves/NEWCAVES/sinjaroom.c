inherit "/room/room.c";

#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/caves/NEWCAVES/"

void reset(status arg){
    if(arg) return;
    short_desc = MAG+"Dark room"+NORM;
    long_desc = ""+
    MAG+"   A thick mucus covers everything as it gives off a violet glow.  Small\n"+
    "white plants grow inbetween cracks and rocks of the walls.  Shadows flicker\n"+
    "from the soft light giving movement to the darkness.  There is a large\n"+
    "boulder here blocking the path north.  Dust has settled here and it looks as\n"+
    "if this cavern has not been explored for years.\n"+NORM;
    items = ({
      "light","It glows a soft violet",
      "mucus","It covers just about everything.  The slimy substance emminates a soft violet light",
      "plants","They are white and very fragile.  They seem to feed off of the darkness",
      "rocks","They are loose particles that fell from the walls",
      "walls","They are jagged with sharp rocks and covered in a slimy mucus",
      "dust","Thick layers of grey dust",
      "boulder","A giant round boulder blocking the exit north.  Perhaps if you were strong\nenough you could 'move' it out of the way"
    });
    dest_dir = (({ }));
}

void init(){
    ::init();
    add_action("moveboulder","move");
}

status moveboulder(string str){
    object obj;
    obj = find_object("/players/wocket/caves/NEWCAVES/sinjaroom2.c");
    if(!str || str != "boulder"){
	notify_fail("What would you like to move?\n");
	return 0;
    }
    if(this_player()->query_attrib("str") < 20){
	write("You try to move the boulder but it does not budge.\n");
	say(this_player()->query_name()+" tries to move the boulder but it does not budge.\n");
	return 1;
    }
    if(obj){
	if(obj->query_occupied()){
	    write("Something is blocking the boulder and it does not move.\n");
	    return 1;
	}
    }
    write("You push the boulder just enought to slip around it before it comes\ncrashing back in place.\n");
    say(this_player()->query_name()+" moves the boulder then slips around it before the boulder rocks back into place.\n");
    move_object(this_player(), PATH+"sinjaroom2.c");
    environment(this_player())->set_occupied(1);
    say(this_player()->query_name()+" enters.\n");
    command("look",this_player());
    return 1;
}
