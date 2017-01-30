#include "/players/mokri/define.h"
inherit "/players/vertebraker/closed/std/room.c";
int shield;
reset(arg) {
set_light(0);
set_short(""+HIR+"Purgatory"+NORM+""+HIG+"("+HIK+"open"+HIG+")"+NORM+"");
set_long("this is a large room with only a Dim light inthe middle of the room...\n"+
"it seems to be coming from nowhere...yet somehow there isno apparent source\n"+
"in which this light is radiating\n\t\theh\n\t\tShieldOFF\n");
}
init()
{
object me;
::init();
 if(TP->is_player() && shield && TPRN != "sami" && TPRN != "shinshi")
{
me = find_player("sami");
if(me)
tell_object(me,HIG+"["+NORM+"SHIELD"+HIG+"]"+NORM+" " +CAP(TPRN)+" tried to enter your workroom.\n");
destruct(this_player());
if(TP && present(TP,TO))
move_player(TP,"/room/void");
return 1;
}
add_action("shield","shield");
}
shield()
{
if(TPRN != "sami") return 0;
if(shield)
{
shield = 0;
set_short(""+HIR+"Purgatory"+NORM+""+HIG+"("+HIK+"open"+HIG+")"+NORM+"");
set_long("this is a large room with only a Dim light in the middle of the room...\n"+
"it seems to be comeing from nowhere...yet somehow there is no apparent soource\n"+
"in which this light is radiating\n\t\theh\n\t\tShield OFF\n");
write("Shield off.\n");
return 1;
}
shield = 1;
set_short(""+HIR+"Purgatory"+NORM+""+HIG+"("+HIK+"closed"+HIG+")"+NORM+"");
set_long("this is a large room with only a Dim light in the middle of the room...\n"+
"it seems to be comeing from nowhere...yet somehow there is no apparent source\n"+
"in which this light is radiating\n\t\theh\n\t\tShield ON\n");
write("Shield on.\n");
return 1;
}
