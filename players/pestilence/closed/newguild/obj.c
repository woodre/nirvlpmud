#define ETO environment(this_object())
inherit "obj/armor";
#define SAVE "players/pestilence/closed/dark/members/"
#define tpn      ENV()->query_real_name()
#include "/players/pestilence/define.h"
/* guild Id */
#include "/players/pestilence/closed/newguild/id.h"

/* guild combat bonus */
#include "/players/pestilence/closed/dark/obj/weapon.h"

/* add actions  */
#include "/players/pestilence/closed/newguild/init.h"
#include "/players/pestilence/closed/dark/obj/action.h"

/* Some Guild set up and other various Misc */
#include "/players/pestilence/closed/dark/obj/misc.h"
#include "/players/pestilence/closed/dark/obj/hb.h"

/* Guild skills and spells and commands */
/* Common skills and spells at Guild Rank 1 */
#include "/players/pestilence/closed/dark/obj/settitle.h"
#include "/players/pestilence/closed/dark/obj/dhelp.h"
#include "/players/pestilence/closed/dark/obj/order.h"
#include "/players/pestilence/closed/dark/obj/bugreport.h"
#include "/players/pestilence/closed/dark/obj/align.h"
#include "/players/pestilence/closed/dark/obj/punch.h"

#include "/players/pestilence/closed/dark/obj/teleport.h"
#include "/players/pestilence/closed/dark/obj/slash.h"
#include "/players/pestilence/closed/dark/obj/ravage.h"
#include "/players/pestilence/closed/dark/obj/demon.h" 
#include "/players/pestilence/closed/dark/obj/darken.h"
#include "/players/pestilence/closed/dark/obj/decorpse.h"
#include "/players/pestilence/closed/dark/obj/torment.h"
#include "/players/pestilence/closed/dark/obj/distraught.h"
#include "/players/pestilence/closed/dark/obj/stun.h"
#include "/players/pestilence/closed/dark/obj/offwield.h"
#include "/players/pestilence/closed/dark/obj/fatal.h"
#include "/players/pestilence/closed/dark/obj/enrage.h""
#include "/players/pestilence/closed/dark/obj/wound.h"
#include "/players/pestilence/closed/dark/obj/dtitle.h"
#include "/players/pestilence/closed/dark/obj/inv.h"
#include "/players/pestilence/closed/dark/obj/invis.h"
#include "/players/pestilence/closed/dark/obj/dportal.h"



reset(arg) {
  if (arg) return 0;
call_out("align_hurt",3);
call_out("light_damage",3);
call_out("test_str",3);
call_out("test_stats",3);
call_out("f_you",5);
set_heart_beat(1);
   ::reset(arg);
   set_name("black coat");
   set_short("A long black overcoat");
   set_ac(6);
   set_type("armor"); 
   set_weight(1);
}

query_auto_load() {
    return "/players/pestilence/closed/dark/dark.c:";
}

drop() {return 1;}

/* Light hurts Draw back Thanks to Eurale*/
light_damage() {
int hurt;

if(!environment()) return 1;
if(!environment(environment()) || environment(environment())->no_light_damage()) return (call_out("light_damage", 6), 1);
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
    if(me->query_hp() < 19) kill_me(me);
*/
}
  }
call_out("light_damage",6);
return 1; }
}

/* Good alignment draw back Thanks to Eurale*/
align_hurt() {
if(ETO) {  /*  needed for startup  */
  if(living(ETO)) {
   if(USER->query_alignment() > 10) {
    tell_object(environment(this_object()),
      ""+HIK+"You feel pain from the goodness inside you"+NORM+".\n");
    if(interactive(ETO)) 
    ETO->hit_player(25 + random(20), "other|pestilence");
    call_out("align_hurt",random(30));
    return 1; }
  else {
    call_out("align_hurt",random(30));
 }
   }
}
}


/* Magic stat of 20 Drawback */
test_stats() {
if(ETO) {
  if(living(ETO)) {
  if(USER->query_attrib("mag") > 20) {
 tell_object(environment(TO),HIR+"\nThe ancients powers of Darkness rids you of your extra magic.\n"+NORM);
    USER->set_attrib("mag",20); 
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
test_str() {
if(ETO) {
  if(living(ETO)) {
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
f_you(){
if(ETO) {
  if(living(ETO)) {
  if(USER->query_real_name() == "grit") {
    USER->set_guild_name("none");
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

do_special(owner)
{

int z;
object ob; 
  z = random(20);
   if (z<5){
 environment()->add_hit_point(random(5));
/*
 environment()->add_spell_point(random(5));
*/
tell_room(environment(owner), "A rotten "+YEL+"stench"+NORM+" from the g-string covers "+environment()->query_name()+"'s body.\n");
return 8;
}
      return 0; 
   }
