/* 10/08/06 - Rumplemintz: fixed syntax error  */
#define io  this_object()->short()
#define ao  this_object()->query_alias()
#define tp  this_player()->query_name()
#define eo  environment(this_object())
#include "/players/mythos/closed/ansi.h"
inherit "players/mythos/amisc/treasure1";
string reserve;
reset(arg) {
  if(arg) return;
    set_id("fake_pet");
    set_alias("fake_pet");
    set_short("fake_pet");
    set_weight(1);
    set_value(0);
}

init() {
  ::init();
  add_action("mount","mount");
  add_action("dismount","dismount");
  add_action("change","change_owner");
  add_action("pethelp","pethelp");
  add_action("bye","pet_bye");
  add_action("follow_set","follow_set");
  add_action("noise","noise");
  add_action("send","SEND");
  call_out("checker",3);
}

mount(str){
object soul;
if(!str) {write("What?\n"); return 1;}
  if(str == io || str == ao) {
  if(present("fake_pet",this_player())) { write("You may not mount more than one pet.\n"); return 1;}
  if(this_player()->query_real_name() == this_object()->query_owner()) {
    write("You mount your "+capitalize(io)+".\n");
    say(capitalize(tp)+" mounts "+this_player()->query_possesive()+" "+capitalize(io)+".\n");
    reserve=(this_object()->short());
    this_object()->set_short(this_object()->short()+" <mounted>");
    this_object()->set_follow(0);
    this_object()->set_mounted(1);
    move_object(this_object(),this_player());
    soul=present("soul",this_player());
    soul->set_min("arrives on the back of a "+ capitalize(io));
    soul->set_mout("leaves riding on the back of a "+ capitalize(io));
    if(this_object()->query_fly()){
    soul->set_mmout("flies off on the back of a "+ capitalize(io));
    soul->set_mmin("flies in on the back of a "+ capitalize(io));
    } else {
    soul->set_mmout("vanishes on the back of a "+ capitalize(io));
    soul->set_mmin("arrives on the back of a "+ capitalize(io));
    }
    return 1;}
    write("The "+capitalize(io)+" is not yours.\n");
    return 1;}
    write(capitalize(str)+" is not here to mount.\n"); return 1;}

dismount(str) {
object soul;
if(!str) {write("What?\n"); return 1;}
if(str == io || str == ao) {
    if(this_object()->query_mount() != 1) {
    tell_object(this_player(),"You are not mounted on "+io+"!\n"); return 1;}
    write("You dismount your "+capitalize(io)+".\n");
    say(capitalize(tp)+" dismounts "+this_player()->query_possesive()+" "+capitalize(io)+".\n");
    this_object()->set_follow(1);
    this_object()->set_short(reserve);
    this_object()->set_mounted(0);
    move_object(this_object(),this_player());
    soul=present("soul",this_player());
    soul->set_min("arrives");
    soul->set_mout("leaves");
    soul->set_mmout("disappears in a puff of smoke");
    soul->set_mmin("arrives in a puff of smoke");
    move_object(this_object(),enironment(this_player()));
    return 1;}
    }

change(str) {
string petname, new;
if(!str) {write("What?\n"); return 1;}
sscanf(str,"%s %s",petname,new);
if(petname== io || petname==ao) {
if(this_player()->query_real_name() != this_object()->query_owner()) {
  write("You are not the owner!\n"); return 1;}
  if(this_object()->query_mount()) {write("You must dismount first!\n"); return 1;}
  if(!present(str,eo)) { write(capitalize(new)+" is not here.\n"); return 1;}
  this_object()->set_owner(new);
  write("You have given "+io+" to "+capitalize(new)+".\n");
  tell_room(eo,io+" has changed hands.\n");
  return 1;}
}

bye(str) {
if(!str) {write("What?\n"); return 1;}
if(str == io || str == ao) {
 if(this_player()->query_real_name() != this_object()->query_owner()) {
  write("You are not the owner!\n"); return 1;}
  if(this_object()->query_mount()) {write("You must first dismount.\n"); return 1;}
  tell_room(eo,capitalize(tp)+" commands "+io+" to leave.\n");
  tell_room(eo,"There is a  >>>Flash<<< and "+io+" is gone!\n");
  destruct(this_object());
  return 1;}
  write(str+" is not here to dismiss.\n"); 
  return 1;}
  
follow_set(str) {
if(!str) {write("What?\n"); return 1;}
if(str == io || str == ao) {
if(this_player()->query_real_name() != this_object()->query_owner()) {
  write("You are not the owner!\n"); return 1;}
  if(this_object()->query_mount()) {write("You must first dismount.\n"); return 1;}
  if(this_object()->query_follow()) {
  this_object()->set_follow(0);
  write(io+" no longer follows you.\n");
  return 1;}
  this_object()->set_follow(1);
  write(io+" will now follow you.\n"); 
  return 1;}
}
  
noise(str) {
if(!str) {write("What?\n"); return 1;}
if(str == io || str == ao) {
if(this_player()->query_real_name() != this_object()->query_owner()) {
  write("You are not the owner!\n"); return 1;}
  if(this_object()->query_noise()) {
  this_object()->set_noise(0);
  write(io+" has been quieted.\n");
  return 1;}
  this_object()->set_noise(1);
  write(io+" is now free to make noise.\n");
  return 1;}
}
  
send(str){
string pet,who,what;
  if(sscanf(str,"%s %s %s",pet,who,what) != 3) {write("Usage: SEND <petname> <who> <what>\n"); return 1;}
if(pet==io || pet==ao) {
if(this_player()->query_real_name() != this_object()->query_owner()) {
  write("You are not the owner!\n"); return 1;}
  if(!present(what,this_player())) {write("You do not have "+what+".\n"); return 1;}
  if(present(what,this_player())->query_id()=="fake_pet") {
  write("You may not send a pet to another.\n"); return 1;}
  if(!find_player(who)) {write(who+" is not on the MUD framework.\n"); return 1;}
  move_object(present(what,this_player()),find_player(who));
  tell_room(environment(this_player()),"\n"+io+" "+this_object()->query_send1()+" "+what+" to "+
  capitalize(who)+".\n\n");
  tell_room(environment(this_player()),io+" returns.\n\n");
  tell_room(environment(find_player(who)),"\n"+io+" "+this_object()->query_send2()+" "+what+" to "+
  capitalize(who)+".\n");
  tell_room(environment(this_player()),io+" leaves.\n\n");
  tell_object(find_player(who),"::> From "+capitalize(tp)+".\n");
  return 1;}
  }
  
checker() {
  if(this_object()->query_follow()) {
  if(!present(this_object()->query_owner(),eo)) {
  if(!find_player(this_object()->query_owner())) { 
  destruct(this_object());
  return 1;}
  tell_room(eo,capitalize(io)+ this_object()->query_msg()+
  " out after "+capitalize(this_object()->query_owner())+".\n");
  move_object(this_object(),environment(find_player(this_object()->query_owner())));
  tell_room(eo,capitalize(io)+ this_object()->query_msg()+
  " in after "+capitalize(this_object()->query_owner())+".\n"); }
  }
  if(this_object()->query_noise()) {
  if(random(100) < 7) {
  if(this_object()->query_mount()) {
  switch(random(4)) {
  case 0 : tell_room(environment(eo),this_object()->query_sound1()); break;
  case 1 : tell_room(environment(eo),this_object()->query_sound2()); break;
  case 2 : tell_room(environment(eo),this_object()->query_sound3()); break;
  case 3 : tell_room(environment(eo),this_object()->query_sound4()); break;
  }
  } else {
  switch(random(4)) {
  case 0 : tell_room(eo,this_object()->query_sound1()); break;
  case 1 : tell_room(eo,this_object()->query_sound2()); break;
  case 2 : tell_room(eo,this_object()->query_sound3()); break;
  case 3 : tell_room(eo,this_object()->query_sound4()); break;
  }}}}
  call_out("checker",3); 
  return 1;}
  
pethelp() {
cat("/players/mythos/amisc/pethelp");
return 1;}
  
  
  
