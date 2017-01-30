inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("ms tisdale"))  {
MOCO("/players/jenny/dukes/mobs/tisdale.c"),this_object()); }
    if(arg) return;
    set_light(1);
short_desc=(BOLD+""+BLU+"Hazzard Post Office"+NORM);
long_desc=
"This is the Hazzard County Post Office.  People come here\n"+
"to get their mail, or pick up packages.  There are a lot of\n"+
"undelivered packages behind the counter.  A bunch of wanted\n"+
"posters are pinned to the bulletin board on the wall.\n";
items = ({
"packages","These are plainly wrapped packages lined up along a shelf",
"counter","Ms. Tisdale works behind this counter",
"board","A bulletin board with posters on it",
"posters","Posters of wanted criminals",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/r6","out",
});
}
