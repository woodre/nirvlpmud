/*ver 5.0*/
#include "/players/mouzar/misc/color.h"
#include "/players/mouzar/closed/guild/include.h"
get(){return 1;}
drop(){return 1;}
int x,t;
id(str){return str=="tattoo" || str=="guild_object"||str=="riskadh-tattoo"||str=="tat";}
short() {return "A Riskadh Tattoo";}
long(){write("A black tattoo of a dragon with two katanas crossed in front of it.  It is\n"+
      "the mark of the Riskadh Order.  Type Help to get a list of commands.\n"); }
query_auto_load() {return "/players/mouzar/closed/guild/tattoo:"+danger+"#"+pamt;}
glvl() {
    if(TOBJ->query_real_name() == "mouzar") {return 500;}
    else
    if(TOBJ->query_real_name() == "scooter"){return 450;}
    else
    if(TOBJ->query_real_name() == "zakk"){return 400;}
    else
    if(TOBJ->query_real_name() == "grimm"){return 400;}
    else
    if(TOBJ->query_real_name() == "albian") {return 350;}
    else
    if(TOBJ->query_real_name() == "mizan"){return 300;}
    else
    if(TOBJ->query_real_name() == "chrystoval") {return 300; }
    else
    if(TOBJ->query_real_name() == "trish") {return 300; }
    else
    if(TOBJ->query_real_name() == "flaw"){return 300;}
    else
    if(TOBJ->query_real_name() == "moon"){return 300;}
    else
    if(TOBJ->query_real_name() == "dragnar") {return 269;}
    else
    if(TOBJ->query_level() >= 30){return 100;}
    else
	return TOBJ->query_guild_rank();
}
set_shield_flag(j){shield = j;}
query_shield_flag() {return shield;}
set_cloaker(ob){cloaker = ob;}
set_CLK(ob) {CLK=ob;}
query_CLK()  { return CLK; }
reset(arg) {
    if(!SHADOW && ME->query_guild_flag() != "drinker") {
	SHADOW=clone_object("/players/mouzar/closed/guild/tat_shadow");
	SHADOW->shadow_me(this_player(),1);
    }
    if(arg) return;
    set_light(1);
    vrmuf = 1;
    pamt = 10;
    danger = 20;
}
init() {
    add_action("CHECK"); add_xverb("");
    if(LVL>3) {
	add_action("do_history","oth");
	add_action("kdwho","kd");
	add_action("danger_set","danger");
	add_action("ANSI_set","ANSI");
	add_action("invisibility","vanish");
	add_action("coins","coins");
	add_action("disarm","disarm");
	add_action("banish","banish");
	add_action("vrw","vrw");
	add_action("vr","vr");
	add_action("inv","i");
	add_action("sharpen","sharpen");
	add_action("remote_sell","rsell");
	add_action("throw_sand","sand");
	add_action("cc","rt");
	add_action("ce","re");
	add_action("offer","offer");
	add_action("hre","hre");
	add_action("hrt","hrt");
	add_action("list_title","ltitle");
	add_action("guild_title","gtitle");
	add_action("muf","su");
	add_action("darken","darken");
	add_action("ewho","ewho");
	add_action("quit","quit");
	add_action("ot","ot");
	add_action("owho","owho");
	add_action("oe","oe");
	add_action("Rhelp","Help");
	add_action("Skills","Skills");
	add_action("Rnew","News");
	add_action("Rules","Rules");
	add_action("health_monitor","hm");
	add_action("health_monitor2","chm");
	add_action("sc","score");
	add_action("sc","sc");
	add_action("frenzy","fr");
	add_action("frenzy","frenzy");
	add_action("kick","rkick");
	add_action("kick","rk");
	add_action("track","track");
	add_action("hide","hide");
	add_action("check","check");
	add_action("break_bone","skedarh");
	add_action("break_bone","sk");
	add_action("gateway","gateway");
	add_action("gateway","gw");
	add_action("swap","swap");
	add_action("shield","defend");
	add_action("CLOAKER","cloaker");
	add_action("send","send");
	add_action("mind_blast","blast");
	add_action("mind_blast","bl");
	add_action("mind_blast","b");
	add_action("call_ancients","ancients");
	add_action("call_ancients","an");
	add_action("poison","poison");
	add_action("meditate","meditate");
	add_action("meditate","med");
	add_action("Rhelp2","Help2");
	add_action("newmark","addmark");
	add_action("tattoo","tattoo");
	add_action("detattoo","detattoo");
	add_action("demand","demand");
	add_action("presure_point","pressure");
	add_action("presure","amt");
	add_action("presure_point","pr");
    }
}
init_arg(str) {
    sscanf(str,"%d#%d",danger,pamt);
    if(ME->ANSI == 1)
	write(">><<\n>><<\t\tType "+YELLOW+""+BLINK+""+REV_BLUE+"News"+END+" to get the guild news\n>><<\n");
    else
	write(">><<\n>><<\t\tType News to get the guild news\n");
    write(">><<\t\tResistance is Futile. Assimulated, You will be!\n");
    write(">><<\t\t\t\tYoda of Borg\n");
    if(ME->query_invis() == 0 && LVL < 1000) {
	/*    
	    if(ME->ANSI == 1)
	      sayit(BLUE+"{>"+NWHITE+"Grand Master Riskadh"+BLUE+"<}: "+LIGHT_BLUE+""+RN+" has come down from the heavens.\n"+END);
	    else
	*/
	sayit("{>Grand Master Riskadh<}: "+RN+" has come down from the heavens.\n");
	say(RN+" comes down from the Heavens.\n");
    }
    ME->set_guild_name("Riskadh");
}
set_pamt(dam) { pamt = dam; }
set_damage(babble) { babble = danger; }
pamt() { return pamt; }
set_PK_flag(num) {PK_flag = num;}
query_PK_flag() {return PK_flag;}
SAY(str){ say(str); return 1;}
lessp(x) {
    if(SP<x) return 0;
    if(LVL>30) return;
    ME->add_spell_point(-x);
    return 1;
    ME->add_spell_point(-x);
    return 1;
}
query_medit() { return medit;}
danger_set(blah) {
    if(!blah){
	write("Your danger is set to "+danger+".\n");
	return 1;
    }
    if(!intp(blah)) sscanf(blah,"%d",blah);
    if(blah < 1) danger = 1;
    else danger = blah;
    write("You health monitor will turn red when you hp goes below "+blah+"\n");
    return 1;
}
meditate(str) {
    object mroom;
    if(glvl()<5) return 0;
    if(str) return;
    if(ME->query_guild_flag() == "putz") {
	write("Grand Master Riskadh tells you:  You MUST contact Mouzar to get this\n"+
	  "skills back cause it has been logged that you used an intoxicating heal\n"+
	  "which is against order rules.\n");
	return 1;
    }
    if(ME->query_attack()) {
	write("You can not focus on meditating when in a fight!\n");
	return 1;
    }
    if(medit==0) {
	if(!env(this_player())->first_object())
	    move_object(this_object(),ME);
	medit=1;
	if(CLK)
	    CLK->set_move(1);
	write("You start meditating.\n");
	say(RN+" goes into a deep meditation.\n");
	med_count=0;
	mroom = clone_object("/players/mouzar/closed/guild/mroom");
	mroom->set_owner(ME);
	move_object(mroom,env(ME));
	move_object(ME,mroom);
	call_out("do_meditate",1);
	return 1;
    }
    return;
}
track(str) {
    if(glvl()<2) return 0;
    if(!str) {
	if(track==1) {
	    track=0;
	    write("You stop tracking.\n");
	} else {
	    write("You were not tracking anybody.\n");
	    track=0;
	}
	return 1;
    }
    if(SP<15&&LVL<30) {
	write("You do not have the mental strength to do that.\n");
	return 1;
    }
    if(!pse) {
	write("That person's tracks are not here to track.\n");
	track=0;
	return 1;
    }
    trp=str;
    lessp(15);
    track=1;
    call_out("do_track",1);
    write("You are tracking "+CAP(trp)+".\n");
    return 1;
}

do_track() {
    if(env(find_living(trp))->query_id() == "meditation") {
	if(TOBJ->ANSI == 1)
	    write(YELLOW+""+(trp)+" has gone into meditation so you stop tracking.\n"+END);
	else
	    write(CAP(trp)+" has gone into meditation so you stop tracking.\n");
	return 1;
    }
    if(env(find_living(trp))->realm() == "NF") {
	if(TOBJ->ANSI == 1)
	    write(YELLOW+"You stop tracking "+CAP(trp)+"\n"+END);
	else
	    write("You stop tracking "+CAP(trp)+"\n");
	track = 0;
	return 1;
    }
    if(medit == 1) {
	if(TOBJ->ANSI == 1)
	    write(YELLOW+"You stop tracking "+CAP(trp)+"\n"+END);
	else
	    write("You stop tracking "+CAP(trp)+"\n");
	track = 0;
	return 1;
    }
    if(TOBJ->query_attack()) {
	if(TOBJ->ANSI == 1)
	    write(YELLOW+"You stop tracking "+CAP(trp)+"\n"+END);
	else
	    write("You stop tracking "+CAP(trp)+"\n");
	track = 0;
	return 1;
    }
    if(!find_living(trp)) {
	track=0;
	write("No one by that name to track.\n");
    } else {
	if(!present(trp, env(ME))) {
	    write("You track "+CAP(trp)+".\n");
	    move_object(ME,env(find_living(trp)));
	    command("look",ME);
	}
    }
    if(track==1) {
	call_out("do_track",2);
    }
    return 1;
}

do_meditate() {
    object out;
    if(medit==0) return;
    if(!interactive(ME) || ME->query_idle() > 1500) {
	medit = 0;
	med_count = 0;
	out=env(ME);
	move_object(ME,env(out));
	command("darken",ME);
	destruct(out);
	return 1;
    }
    if(ME->query_attack()){
	medit = 0;
	med_count=0;
	if(TOBJ->ANSI == 1)
	    write(RED+"You are attacked and snap out of meditation!\n"+END);
	else
	    write("You are attacked and snap out of meditation!\n");
	out = env(ME);
	move_object(ME,out);
	destruct(out);
	return 1;
    }
    med_count = med_count + 1;
    if(med_count>2) {
	if (TOBJ->query_hp() < TOBJ->query_mhp())
	    TOBJ->add_hit_point(1);
	if (TOBJ->query_sp() < TOBJ->query_msp())
	    TOBJ->add_spell_point(1);
    }
    if(medit==1) {
	call_out("do_meditate",1);
    }
}
CHECK(str) {
    object out;
    if(!str) return;
    if(medit==1&&(str=="med"||str=="meditate")) {
	medit=0;
	out = env(ME);
	move_object(ME,env(out));
	destruct(out);
	if(CLK)
	    CLK->set_move(0);
	write("You come out of meditation.\n");
	say(RN+" out of meditation.\n");
	return 1;
    }
    else
    if(str=="ewho") { ewho(); return 1;}
    else
    if(str=="sc"||str =="score") { sc(); return 1;}
    else
    if(str=="owho") { owho(); return 1;}
    else
    if(str=="who"||str=="finger") {return;}
    else
    if(medit==1) {
	write("You may not do that while in meditation!\n");
	return 1;
    }
}
query_muf(){return muf;}
query_guild_channel(){return vrmuf;}
muf(str) {
    if(str == "vr"){
	if(vrmuf==1) {
	    vrmuf=0;
	    write("vamp-riskadh channel is OFF\n");
	    return 1;
	}
	vrmuf=1;
	write("vamp-riskadh channel is ON\n");
	return 1;
    }
    if(muf==0) {
	muf=1;
	write("All guild channels are OFF\n");
	return 1;
    }
    muf=0;
    write("All guild channels are ON\n");
    return 1;
}

darken(str) {
    object ob;
    if(str) return;
    if(medit) return;
    if(shield_flag==1)
	ME->add_ac(-3);
    ob=clone_object("/players/mouzar/closed/guild/tattoo");
    ob->set_cloaker(cloaker);
    ob->set_danger(danger);
    ob->set_pamt(pamt);
    ob->set_CLK(CLK);
    if(gflag>time())
	ob->set_gflag(gflag);
    if(hm_flag == 1)
	ob->set_heart_beat(1);
    if(time()<invis_timer)
	ob->set_invis_timer(invis_timer);
    move_object(ob,ME);
    write("Your tattoo has been darkened.\n");
    destruct(this_object());
    return 1;
}

newmark(str) {
    string target;
    object fin;
    int r,new;
    if(glvl()<=11) return 0;
    if(!str) return;
    if(sscanf(str,"%s %d",target,r)!=2) return;
    fin = find_living(target);
    if(present("riskadh-tattoo",fin))
	fin->add_guild_rank(r);
    new = present("riskadh-tattoo",fin)->query_marks();
    tell_object(fin, RN+" has changed the marks on your tattoo.\n");
    write_file("/players/mouzar/closed/guild/log/marks",RN+" changed "+r+" marks on "+str+" Glvls.("+new+")\n");
    write("You have just changed "+str+"'s marks.\n");
    return 1;
}
sayit(str) {
    int x;
    object us;
    us=users();
    for(x=0;x<sizeof(us);x++)
	if(present("riskadh-tattoo",us[x])&&present("riskadh-tattoo",us[x])->query_muf()==0) {
	    tell_object(us[x],str);
	}
    return 1;
}
set_gflag(x) {
    gflag = x;
}
query_marks(){
    return glvl();
}
set_marks(str) {
    int x;
    x=glvl();
    ME->add_guild_rank(-x);
    ME->add_guild_rank(str);
    return 1;
}
heart_beat() {
    int exp,hp,maxhp,dhp,sp,maxsp,dsp,stuff,maxstuff,intox,maxintox,attack;
    object color;
    attack=TOBJ->query_attack();
    stuff=TOBJ->query_stuffed();
    intox=TOBJ->query_intoxication();
    hp=TOBJ->query_hp();
    sp=TOBJ->query_sp();
    maxstuff=TOBJ->query_level()*8;
    maxintox=TOBJ->qeury_level()+3;
    maxhp=TOBJ->query_mhp();
    maxsp=TOBJ->query_msp();
    exp=TOBJ->query_exp();
    if(hp<danger && TOBJ->ANSI == 1) color=RED;
    if(hp>danger && TOBJ->ANSI == 1) color=GREEN;
    if((sp!=lsp)||(hp!=lhp)) {
	lsp=sp;
	lhp=hp;
	if(TOBJ->ANSI == 1)
	    tell_object(TOBJ,color);
	tell_object(TOBJ,"HP{"+hp+"|"+maxhp+"}  SP{"+sp+"|"+maxsp+"}  EXP{"+exp+"}");
	if(stuff)
	    tell_object(TOBJ," Stuff{"+stuff+"|"+maxstuff+"}");
	if(intox)
	    tell_object(TOBJ," Inotx{"+intox+"|"+maxintox+"}");
	if(TOBJ->ANSI == 1)
	    tell_object(TOBJ,"\n"+END);
	else
	    tell_object(TOBJ,"\n");
    }
}

health_monitor() {
    if(hm_flag==1){
	hm_flag=0;
	write("Health Monitor OFF\n");
	set_heart_beat(0);
	return 1;
    }
    hm_flag=1;
    write("Health Monitor ON\n");
    set_heart_beat(1);
    return 1;
}
/*
invisibility() {
    if(TAT->glvl() <=7) return;
    if(time() < invis_timer) {
	write("You must calm down before using vanish again.\n");
	return 1;
    }
    if(ME->query_invis()) {
	VIS->cmd_vis();
	invis_flag = 0;
	return 1;
    }
    if(SP<50&&LVL<30) {
	write("You do not have the mental strenth to do that.\n");
	return 1;
    }
    write_file("/players/mouzar/closed/guild/log/invis",RN+" went invis\n");
    lessp(50);
    invis_flag = 1;
    INVIS->cmd_invis();
    call_out("check_invis",1);
    return 1;
}
*/
check_invis() {
    if(call_other(TOBJ,"query_npc","query_attacker") == 0 && TOBJ->query_attacker()) {
	ME->vis();
	invis_timer = time() + can_invis_again;
	return 1;
    }
    hb_count += 1;
    if(hb_count == 3 && TOBJ->query_invis()) {
	lessp(1);
	if(SP<1) {
	    TOBJ->set_invis(0);
	    return 1;
	}
	hb_count = 0;
    }
    if(invis_flag)
	call_out("check_invis",1);
    return 1;
}
sc(){
    write("\n");
    if(ME->query_pretitle())
	write(ME->query_pretitle()+" ");
    if(ME->query_prename())
	write(ME->query_prename()+" ");
    write(CAP(ME->query_real_name())); 
    write(" "+ME->query_title());
    write(" ("+ME->query_al_title()+") ");
    if(ME->query_session()) write(ME->query_session());
    if(ME->query_invis()) {
	if(ME->ANSI == 1)
	    write(LIGHT_BLUE+""+BLINK+" {"+ME->query_invis()+"}"+END);
	else
	    write(" {"+ME->query_invis()+"}");
    }
    write("\n");
    write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    write("Level       : "+ME->query_level());
    write("\t\tKills/Deaths: "+ME->query_number_killed()+"/"+ME->query_times_killed()+"\n");
    write("Experience  : "+ME->query_exp()+" \t\tPlatinum    : "+ME->query_platinum()+"\n");
    write("Kingdom     : "+ME->query_kingdom_name());
    if(strlen(ME->query_kingdom_name()) > 8) write("   \t");
    if(strlen(ME->query_kingdom_name()) < 8) write("\t\t");
    write("Gold        : "+ME->query_gold()+"\n");
    write("Race        : "+ME->query_race()+" \t\tElectrum    : "+ME->query_electrum()+"\n");
    write("Guild exp   : "+ME->query_guild_exp()+"  \t\tSilver      : "+ME->query_silver()+"\n");
    write("Guild Rank  : "+present("riskadh-tattoo", ME)->query_marks()+"     \t\tCopper      : "+ME->query_copper()+"\n");
    if(ME->ANSI == 1 && ME->query_hp() <= danger)
	write(RED+"Hit Points  : "+ME->query_hp()+"|"+ME->query_mhp()+"  \t\t"+END);
    else
	write("Hit Points  : "+ME->query_hp()+"|"+ME->query_mhp()+"  \t\t");
    write("Spell Points: "+ME->query_sp()+"|"+ME->query_msp()+"\n");
    ME->show_age();
    if(ME->query_hunter()){
	if(ME->ANSI)
	    write(RED+"You are hunted by "+ME->query_hunter()->query_name()+".\n"+END);
	else
	    write("You are hunted by "+ME->query_hunter()->query_name()+".\n");
    }
    if(ME->query_stuffed()>0){
	if(ME->ANSI == 1)
	    write(GREEN+"Stuffed:  "+ME->query_stuffed()+"|"+ME->query_level()*8+""+END);
	else
	    write("Stuffed:  "+ME->query_stuffed()+"|"+ME->query_level()*8);
    }
    if(ME->query_intoxication())
	write("\tIntoxicated:  "+ME->query_intoxication()+"|"+ME->query_level()+3);
    if(ME->query_intoxication() || ME->query_stuffed())
	write("\n");
    if(ME->query_wimpy()){
	if(ME->ANSI)
	    write(YELLOW+"Wimpy Mode!\n"+END);
	else
	    write("Wimpy Mode!\n"+END);
    }
    if(hm_flag)
	write("Health Monitor ON.\n");
    /*  
      if(gflag<time())
	write("Gateway ready.\t\t");
      else
	write("Gateway not ready.\t\t");
    */  
    write("Amt of Pressure: "+pamt+".\n");
    if(TAT->query_medit()){
	if(ME->ANSI == 1)
	    write(YELLOW+"You are Meditating.\n"+END);
	else
	    write("You are meditating.\n");
    }
    if(track){
	if(ME->ANSI == 1)
	    write(BLUE+"You are tracking "+CAP(trp)+".\n"+END);
	else
	    write("You are tracking "+CAP(trp)+".\n");
    }
    write("\nStr:\t"+ME->query_str()+"\t\tInt:\t"+ME->query_int()+"\t\tWis:\t"+ME->query_wis()+"\n");
    write("Con:\t"+ME->query_con()+"\t\tDex:\t"+ME->query_dex()+"\n");
    return 1;
}
do_history() { MASTER->do_history(); return 1;}
kdwho() { MASTER->kdwho(); return 1;}
ANSI_set() { MASTER->ANSI_set(); return 1;}
coins() { MASTER->coins(); return 1;}
sharpen(str) { MASTER->sharpen(str); return 1;}
health_monitor2() { MASTER->health_monitor2(); return 1;}
disarm(str) { MASTER->disarm(str); return 1;}
nullspell(str) { MASTER->nullspell(str); return 1;}
remote_sell(str) { MASTER->remote_sell(str); return 1;}
throw_sand(str) { MASTER->throw_sand(str); return 1;}
cc(str) { MASTER->cc(str); return 1;}
ce(str) { MASTER->ce(str); return 1;}
offer(str) { MASTER->offer(str); return 1;}
hre(str) { MASTER->hre(str); return 1;}
hrt(str) { MASTER->hrt(str); return 1;}
list_title() { MASTER->list_title(); return 1;}
guild_title() { MASTER->guild_title(); return 1;}
ewho() { MASTER->ewho(); return 1;}
quit() { MASTER->quit(); return 0;}
ot(str) { MASTER->ot(str); return 1;}
owho() { MASTER->owho(); return 1;}
oe(str) { MASTER->oe(str); return 1;}
Rhelp2() { MASTER->Rhelp2(); return 1;}
Rhelp() { MASTER->Rhelp(); return 1;}
Skills() { MASTER->Skills(); return 1;}
Rnew() { MASTER->Rnew(); return 1;}
Rules() { MASTER->Rules(); return 1;}
frenzy(str) { MASTER->frenzy(str); return 1;}
kick(str) { MASTER->kick(str); return 1;}
hide() { MASTER->hide(); return 1;}
check(str) { MASTER->check(str); return 1;}
break_bone(str) { MASTER->break_bone(str); return 1;}
gateway() { MASTER->gateway(); return 1;}
swap(str) { MASTER->swap(str); return 1;}
shield() { MASTER->shield(); return 1;}
CLOAKER(str) { MASTER->CLOAKER(str); return 1;}
send(str) { MASTER->send(str); return 1;}
mind_blast(str) { MASTER->mind_blast(str); return 1;}
call_ancients() { MASTER->call_ancients(); return 1;}
poison(str) { MASTER->poison(str); return 1;}
tattoo(str) { MASTER->tattoo(str); return 1;}
detattoo(str) { MASTER->detattoo(str); return 1;}
presure_point(str) { MASTER->presure_point(str); return 1;}
presure(str) { MASTER->presure(str); return 1;}
vr(str) { MASTER->vr(str); return 1;}
vrw() { MASTER->vrw(); return 1;}
banish(str) { MASTER->banish(str); return 1;}
inv() { MASTER->inv(); return 1;}
set_delay(x) { t=x;}
query_delay() { return t;}
