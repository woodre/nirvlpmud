#define WHO this_player()->query_real_name()
inherit "/obj/monster";
object owner;
string what,nme,own_name;
int cach;
int follow;
 
add_hp_to_me(x) {  this_object()->add_hit_point(x); }
set_go() { set_heart_beat(1); return 1; }
 
reset(arg) {
  ::reset();
  if(arg) return;
  set_light(1);
  set_can_kill(1);
  set_alias("pet");
  set_name("Pet");
  set_wc(20);
  set_ac(10);
  set_hp(1000);
  cach=0;
  follow=1;
  what="pet";
  nme="Nobody's";
  enable_commands();
}
 
heart_beat() {
  ::heart_beat();
  if(this_object()->query_attack()==owner) {
      owner->stop_fight();
      this_object()->stop_fight();
   }
   if(this_object()->query_attack() && !this_object()->query_attack()->query_npc()) {
      say("The pet tears into the measily human.\n");
      if(this_object()->query_attack()->query_hp()>20)
         this_object()->query_attack()->add_hit_point(-15);
   }
   if(!find_living(own_name)) {
      say(nme+"'s owner is missing.  He dies in a pool of sadness.\n");
      destruct(this_object());
      return 1;
   }
   if(!(environment(find_player(owner->query_real_name()))==environment(this_object())) &&
      follow==1) {
      say(nme+"'s "+what+" follows its master out of the room.\n");
      move_object(this_object(),environment(find_living(owner->query_real_name())));
      say(nme+"'s "+what+" follows its master into the room.\n");
   }
}
 
set_nme(str) { nme=str; }
set_owner(ob) { owner=ob; }
set_own_name(str) { own_name=str; }
set_what(str) { what=str; }
 
catch_tell(str) {
  if(!owner) { destruct(this_object()); return 1; }
  if(!find_living(own_name)) {
    say(nme+"'s owner is missing.  It dies in a pool of sadness.\n");
    destruct(this_object());
    return 1;
  }
  if(!str) return 1;
  if(!cach && environment(owner)!=environment(this_object()))
  tell_object(owner,"#"+str);
  return 1;
}
 
Look() {
  object ob;
  cach=0;
  tell_object(owner,"#"+environment(this_object())->long()+"\n");
  ob=first_inventory(environment(this_object()));
  while(ob) {
    if(ob->short()) 
      tell_object(owner,"#"+ob->short()+"\n");
    ob=next_inventory(ob);
  }
  if(!present(owner->query_real_name(),environment(this_object()))) follow=0;
  return 1;
}
 
other(str) {
  object env,new;
  cach=1;
  env=environment(this_object());
  command(str,this_object());
  new=environment(this_object());
  if(env!=new) Look();
  else cach=0;
  return 1;
}
 
north() {
  cach=1;
  command("north",this_object());
  Look();
  return 1;
}
 
south() {
  cach=1;
  command("south",this_object());
  Look();
  return 1;
}
 
east() {
  cach=1;
  command("east",this_object());
  Look();
  return 1;
}
 
west() {
  cach=1;
  command("west",this_object());
  Look();
  return 1;
}
 
ne() {
  cach=1;
  command("northeast",this_object());
  Look();
  return 1;
}
 
nw() {
  cach=1;
  command("northwest",this_object());
  Look();
  return 1;
}
 
se() {
  cach=1;
  command("southeast",this_object());
  Look();
  return 1;
}
 
sw() {
  cach=1;
  command("southwest",this_object());
  Look();
  return 1;
}
 
down() {
  cach=1;
  command("down",this_object());
  Look();
  return 1;
}
 
up() {
  cach=1;
  command("up",this_object());
  Look();
  return 1;
}
 
short() {
  return nme+"'s "+what;
}
 
long() {
  write("This is "+nme+"'s "+what+".\n");
  if(own_name==this_player()->query_real_name()) {
    write("This is your pet "+what+".  With it you can do the comands\n");
    write("listed in \""+what+" help\".  You can also have the pet\n");
    write("\"attack <monster>\".  And you can \"ADD <x>\" to the pet to\n");
    write("add <x> hit points to it (costing <x>*3 sp to you)\n");
    write("The pet currently has: "+this_object()->query_hp()+" hp left.\n");
   }
  return 1;
}
 
id(str) { return str==what || str=="pet" || str=="guild_monster"; }
 
psay(str) {
  if(!str) {
    tell_object(owner,"Your pet asks you: what do you want me to say?\n");
    return 1;
  }
  say(short()+" \"says\": "+str+"\n");
  tell_object(owner,"Your "+what+" says: "+str+"\n");
  return 1;
}
 
pemote(str) {
  if(!str) {
    tell_objet(owner,"Your pet asks you: what do you want me to emote?\n");
    return 1;
  }
  say(short()+" "+str+"\n");
  tell_object(owner,"Your "+what+" emotes:\n"+
              short()+" "+str+"\n");
  return 1;
}
 
ptell(str) {
  string who, it;
  if(!str) {
    tell_object(owner,"Your pet asks you: what and who do you want me to tell?\n");
    return 1;
  }
  if(!(sscanf(str,"%s %s",who,it))) {
    tell_object(owner,"Your pet asks you: what and who do you want me to tell?\n");
    return 1;
  }
  if(!find_living(who)) {
    tell_object(owner,"Your pet tells you: that person is not on the game.\n");
    return 1;
  }
  tell_object(find_living(who),short()+" tells you: "+it+"\n");
  tell_object(owner,"Your pet tells "+capitalize(who)+": "+it+"\n");
  return 1;
}
 
follow() {
  if(!present(owner->query_real_name(),environment(this_object()))) {
    write("You are not in the room with the "+capitalize(what)+".\n");
    return 1;
  }
  follow=1;
  write("Your "+capitalize(what)+" is now following you.\n");
  return 1;
}
 
stay() {
  if(!present(owner->query_real_name(),environment(this_object()))) {
    write("You are not in the room with the "+capitalize(what)+".\n");
    return 1;
  }
  follow=0;
  write("Your "+capitalize(what)+" gets comfortable in the corner of the room.\n");
  return 1;
}
 
init() {
  ::init();
  if(this_player()==owner) {
    add_action("atak","attack");
    add_action("add","ADD");
  }
}
   
atak(str) {
   object ob;
   if(!str) {
     write("Your "+what+" peers at you quizically.\n");
     return 1;
   }
   if(!(ob=present(str,environment(this_object())))) {
     write("Your "+what+" peers at you quizically.\n");
     return 1;
   }
   if(!ob->query_npc()) {
     write("Your "+what+" looks up and down the player and doesn't believe him\nto be tasty enough to attack.\n");
     return 1;
   }
   ob->set_can_kill(1);
  this_object()->attack_object(ob);
   say(nme+"'s "+what+" tears into "+capitalize(str)+".\n");
   write("Your "+what+" tears into "+capitalize(str)+".\n");
   return 1;
}
   
add(str) {
  int x;
  if(!str) {
    write("Your "+what+" peers at you quizically.\n");
    return 1;
  }
  if(!(sscanf(str,"%d",x))) {
    write("Your "+what+" peers at you quizically.\n");
    return 1;
  }
  if(x < 1){
    write("Please try healing me a positive number.\n");
    return 1;
  }
  x = x*3;
  if(owner->query_sp()<x) {
    write("Your "+what+" peers at you quizically.\n");
    return 1;
  }
  owner->add_spell_point(-x);
  this_object()->set_hp(this_object()->query_hp()+(x/3));
  write("Your "+what+" feels better.\n");
  return 1;
}
 
query_pet() { return 1; }
   
query_owner() { return owner; }

query_guild_name() { return "dopple-Dopple-Chronomaners-Barbarians-barbarians-Mystics-mystics"; }

add_exp(x) {
  if(x<1) return;
  if(find_player(own_name)) find_player(own_name)->add_exp(x); }
