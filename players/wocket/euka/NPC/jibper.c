#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

reset(arg){
object gold;
    ::reset(arg);
  if(arg) return;
    set_name("jibper");
    set_alias("bird");
    set_short(HIR+"A "+OFF+get_adj()+HIR+" jibper bird"+OFF);
    set_long();
    set_race("seussian");
    set_al(random(1000));
    set_level(21);
    set_hp(800);
    set_wc(40);
    set_ac(20);

    set_chance(8);
    set_spell_dam(30);
    set_spell_mess1(HIB+"\nThe jibper bird sceetches.\n\tTHE SOUND SHATTERS YOUR EARS DRUMS ! ! !\n"+OFF+"...you scream in pain as blood trickles from your ear.\n"+NORM); 
    set_spell_mess2(HIB+"\nThe jibper bird sceetches.\n\tTHE SOUND SHATTERS YOUR EARS DRUMS ! ! !\n"+OFF+"...you scream in pain as blood trickles from your ear.\n"+NORM);
}

get_adj(){
switch(random(5)){
case 0: return "famous";
case 1: return "hidden";
case 2: return "beautiful";
case 3: return "colorful";
case 4: return "silent";
}
}