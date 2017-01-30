
inherit "obj/weapon.c";

int    wep_life, ignited, is_jedi, bxp, modifier, combo_no, combo_index;
int    combo_status;
string wep_color, Color,wep_owner, modtype;
string* combo;
object ComboAtt;  /* Person combo hit was used on */

#include <ansi.h>
#include "LS/defs.h"
#include "LS/sets.h"
#include "LS/shutdown.h"
#include "LS/return.h"
#include "LS/profic_hit.h"
#include "LS/ignite.h"

reset(arg){
  ::reset(arg);
  if (arg) return;
silentwield = 1;
set_name("lightsaber");
set_alt_name("jedi_saber");
set_alias("saber");

set_short("A Lightsaber");
set_long(
  "  The weapon of a Jedi, the lightsaber is an ancient tool of justice that\n"+
  "has aided the peacekeepers of the galaxy for ages. This one is made of a\n"+
  "shiney steel, its frame notched in thin deep circles to allow for a better\n"+
  "grip.  Midway down its length you find a trigger, which is used to ignite\n"+
  "its deadly blade. A small latch is on one end which is used to secure it to\n"+
  "a belt. The opposite end has a laser shielding cover and beam emitter.\n");

set_type("lightsaber");  
set_class(3);
set_weight(1);
set_value(1000);
set_hit_func(this_object());
set_wield_func(this_object());
}

wield(mixed x) {
  if (objectp(x)) {
    if(USER && !ignited)
      command("ignite saber",USER);
    return 1;
  }
  else return ::wield(x);
}

NoEnergy() {
  if(wielded) call_other(USER, "stop_wielding");
  set_class(3);
  command("wield saber",USER);
  set_light(-1);
  ignited = 0;
 tell_object(USER, "Your lightsaber runs out of energy.\n");
  tell_room(environment(USER), 
    USER->query_name()+"'s lightsaber runs out of energy.\n", ({USER,}));
}

id(str){
  return str == "pro_weapon" || str == "saber" || 
    str == "lightsaber" || str == "jedi_saber"; }
	
short() {
  string temp;

  if( ignited > 1 )
    temp = "["+wep_color+"ignited"+NORM+"] A Lightsaber";
  else
    temp = "A Lightsaber";
  if(WIELDED && !ignited){
    temp += " (wielded)";
  }
  else if(WIELDED && ignited){
    temp += " ["+wep_color+"ignited"+NORM+"] (wielded)";
  }
  else if(!WIELDED && ignited){
    temp += " ["+wep_color+"ignited"+NORM+"]";
  }
  if (call_other(this_player(), "query_level", 0) > 30)
    temp += "  < wc " + class_of_weapon + ","+eff_wc + " ig: "+ignited+">";
  return temp;
}

long() {
  write(long_desc);
  if(ignited) {
    write("The "+wep_color+"ignited blade"+NORM+" emits a deadly humming sound.\n");
  }
}

query_pro_weapon(){ return 1; }  /* Allows for use of paladin code in lib */

init(){
  ::init();
  add_action("ignite_blade", "ignite");
  add_action("shutdown_saber", "collapse");
  add_action("return_saber", "latch");
  add_action("shutdown_saber","unwield");
}

weapon_hit(attack){
  if(USER && USER->is_player() && JEDI && USER->query_spell_point() < 0 ) {
    tell_object(USER,
      "Your lack of connection to the force causes you to strike yourself with your Lightsaber.\n");
    set_modifier(-56);
    USER->hit_player(random(100));
    return;
  }
  if(!JEDI && (random(100) < 80)){
	tell_object(USER,
	"Your lack of skill causes you to accidentally strike yourself!\n");
	USER->hit_player(35);
  }
  tell_object(USER, "weapon_hit\n");
  return 5;
}    

set_short(sh) { short_desc = sh; }

query_wear(){ return 1; }

weapon_breaks() { return 1; }

fix_weapon() {
 write("You cannot fix a weapon like this.\n");
 write("Consult the libraries about creating a new LightSaber.\n");
 return 1;
 }

drop(){
if(ignited){	
shutdown_saber("saber"); }
::drop();
}
