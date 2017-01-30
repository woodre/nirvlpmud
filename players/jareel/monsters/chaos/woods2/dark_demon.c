inherit "obj/monster.c";
#include "/players/jareel/define.h"

int stuff;

reset(arg)  {
  stuff = random(2);
    ::reset(arg);
      if(arg) return;

  set_name("Dark Demon");
  set_alt_name("dark");
  set_short(HIK+"Dark Demon"+NORM);
  set_alias("chaos");
  set_long(
    "The demon is an enormous writhing mass, formed out of ropy\n"+
    "black tentacles.  Here and there, the demon's surface is \n"+
    "covered with great hungry mouths dripping a vile green acidic\n"+
    "substance.  The demon sprawls over the floor on it's slime  \n"+
    "covered tentacles.  Your soul screams in terror as you look\n"+
    "at it.\n");
  set_spell_mess1("The demon whips its tentacles.\n");
  set_spell_mess2("The demon whips its tentacles at you.\n");
  set_chance(5);
    set_armor_params("other|light",0,-10,"prot_from_light");
	set_armor_params("other|light",0,-10,"prot_from_light");
  set_spell_dam(70);
  set_race("demon");
  set_al(-1000);
  set_level(22);
  set_hp(600);

  if(stuff == 0) { 
    MOCO("/players/jareel/heals/stone.c"),this_object());
  }  

  if(stuff == 1) { 
    MOCO("/players/jareel/general_stuff/demonhide.c"),this_object());
  }   
    
  set_wc(80);
  set_ac(10);
  set_heal(5,1);
  set_aggressive(1);
  add_money(2000+random(4000));
  set_armor_params("other|light",0,-10,0); /* +10 damage from light */
  set_armor_params("other|dark",0,10,0); /* -10 damage from dark */
  set_dead_ob(this_object());
}

init() {
  ::init();
    add_action("nogo","west");
    add_action("nogo","east");
    add_action("nogo","south");
    add_action("nogo","north");

}

heart_beat(){
  object ob;
  object att;
  object next;
    if(!environment()) return;
    if(ob = present("chaos", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
  ::heart_beat();
}

nogo() {
    write("Demon blocks your path.\n");
  return 1;
}

prot_from_light(){  /* -10 resistance */
    write(BYEL+"Intense light sears the demons flesh.\n"+NORM);
  return 1;
}

prot_from_dark(){   /* 10 resistance */
    write(HIK+"Darkness is absorbed by the demon.\n"+NORM);
  return 1;
}
