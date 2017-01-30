#include "/players/wocket/closed/ansi.h"
inherit "/obj/monster";

int dogcost,catcost,birdcost,snakecost,turtlecost,ratcost;
reset(arg){
    ::reset(arg);
  if(arg) return;
    set_name("ralphio");
    set_alias("keeper");
    set_short(BOLD+"Ralphio"+NORM+", the kennel keeper");
    set_long("Ralphio is a middle-aged man with a small gut that hangs over his\n"+
    "pants.  He wears a apron with a paw print sewn onto it.  His black hair and\n"+
    "round nose allows his gentle smile to glow.  You may ask him for a 'list' of\n"+
    "the pets that you can 'buy'.  Also he can 'put_to_sleep' pets if their owner\n"+
    "can't care for them anymore, or 'resuscitate' the corpse of a lost friend, if\n"+
    "the body is fresh.\n");
    set_level(14);
    set_hp(300);
    set_wc(20);
    set_ac(11);
    get_cost();
    add_money(400);
}

init(){
    ::init();
    add_action("resuscitate", "resuscitate");
    add_action("order","buy");
    add_action("list","list");
    add_action("sleep","put_to_sleep");
}

list(){
    write("Ralphio says: here is my list of the pets:\n");
    write("\n");
    write("  COST          TYPE\n");
    write("  "+dogcost+"\t\tDog\n");
    write("  "+catcost+"\t\tCat\n");
    write("  "+birdcost+"\t\tBird\n");
    write("  "+snakecost+"\t\tSnake\n");
    write("  "+turtlecost+"\t\tTurtle\n");
    write("  "+ratcost+"\t\tRat\n");
    write("\n");
return 1;
}

get_cost(){
  dogcost = 10000+random(10000);
  catcost = 10000+random(10000);
  birdcost = 10000+random(10000);
  snakecost = 10000+random(10000);
  turtlecost = 10000+random(10000);
  ratcost = 10000+random(10000);
}

order(string str){
int cost;
object ob;
string file;
switch(str){
case "dog":
  cost = dogcost;
  break;
case "cat":
  cost = catcost;
  break;
case "bird":
  cost = birdcost;
  break;
case "snake":
  cost = snakecost;
  break;
case "turtle":
  cost = turtlecost;
  break;
case "rat":
  cost = ratcost;
  break;
default:
  notify_fail("Ralphio says: What was that you wanted to buy?\n");
  return 0;
  break;
}
file = "/players/wocket/turtleville/PETS/saves/"+this_player()->query_real_name()+".o";
if(file_size(file) > 1){
    notify_fail("Ralphio says: You already got a pet. Why do you need two?\n");
    return 0;
}

if(this_player()->query_money() < cost){
    notify_fail("Ralphio says: You ain't got the funds.\n");
    return 0;
}

  this_player()->add_money(-cost); 
  ob = clone_object("/players/wocket/turtleville/PETS/neopet.c");
  ob->set_type(str);
  ob->set_master(this_player()->query_real_name());
  move_object(ob,this_object());
  this_player()->recalc_carry();
  write("Ralphio quietly takes your money.\n");
  environment(this_object())->add_pets(this_player()->query_real_name());
  tell_room(environment(this_object()),"Ralphio pulls a "+str+" from a small container.\n");
  tell_room(environment(this_object()),"Ralphio places the "+str+" onto the ground.\n");
  get_cost();
return 1;
}

sleep(str){
string file;
object pet;
  if(!str){
    notify_fail("Ralphio asks: What would you like to put to sleep?\n");
    return 0;
  }
  file = "/players/wocket/turtleville/PETS/saves/"+this_player()->query_real_name()+".o";
  if(!file_size(file)){
    notify_fail("Ralphio says: You don't have a pet to put to sleep.\n");
    return 0;
  }
  if(!present(str,environment(this_object()))){
    notify_fail("Ralphio says: Your pet has to be here so I can put it to sleep.\n");
    return 0;
  }
  pet=present(str,environment(this_object()));
  if(!pet->is_neopet()){
    notify_fail("Ralphio says: "+capitalize(str)+" is not a pet bought from here.  I can't put it to sleep.\n");
    return 0;
  }
  if(pet->query_master() != this_player()){
    notify_fail("Ralphio says: I can't put a pet you don't own to sleep.\n");
    return 0;
  }
  tell_room(environment(this_object()),"With one quick motion Ralphio breaks the neck of "+capitalize(str)+".\n");
  pet->death();
  rm(file);
  "/players/wocket/turtleville/tville_kennel.c"->remove_pets(this_player()->query_real_name());
  tell_room(environment(this_object()),"Ralphio says: Have a nice day.\n");
  return 1;
}

resuscitate(str)
{
 object c, ob;
 
 if(!str)
  {
    notify_fail("Ralphio says: What fine pet would you like to resusciate?\n");
    return 0;
  }
 if(!str || !(c=present(str, this_player())) || !c->is_corpse() &&
    !query_attribute("neopet_corpse", c) ||
    !file_size("/players/wocket/turtleville/PETS/saves/"+
     this_player()->query_real_name()+".o"))
  {
    notify_fail("Ralphio says: You may only resusciate on of my pets that you haven't put to sleep.\n");
    return 0;
 }
 if(this_player()->query_money() < 3500)
 {
    notify_fail("Ralphio says: You need 3500 coins in order ot resuscitate one of my pets.\n");
    return 0;
 }
 tell_room(environment(), "\
Ralphio looks the corpse over fondly and sprinkles a fine\n\
powder across its dead form.\n\n");

 ob = clone_object("/players/wocket/turtleville/PETS/neopet.c");
 ob->set_master(this_player()->query_real_name());
 move_object(ob, environment());

 destruct(c);

 tell_room(environment(),
  BOLD+ob->short()+" has been resurrected!\n"+NORM);

 write("\nGratefully, you give Ralphio 3500 coins for the return\n"+
       "of your lost friend.\n\n");

 this_player()->add_money(-3500);
 return 1;
}
