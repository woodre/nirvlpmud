/*
 * A multi purpose shadow for use with Masking spells.
 * Bard v3.0
 */

inherit "/obj/monster";

string MASTER, SHADOW;

reset(arg)  {
  ::reset(arg);
  
  if(!arg)  {
  
    set_name("shadow");
    set_short("A shadow");
    set_race("illusion");
    set_alias("summoned");
    set_level(5);
    set_ac(0);
    set_wc(0);
    set_hp(1);
    set_al(0);
    set_ep(1);
    set_gender("creature");
    set_dead_ob(this_object());
    
    call_out("master_check",5);

        }
        }


monster_died()  {
object ob;
  
  ob = clone_object("/players/saber/closed/bard/itm/corpse_gone.c");
  move_object(ob, environment(this_object()));
  remove_call_out("master_check");
  
  return 0;
  
        }


master_check()  {
object TARG, MAST;

  if(!present(this_object()->query_master(), environment(this_object())))  {
  
    say(short()+" shimmers and fades away.\n");
    destruct(this_object());
    return 1;
    
    }

  if(this_object()->query_shadow() == "yes")  {
    MAST = present(this_object()->query_master(), environment(this_object()));
    if(this_object()->query_attack()->query_real_name() != 
       MAST->query_attack()->query_real_name())  {
       
       TARG = MAST->query_attack();
       
       if(!(TARG->is_player()))  {
       this_object()->attack_object(TARG);
    }
    }
    }


  call_out("master_check", 20);
  return 1;
    }
  

set_master(str)  {  MASTER = str;  }
query_master()   {  return MASTER; }
set_shadow(str)  {  SHADOW = str;  }
query_shadow()   {  return SHADOW; }

is_pet()       { return 1; }
is_illusion()  { return 1; }
