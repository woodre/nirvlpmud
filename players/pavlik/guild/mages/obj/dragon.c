inherit "/obj/monster";
#include "/players/pavlik/closed/colors.h"
#define DAE "/players/pavlik/guild/mages/obj/dragon-daemon.c"
#define WHO this_player()->query_real_name()
#define OWE capitalize(owner)
#define NME capitalize(nme)

string owner;
string nme;
string dragon_long, dragon_short;
string dragon_move;
int dragon_level;
int attack, defense;
int stamina, magic;
int max_sp, sp;
int sp_list, spell_count;
int follow, casting;
int wimpy;
int assist;

reset(arg){
  ::reset(arg);
 if(arg) return;
 set_name("Dragon");
 set_short("Dragon");
 set_ep(0);
 set_alias("pet");
 set_can_kill(1);
 set_ac(0);
 set_wc(10);
 set_hp(50);
 set_level(1);
 set_dead_ob(this_object());
 nme = "ben";  owner = "Nobody";
 dragon_long = "none";
 dragon_short = "the";
 dragon_move = "stomps";
 dragon_level = 1;  attack = 1;  defense = 1;
 magic = 1; stamina = 1; follow = 1;
 max_sp = 50;  sp = 50;
 sp_list = 1;  spell_count = 1;
 casting = 0;
 assist = 1;
 enable_commands();
  set_message_hit(({
  HIC+"OBLITERATED"+NORM, " with a Savage tail-'n-teeth "+HIR+"frenzy"+NORM,
  HIC+"Smashed"+NORM, " into the ground with a Deadly "+HIC+"*"+NORM+"StomP"+HIC+"*"+NORM,
  HIC+"Lashed"+NORM, " with his "+HIK+"SpIkeD TaiL"+NORM,
  HIR+"clawed"+NORM, ", drawing "+RED+"blood"+NORM,
  HIR+"chomped"+NORM, ", feeding",
  CYN+"swung"+NORM+" his mighty "+HIK+"TaiL"+NORM+" at", "",
  CYN+"snapped"+NORM+" at", ", exhaling tenuous puffs of smoke",
  }));
 call_out("follow", 3);
}

id(str) {
  return str == nme || str == owner+"'s dragon" || str == "dragon" ||
  str == "pet" || str == "mage_pet" || str == "dragg";
}

short(){ return NME+" "+dragon_short+" Dragon"; }
set_nme(str){ nme = str; }
query_nme(){ return nme; }
set_owner(str){ owner = str; }
query_owner(){ return owner; }
set_follow(n){ follow = n; }
query_follow(){ return follow; }
query_mage_pet(){ return 1; }
add_exp(i){ find_player(owner)->add_exp(i/2); }
set_dragon_long(str){ dragon_long = str; }
query_dragon_long(){ return dragon_long; }
set_dragon_short(str){ dragon_short = str; }
query_dragon_short(){ return dragon_short; }
set_dragon_move(str){ dragon_move = str; }
query_dragon_move(){ return dragon_move; }
set_casting(sp){ casting = sp; }
query_casting(){ return casting; }
set_sp_list(sp){ sp_list = sp; }
query_sp_list(){ return sp_list; }
set_wimpy(i){ wimpy = i; }
query_wimpy(){ return wimpy; }
set_autoassist(i){ assist = i; }
query_autoassist(){ return assist; }

query_dragon_level(){ return dragon_level; }
raise_dragon_level(i){
  if(!i) dragon_level++; else dragon_level += i; udate();
}

query_attack_stat(){ return attack; }
raise_attack(i){ if(!i) attack++; else attack += i; udate(); }
query_defense(){ return defense; }
raise_defense(i){ if(!i) defense++; else defense += i; udate(); }
query_stamina(){ return stamina; }
raise_stamina(i){ if(!i) stamina++; else stamina += i; udate(); }
query_magic(){ return magic; }
raise_magic(i){ if(!i) magic++; else magic += i; udate(); }
set_max_sp(n){ max_sp = n; }
add_spell_point(n){ sp = sp + n; if(sp > max_sp) sp = max_sp; }
query_sp(){ return sp; }
query_max_sp(){ return max_sp; }

udate(){
  save_stats();
  configure_dragon();
  return 1;
}

long() {
 if(WHO == owner){
  if(dragon_long == "none") {
    write("You have not created a description for your dragon yet.\n");
    write("IT looks rather drab and unremarkable right now.\n");
    write("Use 'setdescrip' to create your dragon's description.\n");
  }
  else {
    write(dragon_long+"\n");
  }
  write(" Level: "+dragon_level+"\n");
  write(" HP: "+this_object()->query_hp()+"/"+this_object()->query_mhp()+"\n");
  write(" SP: "+sp+"/"+max_sp+"\n");
  write(" Stamina: "+stamina+"\n");
  write(" Magic  : "+magic+"\n");
  write(" Attack : "+attack+"\n");
  write(" Defense: "+defense+"\n");
  write("\n");
  write("Autoassist is ");
  if(assist) write("on.\n"); else write("off.\n");
  write(NME+" will flee at "+wimpy+" hit points.\n");
 }
 else {
  if(dragon_long == "none")
    write("This is a large, rather plain looking dragon.\n");
  else
    write(dragon_long+"\n");
 }
  return;   
}
   
init() {
  ::init();
  add_action("dragon_commands", nme);
  add_action("dragon_commands", "dragg");
}

configure_dragon(){
  object obj;
  string stats, dragon_descrip;
  remove_action(nme);
  obj = present("mageobj", find_player(owner));
  stats = obj->query_dragon_stats();
  dragon_descrip = obj->query_dragon_descrip();
  sscanf(stats, "%s#%d#%d#%d#%d#%d", nme, dragon_level, attack,
  defense, stamina, magic);
  sscanf(dragon_descrip, "%s#%s#%s", dragon_short, dragon_move, dragon_long);
  if(dragon_level < 1) dragon_level = 1;
  sp_list = present("mageobj", find_living(owner))->query_dragon_spells();
  this_object()->set_name(capitalize(nme));
  this_object()->set_level(dragon_level);
  this_object()->set_hp(50 + (stamina*5));
  this_object()->set_wc(10 + (attack/4));
  this_object()->set_ac(0 + (defense/4));
  wimpy = this_object()->query_mhp()/10;
  max_sp = 50 + (magic*5);
  sp = max_sp;
  sp_list = random(3)+1;
  add_action("dragon_commands", nme);
  return 1;
}

save_stats(){
  object obj;

  if(!find_player(owner)){
    destruct(this_object());
    return 1;
  }

  obj = present("mageobj", find_player(owner));
  if(!obj) return;

  obj->set_dragon_stats(
  nme+"#"+dragon_level+"#"+attack+"#"+defense+"#"+stamina+"#"+magic);
  obj->set_dragon_descrip(
  dragon_short+"#"+dragon_move+"#"+dragon_long);

}

dragon_commands(str){
  if(this_player()->query_real_name() == owner){
    DAE->exe_commands(str);
    return 1;
  } else
  return 0;
}

follow(){
  if(!environment(this_object()))
  {
    if(root()) return;
    return destruct(this_object());
  }
  
  while(remove_call_out("follow") != -1);
  if(follow == 1) DAE->follow(owner);
  if((spell_count == 0) || (this_object()->query_hp() <
  this_object()->query_mhp()/5)) report_status();
  if(spell_count == 2) add_spell_point((dragon_level/5)+1);
  if(spell_count == 3){
    DAE->cast_spell(this_object());
    spell_count = 0;
  } else spell_count++;
  call_out("follow", 3);
  return 1;
}

reset_follow() {
  remove_call_out("follow");
  call_out("follow", 3);
  return 1;
}

report_status(){
 if(this_object()->query_attack()){
  tell_object(find_player(owner), MAG+"-=> "+
  "["+HIM+capitalize(nme)+NORM+MAG+"]: "+
  this_object()->query_hp()+"/"+this_object()->query_mhp()+" hp  "+
  sp+"/"+max_sp+" sp\n"+NORM);
 }
}

monster_died() {
  object ob;
  int i;

  /* make sure the owner is still around */
  if(!find_player(owner)) return 0;

  tell_room(environment(this_object()),
  CYN+"\n"+
  NME+"'s body turns to stone and then explodes into thousands of pieces!\n"+
  "You are pelted with dagger-like shards of stone!\n"+NORM);

  /* dragon's death drains owner's spell points */
  tell_object(find_player(owner),
  HIC+NME+"'s death weakens you to the point of exhaustion.\n"+NORM);
  find_player(owner)->add_spell_point(-random(100));

  /* lose a stat just like a player would */
  i = random(4);
  if(i == 0) {
    attack--;
    tell_object(find_player(owner), NME+"'s attack is now "+attack+".\n");
  }
  else if(i == 1) {
    defense--;
    tell_object(find_player(owner), NME+"'s defense is now "+defense+".\n");
  }
  else if(i == 2) {
    stamina--;
    tell_object(find_player(owner), NME+"'s stamina is now "+stamina+".\n");
  }
  else if(i == 3) {
    magic--;
    tell_object(find_player(owner), NME+"'s magic is now "+magic+".\n");
  }

  save_stats();

  /* no corpse to heal off of either */
  if(present("corpse of "+NME, environment(this_object()))) {
    destruct(present("corpse of "+NME, environment(this_object())));
  }

  /* do some damage to everything in the room */
  ob = all_inventory(environment(this_object()));
  for(i=0; i<sizeof(ob); i++) {
   if(ob[i] && ob[i] != this_object())
    ob[i]->hit_player(random(30), "other|earth");
  }

  return 0;
}

