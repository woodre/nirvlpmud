#include "/players/wocket/closed/ansi.h"
inherit "obj/monster";

reset(arg){
int i;
    ::reset(arg);
    if(arg) return;
    set_name("dryant");
    set_race("seussian");
    set_alias("ghost");
    set_short(HIB+"A "+NORM+"dryant "+HIB+"ghost"+NORM);
    set_level(20);
    set_hp(500);
    set_wc(35);
    set_ac(16);
    set_chance(20);
    set_spell_dam(1);
    set_spell_mess1("The ghost summons "+HIB+"MYSTIC RAGE"+NORM+".\n");
    set_spell_mess2("The ghost summons "+HIB+"MYSTIC RAGE"+NORM+" to tear through your body.\n");
set_aggressive(0);
set_al(0-random(1000));
i = random(4);
switch(i){
case 0: gfrost(); break;
case 1: gfire(); break;
case 2: gstone(); break;
case 3: gwind(); break;
}
/*spell damage bonus */
wc_bonus += 9; /* 1/3 chance of ave 35 sp damage.. using 4/5 of hp value */
/*agro bonus */
wc_bonus += 3;
move_object(clone_object("/players/wocket/graveyard/ghostsoul.c"),this_object());
}

init(){
    ::init();
if(!this_player()->is_npc()){
  if(!present("necro_ob",this_player())){
    attack_object(this_player());
  }
}
}

gfrost(){
   set_long("It is almost invisible.  Ice forms in the air as\n"+
    "this mass of cold flows through it.\n");
}

gfire(){
    set_long("A blaze of fire floats above the ground and seems to ignite anything\n"+
    "that it passes.\n");
}

gstone(){
    set_long("Looking more like a dust cloud then anything else, his eyes\n"+
    "are the only thing that has any substance.\n");
}

gwind(){
    set_long("You don't see anything, but merely sense it's presence.\n");
}

heart_beat(){
int dam;
    ::heart_beat();
if(attacker_ob && present(attacker_ob, environment(this_object())) && random(3) == 2){
    say("The ghost "+HIB+"INVADES"+NORM+" his attacker's soul, "+HIB+"RIPPING"+NORM+" valuable energy from it.\n");
if(attacker_ob->query_sp() < 40){
dam = attacker_ob->query_sp();
  call_other(attacker_ob,"add_spell_point",-dam);
}
else
    call_other(attacker_ob,"add_spell_point",-30-random(10));
}
}
