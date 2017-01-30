inherit "obj/monster.c";
#include "/players/jareel/define.h"
reset(arg)  {
object gold,shield,spear;
  ::reset(arg);
  if(arg) return;

set_name("Yelmalian Guard");
set_alias("yelmalian");
set_alt_name("guard");
set_short("A "+BOLD+YEL+"Yelmalian "+NORM+"Guard");
set_long(
        "The figure standing before you bears the mark of\n"+
        "the Yelmalian infantry.  The infantry are the shock\n"+
        "troops for the vast yelmalian army.\n" );
 if(!random(2)) set_gender("male"); else set_gender("female");
set_race("human");
set_al((500-random(1000)));
set_level(17);
set_hp(350);
MOCO("/players/jareel/weapons/yelmalian_spear.c"),this_object());
init_command("wield spear");
MOCO("/players/jareel/armor/yelmalian_shield.c"),this_object());
init_command("wear shield");
set_wc(24);
set_ac(14);
        call_out("random_move",10);
set_aggressive(0);
add_money(500+random(50));
set_dead_ob(this_object());
}
random_move() {
    int n;
  if(!environment()) return 1;
if(!query_attack()) {
    n = random(8);
    if (n == 0)
        command("west");
    else if (n == 1)
        command("east");
    else if (n == 2)
      command("east");
    else if (n == 3)
        command("north");
    else if (n == 4)
        command("northwest");
    else if (n == 5)
        command("southwest");
    else if (n == 6)
        command("northeast");
    else if (n == 7)
        command("southeast");
}
call_out("random_move",10);
return 1;
}
