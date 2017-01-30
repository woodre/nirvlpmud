/* 
   Adapted from Sandman's pet [/players/sandman/pets/pet.c]
   Redone by Mythos on 6 - 9 - 96
*/
#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/closed/guild/spells/monster2";

object vheh;
object target, oowner;
status Busy;
string name, owned;
int hp, ac, wc, guard;
int timed;

is_pet() { return 1; }
query_crime() { return 0; }

reset(arg) {
   ::reset(arg);
   if (arg) return;
   set_name("pet");
   set_alias("pet");
   set_short("a generic pet");
   set_long("You can have you pet do the following things:\n"+
/*
           "pet_help, fight <thing>, eat_corpse, send <what> <who>\n"+
*/
           "name <name>, release pet, guard, heel, switch <who>,\n"+
           "pet_help, fight <thing>, eat_corpse.\n"+
           "adapted from sandman's pet, remade by mythos\n"+
           "                          - A Mythos Product <6-9-96>\n");
   set_level(1);
   set_hp(1);
   set_wc(1);
   set_ac(1);
   set_al(0);
   target = 0;
   oowner = 0;
   guard = 0;
   timed = 0;
   call_out("follow",5);
}

set_oowner(ob) { oowner = ob; owned = ob->query_real_name();}

multiple_on() { 
  this_object()->set_mult(2);
  this_object()->set_mult_chance(5);
  this_object()->set_mult_dam1(1);
  this_object()->set_mult_dam2(20); 
return 1; }

special_on(int n) {
  if(!n) return 1;
  if(n == 1) {
    set_a_chat_chance(10);
    load_a_chat("The "+ oowner->query_name()+"'s pet screams in rage!\n");
  }
  if(n == 2) {
    set_chance(7);
    set_spell_dam(20);
    set_spell_mess1("The "+oowner->query_name()+"'s pet lashes out!\n");
    set_spell_mess2("The "+ oowner->query_name()+"'s pet lashes out!\n");
  }
return 1; }

init() {
   ::init();
   add_action("fight","fight");
   add_action("eat_corpse","eat_corpse");
   add_action("release","release");
   add_action("guard","guard");
   add_action("heel","heel");
   add_action("name","name");
   add_action("pet_help","pet_help");
   add_action("sswitch","switch");
/*
   add_action("send","send");
*/
}

pet_help() {
  if(!check_ok()) return 0;
  write("Pet Commands:\n"+
        "              fight <target>    -    commands pet to attack target\n"+
        "              eat_corpse        -    commands pet to eat corpse and \n"+
        "                                     heal a bit\n"+
        "              guard             -    commands pet to stay in one\n"+
        "                                     place and guard the area\n"+
        "              heel              -    calls the pet to you [must be\n"+
        "                                     same room]\n"+
        "              pet_help          -    this help file\n"+
        "              release pet       -    Releases the pet, pet disappears\n"+
        "              name <name>       -    Renames the pet\n"+
        "              switch <name>     -    Switches ownership of the pet to\n"+
        "                                     the indicated name [must be in same\n"+
        "                                     room]\n"+
/*
        "              send <what> <who> -    sends <what> to <who>\n");
*/
  "\n");
return 1; }

sswitch(str) {
  if(!check_ok()) return 0;
  if(!str) return 0;
  target = present(str,environment(this_object()));
  if(!target) { write("That is not here\n"); return 1; }
  if(find_player(str) != target) {
    write("That is not a player\n");
  return 1; }
  write("Your pet has switched hands.\n"+target->query_name()+" is now the owner.\n");
  say(oowner->query_name()+"'s pet has switched hands.\n");
  tell_object(target,oowner->query_name()+"'s pet is now your's.\n");
  oowner = target;
return 1; }

send(str) {
object item;
string what,who;
  if(!check_ok()) return 0;
  if(!str) return 0;
  if(sscanf(str,"%s %s",what,who) != 2) return 0;
  item = present(what,this_player());
  target = find_player(who);
  if(!item) { write("You do not have that!\n"); return 0; }
  if(!target) { write("That person is not in game.\n"); return 0; }
  if(target->query_invis()) { write("That person is not in game.\n"); return 0; }
  if(environment(target)->realm() == "NT" || 
     environment(this_player())->realm() == "NT") {
       write("Either you or the target is in a restricted zone.\n"+
             "The object can not be sent.\n");
  return 1; }
  if(item->drop() || item->query_auto_load() || !item->get() ||
     item->namer() == "cold" ||
      !item->query_weight()) {
      write("You may not send this item.\n");
    return 1; }
  if(item->armor_class() && item->query_worn()) { command("remove "+what,this_player()); }
  if(item->weapon_class() && item == this_player()->query_weapon()) { command("unwield "+what,this_player()); }
  tell_room(environment(this_player()),
    oowner->query_name()+" hands "+short()+" something.\n"+
    oowner->query_name()+"'s pet rushes off.\n\n\n");
    move_object(this_object(), "/players/vertebraker/closed/mythos_pet_room");
    vheh = clone_object("/players/vertebraker/closed/mythos_pet_ask");
    move_object(vheh, target);
    vheh->ask_me_foo(this_object(), item, target);
    transfer(item, "/players/vertebraker/closed/mythos_pet_room");
    Busy=1;
    return 1;
}

okay_do_da_ting(stuff, target) {
    if(environment(oowner)) tell_room(environment(oowner),
    oowner->query_name()+"'s pet rushes back in.\n");
  tell_room(environment(target), short() + " rushes in.\n");
  tell_room(environment(target),
    short()+" gives something to "+target->query_name()+".\n"+
    short()+" rushes off.\n");
  if(oowner && stuff && stuff->short())
  tell_object(target,"You recieve a "+stuff->short()+" from "+oowner->query_name()+"\n");
  if(stuff)
  move_object(stuff, target);
   return 1;
}
  
fight(str) {
   if (!check_ok()) return 0;
   if (!str) return 0;
   target = present(str, environment(this_object()));
   if (!target || !living(target) || !target->query_npc()) {
      write("The pet looks at you with a confused expression.\n");
     return 1;
   }
   write("Your pet leaps to attack "+target->query_name()+".\n");
   say(oowner->query_name()+"'s pet leaps to attack "+ target->query_name()+".\n");
   this_object()->attack_object(target);
   return 1;
}

name(str) {
   if (!check_ok()) return 0;
   if (!str) return 0;
   if(str == oowner->query_real_name() ||
      str == oowner->query_name()) { write("You can not do that.\n");
  return 1; }
   set_name(str);
   set_short(str+", "+oowner->query_name()+"'s pet");
   set_long("You can have you pet do the following things:\n"+
           "fight <thing>, eat_corpse, send <what> <who>\n"+
           "name <name>, release pet, guard, and heel.\n"+
           "adapted from sandman's pet, remade by mythos\n"+
           "                          - A Mythos Product <6-9-96>\n");
   write("Ok - name changed!\n");
   return 1;
}

guard() {
   if (!check_ok()) return 0;
   write("Your pet takes guard.\n");
   say(oowner->query_name()+"'s pet looks over the room menacingly.\n");
   guard = 1;
   return 1;
}

heel(){
   if (!check_ok()) return 0;
  if(this_player()->query_sp() < 20) { write("You dont have enough sp!\n"); return 1; }
  this_player()->add_spell_point(-20);
   write("Your pet snaps to attention.\n");
   say(oowner->query_name()+"'s pet snaps to attention.\n");
   target = this_object()->query_attack();
   if (target) {
      this_object()->stop_fight();
      target->stop_fight();
      this_object()->stop_fight();
      target->stop_fight();
   }
   if (guard) guard = 0;
   remove_call_out("follow");
   call_out("follow",3);
   return 1;
}

release(str) {
   if (!check_ok()) return 0;
   if (str != "pet") return 0;
   write("You release your pet.\n");
   say(oowner->query_name()+" releases the pet.\n");
   destruct(this_object());
   return 1;
}

eat_corpse() {
   if (!check_ok()) return 0;
   target = present("corpse",environment(this_object()));
   if(!target) {
      write("Your pet sniffs around but finds nothing to eat.\n");
      return 1;
   }
   if(living(target)) { write("The corpse is alive!\n"); return 1; }
   write("Your pet digs into its meal!\n");
   say(oowner->query_name()+"'s pet ravages a corpse!\n");
/*
   hit_point += target->heal_value();
*/
   heal_self(target->heal_value()); /* changed to this by verte so as the max_hp isn't exceeded */
   destruct(target);
   return 1;
}

check_ok() {
   if (!oowner) { oowner = this_player(); owned = this_player()->query_real_name(); }
  if(id(oowner->query_real_name()) || id(oowner->query_name())) return 0;
   if (this_player() != oowner) {
      tell_object(oowner, this_player()->query_name()+" is trying "+
                "to command your pet.\n");
      return 0;
   }
 if(present("no_pet", this_player())){  
     present("no_pet", this_player())->call_pet(); 
    return 0; }
   return 1;
}

catch_tell(str) {
   string s1,s2;
   if (!guard) return 1;
   if (!oowner) destruct(this_object());
   if(sscanf(str, "%s %s.",s1,s2) != 2) return;
   if (lower_case(s2) == "arrives") {
      target = find_living(lower_case(s1));
      if (target) {
      if(oowner)
         tell_object(oowner, "\n\nYour pet tells you: "+
           target->query_name()+" just entered the room!\n\n");
        return 1;
      }
   }
   return 1;
}

follow() {
  if(Busy) return call_out("follow", 3);
  if(environment(this_object())) {
   if (guard) { remove_call_out("follow"); return 1; }
   if(!oowner) { 
   if(timed > 100) { destruct(this_object()); }
     if(find_player(owned)) { oowner = find_player(owned); timed = 0;}
     else { timed = timed + 1; }
   }
   if(oowner) {
   if (environment(this_object()) != environment(oowner)) {
     if(environment(oowner)) /* check by verte 6.25.01 */
     if(!environment(oowner)->query_death_room()) {
      tell_room(environment(this_object()), this_object()->query_name()+
              " leaves the room.\n");
     tell_room(environment(oowner), this_object()->query_name()+
              " arrives.\n");
      move_object(this_object(),environment(oowner)); }
   } } }
   call_out("follow",3);
   return 1; 
}

heart_beat() {
  ::heart_beat();
  if(oowner && find_player(owned) && oowner->query_ghost()) { destruct(this_object()); set_heart_beat(0); return 1; }
  if(oowner && this_object()->query_attack()) {
    tell_object(oowner,"Pet: "+MAG+
       (this_object()->query_hp() * 10)/this_object()->query_mhp()+" / 10"+
       NORM+"\n");
   if(oowner->query_sp() > -10)
    oowner->add_spell_point(-1-random(2));
   }
 /* What is this? players must be able to kill pets. No auto death for pet combat 
   if(query_attack()) {
     if(find_player(query_attack()->query_real_name()) == query_attack()) {
       heal_self(500);
          query_attack()->heal_self(-10000000);
     }
   }
  */
}

/* Added by Feldegast 10-25-00 */
query_owner() { return oowner; }

NotBusy() { Busy = 0; }
