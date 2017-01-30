#include "std.h"
#define ADD(XXX,YYY) add_action("XXX"); add_verb("YYY");

#define NOT(X) (string)this_player()->query_real_name() != "X"

int shield_int;
init() {
        ADD(church,church)
        ADD(shop,shop)
        ADD(castle,castle)
     ADD(rump,rump)
        ADD(bagera,bagera)
	ADD(castle,castle)
	ADD(techno,techno)
	ADD(south,south)
        set_light( 1);
        add_action("shield","shield");
        add_action("sstatus","sstatus");
        add_action("emote","emote");
	add_action("echo",";");
        if(this_player()->query_level() < 100 ) {
     if (NOT(dersharp) && NOT(rumplemintz) && NOT(ladyfinger) && shield_int==1) {
        write("You bounce off an invisible shield.\n");
        say(this_player()->query_name()+" bounces of the force shield!\n");
	move_object(this_player(), "/room/church");
        return;

        }
}
}

church() {
        this_player()->move_player("church#room/church");
        return 1;
}
techno() {
	this_player()->move_player("techno#players/dersharp/rooms/enter.c");
	return 1;
}
castle() {
	this_player()->move_player("castle#players/dersharp/castle.c");
	return 1;
}
south() {
  this_player()->move_player("south#players/dersharp/workroomadd.c");
return 1;
}
shop() {
        this_player()->move_player("shop#room/shop");
        return 1;
}
rump() {
	this_player()->move_player("to Rump's workroom#players/rumplemintz/workroom");
        return 1;
}
bagera() {
        this_player()->move_player("to Bag's workroom#players/bagera/workroom");
        return 1;
}
shield(str) {
        if(!str) return 0;
	if (NOT(dersharp)) return 0;
        if(str=="on") {
                shield_int=1;
                write("You envoke a ward of shielding.\n");
                say("Dersharp scrawls a ward in the air and the room is locked.\n");
                }
        else if(str=="off") {
                shield_int=0;
                 write("You erase the ward of shielding.\n");
                say("With a wave of his hand, Dersharp lets down the shield.\n");
                }
        else return 0;
        return 1;
        }

sstatus() {
        if(shield_int==1)
        write("The shield is on.\n");
        else if(shield_int==0)
        write("The shield is off.\n");
        return 1;
        }

emote(str) {
        write(capitalize(this_player()->query_name())+" "+str+"\n");
        say(capitalize(this_player()->query_name())+" "+str+"\n");
        return 1;
        }
echo(str) {
        write(str+"\n");
        say(str+"\n");
	return 1;
	}
                         

      
short() {
        return "The Domicile of Dersharp the Dancin Denizen of Dimension D!";
}
                                             
long() {

	write("     The room you enter is like none other you have seen.\n"+
	      "The room is perhaps twenty by twenty with all the walls covered\n"+
    "with shelves containing a wide variety of books.  It seems like you\n"+
    "will have to go further south to get to the main workroom.  On the\n"+
	      "southern wall is a gigantic window split with lattice work\n"+
	      "and with huge drapes hanging on either side of it.  In the\n"+
	      "room in front of the window lies a great worktable.  There\n"+
              "are beekers and other evidence of past experiments strewn about\n"+
	      "the table carelessly.  An ornately carved chair is in back of\n"+
	      "the worktable and you think you can see a figure there.\n"+
	      " \n"+
	      "The obvious exits: rump, bagera, church, shop, techno, castle.\n");
}
