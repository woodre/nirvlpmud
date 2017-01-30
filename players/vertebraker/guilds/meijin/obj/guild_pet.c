inherit "/obj/monster";
#include "/players/vertebraker/guilds/meijin/defs.h"
#define DAE "players/pavlik/guild/pet-daemon.c"
#define NME capitalize(nme)

/*
 * It takes 4.4 Million XP points to fully train a Dragon!
 */

string owner;				/* owner if this pet */
string nme;				/* pet's name */
string pet_long, pet_short;		/* descrip */
string pet_move;			/* mmout/mmin */
int pet_level;				/* level */
int attack, defense;			/* determines pet's wc and ac */
int stamina;				/* determines hps */
int follow;				/* follow toggle */
int wimpy;				/* pet wimpy */
int assist;				/* autoassist toggle */

reset(arg){
  ::reset();
  if(arg) return;
  set_name("Ten");
  set_short("Dragon");
  set_ep(0);
  set_alias("pet");
  set_can_kill(1);
  set_ac(0);
  set_wc(10);
  set_hp(50);
  set_level(1);
  set_dead_ob(this_object());
  nme = "ten";
  owner = "Nobody";
  pet_long = "none";
  pet_short = "the";
  pet_move = "stomps";
  pet_level = 1;
  attack = 1;
  defense = 1;
  stamina = 1;
  follow = 1;
  assist = 1;
  enable_commands();
  call_out("fake_beat", 3);
}

short(){ return NME+" "+pet_short+" Dragon"; }

id(str) {
  return str == nme || str == owner+"'s meijin_pet" || str == "dragon" ||
  str == owner+"'s pet" || str == "meijin_pet";
}

query_npc(){ return 0; }
is_pet(){ return 1; }
query_meijin_pet(){ return 1; }

set_nme(str){ nme = str; }
query_nme(){ return nme; }

set_owner(str){ owner = str; }
query_owner(){ return owner; }

set_follow(n){ follow = n; }
query_follow(){ return follow; }

add_exp(i){ if(find_player(owner)) find_player(owner)->add_exp(i/5); }

set_pet_long(str){ pet_long = str; }
query_pet_long(){ return pet_long; }

set_pet_short(str){ pet_short = str; }
query_pet_short(){ return pet_short; }

set_pet_move(str){ pet_move = str; }
query_pet_move(){ return pet_move; }

set_wimpy(i){ wimpy = i; }
query_wimpy(){ return wimpy; }

set_autoassist(i){ assist = i; }
query_autoassist(){ return assist; }

query_pet_level(){ return pet_level; }
raise_pet_level(i){
  if(!i) pet_level++; else pet_level += i; update_pet();
}

summon_pet() {
  follow = 1;
  reset_fake_beat();
}

/*************/
/* PET STATS */
/*************/
query_attack_stat() { return attack; }
raise_attack(i) { if(!i) attack++; else attack += i; update_pet(); }
query_defense() { return defense; }
raise_defense(i) { if(!i) defense++; else defense += i; update_pet(); }
query_stamina() { return stamina; }
raise_stamina(i) { if(!i) stamina++; else stamina += i; update_pet(); }

update_pet(){
  save_stats();
  configure_pet();
  return 1;
}

long() {
  if(this_player() == find_player(owner)) {
    if(pet_long == "none") {
	write("You have not created a description for your Dragon yet.\n");
	write("It looks rather drab and unremarkable right now.\n");
	write("Use 'setdescrip' to create your pet's description.\n");
    }
    else {
	write(pet_long+"\n");
    }
    write("   "+pad("Level: "+pet_level, 20));
    write(" Stamina: "+stamina+"\n");
    write("   "+pad("HP: "+this_object()->query_hp()+"/"+this_object()->query_mhp(), 20));
    write(" Attack : "+attack+"\n");
    write("   "+pad(" ", 20));
    write(" Defense: "+defense+"\n");
    write("\n");
    write("Autoassist is ");
    if(assist) write("on.\n"); else write("off.\n");
    write(NME+" will flee at "+wimpy+" hit points.\n");
  }
  else {
    if(pet_long == "none") write("This is a plain looking Dragon.\n");
    else write(pet_long+"\n");
  }
  return;   
}
   
init() {
  ::init();
  add_action("pet_commands", nme);
  add_action("pet_commands", "dragg");
  add_action("no_taunt", "taunt");   /* so players cant start fight */
}

no_taunt(str) {
  if(id(str)) {
	write(NME+" completely and utterly ignores you.\n");
	say(NME+" ignores "+capitalize(this_player()->query_name())+"'s taunts.\n");
	return 1;
  }
}

configure_pet(){
  object obj;
  string stats, pet_descrip;

  if(!find_player(owner)) return 0;
  obj = present("pavlik_guild_obj", find_player(owner));
  if(!obj) return 0;
  
  remove_action(nme);
  stats = obj->query_pet_stats();
  pet_descrip = obj->query_pet_descrip();

  sscanf(stats, "%s#%d#%d#%d#%d", nme, pet_level, attack, defense, stamina);
  sscanf(pet_descrip, "%s#%s#%s", pet_short, pet_move, pet_long);
  this_object()->set_name(capitalize(nme));
  this_object()->set_level(pet_level);
  this_object()->set_hp(50 + (stamina*3));	/* max 200 */
  this_object()->set_wc(2 + (attack/4));	/* max 17 */
  this_object()->set_ac(0 + (defense/5));	/* max 12 */
  wimpy = this_object()->query_mhp()/10;
  add_action("pet_commands", nme);

  return 1;
}

save_stats(){
  object obj;

  if(!find_player(owner)){
	destruct(this_object());
	return 1;
  }
  if(!(obj=present("pavlik_guild_obj", find_player(owner)))) return 0;
  obj->set_pet_stats(
  nme+"#"+pet_level+"#"+attack+"#"+defense+"#"+stamina);
  obj->set_pet_descrip(
  pet_short+"#"+pet_move+"#"+pet_long);
}

pet_commands(str){
  if(this_player()->query_real_name() == owner){
	DAE->exe_commands(str);
	return 1;
  }
}

fake_beat(){
  if(follow == 1) DAE->follow(owner);
  call_out("fake_beat", 3);
  return 1;
}

reset_fake_beat() {
  remove_call_out("fake_beat");
  call_out("fake_beat", 3);
  return 1;
}

monster_died() {
  object ob, obj;
  int i;

  /* make sure the owner is still around */
  if(!(obj = find_player(owner))) return 0;
  if(!obj->query_interactive()) return 0;

  tell_room(environment(this_object()), CYN+"\n"+
  NME+"'s body turns to stone and then explodes into thousands of pieces!\n"+
  "You are pelted with dagger-like shards of stone!\n\n"+NORM);

  /* Owner suffers extra damage from pet dying. */
  tell_object(obj, HIC+"You are weakened by "+NME+"'s death.\n"+NORM);
  obj->hit_player(random(50));

  /* lose a stat just like a player would */
  switch (random(3)) {
    case 0 :
	attack--;
	tell_object(obj, NME+"'s attack is now "+attack+".\n");
	break;
    case 1 :
	defense--;
	tell_object(obj, NME+"'s defense is now "+defense+".\n");
	break;
    case 2 :
	stamina--;
	tell_object(obj, NME+"'s stamina is now "+stamina+".\n");
	break;
  }

  save_stats();

  /* no corpse to heal off of either */
  if(present("corpse of "+NME, environment(this_object()))) {
	destruct(present("corpse of "+NME, environment(this_object())));
  }

  /* do some damage to everything in the room */
  ob = all_inventory(environment(this_object()));
  for(i=0; i<sizeof(ob); i++) {
	ob[i]->hit_player(random(30));
  }

  return 0;
}

