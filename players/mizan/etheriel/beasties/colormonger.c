inherit "/players/mizan/core/monster.c";
#include "/players/bastion/closed/color.h"


reset(arg) 
{
    object weapon;
    ::reset(arg);
    if(arg) return;
    set_name("colormonger");
    set_race("colormonger");
    set_alias("monger");
    set_short(RED+"C"+YELLOW+"o"+GREEN+"l"+BLINK+"o"+OFF+BLUE+"r"+RED+"m"+
    BLUE+"o"+BLINK+"n"+OFF+YELLOW+"g"+GREEN+"e"+RED+BLINK+"r"+OFF);
    set_long("Thi"+RED+"s i"+BLINK+"s"+OFF+YELLOW+" a bl"+GREEN+"ob o"+BLUE+
    "f tran"+BLINK+"slu"+OFF+BOLD+"cent c"+RED+"olo"+BLINK+"rma"+YELLOW+"ss, e"+
    OFF+"ver c"+BLUE+"han"+BOLD+"gi"+OFF+GREEN+"ng."+RED+"."+YELLOW+"."+OFF+"\n");
    set_level(18);
    set_hp(450);
    set_al(670);
    set_ac(26);
    set_wc(15);
    set_chance(20);
    set_spell_dam(25);
    set_spell_mess1(YELLOW+"Colormonger "+RED+BLINK+"flobles"+OFF+GREEN+" you"+
    BOLD+" with the color "+BLUE+"of "+RED+BLINK+"death!"+OFF);
    set_spell_mess2(BOLD+"You "+YELLOW+"are showered with a "+BLUE+"+blue"+YELLOW+"-"+
    GREEN+"green"+RED+" acid"+BLINK+"!"+OFF);
    move_object(clone_object("players/mizan/etheriel/items/trick-brick"), this_object());
    weapon=clone_object("players/mizan/etheriel/heals/berynol.c");
    move_object(clone_object("players/mizan/etheriel/items/cardboard-tube.c"), this_object());
    move_object(weapon, this_object());

}

