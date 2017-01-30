/* Healer Reboot by Shinshi 2016    >>> START AT 273 <<<*/

#include <ansi.h>
#include "defs.h"


/* Entrance Message */
string entry;

/* Need Monitor Variables */
int monitor, reduced;
static string *need_mon;
int mon_on;

/* Experience Stopper */
int exper;
static object shade;

/* Save Timer */
int sav;

/* Other variables */
int lev, lighting;

id(str) {
    return str == "healerob" || str == "new_healers" ||
    str == "healer_staff" || str == "GI" ||
    str == "staff" || str == "no_spell"; }

short() { return "Healer's Staff"; }

long() { write("A long white staff of stout oak.\n"+
	  "It is the tool of the Healer.\n"+
	  "hhelp will give you the help files.\n"); }

get() {
   return 1;
}

drop() {
   return 1;
}

reset(arg){
	if(arg) return;
    if(!environment(this_object())) return 0; /* Rumplemintz */
    
    exper = 0;
    need_mon = 0;
    
}

init() {
	int c;
	string *spells, cmd;
	
	if(!environment()) return;
	if(this_player() && this_player()->is_npc()) return;
	restore_object(MEMPATH+environment(this_object())->query_real_name());
	if(environment(this_object())->query_level() < 1000){
		environment(this_object())->set_guild_name("Healer");
                environment(this_object())->set_guild_file(basename(this_object()));
    }
    
    if(!exper)
    {
	    shade = clone_object(OBJECTPATH+"shade.c");
	    shade->shadow_healer_on(this_player());
	    exper = 1;
    }
    
    lev = (int)this_player()->query_level() + (int)this_player()->query_extra_level();
    
    if(lev > 50) lev = 50;		/* Max of 50 now. Up from 40 -Shinshi (10/10/15) */
    
    environment(this_object())->set_guild_rank(lev);
    
    need_mon = allocate(lev/5);
    
   CHAND->add_channel(CHAN_NAME, environment());
	
   c = sizeof(spells = files(SPELLPATH+"*.c"));
   while(c--)
   {
	   sscanf(spells[c], "%s.c", cmd);
	   add_action("cmd_hook", cmd);
   }
   	   add_action("h_save", "hsave");
   	   add_action("add_need", "add_need");
   	   add_action("clear_need", "clear_need");
   	   
	set_heart_beat(1);
   	   
}

mixed cmd_hook(string str)
{
	string go;
	
	go = SPELLPATH+query_verb()+".c";
	
	if(file_size(go) > 0)
		return (mixed) go->main(str, this_object(), this_player());
		return 0;
}

gen_sp_bonus()
{
	int bonus;
	
  	bonus = 0;
  	
  	if(environment(this_object())->query_prestige_level())
  	{
		bonus += (environment(this_object())->query_extra_level() * 3);
  	}
	return bonus;
}

h_save()  /* Non-silent save */
{
	save_object(MEMPATH+environment()->query_real_name());
	tell_object(environment(), "Saving Healer Stats...\n");
	return 1;
}

hsave()   /* Silent save */
{
	save_object(MEMPATH+environment()->query_real_name());
	return 1;
}


heart_beat() {
	object ob;
	string mon;
	
	if(!environment()) return;
	ob = environment(this_object());
	
	if(ob->query_level() < 20 && sav++ >= 250)
	{
		h_save();
		sav = 0;
	}
	
	if(monitor)
	{
		need_monitor();
	}
	
	if(!ob->query_attack() && mon_on) {
	mon = " <<<<  HP "+ob->query_hp()+"/"+ob->query_mhp();
	mon += " SP "+ob->query_sp()+"/"+ob->query_msp();
	mon += " I "+(ob->query_intoxination()*100/(ob->query_max_intox()))+"%";
	mon += " F "+(ob->query_stuffed()*100/(ob->query_max_stuff()))+"%";
	mon += " S "+(ob->query_soaked()*100/(ob->query_max_soak()))+"%";
	mon += "  >>>>\n";
	tell_object(ob, BOLD+mon+NORM);
    }
}

need_monitor() {
    string NEEDMON;
    object needer, me, atk;
    int j, nhp, nsp;
    int itx, f,s;
    int nip, atkmon;
    
    if(reduced) NEEDMON = ""+HIM+"hp"+NORM+"/"+HIC+"sp"+NORM+"/t  ";
    else NEEDMON = ""+HIM+"hp"+NORM+"/"+HIC+"sp"+NORM+"/i/f/s/t  ";
    for(j=0;j<sizeof(need_mon);j++) {
	if(need_mon[j]) if(needer = present(need_mon[j],environment(environment(this_object())))) if(needer->is_player()) {
		    if(needer) {
			nhp = needer->query_hp() * 10/needer->query_mhp();
			nsp = needer->query_sp() * 10/needer->query_msp();
			atk = needer->query_attack();
			nip = needer->query_infuse() * 10/needer->query_infuse_limit();
			if(!reduced) f = needer->query_stuffed() * 10/ (needer->query_max_stuff());
			if(!reduced) itx = needer->query_intoxination()*10/(needer->query_max_intox());
			if(!reduced) s = needer->query_soaked()*10/(needer->query_max_soak());
			if(reduced) NEEDMON += need_mon[j]+" : "+HIM+""+nhp+""+NORM+"/"+HIC+""+nsp+""+NORM+"/"+nip+"  \n";
			else NEEDMON += BLU+"  [] "+NORM+capitalize(need_mon[j])+" : "+HIM+""+nhp+""+NORM+"/"+HIC+""+nsp+""+NORM+"/"+itx+"/"+f+"/"+s+"/"+nip+"  ";
			if(atk)
			{
				atkmon = atk->query_hp() * 10/atk->query_mhp();
				NEEDMON += "AHP: "+atkmon;
			}
			}
		}
    }
    tell_object(environment(),BLU+"\   "+NORM+NEEDMON+"\n");
    return 1;
}

clear_need(str) {
    int l;
    if(!str) { write("Clear who?\n"); return 1; }
    if(str == "all") {
	for(l=0;l<sizeof(need_mon);l++) need_mon[l] = 0;
	write("You have cleared your Need Monitor Members.\n");
	return 1; }
    if((l=member_array(lower_case(str),need_mon)) == -1) { write("That person is not in your Need List.\n"); return 1; }
    need_mon[l] = 0;
    write(str + " has been removed from the Need Monitor Members.\n");
    return 1; }

add_need(str)
{
	int l;
	int x;
	
	l = 0;
	
	if(!str)
	{
		write("Your Need Monitor Members [max #:"+lev/5+"]: \n");
		for(l=0;l<sizeof(need_mon);l++)
		{
			if(need_mon[l]) write("  "+capitalize(need_mon[l]));
		}
		write("\n");
		return 1;
	}
	
	if(index(need_mon, str) > -1)
	{
		write("That person is already on your Need List.\n");
		return 1;
	}
	
	while(l < sizeof(need_mon))
	{
		if(!need_mon[l])
		{
			need_mon[l] = lower_case(str);
			write(capitalize(str)+" has been added to the Need Monitor.\n");
			l = 100;
		}
		
		else l++;
	}
	
	if(l != 100)
	{
		write("Your capacity for Need Monitor is at max.\n");
		return 1;
	}
	return 1;
}

needany(int a)
{
	string what;
	switch(a) {
		case 0: what = HIR+"ZERO*"+NORM; break;
		case 1: what = HIR+"ZERO*"+NORM; break;
		case 2: what = RED+"SOME "+NORM; break;
		case 3: what = RED+"SOME "+NORM; break;
		case 4: what = BLU+"HALF "+NORM; break;
		case 5: what = BLU+"HALF "+NORM; break;
		case 6: what = BLU+"HALF "+NORM; break;
		case 7: what = GRN+"ALOT "+NORM; break;
		case 8: what = GRN+"ALOT "+NORM; break;
		case 9: what = "FULL "; break;
		case 10: what = "FULL "; break;
		default : what = " NM "; break;
	}
	return what;
}

needDef(int a)
{
	string what;
	switch(a) {
		case -5:
		case -4:
		case -3:
		case -2:
		case -1:
		case 0:
		case 1: what = "WEAK"; break;
		case 2:
		case 3:
		case 4: what = "OKAY"; break;
		case 5:
		case 6:
		case 7: what = "BUFF"; break;
		default: what = "STRONG"; break;
		}
	return what;
}
    
    
/* Monitor Variables */
set_monitor(int x) { monitor = x; }
query_monitor() { return monitor; }
set_reduced(int x) { reduced = x; }
query_reduced() { return reduced; }
set_mon_on(int x) { mon_on = x; }
query_mon_on() { return mon_on; }

/* Entry Message */
set_msg(string str) { entry = str; }
query_msg() { return entry; }

/* Shade */
query_shade() { return exper; }

/* Level */
query_lev() { return lev; }

/* Light */
set_lighting(int x) { lighting = x; }
query_lighting() { return lighting; }