inherit "obj/monster.c";
#include "/players/jareel/define.h"


#define BERSERKER HIR+"R"+NORM+RED+"ogar"+NORM+BOLD+" movements blur in a fury of attacks!!"+NORM
#define FURY HIR+"R"+NORM+RED+"ogar"+NORM+BOLD+"'s Chaos Axe blurs through the air!!"+NORM

int stuff;

reset(arg)  {
  stuff = random(2);
  ::reset(arg);
    if(arg) return;

  set_name("rogar");
  set_alt_name("storm bull");
  set_short(HIR+"R"+NORM+RED+"ogar "+NORM+"- "+HIR+"S"+NORM+RED+"torm "+HIR+"B"+NORM+RED+"ull"+NORM+" ("+BOLD+"Berserker Lord"+NORM+")"+NORM);
  set_alias("chaos");
  set_long(
    "A crazed man stands seven feet tall in front of you.  His impressive structure\n"+
    "is easy to see for all he wear is a loin cloth and a variety of tattoos.  Buggy\n"+
    "eyes bulge as he is a pure berserker believing the best protection is having\n"+
    "a great offence.  Scars riddle his body, like a mosaic of modern art.  Runes\n"+
    "of chaos and truth are inscribed across Rogars gleaming axe.\n");
  set_race("human");
  set_al(0);
  set_level(25);
  set_hp(1000);

  if(stuff == 0) { 
    MOCO("/players/jareel/weapons/chaos/woods2/chaos_axe.c"),this_object());
      init_command("wield axe");
  }  

  if(stuff == 1) { 
    MOCO("/players/jareel/weapons/chaos/woods2/chaos_axe.c"),this_object());
      init_command("wield axe");
  }

  set_wc_bonus(160); /* Double hit in Heart Beat double cast spell */
  set_ac_bonus(45); /* +45 for physical Resistance*/
  set_wc(130); /* Hits like a Freight Train */
  set_ac(1); /* No AC has Res over AC for Physical Damage */
  set_heal(10,1);
  add_money(9000+random(14000));
  set_res(90);
  set_armor_params("other|light",0,10,0); 
  set_armor_params("other|dark",0,100,0);
  set_armor_params("magical",0,100,0);
  set_armor_params("other|evil",0,-40,0); 
  set_armor_params("other|electricity",0,60,0);

  add_spell(
    "beserkerrage",""+BERSERKER+"\n"+BERSERKER+"\n"+BERSERKER+"\n"+BERSERKER+"\n"+BERSERKER+"\n"+BERSERKER+"\n",
                   ""+BERSERKER+"\n"+BERSERKER+"\n",
    10,180,"other|physical");
  
  add_spell(
    "axe",""+FURY+"\n",
          ""+FURY+"\n",
    10,100,"other|physical");
  
 add_spell(
    "spirit","\n"+BOLD+"        An enraged Spirit slashes at you!\n"+NORM+"\n",
             "\n"+BOLD+"        An enraged Spirit slashes at #TN#.\n"+NORM+"\n",
    10,200,"other|spirit");
  
  add_spell(
    "fury",""+BERSERKER+"\n"+FURY+"\n"+BERSERKER+"\n",
           ""+BERSERKER+"\n"+FURY+"\n"+BERSERKER+"\n",
    10,90,"other|physical");

  set_dead_ob(this_object());
}


pro_physical(){   /* 90 resistance */
    write(HIR+"R"+NORM+RED+"ogar "+NORM+"deftly sidesteps your attack.\n"+NORM);
  return 1;
}

heart_beat(){
  ::heart_beat();
    if(attacker_ob) {
      already_fight=0;
      attack();

}}
