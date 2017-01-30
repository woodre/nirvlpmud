inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()
#define STAB BOLD+"Doran's form blurs in a "+RED+"fury"+NORM+BOLD+" of blinding attacks"+NORM
#define THRUST BOLD+"Doran thrusts his spear piercing flesh"+NORM

  int V;
  int spear;
  int armor;

  reset(arg)  {
    ::reset(arg);
  if (arg) return;
  set_name("Doran - "+HIY+"Y"+NORM+BOLD+"elmalian "+YEL+"G"+NORM+BOLD+"eneral"+NORM+". ");
  set_alias("doran");
  set_alt_name("general");
  set_race("human");
  set_al(0);
  set_level(21);
  set_aggressive(0);
  set_hp(600);
  set_ac(19);
#if 0
  set_heal(30,1);
#endif
  MOCO("/players/jareel/weapons/yelmspear.c"),this_object());
  init_command("wield spear");
  set_wc(45);
  set_wc_bonus(64); 
  set_gender("male");
  add_money(2000+random(1000));
  set_dead_ob(this_object());
  set_short("Doran - "+HIY+"Y"+NORM+BOLD+"elmalian "+YEL+"G"+NORM+BOLD+"eneral"+NORM);
  set_long(
    "Doran is an older man.  Having seen many years of\n"+
    "battle, his far-away stare makes you believe he has\n"+
    "been in too many fights.  You get the sense that a dark\n"+
    "hatred fills his soul.  \n");
  add_spell(
    "spear stab",STAB+"\n"+THRUST+"\n"+STAB+"\n",
    "\n",
  35,70,"other|physical");

  add_spell(
    "spear thrust",STAB+"\n"+STAB+"\n"+STAB+"\n"+THRUST+"\n"+STAB+"\n",
    "\n",
  45,140,"other|physical");
  set_chat_chance(2);
    load_chat("Doran says:  The creatures of Darkness will die on the head of my spear.\n");
    load_chat("Doran says:  We will vanquish all in this realm of Darkness!\n");
  }
  heart_beat(){
    object ob;
    object att;
    object next;
    if(!environment()) return;
      if(ob = present("guard", environment())) { if(ob->query_attack()) 
    attack_object(ob->query_attack()); } ;
      ::heart_beat();
    if(attacker_ob) {
      already_fight=0;
      V = random(3);
        if(attacker_ob){
        if(V == 1) V_stab();
      else if(V == 2) V_bladesharp();
    }
  }
  if( hit_point < max_hp )
    {
        autoheal_count++;
        if( autoheal_count >= 1 ) {
          hit_point += 30;
          set_ac_bonus( ac_bonus + 30 );
          if (hit_point > max_hp)
            hit_point = max_hp;
          autoheal_count = 0;
        }
    }
}

  V_stab()  {
    tell_room(environment(TO),
      "Doran stabs you with his spear.\n");
    call_other(attacker_ob,"hit_player",random(25)+10);
  return;
  }
  V_bladesharp() {
    tell_room(environment(TO),
      "Doran unleashes solar energy....\n"+
      STAB+"\n"+STAB+"\n"+THRUST+"\n"+STAB+"\n");
     call_other(attacker_ob,"hit_player",random(86)+65);
  return;
  }
