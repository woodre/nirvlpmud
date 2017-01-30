/* A zombie for DarK ArenA */
/* added numerous checks by verte so it clones 3-11-01 */

inherit "/obj/monster.c";
#include "/players/snow/dark/defs.h"
#include "/players/snow/closed/cyber/color.h"

string victim;

void
reset(status arg)
{
   if(arg) return;
   ::reset();
 
    set_name("zombie");
    set_short(BOLD+"Zombie"+OFF);
    set_race("undead");
    set_alias("zomb");
    set_long(
"A shambling mound of rotting flesh in vaguely human form.\n");
    set_level(10);
    set_hp(random(100)+100);
    set_ac(random(4)+4);
    set_wc(random(8)+12);
    set_al(-1000);
    set_dead_ob(this_object());
    set_aggressive(1);
    set_chat_chance(20);
    load_chat(
" The zombie creates a ferocious stink!\n");
    load_chat(
" The zombie groans sickeningly.\n");
    call_out("monster_move",(1 + random(50)));
}
 
monster_died() 
{
  object party;
  if(!attacker_ob) return;
  party = present("party object", attacker_ob);
  if(party) party->share_exp(750);
  if(!party) attacker_ob->add_exp(750);
  if(environment())
    TR(ENV(), "The zombie collapses into rotting flesh.\n");
  "/players/snow/dark/counter.c"->add_count(-1);
  return 0;
}
 
heart_beat() 
{
    object meat;
    ::heart_beat();
    if(!environment()) return;
    if(attacker_ob) 
    {
      if(victim != attacker_ob->query_real_name())
        victim = attacker_ob->query_real_name();
      if(ENV(attacker_ob) && (ENV(attacker_ob) != environment()) 
         && ENV(attacker_ob)->query_darena() == "boo") 
        MO(TO,ENV(attacker_ob));
      pound();
      RE;
    }
    
    if(victim) 
    {
      meat = PRE(victim,ENV(TO));
      if(meat) 
      {
        attack_object(meat);
        pound();
        RE;
      }
      meat = find_player(victim);
      if(meat) 
      {
        if(ENV(meat)->query_darena() == "boo") 
        {
          MO(TO,ENV(meat));
          attack_object(meat);
          pound();
          RE;
        }
      }
    }

    findmeat();
}
 
findmeat() 
{
  object ob;
  ob = first_inventory(ENV(TO));
  while(ob) 
  {
    if(ob->is_player()) 
    {
      if(random(10) < 4) 
      {
        TO->attack_object(ob);
        pound();
        RE;
      }
    }
    ob = next_inventory(ob);
  }
}
 
 
monster_move() {
  int ran;
  string dest;
  call_out("monster_move",(1 + random(50)));
  if(attacker_ob) RE;
  ran = random(9);
  if(ran == 0) dest = C1;
  if(ran == 1) dest = C2;
  if(ran == 2) dest = C3;
  if(ran == 3) dest = C4;
  if(ran == 4) dest = C5;
  if(ran == 5) dest = C6;
  if(ran == 6) dest = C7;
  if(ran == 7) dest = C8;
  if(ran == 8) dest = C9;
  MO(TO,dest);
}
 
pound() {
  if(random(10) < 4 || ENV(TO) != ENV(attacker_ob) ) RE;
  TE(attacker_ob,
     "  The zombie pounds you with fists of rotting flesh!\n");
  attacker_ob->add_hit_point(-(random(10)+3));
}
