#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
    ::reset(arg);
    if(arg) return;
move_object(clone_object("/players/wocket/graveyard/ruby.c"),this_object());
    set_name("dryant");
    set_short(YEL+"A "+NORM+"dryant "+YEL+"mummy"+NORM);
    set_race("seussian");
    set_alias("mummy");
set_long("This mummy of a dryant looks like it has been down here\n"+
    "for 500 or more years.  Her bandages are torn and soiled, and her\n"+
    "stance is crouched.  A faint yellow glow surrounds her body.\n"+
    "Perhaps that is what allows her to sustain life.\n");
set_level(20);
set_hp(650);
set_wc(30);
set_ac(15);
set_aggressive(1);
set_chance(10);
set_spell_dam(20);
set_spell_mess1(HIY+"The aura of the mummy reaches out and drains her opponent of life."+NORM);
set_spell_mess2(HIY+"The aura of the mummy reaches out and drains your life."+NORM);
}
