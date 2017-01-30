/*HUMBLE CORPS 2004*/
#include "../defs.h"
inherit "/obj/monster";
reset(arg) {
    ::reset(arg);
    if (!arg)  {
    money=2000+random(1000);
    move_object(clone_object("/players/humble/area1/objs/fish.c"));
    move_object(clone_object("/players/humble/area1/objs/fishmanshoes.c"));
    init_command("wield fish");
    init_command("wear boots");
    set_name("Eric");
    set_alt_name("eric");
    set_alias("eric");
    set_short(HIC+"Eric"+NORM);
    set_race("human");
    set_long(
    "This is Eric, the guy who runs the "+HIC+"Seafood Department"+NORM+".\n"+
    "This motherfucker just looks like a fish.  He is incredibly pale\n"+
    "with pinks rings around his eyes.  He has a receeding hairline\n"+
    "and appears to be in his mid 30s.  He looks like he's high on heroin.\n"+
    "Not much else you could expect from a Union grocery store worker.\n");
    set_gender("male");
    set_level(18);
    set_ac(20+random(3));
    set_wc(24+random(2));
    set_hp(850+random(150));
    set_chat_chance(5);
     load_chat(HIW+"Eric shifts his weight a bit.\n"+NORM);
    set_chance(20);
    set_spell_type("other|electric");
    set_spell_dam(30+random(30));
    set_spell_mess1(
    HIC+"Eric pulls an electric eel out of his pants and throws it at his opponent.\n"+NORM);
    set_spell_mess2(
    HIC+"Eric throws an electric eel at you with deadly precision!\n"+NORM+
    HIY+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM+
    HIY+"  ~~~~~~~~~~~~~~~~~"+HIR+"<S H O C K>"+HIY+"~~~~~~~~~~~~~~~~~~~~~  \n"+NORM+
    HIY+"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"+NORM);
  }
}
