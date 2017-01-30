#include "/players/hippo/bs.h"
inherit "obj/monster";
int i;
reset(arg) {
    object heal,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("thrombocyte");  /* Rumplemintz - 10/24/07 */
    /* set_name("thrombo");  */
    set_short("A thrombocyte");
    set_alias("thrombo");
    money = 400;
    set_long("A thrombocyte, or thrombo. The blood cell that can cope"+BS+
      "with (nearly) all intruders"+BS);
    set_level(20);
    set_wc(30);
    set_ac(17);
    set_hp(500);
    heal = clone_object("/players/hippo/heals/nucleus");
    if (heal) {
	move_object(heal,this_object());
    }
    armor = clone_object("/players/hippo/armour/boots");
    if(armor) {
	move_object(armor,this_object());
    }
    weapon = clone_object("/players/hippo/weapons/glue");
    if(weapon) {
	move_object(weapon,this_object());
    }
}
