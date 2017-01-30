inherit "/room/room.c";

#include "/players/wocket/closed/ansi.h"
#define PATH "/players/wocket/caves/NEWCAVES/"

int occupied;

void reset(status arg){
    if(!present("sinja"))
	move_object(clone_object("/players/wocket/caves/NPC/sinja.c"),this_object());
    if(arg) return;
    short_desc = MAG+"Dark room"+NORM;
    long_desc = MAG+
    "   The walls are mauled with deep lacerations that split the\n"+
    "natural cracks of the rock.  Bones litter the ground around the\n"+
    "entrance.  A thick mucus covers much of the ground giving off a\n"+
    "soft glow.  There is a large boulder to the south blocking any\n"+
    "escape.  This cave appears to be the habitate of a very large\n"+
    "creature from the tail tracks left in the dust.\n"+NORM;
    items = ({
      "mucus","It covers just about everything.  The slimy substance emminates a soft violet light",
      "walls","They are very ruff and filled with loose rocks",
      "bones","They are bright white as if licked clean",
      "tracks","There are slither markings in the dust",
      "lacerations","Deep cuts looking very similar to teeth marks",
      "rock","A sandstone the walls are made from",
      "ground","It is covered with dust and bones",
      "boulder","A giant round boulder blocking the exit south.  Perhaps if you were strong\nenough you could 'move' it out of the way",
      "dust","Thick layers of grey dust",
    });
}

void init(){
    ::init();
    add_action("moveboulder","move");
}

int query_occupied(){ return occupied; }
void set_occupied(int i){ occupied = i; }

status moveboulder(string str){
    if(!str || str != "boulder"){
	notify_fail("What would you like to move?\n");
	return 0;
    }
    if(this_player()->query_attrib("str") < 20){
	write("You try to move the boulder but it does not budge.\n");
	say(this_player()->query_name()+" tries to move the boulder but it does not budge.\n");
	return 1;
    }
    if(this_player()->query_attack()){
	write("As you try to move the boulder your opponent hits you back.\n");
	return 1;
    }
    write("You push the boulder just enough to slip around it before it comes\ncrashing back in place.\n");
    say(this_player()->query_name()+" moves the boulder then slips around it before the boulder rocks back into place.\n");
    move_object(this_player(), PATH+"sinjaroom.c");
    set_occupied(0);
    say("The boulder moves slightly.\n"+this_player()->query_name()+" arrives.\n");
    command("look",this_player());
    return 1;
}

realm(){ return "NT"; }
