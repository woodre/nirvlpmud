#include "defs.h"
#define ETO environment(this_object())
#include "/players/pestilence/define.h"
/* guild Id */
#include "/players/pestilence/closed/dark/obj/id.h"

/* guild combat bonus */
#include "/players/pestilence/closed/dark/obj/weapon.h"

/* add actions  */
#include "/players/pestilence/closed/dark/obj/init.h"
#include "/players/pestilence/closed/dark/obj/action.h"

/* Some Guild set up and other various Misc */
#include "/players/pestilence/closed/dark/obj/misc.h"

static int sav;


reset(arg) {
  cout = 0;
  if (arg) return 0;
set_heart_beat(1);
}

init_callout() {
if(ETO) {
}
}
#if 0
query_auto_load() {
    return "/players/pestilence/closed/dark/dark.c:";
}
#endif

drop() {return 1;}

heart_beat(){
  int str_bonus;
  object me, myenv;
  me = environment();
  if( !me )
    return;
  if(me->query_level() < 20 && sav++ >= 250) {
    save_me();
    sav = 0;
  }
   cout += 1;
if(cout >= 12) {
cout = 0;
}
switch(cout){
    case 0..1: return 0;
  break;
  case 2: light_damage();
  break;
  case 3: f_youwiz();
  break;
  case 4: align_hurt ( me );
  break;
  case 5: light_damage();
  break;
  case 6: light_damage();
  break;
  case 7: align_hurt( me );
  break;
  case 8: light_damage();
  break;
  case 9: test_stats();
  break;
  case 10: light_damage();
  break;
  case 11: light_damage();
  break;
}

if(query_spell_delay() && me->query_current_light() < -2) add_spell_delay(-1);

if( query_spell_delay() && me->query_prestige_level() )
  add_spell_delay(-1);

if(query_spell_delay()) add_spell_delay(-1);
    if(query_spell_delay() == 1) tell_object(USER,
      YEL+"You regain use of all your skills.\n"+NORM);
if(query_spell_delay() < 0) set_spell_delay(0);
  if(!me || !me->is_player()) return;
  myenv = environment(me);
  if(!myenv) return;
/*
  if(me->query_attack() && me->query_alignment() < 200) d_attack();
*/
if(me->query_attack()) d_attack();

  if(me->query_level() < 21 &&  !me->query_attack() && !random(8)) s_mess();
  return 1;
  }

d_attack(){
 object target, me, targetn;
   object wepp;
  int w, p, z, dex, wepwc, str_bonus;
 string mess, color;
 me = environment();
 target = me->query_attack();
 targetn = target->query_name();
  w = random(10);
 p = random(50);
 z = random(6);
  str_bonus = query_combat();
  switch(p){
   case 0..2: mess = ""+me->query_name()+" strikes terror through "+capitalize(targetn)+"."; break;
   case 3..4: mess = "\n\t\t"+HIK+"D A R K N E S S"+NORM+"\nErupts from the ground engulfing "+HIY+capitalize(targetn)+NORM+" in\n\t\t"+HIR+"  F L A M E S"+NORM+".\n"; break;
   case 5..6: mess = "\n\t"+RED+"C H A O S"+NORM+" rips through "+capitalize(targetn)+"'s soul.\n"; break;
   case 7: mess = "Evil erupts from "+me->query_name()+" leaving "+capitalize(targetn)+" in pain"; break;
   case 8: mess = capitalize(targetn)+" cowers before pure evil"; break;
   case 9: mess = "Darkness assists "+me->query_name()+"'s attack"; break;
   case 10: mess = ""+me->query_name()+" screams, You don't know my hate!"; break;
   case 11..13: mess = ""+HIR+"B L O O D"+NORM+" flows from "+capitalize(targetn); break;
   case 14..17: mess = ""+me->query_name()+ " fills "+capitalize(targetn)+"'s soul with HATE"; break;
   case 18..19: mess = ""+me->query_name()+ " urges "+capitalize(targetn)+" to KILL"; break; 
   case 20: mess = ""+me->query_name()+ " glares at "+capitalize(targetn)+", making them cower"; break;
   case 21..50: return;
   }
  switch(z){
   case 0: color = HIK; break;
   case 1: color = HIR; break;
   case 2: color = HIB; break;
   case 3: color = HIK; break;
   case 4: color = BLU; break;
   case 5: color = RED; break;
   }
 if(p > w){
/*
    USER->heal_self(-(random(10)));
  if(wepp = environment()->query_weapon()) wepp->hit(environment()->query_attack());
environment(this_object())->attack();
*/

tell_room(environment(environment(this_object())),color+"\t"+mess+"\n"+NORM);


   return 1;}
}

s_mess(){
 object target, me, targetn;
  int k, l, m;
 string mess, color;
 me = environment();
 k = random(21);
 l = random(250);
 m = random(6);
  switch(k){
   case 0..2: mess = "A voice whispers to you:  don't idle go "+HIR+"K I L L"; break;
   case 3..4: mess = "A voice whispers to you:  You must "+HIR+"D E S T R O Y"+NORM+" all in your way"; break;
   case 5..6: mess = "A voice whispers to you: You must FEED ME "+HIR+"BLOOD!"; break;
   case 7..9: mess = "A voice whispers to you: embrace your "+HIG+"H A T E!"; break;
   case 10: mess = "A voice whispers to you:  I need "+HIR+"B L O O D"; break;
   case 11..20: return;

   }

  switch(m){
   case 0: color = HIW; break;
   case 1: color = HIR; break;
   case 2: color = HIB; break;
   case 3: color = HIK; break;
   case 4: color = BLU; break;
   case 5: color = RED; break;
   }
 if(k > l){
 tell_object(USER, color+""+mess+"\n"+NORM);
   return 1;}
}

kill_me(ob) {
  object sand;
  sand=clone_object("/players/pestilence/closed/dark/mob/light.c");
  tell_object(ob, HIW+"\n\n\tTHE LIGHT TAKES YOUR LIFE!\n\n"+NORM);
  move_object(sand, environment(ob));
  ob->attacked_by(sand);
  ob->hit_player(100000, "other|snow");
  destruct(sand);
  return 1;
}
/* Good alignment draw back Thanks to Eurale*/
align_hurt( object me) {
  int gooddam;
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
   if(ETO->query_ghost()) 
     return 1;
   if(USER->query_alignment() > 300 && me->query_hp() > 40){
    tell_object(environment(this_object()),
      ""+HIK+"You feel pain from the goodness inside you"+NORM+".\n");
    if(interactive(ETO)) 
/*
    ETO->hit_player(25 + random(20), "other|pestilence");
*/
  gooddam = query_combat();
    ETO->hit_player(gooddam, "other|pestilence");
      if(me->query_hp() < 20) kill_mee(me);
    return 1; }
   }
}
}

kill_mee(ob) {
  object goodness;
  goodness=clone_object("/players/pestilence/closed/dark/mob/goodness.c");
  tell_object(ob, HIW+"\n\n\tYour GOODY GOODY GOODNESS TAKES YOUR LIFE!\n\n"+NORM);
  move_object(goodness, environment(ob));
  ob->attacked_by(goodness);
  ob->hit_player(100000, "other|pestilence");
  destruct(goodness);
  return 1;
}

/* Light hurts Draw back Thanks to Eurale*/
light_damage() {
int hurt;

  if( !environment()) return 1;

if( environment(TO)->query_ghost() ) return 1;

hurt = set_light(0);

if(environment(TO)->query_level() < 21) {

  if(hurt > 1)
  tell_object(environment(TO),
    HIK+"The light burns the darkness in your soul, causing extreme pain and discomfort...\n"+NORM);

if(hurt < -1 &&
  environment(TO)->query_mhp() != environment(TO)->query_hp())
    tell_object(environment(TO),
      HIK+"Darkness comforts your soul...\n"+NORM);
  if((environment(TO)->query_hp() - hurt) > 0) {
    if(hurt > 5) hurt = 5;
    if(hurt < -5) hurt = -5;
if(environment(TO)->query_interactive()){
    environment(TO)->add_hit_point(-hurt);
    environment(TO)->add_spell_point(-hurt);
/*
  environment(TO)->heal_self(-hurt);
*/
  /*
    if(me->query_hp() < 5 && !me->query_attack()  && me->query_ghost() == 0) kill_me(me);
*/
    if(environment(TO)->query_hp() < 5) kill_me(me);
}
  }
return 1; }
}


/* Magic stat of 20 Drawback */
test_stats() {
if(ETO) {
  if(living(ETO)) {
if(environment(TO)->query_level() < 21) {
  if(USER->query_attrib("mag") > 20) {
 tell_object(environment(TO),HIR+"\nThe ancients powers of Darkness rids you of your extra magic.\n"+NORM);
    USER->set_attrib("mag",20); 
    USER->save();
    return 1;
 }
  else{
 }
}
}
}
}

test_str() {
if(ETO) {
  if(living(ETO)) {
if(environment(TO)->query_level() < 21) {
  if(USER->query_attrib("str") > 19) {
 tell_object(environment(TO),HIR+"\nThe ancients powers of Darkness rids you of your strength.\n"+NORM);
    USER->set_attrib("str",19); 
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

f_youwiz()
{
    int manager, wizlevel;

    if(!ETO || !living(ETO)) return 0; 

    /* init our shit */
    manager = USER->query_real_name();
    wizlevel = USER->query_level();
    if(wizlevel < 20)
        return 0;

    /* now we do our checking */
    
   if(manager == "jareel" || manager == "pestilence" || manager == "wicket" || manager == "mosobp"  || manager == "forbin")
         return 0;
    if(wizlevel > 20 && wizlevel < 100)
    {
        tell_object(environment(TO), HIR+"\nYou don't have permisson for this guild object.\n"+NORM);
        destruct(this_object());
        return 1; 
    }


}

spelldelay() {
    int delay;
    delay = query_spell_delay();
   tell_object(environment(this_object()),HIW+delay+HIK+"spell delay"+NORM);
return 1;
}

unwield(string str) {
  object offwep, mygob;
command("offw",environment(this_object()));
 if(!str) {
    offwep = query_offwep();
    if(offwep) {
      offwep->stop_offwield();
       stop_offwield();
       stop_offwield();command("offw",environment(this_object()));
      write("You stop offwielding "+offwep->query_name()+" in your offhand.\n");
    return 1; 
  }
return 0;
}
}
