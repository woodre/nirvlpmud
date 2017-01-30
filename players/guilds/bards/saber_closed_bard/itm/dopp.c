/*
 * Part of the confusion spell.
 * Bard v3.0
 */

inherit "/obj/monster";

#define TO this_object()
#define ENV environment(this_object())

string MASTER, DUMMY;
int DECAY, HOW_LONG, WC, AC, TOTAL_SPENT, DAMAGE, HIT_ME;
object TEMP;

reset(arg)  {
  ::reset(arg);
  if(!arg)  {
    set_name("wildy and hits itself");
    set_short();
    set_alias("summoned");
    set_long();
    set_level(1);
    set_ac(50);
    set_wc(0);
    set_hp(600);
    set_al(0);
    set_ep(1);
    set_heart_beat(1);
    call_out("check_here",10);
        }
        }


is_pet()         {  return 1; }


set_master(str)  {  MASTER = str; }
set_dummy(str)   {  DUMMY  = str; }

set_how_long(str){  HOW_LONG = str; } 
set_org_ac(str)  {  AC = str;       }  
set_org_wc(str)  {  WC = str;       }  



heartbeat()  {

  DECAY++;
  
  SPENT = 0; DAMAGE = 0;
  
  DAMAGE = random(WC) - random(AC);

  if(!(HIT_ME = present(DUMMY, ENV)))  { check_here(); }
  TO->heal_self(600);
  
  if(DAMAGE > 0)  {
  
    HIT_ME->heal_self(-DAMAGE);
    tell_room(ENV, "\n"+DAMAGE+" done.\n\n");
  
    TOTAL_SPENT = TOTAL_SPENT + DAMAGE;
    
    if(TOTAL_SPENT > 35)  {  
    
      TEMP = present(MASTER, ENV);
      if(!TEMP) { check_here(); return 1; }
      TEMP->add_spell_point(-DAMAGE);
      tell_object(TEMP, "The confusion spell saps your mana.\n");
    }
    
    }
  
  if(living(HIT_ME))  { HIT_ME->attack_object(TO);  }

  
  if(DECAY > HOW_LONG)  {
  TEMP = present("confuse_mark", DUMMY);
  TEMP->end_game();
  remove_call_out("check_here");
  set_heart_beat(0);
  destruct(TO);
  return 1; 
     } 

     }


check_here()  {
  if(!present(MASTER, ENV))  {
  remove_call_out("check_here");
  set_heart_beat(0);
  destruct(TO);
  return 1;
     }

  if(!present(DUMMY, ENV))  {
  remove_call_out("check_here");
  set_heart_beat(0);
  destruct(TO);
  return 1;
     }

  call_out("check_here", 10);
  return 1;
     }
