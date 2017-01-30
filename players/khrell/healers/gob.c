#include "def.h"
#include "cost.h"

static int count, rc, clr;
static int pow, lt, lv, pww;
static int ahlv, ahpww, ahmuch;
static int auto_heal;
static int flag_count;
static int reduced;
static string ahwho;
static object shade;
static string *mass_p;
static int mon_on, need_on;
static string *need_mon;
static string autotype;
string enter_msg;
int lev;

id(str) 
{
  return str == "healerob" || str == "mythos_healer" ||
         str == "healer_staff" || str == "GI" ||
         str == "staff" || str == "no_spell"; 
}

drop () { return 1; } /* undroppable */
get() { return 0; }   /* ungettable */

reset(arg) 
{
  if(arg) return;
  reset_m();
  reduced = 0;
  count = rc = clr = pow = 0;
  auto_heal = 0;
  mon_on = need_on = 0;
  lt = lv = pww = 0;
  ahlv = ahpww = ahmuch = 0;
  enter_msg = "enters the game.";
  shade = 0;
  need_mon = 0;
  mass_p = 0;
  flag_count = 0;
  set_heart_beat(1);
}

query_prevent_shadow() { return 1; }

short() { if(rc) return "Healer's Staff"; }

long() 
{
  if(rc) 
    write("A long white staff of stout oak.\n"+
	  "It is the tool of the Healer.\n"+
	  HIW+"hhelp"+NORM+" will give you the help files.\n"); 
}

void guild_login()
{
  TP->set_guild_file(ROOT+"gob.c");
  TP->set_home(HOME_H);

  if((string)TP->query_guild_name() != "healer")
    TP->set_guild_name("healer");
}

init() 
{
  int c;
  string *spells, cmd;
 
  if(!ENV) return;

  if(TP == ENV) 
  {
    if(!TP->query_guild_name("healer"))
    { 
      destruct(this_object()); 
      return; 
    }

    if(!clr) 
    {
      shade = clone_object(ROOT+"obj/shade.c");
      shade->shadow_healer_on(TP);
      clr = 1;
      call_other(ROOT+"obj/chandaem.c","add_channel", TP);

      if(!TP->query_invis() && LVL < 60)
        call_other(ROOT+"obj/chandaem.c", "speak_channel", RED+"("+BLU+"] "+NORM+ENV->QN+" "+enter_msg+"\n");

    }

    add_action("needmon","need_mon");
    add_action("list_need","list_need");
    add_action("squit","quit");
    add_action("guild_leave","guild_leave");
    add_action("monitoring","heal_mon");
    add_action("add_need","add_need");
    add_action("clear_need","clear_need");
    add_action("add_mass","add_mass_heal");
    add_action("add_mass","show_mass");
    add_action("clear_mass","clear_from_mass");

    c = sizeof(spells = files(ROOT+"power/"+"*.c"));
   
    while(c--)
    {
      sscanf(spells[c], "%s.c", cmd);
      add_action("cmd_hook", cmd);
    }
   
    /****** Move the following actions to the Power Dir ******/

    add_action("hhistory","hhistory");
    add_action("heal","chant");
    add_action("heal","heal");
    add_action("heal","hp");
    add_action("heal","sp");
    add_action("peace","peace");
    add_action("fortify","fortify");
    add_action("cure","cure");
    add_action("mystic_transfer","mystic_transfer");
    add_action("defend","defend");
    add_action("reduce","reduce");
    add_action("resurrect","resurrect");
    add_action("shield","shield");
    add_action("simulcrum","illusion");
    add_action("simulcrum","simulcrum");
    add_action("potion","potion");
    add_action("reinstate","reinstate");
    add_action("regenerate","regenerate");
    add_action("haven","haven");
    add_action("bless","minor_blessing");
    add_action("cove","cove");
    add_action("grant","grant");
    add_action("salve","salve");
    add_action("healing_spring","healing_spring");
    add_action("robe_of_healing","robe_of_healing");
    add_action("holy_blessing","holy_blessing");
    add_action("mass_heal","mass_heal");
    add_action("full_heal","full_heal");

    /****** Move the above actions to the Power Dir ******/

  }
}

mixed cmd_hook(string str)
{
  string go;

  go = ROOT+"power/"+query_verb()+".c";

  if(file_size(go) > 0)
    return (mixed) go->main(str, TO, TP);
  return 0;
}

/*********VARIABLES**********/

set_rec() { rc = 1; }
query_rec() { return rc; }

set_enter_msg(str){ enter_msg = str; }
query_enter_msg(){ return enter_msg; }

set_reduced(int a){ reduced = a; }
query_reduced(){ return reduced; }

set_lt(int a){ lt = a; }
query_lt(){ return lt; }

add_lv(int a){  lv = lv + a; }
query_lv(){ return lv; }

set_pww(int a){ pww = a; }
query_pww(){ return pww; }

/*******END*************/


h_level() 
{
  string TITLE_H;
  string Tpart, Tpart2;
  int cexp, xxp, hhh, mss;
  int nss;
  
  if(ENV->query_level() < 20) 
  {
    int h;
	
    xxp = ENV->EXP;

    cexp = call_other("room/adv_guild", "check_level", ENV->LVL);

    if(xxp < cexp) 
      call_other("room/adv_guild", "correct_level", ENV);

    if(ENV->EXLVL) 
    {
      cexp = call_other("room/exlv_guild", "check_level", ENV->EXLVL);

      if(xxp < cexp) 
        call_other("room/exlv_guild", "correct_extra_level", ENV);
    }
	
    if((hhh = ENV->query_guild_rank()) != (ENV->LVL + ENV->EXLVL)) 
      ENV->add_guild_rank((ENV->LVL + ENV->EXLVL) - hhh);

    lev = ENV->LVL + ENV->EXLVL;

    if(lev > 119) lev = 119;

    TITLE_H = call_other(POWER, "titler", lev);
  
    if(ENV->query_gender() == "female") 
    {
      if(sscanf(TITLE_H,"%sriest%s",Tpart,Tpart2) == 2) TITLE_H = Tpart + "riestess" + Tpart2;
  
      if(sscanf(TITLE_H,"%sPatriarch%s",Tpart,Tpart2) == 2) TITLE_H = Tpart + "Matriarch" + Tpart2;
    }
	
    ENV->set_title(TITLE_H);

    if(lev < 5) 
      tell_object(ENV,
       "You are a disgrace!\nGo back to your study and repent to gain what was lost!\n");
  } 
 
  else lev = 119;

  pow = ENV->query_attrib("pie");
  nss = 0;

  if(!need_mon) nss = 1;
  else if(sizeof(need_mon) != lev/5) nss = 1;

  if(nss) 
  {
    tell_object(ENV,
      "Need Monitor set to "+lev/5+" players.\n");
    
    need_mon = allocate(lev/5);
  }
  if(mass_heal_var[0] - 1 < lev) 
  {
    mss = 0;

    if(!mass_p) mss = 1;
    else if(sizeof(mass_p) != lev/5) mss = 1;

    if(mss) 
    {
      tell_object(ENV,
        "Resetting mass healing capacity.\n"+
        "Now you may mass heal up to "+lev/5+" beings.\n");

      mass_p = allocate(lev/5);
    }
  }
  return 1; 
}

heart_beat() 
{
  string monitor;
  
  if(!ENV) { set_heart_beat(0); return 1; }

  h_level();

  if(!ENV->query_attack() && mon_on) 
  {
    monitor = " <<<<  HP"+ENV->HP+"/"+ENV->MHP;
    monitor += " SP "+ENV->SP+"/"+ENV->MSP;
    monitor += " I "+(ENV->query_intoxination()*100/(ENV->query_max_intox()))+"%";
    monitor += " F "+(ENV->query_stuffed()*100/(ENV->query_max_stuff()))+"%";
    monitor += " S "+(ENV->query_soaked()*100/(ENV->query_max_soak()))+"%";
    monitor += "  >>>>\n";

    tell_object(ENV, monitor);
  }

  if(need_on) need_monitor();

  if(ENV->query_attack())
  {
    flag_count = 0;

    if(!ENV->query_combat_flag()) 
      ENV->set_combat_flag(1);
  } 
 
  else 
  {
    if(flag_count > FLAGCOUNT + random(FLAGRND)) 
    {
      ENV->set_combat_flag(0);
      flag_count = 0;
    } 
    
    else 
      flag_count++;
  }

  if(count > 10) 
  { 
    move_object(TO, ENV); 
    count = 0; 
  } 
  
  else count++;
}

need_monitor() 
{
  string NEEDMON;
  object needer;
  int j, nhp, nsp;
  int itx, f, s;
  int nip;

  if(reduced) 
    NEEDMON = "hp/sp/t  ";
  else 
    NEEDMON = "hp/sp/i/f/s/t  ";
    
  for(j=0; j<sizeof(need_mon); j++) 
  {
    if(need_mon[j]) 
      if(needer = present(need_mon[j], environment(ENV))) 
        if(needer->is_player()) 
        {
          if(needer) 
          {
            nhp = needer->HP * 10/needer->MHP;
            nsp = needer->SP * 10/needer->MSP;
            nip = needer->query_infuse() * 10/needer->query_infuse_limit();

            if(!reduced) 
              f = needer->query_stuffed() * 10/ (needer->query_max_stuff());
		
            if(!reduced) 
              itx = needer->query_intoxination()*10/(needer->query_max_intox());

            if(!reduced) 
              s = needer->query_soaked()*10/(needer->query_max_soak());
			
            if(reduced) 
              NEEDMON += need_mon[j]+" : "+nhp+"/"+nsp+"/"+nip+"  ";

            else 
              NEEDMON += need_mon[j]+" : "+nhp+"/"+nsp+"/"+itx+"/"+f+"/"+s+"/"+nip+"  ";
          }
	}
  }
  tell_object(ENV, BLU+"  [] "+NORM+NEEDMON+"\n");
  return 1; 
}

list_need() 
{
  add_need();
  return 1; 
}

needmon() 
{
  if(need_on) 
  { 
    write("You turn off the Need Monitor.\n"); 
    need_on = 0; 
    return 1; 
  }
  
  else 
  { 
    write("You turn on the Need Monitor.\n"+
          "Max Need Slots: "+lev/5+"\n"); 
    need_on = 1; 
    return 1; 
  }
}

monitoring() 
{
  if(mon_on) 
  { 
    write("You turn the heal monitor off\n"); 
    mon_on = 0; 
    return 1; 
  }
  
  else 
  { 
    write("You turn on the heal monitor\n"); 
    mon_on = 1; 
    return 1; 
  }
}

add_need(str) 
{
  int l;

  if(!str) 
  {
    write("Your Need Monitor Members [max #:"+lev/5+"]: \n");
    
    for(l=0; l<sizeof(need_mon); l++) 
    {
      if(need_mon[l]) 
        write("  "+capitalize(need_mon[l]));
    }
    write("\n");
    return 1; 
  }
  
  while(l < sizeof(need_mon)) 
  {
    if(!need_mon[l]) 
    { 
      need_mon[l] = lower_case(str); 
      l = 100; 
    }

    else l++;
  }
  
  if(l != 100) 
  { 
    write("Your capacity for Need Monitor is at max.\n"); 
    return 1; 
  }
  
  write(str+" added to Need Monitor Members.\n");
  return 1; 
}

clear_need(str) 
{
  int l;
  
  if(!str) 
  { 
    write("Clear who?\n"); 
    return 1; 
  }

  if(str == "all") 
  {
    for(l=0; l<sizeof(need_mon); l++) 
      need_mon[l] = 0;
	
    write("You have cleared your Need Monitor Members.\n");
    return 1; 
  }
  
  if((l = member_array(lower_case(str), need_mon)) == -1) 
  { 
    write("That person is not in your Need List.\n"); 
    return 1; 
  }
  
  need_mon[l] = 0;
  write(str + " has been removed from the Need Monitor Members.\n");
  return 1; 
}

squit() 
{
  SOE;

  if(!TP->query_invis() && TP->LVL < 60)
    call_other(ROOT+"obj/chandaem.c","speak_channel",
      RED+"("+BLU+"] "+NORM+ENV->QN+" leaves the game.\n");

  if(shade) 
    shade->shadow_healer_off();

  if(ENV->LVL < 20) 
    write_file("/players/khrell/healers/logs/EXP.TXT",ctime(time())+"  "+ENV->QN+"  "+ENV->EXP+"\n");
}



guild_leave() 
{
  int hh;
  
  hh = ENV->query_guild_rank();

  ENV->add_guild_rank(-hh);
  ENV->set_guild_name(0);
  ENV->set_guild_file(0);
  ENV->set_home("/room/church.c");
    
  save_object(MEM+"left/"+ENV->RN);
    
  rm("/"+MEM+ENV->RN+".o");

  ENV->add_xp(-(ENV->EXP)/6);

  if(shade) 
    shade->shadow_healer_off();
    
  command("save", ENV);

  tell_object(ENV,"You have left the Healers.\nGo in peace.\n");
  destruct(TO);
  return 1; 
}

add_mass(str) 
{
  int l;
  
  if(mass_heal_var[0] > lev) return 0;
  
  if(!str) 
  {
    write("Your Mass Heal Members: \n");
    for(l=0; l<sizeof(mass_p); l++) 
    {
      if(mass_p[l]) 
        write("  "+capitalize(mass_p[l]));
    }
    write("\n");
    return 1; 
  }
  while(l < sizeof(mass_p)) 
  {
    if(!mass_p[l]) 
    { 
      mass_p[l] = lower_case(str); 
      l = 100; 
    }
    
    else l++;
  }

  if(l != 100) 
  { 
    write("Your capacity for Mass Heal is at max.\n"); 
    return 1; 
  }
  
  write(str+" added to Mass Heal Members.\n");
  return 1; 
}

clear_mass(str) 
{
  int l;
  
  if(!str) 
  { 
    write("Clear who?\n"); 
    return 1; 
  }

  if(str == "all") 
  {
    for(l=0; l<sizeof(mass_p); l++) 
      mass_p[l] = 0;
   
    write("You have cleared your Mass Heal Members.\n");
    return 1; 
  }
  
  if((l = member_array(lower_case(str), mass_p)) == -1) 
  { 
    write("That being is not in the Member's List.\n"); 
    return 1; 
  }
  
  mass_p[l] = 0;
  write(str + " has been removed from the Mass Heal Members.\n");
  return 1; 
}


/********************NEED TO ADD TO POWER DIRECTORY**********************/

hhistory() { call_other(POWER,"history"); return 1; }
peace(str) { if(peace_var[0] > lev) return 0; call_other(POWER,"peace",lev,pow,str); return 1; }
heal(str) {
    string mwho;
    int mmuch;
    if(!str) { mwho=""; mmuch = 0; }
    if(str) if(sscanf(str,"%s %d",mwho,mmuch) != 2) { mwho = str; mmuch = 0; }
	/* 06/01/06 Earwax: laf, had to add this */
    if (mmuch < 0) {
	write("Nice try scrotumbreath.\n");
	mmuch *= -1;
    }
    if(heal_var[0] > lev) return 0;
    if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;    /* Added by Maledicta due to XLvl going to 100 now */
    if(pww == 0) pww = pow;
    if(query_verb() == "hp" || query_verb() == "sp") {
	call_other(POWER,"heal",lv,pww,mwho,query_verb(),mmuch);
    } else call_other(POWER,"heal",lv,pww,mwho,"heal",mmuch);
    lv = lev; pww = 0;
    return 1; }
mass_heal(str) {
    string mtype;
    int mmuch;
    if(mass_heal_var[0] > lev) return 0;
    if(!str) { mtype="heal"; mmuch = 0; }
    if(str) if(sscanf(str,"%s %d",mtype,mmuch) != 2) {
	    if(str == "hp" || str == "sp") { mtype = str; mmuch = 0; }
	    else { mtype = "heal"; sscanf(str,"%d",mmuch); }
	}
    if(pww == 0) pww = pow; if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;
    call_other(POWER,"mass_heal",lv,pww,mass_p,mtype,mmuch);
    pww = lv = 0;
    return 1; }
fortify(str) { if(fortify_var[0] > lev) return 0; call_other(POWER,"fortify",lev,pow,str); return 1; }
mystic_transfer(str) {
    string boo,hoo;
    if(mystic_transfer_var[0] > lev) return 0;
    if(!str) { write("mystic_transfer <who> <what>\n"); return 1; }
    sscanf(str,"%s %s",boo,hoo);
    call_other(POWER,"mystic_transfer",lev,pow,boo,hoo); return 1; }
cure(str) { if(cure_var[0] > lev) return 0; call_other(POWER,"cure",lev,pow,str); return 1; }
defend(str) {
    if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;
    if(defend_var[0] > lev) return 0;
    call_other(POWER,"defend",lv,pow,str);
    lv = 0;
    return 1;
}
/* Changed for a cap on level - Maledicta */
shield(str) {
    if(lv == 0) lv = lev;
    if(lv > 40) lv = 40;
    if(shield_var[0] > lev) return 0;
    call_other(POWER,"shield",lv,pow,str);
    lv = 0;
    return 1;
}
reduce(str) { if(reduce_var[0] > lev) return 0; call_other(POWER,"reduce",lev,pow,str); return 1; }
resurrect(str) { if(resurrect_var[0] > lev) return 0; call_other(POWER,"resurrect",lev,pow,str); return 1; }
simulcrum(str) { if(simulcrum_var[0] > lev) return 0; call_other(POWER,"simulcrum",lev,pow,str); return 1; }
potion() { if(potion_var[0] > lev) return 0; call_other(POWER,"potion",lev,pow); return 1; }
reinstate(str) {
    string boo,hoo;
    if(reinstate_var[0] > lev) return 0;
    if(!str) { write("reinstate <who> <what>"); return 1;}
    sscanf(str,"%s %s",boo,hoo);
    call_other(POWER,"reinstate",lev,pow,boo,hoo); return 1; }
regenerate(str) { if(regenerate_var[0] > lev) return 0; call_other(POWER,"regenerate",lev,pow,str); return 1; }
haven() { if(haven_var[0] > lev) return 0; call_other(POWER,"haven",lev,pow); return 1; }
cove() { if(cove_var[0] > lev) return 0; call_other(POWER,"cove",lev,pow); return 1; }
grant(str) {
    string boo,hoo;
    if(grant_var[0] > lev) return 0;
    if(!str) { write("grant <who> <what>"); return 1;}
    sscanf(str,"%s %s",boo,hoo);
    call_other(POWER,"grant",lev,pow,boo,hoo); return 1; }
salve() { if(salve_var[0] > lev) return 0; call_other(POWER,"salve",lev,pow); return 1; }
healing_spring() { if(healing_spring_var[0] > lev) return 0; call_other(POWER,"healing_spring",lev,pow); return 1; }
robe_of_healing(str) { if(robe_of_healing_var[0] > lev) return 0; call_other(POWER,"robe_of_healing",lev,pow,str); return 1; }
holy_blessing(str) { if(holy_blessing_var[0] > lev) return 0; call_other(POWER,"holy_blessing",lev,pow,str); return 1; }
full_heal(str) { if(full_heal_var[0] > lev) return 0; call_other(POWER,"full_heal",lev,pow,str); return 1; }
bless(str) { if(bless_var[0] > lev) return 0; call_other(POWER,"bless",lev,pow,str); return 1; }

/*******************************END****************************/
