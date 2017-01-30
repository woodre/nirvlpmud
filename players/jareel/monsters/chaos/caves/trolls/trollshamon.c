/* **********************************************************************
*
********************************************************************** */

#include "/players/jareel/ansi.h"
inherit "/obj/monster.c";

  reset(arg){
    ::reset();
  if(arg) return;
    
  set_name("shaman");
  set_race("troll");
  set_short("A Troll Shaman");
  set_long(
    "The troll is stooped over.  Its narrow slits for eyes\n"+
    "peer at you in the darkness.  A magical aura surounds\n"+
    "the creatures body, creating a strange glow about him.\n");
  set_level(20);
  set_hp(500);
  set_wc(25);
  set_ac(20);
  set_heal(10,20);
  set_chance(25);
  set_spell_dam(50);
  set_spell_mess1("");
  set_spell_mess2("The shaman releases spiritual energy into you.\n");
  set_dead_ob(this_object());
  }

monster_died(){
  int i;
  for(i=0;i<2;i++){
  if(random(2)==1){ move_object(clone_object("/players/jareel/heals/redspirit.c"),this_object()); }
  else{ move_object(clone_object("/players/jareel/heals/bluespirit.c"),this_object()); }
  }
}
