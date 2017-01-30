#include "../DEFS.h"


status fake_beat(object ob)
{
  int atthp, mymaxhp, mymaxsp, myhp, mysp;
  int newac, bdam;
  int shadmod;
  object att, wep, nob;

  if (!ob || !environment(ob)) return 1;
  if (!IPOB) return 1;

  IPOB->add_beats();

  nob = present("speedster", ob);
  if (nob) destruct(nob);

  mymaxhp = (int)ob->query_mhp();
  mymaxsp = (int)ob->query_msp();
  myhp    = (int)ob->query_hp();
  mysp    = (int)ob->query_sp();

  if (ob->query_attack()) att = (object)ob->query_attack();
  if (att) atthp = (int)att->query_hp();

  if (IPOB->query_digest()) 
    call_other(LIB_TOOLS+"digest.c", "digestion", ob);
  if (IPOB->query_regen()) 
    call_other(LIB_TOOLS+"reg.c", "regenerate", ob);
  if (IPOB->query_rejuv()) 
    call_other(LIB_TOOLS+"rej.c", "rejuvenate", ob);
  if (IPOB->query_equil()) 
    call_other(LIB_TOOLS+"equil.c", "equilibrate", ob);
  if (IPOB->query_charge_on()) 
    call_other(LIB_TOOLS+"fluxcharge.c", "flux_charge", ob);

  if ((IPOB->query_bion_on() || IPOB->query_blad_on()) && !att)
  {
    if(IPOB->query_blad_on())
    {
      tell_object(ob,"Your blades retract.\n");
      IPOB->set_blad_on(0); 
    }
    if(IPOB->query_bion_on())
    {
      tell_object(ob,"Your bionics de-activate.\n");
      IPOB->set_bion_on(0); 
    }
  }

/****** DELAY MANAGEMENT ******/
  if(IPOB->query_use_delay())
  {
    IPOB->lower_use_delay();
    if(!IPOB->query_use_delay())
    {
      tell_object(ob, BOLD+"Use Process < "+IPOB->query_use_name()+" > Ended.\n"+OFF);
      IPOB->clear_use_name();
    }
  }

/* Manage Shadows Modifier */
  shadmod = (int)IPOB->shadows_modifier();
  if (shadmod) IPOB->add_shadows_modifier(-1);

/* Resetting spell damage if not in combat */
  if (ob->query_spell_dam() && !ob->query_attack())
    ob->set_spell_dam(0);

/* Bringing home the bacon for Renegades */
  if (IPOB->query_nohonor() && !ob->query_pl_k())
  {
    if (!ob->query_ghost())
    {
      if (!random(5))
      {
        tell_object(ob, RED+"You suffer painful convulsions.\n"+
          "Player-killing will be your only salvation.\n"+OFF);
        ob->hit_player(10);
      }
    }
  }

  if (!att && 
      !IPOB->query_nohonor() && 
      random(5) == 1
     )
  {
     call_other(HLEVELD, "honor_checkup", ob);
  }

  if (att)
  {
    if (IPOB->query_shadows())
    {
      tell_object(ob, "You step out of the shadows while in combat.\n");
      IPOB->set_shadows(0);
    }
    if (!IPOB->query_nohonor()) call_other(HLEVELD, "honor_checkup", ob);
  }

  /* AUTOMATICS MANAGEMENT */
  if (IPOB->query_auto_on() && att)
  {
    if (atthp > 50)
    {
      if (IPOB->query_auto_bion() && !IPOB->query_bion_on())
      {
        tell_object(ob, BOLD+"[*] AUTO BIONICS [*]"+OFF+"\n");
        command("bion", ob);
      }
      if (IPOB->query_auto_blad() && !IPOB->query_blad_on())
      {
        tell_object(ob, BOLD+"[*] AUTO BLADES [*]"+OFF+"\n");
        command("blad", ob);
      }
    }

    if (IPOB->query_auto_reg())
    {
      if (myhp < mymaxhp/2 && !IPOB->query_regen() && !IPOB->query_rejuv())
      {
        tell_object(ob, BOLD+"[*] AUTO REGENERATION [*]"+OFF+"\n");
        command("reg", ob); 
      }
    }

    if (IPOB->query_auto_dgst() && !IPOB->query_digest())
    {
      int st, in;
      st = (int)ob->query_stuffed();
      in = (int)ob->query_soaked();
      if (st > 2 || in > 2)
      {
        tell_object(ob, BOLD+"[*] AUTO DIGESTION [*]"+OFF+"\n");
        command("digest", ob); 
      }
    }

    if (IPOB->query_auto_targ() && att)
    {
      object targOb;
      string targName, attName;
      targOb   = (object)IPOB->query_target();
      if (targOb) targName = (string)targOb->query_name();
      else        targName = 0;
      attName  = (string)att->query_name();
      if (!targName || targName != attName)
      {
        tell_object(ob, BOLD+"[*] AUTO TARGETING [*]"+OFF+"\n");
        command("target", ob); 
      }
    }

    if (IPOB->query_auto_rej())
    {
      if (myhp > mymaxhp*2/3 && mysp < mymaxsp/2 &&
          !IPOB->query_regen() && !IPOB->query_rejuv())
      {
        tell_object(ob, BOLD+"[*] AUTO REJUVENATION [*]"+OFF+"\n");
        command("rej", ob); 
      }
    }
  }

  return 1;
}
