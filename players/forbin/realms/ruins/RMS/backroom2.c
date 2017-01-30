
#include "/players/maledicta/ansi.h"

#define tp this_player()
#define tpn this_player()->query_name()
#define tpp this_player()->query_possessive()
inherit "room/room";

reset(arg) {
if(!present("dealer_board", this_object())){
 move_object(clone_object("/players/maledicta/closed/symbio/symbioboard.c"), this_object());
 }
  if(arg) return;
set_light(1);
dest_dir = ({
  "/players/forbin/realms/ruins/RMS/r07.c","out",
});

}
long(){
write(BOLD+BLK+"  Particles of dust and ash float about on the wind.  The floor of the\n"+
           "forest is covered in a wash of black residue.  The smoke and smell of\n"+
           "smoldering wood wafts about.\n"+
           "           There are three obvious exits: north, south and west\n"+NORM);
if(this_player())
if(present("clan_symbio", this_player())){
write("The true exit is 'out'.\n"+
	  "There is a "+HIG+"Display"+NORM+" here.\n");
return 1;
}
return 1;
}

short() { 
	string desc;
	switch(random(5)) {
		case 0:	desc = "Dark room"; break;
		case 1: desc = "Dark room"; break;
		case 2: desc = HIW+"The Ruins"+NORM; break;
		case 3: desc = HBRED+HIW+"The Flame Forest"+NORM+NORM; break;
		case 4: desc = HBRED+HIW+"The Flame Forest"+NORM+NORM; break;		
	}
	return desc; 
}

init(){
    ::init();
if(this_player()) 
if(!present("clan_symbio", this_player()) && !this_player()->is_pet())
 move_object(this_player(), "/players/forbin/realms/ruins/RMS/r07.c");
}


