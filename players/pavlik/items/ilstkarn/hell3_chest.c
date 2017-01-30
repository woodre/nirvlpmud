#define ME capitalize(this_player()->query_name())

int closed, locked;

reset(arg){
 object ob;
 if(arg) return;
 move_object(clone_object("players/pavlik/items/heals/wand_of_healing"),
 this_object());
 move_object(clone_object("players/pavlik/items/ilstkarn/demonbane_gem"),
 this_object());
 ob = clone_object("obj/money");
 move_object(ob, this_object());
 ob->set_money(3000+random(3000));
 ob = clone_object("players/pavlik/items/ilstkarn/ammo_box");
 move_object(ob, this_object());
 ob->add_ammo(1000+random(1000));
 closed = 1;
 locked = 1;
}

id(str){
  return str == "chest" || str == "iron chest" || str == "hell3_chest";
}

short(){
  return "A heavy iron chest";
}

long(){
  write("A heavy iron chest.  The hinges look abit rusted.\n");
  if(closed == 1) write("The chest is closed.\n");
  else write("The chest is open.\n");
  if(locked == 0) write("The chest is unlocked.\n");
  else write("The chest is locked.\n");
  if(closed) return 1;
}

query_weight(){ return 999; }

add_weight(x) { return 1; }

query_value(){ return 0; }

get(){ return 1; }

prevent_insert() {
  if(closed) return 1;
  else return 0;
}

can_put_and_get() {
  if(closed) return 0;
  else return 1;
}

init(){
 add_action("open","open");
 add_action("close","close");
 add_action("unlock","unlock");
 add_action("lock","lock");
}

open(str){
  if(str == "chest"){
    if(locked == 1){
      write("The chest is locked!\n");
      return 1;
    }
    if(closed == 0){
      write("The iron chest is already open!\n");
      return 1;
    }
    write("The rusty hinges squeal noisily as you open the chest.\n");
    say("The rusty hinges squeal noisily as "+ME+" opens the chest.\n");
    closed = 0;
    return 1;
  }
}

close(str) {
  if(id(str)) {
    if(closed) {
      write("The chest is already closed.\n");
      return 1;
    }
    write("You close the chest.\n");
    say(ME+" closes the heavy iron chest.\n");
    closed = 1;
    return 1;
  }
}

unlock(str){
  if(str == "chest"){
    if(!present("hell3_chest_key", this_player())){
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
    if(random(30)==13){
      write("You stick the gold key in the lock and twist it.\n");
      write("The fragile key breaks off in the lock!\n");
      say(ME+" tries to unlock the chest, but the key breaks!\n");
      this_player()->add_weight(-1);
      destruct(present("hell3_chest_key", this_player()));
      return 1;
    }
    write("You stick the golden key in the lock and twist it.\n");
    write("The key disappears in the lock and it pops open!\n");
    say(ME+" unlocks the chest.\n");
    this_player()->add_weight(-1);
    destruct(present("hell3_chest_key", this_player()));
    locked = 0;
    return 1;
  }
}

lock(str) {
  if(id(str)) {
    if(locked) {
      write("The chest is already locked.\n");
      return 1;
    }
    if(!closed) {
      write("You must close it first.\n");
      return 1;
    }
    write("You lock the heavy iron chest.\n");
    say(ME+" locks the heavy iron chest.\n");
    locked = 1;
    return 1;
  }
}

