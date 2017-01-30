/* Mage guild weapon ... the Mage Staff
 * The player can create a list of spells that the staff will
 * cast automatically during combat.  Up to 5 spells can be
 * added to the list and the staff can either choose randomly
 * each time or go consecutivly.
 * The staff costs 250 spell points to create and can only be
 * gotten from within the Mages Tower (guild hall)
 *
 * The weapon itself is WC 16 with a return of random(Power)/10
 * Power is a guild stat that ranges from 0 to 100.
 * The max return is 9.
*/
inherit "obj/weapon";
#include "/players/pavlik/closed/colors.h"
#define tp this_player()
#define PAV "/players/pavlik/guild/mages/mage-master2.c"

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

/* Two variable used for casting order */
int XCON, SCON;

reset(arg) {
::reset(arg);
  if(arg) return;
  set_name(MAG+"Mage Staff"+NORM);
  set_short("the Mage Staff");
  set_long(
 "A long sleek staff of mystic Dragon Wood, the Mage's Staff is a\n"+
 "weapon born of sorcery and power.  The sculpted wood is covered \n"+
 "with powerful runes and magic devices.  Only one disciplined in the\n"+
 "art of Magic may wield it.  Type 'staff help' for commands.\n");
  set_type("staff");
  set_alias("staff");
  set_class(16);
  set_weight(3);
  set_value(0);
  set_hit_func(this_object());
  set_save_flag(1);
  count = -1;
  frequency = 3;
  autocast = 1;
  owner = "NOONE";
  order = "random";
  set_params("magical", 15, 0);
  set_message_hit(({
    HIM+"MASSACRED"+NORM, " to "+MAG+"small fragments"+NORM,
    HIM+"Smashed"+NORM, " with a "+MAG+"bone crushing"+NORM+" sound",
    HIM+"Hit"+NORM, " "+MAG+"very hard"+NORM,
    HIM+"Hit"+NORM, " "+MAG+"hard"+NORM,
    MAG+"Hit"+NORM, "",
    NORM+"grazed"+NORM, "",
    NORM+"tapped"+NORM, "",
 }));

  spell_list = allocate(6);


  XCON = 0;  SCON = 0;
}

id(str){
  return ::id(str) || str=="mage_staff" || str == "mage staff" ||
  str == owner+"'s staff" || str == owner+"'s mage staff";
}

short(){
  if(owner=="NOONE") short_desc=HIM+"A Mage Staff"+NORM;
  else short_desc=HIM+capitalize(owner)+"'s Mage Staff"+NORM;
  return ::short();
}

drop(){
  return 1;
}

long(){
  ::long();
 write(
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
query_a_spell(i){ return spell_list[i]; }

weapon_hit(attacker){
  int ranx, dmg;

  if(!attacker) return 0;
  dmg = random(present("mageobj", tp)->query_total_pow()) / 10;
  if(dmg > 9) dmg = 9;

  ranx = random(count+1);

  /* no spells/specials on other players */
  if(attacker->is_player()){
    PAV->staff_hit(attacker);
    return dmg;
  }

  /* if we can't cast another spell yet or out of SPs */
  if(present("mageobj", tp)->query_casting() || tp->query_sp() < 0){
    PAV->staff_hit(attacker);
    return dmg;
  }

  if(!autocast || count < 0) {
    PAV->staff_hit(attacker);
    return dmg;
  }

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
 if(environment()==tp && !present("mageobj", tp)){
   write("The staff flashes violently in your hands!\n");
   write("You drop the weapon.\n");
   say(capitalize(tp->query_name())+" drops a staff.\n");
   move_object(this_object(), environment());
   tp->add_weight(-3);
   return 1;
 }
 if(owner == "NOONE" && environment(this_object())->query_real_name())
 owner = environment(this_object())->query_real_name();
 add_action("staff_action","staff");
 add_action("mage_wield","wield");
}

mage_wield(){
  if(this_player()->query_real_name() != owner){
    write("The weapon turns into a whisp of smoke and disappears.\n");
    destruct(this_object());
    tp->add_weight(-3);
    return 1;
  }
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
      write("Casting frequency now set at: "+frequency+".\n");
      XCON = 0;
      return 1;
    }
  }
  else if(str == "list"){
    write("Your mage staff spell list:\n");
    for(i=0; i<=count; i++)
      write("  "+(i+1)+" "+spell_list[i]+"\n");
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


query_wear() { return 0; }
weapon_breaks() { return 1; }
