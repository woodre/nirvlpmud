#include "/players/wocket/closed/ansi.h"
inherit "obj/monster";

reset(arg){
int i;
    ::reset(arg);
    if(arg) return;
    set_short(HIG+"A "+NORM+"dryant "+HIG+"zombie"+NORM);
    set_name("dryant");
    set_race("seussian");
    set_alias("zombie");
    set_level(20);
    set_hp(500+random(50));
    set_ac(30+random(3));
    set_wc(17+random(3));
    set_al(0-random(1000));
i = random(4);
switch(i){
case 0: zfrost(); break;
case 1: zfire(); break;
case 2: zstone(); break;
case 3: zwind(); break;
}
move_object(clone_object("/players/wocket/graveyard/diamond.c"),this_object());
}

zfrost(){
    set_long("Dead skin falls away from this living corpse.  His eyes\n"+
    "are sunken in and his muscles are shiver. Frost forms from his\n"+
    "breath and cold air fills his surroundings.\n");
    set_chance(33);
    set_spell_dam(25);
    set_spell_mess1(HIB+"\nICE SHARDS fly from the hands of this dryant\nas he crushes his opponent with a MIGHTY BLOW\n"+NORM);
    set_spell_mess2(HIB+"\nICE SHARDS fly from the hands of this dryant\nas he crushes his opponent with a MIGHTY BLOW.\n"+NORM+RED+"...blood flows freely from your open wounds...\n"+NORM);
}

zfire(){
    set_long("His clothes are caked with blood and dirt upon his rotting\n"+
    "burned skin.  Gentle flames still encompass his body as he moves\n"+
    "with great effort.  Mindless is he as his actions seem random.\n");
    set_chance(10);
    set_spell_dam(50);
    set_spell_mess1(HIR+"\nFlames burn through his attackers flesh as his touch egnites skin.\n"+NORM);
    set_spell_mess2(HIR+"\nFlames burn through his attackers flesh as his touch egnites skin.\n"+NORM+RED+"...pain fills your body as skin burns away and blood takes its place...\n"+NORM);
}

zstone(){
    set_long("Cracks line the face of this dead dryant.  A trail of stone chips\n"+
    "follow him as he moves.  Huge footprints are left behind as he wanders\n"+
    "around in circles.\n");
    set_chance(5);
    set_spell_dam(150);
    set_spell_mess1(CYN+"The stone zombie manages to connect with his opponent.\n"+NORM);
    set_spell_mess2(CYN+"The stone zombie manages to connect with his opponent.\n"+NORM+"You are crushed as you fly back several feet from the blow.\n"+RED+"...all you see is red..."+BRED+"\n\n\n\n\n\n"+NORM);
}

zwind(){
    set_long("The rotting corpse appears to be walking on air as it moves\n"+
    "across the ground.  His torn clothes barely keep together his \n"+
    "shriveled torso as chunks of flesh litter the area.\n");
    set_chance(88);
    set_spell_dam(10);
    set_spell_mess1(BOLD+"A BLAST OF WIND bows by as the dryant's predator is knocked back.\n"+NORM);
    set_spell_mess2(BOLD+"A BLAST OF WIND blows by as the dryant's predator is knocked back.\n"+NORM+RED+"...internal bleeding floods your body as you're crushed from the wind...\n"+NORM);
}

/*
heart_beat(){
    ::heart_beat();
if(attacker_ob && present(attacker_ob, environment(this_object())) && random(3) == 2){
    tell_object(attacker_ob,"Giant hits you hard.\n");
    call_other(attacker_ob,"hit_player",20);
}
}
*/
