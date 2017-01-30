#include "defs.h"
#include "/players/fred/closed/venom/obj/variables.h"
#include "/players/fred/closed/venom/obj/weapon.h"
#include "/players/fred/closed/venom/obj/armor.h"
#include "/players/fred/closed/venom/obj/settings.h"
#include "/players/fred/closed/venom/obj/guilddeath.h"
#include "/players/fred/closed/venom/obj/defense.h"
#include "/players/fred/closed/venom/obj/bitetwo.h"
#include "/players/fred/closed/venom/obj/clawstwo.h"
#include "/players/fred/closed/venom/obj/slamtwo.h"
#include "/players/fred/closed/venom/obj/kicktwo.h"
/************ Evolutions *****************/

/*
query_auto_load()
{
  save_object(SAVE_PATH+NAME);
  return "/players/fred/closed/venom/venom.c:"; 
}
*/

reset(arg)
{
  if(arg) return;
  set_heart_beat(2);
}


#define ID_ARR ({"guild_object","venom_object","no_pet","no_spell","link",\
              "guild_death_object","no_mini","party object","venom_object_chal","GI" })
#define ID_CHANGED_ARR ({ "notarmor","notweapon","pro_object","player_short_object","guild_monitor", "GI" })

id(string str)
{
  return (member_array(str, ID_ARR) > -1 ||
          (query_venomed() && member_array(str, ID_CHANGED_ARR) > -1));
}

/* When in combat, this share_exp() catches the incoming first, checks
   what is being fought, and records several things about it.  An
   improved version of the MK scar really. */

share_exp(int i)
{
  if(i > query_best_xp_score())
  {
    set_best_xp_score(i);
    set_best_xp_name(ATT->short());
  }
  if(ATT->is_player())
  {
    add_total_pks(1);
    add_total_level_pks(ATT->QL);
    write_file("/players/fred/closed/venom/pks/"+USER->QN+"",
      ATT->QRN+" "+ctime(time())+" Level: "+ATT->QL+"\n");
 }

/* I used the check for the party object with "party" hoping
   this won't conflict since i need "party_object" and
   "party object" for other things. But who would use "party"
    as an id() for an object??? heh. */

  if(present("party", ENV()))
  {
     present("party", ENV())->share_exp(i);
  }
  else
  {
    USER->add_exp(i);
    TOM "Experience Gained: "+i+".\n");
  }
  return 1;
}

mini_dest(str)
{
  TOM BOLD+CAP((string)query_symbiote())+NORM+" shouts: \"We do not owe allegiance to the "+str+"!\"\n");
  return;
}

call_pet()
{
  if(previous_object()->is_pet())
  {
    TRM BOLD+CAP((string)query_symbiote())+NORM+" becomes insanely jealous and devours the pet!\n");
    destruct(previous_object());
    return 1;
  }
  return 1;
}

extra_look()
{
  string str, me;

  str = ""+HIW+USER->QN+" has a symbiotic link to "+CAP((string)query_symbiote())+""+NORM;
  me  = ""+HIW+"You have a symbiotic link to "+CAP((string)query_symbiote())+" "+HIR+"["+(int)query_mp()+"]"+NORM+"";
    
  if(query_shaped() && (string)query_shapetype() == "sword")
  {
    str += "\n"+HIW+USER->QN+"'s arm has taken on the shape of an Sword"+NORM;
    me  += "\n"+HIW+"Your arm has taken on the shape of a Sword"+NORM;
  }
  else if(query_shaped() && (string)query_shapetype() == "axe")
  {
    str += "\n"+HIW+USER->QN+"'s arm has taken on the shape of an Axe"+NORM;
    me  += "\n"+HIW+"Your arm has taken on the shape of an Axe"+NORM;
  }
  else if(query_shaped() && (string)query_shapetype() == "spear")
  {
    str += "\n"+HIW+USER->QN+"'s arm has taken on the shape of an Spear"+NORM;
    me  += "\n"+HIW+"Your arm has taken on the shape of a Spear"+NORM;
  }
  else if(query_shaped() && (string)query_shapetype() == "shield")
  {
    str += "\n"+HIW+USER->QN+"'s arm has taken on the shape of an Shield"+NORM;
    me  += "\n"+HIW+"Your arm has taken on the shape of a Shield"+NORM;
  }	
  else if(query_shaped() && (string)query_shapetype() == "maul")
  {
    str += "\n"+HIW+USER->QN+"'s arm has taken on the shape of an Maul"+NORM;
    me  += "\n"+HIW+"Your arm has taken on the shape of a Maul"+NORM;
  }	
  if(TP != ENV(TO))
  {
    return str;
  }
  else
  {
    return me;
  }
}

long()
{
  TOM "  This is the link between you and the creature known\n"+
      "as "+BOLD+CAP((string)query_symbiote())+NORM+".  For mental instructions on how to us it\n"+
      "type: "+HIR+"link_help"+NORM+".\n");
  return 1;
}

init_arg(str){ }

init()
{
  object symb_shad;
  int c;
  string *spells, cmd;
	
  if(!ENV()) return;
  ENV()->set_guild_name("symbiote");
  ENV()->set_guild_file("/players/fred/closed/venom/venom.c");
  if(TP)
  {
    if(!TP->is_player()) return;
  }
  restore_object(SAVE_PATH+NAME);
  if(USER->QL < 20)
  {
    USER->set_guild_name(GUILDNAME);
  }
  if(USER->QL < 20)
    write_file("/players/fred/log/venom_xp",
               "Login: "+ctime(time())+"  "+NAME+
               "  [Level  "+USER->QL+"+"+USER->QEL+"] "+(int)query_hb_count()+" "+
               ""+USER->query_exp()+"\n");
  if(!query_symbiote()) set_symbiote("unnamed");
  set_hb_count(0);
  set_old_exp(0);
  set_has_changed(0);
  set_hyper_mode(0);
  set_venomed(0);
  /*
  set_defense_bonus(0);
  */ 

  add_action("new_say", "say");
#ifndef __LDMUD__ /* Rumplemintz */
  add_action("new_say", "'");
  add_action("new_say"); add_xverb("'");
#else
  add_action("new_say", "'", 3);
#endif
  add_action("changeform", "changeform");
  add_action("ssave", "save");

  c = sizeof(spells = files("/players/fred/closed/venom/power/"+"*.c"));
  while(c--)
  {
    sscanf(spells[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }
  
  TOM  "************************* SYMBIOTES *********************************\n"+
       "Your guild hall is located at: church, s,4w,6n,u,2w,n, enter crack \n"+
       "*********************************************************************\n\n");
	
  TOM  HIR+"\n\nDon't forget to check the "+HIW+"'news'"+HIR+" in the Guild Hall for updates!\n");

  TOM  HIR+"\n\n\nWARNING: THE CLOCK TOWERS RING IS SONIC!! IT HURTS.\n"+
       "ALSO, READ THE GUILD NEWS FOR UPDATES!\n\n\n"+NORM);
	
  call_other(USER, "wear", this_object(), 1, "mine", 
    ({"physical",0,0,"shield_bonus"}));
	
  set_type("mine");
  set_ac(0);
  worn_by = USER;
  worn = 1;
  set_class(0);
}

mixed cmd_hook(string str)
{
  string go;

  go = "/players/fred/closed/venom/power/"+query_verb()+".c";

  if(file_size(go) > 0)
    return (mixed) go->main(str, this_object(), this_player());
  return 0;
}

/*****  New Damager for Sonic type attacks ****/
sonic_damager(int i)
{
  if(i < 1) return 0;
  if(i > 1000 && query_venomed())
  {
    TOM "The sonic damage is too much for your symbiote to withstand!\n");
    command("changeform", USER);
    return 1;
  }
  else if(i < 301 && query_venomed())
  {
    USER->hit_player(random(i));
    USER->add_hit_point(-(random(i)));
    add_mp(-(random(i / 20)));
  }
  return;
}

pklister()
{
  write("Player Kills:\n");
  cat("/players/fred/closed/venom/pks/"+USER->QRN+"");
  return 1;
}

restore_venom()
{
  TOM "Restoring Symbiotic Link...\n");
  restore_object(SAVE_PATH+NAME);
  return 1;
}

new_say(string str)
{
  if(!str)
  {
    write("Say what?\n");
    return 1;
  }
  if(query_venomed() && !query_uncovered())
  {
    TOM ""+HIW+"You hiss, '"+NORM+""+strsub(str, ({ "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are", "we am", "we are", "We am", "We are",
        "myself", "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours", "Mine", "Ours",
        "we was", "we are", "We was", "We are"}), 3)+""+HIW+"'"+NORM+"\n\n");

    TRM	""+BOLD+CAP((string)query_symbiote())+" hisses, '"+NORM+""+strsub(str, ({ "s", "ss", "S", "Sss", "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are",
        "we am", "we are", "We am", "We are", "myself", "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours", "Mine", "Ours",
        "we was", "we are", "We was", "We are"}), 3)+""+BOLD+BLK+"'"+NORM+"\n\n", ({USER}));
    return 1;
  }
  if(query_venomed() && query_uncovered())
  {
    if(USER->query_sp() < 5)
    {
      TOM "You don't have the energy to continue talking while supplanted.\n");
      return 1;
    }
    USER->add_spell_point(-5);
    return;
  }
  return;
}

heart_beat()
{
  int rate, reg;

  if(!ENV()) return;
  if(!USER->is_player()) return;
  if(USER->query_ghost()) return;

/***** HB counter for logs ***********************/
  if(USER->query_attack())
  {
    add_hb_count(1);
  }

  if(query_no_harden()) add_no_harden(-1);

/***** Symbiote Coward drawback ******************/
  if(query_venomed() && USER->query_attack() && (USER->query_hp()*10)/(USER->query_mhp()) < 2)
  {
    if(((USER->query_intoxination() * 2) + random(100)) > 
       ((USER->query_attrib("wil")*3)+ random(100)))
    {
      if(USER->query_mhp() > 150 && USER->QL > 9)
      {
        command("changeform", USER);
        command("drop all", USER);
        move_object(clone_object("/players/fred/closed/venom/OBJ/ouch.c"), ENV());
        
        TOM "\n\n"+
             HIR+CAP(query_symbiote())+" screams in fear as it retreats back into your spine!"+NORM+"\n\n");
      }
    }
  }
/*************************************************/

/********* Bite delay ****************************/
  if(query_bite_delay())
  {
    if(query_bite_delay() == 1)
    {
       TOM HIB+"You feel rested.\n"+NORM);
    }
  add_bite_delay(-1);
  }

  if(query_anti_webs()) set_anti_webs(0);

/****** If mp drops below 10 the symbiote will take 150 hps to survive ******/
  
  if(query_mp() < 10)
  {
    TOM "You feel a horrible pain as the symbiote feeds from your flesh to survive!\n");
    USER->hit_player(150);
    add_mp(10);
  }
	        
/***************************************************************************/

/**** infusion hurts a symbiote ******************/
  if(USER->query_infuse() && !random(6) && query_venomed())
  {
    TOM ""+HIR+"The infusion within your body eats away at your symbiote, you feel great pain!"+NORM+"\n");	
    USER->heal_self(-(5 + random(5)));
    if(USER->query_hp() <= 0)
    {
      USER->hit_player(1000);
    }
  }
/*************************************************/


/****** Burn off *********************************/

  if(query_burnoff() && USER->query_hp() < 50)
  {
    TOM "Your body can no longer sustain the burnoff process...\n");
    set_burnoff(0);
  }
  if(query_burnoff() && !USER->query_intoxination() && !USER->query_stuffed() &&
   !USER->query_soaked())
  {
    TOM "Your body no longer has toxins to reduce, stopping the burnoff process.\n");
    set_burnoff(0);
  }
  if(query_burnoff())
  {
    if(USER->query_hp() > 50 && random(100) > 24)
    {
      if(USER->query_intoxination())
      {
        USER->add_intoxination(-1);
        USER->add_hit_point(-1); 
      }
    }
    if(USER->query_hp() > 50 && random(100) > 24)
    {
      if(USER->query_stuffed())
      {
        USER->add_stuffed(-1);
      }
      if(USER->query_soaked())
      {
        USER->add_soaked(-1);
      }
     USER->add_hit_point(-1);
    }
    if(!random(3))
      TOM "You feel the waste in your body begin to dissipate...\n");
  }
/*************************************************/

  if(query_regen() && USER->query_sp() < 50)
  {
    TOM "Not enough energy to regen, stopping the regeneration process...\n");
    set_regen(0);
  }

/********* Regeneration **************************/
  if(query_regen() > 0)
  {
    if(USER->query_hp() == USER->query_mhp())
    {
      TOM ""+BOLD+CAP((string)query_symbiote())+NORM+" whispers, 'Our wounds are healed.\n");
      set_regen(0);
      return 1;
    }
    reg = random(6);
    USER->add_hit_point(reg);
    USER->add_spell_point(-reg);
    if(!random(5))
      TOM ""+BOLD+CAP((string)query_symbiote())+NORM+" slowly mends your wounds...\n");
  }
/*************************************************/


/****** Stop hypermode when dead *****************/
  if(query_hyper_mode() && USER->query_ghost())
  {
    set_hyper_mode(0);
  }
/*************************************************/	
	
	
/****** Hypermode attack *************************/
  if(query_hyper_mode())  
  {
    if(USER->query_attack())
      add_hyper_mode(-1);
    if(query_hyper_mode() < 0) 
      set_hyper_mode(0);
    if(!random(25) && !USER->query_attack())
    {
      switch(random(5))
      {
        case 4..100:
          TRM HIW+CAP((string)query_symbiote())+NORM+" flies wildly about the room in a mad rage!\n", ({ USER }));
          break;
        case 3:
          TRM HIW+CAP((string)query_symbiote())+NORM+" lashes out at imaginary enemies!\n", ({ USER }));
          break;
        case 2:
          TRM HIW+CAP((string)query_symbiote())+NORM+" howls with mad laughter!\n", ({ USER }));
          break;
        case 1:
          TRM HIW+CAP((string)query_symbiote())+NORM+" growls at you.\n", ({ USER }));
          break;
        default: 
          TRM HIW+CAP((string)query_symbiote())+NORM+"'s tongue lashes about violently!\n", ({ USER }));
          break;          
      }
    }
  }
/*************************************************/


/****** Set magic to 5 if higher *****************/
  if(USER->QL < 20)
  {
    /*
       CHANGED TO 9 WITH NEW STAT SYSTEM.  GIVES THEM MORE SPS THAN THE
       ORIGINAL GUILD ALLOWED.  FRED                                  
    */
    if(USER->query_attrib("mag") > 9)
    {
      TOM "Your symbiote feeds on your magical life! Magic drops to 9.\n");
      USER->set_attrib("mag", 9);
      USER->save();
      call_other(USER, "reset", 1);
    }
  }
/*************************************************/

/****** Set stealth to 30 if higher **************/

/* Reason for this is if they join felines and raise stealth
   before it dests they will have a 25 stealth. */
   
/* CHANGED TO 30 FOR NEW STAT SYSTEM - FRED */
  if(USER->QL < 20)
  {
    if(USER->query_attrib("ste") > 30)
    {
      USER->set_attrib("ste", 30);
      USER->save();
      call_other(USER, "reset", 1);
    }
  }
/*************************************************/
}

changeform()
{
  object inv;
  int x, w, mpamt;	
  if(!query_venomed())
  {
/***** Mp cost **********/
    if(query_changestat() > 5000)
    {
      mpamt = 150;
    }
    else if(query_changestat() > 1000)
    {
      mpamt = 160;
    }
    else if(query_changestat() > 600)
    {
      mpamt = 170;
    }
    else if(query_changestat() > 300)
    {
      mpamt = 180;
    }
    else if(query_changestat() > 100)
    {
      mpamt = 190;
    }
    else
    {
      mpamt = 200;
    }
/*************************/

    if(query_mp() < mpamt)
    { 
      TOM "You don't have the energy to do this!\n");
      return 1;
    }
    if(USER->query_sp() < 50)
    {
      TOM "You don't have the energy to do this!\n");
      return 1;
    }
    inv = all_inventory(USER);
    for(x = 0; x < sizeof(inv); x++)
    {
      if(inv[x]->query_worn() && inv[x]->is_armor() && inv[x]->query_type() != "mine")
      {
        TOM "You cannot change form while wearing armor!\n");
        return 1;
      } 	
    }
    for(w = 0; w < sizeof(inv); w++)
    {
      if(inv[w]->query_wielded() && inv[w]->query_type() != "mine")
      {
        TOM "You cannot change form while wielding a weapon!\n");
        return 1;
      }	
    }
    TRM "Tentacles of ooze suddenly lash out of "+USER->QN+"'s body.\n"+
        ""+USER->QN+" writhes in pleasure as "+USER->PRO+" is transformed into "+HIW+CAP((string)query_symbiote())+NORM+".\n");
    set_venomed(1);
    set_oldtitle((string)USER->query_title());
    set_oldalign((string)USER->query_al_title());
    set_oldpretitle((string)USER->query_pretitle());
    set_player_short(HIW+CAP((string)query_symbiote())+"  ("+HIR+" Symbiote "+HIW+")"+NORM);
    USER->add_spell_point(-50);
    wielded_by = USER;
    call_other(USER, "wield", TO, 1);
    wielded = 1;
    add_changestat(1);
    add_mp(-mpamt);
    USER->add_player_id(query_symbiote());
    save_object(SAVE_PATH+NAME);
    return 1;
  }  
  TRM "Dark matter retracts from "+USER->QN+"'s body.\n"+
      "It disappears into "+USER->POS+" spine.\n");
  set_shaped(0);
  set_shapetype(0);
  set_hyper_mode(0);
  set_burnoff(0);
  set_hardened(0);
  set_webf_delay(0);
  set_regen(0);
  set_venomed(0);
  set_no_harden(0);
  USER->set_title((string)query_oldtitle());
  USER->set_pretitle((string)query_oldpretitle());
  USER->set_al_title((string)query_oldalign());
  set_oldtitle(0);
  set_oldalign(0);
  set_oldpretitle(0);
  call_other(USER, "stop_wielding", TO);
  wielded = 0;
  wielded_by = 0;
  USER->remove_player_id(query_symbiote());
  save_object(SAVE_PATH+NAME);
  return 1;
}

ssave()
{
  TOM HIW+"\nSaving symbiotic link...."+NORM+"\n");

  save_object(SAVE_PATH+NAME);
  TOM HIR+"done."+NORM+"\n");
  return 0;
}

void dur_mon()
{
  string m;
  if(query_venomed())
    m = HIW+"  MP  [  "+query_mp()+"/300  ]"+NORM;

  if(query_regen())
    m += HIR+"  [Regen "+NORM+"ON"+HIR+"]"+NORM;

  if(query_burnoff())
    m += HIG+"  [Burnoff "+NORM+"ON"+HIG+"]"+NORM;

  if(query_hyper_mode())
    m += HIB+"  [Hypermode "+NORM+"ON"+HIB+"]"+NORM;

  TOM m+"\n");
}

void print_monitor()
{ 
  dur_mon(); 
}

