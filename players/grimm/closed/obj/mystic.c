#define THISFACTION "Dopple-Mystic"
#include "/players/grimm/closed/obj/faction.h"
int spirits;
int cursed;
int veiled;
int weakened;
int plagued;
int tmp;
object sp_obj;
object cursed_obj;
object plagued_obj;
 
set_plagued(x) { plagued = x; }
 
set_plagued_obj(ob) { plagued_obj = ob; }
 
set_weakened(x) { weakened = x; }
 
set_velied(x) { veiled = x; }
 
set_sp_obj(ob) { sp_obj = ob; }
 
set_spirits(x) { spirits = x; }
 
set_cursed(x) { cursed = x; }
 
set_cursed_obj(ob) { cursed_obj = ob; }
 
reset(arg) {
  if(arg) return;
  plagued = 0;
  spirits = 0;
  veiled = 0;
  weakened = 0;
  HP_STORED = 0;
  MUFFLED = 0;
  set_heart_beat(1);
}
 
 
heart_beat() {
  if(plagued) {
    if(plagued_obj->query_hp()>0 && plagued<7 &&
       THIS->query_attack()==plagued_obj) {
      plagued++;
      plagued_obj->hit_player(random(10));
      tell_object(env(env(TO)),CAP(plagued_obj->query_name())+" writhes in pain from the plague!\n");
       tell_object(env(TO),CAP(plagued_obj->query_name())+" writhes in pain from the plague!\n");
    } else {
      tell_object(env(env(TO)),CAP(plagued_obj->query_name())+" shakes the plague.\n");
      tell_object(env(TO),CAP(plagued_obj->query_name())+" shakes the plague.\n");
      plagued = 0;
    }
  }
}
 
 
query_dopp_ow() { return "Myst"; }
 
query_pet_allow() {
  if(GLEVEL>11) return 1;
  return 0;
}
 
short() { 
  string stng;
  if(FINAL>time()) return 0;
  if(TP==THIS) stng = " ("+HP_STORED+" sp stored)";
  else stng = "";
  return "Mark of the Mystics Faction"+stng; }
 
long() { 
  write("This is the mark of the mystics' faction.\n"+
        "Only those who have proven themselves worthy may wear it.\n"+
        "Type \"mh\" or \"mystic_help\" for more help.\n");
  if(HP_STORED)
    write("("+HP_STORED+" spell points stored)\n");
  return 1;
}
 
id(str) {
  return str == THISFACTION || str == "mark" || str == "Dopple-Faction";
}
 
init() {
  if(GLEVEL>9) {
    add_action("help_faction","mh");
    add_action("help_faction","mystic_help");
    add_action("say_it_in_lingo","msay");
    add_action("guild_who","mystic_who");
    add_action("guild_who","mw");
    add_action("guild_tell","mystic_tell");
    add_action("guild_tell","mt");
    add_action("guild_emote","mystic_emote");
    add_action("guild_emote","me");
    add_action("generic_shaddup","mystic_shaddup");
    add_action("generic_shaddup","mts");
    add_action("update","mupdate");
    add_action("coins_to_heal","cheal");
    add_action("zar","shadizar");
    add_action("zar","zar");
    add_action("mbag","mbag");
  }
  if(GLEVEL>10) {
    add_action("veil","veil");
    add_action("sp_store","store");
    add_action("sp_retrieve","retrieve");
    add_action("crypt","crypt");
  }
  if(GLEVEL>11) {
    add_action("weaken","weaken");
    add_action("enchant_armor","enchant");
    add_action("get_pet","imp");
  }
  if(GLEVEL>12) {
    add_action("dull","dull");
    add_action("plague","plague");
    add_action("spirits","spirits");
  }
  if(GLEVEL>13) {
    add_action("cure","cure");
    add_action("curse","curse");
  }
  if(GLEVEL>14) {
    add_action("resurect","resurect");
    add_action("scare","scare");
    add_action("death","death");
  }
}
 
query_auto_load() {
  return "/players/grimm/closed/obj/mystic:"; }
 
init_arg(str) {
}
 
help_faction() {
  cat("/players/grimm/closed/obj/badge_stuff/mystic.help");
  return 1;
}
 
/* GLEVEL 10 commands */
guild_tell(str) {
  if(!str) {
    write("What do you want to tell them?\n");
    return 1;
  }
  tell_the_guilders(str,"<",">");
  return 1;
}
 
update() {
  object fact;
  fact = clone_object("/players/grimm/closed/obj/mystic");
  fact->set_plagued(plagued);
  fact->set_plagued_obj(plagued_obj);
  fact->set_weakened(weakened);
  fact->set_veiled(veiled);
  fact->set_pet(pet);
  fact->set_hp_stored(HP_STORED);
  fact->set_sp_obj(sp_obj);
  fact->set_spirits(spirits);
  fact->set_cursed(cursed);
  fact->set_cursed_obj(cursed_obj);
  move_object(fact, TP);
  write("Faction Mark Restored.\n");
  destruct(TO);
  return 1;
}
 
zar(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Cast a Shadizar spell at what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  getem(20,random(40),what,"You speak some cryptic words and a "+cwhat+
        " is engulfed in blue flames",
        CN+" speaks some cryptic words and a "+cwhat+
        " is engulfed in blue flames");
  return 1;
}
 
mbag() {
  object bag;
  if(SP<20) { NOSP; return 1; }
  bag = clone_object("/players/grimm/closed/obj/badge_stuff/bag");
  bag->set_max_weigth(20+((GLEVEL-9)*2));
  move_object(bag, TP);
  write("You conjur up a magical bag.\n");
  say(CN+" conjures up a magical bag.\n");
  lessp(20);
  return 1;
}
 
/* GLEVEL 11 commands */
veil(str) {
  object ob;
  string what;
  int oldwc;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("What do you want to cast a veil around?\n");
            return 1;
            }
  if(veiled) {
    write("You are already casting a veil on something.\n");
    return 1;
  }
  if(SP<50) { NOSP; return 1; }
  if(!(ob=present(what,ENV_THIS))) {
    write("That is not in the room with you.\n");
    return 1;
  }
  if(!ob->query_npc()) {
    write("You cannot cast a veil on players.\n");
    return 1;
  }
  if(TP->query_attack()!=ob) {
    write("You must be attacking that to be close enough to cast a veil on it.\n");
    return 1;
  }
  oldwc = ob->query_wc();
  lessp(50);
  ob->set_wc(oldwc/2);
  veiled = 1;
  write("You cast a veil on "+CAP(what)+" cripling it.\n");
  say(CN+" casts a veil on a "+CAP(what)+" cripling it.\n");
  tmp = oldwc;
  call_out("un_veil",GLEVEL,ob);
  return 1;
}
 
un_veil(ob) {
  say("A "+CAP(ob->query_name())+" regains its strength.\n");
  ob->set_wc(tmp+2);
  veiled = 0;
  return 1;
}
 
sp_store(str) {
  int x;
  if(!(sscanf(str,"%d",x))) {
    write("How many spell points do you want to store?\n");
    return 1;
  }
  if(SP<x) {
    write("You do not have that many spell points.\n");
    return 1;
  }
  if(x<1) {
    write("Yeah, right, like I'm gonna fall for that one.\n");
    return 1;
  }
  if((HP_STORED+(x/2))>100) {
    write("That would put you over the limit...");
    x = (100*2) - (HP_STORED*2);
    write("adding "+x+" to max it.\n");
  }
  TP->add_spell_point(-x);
  HP_STORED += (x/2);
  write(HP_STORED+" total spell points now stored.\n");
  return 1;
}
 
sp_retrieve(str) {
  int x;
  if(!(sscanf(str,"%d",x))) {
    write("How many spell points do you want to retrive?\n");
    return 1;
  }
  if(x<1) {
    write("Yeah, right, like I'm gonna fall for that one.\n");
    return 1;
  }
  if(HP_STORED<x) {
    write("You do not have that many stored...");
    x = HP_STORED;
    write("retriving "+x+" spell points.\n");
  }
  TP->add_spell_point(x);
  HP_STORED -= x;
  write(x+" spell points added.\n");
  return 1;
}
 
crypt() {
  object corp, room;
  if(SP<30) { NOSP; return 1; }
  if(!(corp=present("corpse",ENV_THIS))) {
    write("There is no corpse in the room.\n");
    return 1;
  }
  if(!find_object("/players/grimm/closed/obj/badge_stuff/m_pr")) {
    room=clone_object("/players/grimm/closed/obj/badge_stuff/m_pr");
  }
  lessp(30);
  write("You send the corpse back to your crypt.\n");
  say(CN+" sends a corpse to the crypt.\n");
  move_object(corp,find_object("/players/grimm/closed/obj/badge_stuff/m_pr"));
  return 1;
}
 
/* GLEVEL 12 commands */
weaken(str) {
  object ob;
  int oldac;
  string what;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("What do you want to weaken?\n");
            return 1;
            }
  if(weakened) {
    write("You are already weakening something.\n");
    return 1;
  }
  if(SP<40) { NOSP; return 1; }
  if(!(ob=present(what,ENV_THIS))) {
    write("That is not in the room with you.\n");
    return 1;
  }
  if(!ob->query_npc()) {
    write("You cannot weaken players.\n");
    return 1;
  }
  if(TP->query_attack()!=ob) {
    write("You must be attacking that to be close enough to weaken it.\n");
    return 1;
  }
  oldac = ob->query_ac();
  lessp(40);
  ob->set_ac(oldac/2);
  weakened = 1;
  write("You weaken a "+CAP(what)+".\n");
  say(CN+" weakens a "+CAP(what)+".\n");
  tmp = oldac;
  call_out("un_weaken",GLEVEL,ob);
  return 1;
}
 
un_weaken(ob) {
  say("A "+CAP(ob->query_name())+" regains its strength.\n");
  ob->set_ac(tmp+2);
  weakened = 0;
  return 1;
}
 
enchant_armor(str) {
  object ob;
  int ac, max;
  string type;
  if(!str) {
    write("Which piece of armor do you wish to enchant?\n");
    return 1;
  }
  if(SP<80) { NOSP; return 1; }
  if(!(ob=present(str,TP))) {
    write("You do not have one of those on you.\n");
    return 1;
  }
  if(!(ac=ob->armor_class())) {
    write("That is not a piece of armor.\n");
    return 1;
  }
  type = ob->query_type();
  if(type=="armor") max = 6;
  else max = 2;
  if(ac==max) {
    write("That is already been enchanted enough.\n");
    return 1;
  }
  ac++;
  ob->set_ac(ac);
#if 1 /* Rumplemintz */
  ob->set_short(ob->short() + " [Mystic Enchanted]");
  call_out("disenchant_armor", 1800, ob);
#  if 0
  write("DISENCHANT_ARMOR CAlled with Delay of 3600\n");
#  endif
#endif
  write("You concentrate on the armor and it begins to glow.\n");
  say(CN+" recites some mystic words and a piece of "+query_possessive()+
      " armor begins to glow.\n");
  lessp(80);
  return 1;
}

#if 1 /* Rumplemintz */
int disenchant_armor(object obj) {
  string pre, post;

  if (!obj)  return 1;
  if (sscanf(obj->short(), "%s [Mystic Enchanted]%s", pre, post) != 2)
    return 1;
  obj->set_ac((int)obj->query_ac() - 1);
  obj->set_short(pre + post);
  tell_object(environment(obj),
    "The Mystic Enchantment on " + obj->short() + " fadess.\n");
  return 1;
}
#endif
 
get_pet(str) {
  if(!str) pet2("help","blah");
  pet2(str,"imp");
  return 1;
}
 
/* GLEVEL 13 commands */
dull(str) {
  int was, to_be;
  object ob;
  if(!str) {
    write("What do you want to dull?\n");
    return 1;
  }
  if(SP<75) { NOSP; return 1; }
  if(!(ob=present(str,this_player()))) {
    write("You do not have one of those.\n");
    return 1;
  }
  if(!(was=ob->weapon_class())) {
    write("That is not a weapon.\n");
    return 1;
  }
  if(was<7) {
    write("That weapon is dull enough.\n");
    return 1;
  }
  to_be=was-1;
  lessp(75);
  ob->set_class(to_be);
  write("You bang the weapon on the ground.\n");
  write("(Be sure to \"unwield "+str+"\" and then \"wield "+str+"\" to get the change on you)\n");
  say(CN+" bangs "+query_possessive()+" weapon on the ground.\n");
  return 1;
}
 
plague(str) {
  object ob;
  if(plagued) {
    write("You are already concentrating on plagueing something.\n");
    return 1;
  }
  if(!str) return;
  if(SP<30) { NOSP; return 1; }
  if(!(plagued_obj=present(str,ENV_THIS))) {
    write("That is not here.\n");
    return 1;
  }
  if(plagued_obj==TP) {
    write("You can't plague yourself.\n");
    return 1;
  }
  if(!(TP->query_attack()==plagued_obj)) {
    write("You must be attacking the "+CAP(str)+" to plague it.\n");
    return 1;
  }
  lessp(30);
  plagued = 1;
  write("You cast a plague on a "+CAP(str)+"!\n");
  say(CN+" plagues a "+CAP(str)+".\n");
  return 1;
}
 
spirits() {
  if(SP<40) { NOSP; return 1; }
  if(spirits) {
    write("Your are already protecting you.\n");
    return 1;
  }
  spirits = 1;
  lessp(40);
  sp_obj = clone_object("/players/grimm/closed/obj/badge_stuff/absorb");
  sp_obj->set_absorb(20+random(30));
  sp_obj->shadow_me(TP,TO);
  sp_obj->set_msg("The spirits absorb ");
  sp_obj->set_msg2("The spirits disipate.\n");
  write("The faction spirits begin absorbing damage for you.\n");
  say(CN+" casts a spell and is suddenly surrounded by spirits.\n");
  return 1;
}
 
blam_abs() {
  destruct(sp_obj);
  spirits = 0;
  return 1;
}
 
 
/* GLEVEL 14 commands */
cure(str) {
  object per;
  if(!str) {
    write("Who do you want to cure?\n");
    return 1;
  }
  if(SP<40) { NOSP; return 1; }
  if(!(per=present(str,ENV_THIS))) {
    write("That player is not in the room with you.\n");
    return 1;
  }
  lessp(40);
  per->heal_self(35);
  write("You apply cures "+CAP(str)+".\n");
  say(CN+" applies cures "+CAP(str)+".\n");
  return 1;
}
 
curse(str) {
  if(cursed) {
    write("You are already cursing something.\n");
    return 1;
  }
  if(!str) {
    write("What do you want to curse?\n");
    return 1;
  }
  if(SP<40) { NOSP; return 1; }
  if(!(cursed_obj=present(str,ENV_THIS))) {
    write("That is not in the room with you.\n");
    return 1;
  }
  if(!TP->query_attack()) {
    write("You must be attacking the "+CAP(str)+" to be close enough to "+
          "curse it.\n");
    return 1;
  }
  if(TP->query_attack()!=cursed_obj) {
    write("You must be attacking the "+CAP(str)+" to be close enough to "+
          "curse it.\n");
    return 1;
  }
  lessp(40);
  write("You curse the "+CAP(str)+" and it clutches it's heart in agony.\n");
  say(CN+" puts a curse on a "+CAP(str)+" and it cluthes it's heart in agony.\n");
  cursed_obj->set_heal(0,305);
  call_out("remove_curse",300);
  return 1;
}
 
remove_curse() {
  cursed_obj->set_heal(4,30);
  cursed = 0;
  return 1;
}
 
/* GLEVEL 15 commands */
resurect(str) {
  object pers;
  if(!str) {
    write("Who do you want to resurect?\n");
    return 1;
  }
  if(SP<80) { NOSP; return 1; }
  if(!(pers=present(str,ENV_THIS))) {
    write("That person is not in the room with you.\n");
    return 1;
  }
  if(!pers->query_ghost()) {
    write("Get real! You cannot resurect the living!\n");
    return 1;
  }
  if(pers==TP) {
    write("You attempt to resurect yourself, but the strain is too much.\n");
    return 1;
  }
  lessp(80);
  resurect2(pers);
  tell_object(pers,CN+" resurects you from the dead!\n");
  say(CN+" resurects "+CAP(str)+" from the dead!\n");
  write("You resurect "+CAP(str)+" from the dead!\n");
  return 1;
}
 
resurect2(pers) {
  return call_other(pers,"remove_ghost",0); }
 
death(str) {
  string what,cwhat;
  if(str) what=str;
  else if(TP->query_attack())
         what=TP->query_attack()->query_name();
       else {
            write("Summon death on what?\n");
            return 1;
            }
  what=lower_case(what);
  cwhat=capitalize(what);
  if(SP<80) { NOSP; return 1; }
  write("You summon Death.\n");
  say(CN+" summons Death.\n");
  getem(20,20,what,"Death masacres a "+cwhat+" to small fragments",
        "Death masacres a "+cwhat+" to small fragments");
  if(present(what,ENV_THIS)->query_hp())
    getem(20,20,what,"Death masacres a "+cwhat+" to small fragments",
          "Death masacres a "+cwhat+" to small fragments");
  else lessp(20);
  if(present(what,ENV_THIS)->query_hp())
    getem(20,20,what,"Death masacres a "+cwhat+" to small fragments",
          "Death masacres a "+cwhat+" to small fragments");
  else lessp(20);
  if(present(what,ENV_THIS)->query_hp())
    getem(20,20,what,"Death masacres a "+cwhat+" to small fragments",
          "Death masacres a "+cwhat+" to small fragments");
  else lessp(20);
  write("Death leaves until called again.\n");
  say("Death leaves until called again.\n");
  return 1;
}
