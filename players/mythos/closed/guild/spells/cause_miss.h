#include "/players/mythos/closed/guild/def.h"

cause_miss()
{
  object ob;
  if(qtf < 5)
  {
    write("Your control over fae is not enough!\n");
    return 1;
  }
  if(scrp < 10000)
  {
    write("The darkness calls for a sacrifice.\n");
    return 1;
  }
  if(tsp < 175)
  {
    write("You do not have enough energy!\n");
    return 1;
  }
  if(!(tp->query_attack()))
  {
    write("You may only use this during combat.\n");
    return 1;
  }
  if(!((tp->query_attack())->query_npc()) &&  !dpp)
  {
    write("You may not use this on players at this time.\n");
    return 1;
  }
  if(present("adder",(tp->query_attack())))
  {
    write("That target is already frozen!\n");
    return 1;
  }
  if(present("ooga",(ob=tp->query_attack()))) {
    write("You must wait while the fae gather.\n");
    return 1; 
  }
  else
  {
    int org_wc;
    object spell;
    
    org_wc = ob->query_wc();
    spell = clone_object("/players/mythos/closed/guild/spells/adder");
    move_object(spell, ob);
    
    write("Whispering a few key words, you cause your enemy's limbs to freeze!\n");
    say(capitalize(tpn)+" whispers a few words.....\n");
    
    spell->start_it(org_wc - (random(25 - qtf)), 20+qtf);
    tp->add_sp(-175);
    pp->add_sacrifice(-10000);
    return 1;
  }
}
