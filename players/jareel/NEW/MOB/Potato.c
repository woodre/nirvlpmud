inherit "obj/monster.c";
#include "/players/jareel/define.h"

reset(arg)  {
  ::reset(arg);
    if(arg) return;

  set_name("potato");
  set_alt_name("potato");
  set_short("Potato");
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
  set_hp(5000);
  set_wc(164); /* Hits like a Freight Train */
  set_ac(48); /* No AC has Res over AC for Physical Damage */
  set_heal(70,3);

  add_money(9000+random(14000));

  add_spell(
    "beserkerrage","\n",
    10,200,"other|physical");
  
  add_spell(
    "axe","\n",
    10,200,"other|physical");
  
 
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
