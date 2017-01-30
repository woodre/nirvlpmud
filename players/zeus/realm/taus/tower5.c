inherit "room/room";	/*  tower5.c  */
#include "/players/zeus/closed/all.h"
#include "/players/zeus/closed/fl_demon.h"

int teleport, secret, one;

reset(arg){

    one = 0;  /* empty */

    teleport = 0;  if(random(TFL_TLP)) teleport = 1;
    secret = 0;

    if(arg) return;
 short_desc="Auseth's Tower";
 long_desc=
"You have entered a small study.  On the east wall a single desk sits up\n"+
"against the wall.  Just to the left of it is a tiny window which looks\n"+
"out upon the forest.  A single bookcase is sitting against the north wall\n"+
"of the room.  There is a small rug spread out on the floor of the room.\n"+
"The door on the west wall leads back to the main room.\n";
 set_light(1);
 items=({
	"desk",
"The desk is beautifully crafted.  The entire thing is made of beauitful\n"+
"oak wood.  It has two drawers underneath it, each of which is locked",
	"wall",
"The wall is made of the plain grey stone blocks which the tower is built\n"+
"from.  Each one looks incredibly heavy",
	"window",
"The simple window provides the room with light, and offers a fantastic\n"+
"view of the tops of the trees outside the tower",
	"bookcase",
"The fine bookcase is made of a beautiful oak wood.  The entire bookcase\n"+
"is filled with books, texts and scrolls that all look very old",
	"books",
"There are quite a few books on the bookshelf in the room.  Most of them\n"+
"are in rather poor shape, and are not bound very well.  They contain\n"+
"untold amounts of knowledge.  One book looks strangely out of place",
	"book",
"There is one book that looks out of place on the bookshelf.  It is\n"+
"rather new, and around it there are only scrolls.  Looking at the dust\n"+
"it seems as though it has been pulled out many times",
	"texts",
"There are numerous texts lining the bookshelves in the room",
	"scrolls",
"There are numerous scrolls on the bookshelves in the room",
	"rug",
"The rug is oval shaped and is sitting in the middle of the room.  It was\n"+
"clearly woven by an expert.  It is red with black swirls running through it",
	"door",
"The simple door leads back to the main part of the second floor",
 });
 dest_dir=({
	 "/players/zeus/realm/taus/tower4.c", "west",
 });
}

set_one(i) { one = i; }
query_one() { return one; }

void init(){
	::init();
	add_action("w_dir", "west");
	add_action("pull_cmd", "pull");
	add_action("enter_cmd", "enter");
}

exit(){    if(TP) TP->clear_fight_area();     }
realm(){   if(teleport) return "NT";    }
okay_follow(){ return 1; }

status pull_cmd(string str){
  if(str != "book") return 0;
  if(!secret){
    write("You pull on the out of place book...\n"+
      "The bookcase shifts, opening a passage in the wall.\n"+
      "You could 'enter' the passage.\n");
    say(TP->QN+" pulls on the out of place book.\n"+
      "The bookcase shifts, opening a passage in the wall.\n");
    secret = 1;
    return 1;
  }
  else {
    write("You pull on the out of place book, but nothing happens...\n"+
      "The passage is already open, you could 'enter' it.\n");
    say(TP->QN+" pulls on the out of place book.\n");
    return 1;
  }
  return 1;
}

status enter_cmd(string str){
  int y, z;
  object *x;
  z = 0;
  if(!str) return 0;
  if(str == "passage" || str == "secret"){
    if(!secret) return 0;
    if(secret && one){
      x = all_inventory("/players/zeus/realm/taus/tower8.c");
      for(y = 0; y < sizeof(x); y++)
      {
        if(x[y]->is_player())
        {
          write(
        "You try to enter the hidden passage, but realize it is blocked.\n");
          z = 1;
        }
      }
      if(0 == z)
        one = 0;
    }
    if(secret && !one){
      write("You enter the hidden passage in the wall...\n");
      TP->MP("into the passage#/players/zeus/realm/taus/tower8.c");
      one = 1; /* full */
      return 1;
    }
    return 1;
  }
  else return 0;
  return 1;
}
