#include "/players/mokri/define.h"
inherit "/players/vertebraker/closed/std/room.c";
int shield;
reset(arg) {
set_light(0);
set_short(RED+"Ele"+YEL+"me"+GRN+"nt"+CYN+"al"+NORM+MAG+" Nightmare"+NORM);
set_long("All the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" swirl around the room..... The Room is ever changing and seems\n"+
"to never have the same look. Everything surrounding the place is pure energy.\n\t\tShield OFF\n");
}
init()
{
object me;
::init();
 if(TP->is_player() && shield && TPRN != "wicket" && TPRN != "shinshi")
{
me = find_player("wicket");
if(me)
tell_object(me,HIR+"["+NORM+"SHIELD"+HIG+"]"+NORM+" " +CAP(TPRN)+" tried to enter your workroom.\n");
destruct(this_player());
if(TP && present(TP,TO))
move_player(TP,"/room/void");
return 1;
}
add_action("shield","shield");
}
shield()
{
if(TPRN != "wicket") return 0;
if(shield)
{
shield = 0;
set_short(RED+"Ele"+YEL+"me"+GRN+"nt"+CYN+"al"+NORM+MAG+" Nightmare"+NORM+HIG+"("+HIK+"open"+HIG+")"+NORM);
set_long("All the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" swirl around the room..... The Room is ever changing and seems\n"+
"to never have the same look. Everything surrounding the place is pure energy.\n\t\t\tShield OFF\n");
write("Shield off.\n");
return 1;
}
shield = 1;
set_short(RED+"Ele"+YEL+"me"+GRN+"nt"+CYN+"al"+NORM+MAG+" Nightmare"+NORM+HIG+"("+HIK+"open"+HIG+")"+NORM);
set_long("All the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" swirl around the room..... The Room is ever changing and seems\n"+
"to never have the same look. Everything surrounding the place is pure energy\n\t\tShield ON\n");
write("Shield on.\n");
return 1;
}
