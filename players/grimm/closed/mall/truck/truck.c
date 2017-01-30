#include "/players/grimm/closed/mall/truck/truck.h"
inherit "/obj/monster";
object owner, remote;
string nme, myid, capown;
int bullets, armor, bulstrength, straif, hits, kills, nuke, cach;
 
reset(arg) {
  if(arg) return;
  set_light(1);
  set_alias("truck");
  set_name("Monster Truck");
  set_wc(20);
  set_ac(10);
  set_hp(1000);
  bullets=1000;
  bulstrength=5;
  armor=10;
  cach=0;
  capown="NOBODY";
  straif=10;
  hits=1000;
  nuke=0;
  myid="TRUCK";
  enable_commands();
}
 
set_nme(str) { nme=str; }
set_remote(ob) { remote=ob; }
set_owner(ob) { owner=ob; }
set_cap_own(str) { capown=str; }
 
catch_tell(str) {
  if(!find_living(owner->query_real_name())) {
    destruct(remote);
    destruct(this_object());
    return 1;
  }
  if(!str) return 1;
  if(!cach)
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
 
honk() {
  say(capown+" honks "+owner->query_posessive()+" horn.\n");
  tell_object(owner,"You honk the truck's horn.\n");
  return 1;
}
 
rev() {
  say(capown+" revs "+owner->query_possessive()+" engine.\n");
  tell_object(owner,"You rev the truck's engine.\n");
  return 1;
}
 
im_a_truck() { return 1; }
 
atak(str) {
  object ob;
  string it;
  if(!str) {
    tell_object(owner,"What?\n");
    return 0;
  }
  it=str+"truck";
  if(!(ob=present(it,environment(this_object())))) {
    tell_object(owner,"That is not here.\n");
    return 0;
  }
  if(!ob->im_a_truck()) {
    tell_object(owner,"That is not a truck.\n");
    return 0;
  }
  return ob;
}
 
shoot(str) {
  object ob;
  int amt;
  if(!bullets) {
    tell_object(owner,"You are out of bullets!\n");
    say(capown+"'s truck's barrels are empty.\n");
    return 1;
  }
  if(!(ob=atak(str))) return;
  say(capown+" lets "+owner->query_possessive()+" machine guns blaze!\n");
  tell_object(ob,capown+" showers your truck in a barrage of bullets!\n");
  tell_object(owner,"You shower the truck in a barrage of bullets!\n");
  amt=(random(straif)+1);
  if(amt>bullets) {
    amt=bullets;
    tell_object(owner,"You run out of bullets!\n");
    say(capown+"'s truck runs out of bullets.\n");
  }
  bullets-=amt;
  amt=amt*(random(bulstrength));
  if(!amt) amt=1;
  remote->add_coolant(-amt);
  ob->damage_me(amt,owner,this_object());
  return 1;
}
 
damage_me(amt,that,ataktruk) {
  int dam;
  object ob;
  dam=amt-random(armor);
  if(dam>(armor*2) && armor) {
    tell_object(that,"You blow up a shield in your attack!\n");
    armor--;
    tell_object(owner,"A shield blows up! ("+armor+" left)\n");
    say(capown+" looses a shield!\n");
  }
  if(amt>hits) {
    ataktruk->add_kill(1);
    tell_object(owner,"Your truck blows up!\n");
    tell_object(that,"You blow the truck up in your attack!\n");
    say(capown+"'s truck blows up!\n");
    tell_room(owner,capown+"'s truck blows up!\n");
    destruct(remote);
    ob=clone_object("/players/grimm/closed/mall/truck/dead_truck");
    ob->set_nme("The remains of "+capown+"'s truck");
    move_object(ob,environment(this_object()));
    tell_object(owner,"GAME OVER.\n");
    destruct(this_object());
    return 1;
  }
  amt-=((armor/2)+random(armor/2));
  if(amt<0) amt=0;
  hits-=amt;
  tell_object(owner,capitalize(that->query_real_name())+" damaged your truck!\n"+
      "hits: "+hits+"   shields: "+armor+"   bullets left: "+bullets+"\n");
  return 1;
}
 
short() {
  return nme+"("+capown+")";
}
 
long() {
  write("This is "+capown+"'s monster truck.\n");
  return 1;
}
 
nuke(str) {
  int amt;
  object ob;
  if(!nuke) {
    tell_object(owner,"You do not have any nukes!\n");
    return 1;
  }
  if(!(ob=atak(str))) return;
  say(capown+" sets off a nuke against "+ob->short()+".\n");
  tell_object(ob,capown+" sends a nuke againse your truck!\n");
  tell_object(owner,"You set off a nuke!\n");
  nuke--;
  amt=500+random(500);
  remote->add_coolant(-100);
  ob->damage_me(amt,owner,this_object());
  if(!nuke) tell_object(owner,"You are out of nukes.\n");
  return 1;
}
 
add_nuke(x) { nuke+=x; }
query_nuke() { return nuke; }
add_bullets(x) { bullets+=x; }
query_bullets() { return bullets; }
add_armor(x) { armor+=x; }
query_armor() { return armor; }
query_kills() { return kills; }
add_kill(x) { kills+=x; }
add_straif(x) { straif+=x; }
query_straif() { return straif; }
add_hits(x) { hits+=x; }
query_hits() { return hits; }
add_bulstrength(x) { bulstrength+=x; }
query_bulstrength() { return bulstrength; }
 
id(str) { return str=="truck" || str==myid; }
 
set_my_id(str) { myid=str; }
 
tsay(str) {
  if(!str) {
    tell_object(owner,"What do you want the truck to say?\n");
    return 1;
  }
  say(capown+"'s truck \"says\": "+str+"\n");
  tell_object(owner,"Your truck says: "+str+"\n");
  return 1;
}
 
save_me(fn) {
  save_object(fn+"t");
  return 1;
}

restore_me(fn) {
  restore_object(fn);
  return 1;
}
