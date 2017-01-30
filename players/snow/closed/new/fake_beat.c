#include "../DEFS.h"


status fake_beat(object ob) {
  int atthp, mymaxhp, mymaxsp, myhp, mysp;
  int newac, bdam;
  object att, wep;

  if(!ob || !environment(ob)) return 1;

  if(IPOB) IPOB->add_beats();

  /* ENHANCEMENT MANAGEMENT */
  mymaxhp = (int)ob->query_mhp();
  mymaxsp = (int)ob->query_msp();
  myhp    = (int)ob->query_hp();
  mysp    = (int)ob->query_sp();
  if(ob->query_attack()) att = (object)ob->query_attack();
  if(att) atthp = (int)att->query_hp();
  if(IPOB->query_regen()) 
    call_other(LIB_TOOLS+"reg.c", "regenerate", ob);
  if(IPOB->query_rejuv()) 
    call_other(LIB_TOOLS+"rej.c", "rejuvenate", ob);
  if(IPOB->query_equil()) 
    call_other(LIB_TOOLS+"equil.c", "equilibrate", ob);
  if(IPOB->query_charge_on()) 
    call_other(LIB_TOOLS+"flux_charge.c", "flux_charge", ob);
  if( (IPOB->query_bion_on() ||
       IPOB->query_blad_on() ) && !att) {
    if(IPOB->query_blad_on()) {
      tell_object(ob,"Your blades retract.\n");
      IPOB->set_blad_on(0); 
    }
    if(IPOB->query_bion_on()) {
      tell_object(ob,"Your bionics de-activate.\n");
      IPOB->set_bion_on(0); 
    }
  }

  /* ARMOR CLASS AND DAMAGE MANAGEMENT */
  if(!att && !IPOB->query_nohonor() && random(15) == 1)
     call_other(HLEVELD, "honor_checkup", ob);
  if(att) {
    if(IPOB->query_blad_on()) { 
      if(random(100) < (int)IPOB->guild_lev() + 5) { 
        /* eliminated extra hit_player damage by blades */
        if(random(1000) < 20 - (int)IPOB->guild_lev()) {
          tell_object(ob, BOLD+" YOUR BLADES BREAK!"+OFF+"\n");
          IPOB->item_blades(0); 
          IPOB->save_me(); 
          IPOB->reset();
        }
      }
      if(random(100) < (int)IPOB->guild_lev() -1) {
        if((object)att->query_attack() == ob) {
          tell_object(ob, RED+"\t"+att->query_name()+                            
            " is impaled on your blades!"+OFF+"\n");
          tell_object(att, " You impale yourself on "+OPN+"'s blades!\n");
          bdam = (int)IPOB->guild_lev();
          if(bdam > atthp) bdam = atthp - 1;
          att->heal_self(-bdam); 
        }
      }
    }
if(((string)ob->query_real_name()) != "snowtest") {
if(!IPOB->query_nohonor()) call_other(HLEVELD, "honor_checkup", ob);
    newac = random(((int)IPOB->query_art_level())/2) + 1;
    if(IPOB->query_armor()) newac++;
    if(call_other(ob, "query_attrib", "pie") >= random(400)) newac += random(4);
    if(call_other(ob, "query_attrib", "ste") >= random(200)) newac += (random(2) + 1);
    if((int)IPOB->query_attack_mode() == 2) {
    newac = newac + 4;
    if(att && (object)att->query_attack() == ob) {
     if((int)att->query_wc() > 10) ob->add_hit_point((((int)att->query_wc())/10)+1); }}
    if((int)IPOB->query_attack_mode() == 1) if(newac > 0) newac = 1;
    if(newac > 9) newac = 9;
    if(newac < 0) newac = 0;
    if(ob->query_level() >= 60) tell_object(ob, "NEWAC = "+newac+"\n");
    ob->set_ac(newac);
    if((object)att->query_attack() == ob) {
      if(newac > 3 && newac <= 6)
        tell_object(ob, "You partially block "+att->query_name()+"'s attack!\n");
      if(newac >= 7)
        tell_object(ob, "You block most of "+att->query_name()+"'s attack!\n");
    }
} /* END SNOWTEST */
  }

  /* AUTOMATICS MANAGEMENT */
  if(IPOB->query_auto_on() && att) {
    if(atthp > 50) {
      if(IPOB->query_auto_bion() && !IPOB->query_bion_on()) {
        write(BOLD+"AUTO BIONICS"+OFF+"\n");
        command("bion", ob);
      }
      if(IPOB->query_auto_blad() && !IPOB->query_blad_on()) {
        write(BOLD+"AUTO BLADES"+OFF+"\n");
        command("blad", ob);
      }
    }
    if(IPOB->query_auto_reg()) {
      if(myhp < mymaxhp/2 && !IPOB->query_regen() && !IPOB->query_rejuv()) {
        tell_object(ob,BOLD+"[*] AUTO REGENERATION [*]"+OFF+"\n");
        command("reg",ob); 
      }
    }
    if(IPOB->query_auto_rej()) {
      if(myhp > mymaxhp*2/3 && mysp < mymaxsp/2 &&
         !IPOB->query_regen() && !IPOB->query_rejuv()) {
        tell_object(ob,BOLD+"[*] AUTO REJUVENATION [*]"+OFF+"\n");
        command("rej",ob); 
      }
    }
  }
  return 1;
}

def(object ob) {
  object att;
  int myhp, attwc;
  att = ob->query_attack();
  if(!att) return;
  if(!att->query_attack() || att->query_attack() != ob) return;
  attwc = att->query_wc();
  myhp = ob->query_hp();
  if(myhp < ob->query_mhp()*3/4) ob->add_hit_point(attwc/10);
  return 1; }
