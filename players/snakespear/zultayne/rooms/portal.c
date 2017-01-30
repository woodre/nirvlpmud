#include "/players/snakespear/closed/ansi.h"
inherit "room/room";
reset(arg){
   if(!arg){
      
set_light(0);
short_desc="A Dead End";
long_desc=
 "  The walls here are nothing but dirt and rock.  It's evident that\n"+
 "someone has taken a long time to dig back to this area of the\n"+
 "stronghold.  There seems to be something very magical about this\n"+
 "place.  Several pieces of furniture made from beautiful stone sit\n"+
 "in the room.  Someone has spent great amounts of time to form this\n"+
 "furniture.  A stone tablet lays on the mold covered chalcedony table.\n"+
 "There are all kinds of sounds here that penetrate your thoughts.\n";

items=({
     "walls", "Roughly cut rock forms the surrounding walls",
     "table", "A small table made from chalcedony, a protective stone",
     "furniture", "A table and two chairs made from chalcedony",
     "mold", "Thin, dark mold covering a little table",
     "tablet", "A dark stone tablet that has something scratched into it",
     "rock", "Dark and jagged granite that forms the walls",
     "chalcedony","A quartz like stone that is said to have protective powers",
     "stone","A quartz like stone that is said to have protective powers",
});
    
}  }

realm() { return "NT"; }

init() {
    ::init();
    write(HIW+"\n\n\nThere is a sudden rumbling sound and your passage is blocked!!\n\n\n"+NORM);
    add_action("search_room","search");
    add_action("listen","listen");
    add_action("smell","smell");
    add_action("church","church");
    add_action("pub","pub");
    add_action("read","read");
    add_action("touch","touch");
    add_action("well","well");
    add_action("taste","taste");
    add_action("grit","grit");
}

search_room(str) {
      if(!str) {
            write("What do you want to search?\n");
            return 1; }
  if(str == "furniture") {
	    write("You search around the furniture and can't find anything.\n");
	    return 1; }
	  else {
	    write("You search the "+str+" but find nothing.\n");
	    return 1; }  
}
smell(str) {
      if(!str) {
            write("What do you want to smell?\n");
            return 1; }
   if(str == "dirt") {
	    write("You smell alcohol, perhaps like a 'pub'.\n");
	    return 1; }
	  else {
	    write("You try to smell "+str+", but can't smell anything unusual.\n");
	    return 1; }  
}
listen(str) {
      if(!str) {
            write("What do you want to listen to?\n");
            return 1; }
   if(str == "sounds") {
	    write("It almost sounds like singing from a 'church'.\n");
	    return 1; }
	  else {
	    write("You strain to hear the "+str+", but never hear a thing.\n");
	    return 1; }  
}
touch(str) {
      if(!str) {
        write("What are you trying to touch?\n");
        return 1; }
      if(str == "furniture") { 
        write("Feels like all your wishes could come true at the 'well'.\n");
        return 1; }
      else {
        write("You touch "+str+", but feeling nothing odd.\n");
        return 1; }
}
taste(str) {
      if(!str) {
        write("What are you trying to taste?\n");
        return 1;  }
      if(str == "mold") { 
        write("You taste true 'grit' and wonder if you can stomach the pain..\n");
        return 1; }
      else {
        write("You taste "+str+" and try to get the nasty taste from your mouth!\n");
        return 1; }
}
church() {
      call_other(this_player(),"move_player","the room#room/church.c");
      return 1;
}
pub() {
      call_other(this_player(),"move_player","into the air#room/pub2.c");
      return 1;
}
well() {
      call_other(this_player(),"move_player","into the darkness#players/arrina/newbie/newbie1a.c");
      return 1;  
}
grit() {
      call_other(this_player(),"move_player","to die#players/snakespear/zultayne/rooms/warn.c");
      return 1;
}
read(str) {
    if(!str) { 
       write("Read what?\n");
       return 1; }
    if(str == "tablet" ) {
       write("\t One who is wise would use thine\n"+
             "\tnatural senses to find what those\n"+
             "\tthat are not graced with the powers\n"+
             "\tto do so.  Do not trust that there\n"+
             "\tis not, because a place of power\n"+
             "\tholds many secrets, but you have to\n"+
             "\thave the will to 'see' what is not,\n"+
             "\t'touch' what is, 'smell' what can't be\n"+
             "\tand 'hear' what is not to be heard.\n"+
             "\tTo find what is good and know the\n"+
             "\t'taste' of rock may lead to dea...\n\n"+   
             HIM+"\t\tLady Turton\n"+NORM);
       return 1;}
    else {
       write("You can't seem to read the "+str+".\n");
       return 1; }
}
