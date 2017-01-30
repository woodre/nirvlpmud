#define ME capitalize(this_player()->query_name())
int closed, locked, empty;
reset(arg){
 if(arg) return;
 empty = 0;
 closed = 1;
 locked = 1;
}
id(str){ return str == "chest" || str == "iron chest"; }
short(){ return "A heavy iron chest"; }
long(){
  write("A heavy iron chest.  The hinges look abit rusted.\n");
  if(closed == 1) write("The chest is closed.\n");
  else write("The chest is open.\n");
  if(locked == 0) write("The chest is unlocked.\n");
  else write("The chest is locked.\n");
  if(closed == 0 && empty == 0) write("There are items in the chest.\n");
  else if(closed == 0 && empty == 1) write("The chest is empty.\n");
  return;
}
query_weight(){ return 999; }
query_value(){ return 0; }
get(){ return 1; }

init(){
 add_action("open","open");
 add_action("unlock","unlock");
 add_action("get_all","get");
}

open(str){
if(str == "chest"){
  if(present("lich", environment(this_object()))){
    write("Lancoz will not let you approach the chest.\n");
    return 1;
    }
  if(locked == 1){
    write("The chest is locked!\n");
    return 1;
    }
  if(closed == 0){
    write("The heavy iron chest is already open!\n");
    return 1;
    }
  write("They key disappears inside the lock.\n");
  write("The rusty hinges squeal noisily as you open the chest.\n");
  say("The rusty hinges squeal noisily as "+ME+" opens the chest.\n");
  destruct(present("duln_key", this_player()));
  closed = 0;
  return 1;
  }
}

unlock(str){
if(str == "chest"){
  if(present("lich", environment(this_object()))){
    write("Lancoz will not let you approach the chest!\n");
    return 1;
    }
  if(!present("duln_key", this_player())){
    write("You do not have the key!\n");
    return 1;
    }
  if(closed == 0){
    write("The chest is already open!\n");
    return 1;
    }
  if(locked == 0){
    write("The chest is already unlocked.\n");
    return 1;
    }
  if(random(10)==8){
    write("You stick the iron key in the lock and twist it.\n");
    write("The old key breaks off in the lock!\n");
    destruct(present("duln_key", this_player()));
    return 1;
    }
  write("You stick the iron key in the lock and twist it.\n");
  write("The lock pops open!\n");
  say(ME+" unlocks the chest.\n");
  locked = 0;
  return 1;
  }
}

get_all(str){
  string what, where;
  if((sscanf(str, "%s %s", what, where)==2) && (where == "from chest")){
  if(present("lich", environment(this_object()))){
    write("Lancoz will not let you approach the chest.\n");
    return 1;
    }
  if(closed == 1){
    write("The chest is closed.\n");
    return 1;
    }
  if(empty == 1){
    write("There is nothing in the chest.\n");
    return 1;
    }
  write("You take everything out of the chest.\n");
  move_object(clone_object("players/pavlik/items/heal_potion"), this_player());
  move_object(clone_object("players/pavlik/items/heal_potion"), this_player());
  move_object(clone_object("players/pavlik/weapons/soultaker"), this_player());
  move_object(clone_object("players/pavlik/items/evil_potion"), this_player());
  this_player()->add_money(3000+random(8000));
  tell_room(environment(this_object()),
  ME+" takes a healing potion from the chest.\n"+
  ME+" takes a healing potion from the chest.\n"+
  ME+" takes the Soultaker from the chest.\n"+
  ME+" takes a bag of gold coins form the chest.\n");
  empty = 1;
  return 1;
  }
}
