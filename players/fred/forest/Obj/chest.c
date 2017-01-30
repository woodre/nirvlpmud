inherit "/obj/treasure.c";
int opened;

reset(arg) {
 opened = 0;
 set_id("chest");
 set_long("A small treasure chest with intricate designs carved into the sides.\n");}
init(){
  ::init();
  add_action("open_chest", "open"); } 
open_chest(str){
object money;
if(!str){ write("Open what?\n"); return 1; }

if(str == "chest"){
if(present("drablo", environment(this_object()))){
  write("Drablo steps in front of you blocking the chest.\n");
  return 1;
  }
if(opened){
write("The chest is already open!\n");
return 1;
}
opened = 1;
money = clone_object("obj/money");
money->set_money(3000 + random(500));
move_object(money, (this_object()));
write("You open the chest, light reflects off the coins blinding you!\n");
say(this_player()->query_name() + " opens the chest.\n");
return 1;
}
write("Open what?\n");
return 1;
}
query_weight() {
return 50000; 
}
can_put_and_get(){ return 1; }