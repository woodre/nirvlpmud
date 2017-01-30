inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int money;
reset(arg) {
if(!present("boss hogg"))  {
MOCO("/players/jenny/dukes/mobs/boss.c"),this_object()); }
money = 1;
    if(arg) return;
    set_light(1);
    set_smell(BOLD+"The room smells like barbequed ribs."+NORM);
short_desc=(BOLD+""+WHT+"County Commissioner's office"+NORM);
long_desc=
"This is the office of the County Commissioner.  Boss Hogg\n"+
"and Rosco use it to plan their schemes.  The wood paneling\n"+
"on the walls make this room look very nice.  A safe sits\n"+
"along the back wall, next to Boss Hogg's desk.  A CB radio\n"+
"sits on top of the desk, next to a plate full of barbequed ribs.\n";
items = ({
"safe","Boss Hogg keeps money and important papers locked up in this safe",
"desk","This solid oak desk belongs to Boss Hogg",
"cb","A CB which lets Boss Hogg communicate with the sheriffs' department",
"radio","A CB which lets Boss Hogg communicate with the sheriffs' department",
"ribs","This huge plate of ribs is one of Boss Hogg's afternoon snacks.\n"+
"Rosco tries to sneak a little piece of food now and then",
"paneling","This dark wood paneling makes the office look cosy",
});
dest_dir = ({
 "/players/jenny/dukes/rooms/boffice1","west",
});
}
init() { 
    ::init();
add_action("coins","search");
}
coins(arg)  {
int cash;
cash = TP->query_attrib("luc") + TP->query_attrib("wil");
if(money == 1) {
write(BOLD+"You find "+cash+" coins."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }
}
