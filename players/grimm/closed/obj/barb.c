#define THISFACTION "Dopple-Barbarian"
#include "/players/grimm/closed/obj/faction.h"
int absorb;
object abs_obj;
 
reset(arg) {
  if(arg) return;
  absorb = 0;
  HP_STORED = 0;
  MUFFLED = 0;
}/*  set_heart_beat(1);
}
 
 
heart_beat() {
}
*/
 
query_dopp_ow() { return "Barb"; }
 
query_pet_allow() {
  if(GLEVEL>11) return 1;
  return 0;
}
 
short() { 
  string stng;
  if(FINAL>time()) return 0;
  if(TP==THIS) stng = " ("+HP_STORED+" hp stored)";
  else stng = "";
  return "Scar of the Barbarian Faction"+stng; }
 
long() { 
  write("This is the scar of the barbarian's faction.\n"+
        "Only those who have proven themselves in battle may wear it.\n"+
        "Type \"bh\" or \"barbarian_help\" for more help.\n");
  if(HP_STORED)
    write("("+HP_STORED+" hit points stored)\n");
  return 1;
}
 
id(str) {
  return str == THISFACTION || str == "scar" || str == "Dopple-Faction";
}
 
init() {
  if(GLEVEL>9) {
    add_action("help_faction","bh");
    add_action("help_faction","barbarian_help");
    add_action("say_it_in_lingo","bsay");
    add_action("guild_who","barbarian_who");
    add_action("guild_who","bw");
    add_action("guild_tell","barbarian_tell");
    add_action("guild_tell","bt");
    add_action("guild_emote","barbarian_emote");
    add_action("guild_emote","be");
    add_action("generic_shaddup","barbarian_shaddup");
    add_action("generic_shaddup","bts");
    add_action("update","bupdate");
    add_action("coins_to_heal","cheal");
    add_action("nope","missile",2);
    add_action("nope","fireball",2);
    add_action("nope","shock",2);
    add_action("hack","hack");
  }
  if(GLEVEL>10) {
    add_action("hp_store","store");
    add_action("hp_retrieve","retrieve");
    add_action("tame","tame");
    add_action("scare","scare");
  }
  if(GLEVEL>11) {
    add_action("get_pet","wolf");
    add_action("reforge","reforge");
    add_action("first_aid","firstaid");
  }
  if(GLEVEL>12) {
    add_action("squeeze","squeeze");
    add_action("terminate","terminate");
    add_action("polish","polish");
  }
  if(GLEVEL>13) {
    add_action("forge","forge");
    add_action("peek","peek");
    add_action("aggress","aggress");
  }
  if(GLEVEL>14) {
    add_action("forgearmor","forgearmor");
    add_action("absorb","absorb");
    add_action("quake","quake");
  }
}
 
query_auto_load() {
  return "/players/grimm/closed/obj/barb:"; }
 
init_arg(str) {
}
 
help_faction() {
  cat("/players/grimm/closed/obj/badge_stuff/barb.help");
  return 1;
}
 
/* GLEVEL 10 commands */
guild_tell(str) {
  if(!str) {
    write("What do you want to tell them?\n");
    return 1;
  }
  tell_the_guilders(str,"{","}");
  return 1;
}
 
update() {
  object fact;
  fact = clone_object("/players/grimm/closed/obj/barb");
  fact->set_pet(pet);
  fact->set_hp_stored(HP_STORED);
  move_object(fact, TP);
  write("Faction Scar Restored.\n");
  destruct(TO);
  return 1;
}
 
hack(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Hack what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem((8+random(6)),10,what,"You hack at a "+cwhat,
        CN+" hacks away at a "+cwhat);
  return 1;
}
 
/* GLEVEL 12 commands */
get_pet(str) {
  if(!str) pet2("help","blah");
  pet2(str,"wolf");
  return 1;
}
 
reforge(str) {
  object ob;
  if(!str) {
    write("What do you want to reforge?\n");
    return 1;
  }
  if(SP<40) { NOSP; return 1; }
  if(!(ob=present(str,TP))) {
    write("You do not have one of those.\n");
    return 1;
  }
  if(!ob->weapon_class()) {
    write("That is not a weapon.\n");
    return 1;
  }
  if(!ob->query_broke()) {
    write("That is not broken.\n");
    return 1;
  }
  ob->fix_weapon();
  lessp(40);
  write("You reforge the weapon.\n");
  say(CN+" reforges a "+CAP(str)+".\n");
  return 1;
}
 
first_aid(str) {
  object per;
  if(!str) {
    write("Who do you want to apply first aid to?\n");
    return 1;
  }
  if(SP<30) { NOSP; return 1; }
  if(!(per=present(str,ENV_THIS))) {
    write("That player is not in the room with you.\n");
    return 1;
  }
  lessp(30);
  per->heal_self(25);
  write("You apply first-aid to "+CAP(str)+".\n");
  say(CN+" applies first-aid to "+CAP(str)+".\n");
  return 1;
}
 
/* GLEVEL 13 commands */
squeeze(str) {
  object ob;
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Squeeze what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  if(SP<20) { NOSP; return 1; }
  if(present(what,ENV_THIS))
    ob=present(what,ENV_THIS);
  else { write("That is not here.\n");
          return 1;
    }
  if(!ob->query_npc()) {
    write("That is not a monster.\n");
    return 1;
  }
  getem(10,20,what,"You squeeze the life out of a "+cwhat,
        CN+" squeezes the life out of a "+cwhat);
/* Um.. not sure why this is here... defeats the purpose...
  ob->set_hp(ob->query_hp());
*/
  return 1;
}
 
terminate(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Terminate what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem((15+random(30)),30,what,"You cast a termination spell at a "+cwhat,
        CN+" casts a termination spell at a "+cwhat);
  return 1;
}
 
polish(str) {
  int amt;
  object ob;
  if(!str) {
    write("Polish what?\n");
    return 1;
  }
  if(SP<15) { NOSP; return 1; }
  if(!(ob=present(str,TP))) {
    write("You do not have one of those.\n");
    return 1;
  }
  amt = ob->query_value();
  if(!amt) {
    write(CAP(str)+" has no value to begin with.\n");
    return 1;
  }
  amt /= 10;
  ob->set_value(ob->query_value()+amt);
  lessp(15);
  write("You polish a "+CAP(str)+".\n");
  say(CN+" polishes "+query_possessive()+" "+CAP(str)+".\n");
  return 1;
}
 
/* GLEVEL 14 commands */
forge(str) {
  object ob;
  int val, sps, class;
  if(!str) {
    write("You can:\n"+
          "  forge dagger  for 20sp and 100 coins\n"+
          "  forge mace    for 30sp and 200 coins\n"+
          "  forge sword   for 40sp and 300 coins\n"+
          "  forge axe     for 50sp and 500 coins\n");
    return 1;
  }
  if(!(str=="dagger" || str=="mace" || str=="sword" || str=="axe")) {
    forge();
    return 1;
  }
  ob = clone_object("/obj/weapon");
  ob->set_id(str);
  ob->set_alias(str);
  ob->set_short("A barbarians "+str);
  ob->set_long("This is a "+str+" made by a mighty barbarian.\n");
  if(str=="dagger") {
    val = 100;
    sps = 20;
    class = 6;
  }
  if(str=="mace") {
    val = 200;
    sps = 30;
    class = 8;
  }
  if(str=="sword") {
    val = 300;
    sps = 40;
    class = 10;
  }
  if(str=="axe") {
    val = 500;
    sps = 50;
    class = 13;
  }
  ob->set_value(val);
  ob->set_weight((sps/10)-1);
  ob->set_class(class);
  if(SP<sps) { NOSP; destruct(ob); return 1; }
  if(TP->query_money()<val) {
    write("You do not have enough coins for that.\n");
    return 1;
  }
  lessp(sps);
  TP->add_money(-val);
  move_object(ob,TP);
  write("You gather the needed elements and forge a "+CAP(str)+".\n");
  say(CN+" forges a "+CAP(str)+".\n");
  return 1;
}
 
aggress(str) {
  string dummy;
  int x;
  x = random(100);
  if(!str) {
    write("What do you want to turn aggressive?\n");
    return 1;
  }
  if(SP<20) { NOSP; return 1; }
  if(!present(str,ENV_THIS)) {
    write("That is not here.\n");
    return 1;
  }
  if(!(present(str,ENV_THIS)->query_npc())) {
    write("That is not a monster!\n");
    return 1;
  }
  if(x<21) {
    write("The spell fails!\n");
    say(CN+" tries to make "+CAP(str)+" aggressive but just pisses it off.\n");
    lessp(25);
    present(str,ENV_THIS)->attack_object(TP);
    return 1;
  }
  if(sscanf(file_name(ENV_THIS),"room/%s",dummy)) {
    write("You cannot do that this close to town.\n");
    return 1;
  }
  lessp(20);
  write("You turn a "+CAP(str)+" aggressive.\n");
  say(CN+" turns a "+CAP(str)+" aggressive.\n");
  present(str,ENV_THIS)->set_aggressive(1);
  return 1;
}
 
/* GLEVEL 15 commands */
forgearmor(str) {
  object ob;
  int val, sps, class;
  if(!str) {
    write("You can:\n"+
          "  forge leather   for 30sp and 100 coins\n"+
          "  forge ringmail  for 40sp and 200 coins\n"+
          "  forge chain     for 50sp and 300 coins\n"+
          "  forge plate     for 70sp and 500 coins\n");
    return 1;
  }
  if(!(str=="leather" || str=="ringmail" || str=="chain" || str=="plate")) {
    forgearmor();
    return 1;
  }
  ob = clone_object("/obj/armor");
  ob->set_name(str);
  ob->set_alias("armor");
  ob->set_short("A barbarians "+str+" armor");
  ob->set_long("This is a suit of "+str+" armor made by a mighty barbarian.\n");
  ob->set_alias("armor");
  ob->set_type("armor");
  if(str=="leather") {
    val = 100;
    sps = 30;
    class = 2;
  }
  if(str=="ringmail") {
    val = 200;
    sps = 40;
    class = 3;
  }
  if(str=="chain") {
    val = 300;
    sps = 50;
    class = 3;
  }
  if(str=="plate") {
    val = 500;
    sps = 70;
    class = 4;
  }
  ob->set_value(val);
  ob->set_weight((sps/10)-1);
  ob->set_ac(class);
  if(SP<sps) { NOSP; destruct(ob); return 1; }
  if(TP->query_money()<val) {
    write("You do not have enough coins for that.\n");
    return 1;
  }
  lessp(sps);
  TP->add_money(-val);
  move_object(ob,TP);
  write("You gather the needed elements and forge a suit of "+
        CAP(str)+" armor.\n");
  say(CN+" forges a suit of "+CAP(str)+" armor.\n");
  return 1;
}
 
absorb() {
  if(SP<50) { NOSP; return 1; }
  if(absorb) {
    write("You are already absorbing points.\n");
    return 1;
  }
  absorb = 1;
  lessp(50);
  abs_obj = clone_object("/players/grimm/closed/obj/badge_stuff/absorb");
  abs_obj->set_absorb(40+random(20));
  abs_obj->shadow_me(TP,TO);
  abs_obj->set_msg("Your faction absorbs ");
  abs_obj->set_msg2("The faction scar runs out of energy.\n");
  write("Your faction begins absorbing damage.\n");
  say(CN+"'s faction scar glows.\n");
  return 1;
}
 
blam_abs() {
  destruct(abs_obj);
  absorb = 0;
  return 1;
}
 
quake() {
  object ob, next;
  if(SP<30) { NOSP; return 1; }
  if(ENV_THIS->realm()=="NT") {
    write("You can't do that in this room.\n");
    return 1;
  }
  lessp(30);
  ob = first_inventory(ENV_THIS);
  while(ob) {
    next = next_inventory(ob);
    if(ob!=TP && !ob->query_npc() && ob->query_hp()) {
      tell_object(ob,CN+" hits the ground and makes the earth quake.\n"+
                  "You litterally \"fall\" out of the room.\n");
      ob->run_away();
    }
    ob = next;
  }
  write("You hit the ground and make the earth quake.\n");
  say(CN+" hits the ground and makes the earth quake.\n");
  return 1;
}
