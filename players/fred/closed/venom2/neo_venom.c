int glvl;                         /* Guild Level   */
int gexp;                         /* Guild Exp     */
int mp;                           /* Matter Point  */
static int max_mp;                /* Max MP Amt    */
static int used_mp;
int stored_mp;                    /* Stored MP     */
int stored_sp;                    /* Stored SP's   */
int stored_mon;                   /* Stored Money  */
static int hyper;                 /* Hypermode Tog */
static int burnoff;               /* Burnoff Tog   */
static int regen;                 /* Regen Tog     */
static int body;
static int block;                
static int done;
static int delay;
string color;                     /* Guild Color   */
string *sh_armor;                 /* Shaped Armors */
static string sdelay;             /* Spell delay   */
string symbiote;                  /* Symb Name     */
int has_lair;                     /* Guild Cave    */
string lair;                      /* Path of Cave  */
static object pet;                /* Guild Pet     */
int creation;                     /* Creation Lvl  */
int combat;                       /* Combat Lvl    */
int control;                      /* Control Lvl   */
static int t_burn;                /* Tentacles     */        
static int t_regen;               /* Tentacles     */
static int t_attack;              /* Tentacles     */
static int t_defend;              /* Tentacels     */
static int wep_damage;          

#include "/players/fred/closed/venom2/defs.h"
#include "/players/fred/closed/venom2/obj/weapon.h"
#include "/players/fred/closed/venom/obj/clawstwo.h"
/*
#include "/players/fred/closed/venom2/obj/armor.h"
*/
#include "/players/fred/closed/venom2/obj/settings.h"

query_auto_load()
{
  save_object(SAVE_PATH+NAME);
  return "/players/fred/closed/venom2/neo_venom.c:"; 
}

reset(arg)
{
  if(arg) return;
  set_heart_beat(1);
}

extra_look()
{
  if(TP)
  {
    if(TP == USER) 
      return "Type 'link' to see a listing of your powers";
    else HIW+USER->QN+"'s "+query_color()+"Dark Matter"+NORM+HIW+" Link"+NORM;
  }
}

/*
short()
{
  string all, woo;
  int i,j,count;

  count = 0;
  if(!query_sh_armors()) return;
  for(j = 0; j < 8; j++)
  {
    if(sh_armors[j]) 
      count += 1;
  }
  if(count > 0) 
    woo = BOLD+"Shaped Armors:\n"+NORM;
  for(i = 0; i < sizeof(sh_armors); i++)
  {
    if(sh_armors[i]) 
      woo += "     "+sh_armors[i]+" (shaped)\n";
  }
  return woo;
}
*/

mini_dest(str)
{
  TOM "Do not rely on such weak things!\n");
  return;
}

call_pet()
{
  if(previous_object()->is_pet())
  {
    TOM "Your pet refuses to follow you and leaves the room.\n");
    TRM USER->QN+"'s pet refuses to follow "+USER->OBJ+" and leaves the room.\n");
    destruct(previous_object());
    return 1;
  }
  return 1;
}

init()
{
  int c;
  string *spells, cmd;

  if(done) return;
  if(!TP) return;
  if(!ENV()) return;
  if(ENV() != TP) return;
  set_glvl(1);
  this_object()->add_skill_pt(1);
  this_object()->set_gxp(0);
  set_color(NORM);
  add_mp(300);
  
  if(!query_symbiote()) 
    set_symbiote("Unnamed");
  
  restore_object(SAVE_PATH+NAME);
  
  if(USER->query_level() < 20)
    USER->set_guild_name(GUILDNAME);

  /* Armor bonuses */
  TP->RegisterArmor(TO, ({ "physical", 0, 0, "armor_special" }));

  c = sizeof(spells = files("/players/fred/closed/venom2/power/"+"*.c"));
  
  while(c--)
  {
    sscanf(spells[c], "%s.c", cmd);
    add_action("cmd_hook", cmd);
  }

  add_action("new_say", "say");
#ifndef __LDMUD__
  add_action("new_say"); add_xverb("'");
#else
  add_action("new_say", "'", 3);
#endif
  add_action("save_venom2", "save");

 /*
  message_hit=({
    ""+COLOR+"D E S T R O Y E D"+NORM+"", " with a frenzy of attacks",
    ""+COLOR+"Mutilated"+NORM+"", "'s body into bloody ribbons",
    ""+HIW+"Destroyed"+NORM+"", " with an onslaught of blows",
    ""+HIW+"Massacred"+NORM+""," into small fragments",
    ""+COLOR+"Slammed"+NORM+""," into the ground with bone shattering force",
    ""+HIW+"Smashed"+NORM+""," with a bone crushing sound",
    ""+HIW+"Hit"+NORM+""," very hard",
    ""+HIW+"Hit"+NORM+""," hard",
    ""+HIW+"Hit"+NORM+"","",
    ""+HIW+"Grazed"+NORM+"","",
    ""+HIW+"Tickled"+NORM+""," in the stomach",
  });
  */

  TOM HIR+"\n\n\n\nPLEASE NOTE, LAIRS CAN NOW BE ENTERED BY ANYONE!"+NORM+"\n\n\n\n");

  done = 1;
}

mixed cmd_hook(string str)
{
  string go;

  go = "/players/fred/closed/venom/power/"+query_verb()+".c";

  if(file_size(go) > 0)
    return (mixed) go->main(str, this_object(), this_player());
  return 0;
}

heart_beat()
{
  object symb, wep_shad, wep;
  int dead, reg;

  if(!ENV()) return ;
  if(USER->QL > 19) return;
  if(!USER->query_ghost() && dead) dead = 0;

  if(USER->query_ghost())
  {
    set_pet(0);
    /*
    if(sh_armors && !dead)
    { 
      TOM "Your shaped armors disappear as you die...\n");

      sh_armors = 0;
      sh_armors = allocate(8);
      dead = 1;
    }
    */
    set_hypermode(0);
    set_burnoff(0);
    set_regen(0);
    return;
  }	
  /*
  if(!USER->query_weapon() && !USER->query_ghost())
  {
    wielded_by = TP;
    call_other(USER, "wield", this_object(), 1);
    wielded = 1;
    TOM HIW+"Tentacles lash out and surround you offensively and defensively."+NORM+"\n");
  }
  */
  if(query_wep() && USER->query_weapon() != query_wep())
    set_wep(0);
  if(!query_wep() && USER->query_weapon() && USER->query_weapon() != this_object())
  {
    TOM HIW+"\nDark Matter lashes out and surrounds your weapon..."+NORM+"\n\n");
    set_wep(USER->query_weapon());
  }
		
  if(query_sdelay()) set_sdelay(0);
  if(query_mp() < 1) set_mp(1);
	
  if(query_burnoff() && query_tentacles_burn() > 0)
  {
    if(USER->query_hp() < 50)
    {
      TOM  query_color()+"Health too low -"+NORM+" stopping the burnoff process.\n");
      set_burnoff(0);
    }
    else if(query_burnoff() && !USER->query_intoxination() && 
            !USER->query_stuffed() && !USER->query_soaked())
    {
      TOM query_color()+"Your body no longer has toxins to reduce, stopping the burnoff process."+NORM+"\n");
      set_burnoff(0);
    }
    else
    {
      if(USER->query_hp() > 50 && random(100) < query_tentacles_burn() * 8)
      {
        if(USER->query_intoxination())
        {
          USER->add_intoxination(-1);
          USER->add_hit_point(-random(2));
        }
        
        if(USER->query_stuffed())
          USER->add_stuffed(-1);
	
        if(USER->query_soaked())
          USER->add_soaked(-1);
	
	USER->add_hit_point(-1);

        TOM "You feel the waste in your body begin to dissipate...\n");
      }
    }
  }
	
  if(USER->query_attack() && (USER->query_hp()*10)/(USER->query_mhp()) < 2)
  {
    if(((USER->query_intoxination() * 2) + random(100)) >
       ((USER->query_attrib("wil")*3)+ random(100)) && 
         !USER->query_attack()->is_player())
    {
      TOM HIR+"\n\n\nAs you grow weaker your Symbiote takes revenge on you for it's enslavement!"+NORM+"\n\n\n");

      symb = clone_object("/obj/monster.c");
      symb->set_name(HIR+query_symbiote()+NORM);
      USER->stop_fight();
      USER->stop_fight();
      USER->attacked_by(symb);
      USER->add_hit_point(-350);
      USER->hit_player(1000);

      write_file("/players/fred/closed/vemon2/logs/symb_kill",
        USER->QRN+" was killed by own Symbiote. "+ctime(time())+".\n");
    }
  }

  if(query_mp() < 10)
  {
    TOM "Your body requires "+BOLD+"Dark Matter"+NORM+" to survive!\n");
    USER->hit_player(150);
    add_mp(10);
  }
	
  if(USER->query_infuse() && !random(4))
  {
    TOM  ""+HIR+"The infusion within your body eats at you!"+NORM+"\n");
    USER->heal_self(-(5 + random(5)));
    
    if(USER->query_hp() <= 0)
      USER->hit_player(1000);
  }

  if(query_glvl() > 10 && USER->query_hp() < USER->query_mhp() && random(100) < query_glvl()/2 )
    USER->add_hit_point(1);
	
  if(query_hyper() && USER->query_attack()) 
    add_hyper(-1);
	
  if(query_hyper() && !random(40) && !USER->query_attack())
  {
    switch(random(5) + 1)
    {
      case 5:
        TRM USER->QN+"'s eyes blaze with an Inner "+query_color()+"Light"+NORM+".\n", ({ USER }));
	break;
      case 4:
        TRM "You blink back in dizziness as "+USER->QN+"'s form blurs slightly.\n", ({ USER }));
        break;
      case 3:
        TRM USER->QN+" tenses and relaxes over and over.\n", ({ USER }));
        break;
      case 2:
        TRM USER->QN+" breathes heavily as veins of "+HIW+"Dark Matter"+NORM+" pulse over "+USER->POS+" body.\n", ({ USER }));
        break;
      case 1:
        TRM USER->QN+" paces the ground as his form blurs.\n", ({ USER }));
        break;
    }
  }
	

  /****** Set magic to 9 if higher *****************/
  if(USER->QL < 20)
  {
    if(USER->query_attrib("mag") > 9)
    {
      TOM "Your body feeds on your magical life! Magic drops to 9.\n");
      USER->set_attrib("mag", 9);
      USER->save();
      call_other(USER, "reset", 1);
    }
  }
  /************************************************/
	

  /******** Bonus Strength - 35 max based on Control ******/
  if(USER->QL < 20)
  {
    if(USER->query_attrib("str") < USER->query_attrib_max("str") + (query_control() - 1))
    {
      TOM HIW+"Dark Matter"+NORM+" reinforces your musculature...\n");
      USER->set_attrib("str", USER->query_attrib_max("str") + (query_control() - 1));
      USER->save();
      USER->reset(1);
    }
  }
  /*************************************************/
	
  if(ENV(USER)->query_symb_cave()) 
    USER->heal_self(random(2) + 1);
	
  if(query_bad()) 
    add_bad(-1);

  if(USER->query_invis() && !random(4))
    add_mp(-1);

  if(USER->query_invis() && query_mp() < 50)
  {
    TOM query_color()+"\nYou run out of enough matter to sustain Camouflage."+NORM+"\n\n");
    USER->visible();
  }

  if(USER->query_invis() && USER->QL < 20 && query_mp() > 49) 
    USER->set_invs_sp();
	
  if(query_regen())
  {
    if(USER->query_sp() < 50)
    {
      TOM query_color()+"-- -- "+NORM+"Unable to maintain regeneration.  Stopping the process.\n");
      set_regen(0);
    }
  }
	
  if(USER->query_hp() == USER->query_mhp())
  {
    TOM query_color()+"-- -- "+NORM+"Fully regenerated.  Stopping regen process.\n");
    set_regen(0);
  }  

  if(query_regen() && query_tentacles_regen() > 0)
  {
    if(random(100) < query_tentacles_regen() * 6)
    {
      reg = random(6);
      USER->add_hit_point(reg);
      USER->add_spell_point(-reg);

      if(!random(5))
        TOM CAP((string)query_symbiote())+" slowly mends your wounds...\n");
    }
  }
}

adv_check(exp)
{
  if(query_glvl() > 15) return;
	
  add_gxp(exp);
	
  if(query_gxp() >= 250000)
  {
    add_gxp((int)query_gxp() - 250000);
    add_glvl(1);
    add_skill_pt(1);
		
    TOM "\n"+query_color()+"                  !!! You Gain a Level !!! "+NORM+"\n"+
        "               You are now Symbiote Level "+query_glvl()+".\n");
    
    if(query_gxp() >= 250000) 
    adv_check(0);
    save();
    return 1;
  }
  return 1;
}

save_venom2()
{
  TOM HIW+"\nSaving symbiotic link...."+NORM+"\n");

  save_object(SAVE_PATH+NAME);
  TOM HIR+"done."+NORM+"\n");
  return 0;
}

new_say(string str)
{
  if(!str)
  {
    TOM "Say what?\n");
    return 1;
  }
  if((USER->query_hp() * 10) / (USER->query_mhp()) < 4)
  {
    if(random(100) < (10 - (USER->query_hp() * 10) / (USER->query_mhp())) * 10)
    {
      TRM HIW+"Dark Matter"+NORM+" temporarily surrounds the face of "+USER->QN+"...\n");

      TOM ""+HIW+"You hiss, '"+NORM+""+strsub(str, 
          ({ "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are", "we am",
             "we are", "We am", "We are", "myself", "ourselves", "Myself", "Ourselves", "my", "our", "My",
             "Our", "mine", "ours", "Mine", "Ours", "we was", "we are", "We was", "We are"}), 3)+""+HIW+"'"+NORM+"\n\n");

      TRM ""+HIW+CAP((string)query_symbiote())+" hisses, '"+NORM+""+strsub(str, 
          ({ "s", "ss", "S", "Sss", "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm",
             "we are", "We'm", "We are", "we am", "we are", "We am", "We are", "myself",
             "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours",
             "Mine", "Ours", "we was", "we are", "We was", "We are"}), 3)+""+HIB+"'"+NORM+"\n\n", ({ USER }));
      return 1;
    }
  }
  return;
}

no_spell()
{
	write("You cannot do that.\n");
	return 1;
}

/************************************************************
**      No quit - woot.                                     **
*************************************************************/
quit_out(){
	if(USER->query_attack()){
		write("You cannot quit out while in combat!\n");
		return 1;
	}
	save_venom();
	return;
}

get(){ return 1; }
drop(){ return 1; }
query_weight(){ return 0; }
query_value(){ return 0; }


 id(str) { return str=="neo_venom_object"; }
