#include "/players/linus/def.h"
inherit "/obj/monster.c";
reset(arg) {
 ::reset(arg);
 if(arg) return;
switch(random(10)) {
 case 0..4: frog(); break;
 case 5..9: turtle(); break;
 default: turtle(); break;
}
}
frog() {
 set_name(GRN+"Frog"+NORM);
 set_alias("frog");
 set_short("A small "+GRN+"frog"+NORM);
 set_long(
 "A small "+GRN+"frog"+NORM+" that has hopped onto the bridge from the stream below.\n"+
 "It's tongue suddenly lashes out and grabs a fly.\n");
 set_level(5);
 set_wc(9);
 set_ac(5);
 set_hp(75);
 set_dead_ob(TO);
}
turtle() {
 object arm;
 set_name(GRN+"Turtle"+NORM);
 set_alias("turtle");
 set_short("A small "+GRN+"turtle"+NORM);
 set_long(
 "A small "+GRN+"turtle"+NORM+" that has wandered onto the bridge.  He lives in a small\n"+
 GRN+"shell"+NORM+" and hides in there when threatened.\n");
 arm=CO("/players/linus/Newbie/obj/t_shell.c");
 MO(arm,TO);
 init_command("wear shell", TO);
 set_level(5);
 set_wc(9);
 set_ac(4);
 set_hp(75);
}
monster_died() {
 tell_room(environment(TO),"The frogs legs are severed, causing it to bleed to death.\n");
 MO(CO("/players/linus/Newbie/obj/f_legs.c"),TO);
 return 1;
}
