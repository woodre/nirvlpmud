#include <ansi.h>
#include "defs.h"
/* Guild Officers / Office Abilities */
int elder, gwiz;
int suspend;
string reason;

/* Other */
int niggerrig, niggerrig2, niggerrig3, rainstormNum;
int count, pyro, woot, niggerrig4, activeRainstorm;
int sav;

/* Different bonds to strengthen abilities */
int earthbond, earthbond_expire, airbond, airbond_expire;
int firebond, firebond_expire, waterbond, waterbond_expire;

/* Level these abilities up */
int cshards, fdagger, lhammer, rainstormLevel;
int eprison, tsunami, shockwave, imirror;
int iceblast;

/* Element Levels */
int FIRE, WATER, AIR, EARTH;

/* Armor Variables */
static string *sh_armors;
string *armors;
static int arm_tot;
static int shaped;
static string shaped_form;

/* Djinns */
int has_djinn;

/* Spell Cooldowns */
int gskin, gskin_cooldown, gskinLength;          /* Granite Skin */
int airshroud, airshroudLength, airshroudCD;     /* Air Shroud   */
int rainstorm, rainstormLength, rainstormCD;                  /* Rainstorm    */
int imirrorCD, pyroblastCD, pyroblast, isprayCD;
int pbloodCD, lclapCD;

id(str) { return (str == "orb" || str == "elementalist orb" || str == "wicket_element_orb" || 
          str == "GI" || str == "no_pet" || str == "no_spell" || str == "pro_object" || str == "generic_wc_bonus" ||
          (str == "notweapon" && !previous_object()->is_elementalist_weapon()) ||
          (str == "notarmor" && !previous_object()->is_elem_armor()));
}


short()
{
	string all;
	int i, j, count;
	string woo;
	count = 0;
	woo = environment(this_object())->query_name()+"'s "+RED+"Ele"+YEL+"men"+GRN+"tal"+CYN+"ist"+NORM+" Orb\n";
	for(j = 0; j < 8; j++)
	{
		if(sh_armors[j]) count += 1;
	}
	if(count > 0) woo += BOLD+"Elemental Armors:\n"+NORM;
		for(i = 0; i < sizeof(sh_armors); i++){
			if(sh_armors[i]) woo += "	"+sh_armors[i]+"\n";
		}
		return woo;
}

long() {
	write(" An ancient orb that was forged and contains the four "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+"\n"+
		  "         "+GRN+"Earth"+NORM+", "+YEL+"Air"+NORM+", "+CYN+"Water"+NORM+", and "+RED+"Fire"+NORM+".\n"+
	      "Ancient powers can be felt flowing from the contents of the orb as it\n"+
	      "pulsates with energy. This orb is an ancient symbol of the "+BOLD+"Elders"+NORM+" of\n"+
	      "the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" passed down from the generations that this power has been\n"+
	      "in knowledge of existance.\n"+
	      "                 "+RED+"elehelp"+NORM+" - for more knowledge and assistance.\n");
}

get() {
   return 1;
}

drop() {
   return 1;
}

reset(arg){
	if(arg) return;
	armors = ({ "armor", "helmet", "boots", "chest", "cloak", "bracelet", "pants", "belt", "gloves" });
    if(!environment(this_object())) return 0; /* Rumplemintz */
}

/*guild_save()
{
       object ob;
       ob = environment(this_object());
       command("gsave", ob);
       call_out("guild_save", 1800);
       return 1;
}*/

init() {
	int c;
	string *spells, cmd;
	
	if(!environment()) return;
	if(this_player() && this_player()->is_npc()) return;
	restore_object(MEMPATH+environment(this_object())->query_real_name());
	if(environment(this_object())->query_level() < 1000){
		environment(this_object())->set_guild_name("Elementalist");
                environment(this_object())->set_guild_file(basename(this_object()));
    }
    
    /*if(environment(this_object())->query_real_name() == "thrall")
    {
	    tell_object(environment(), HIR+"YOU DISOBEYED MY WISHES AND NOW YOU ARE NOT ALLOWED IN THE GUILD.\n");
	    tell_object(environment(), HIR+"IF YOU WANT BACK IN, YOU CAN TEXT SHINSHI.\n"+NORM);
	    environment()->set_home(0);
	    environment()->set_guild_name(0);
	    environment()->set_guild_file(0);
	    destruct(this_object());
	    return 1;
    }*/
	
   if(!sh_armors) sh_armors = allocate(9);
   CHAND->add_channel(CHAN_NAME, environment());
	
   c = sizeof(spells = get_dir(SPELLPATH+"*.c"));
   while(c--)
   {
	   sscanf(spells[c], "%s.c", cmd);
	   add_action("cmd_hook", cmd);
   }
   	   add_action("g_save", "gsave");
   	   
	set_heart_beat(1);
	/*call_out("guild_save", 1800);*/
   	   
}

query_gmon1()
{
	string msg;
	
	msg = "";
	
	if(airbond)
	{
		msg += YEL+" AB "+NORM;
	}
	
	if(earthbond)
	{
		msg += GRN+" EB "+NORM;
	}
	
	if(firebond)
	{
		msg += RED+" FB "+NORM;
	}
	
	if(waterbond)
	{
		msg += CYN+" WB "+NORM;
	}
	
	if(airshroud)
	{
		msg+= HIY+"Airshroud"+NORM;
	}
	
	return msg;
}

gen_wc_bonus(){
	
	int air, earth, fire, water;
	int total;
	
	air = (int)this_object()->query_AIR();
	earth = (int)this_object()->query_EARTH();
	fire = (int)this_object()->query_FIRE();
	water = (int)this_object()->query_WATER();
	
	total = air + earth + fire + water;
	
	return (total / 4);
}

guild_login()
{
	CHAND->add_channel(CHAN_NAME, environment());
	
	write(RED);
	cat("/players/wicket/guild/login.txt");
	write(NORM);
	return 1;
}

mixed cmd_hook(string str)
{
	string go;
	
	go = SPELLPATH+query_verb()+".c";
	
	if(file_size(go) > 0)
		return (mixed) go->main(str, this_object(), this_player());
		return 0;
}

g_save()
{
	save_object(MEMPATH+environment()->query_real_name());
	tell_object(environment(), HIK+"Saving "+NORM+RED+"Ele"+YEL+"me"+GRN+"nt"+CYN+"al"+HIK+" Stats."+NORM+"\n");
	tell_object(environment(), HIK+"Save Complete."+NORM+"\n");
       return 1;
}

gsave()
{
	save_object(MEMPATH+environment()->query_real_name());
	return 1;
}

heart_beat()
{
	object ob, skin;
	int t;
	       
	if(!environment()) return;
	ob = environment(this_object());
	
	t = time();
	
	if(ob->query_ghost()){
		return;
	}
	
	if(ob->query_level() < 20 && sav++ >= 250)
	{
		g_save();
		sav = 0;
	}
	
	if(earthbond && t > earthbond_expire)
	{
		tell_object(ob, "\n\nThe spirit and strength of  "+HIG+"Aatami"+NORM+" leaves you.\n\n");
		earthbond = 0;
		earthbond_expire = 0;
	}
	
	if(airbond && t > airbond_expire)
	{
		tell_object(ob, "\n\nThe spirit and strength of "+HIY+"Aeolos"+NORM+" leaves you.\n\n");
		airbond = 0;
		airbond_expire = 0;
	}
	
	if(firebond && t > firebond_expire)
	{
		tell_object(ob, "\n\nThe spirit and strength of "+HIR+"Adroushan"+NORM+" leaves you.\n\n");
		firebond = 0;
		firebond_expire = 0;
	}
	
	if(waterbond && t > waterbond_expire)
	{
		tell_object(ob, "\n\nThe spirit and strength of "+HIB+"Glyndwr"+NORM+" leaves you.\n\n");
		waterbond = 0;
		waterbond_expire = 0;
	}
	
        /* Not needed.  Once gskinLegth wears off, you should be able to recast.  Fred [10.13.14]
	if(gskin && t > gskin_cooldown)
	{
		tell_object(ob, "\n\nYour skin goes back to normal and you can reuse Granite Skin.\n\n");
		gskin = 0;
		gskin_cooldown = 0;
	}
        */
         
	if(gskin && t > gskinLength && !niggerrig)
	{
		tell_object(ob, "\n\nYour skin softens back to normal and turns a strange purple color.\n\n");
		command("unwear wicket_ele_skin", environment());
		skin = present("wicket_ele_skin", environment());
		destruct(skin);
		gskin = 0;
                gskinLength = 0;
		niggerrig = 1;
	}
	
	if(airshroud && t > airshroudCD)
	{
		tell_object(ob, YEL+"\n\nAeolos "+NORM+"informs you that your "+YEL+"Airshroud"+NORM+" spell is ready.\n\n");
		airshroud = 0;
		airshroudCD = 0;
	}
	
	if(airshroud && t > airshroudLength && !niggerrig2)
	{
		tell_object(ob, YEL+"\n\nAeolos'"+NORM+" whipping winds around you slowly die.\n\n");
		airshroudLength = 0;
		niggerrig2 = 1;
	}
	
	if(ob->query_attrib("sta") > 20)
	{
		ob->set_attrib("sta", 20);
		tell_object(ob, "The "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" scorn you for your overage of stamina and take it from you!\n");
	}
	
	if(ob->query_attrib("str") > 20)
	{
		ob->set_attrib("str", 20);
		tell_object(ob, "The "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+NORM+" scorn you for your overage of strength and take it from you!\n");
	}
	
	if(rainstorm && rainstormLength)
	{
		ob->heal_self(rainstormNum);
		count++;
		tell_object(ob, "You feel the healing properties of the "+HIB+"Rainstorm"+NORM+".\n");
	}
	
	if(rainstorm && count > rainstormLength)
	{
		tell_object(ob, HIB+"\n\nGlyndwr recalls his Rainstorm!\n\n"+NORM);
		rainstormLength = 0;
		rainstormNum = 0;
		activeRainstorm = 0;
		count = 0;
	}
	
	if(rainstorm && (t > rainstormCD))
	{
		tell_object(ob, HIB+"\n\nGlyndwr"+NORM+" informs you that your "+HIB+"Rainstorm"+NORM+" spell is ready.\n\n");
		rainstorm = 0;
		rainstormCD = 0;
	}
	
	if(imirrorCD && t > imirrorCD)
	{
		tell_object(ob, HIB+"\n\nGlyndwr"+NORM+" informs you that your "+HIB+"Ice Mirror"+NORM+" spell is ready.\n");
		imirrorCD = 0;
	}
	
	if(pyroblast && !woot)
	{
		pyro++;
		tell_room(environment(ob), HIR+"\n\n"+ob->query_name()+"'s Pyroblast continues to grow in size and power!\n\n"+NORM);
		
		if(pyro > 5)
		{
			woot = 1;
			pyroblastCast();
		}
	}
	
	if(pyroblast && woot && (t > pyroblastCD))
	{
		tell_object(ob, HIR+"\n\nAdroushan"+NORM+" informs you that your "+HIR+"Pyroblast"+NORM+" spell is ready.\n");
		pyroblast = 0;
		pyroblastCD = 0;
		woot = 0;
		pyro = 0;
	}
	
	if(isprayCD && (t > isprayCD))
	{
		tell_object(ob, CYN+"Glyndwr"+NORM+" informs you that your "+CYN+"Ice Spray"+NORM+" spell is ready.\n");
		isprayCD = 0;
	}
	
	if(pbloodCD && (t > pbloodCD))
	{
		tell_object(ob, RED+"Adroushan"+NORM+" informs you that your "+HIR+"Purify Blood"+NORM+" spell is ready.\n");
		pbloodCD = 0;
	}
	
	if(lclapCD && (t > lclapCD))
	{
		tell_object(ob, YEL+"\n\nAeolos"+NORM+" informs you that your "+YEL+"Lightning Clap"+NORM+" spell is ready.\n\n");
		lclapCD = 0;
	}
	
	if(!ob->query_attacker())
	{
		ob->set_spell_dam(0);
	}
}

pyroblastCast()
{
	int damage;
	object attacker, test;
	
	damage = 45;
	attacker = environment()->query_attack();
	
	if(!attacker)
	{
		write("You aren't in combat with anyone.\n");
		return 1;
	}
	
	test = present("wicket_element_orb", environment());
	
	if(test->query_firebond())
	{
		damage *= 7;
		damage /= 3;
	}
	
	attacker->hit_player(damage, "other|fire");
	if(attacker)
	{
		tell_object(attacker, HIR+environment()->query_name()+" releases"+environment()->query_possessive()+" Pyroblast which directly hits you in the chest!\n"+NORM);
		tell_object(environment(), HIR+"You release your Pyroblast, directly hitting "+attacker->query_name()+" in the chest!\n"+NORM);
	}
}


armor_special(){
	int total;
	total = 0;
	
	/******* Shaped Armor - alternative to grafting your armors *******/
	if(arm_tot){
		if(!random(20) < arm_tot) tell_object(environment(), BOLD+"The "+NORM+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts"+BOLD+" begin to protect you, making you resist damage.\n"+NORM);
	}
	return arm_tot;
}




add_armors(str){
	int element;
	
	element = random(4);
	
	if(str == "chest"){
		if(element == 0)
		{
			sh_armors[0] = "Chestguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[0] = "Chestguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[0] = "Chestguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[0] = "Chestguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "armor"){
		if(element == 0)
		{
			sh_armors[1] = "Armorguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 5;
		}
		else if(element == 1)
		{
			sh_armors[1] = "Armorguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 5;
		}
		else if(element == 2)
		{
			sh_armors[1] = "Armorguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 5;
		}
		else if(element == 3)
		{
			sh_armors[1] = "Armorguard of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 5;
		}
	}
	
	if(str == "helmet"){
		if(element == 0)
		{
			sh_armors[2] = "Helmet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[2] = "Helmet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[2] = "Helmet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[2] = "Helmet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "boots"){
		if(element == 0)
		{
			sh_armors[3] = "Boots of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[3] = "Boots of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[3] = "Boots of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[3] = "Boots of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "cloak"){
		if(element == 0)
		{
			sh_armors[4] = "Cloak of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[4] = "Cloak of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[4] = "Cloak of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[4] = "Cloak of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "bracelet"){
		if(element == 0)
		{
			sh_armors[5] = "Bracelet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[5] = "Bracelet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[5] = "Bracelet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[5] = "Bracelet of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "pants"){
		if(element == 0)
		{
			sh_armors[6] = "Pants of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[6] = "Pants of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[6] = "Pants of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[6] = "Pants of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "belt"){
		if(element == 0)
		{
			sh_armors[7] = "Belt of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[7] = "Belt of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[7] = "Belt of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[7] = "Belt of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	
	if(str == "gloves"){
		if(element == 0)
		{
			sh_armors[8] = "Gloves of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+GRN+"Earth Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 1)
		{
			sh_armors[8] = "Gloves of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+RED+"Fire Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 2)
		{
			sh_armors[8] = "Gloves of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+CYN+"Water Formed"+NORM+")";
			arm_tot += 3;
		}
		else if(element == 3)
		{
			sh_armors[8] = "Gloves of the "+RED+"El"+YEL+"em"+GRN+"en"+CYN+"ts "+NORM+"("+YEL+"Air Formed"+NORM+")";
			arm_tot += 3;
		}
	}
	else
	{
		return 1;
	}
	return 1;
}

check_armors(string str){
object inv;
int x;
int woo;
inv = all_inventory(this_player());
   for(x = 0; x < sizeof(inv); x++){
     if(inv[x]->query_worn() && inv[x]->query_type() == str){
      return 1;
	   }	
     }
 
	if(str == "chest"){
		if(sh_armors[0]) return 1;
		return 0;
	}
        else if(str == "armor"){
		if(sh_armors[1]) return 1;
		return 0;
	}
	else if(str == "helmet"){
		if(sh_armors[2]) return 1;
		return 0;
	}
	else if(str == "boots"){
		if(sh_armors[3]) return 1;
		return 0;
	}
	else if(str == "cloak"){
		if(sh_armors[4]) return 1;
		return 0;
	}
	else if(str == "bracelet"){
		if(sh_armors[5]) return 1;
		return 0;
	}
	else if(str == "pants"){
		if(sh_armors[6]) return 1;
		return 0;
	}
        else if(str == "belt"){
		if(sh_armors[7]) return 1;
		return 0;
	}
        else if(str == "gloves"){
	        if(sh_armors[8]) return 1;
	        return 0;
        }
                return 0;
}

/* Armor Check */
query_sh_armors(){ return sh_armors; }
query_armors(){ return armors; }

/* Damage Modifiers */
query_earthbond(){ return earthbond; }
set_earthbond(int x){ earthbond = x; }
start_earthbond() {	earthbond_expire = time() + (10 * 60); }
query_airbond(){ return airbond; }
set_airbond(int x){ airbond = x; }
start_airbond() { airbond_expire = time() + (10 * 60); }
query_firebond(){ return firebond; }
set_firebond(int x){ firebond = x; }
start_firebond() { firebond_expire = time() + (10 * 60); }
query_waterbond(){ return waterbond; }
set_waterbond(int x){ waterbond = x; }
start_waterbond() { waterbond_expire = time() + (10 * 60); }

/* Ability Modifiers */
add_cshards(int x) { cshards += x; if(cshards > 495) cshards = 495; }
query_cshards() { return cshards; }
set_cshards(int x) { cshards = x; }

add_fdagger(int x) { fdagger += x; if(fdagger > 495) fdagger = 495; }
query_fdagger() { return fdagger; }
set_fdagger(int x) { fdagger = x; }

add_lhammer(int x) { lhammer += x; if(lhammer > 495) lhammer = 495; }
query_lhammer() { return lhammer; }
set_lhammer(int x) { lhammer = x; }

add_rainstormLevel(int x) { rainstormLevel += x; if(rainstormLevel > 495) rainstormLevel = 495; }
query_rainstormLevel() { return rainstormLevel; }
set_rainstormLevel(int x) { rainstormLevel = x; }
query_rainstorm() { return rainstorm; }
query_rainstormCD() { return rainstormCD; }

add_eprison(int x) { eprison += x; if(eprison > 495) eprison = 495; }
query_eprison() { return eprison; }
set_eprison(int x) { eprison = x; }

add_tsunami(int x) { tsunami += x; if(tsunami > 495) tsunami = 495; }
query_tsunami() { return tsunami; }
set_tsunami(int x) { tsunami = x; }

add_shockwave(int x) { shockwave += x; if(shockwave > 495) shockwave = 495; }
query_shockwave() { return shockwave; }
set_shockwave(int x) { shockwave = x; }

add_imirror(int x) { imirror += x; if(imirror > 495) imirror = 495; }
query_imirror() { return imirror; }
set_imirror(int x) { imirror = x; }

add_iceblast(int x) { iceblast += x; if(iceblast > 495) iceblast = 495; }
query_iceblast() { return iceblast; }
set_iceblast(int x) { iceblast = x; }

/* Level Elements */
query_FIRE() { return FIRE; }
add_FIRE(int x) { FIRE += x; }
query_EARTH() { return EARTH; }
add_EARTH(int x) { EARTH += x; }
query_AIR() { return AIR; }
add_AIR(int x) { AIR += x; }
query_WATER() { return WATER; }
add_WATER(int x) { WATER += x; }

/* Elder & Wizards */
add_elder(int x){ elder = x; }
query_elder() { return elder; }
set_gwiz(int x) { gwiz = x; }
query_gwiz() { return gwiz; }

/* Suspend */
set_suspend(int x) { suspend = x; }
query_suspend() { return suspend; }

/* Expel */
set_reason(string str) { reason = str; }

/* Djinns */
set_has_djinn(x){ has_djinn = x; }
query_has_djinn() { return has_djinn; }

/* Spell Cooldowns */
start_gskinCD() { gskin_cooldown = time() + (5 * 60); }
start_gskinLength() { gskinLength = time() + (10 * 60); }
query_gskin() { return gskin; }
set_gskin(int x) { gskin = x; }
set_niggerrig(int x) { niggerrig = x; }

start_airshroudCD() { airshroudCD = time() + (10 * 60); }
start_airshroudLength() { airshroudLength = time() + (5 * 60); }
query_airshroud() { return airshroud; }
set_airshroud(int x) { airshroud = x; }
set_niggerrig2(int x) { niggerrig2 = x; }

start_rainstormLength(int x) { rainstormLength = time() + x; }
start_rainstormCD() { rainstormCD = time() + (5 * 60); }
set_rainstorm(int x) { rainstorm = x; }
set_rainstormNum(int x) { rainstormNum = x; }
set_rainstormLength(int x) { rainstormLength = x; }
set_activeRainstorm(int x) { activeRainstorm = x; }
query_activeRainstorm() { return activeRainstorm; }
set_niggerrig3(int x) { niggerrig3 = x; }

start_imirrorCD() { imirrorCD = time() + (1 * 60); }
query_imirrorCD() { return imirrorCD; }

start_pyroblastCD() { pyroblastCD = time() + (3 * 60); }
set_pyroblast(int x) { pyroblast = x; }
set_pyro(int x) { pyro = x; }
query_pyroblastCD() { return pyroblastCD; }
query_pyroblast() { return pyroblast; }

start_isprayCD() { isprayCD = time() + (1 * 60); }
query_isprayCD() { return isprayCD; }

start_pbloodCD() { pbloodCD = time() + (5 * 60); }
query_pbloodCD() { return pbloodCD; }

start_lclapCD() { lclapCD = time() + (3 * 60); }
query_lclapCD() { return lclapCD; }

/* Yep I'm an Elementalist */
is_elementalist() { return 1; }
