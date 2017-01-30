#include "/players/snakespear/closed/ansi.h"
inherit "room/room";
short () {
      return (HIW+"The "+GRY+"Gentleman's "+HIW+"Sanctum"+NORM);
      }
reset(arg){
   if(!present("machine")) {
     move_object(clone_object("/players/snakespear/tools/tmachine.c"),this_object()); 
   }
   if(!present("computer")) {
     move_object(clone_object("/players/snakespear/tools/smail.c"),this_object()); 
   }
   if(arg) return;
      
set_light(1);
long_desc=
 "  This is the Gentlemans' Sanctum.  The hard obsidian floor shines with\n"+
 "the gentle lighting from a few oil lamps.  A delicate aroma fills the\n"+
 "room.  There is a large wooden desk set in one corner with a small lamp\n"+
 "on it's corner.  On the other side of the sanctum is a stereo with a rack\n"+
 "of compact discs beside it.  The stereo is playing music that is coming\n"+
 "from a nice set of Advent speakers that are located in each corner.  Along\n"+
 "the wall there is a black leather couch with a few throw pillows beside\n"+
 "each arm.  The fireplace that sits midway through the far wall is glowing\n"+
 "with a faint fire that seems to burn eternally.  A small piece of paper\n"+
 "sits on the hearth of the fireplace.  Impressionistic paintings line the\n"+
 "smooth, dark walls.  If you really want to leave, you can always go 'out'.\n";

items=({
     "floor", "A lovely dark floor that is smooth as silk",
     "lamps", "Small flames burning on different colored oils",
     "desk", "An old oak desk that looks well oiled and cared for",
     "stereo", "A midsized Sony stereo with all the latest features",
     "speakers", "One pair of Advent tower speakers with an hardwood finish",
     "corner", "Empty corners that seem to be kept clean and tidy",
     "wall","Thick wall made from marble with many dark swirls",
     "couch","A nice, genuine leather couch that looks well used",
     "pillows","Elegant looking pillows that look very comfortable",
     "arm","Each end of the couch is graced with pluch leather arms",
     "fireplace","The fireplace glows with an odd flame, 'dive'ing into it looks fun!",
     "fire","An eternal flame, always burning with nothing to fuel it",
     "flame","An eternal flame with nothing to fuel it",
     "paper","A piece of paper with some writing on it",
     "hearth","The ledge of the fireplace with plenty of room for resting",
     "paintings","Large paintings of Zultayne and it's battles.\n"+
                 "You might want to 'touch' one",
     "walls","Thick walls made from marble with many dark swirls",
});
    
}

realm() { return "NT"; }

init() {
    ::init();
    write(HIG+"\nYou flail wildly as your body is sent somewhere..\n"+NORM);
    write(GRY+"\nAs fast as you are traveling, you seem to not be moving..\n"+NORM);
    write(HIG+"\nFinally... you land....\n"+NORM);
    write("\nYou have entered "+HIW+"The "+GRY+"Gentlemans' "+HIW+"Sanctum"+NORM+"!!\n\n");
    add_action("search_room","search");
    add_action("listen","listen");
    add_action("smell","smell");
    add_action("touch","touch");
    add_action("out","out");
    add_action("read","read");
    add_action("dive","dive");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
  if(str == "desk") {
	    write("You find some erotic poetry and adult short stories.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "aroma") {
	    write("Mmmm.. the nice smell of patchouli fills the air.\n");
	    return 1; }
	  else {
	    write("You can't smell that.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "music") {
	    write("You get lost in the hard jams of Pantera.\n");
	    return 1; }
	  else {
	    write("You can't listen to that.\n");
	    return 1; }  
}
touch(str) {
      if(!str) {
        write("What are you trying to touch?\n");
        return 1; }
      if(str == "painting") { 
        call_other(this_player(),"move_player","the room#players/snakespear/zultayne/rooms/zentry");
        return 1; }
      else {
        write("You touch the "+str+", then smile.\n");
        return 1; }
}
dive(str) {
      if(!str) {
        write("Dive into what?\n");
        return 1; }
      if(str == "fireplace" || "flame") { 
        write("This isn't quite open yet... try diving another day!\n");
        return 1; }
      else {
        write("You dive into the "+str+" and almost hurt yourself!\n");
        return 1; }
}

out() {
      call_other(this_player(),"move_player","the room#room/south/sforst1");
      return 1;
}
read(str) {
    if(!str) { 
       write("Read what?\n");
       return 0; }
    if(str == "paper" ) {
       write("\t Gentleman,\n"+
             "\tPlease do feel welcome in my sanctum.\n"+
             "\tIt would be in your best interest to\n"+
             "\tlook around and be sure to look at\n"+
             "\teverything closely and carefully.  I\n"+
             "\thave placed many secret passageways\n"+
             "\tthrough the items inside my sanctum.\n"+
             "\tI love to add new things, so changes\n"+
             "\twill happen on occasion, so be sure \n"+
             "\tto check for new passageways often.\n"+
             "\tHave fun and be sure to pick up after\n"+
             "\tyou are done in here.\n\n"+   
             HIW+"\t\tThe "+GRY+"Dark "+HIW+"Gentleman\n"+NORM);
       return 1;}
    else {
       notify_fail("You sure that is what you want to read?\n");
       return 0; }
}
