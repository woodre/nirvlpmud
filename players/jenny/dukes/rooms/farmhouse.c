inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int money;
reset(arg) {
if(!present("jesse duke"))  {
MOCO("/players/jenny/dukes/mobs/jesse.c"),this_object()); }
money = 1;
    if(arg) return;
    set_light(1);
short_desc=(BOLD+""+WHT+"The Duke Farmhouse"+NORM);
long_desc=
"This small farmhouse has been in the Duke family for\n"+
"generations.  Currently, Uncle Jesse lives here with his\n"+
"two nephews, Bo and Luke, and his niece Daisy.  They\n"+
"do not have a lot of nice things, but get by just the same.\n"+
"A small stove sits in the kitchen, not far from the dining\n"+
"room table.  An oak bookcase stands along the far wall.\n";
items = ({
"stove","Daisy uses this stove to cook her delicious vittles.  Friends, I\n"+
"don't know what's better, Daisy's looks, or her cookin",
"table","A plain table with a red and white checkered table cloth.\n"+
"The Duke clan sits around this table for meals",
"bookcase","This is an old bookcase made of oak.  Uncle Jesse hides his best\n"+
"moonshine behind the books",
"wall","A plain white wall, with a clock hanging from it",
"clock","It is "+ctime()+"\n",

});
dest_dir = ({
 "/players/jenny/dukes/rooms/farm1","out",
});
}
init() { 
    ::init();
add_action("coins","search");
}
coins(arg)  {
int cash;
cash = 10+random(30);
if(money == 1) {
write(BOLD+"You find "+cash+" coins."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }
}
