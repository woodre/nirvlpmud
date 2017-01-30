#include "/players/pavlik/guild/mages/rooms/ROOMS"
#define rlname this_player()->query_real_name()
#define ME capitalize(this_player()->query_real_name())
#define IT capitalize(obj->query_name())
inherit "room/room";
  object obj;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Dragon Room";
long_desc=
"Huge deep gashes mark nearly every inch of every wall of this chamber.\n"+
"This deep chamber below the Tower is home of Vrideen, the Dragon Master.\n"+
"Several large whips and other more strange 'training implements' are\n"+
"stowed neatly in the corner.  There is a scorched piece of wood with\n"+
"writing on it on the southern wall.\n";
items=({
"wood",
"Vrideen the Dragon Master: \n"+
"   train <stat> \n"+
"   cost <stat> \n"+
" notice: your dragon Must be present",
"sign",
"Vrideen the Dragon Master: \n"+
"   train <stat> \n"+
"   cost <stat> \n"+
" notice: your dragon Must be present",
});

dest_dir=({
  "players/pavlik/guild/mages/rooms/summon_room", "east",
});

if(!present("vrideen", this_object())){
  obj = clone_object("players/pavlik/guild/mages/rooms/npc/vrideen");
  move_object(obj, this_object());
  }
  
  }
}
realm(){ return "NT"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("train_dragon","train");
  add_action("cost_stat","cost");
  mage_check();
}

cost_stat(str){
  object ob, obj;
  int cost, money;

  if(!str){
    write("Vrideen croaks: What?\n");
    return 1;
    }
  obj = present(rlname+"'s dragon", this_object());

  if(!obj){
    write("Vrideen croaks: You must have the pet here!\n");
    return 1;
    }
  cost = get_cost(obj, str);
  if(str == "attack" || str == "defense") money = 750;
  else if(str == "stamina" || str == "magic") money = 750;
  else if(str == "level") money = 5000;
  else {
    write("Vrideen croaks: I don't understand what yer sayin'.\n");
    return 1;
    }
  write(
  "Vrideen croaks: I will cost you "+cost+" xp and "+money+" gold coins\n"+
  "                to train "+IT+" in "+str+".\n");
  return 1;
}  

get_cost(obj, stat){
  int much, cost;

  if(stat == "attack"){
    much = obj->query_attack_stat();
    cost = much * 1100;
  } else if(stat == "defense"){
    much = obj->query_defense();
    cost = much * 1100;
  } else if(stat == "stamina"){
    much = obj->query_stamina();
    cost = much * 2250;
  } else if(stat == "magic"){
    much = obj->query_magic();
    cost = much * 2250;
  } else if(stat == "level"){
    much = obj->query_dragon_level();
    cost = much * 10000;
  } else cost = 0;
  return cost;
}

train_dragon(str){
  object ob, obj;
  int mxp, cost, money;

  if(!str){
    write("Vrideen croaks: What?\n");
    return 1;
    }

  obj = present(rlname+"'s dragon", this_object());
  if(!obj){
    write("Vrideen croaks: You must have the pet here.\n");
    return 1;
    }

  money = 750;
  cost = get_cost(obj, str);
  if(str == "level"){
    if(obj->query_dragon_level() >= 20){ maxed_out(); return 1; }
    money = 5000;
  } else if(str == "attack"){
    if(obj->query_attack_stat() >= 60){ maxed_out(); return 1; }
  } else if(str == "defense"){
    if(obj->query_defense() >= 60){ maxed_out(); return 1; }
  } else if(str == "stamina"){
    if(obj->query_stamina() >= 50){ maxed_out(); return 1; }
  } else if(str == "magic"){
    if(obj->query_magic() >= 40){ maxed_out(); return 1; }
  } else {
    write("Vrideen croaks: What?\n");
    return 1;
  }

  if(cost > present("mageobj", this_player())->query_spendable_exp()){
    write("Vrideen croaks: You don't have the experience.\n"+
          "                Come back some other time.\n");
    return 1;
    }

  if(money > this_player()->query_money()){
    write("Vrideen croaks: You can't afford my training.\n"+
          "                Come back some other time.\n");
    return 1;
    }

  write("Vrideen trains "+IT+" in "+str+".\n");
  if(str == "level") obj->raise_dragon_level();
  else if(str == "attack") obj->raise_attack();
  else if(str == "defense") obj->raise_defense();
  else if(str == "stamina") obj->raise_stamina();
  else if(str == "magic") obj->raise_magic();
  this_player()->add_guild_exp(-cost);
  this_player()->add_money(-money);
  return 1;
}
    
maxed_out(){
  write("Vrideen says: I have taught all I can to this dragon.\n");
  return 1;
}
