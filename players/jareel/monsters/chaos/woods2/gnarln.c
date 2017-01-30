inherit "obj/monster.c";
#include "/players/jareel/define.h"
#define BERSERKER HIR+"G"+NORM+RED+"narlin"+NORM+BOLD+" movements blur in a fury of attacks!!"+NORM
#define FURY HIR+"G"+NORM+RED+"narlin"+NORM+BOLD+"'s Chaos Axe blurs through the air!!"+NORM

int stuff;

reset(arg)  {
  stuff = random(2);
  ::reset(arg);
    if(arg) return;

  set_name("gnarlin");
  set_alt_name("storm bull");
  set_short(HIR+"G"+NORM+RED+"narlin "+NORM+"- "+HIR+"S"+NORM+RED+"torm "+HIR+"B"+NORM+RED+"ull"+NORM+" ("+BOLD+"Berserker"+NORM+")"+NORM);
  set_alias("chaos");
  set_long(
    "A crazed man stands seven feet tall in front of you.  His impressive structure\n"+
    "is ez to see for all he wear is a loin cloth and a variety of tattoos.  Buggy\n"+
    "eyes bulge as he is a pure berserker believing the best protection is having\n"+
    "a great offense.  Scars riddle his body, like a mosaic of modern art.  Runes\n"+
    "of chaos and truth are inscribed accross Gnalins gleaming axe.\n");
  set_race("human");
  set_al(200);
  set_level(22);
  set_hp(600);

  if(stuff == 0) { 
    MOCO("/players/jareel/weapons/chaos/woods2/chaos_axe.c"),this_object());
      init_command("wield axe");
  }  

  if(stuff == 1) { 
    MOCO("/players/jareel/weapons/chaos/woods2/chaos_axe.c"),this_object());
      init_command("wield axe");
  }
  
  /********************************************************
   * wc bonus is for extra attack() in HB. Doubles wc as 
   * well as causing extra spells to fire.
   * --Gnar 06/25/2014
   ********************************************************/
  set_wc_bonus(130);
  set_ac_bonus(45); /* Talked to Ill about Phys res he said about 1pt per res so this is 90 adjust as needed  I droped this in half cause I didn't want his xp so high*/
  set_wc(100);
  set_ac(11);
  set_heal(10,1);
  add_money(5000+random(4000));
  set_res(90);
  set_armor_params("other|light",0,10,0); 
  set_armor_params("other|dark",0,100,0);
  set_armor_params("other|physical",0,90,0); 
  set_armor_params("other|evil",0,40,0); 
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
    write(HIR+"G"+NORM+RED+"narlin "+NORM+"deftly sidesteps your attack.\n"+NORM);
  return 1;
}

heart_beat(){
  ::heart_beat();
    if(attacker_ob) {
      already_fight=0;
      attack();

}}
