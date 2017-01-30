inherit "/obj/monster";
#include "/players/fred/closed/bloodfist/defs.h"
#define ENTER "A guard storms into the room...\n"
#define EXIT "A guard storms out of the room ready for battle...\n"
object morningstar,breastplate,boots,helm,gd,gda,*all,ths,nmy,*nmys;
object *x,guard_timer,tt,ob;
int f,q,l,p,yep,now;
int chan_shout, a, sa;

reset(arg){
  if(arg) return;
  ::reset(arg);
/*
  x = ({  "/players/fred/closed/bloodfist/r/armory",
          "/players/fred/closed/bloodfist/r/backroom",
          "/players/fred/closed/bloodfist/r/courtyard",
          "/players/fred/closed/bloodfist/r/entrance_in",
          "/players/fred/closed/bloodfist/r/entrance_out",
          "/players/fred/closed/bloodfist/r/graveyard",
          "/players/fred/closed/bloodfist/r/hall",  
          "/players/fred/closed/bloodfist/r/lockers",
          "/players/fred/closed/bloodfist/r/lookout",
          "/players/fred/closed/bloodfist/r/meeting",
          "/players/fred/closed/bloodfist/r/open",
          "/players/fred/closed/bloodfist/r/portal",
          "/players/fred/closed/bloodfist/r/well",
      });
*/
  nmys = ({ });

  chan_shout = 0;

  helm = clone_object("/obj/armor.c");
  helm->set_weight(2);
  helm->set_value(2300);
  helm->set_type("helmet");
  helm->set_name("fullhelm");
  helm->set_alt_name("helm");
  helm->set_alias("fullhelm");
  helm->set_short("A fullhelm");
  helm->set_long(
    "This fullhelm protects the wearers entire head.  Steel bars extend\n"+
    "from beneath the eye slits down over the wearers mouth and chin.\n"+
    "At the very top of the helm is a steel point which protrudes into\n"+
    "the air.\n");
  helm->set_ac(1);
  move_object(helm, this_object());
  init_command("wear helmet");

  boots = clone_object("/obj/armor.c");
  boots->set_weight(2);
  boots->set_value(800);
  boots->set_type("boots");
  boots->set_name("black leather boots");
  boots->set_short("Leather boots");
  boots->set_long(
    "A pair of leather boots.  They are well made however would\n"+
    "only provide moderate protection.  They look as though they were\n"+
    "recently cleaned, however still hand sand and dirt on them.\n");
  boots->set_ac(1);
  move_object(boots, this_object());
  init_command("wear boots");

  breastplate = clone_object("/obj/armor.c");
  breastplate->set_weight(2);
  breastplate->set_value(500);
  breastplate->set_type("armor");
  breastplate->set_name("beastplate");
  breastplate->set_alias("plate");
  breastplate->set_short("A light breastplate");
  breastplate->set_long(
    "This is a well made breastplate with an insignia of swirling\n"+
    "sand on the front.  It looks moderately heavy.\n");
  breastplate->set_ac(3);
  move_object(breastplate, this_object());
  init_command("wear armor");

  morningstar = clone_object("/obj/weapon.c");
  morningstar->set_weight(3);
  morningstar->set_class(19);
  morningstar->set_type("sword");
  if(!random(2))
  {
    morningstar->set_name("broadsword");
    morningstar->set_short("A broadsword");
    morningstar->set_long("This is a simple looking broadsword.\n");
  }
  else {
    morningstar->set_name("longsword");
    morningstar->set_short("A longsword");
    morningstar->set_long("This is a simple looking longsword.\n");
  }
  morningstar->set_value(1400);
  move_object(morningstar, this_object());
  init_command("wield sword");

  set_name("guard");
  set_alias("bloodfist guard");
  set_short("A Bloodfist Guard");
  set_long(
"This guard of the Bloodfist guild is ready to defend the guild hall\n"+
"with his life.  He is well clad in armor and looks prepared to fight\n"+
"should the opportunity arise.  He is watching the area closely.\n");
  set_race("human");
  set_level(20);
  set_ac(17);
  set_heal(1,2);
  set_ac_bonus(5);
  set_wc(40+random(3));
  set_hp(1000+random(100));
  set_gender("male");
  set_chat_chance(1);
  set_a_chat_chance(1);
  load_chat("The guard surveys the area.\n");
  load_a_chat("The guard attacks with his sword.\n");
  set_chance(15);
  set_spell_dam(60);
  set_spell_mess1("The guard gets a lucky blow.\n");
  set_spell_mess2("The guard hits you with a lucky blow.\n");
  set_dead_ob(this_object());
  l = 0;
}

heart_beat()
{
  ::heart_beat();
  if(!environment()) return;
  all = all_inventory(environment());
  sa = sizeof(all);
  for(a = 0; a < sa; a++)
  {
    gd = all[a];
    if(gd->id("bloodfist guard") && (this_object() != gd)
      && (gda = gd->query_attack()))
      attack_object(gda);
  }
  if(!attacker_ob && gd->is_player() && gd->query_guild_name() != "bloodfist" && !random(2))
  {
    tell_room(environment(),
      "\n"+
      "         "+this_object()->short()+" yells at "+gd->query_name()+":\n"+
      "\"You are not a member of the "+BOLD+RED+"Bloodfist"+NORM+" ...Prepare to die!\"\n\n"); 
      attack_object(gd);
  }
  if(this_object()->query_attack()) nmy = attacker_ob;  
  if(!chan_shout && nmy && nmy->is_player())
  {
    CHAN_DAEMON->hprint(RED+" WARNING "+NORM+BOLD+BLK+
      capitalize((string)nmy->query_real_name())+
      " is trying to break into the guild hall!"+NORM);
    chan_shout = 1;
  }
  if(nmy && !nmy->is_player())
    nmy->hit_player(20);
}

monster_died()
{
  tell_room(environment(attacker_ob),
    "The guard gasps, \"You may have defeated me but you can't defeat us all...\"\n");
  tell_room(environment(attacker_ob),
    "                 \"We'll never give up!\"\n");
  GUARD_DAEMON->guard_death();
}

hunt()
{  
  if(this_object()->query_attack())
  {
    remove_call_out("hunt");
    call_out("hunt", 10);
    return 1;
  }
  nmys = ({ });
  yep = 0;
  while(l < sizeof(x))
  {
    ths = all_inventory(x[l]);
    for(p = 0; p < sizeof(ths); p++)
    {
      if(ths[p]->is_player() && !ths[p]->query_ghost() && ths[p]->query_guild_name() != "bloodfist")   
      {
        nmys += ({ ths[p], });
        yep = 1;
      }
    }
   l++;
  }
  if(yep > 0)
  {
    tt = nmys[random(sizeof(nmys))];
    if(present(tt, environment(this_object())))
    {
      this_object()->attack_object(tt);
    }
    else
    {
      tell_room(environment(this_object()), EXIT);
      move_object(this_object(), environment(tt));
      tell_room(environment(this_object()), ENTER);
      this_object()->attack_object(tt);
    }
  }
}

destroy()
{
  if(!nmy)
  {
    remove_call_out("destroy");
    call_out("destroy", 10);
    return 1;
  }
  ob = attacker_ob->query_real_name();
  gda = find_living(ob);
  if(!gda || gda->query_ghost() || creator(environment(gda)) != "fred")	 
  {
    tell_object(find_player("fred"), "Check Check.\n");
    remove_call_out("destroy");
    return 1;
  }
  if(!present(gda, environment(this_object())))
  {
    tell_room(environment(), EXIT);
    move_object(this_object(), environment(gda));
    tell_room(environment(), ENTER);
    now = 1;
  }
}



