inherit "/obj/treasure.c";
int opened;

reset(arg) {
 opened = 0;
 set_id("sack");
 set_short("A sack");
 set_long("A small sack that might contain a few coins.\n");
 set_weight(1);
 set_value(50); 
 }

query_save_flag(){
  return 1; 
}

init(){
  ::init();
  add_action("open_sack", "open"); } 

open_sack(str){
object money;
if(!str){ write("Open what?\n"); return 1; }
if(str == "sack"){
if(opened){
write("The sack is already open!\n");
return 1;
}
opened = 1;
money = clone_object("obj/money");
money->set_money(250 + random(100));
move_object(money, (this_object()));
write("You open the small sack.\n");
say(this_player()->query_name()+ " opens a small sack.\n");
return 1;
}
write("Open what?\n");
return 1;
}
can_put_and_get(){
return 1;
} 
