#include "../DEFS.h"
#include DEFS_ENHANCEMENTS


string get_flux_damage(int num, int num2)
{
  int perc;
  string mess;

  if (num == 0) num = -1;
  perc = (num2 * 100) / num;

  if (perc < 10)
    mess = " dodges nearly all of the FluX blast...\n";
  if (perc >= 10 && perc < 25)
    mess = " dodges most of the FluX blast...\n";
  if (perc >= 25 && perc < 50)
    mess = " partially dodges the FluX blast...\n";
  if (perc >= 50)
    mess = " is hit by the BRUNT of the FluX blast.\n";
  if (perc >= 75)
    mess = " suffers a DIRECT HIT by the FluX blast!\n";

  return mess;
}


status main(string who)
{
  /* concentrated dmg enhancement */
  object ob;
  int dmg, messnum, glev, i, k, failCheck, spCost;
  status hasFlux, syncFlux;
  string fluxType, dmgType, fluxColor, fluxName, fluxSymbol, msg, spaces;
  string *fluxList;

  if (IPTP->query_use_delay())
  {
    write("Your processor is recovering from use < "+IPTP->query_use_name()+" >\n");
    return 1;
  }

  hasFlux = (status)IPTP->item_electricflux() ||
            (status)IPTP->item_heatflux() ||
            (status)IPTP->item_magneticflux();

  if (!hasFlux && !IPTP->guild_wiz())
    return 0;

  if (!who)
  {
    if (!TP->query_attack())
    {
      write("You need to specify a target.\n"); 
      return 1;
    }
    else ob = (object)TP->query_attack(); 
  }
  if (who)
  {
    if (!present(who, environment(TP)))
    {
      write("There is no "+capitalize(who)+" here.\n"); 
      return 1;
    }
    else ob = present(who,environment(TP)); 
  }

  /* Feldegast 2-25-01 */
  if (this_player()->query_dead())
  {
    notify_fail("You are a ghost!\n");
    return 0;
  }

  /* mizan 25 jul 2004 */
  if(environment(this_player()) && environment(this_player())->query_no_fight())
  {
     notify_fail("Fighting is NOT allowed to begin here.\n");
     return 0;
  }

  syncFlux = (status)IPTP->query_flux_hb();

  /* temporarily disabled spell_object fluxing */
  /* if (syncFlux) write("Auto-switching to asynchronous flux...\n"); */
  syncFlux = 0;

  if (!syncFlux && !call_other(COMBATD, "valid_attack", ob, TP))
  {
    write("You cannot FluX that!\n");
    return 1;
  }

  if (!TP->query_interactive()) return 1;

  if (!((int)IPTP->query_flux_charges()))
  {
    write("You must charge your FluX before you can use it.\n");
    return 1; 
  }

  glev = (int)IPTP->guild_lev();
  dmg = (glev / 2) * (random(6)+5);
  spCost = dmg+10;

  if (!gotsp(TP, spCost)) return 1;

  fluxType = (string)IPTP->query_flux_type();
  if (!fluxType)
  {
    /* get a random flux type */
    fluxList = (string*)call_other(ENHANCEMENTD, "getFluxInfoList", "type");
    fluxType = fluxList[random(sizeof(fluxList))];
  }

  fluxName = (string)call_other(ENHANCEMENTD, "getFluxInfo", "name", fluxType);
  fluxColor = (string)call_other(ENHANCEMENTD, "getFluxInfo", "color", fluxType);
  fluxSymbol = (string)call_other(ENHANCEMENTD, "getFluxInfo", "symbol", fluxType);

  dmgType = "other|"+fluxType;

  failCheck = random(100);

  IPTP->add_flux_charges(-1);
  IPTP->save_me();

  if (glev + 85 < failCheck)
  {
    write(BOLD+"Your flux generator backfires!"+OFF+"\n");
    if ((int)TP->query_attrib("wil") < random(25))
    {
      write(fluxColor+"Radical "+fluxName+" rays rip through your body!"+OFF+"\n");
      TP->hit_player(random(glev)+1, dmgType);
    }
    TP->add_spell_point(-(random(20)));
    return 1;
  }

  msg = "";
  spaces = "";

  if (dmg <= 15)
  {
    msg += fluxColor;
    for (i=1; i <= 3; i++)
    {
      msg += spaces;
      for (k=1; k <= i*4; k++)
      {
        msg += fluxSymbol;
      }
      msg += "\n";
      spaces += pad(" ", 4);
    }
    msg += OFF;
  }

  if (dmg >= 16 && dmg <= 29)
  {
    msg += fluxColor;
    for (i=1; i <= 4; i++)
    {
      msg += spaces;
      for (k=1; k <= i*5; k++)
      {
        msg += fluxSymbol;
      }
      msg += "\n";
      spaces += pad(" ", 5);
    }
    msg += OFF;
  }

  if (dmg >= 30)
  {
    msg += fluxColor;
    for (i=1; i <= 5; i++)
    {
      msg += spaces;
      for (k=1; k <= i*7; k++)
      {
        msg += fluxSymbol;
      }
      msg += "\n";
      spaces += pad(" ", 7);
    }
    msg += OFF;
  }

  /* Cost of charging, failure, and enhancement are in addition */
  if (!syncFlux)
  {
    tell_room(environment(TP),
      "<<<<< "+TPN+" releases a burst of "+fluxName+" FluX into "+OPN+"! >>>>>\n\n");
    tell_room(environment(TP), msg+OFF+"\n");
    TP->add_spell_point(-spCost);
    messnum = (int)ob->hit_player(dmg, dmgType);
  }
  else
  {
    TP->spell_object(ob, "Flux", dmg, spCost,
      "You release a burst of "+fluxName+" FluX into "+OPN+"! >>>>>\n\n"+msg+OFF+"\n",
      TPN+" releases a burst of "+fluxName+" FluX into you! >>>>>\n\n"+msg+OFF+"\n",
      TPN+" releases a burst of "+fluxName+" FluX into "+OPN+"! >>>>>\n\n"+msg+OFF+"\n");
  }

  if (ob)
  {
    if (!syncFlux)
    {
      write(LINE+capitalize((string)ob->query_name())+get_flux_damage(dmg, messnum)+LINE);
    }
    if(!TP->query_attack()) TP->attack_object(ob);
    if(!ob->query_attack()) ob->attack_object(TP);
  }

  IPTP->set_use_delay(1);
  IPTP->set_use_name("Flux");
  return 1;
}
