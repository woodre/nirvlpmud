inherit "/obj/monster";
#include "/players/jareel/define.h"
#define TO this_object()
#define STAB BOLD+"Invictis's form blurs in a "+RED+"fury"+NORM+BOLD+" of blinding attacks"+NORM
#define THRUST BOLD+"Invictis thrusts his spear piercing flesh"+NORM
int K;

reset(arg) {
  ::reset(arg);
    if (arg) return;

  MOCO("/players/jareel/weapons/YELMALIAN/trainerspear.c"),this_object());
    init_command("wield spear");

  MOCO("/players/jareel/armor/yelmalian/trainershield.c"),this_object());
    init_command("wear shield");

  set_alias("captain");
  set_alt_name("invictis");
  set_name("Invictis - "+HIY+"L"+NORM+BOLD+"ight "+HIY+"C"+NORM+BOLD+"aptain "+NORM+RED+"["+NORM+BOLD+"Yelmalian Trainer"+NORM+RED+"]"+NORM);
  set_race("human");
  set_al(100);
  set_level(22);
  set_aggressive(0);
  set_hp(1000);
  add_money(random(15000));
  set_ac(25);
  set_heal(5,1);
  set_wc(55);
  set_dead_ob(this_object());
  set_short("Invictis - "+HIY+"L"+NORM+BOLD+"ight "+HIY+"C"+NORM+BOLD+"aptain "+NORM+RED+"["+NORM+BOLD+"Yelmalian Trainer"+NORM+RED+"]"+NORM);
  set_long(
    "Holding a spear in one hand and a shield in the other Invictis\n"+
    "appears to be able to hold his own in a fight.  Long blond hair\n"+
    "flows over his face as he surveys the room.  Few are better with\n"+
    "a shield and spear and few can match his knowledge.\n"+NORM);

  add_spell(
    "spear stab",STAB+"\n"+THRUST+"\n"+STAB,
                 "\n",
    25,70,"other|physical");

  add_spell(
    "spear thrust",STAB+"\n"+STAB+"\n"+STAB+"\n"+THRUST+"\n"+STAB,
                   "\n",
    25,140,"other|physical");

  add_spell(
    "trip","Invictis trips you with the shaft of his spear.\n",
           "\n",
    25,90,"other|physical");


  set_chat_chance(10);
    load_chat("\n");
    load_chat("\n");
}

heart_beat(){
  object ob;
  object att;
  object next;
    if(!environment()) return;
    if(ob = present("chaos", environment())) { if(ob->query_attack()) attack_object(ob->query_attack()); } ;
  ::heart_beat();
}

monster_died() {
}
