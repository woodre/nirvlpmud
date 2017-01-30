#include "/players/forbin/realms/keats/keatsdefine.h"
inherit "/players/forbin/realms/keats/room.c";

string Location;

reset(arg) {
	if(!present("the tower of the magi")) 
	{ 
		move_object(clone_object("/players/forbin/mages/obj/tower.c"), this_object());
  }
  if(!present("the holy church of the spoken sacrament")) 
	{ 
		move_object(clone_object("/players/forbin/realms/keats/OBJ/church.c"), this_object());
  }
  if(arg) return;
  short_desc = KEATS;
  Location = "Square of Sad King Billy";
  long_desc = 
    "\n                   "+HIW+"Saint Antonnius Way"+HIC+"     (["+NORM+"northeast"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"The Vigeous Road"+HIC+"        (["+NORM+"southeast"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"The Avenue of the Word"+HIC+"  (["+NORM+"north"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"The Path of the Dead"+HIC+"    (["+NORM+"southwest"+HIC+"])"+NORM+"\n"+
    "                   "+HIW+"Grand Market Street"+HIC+"     (["+NORM+"northwest"+HIC+"])"+NORM+"\n"+
    "  The Great Square of Sad King Billy stretches hundreds of men across,\n"+
    "the pentagonal square marking the civic center of the City of Keats.\n"+
    "Wide, towering gates stand at each apex of the square, marking the\n"+
    "commencement of each of the five major thoroughfares inside the city.\n"+
    "A broad cobbled pathway circles the expanse of grass that makes up the\n"+
    "bulk of the plaza.  On the western edge of the square lies "+HIW+"The Holy\n"+
    "Church of the Spoken Sacrament"+NORM+", while directly across from it stands\n"+ 
    "the "+HIM+"T"+NORM+MAG+"ower of the "+HIM+"M"+NORM+MAG+"agi"+NORM+".\n";
  add_item(({"city","keats","city of keats"}),"a");
  add_item(({"gate","gates","towering gate","towering gates"}),"b");
  add_item(({"thoroughfare","thoroughfares"}),"c");  
  add_item(({"path","pathway","cobbled path","cobbled pathway"}),"d");
  add_item(({"grass","plaza"}),"e");
  add_item(({"saint antonnius way","antonnius way","way"}),"f");
  add_item(({"the vigeous road","vigeous road","road"}),"g");
  add_item(({"the avenue of the word","avenue","avenue of the word","avenue of word"}),"h");
  add_item(({"the path of the dead","path","path of the dead","path of dead"}),"i");
  add_item(({"grand market street","market street","street"}),"j");
  add_exit(RMS+"1antonius01.c", "northeast");
  add_exit(RMS+"1viggus01.c", "southeast");
  add_exit(RMS+"1word01.c", "south");
  add_exit(RMS+"1morti01.c", "southwest");
  add_exit(RMS+"1market01.c", "northwest");
  set_light(1);
}

init() {
  ::init();
  add_action("cmd_ne","northeast");
  add_action("cmd_ne","ne");
  add_action("cmd_se","southeast");
  add_action("cmd_se","se");
  add_action("cmd_sw","southwest");
  add_action("cmd_sw","sw");
  add_action("cmd_nw","northwest");
  add_action("cmd_nw","nw");
}

status cmd_ne() 
{
  tell_object(this_player(),
    "The gateway leading to "+HIW+"Saint Antonnius Way"+NORM+" is closed indefinitely.\n");
  return 1; 
}

status cmd_se() 
{
  tell_object(this_player(),
    "The gateway leading to "+HIW+"The Vigeous Road"+NORM+" is closed indefinitely.\n");
  return 1; 
}

status cmd_sw() 
{
  tell_object(this_player(),
    "The gateway leading to "+HIW+"The Path of the Dead"+NORM+" is closed indefinitely.\n");
  return 1; 
}

status cmd_nw() 
{
  tell_object(this_player(),
    "The gateway leading to "+HIW+"Grand Market Street"+NORM+" is closed indefinitely.\n");
  return 1; 
}
