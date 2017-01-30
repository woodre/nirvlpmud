/*****************************************************
Magician's Guild Generic Pet
by Feldegast/Christopher Smith
for Nirvana (elof.cns.iit.edu 3500)

Basic commands and structure for a generic pet.

*****************************************************/
#include "/players/feldegast/defines.h"
inherit "obj/monster";

object owner;
string owner_name;

object guardee;

int follow;
int upkeep_timer;

reset(arg) {
  ::reset(arg);
  if(arg) return;
  follow=1;
  call_out("faux_hb",2);
}

init() {
  add_action("cmd_hook", lower_case(name) );
}

void set_owner(object ob) {
  owner=ob;
  owner_name=(string)owner->query_real_name();
}
object query_owner() {
  return owner;
}
void set_owner_name(string str) {
  owner_name=str;
}
string query_owner_name() {
  return owner_name;
}
void set_upkeep_timer(int x) {
  upkeep_timer=x;
}
/*
   You can customize the method of upkeep by changing this function
   in the object that you inherit.  Just be sure to reset the upkeep
   timer or it will default to a period of 1.
*/
void upkeep() {
  if(owner->query_sp() > -10) {
    owner->add_spell_point(-5);
    if(!random((int)owner->query_attrib("wil")))
      tell_object(owner,"You struggle in a battle of wills with "+name+".\n");
  }
  else {
/*
This is rather tame, but I envision captive monsters taking a bit of
revenge as they shake off their masters in most cases.
*/
    tell_object(owner,name+" shakes off your control and runs away.\n");
    say(name+" runs off in a hurry.\n");
    destruct(this_object());
  }
  upkeep_timer=10;
}

void faux_hb() {
/*
  while(remove_call_out("faux_hb")==-1) ;
*/
  if(!owner) owner=find_player("owner_name");
  if(!owner) return;
  if(follow && owner &&
     !present(owner,environment(this_object())) &&
     environment(owner) ) {
    say(query_name()+" leaves.\n");
    move_object(this_object(),environment(owner));
    say(query_name()+" arrives following "+owner_name+".\n");
  }
  if( guardee && guardee->query_attack() &&
      environment(guardee)==environment(this_object()) ) {
     say(name+" leaps to join "+guardee->query_name()+" in battle!\n");
     attacked_by(guardee->query_attack());
  }
  if(--upkeep_timer <= 0) {
    upkeep();
  }

  call_out("faux_hb",2);    
}

void help() {
  write(
"All commands must be preceded by '"+name+"'.\n\
You can command this servant to do the following:\n\
\tattack <monster>     - Have "+name+" attack something\n\
\tguard <target>       - Have "+name+" guard somebody\n\
\tstay                 - Have "+name+" stop following you\n\
\tfollow               - Have "+name+" follow you\n\
\tdismiss              - Have "+name+" leave\n");
}
/*******************************************************************
Additional commands can be added to the help list by adding the
following lines to the object that inherits this:

void help() {
  ::help();
  write("blah blah blah");
  return 1;
}
*******************************************************************/

/******************************************************************
Another function that should be custom, but that I am leaving a
default for.
******************************************************************/
dismissed() {
  object control;
  write("You dismiss the "+short()+".\n");
  say(owner->query_name()+" dismisses "+short()+".\n");
  say(short()+" fades out of existence.\n");
  control=present("pet_controller",owner);
  if(control) {
    control->remove_pet(this_object());
  }
  destruct(this_object());
}

int attack_target(string str) {
  object target;
  target=present(str,environment(this_object()));
  if(!target) {
    write(capitalize(str)+" isn't here.\n");
    return 0;
  }
  if(target->is_player()) {
    write(capitalize(str)+" is a player!\n");
    return 0;
  }
  tell_room(environment(this_object()),
      BOLD+short()+" attacks "+target->query_name()+"!\n"+NORM);
  this_object()->attack_object(target);
  target->attacked_by(this_object());
  return 1;
}

int guard_target(string str) {
  object target;
  if(str=="nobody") {
    write("You command "+name+" to quit guarding.\n");
    guardee=0;
    return 0;
  }
  target=present(str,environment(this_object()));
  if(!target) {
    write(capitalize(str)+" is not here.\n");
    return 0;
  }  
  guardee=target;
  write("You order "+name+" to guard "+guardee->query_name()+".\n");
  if(target!=owner)
    tell_object(target,this_player()->query_name()+" has ordered "+name+" to guard you.\n");
  return 1;
}

int cmd_hook(string str) {
  string arg;
  if(!str) {
    help();
    return 1;
  }
  if(owner_name!=(string)this_player()->query_real_name()) return 0;
  if(sscanf(str,"attack %s",arg)==1) {
    attack_target(arg);
    return 1;
  }
  if(str=="stay") {
    write("You order "+name+" to stay here.\n");
    follow=0;
    return 1;
  }
  if(str=="follow") {
    write("You beckon for "+name+" to follow you.\n");
    follow=1;
    return 1;
  }
  if(str=="dismiss") {
    dismissed();
    return 1;
  }
  if(sscanf(str,"guard %s",arg)==1) {
    guard_target(arg);
    return 1;
  }
  help();
  return 1;
}

void remove_object(object prev) {
  object control;
  if(!owner) return;
  control=present("pet_controller",owner);
  if(!control) return;
  if(this_player()) write("Remove object called.\n");
  control->remove_pet(this_object());
}

void second_life() {
  object control;
  ::second_life();
  if(!owner) return;
  control=present("pet_controller",owner);
  if(!control) return;
  control->remove_pet(this_object());
}
