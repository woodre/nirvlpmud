/** Changes made by Maledicta on 4.23.01 on authority of Boltar
    Capped gain from levels at 40th
*/

#include "def.h"
#include "cost.h"
#define HOME_H "/"+root+"room/hall.c"
#define FLAGCOUNT 10
#define FLAGRND 7

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

id(str) {
    return str == "healerob" || str == "mythos_healer" ||
    str == "healer_staff" || str == "GI" ||
    str == "staff" || str == "no_spell"; }

drop () { return 1; } /* undroppable */
get() { return 0; }   /* ungettable */

reset(arg) {
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

long() { if(rc) write("A long white staff of stout oak.\n"+
	  "It is the tool of the Healer.\n"+
	  "hhelp will give you the help files.\n"); }

void guild_login(){    /* Rumplemintz */
    this_player()->set_guild_file(root+"guildob.c");
    this_player()->set_home(HOME_H);
    if((string)this_player()->query_guild_name() != "healer")
	this_player()->set_guild_name("healer");
}

init() {
    if(tp == ep) {
	/*
		if(!restore_object(MEM+tpn)) { destruct(TO); return 1; }
	*/
	if(!this_player()->query_guild_name("healer")){ destruct(this_object()); return; }
	if(!clr) {
	    shade = clone_object(root+"obj/shade.c");
	    shade->shadow_healer_on(tp);
	    clr = 1;
	    call_other(root+"obj/chandaem.c","add_channel",tp);
	    if(!tp->query_invis() && tp->query_level() < 60)
		call_other(root+"obj/chandaem.c","speak_channel", RED+"("+BLU+"] "+NORM+ep->query_name()+" "+enter_msg+"\n");

	}
       this_object()->set_rec();
       this_player()->set_guild_file(root+"guildob.c");
	add_action("hhelp","hhelp");
	add_action("lit","light");
	add_action("hhistory","hhistory");
#ifndef __LDMUD__
	add_action("chat"); add_xverb("ht");
	add_action("chat"); add_xverb("hht");
#else
	add_action("chat", "ht", 3);
	add_action("chat", "hht", 3);
#endif
	add_action("squit","quit");
	add_action("invis","invis");
	add_action("heal","chant");
	add_action("heal","heal");
	add_action("heal","hp");
	add_action("heal","sp");
	add_action("guild_leave","guild_leave");
	add_action("add_need","add_need");
	add_action("clear_need","clear_need");
	add_action("toggle_need_level","toggle_need_level");
	add_action("needmon","need_mon");
	add_action("list_need","list_need");
	add_action("monitoring","heal_mon");
	add_action("change_msg","change_msg");
	add_action("show_msg","show_msg");
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
	add_action("add_mass","add_mass_heal");
	add_action("add_mass","show_mass");
	add_action("clear_mass","clear_from_mass");
	add_action("full_heal","full_heal");
	add_action("need","need");
    }
}

set_rec() { rc = 1; }
query_rec() { return rc; }

show_msg() {
    write("Your entrance msg is: "+enter_msg+"\n");
    return 1; }

change_msg(str) {
    enter_msg = str;
    SOE;
    write("You have changed your message to: "+enter_msg+"\n");
    return 1; }

h_level() {
    string TITLE_H;
    string Tpart,Tpart2;
    int cexp, xxp,hhh,mss;
    int nss;
    if(epl < 20) {
	int h;
	xxp = ep->query_exp();
	cexp=call_other("room/adv_guild", "check_level", epl);
	if(xxp < cexp) call_other("room/adv_guild", "correct_level", ep);
	if (epxl) {
	    cexp=call_other("room/exlv_guild", "check_level", epxl);
	    if(xxp < cexp) call_other("room/exlv_guild", "correct_extra_level", ep);
	}
	if((hhh=ep->query_guild_rank()) != (epl + epxl)) ep->add_guild_rank((epl + epxl) - hhh);
	lev = epl + epxl;
	if(lev > 40) lev = 40;  /* Level maxed at 40 - Maledicta */
	TITLE_H = call_other(POWER,"titler",lev);
	if(ep->query_gender() == "female") {
	    if(sscanf(TITLE_H,"%sriest%s",Tpart,Tpart2) == 2) TITLE_H = Tpart + "riestess" + Tpart2;
	    if(sscanf(TITLE_H,"%sPatriarch%s",Tpart,Tpart2) == 2) TITLE_H = Tpart + "Matriarch" + Tpart2;
	}
	ep->set_title(TITLE_H);
	if(lev < 5) tell_object(ep,"You are a disgrace!\nGo back to your study and repent to gain what was lost!\n");
    } else lev = 40;
    pow = ep->query_attrib("pie");
    nss = 0;
    if(!need_mon) nss = 1;
    else if(sizeof(need_mon) != lev/5) nss = 1;
    if(nss) {
	tell_object(ep,"Need Monitor set to "+lev/5+" players.\n");
	need_mon = allocate(lev/5);
    }
    if(mass_heal_var[0] - 1 < lev) {
	mss = 0;
	if(!mass_p) mss = 1;
	else if(sizeof(mass_p) != lev/5) mss = 1;
	if(mss) {
	    tell_object(ep,"Resetting mass healing capacity.\nNow you may mass heal up to "+lev/5+" beings.\n");
	    mass_p = allocate(lev/5);
	}
    }
    return 1; }

heart_beat() {
    string monitor;
    if(!ep) { set_heart_beat(0); return 1; }
    h_level();
    if(!ep->query_attack() && mon_on) {
	monitor = " <<<<  HP"+ep->query_hp()+"/"+ep->query_mhp();
	monitor += " SP "+ep->query_sp()+"/"+ep->query_msp();
	monitor += " I "+(ep->query_intoxination()*100/(ep->query_max_intox()))+"%";
	monitor += " F "+(ep->query_stuffed()*100/(ep->query_max_stuff()))+"%";
	monitor += " S "+(ep->query_soaked()*100/(ep->query_max_soak()))+"%";
	monitor += "  >>>>\n";
	tell_object(ep,monitor);
    }
    if(need_on) need_monitor();
    if(ep->query_attack()) {
	flag_count = 0;
	if(!ep->query_combat_flag()) ep->set_combat_flag(1);
    } else {
	if(flag_count > FLAGCOUNT + random(FLAGRND)) {
	    ep->set_combat_flag(0);
	    flag_count = 0;
	} else flag_count++;
    }
    if(count > 10) { move_object(TO,ep); count = 0; } else count++;
}

toggle_need_level() {
    if(!reduced) {
	reduced = 1;
	write("Need Mon set to reduced mode.\n");
    } else {
	reduced = 0;
	write("Need Mon set to full mode.\n");
    }
    return 1;
}

need_monitor() {
    string NEEDMON;
    object needer;
    int j, nhp, nsp;
    int itx, f,s;
    int nip;
    if(reduced) NEEDMON = ""+HIM+"hp"+NORM+"/"+HIC+"sp"+NORM+"/t  ";
    else NEEDMON = ""+HIM+"hp"+NORM+"/"+HIC+"sp"+NORM+"/i/f/s/t  ";
    for(j=0;j<sizeof(need_mon);j++) {
	if(need_mon[j]) if(needer = present(need_mon[j],environment(ep))) if(needer->is_player()) {
		    if(needer) {
			nhp = needer->query_hp() * 10/needer->query_mhp();
			nsp = needer->query_sp() * 10/needer->query_msp();
			nip = needer->query_infuse() * 10/needer->query_infuse_limit();
			if(!reduced) f = needer->query_stuffed() * 10/ (needer->query_max_stuff());
			if(!reduced) itx = needer->query_intoxination()*10/(needer->query_max_intox());
			if(!reduced) s = needer->query_soaked()*10/(needer->query_max_soak());
			if(reduced) NEEDMON += need_mon[j]+" : "+HIM+""+nhp+""+NORM+"/"+HIC+""+nsp+""+NORM+"/"+nip+"  ";
			else NEEDMON += need_mon[j]+" : "+HIM+""+nhp+""+NORM+"/"+HIC+""+nsp+""+NORM+"/"+itx+"/"+f+"/"+s+"/"+nip+"  ";
		    }
		}
    }
    tell_object(ep,BLU+"  [] "+NORM+NEEDMON+"\n");
    return 1; }

list_need() {
    add_need();
    return 1; }

needmon() {
    if(need_on) { write("You turn off the Need Monitor.\n"); need_on = 0; return 1; }
    else { write("You turn on the Need Monitor.\nMax Need Slots: "+lev/5+"\n"); need_on = 1; return 1; }
}

monitoring() {
    if(mon_on) { write("You turn the heal monitor off\n"); mon_on = 0; return 1; }
    else { write("You turn on the heal monitor\n"); mon_on = 1; return 1; }
}

add_need(str) {
    int l;
    if(!str) {
	write("Your Need Monitor Members [max #:"+lev/5+"]: \n");
	for(l=0;l<sizeof(need_mon);l++) {
	    if(need_mon[l]) write("  "+capitalize(need_mon[l]));
	}
	write("\n");
	return 1; }
    while(l < sizeof(need_mon)) {
	if(!need_mon[l]) { need_mon[l] = lower_case(str); l = 100; }
	else l++;
    }
    if(l != 100) { write("Your capacity for Need Monitor is at max.\n"); return 1; }
    write(str+" added to Need Monitor Members.\n");
    return 1; }

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

chat(string moo) {
    string mee;
    string nam;
    if(!moo) moo = "";
    if(moo != "") {
	nam = tp->query_name();
	if(query_verb() == "hht") nam = capitalize(tp->query_real_name());
	if(sscanf(moo,"e %s",mee)) moo = RED+"("+BLU+"] "+NORM+nam + " " + mee;
	else if(sscanf(moo,"a %s",mee)) moo = RED+"("+BLU+"] "+NORM+mee + " <" + nam + ">";
	else moo = RED+"("+BLU+"] "+NORM+ nam +" intones:"+ moo;
	moo = format(moo,70);
    }
    call_other(root+"obj/chandaem.c","speak_channel",moo);
    return 1; }

squit() {
    SOE;
    /* Added so invis wizard can log off silently. -Feldegast 12-31-00 */
    if(!tp->query_invis() && tp->query_level() < 60)
	call_other(root+"obj/chandaem.c","speak_channel",
	  RED+"("+BLU+"] "+NORM+ep->query_name()+" leaves the game.\n");
    if(shade) shade->shadow_healer_off();
    if(ep->query_level() < 20) write_file("/players/guilds/healers/EXP.TXT",ctime(time())+"  "+epn+"  "+ep->query_exp()+"\n");
}

invis() {
    if(tl < 20) {
	if(tsp < 40) { write("You don't have enough energy.\n"); return 1; }
	tp->set_invs_sp();
	tp->add_spell_point(-40);
	write("You are now invisible.\n");
	return 1; }
}

guild_leave() {
#if 0 /* Rumplemintz - recoding this a bit */
    int hh,jj;
    jj=ep->query_guild_exp();
    call_other(ep,"add_guild_exp",jj);
    hh=ep->query_guild_rank();
    ep->add_guild_rank(-hh);
    ep->set_guild_name(0);
    ep->set_guild_file(0);
    ep->set_home("/room/church.c");
    save_object(MEM+"left/"+epn);
    rm("/"+MEM+epn+".o");
    ep->add_xp(-(ep->query_exp())/6);
    /* added by wocket 12-11-00 */
    if(shade) shade->shadow_healer_off();
    command("save",ep);
    /* end addition */
    tell_object(ep,"You have left the Healers.\nGo in peace.\n");
    destruct(TO);
    return 1; }
#else
  this_player()->set_guild_exp(0);
  this_player()->set_guild_rank(0);
  this_player()->set_guild_name(0);
  this_player()->set_guild_file(0);
  this_player()->set_home(0);
  save_object(MEM + "left/" + this_player()->query_real_name());
  rm("/" + MEM + this_player()->query_real_name() + ".o");
  this_player()->add_xp(-(this_player()->query_exp())/6);
  if (shade) shade->shadow_healer_off();
  this_player()->save_character();
  write("You have left the Healers.\nGo in peace.\n");
  destruct(this_object());
  return 1;
}
#endif

cast_out() {
    if(tl < 90) return 1;
    tell_object(ep,"You have been cast out of the Healers!\n");
    ep->add_xp(-3 * (ep->query_exp()/4));
    move_object(clone_object("/players/mythos/closed/play/save.c"),ep);
    tell_object(tp,"You have cast "+epn+" out of the Healers\n");
    guild_leave();
    return 1;}

lit() {
    if(lt) { set_light(-2); write("You dim the light of your staff.\n");
	say(tp->query_name()+" dims the light of the Staff of Healing.\n"); lt = 0; }
    else { set_light(2); write("You brighten the room with the light of your staff.\n");
	say("The room brightens as "+tp->query_name()+"'s staff glows.\n"); lt = 1; }
    return 1; }

add_mass(str) {
    int l;
    if(mass_heal_var[0] > lev) return 0;
    if(!str) {
	write("Your Mass Heal Members: \n");
	for(l=0;l<sizeof(mass_p);l++) {
	    if(mass_p[l]) write("  "+capitalize(mass_p[l]));
	}
	write("\n");
	return 1; }
    while(l < sizeof(mass_p)) {
	if(!mass_p[l]) { mass_p[l] = lower_case(str); l = 100; }
	else l++;
    }
    if(l != 100) { write("Your capacity for Mass Heal is at max.\n"); return 1; }
    write(str+" added to Mass Heal Members.\n");
    return 1; }

clear_mass(str) {
    int l;
    if(!str) { write("Clear who?\n"); return 1; }
    if(str == "all") {
	for(l=0;l<sizeof(mass_p);l++) mass_p[l] = 0;
	write("You have cleared your Mass Heal Members.\n");
	return 1; }
    if((l=member_array(lower_case(str),mass_p)) == -1) { write("That being is not in the Member's List.\n"); return 1; }
    mass_p[l] = 0;
    write(str + " has been removed from the Mass Heal Members.\n");
    return 1; }



add_lv(int a) { lv = lv + a; if(lv > 40) lv = 40; } /* Max of 40 - Maledicta */
set_pww(int a) { pww = a; }

/*    *******  Calls to POWER  ******     */

need(str) { call_other(POWER,"need",str); return 1; }
hhelp(str) { call_other(POWER,"help",str); return 1; }
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


