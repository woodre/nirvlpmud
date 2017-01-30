#include "/players/mythos/bounty/def.h"
inherit "obj/monster";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
  set_name("Officer");
  set_alias("bounty_officer_69");
  set_alt_name("officer");
  set_race("hunter");
  set_short("Bounty Hunter Officer");
  set_long("A Man in dark volumious clothing.\n"+
           "> Desiring a Hunt? This is the man you seek.\n"+
           "> Desiring Payment? hand corpse to officer\n"+
           "     note: make sure the corpse is highest in\n"+
           "           your inventory. dont want the officer\n"+
           "           to make a mistake do we?\n");
  set_hp(10000);
  set_level(50);
  set_al(0);
  set_wc(500);
  set_ac(500);
  set_aggressive(0);
}

init() {
 ::init();
  add_action("hand_corpse","hand");
}

query_prevent_shadow() { return 1;}

heal_self(arg) {
  int much;
  much = arg;
  if(much < -50) much = -50;
  ::heal_self(much);
}

zap_object() { return 1;}

hand(str) {
string null,names;
  if(!str) { write("hand what?\n"); return 1; }
  if(str != "corpse to officer") { write("hand what?\n"); return 1; }
  if(!present("corpse",this_player())) {
    write("You don't have a corpse!\n");
  return 1; }
  if(!present("corpse",this_player())->heal_value()) {
    write("You don't have a real corpse!\n"+
          "Trickery is not a good thing!\n");
    tell_room(environment(this_player()),
       "The officer lashes out at "+this_player()->query_name()+" with a small whip.\n");
    this_player()->heal_self(-10 - random(1000));
  return 1; }
  write("You hand the corpse to the officer.\n");
  say(this_player()->query_name()+" hands a corpse to the officer.\n");
  sscanf(present("corpse",this_player())->short(),"%s of %s",null,names);
  environment(this_object())->bounty(lower_case(names),this_player());
  destruct(present("corpse",this_player()));
  this_player()->add_weight(-5);
  write("The officer takes a look at the corpse.\n");
return 1; }

bounty_ok(str,ob) {
int much;
string what;
  if(ob) {
    sscanf(str,"%d %s",much,what);
    if(what == "coins" || what == "coin") ob->add_money(much);
    if(what == "exp" || what == "experience" || what == "xp") ob->add_exp(much);
    ob->save_me();
    tell_object(ob,"You recieve "+str+" from the officer.\n");
    tell_room(environment(this_object()),
              ob->query_name()+" collect a reward in exchange for a bounty\n",
              ob);
  }
return 1; }

bounty_reject(str,ob) {
  if(ob) tell_object(ob,"The officer rejects the corpse of "+str+".\n"+
                        "You recieve nothing in exchange \n"+
                        "and the corpse is destroyed.\n");
return 1; }