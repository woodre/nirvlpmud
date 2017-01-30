#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster.c";

reset(arg){
  ::reset(arg);
  if(arg) return;
set_name("pojoui");
set_short(RED+"A pojoui"+NORM);
set_long("This small little lizard-like creature bounces around with great speed.\n"+
         "It's eyes glow yellow in the darkness and it's skin gleams with moisture.\n"+
         "It's teeth are razor sharp but the most feared feature of this creature\n"+
         "is it's blood.  Legend has it, the blood of a pojoui will burn through\n"+
         "any flesh it touches, including the dreaded Sinja worm.\n");
set_dead_ob(this_object());
set_level(20);
set_wc(50);
set_ac(17);
set_al(-1000);
set_hp(500+random(50));
set_chance(33);
set_spell_dam(50);
set_spell_mess1("The pojoui spits venomous blood.");
set_spell_mess2("The pojoui spits venomous blood.\n"+RED+"Your skin begins to boil and burn as the venom rips through you."+NORM);
/* autoattack */
ac_bonus += 3;
}

init(){
::init();
#ifndef __LDMUD__
   add_action("attackme");add_xverb("");

#else
   add_action("attackme","", 3);

#endif
}

attackme(){
if(!attacker_ob && random(10) == 1){
if(this_player()->is_player()){
  tell_object(this_player(),"The pojoui notices you and attacks.\n");
attacker_ob = this_player();
}
}
return 0;
}

monster_died(){
  move_object(clone_object("/players/wocket/caves/OBJ/blood.c"),environment(this_object()));
if(random(3)==1){
  tell_object(attacker_ob,RED+"Venomous blood splatters across your face as you strike the last blow.\n"+NORM);
move_object(clone_object("/players/wocket/caves/OBJ/pblood.c"),attacker_ob);
}
write_file("/players/wocket/closed/log/CAVES","pojoui - "+attacker_ob->query_real_name()+" "+attacker_ob->query_level()+" - "+ctime()+"\n");
return 0;
}
