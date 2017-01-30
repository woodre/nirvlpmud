#define ETO environment(this_object())
#define SAVE "players/pestilence/closed/destroyer/members/"
#define tpn      ENV()->query_real_name()
#define qgxp USER->query_guild_exp()
#define COMBAT present("destroyer_ob",this_player())->query_combat()
#include "/players/pestilence/define.h"
int spell_delay;
string Grank;
/* guild Id */
#include "/players/pestilence/closed/destroyer/gobdir/id.h"
#include "/players/pestilence/closed/destroyer/gobdir/hb.h"
#include "/players/pestilence/closed/destroyer/gobdir/init.h"
#include "/players/pestilence/closed/destroyer/gobdir/action.h"
#include "/players/pestilence/closed/destroyer/gobdir/misc.h"
#include "/players/pestilence/closed/destroyer/gobdir/weapon.h"
#include "/players/pestilence/closed/destroyer/gobdir/gupdate.h"
#include "/players/pestilence/closed/destroyer/powers/dhelp.h"
#include "/players/pestilence/closed/destroyer/powers/guildwho.h"
#include "/players/pestilence/closed/destroyer/powers/pwho.h"
#include "/players/pestilence/closed/destroyer/powers/punch.h"
#include "/players/pestilence/closed/destroyer/powers/weaken.h"
#include "/players/pestilence/closed/destroyer/powers/death.h"
#include "/players/pestilence/closed/destroyer/powers/dtitle.h"
#include "/players/pestilence/closed/destroyer/powers/guildquit.h"
#include "/players/pestilence/closed/destroyer/powers/frenzy.h"
#include "/players/pestilence/closed/destroyer/powers/rage.h"
#include "/players/pestilence/closed/destroyer/powers/blindside.h"
#include "/players/pestilence/closed/destroyer/gobdir/bugreport.h"
#include "/players/pestilence/closed/destroyer/powers/disable.h"
#include "/players/pestilence/closed/destroyer/powers/hulk.h"
#include "/players/pestilence/closed/destroyer/powers/rush.h"
#include "/players/pestilence/closed/destroyer/powers/decorpse.h"
#include "/players/pestilence/closed/destroyer/powers/wield.h"
#include "/players/pestilence/closed/destroyer/powers/disarm.h"
#include "/players/pestilence/closed/destroyer/powers/study.h"
#include "/players/pestilence/closed/destroyer/powers/arm.h"
#include "/players/pestilence/closed/destroyer/powers/enemy.h"
#include "/players/pestilence/closed/destroyer/powers/settitle.h"
#include "/players/pestilence/closed/destroyer/powers/settitle2.h"
#include "/players/pestilence/closed/destroyer/powers/santa.h"




reset(arg) {
  if (arg) return 0;
/* all this can be done from init. That way it's done when a player
gets the object instead of when it's just floating about -Bp
call_out("test_stats",3);
call_out("raise_str",2);
call_out("raise_sta",5);
*/
/*
call_out("f_you",5);
call_out("f_youwiz",5);
Ld mud doesn't like castle driven preloads to have call-outs from reset.
You can do this by calling this function from init without the need of a 
call-out. -Bp
*/
set_heart_beat(1);
}

init_callout() {
if(ETO) {
while(remove_call_out("test_stats") != -1);
call_out("test_stats",3);
while(remove_call_out("raise_str") != -1);
call_out("raise_str",2);
while(remove_call_out("raise_sta") != -1);
call_out("raise_sta",5);
}}
query_auto_load() {
    return "/players/pestilence/closed/destroyer/gob.c:";
}

drop() {return 1;}

extra_look() {
 Grank = present("destroyer_ob",environment())->query_grank();
write(environment()->query_name()+" is the "+Grank+" in the "+HIW+">"+HIR+"A.o.P"+HIW+"<"+NORM+"\n");
}




/* Magic stat of 20 Drawback */
test_stats() {
if(ETO) {
  if(living(ETO)) {
if(environment(TO)->query_level() < 21) {
  if(USER->query_attrib("mag") > 15) {
 tell_object(environment(TO),HIR+"\nYour physical strength prevents you from having a magic higher than 15.\n"+NORM);
    USER->set_attrib("mag",15); 
    USER->save();
    call_out("test_stats",3);
    return 1;
 }
  else{
call_out("test_stats",3);
 }
}
}
}
}

test_str() {
if(ETO) {
  if(living(ETO)) {
if(environment(TO)->query_level() < 21) {
  if(USER->query_attrib("int") > 10) {
 tell_object(environment(TO),HIR+"\nDo to your physical strength you lack the means of having intelligence above 10.\n"+NORM);
    USER->set_attrib("int",10); 
    USER->save();
    call_out("test_str",3);
    return 1;
 }
  else{
call_out("test_str",3);
 }
}
}
}
}

f_you(){
if(ETO) {
  if(living(ETO)) {
  if(USER->query_real_name() == "grit") {
    USER->set_guild_name(0);
      USER->add_guild_exp(-USER->query_guild_exp());
    USER->set_guild_rank(0);
    USER->set_title(HIR+"is annoying and a loser. "+HIW+"("+HIK+"Annoyer of the Order"+HIW+")"+NORM+"");
    USER->set_home("/room/church");
    tell_object(environment(this_object()),
      ""+HIK+"You have annoyed this guild long enough.  You are no longer a  part of this guild."+NORM+".\n");
 move_object(USER, "/room/church.c");  
      destruct(this_object());
return 1; }
else
return 1;
}
}
}


raise_str()
{
    int guildrank, recommended_strength, strength;

    if(!ETO || !living(ETO)) return 0; 

    /* init our shit */
    guildrank = USER->query_guild_rank();
    strength = USER->query_attrib("str");

    /* if they don't have enough strength, we bail out. */
    if(strength < 30)
        return 0;

    /* now we do our checking */
    recommended_strength =  30 + guildrank / 2;
    
    /* if we are too weak, we get our bonus */
    if(strength < recommended_strength) 
    {
        tell_object(environment(TO), HIR+"\nYour dna has upgraded your strength.\n"+NORM);

        USER->set_attrib("str", recommended_strength);
        USER->save();
        return 1; 
    }


}

raise_sta()
{
    int grank, recommended_stamina, stamina;

    if(!ETO || !living(ETO)) return 0; 

    /* init our shit */
    grank = USER->query_guild_rank();
    stamina = USER->query_attrib("sta");

    /* if they don't have enough stamina, we bail out. */
    if(stamina < 30) 
        return 0;

    /* now we do our checking */
    recommended_stamina =  30 + grank / 2;
    
    /* if we are too weak, we get our bonus */
    if(stamina < recommended_stamina) 
    {
        tell_object(environment(TO), HIR+"\nYour dna has upgraded your stamina.\n"+NORM);

        USER->set_attrib("sta", recommended_stamina);
        USER->save();
        return 1; 
    }


}

f_youwiz()
{
    int manager, wizlevel;

    if(!ETO || !living(ETO)) return 0; 
 
    /* init our shit */
    manager = USER->query_real_name();
    wizlevel = USER->query_level();
    /* if they don't have enough strength, we bail out. */
    if(wizlevel < 20)
        return 0;

    /* now we do our checking */
    
    /* if we are too weak, we get our bonus */
    if(manager == "puppy" || manager == "pestilence" || manager == "linus"  || manager == "katya")
         return 0;
    if(wizlevel > 20 && wizlevel < 100)
    {
        tell_object(environment(TO), HIR+"\nYou don't have permisson for this guild object.\n"+NORM);
        destruct(this_object());
        return 1; 
    }

}
got_rid_of_you()
{
  if(!USER) return; /* added by illarion 6 Dec 2004 */
  USER->add_guild_exp(-(USER->query_guild_exp()));
  USER->set_guild_name(0);
 USER->add_exp(qgxp);
  USER->set_guild_rank(0);
  USER->save_me();
  USER->reset();
/*
  rm("/players/pestilence/closed/destroyer/members/"+USER->query_real_name()+".o");
*/
  write_file("/players/pestilence/closed/destroyer/log/restored", ctime(time())+" "+HIR+USER->query_real_name()+NORM+" [L "+USER->query_level()+"+"+USER->query_extra_level()+"] \n"+NORM);
/*
  tell_object(USER, "The AoP is closing down testing.  Thank you for your time and effort.\n");
  destruct(this_object());
*/
    return 1;
}
