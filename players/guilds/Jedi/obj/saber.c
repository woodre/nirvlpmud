inherit "obj/weapon.c";

#include <ansi.h>
#include "../defs.h"
#include "saber.h"

/******************************************************************************
 * Program: saber.c
 * Path: /players/guilds/Jedi/obj
 * Type: Weapon
 * Created: 1999 by Dragnar / Maledicta
 *
 * Purpose: The guild weapon for the Jedi. A very normal weapon unless the
 *          jedi attacks are used. The attacks if used correctly will add
 *          to the guild wc bonus. The attacks must be done in combinations
 *          in order to do decent damage. Also, the combos must be varied or 
 *          their damage will decrease to 0.
 *          If no attack is done, the weapon is reduced to max of wc 7.
 *    NOTE: Intoxication or causing sp to go negative will cause this weapon
 *          to miss every time. Low sp also can be deadly when using a 
 *          lightsaber. 
 * History:
 *          1999 - Dragnar
 *            Created
 *          09/04/2015 - Gnar
 *            Updated to remove .h files, and changed to wc_bonus instead of
 *            using old paladin code. Added secondary blade option.
 ******************************************************************************/

int    wep_life, ignited, bxp, modifier, combo_no, combo_index;
int    combo_status;
string wep_color, Color,wep_owner, modtype;
string* combo;
object ComboAtt;  /* Person combo hit was used on */

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


xp_bonus(){
  switch(XP) {
  case 13000000..9999999999:
  bxp = 12;
  break;
  case 9000000..12999999:
  bxp = 10;	
  break;
  case 6500000..8999999:
  bxp = 8;
  break;
  case 5000000..6499999:
  bxp = 6;
  break;
  case 3500000..4999999:
  bxp = 4;
  break;
  default:
  bxp = 0;
  break;
  }
}	

ignite_blade(string str){

  if(!str) { 
    write("ignite what?\n"); 
    return 1; 
  }
  if(!wep_life) { 
    write("It is out of power.\n");
    return 1; 
  }
  if(ignited) {
    if( !JEDI || JEDI->query_saber_type() != 1 ) {  
    write("It is already ignited!\n");
    return 1; 
    }
    if( ignited < 2 ) {
      ignited = 2;
      write("You ignite the second blade of your Lightsaber.\n");
      tell_room(environment(USER), USER->query_name()+ " ignites "+USER->query_possessive()+
                " lightsaber's secondary blade  with a..."+wep_color+"\n\n\
           -   -  --  --- ----  ------- SNAP HISS -------  ---- ---  --  -   -"+NORM+"\n\n\n");
      USER->RegisterWeapon(JEDI, ({ "physical", 17, "jedi_extra_hit" }));
      set_light(1);
      JEDI->SetSaber( SABER2, this_object() );
      return 1;
    }
  }
if(str == "lightsaber" ||
   str == "saber"){
  if(JEDI) {
    if(Rank > 7 && SKILL > 9) {
      set_class(17);
    }
    else if(Rank > 5 && SKILL > 5) {
      set_class(14);
    }
   else set_class(12);
  }
  else set_class(10);
  ignited = 1;
  if(!wielded) wield(str);
if(!JEDI){
tell_room(environment(USER),
""+USER->query_name()+" fumbles with the lightsaber and finally gets it to ignite.\n"); }	
else{
tell_room(environment(USER),
""+USER->query_name()+""+
" ignites "+USER->query_possessive()+" lightsaber with a...\n\n"+
""+wep_color+"           -   -  --  --- ----  ------- SNAP HISS -------  ---- ---  --  -   -"+NORM+"\n\n\n");
set_message_hit(({
  wep_color+"MASSACRED"+NORM," to "+wep_color+"smoking ruins"+NORM,
  wep_color+"s l i c e d"+NORM,"'s flesh from bone",
  wep_color+"mauled"+NORM,"",
  wep_color+"hit"+NORM," very hard",
  wep_color+"hit"+NORM," hard",
  "hit","",
  "grazed"," with a glancing blow"}));
  set_light(1);
  JEDI->SetSaber( SABER1, this_object() );
   return 1;
   }
  }
return 0;
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
  return str == "saber" || str == "lightsaber" || str == "jedi_saber"; }
	
query_short() {
  string temp;

  if( ignited > 1 )
    temp = "["+wep_color+"ignited"+NORM+"] A Lightsaber";
  else
    temp = "A Lightsaber";

  if( ignited )
    temp += " ["+wep_color+"ignited"+NORM+"]";
  if (this_player()->query_level() > 30)
    temp += " {ig:"+ignited+" nrg:"+wep_life+"}";
  return temp;
}

long() {
  write(long_desc);
  if(ignited) {
    write("The "+wep_color+"ignited blade"+NORM+" emits a deadly humming sound.\n");
  }
}

init() {
  ::init();
  add_action("ignite_blade", "ignite");
  add_action("shutdown_saber", "collapse");
  add_action("return_saber", "latch");
  add_action("shutdown_saber","unwield");
}

int weapon_hit(object ob) {
  if(!JEDI && !random(3) ){
    tell_object(USER, "Your lack of skill causes you to accidentally strike yourself!\n");
    USER->hit_player(random(50), "other|energy");
  }
  return 0;
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

shutdown_saber(string str){
  if(!ignited){ write("What?\n"); return 1; }	
  if(!str){ write("collapse what?\n"); return 1; }
  if(str == "lightsaber" || str == "saber"){
    if( ignited == 2 ) {
      tell_object( USER, "You close down the secondary blade of your saber.\n");
      say( USER->query_name()+" closes down the secondary blade on "+USER->query_poessive()+" Lightsaber.\n");
      ignited = 1;
      set_light(-1);
      /** Deregister weapon here **/
      USER->RemoveWeapon(JEDI );
      return 1;
    }
    if(wielded) ::stopwield();
    set_class(3);
    ignited = 0;
    this_object()->set_message_hit(({"massacre"," to small fragments","smashed",
                    " with a bone crushing sound","hit"," very hard","hit"," hard","hit","",
                    "grazed","","tickled"," in the stomach"}));
    set_light(-1);
    tell_object(USER,
      "You close down your lightsaber.\n");
    say(USER->query_name()+" closes down "+USER->query_possessive()+" lightsaber.\n");
    return 1;
  } 

write("no go.\n");
return 1;
}

return_saber(string str){
  if(!JEDI){ return 0; }	
  if(!str){ tell_object(USER, "Latch what?\n"); return 1; }
  if(!wep_life){ tell_object(USER,
     "It's lack of power makes it useless.\n");
     return 1; 
  }
  if(wielded || ignited)  command("collapse saber",USER);
  if(ignited || wielded){
    tell_object(USER,
    "You must collapse it first.\n");
    return 1; 
  }
   
  tell_object(USER,
    "You latch your lightsaber to your belt and hide it from sight.\n");  	  	     
  say(capitalize(this_player()->query_name())+" latches "+this_player()->query_possessive()+" lightsaber to "+this_player()->query_possessive()+" belt.\n");
  JEDI->set_wep_life(wep_life);
  JEDI->set_wep_color(Color);
  JEDI->save_stats();
  destruct(this_object());     
  return 1;
}	
/* Sets and query's used by lightsaber */

set_ignited(int i){ ignited = i; }
query_ignited(){ return ignited; }

adj_wep_life(int i) { wep_life += i; }
set_wep_life(int i){ wep_life = i; }
query_wep_life(){ return wep_life; }

query_wep_color(){ return wep_color; }

set_wep_color(string x){
  wep_color = LEV->QueryColor( x );
  Color = x;
}			

set_modtype(string str) { modtype = str; }
query_modtype() {
  tell_object( environment(), "\t\t\tquery_modtype\n");
  if(ATT && ComboAtt != ATT) return 0;
  tell_object(USER, HIB+"modtype: "+modtype+"\n"+NORM);
  return modtype;
}

set_modifier(int x) { modifier = x; }
query_modifier() { return modifier; }

int set_combo(string str) {
  int i;
  string ComboStr;

  /* This is not ideal, but faster than constantly resizing the array */
  combo_status = 1;
  if(!combo) {
    combo = ({ "null","null","null","null","null","null","null","null","null","null", });
    combo_index = 0;
  }
  combo[combo_index] = str;
  combo_index++;   /* point to the next index where we will insert */
  /* If we at at index 10, we need to start at the beginning again */
  if(combo_index > 9) combo_index = 0;

  for(i=0, combo_no=0; i < MAX; i++) 
  {
  	if(combo[i] == str) combo_no++;
  	/************ FOR TESTING ONLY ***************/
  	if(i == 0) ComboStr = combo[i];
  	else ComboStr += ":" + combo[i];
  	/*********************************************/
  }
  
  tell_object(USER, HIR+"combos: "+ComboStr+"\n"+NORM);
  if(combo_no > 2) return combo_no - 2;
  else return 0;
}

/** Needs to be moved to guild obj **/
proficiency_hit(ob){
  int temp;  /* so we can reset modifier when done */
  int i;
  int j;   /* counting vars */

  if(!JEDI || !SKILL) return 0;

  if(ignited) {
    if(ComboAtt && ComboAtt != ATT) ResetCombo();
    if(modifier) {
    	tell_object(USER, "modifier: "+modifier+".\n");
      temp = modifier;
      modifier = 0;
      if(ATT) ComboAtt = ATT;
      if(temp > 0) AddGxp(temp);
      return temp;
    }
    modtype = 0; /* Reset modtype since no attack was done */
		    
    if(combo) { 
    /* No attack was done, so go to the oldest attack and null it out */
	  if(combo_status == 1) {
        i = combo_index;
  	    j = 1;
        while(j < 11 && combo[i] == "null") {
          if(i == 9) i = 0;
          else i++;
          j++;
        }
  	 
  	  if(j > 10) combo_status = 0;
        else combo[i] = "null";
	  }
    }
  } 
  return 0;
}

ResetCombo() {
	tell_object(USER, "\tATTACKER CHANGED!!\n");
  combo = ({ "null","null","null","null","null","null","null","null","null","null", });
  combo_no = 0;
  combo_index = 0;
}

AddGxp(int amt) {
  if(ATT) USER->add_guild_exp(amt/10*ATT->query_level());
  return;
}
