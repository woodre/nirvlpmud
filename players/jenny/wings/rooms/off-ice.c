inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int cash, randomchance, money;
realm() { return "NT"; }
reset(arg) {
money = 1;
randomchance = random(9);
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear some activity down on the ice surface."+NORM);
long_desc=
"This is a small booth used by the off-ice officials.  It has plain white\n"+      
"walls and thin red carpet.  A large window gives a view of the ice\n"+
"surface.  There are five chairs and a long table, with a monitor and\n"+
"telephone sitting on top of it.\n";
items = ({
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"window","This is a large opening that gives a good view of the ice surface",
"chairs","Five lightly padded chairs",
"table","A long wooden table that has a monitor and telephone sitting on\n"+
            "top of it",
"monitor","A large television monitor that the off-ice officials use to look\n"+
                 "at replays.  It is used for disputed goals, as well as to make sure\n"+
                 "the right players are credited with goals and assists",
"telephone","A plain black telephone, which is a direct line to the timekeepers\n"+
             "box",
});
dest_dir = ({
 "/players/jenny/wings/rooms/2h4","south",
});
}
short() {
return BOLD+WHT+"Off-Ice Officials Booth"+NORM; }
init() { 
    ::init(); 
add_action("coins","search");
   this_player()->set_fight_area();
}
coins(arg)  {
int cash;
cash = 10+random(random(LUCSTAT)*5);
if(money == 1 && randomchance == 1) {
write(BOLD+"You find "+cash+" coins on the table."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }}
