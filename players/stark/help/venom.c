#include "defs.h"
#include "/players/maledicta/ansi.h"
#include "/players/maledicta/venom/obj/variables.h"
#include "/players/maledicta/venom/obj/id.h"
#include "/players/maledicta/venom/obj/reset.h"
#include "/players/maledicta/venom/obj/armor.h"
#include "/players/maledicta/venom/obj/weapon.h"
#include "/players/maledicta/venom/power/change.h"
#include "/players/maledicta/venom/obj/hb.h"
#include "/players/maledicta/venom/obj/settings.h"
#include "/players/maledicta/venom/obj/defense.h"
#include "/players/maledicta/venom/power/bite_spec.h"
#include "/players/maledicta/venom/power/absorb.h"
#include "/players/maledicta/venom/power/web_slam2.h"
#include "/players/maledicta/venom/power/newwho.h"
#include "/players/maledicta/venom/obj/guilddeath.h"
#include "/players/maledicta/venom/obj/clawstwo.h"
#include "/players/maledicta/venom/obj/bitetwo.h"
#include "/players/maledicta/venom/obj/slamtwo.h"
#include "/players/maledicta/venom/obj/kicktwo.h"
#include "/players/maledicta/venom/power/hypermode.h"
#include "/players/maledicta/venom/power/finisher.h"
#include "/players/maledicta/venom/power/web.h"
#include "/players/maledicta/venom/power/link_spells.h"
#include "/players/maledicta/venom/obj/_cackle.h"
#include "/players/maledicta/venom/obj/_glare.h"
#include "/players/maledicta/venom/obj/_grin.h"
#include "/players/maledicta/venom/obj/_laugh.h"
#include "/players/maledicta/venom/obj/_sneer.h"
#include "/players/maledicta/venom/obj/_lick.h"
#include "/players/maledicta/venom/obj/_chog.h"

query_auto_load(){
save_object(SAVE_PATH+NAME);
return "/players/maledicta/venom/venom.c:"; }


extra_look(){
string testlook;
if(this_player() != environment(this_object())){	
if(shaped && shapetype == "sword"){
return ""+HIW+"A symbiotic link to "+capitalize(symb_name)+""+NORM+"\n"+
       USER->query_name()+"'s arm has taken on the shape of a Sword";
}
else if(shaped && shapetype == "axe"){
return ""+HIW+"A symbiotic link to "+capitalize(symb_name)+""+NORM+"\n"+
       USER->query_name()+"'s arm has taken on the shape of an Axe";
}
else if(shaped && shapetype == "spear"){
return ""+HIW+"A symbiotic link to "+capitalize(symb_name)+""+NORM+"\n"+
       USER->query_name()+"'s arm has taken on the shape of a Spear";
}
else if(shaped && shapetype == "shield"){
return ""+HIW+"A symbiotic link to "+capitalize(symb_name)+""+NORM+"\n"+
       USER->query_name()+"'s arm has taken on the shape of a Shield";
}

else{
return ""+HIW+"A symbiotic link to "+capitalize(symb_name)+""+NORM+"";
 }
}
else{
return ""+HIW+"A symbiotic link to "+capitalize(symb_name)+" "+HIR+"["+mp+"]"+NORM+"";	
   }
}

long(){
write(
"  This is the link between you and the creature known\n"+
"as "+capitalize(symb_name)+". For mental instructions on how to use it\n"+
"type: "+HIR+"link_help"+NORM+".\n");
return;
}				

init_arg(str){ }

init(){
object symb_shad;

if(!environment()) return;
if(this_player()){
if(!this_player()->is_player()) return;
}
restore_object(SAVE_PATH+NAME);
if(USER->query_level() < 20){	
USER->set_guild_name(GUILDNAME);	
}
if(!shok){
symb_shad = clone_object("players/maledicta/venom/OBJ/symb_shadow.c");
symb_shad->shadow_symbon(this_player());   
shok = 1;
} 
if(USER->query_level() < 20)    
if(!symb_name) symb_name = "unnamed";
hb_count = 0;
old_exp = 0;
hyper_mode = 0;
venomed = 0;
defense_bonus = 0;
add_action("change_form", "changeform");
add_action("cmd_cackle", "cackle");
add_action("cmd_glare", "glare");
add_action("cmd_grin", "grin");
add_action("cmd_laugh", "laugh");
add_action("cmd_sneer", "sneer");
add_action("cmd_lick", "lick");
add_action("cmd_chog", "chog");
add_action("new_mon","mon");
add_action("absorb_corpse", "absorb");
add_action("bite_spell", "bite");
add_action("web_slam", "webslam");
add_action("new_emote", "emote");
add_action("new_score2", "score", 2);
add_action("tell_mp", "mp");
add_action("new_who", "threat");
add_action("hypermode", "hypermode");
add_action("web", "web");
add_action("store_coins","store_coins");
add_action("save_venom", "ssave");
add_action("quit_out", "quit");
add_action("link_help", "link_help");
add_action("leave_guild", "rip_out_symbiote");
add_action("link_spell", "link");
add_action("finish_spell","fatal");
add_action("new_say", "say");
add_action("new_say", "'");
add_action("new_say"); add_xverb("'");
if(USER->query_real_name() == "maledicta" || USER->query_real_name() == "maltest"){
add_action("renew_mp", "renew");
add_action("new_score2", "sc3");
}
add_action("supplant", "supplant");
add_action("pretitle_catch", "pretitle");

tell_object(USER,
"************************* SYMBIOTES *********************************\n"+
"Your guild hall is located at: church, s,4w,6n,u,2w,n, enter crack \n"+
"*********************************************************************\n\n");
tell_object(USER,
HIR+"\n\n\nWARNING: THE CLOCK TOWERS RING IS SONIC!! IT HURTS.\n"+
"ALSO, READ THE GUILD NEWS FOR UPDATES!\n\n\n"+NORM);

if(oldtitle){ 
USER->set_title(oldtitle);
oldtitle = 0;
      }
if(oldalign){
USER->set_al_title(oldalign);
oldalign = 0;
      }
if(oldpretitle){      
USER->set_pretitle(oldpretitle);
oldpretitle = 0;
      }
/*
call_other(this_player(), "wear_old", this_object());
*/
call_other(USER, "wear", this_object(), 1, "mine", ({"physical",0,0,"shield_bonus"}));
   
            
            set_type("mine");  
            set_ac(0);            
            worn_by = USER;
            worn = 1;
            set_class(0);
            message_hit=({
			""+HIR+"D E S T R O Y E D"+NORM+"", " with a frenzy of attacks",
				""+RED+"Mutilated"+NORM+"", "'s body into bloody ribbons", 
				""+HIW+"Destroyed"+NORM+"", " with an onslaught of blows",
				""+HIW+"Massacred"+NORM+""," into small fragments",
                ""+RED+"Slammed"+NORM+""," into the ground with bone shattering force",
				""+HIW+"Smashed"+NORM+""," with a bone crushing sound",
                ""+HIW+"Hit"+NORM+""," very hard",
                ""+HIW+"Hit"+NORM+""," hard",
                ""+HIW+"Hit"+NORM+"","",
				""+HIW+"Grazed"+NORM+"","",
                ""+HIW+"Tickled"+NORM+""," in the stomach",
			     });
            
}
/*****  New Damager for Sonic type attacks ****/
sonic_damager(int i){
if(i < 1) return 0;
if(i > 1000 && venomed){
tell_object(USER,
"The sonic damage is too much for your symbiote to withstand!\n");
command("changeform", USER);
return 1;
}
else if(i < 301 && venomed){
USER->hit_player(random(i));
USER->add_hit_point(-(random(i)));
mp -= random(i / 20);
}
return;
}
 

pklister(){
write("Player Kills:\n");
cat("/players/maledicta/venom/pks/"+USER->query_real_name()+"");
return 1;
}


new_mon(str){
if(!str){
this_player()->print_monitor();
if(regen){
tell_object(USER,
HIR+" [Regen "+NORM+"ON"+HIR+"]"+NORM+"");
}
if(burnoff){
tell_object(USER,
HIG+"  [Burnoff "+NORM+"ON"+HIG+"]"+NORM+"");
}
if(hyper_mode){
tell_object(USER,
HIB+"  [Hypermode "+NORM+"ON"+HIB+"]"+NORM+"");
}
tell_object(USER,
"\n");
return 1;
}
else{
 this_player()->cmd_monitor(str);
 return 1;
}
return 1;
}

store_coins(i){
int moneymoney;
if(file_name(environment(this_player())) != "players/maledicta/venom/symb_room"){
return 0;
}
if(!i){
write("store how many coins?\n");
return 1;
}
sscanf(i, "%d", moneymoney);
if(moneymoney < 1){
write("You cannot store that amount!\n");
return 1;
}
if(moneymoney > USER->query_money()){
write("You don't have that much!\n");
return 1;
}
USER->add_money(-(moneymoney));
stored_mon += moneymoney;
write("You drop "+moneymoney+" coins into the pool of dark matter.\n");
write("You now have "+stored_mon+" saved up.\n");
write_file("/players/maledicta/log/store_coins",
                NAME+" "+ctime(time())+"  "+moneymoney+" "+stored_mon+"\n");
save_venom();
return 1;
}
query_stored_coins(){ return stored_mon; }


new_score(){
USER->score();
USER->check_fight_area();
if(USER->query_fight_area()){
write(""+HIR+"PK Area"+NORM+"       ");
}
else{
write(""+HIB+"NON-PK Area"+NORM+"   ");
}
write("MP: "+BOLD+mp+NORM+"\n");
write("Stored Coins: "+stored_mon+"\n");
if(best_xp_score)
write("Best Kill (Name/Exp): "+best_xp_name+" / "+best_xp_score+"\n");
return 1;
}

new_score2(){
write(" Name: ");
if(USER->query_pretitle()) write(""+USER->query_pretitle()+" ");
write(""+capitalize(USER->query_name())+" ");
if(USER->query_title())write(""+USER->query_title()+" ");
write("("+USER->query_al_title()+")  [L: "+USER->query_level()+"");
if(USER->query_extra_level()){
  write("+"+USER->query_extra_level()+"]\n\n");
  }
else{
  write("]\n\n");
  }
write(
" Strength ["+USER->query_attrib("str")+"]\t\t\tIntelligence ["+USER->query_attrib("int")+"]\n"+
" Stamina  ["+USER->query_attrib("sta")+"]\t\t\tWillpower    ["+USER->query_attrib("wil")+"]\n"+
" Stealth  ["+USER->query_attrib("ste")+"]\t\t\tPiety        ["+USER->query_attrib("pie")+"]\n"+
" Luck     ["+USER->query_attrib("luc")+"]\t\t\tMagic        ["+USER->query_attrib("mag")+"]\n\n");
write(BLU+" HP"+NORM+" "+BOLD+"("+NORM+HIB+USER->query_hp()+NORM+BOLD+"/"+NORM+HIB+USER->query_mhp()+NORM+BOLD+")"+NORM+"\n");
write(RED+" SP"+NORM+BOLD+" ("+NORM+HIR+USER->query_sp()+NORM+BOLD+"/"+NORM+HIR+USER->query_msp()+NORM+BOLD+")"+NORM+"\n");
write(
" Food["+BOLD+USER->query_stuffed()*100/(USER->query_level()*8)+NORM+"%] "+
" Soak["+BOLD+USER->query_soaked()*100/(USER->query_level()*8)+NORM+"%] "+
" Intox["+BOLD+USER->query_intoxination()*100/(USER->query_level()+3)+NORM+"%]\n");
write(" ___________________________________________________\n");
write("Experience ["+USER->query_exp()+"]     Coins ["+USER->query_money()+"]  \n\n");
if(USER->query_quest_point())
write("QPS        ["+USER->query_quest_point()+"]\n");
write("\n");
USER->show_age();
write("\n");
USER->check_fight_area();
if(USER->query_fight_area()){
write(""+HIR+"PK Area"+NORM+"       ");
}
else{
write(""+HIB+"NON-PK Area"+NORM+"   ");
}
write("         MP: "+BOLD+mp+NORM+"\n");
write("Stored Coins: "+stored_mon+"\n");
if(best_xp_score)
write("Best Kill (Name/Exp): "+best_xp_name+" / "+best_xp_score+"\n");
return 1;
}


tell_mp(){
tell_object(USER,
"You currently have "+mp+" MP.\n");
return 1;
}


/******* Wizard test functions **********/
static renew_mp(){
tell_object(USER,
"You give yourself 300 mp.\n");	
mp += 300;
return 1;
}
/****************************************/

pretitle_catch(string str){
if(venomed){
  tell_object(USER,
  "You cannot change your pretitle while you are "+capitalize(symb_name)+"!\n");
  return 1;
  }		
return;
}
quit_out(){
if(USER->query_attack()){
write("You cannot quit out while in combat!\n");
return 1;
}
save_venom();
return;
}		

save_venom(){
	tell_object(USER,
	""+HIW+"Saving symbiotic link...."+NORM+"\n");
        save_object(SAVE_PATH+NAME);
        tell_object(USER,
        ""+HIR+"done."+NORM+"\n");
	return 1;
	}
restore_venom(){
        write("Restoring Symbiotic Link...\n");
	restore_object(SAVE_PATH+NAME);
	return 1;
         }

link_help(){
write(
" You commune with "+BOLD+""+capitalize(symb_name)+""+NORM+"....\n\n"+
" You are filled with knowledge of the following abilities:\n"+
" "+BOLD+"Power:           Level:"+NORM+"\n"+
" "+HIB+"absorb"+NORM+"             "+HIW+"-      - Absorb a corpse into your link giving it energy."+NORM+"\n"+
" "+HIB+"fatal"+NORM+"          "+HIW+"    -      - A fatal to finish your opponent."+NORM+"\n");
if(USER->query_level() > 4){
write(
" "+HIB+"changeform"+NORM+"         "+HIW+"5      - Allows you to become one with your symbiotic link."+NORM+"\n"+
" "+HIB+"link"+NORM+" "+BOLD+"<power>"+NORM+"       "+HIW+"5+     - Numerous powers that allow you to call on your\n"+
"                             symbiotic link for assistance. Use link alone to\n"+
"                             see a full listing."+NORM+"\n");
}
if(USER->query_level() > 6){
write(
" "+HIB+"webslam"+NORM+"            "+HIW+"7      - Momentarily capture a target and do some damage\n"+
"                             to them with a slam."+NORM+"\n");
}
if(USER->query_level() > 11){
write(
" "+HIB+"bite"+NORM+"              "+HIW+"12      - A series of damaging bites."+NORM+"\n");
}
if(USER->query_level() > 13){
write(	
" "+HIB+"web"+NORM+"               "+HIW+"14      - Will freeze a monster in place with a sticky web."+NORM+"\n");
}
if(USER->query_level() > 14){
write(
" "+HIB+"threat"+NORM+"            "+HIW+"15      - The threat list of current pkers on."+NORM+"\n"+
" "+HIB+"webslam <#>"+NORM+"       "+HIW+"15      - Same as the old, but use a number up to 40 in sps\n"+
"                             to increase its power."+NORM+"\n");
}
if(USER->query_extra_level() > 7){
write(
" "+HIB+"hypermode"+NORM+"         "+HIW+"19+8    - A frenzied series of dangerous attacks."+NORM+"\n");
}
write(
"      "+BOLD+"---------------------------------------------------"+NORM+"\n"+
" "+HIB+"supplant"+NORM+"                  "+HIW+"- Allows you to speak normally while changed."+NORM+"\n"+
" "+HIB+"ssave"+NORM+"                     "+HIW+"- Guild save."+NORM+"\n"+
" "+HIB+"rip_out_symbiote"+NORM+"          "+HIW+"- Will remove you from the guild with a great\n"+
"                             deal of pain involved."+NORM+"\n"+
" "+HIB+"mp"+NORM+"                        "+HIW+"- Will give current MP"+NORM+"\n");
return 1;
}

supplant(){
if(!venomed) return 1;
if(uncovered == 1){
 uncovered = 0;
 write(
  "You concentrate briefly and feel the symbiote regrow over your face.\n");
 say(
  "You watch as black ooze slowly grows back over "+NAME+"'s face.\n");
  return 1;
  }
else{
 uncovered = 1;
 write("You feel a tingling as the symbiote separates itself from around your head.\n");
 say(
 "The black ooze around "+symb_name+"'s head peels back to reveal "+NAME+".\n");
 return 1;
  }
return 1;
}
			
new_say(string str){
if(!str){
   write("Say what?\n");
   return 1;
   }		
if(venomed && !uncovered){
tell_object(USER,
""+HIW+"You hiss, '"+NORM+""+strsub(str, ({ "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are", "we am", "we are", "We am", "We are",
"myself", "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours", "Mine", "Ours",
 "we was", "we are", "We was", "We are"}), 3)+""+HIW+"'"+NORM+"\n\n");
tell_room(environment(USER),
""+BOLD+capitalize(symb_name)+" hisses, '"+NORM+""+strsub(str, ({ "s", "ss", "S", "Sss", "I", "We", "i", "we", "me", "us", "Me", "Us", "we'm", "we are", "We'm", "We are",
 "we am", "we are", "We am", "We are", "myself", "ourselves", "Myself", "Ourselves", "my", "our", "My", "Our", "mine", "ours", "Mine", "Ours",
 "we was", "we are", "We was", "We are"}), 3)+""+BOLD+BLK+"'"+NORM+"\n\n", ({USER}));	
return 1;
  }
if(venomed && uncovered){
if(USER->query_sp() < 5){
write("You don't have the energy to continue talking while supplanted.\n");
return 1;
}
USER->add_spell_point(-5);
return; }
return;
}	

new_emote(string str){
	if(!str){
		write("Emote what?\n");
		return 1;
	}
	if(venomed){
		tell_room(environment(USER),
			BOLD+capitalize(symb_name)+" "+str+NORM+"\n");
	return 1;
	}
    tell_room(environment(USER),
			USER->query_name()+" "+str+"\n");
    return 1;
}
	


leave_guild(){
if(venomed){
write("Change to normal before you leave the guild.\n");
return 1;
}
if(USER->query_level() > 19){
  tell_object(USER, "Dest this object, your a wiz.\n");
  return 1;
  }		
tell_object(USER,
"\n\nYou take hold of the symbiote and tear it from your spine!\n"+
"\n          YOU HEAR A MENTAL SCREAM TEAR INTO YOUR HEAD!!!\n"+
"A dark thick blood gushes outward and you feel yourself\n"+
"sink into dark oblivion.\n\n");
tell_object(USER,
"\n\n                      You feel very alone.....\n");
write_file("/players/maledicta/venom/logs/LEAVE", ctime(time())+
			"   "+HIR+USER->query_real_name()+NORM+" [L "+
			USER->query_level()+"+"+USER->query_extra_level()+"] \n"+NORM);
                  this_player()->destruct_this_shadow();
			rm("/players/maledicta/venom/member/"+USER->query_real_name()+".o");
			USER->set_guild_name(0);
                  
			if(USER->query_exp() > 5885) {
                           USER->add_exp(-(USER->query_exp() - 5885));
                           USER->set_level(5);
                           USER->set_extra_level(0);
                           }
                        USER->save_me();
                        USER->reset();
			destruct(this_object());

			return 1;	
			}


string
extra_short() { return ""; }
