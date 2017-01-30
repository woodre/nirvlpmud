inherit "/players/stark/room";
#include "/players/stark/defs.h"
int found;
int money;

reset(arg){

found=0;
money=2200+random(2000);
if(!present("utena"))  {
MOCO("/players/stark/utena/mon/utena.c"),this_object());  }
if(!present("chuchu"))  {
MOCO("/players/stark/utena/mon/chuchu.c"),this_object());  }

    if(arg) return;
    set_light(1);

    set_listen("A small mouse skittering about?");
    set_smell("A fresh pine scent left from the daily cleaning.");
    /*set_search("It isn't proper to search the room of Lady!\n But you do anyways, and find nothing.");*/

    short_desc="Utena's Dorm Room";
    long_desc=
"   Utena's dorm room is immaculately clean, with a shining wood floor, \n"+
"a simple rug with a small table.  The room is made for two; having a \n"+
"large double closet, a bunk bed, and matching desks.  Everything is \n"+
"cleaned spotless thanks to Anthy, who lives wherever Utena does.\n";

items=({
"closet","This tall and wide closet is made of oak and stained a soft cherry colour",
"floor","A cleaned and polished wood floor",
"rug","A simple rug laid beneath the table",
"table","A low and small table",
"bed","Both of the bunk beds have been made",
"beds","Both of the bunk beds have been made",
"bunks","Both of the bunk beds have been made",
"desks","One desk is clean and tidy, the other has supplies and paper all about it"
});

dest_dir=({"/players/stark/utena/room/street2.c", "out"
});

}

init() {
::init();
add_action("search","search");
}

search(){
	if(found){
		write("It isn't proper to search the room of a Lady!\n But you do anyways, and find nothing.\n");
	return 1;}
	write("It isn't proper to search the room of a Lady!\n But you do anyways, and find "+money+" in coins!\n");
	this_player()->add_money(money);
	found=1;
	money=0;
return 1;}

