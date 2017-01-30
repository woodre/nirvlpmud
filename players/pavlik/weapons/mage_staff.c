/* Mage's Guild weapon ...
 * Mage must quest and retrieve the Staff from Hzsade the dragon
 * The staff will automatically cast spells for the Mage
 * Weapon Class = 14 + mages weapon stat / 10 (max = 19)
*/
/* I have changed the mage_staff's wc to 13 + stat/10 to make the max 18
  since the weapon is savable and has no drawback .. the wc was changed
  - Mythos <4-1-96>
*/
/*
  And, back again.  Nice try Mythos.
 -Verte 2004.
*/
inherit "obj/weapon";
#include "/players/pavlik/closed/colors.h"
#define tp this_player()
#define PAV "/players/pavlik/mages/mage-master.c"

/* list of spells entered into the staff */
string spell_list;
/* owner of the staff */
string owner;
/* casting order, either sequetionally or random */
string order;
/* number of spells entered into the staff */
int count;
/* how often the staff casts a spell */
int frequency;
/* toggles the autocasting */
int autocast;
/* Weapon Class of staff = 14 + (mages weapon stat / 10) */
int weap;
/* Two variable used for casting order */
int XCON, SCON;

reset(arg) {
::reset(arg);
if(arg) return;
 set_name(MAG+"Mage Staff"+NORM);
 set_short("the Mage Staff");
 set_long("the Mage Staff.\n");
 set_alias("staff");
 set_class(14);
 set_weight(3);
 set_value(0);
 set_hit_func(this_object());
 count = -1;  frequency = 3;  autocast = 1;
 owner = "jomama";
 order = "random";
 spell_list = allocate(6);
 weap = 0;
 XCON = 0;  SCON = 0;
}

id(str){ return str == "staff" || str == "mage_staff" || str == "mage staff" ||
  str == owner+"'s staff" || str == owner+"'s mage staff"; }

short(){
 if(owner == "jomama") return HIM+"A Mage Staff"+NORM;
 if(wielded) return HIM+capitalize(owner)+"'s Mage Staff "+NORM+MAG+"(wielded)"+NORM;
 else return HIM+capitalize(owner)+"'s Mage Staff"+NORM;
}

drop(){
 if(query_verb()=="drop" || query_verb()=="quit" || query_verb()=="sell")
  return 1;
}

long(){
 write("\n"+
 "A long sleek staff of mystic Dragon Wood, the Mage's Staff is a\n"+
 "weapon born of sorcery and power.  The sculpted wood is covered \n"+
 "with powerful runes and magic devices.  Only one disciplined in the\n"+
 "art of Magic may wield it.  Type 'staff help' for commands.\n"+
 "~ Autocasting ");
 if(autocast) write("is on.\n"); else write("is off.\n");
 write("~ Casting Order: "+order);
 if(order == "random") write(".\n"); else write(" {"+SCON+"}\n");
 write("~ Casting Frequency: "+frequency+"\n");
 return;
}

query_count(){ return count; }
set_owner(str){ owner = str; }
query_owner(){ return owner; }
set_autocast(i){ autocast = i; }
query_autocast(){ return autocast; }
set_weap(i){ weap = i; }
query_weap(){ return weap; }
query_a_spell(i){ return spell_list[i]; }

weapon_hit(attacker){
 int ranx, dmg;
 dmg = random(weap/20);
 ranx = random(count+1);
 if(!attacker->query_npc()){ PAV->staff_hit(attacker); return dmg; }
 if(present("mageobj", tp)->query_casting()){ PAV->staff_hit(attacker); return dmg; }
 if(tp->query_sp() < -100){ PAV->staff_hit(attacker); return 1; }
 if(!autocast){ PAV->staff_hit(attacker); return dmg; }
 if(count < 0){ PAV->staff_hit(attacker); return dmg; }

 if(XCON == frequency){
   if(order == "random"){
    command(spell_list[ranx], tp);
   } else {
    command(spell_list[SCON], tp);
   }
   SCON++;
   if(SCON > count) SCON = 0;
   XCON = 0;
 } else {
   XCON++;
   PAV->staff_hit(attacker);
   return dmg;
 }
}

init(){
 ::init();
 if(environment(this_object())==tp && !present("mageobj", tp)){
  write("The staff flashes violently in your hands!\n");
  write("You drop the weapon.\n");
  say(capitalize(tp->query_name())+" drops a staff.\n");
  move_object(this_object(), environment(tp));
  return 1;
 }
 if(owner == "jomama" && environment(this_object())->query_real_name())
 owner = environment(this_object())->query_real_name();
 add_action("staff_action","staff");
 add_action("mage_wield","wield");
}

mage_wield(){
 if(this_player()->query_real_name() != owner){
  write("The weapon turns into a whisp of smoke and disappears.\n");
  destruct(this_object());
  return 1;
 }
 if(weap < 1) weap = present("mageobj", this_player())->query_weapons();
 this_object()->set_class(13 + weap/10);
}

staff_action(str){
  string what, what2;
  string spell, rest;
  int i, match;

  if(sscanf(str, "%s %s", what, what2)==2){
  if(what == "add"){
    if(count >= 5){
    write("The spell list is full.\n");
    return 1;
    }
  if(!present("mageobj", this_player())->knowit(what2)){
    write("You do not know any such spell.\n");
    return 1;
    }
  count++;
  write("You add the spell '"+what2+"' to the spell list.\n");
  write("There are "+(count+1)+" spells in the spell list.\n");
  spell_list[count] = what2;
  return 1;
  }
  if(what == "remove"){
    match = -1;
    for(i=0; i<6; i++){
      if(spell_list[i] == what2) match = i;
    }
  if(match == -1){
    write("The spell '"+what2+"' is not in the spell list.\n");
    return 1;
  }
  for(i=match; i<count; i++){
    spell_list[i] = spell_list[i + 1];
  }
  count--;
  write("The spell '"+what2+"' is removed from the spell list.\n");
  write("You have "+(count+1)+" spells entered.\n");
  return 1;
  }
 if(what == "autocast"){
    if(what2 == "off"){
    write("Autocasting off.\n");
    autocast = 0;
    } else {
    write("Autocasting on.\n");
    autocast = 1;
    }
  return 1;
  }
 if(what == "freq" || what == "frequency"){
  sscanf(what2, "%d", frequency);
  if(frequency < 1) frequency = 1;
  if(frequency > 5) frequency = 5;
  write("Casting frequency now set at: "+frequency+".\n");
 XCON = 0;
  return 1;
 }
  } else
  if(str == "list"){
  write("Your mage staff spell list:\n");
  for(i=0; i<=count; i++)
    write("  "+(i+1)+" "+spell_list[i]+"\n");
  return 1;
  }
  if(str == "drop"){
  write("You drop your mage staff.\n");
  say(capitalize(tp->query_name())+" drops a staff.\n");
  move_object(this_object(), environment(tp));
  return 1;
  }
  if(str == "storeable"){
  this_object()->set_wc(13);
  write("The staff is now storable.\n");
  return 1;
  }
  if(str == "clear"){
  write("Clearing Mage Staff ... ok.\n");
  write("There are 0 spells entered.\n");
  count = -1;
  for(i=0; i<6; i++) spell_list[i] = "0";
  return 1;
  }
  if(str == "order"){
  if(order == "random"){
   write("Casting order is now set to Consecutive.\n");
   order = "consecutive";
  } else {
   write("Casting order is now set to Random.\n");
   order = "random";
  }
 XCON = 0; SCON = 0;
  return 1;
  }
  if(str == "renew"){
  weap = present("mageobj", this_player())->query_weapons();
  this_object()->set_class(13 + weap/10);
  count = -1;
  rest = present("mageobj", this_player())->query_staff_spells();
  while(sscanf(rest, "%s#%s", spell, rest)==2){
    if(spell != "0"){
    count++;
    spell_list[count] = spell;
    }
  }
  if(rest != "0"){
    count++;
    spell_list[count] = rest;
  }
  write("You renew your Mage Staff.\n");
  write("There are "+(count+1)+" spells entered.\n");
  if(wielded){
   wielded = 0;
   command("wield mage_staff", this_player());
  }
  return 1;
  }
  if(str == "save"){
  rest = spell_list[0];
  for(i=1; i<6; i++)
    rest = rest +"#"+ spell_list[i];
  present("mageobj", this_player())->set_staff_spells(rest);
  write("Saving Mage Staff ... ok.\n");
  return 1;
  }
  if(str == "help"){
  PAV->staff_help();
  return 1;
  }
}
