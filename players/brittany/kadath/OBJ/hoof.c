inherit "/obj/treasure.c";

object item;
reset(arg){
if(arg)return;
 
  set_id("ghast's hoof");
  set_alias("hoof");
  set_short("A ghast's hoof");
  set_long(
"This is a sharp-edged hoof, the merchant would trade it for a decent\n"+
"weapon if you 'choose', or he might give you a decent price if you\n"+
"'trade' it.\n");
  set_weight(3);
  set_value(500+random(250));
}
init() {
  ::init();
  add_action("cmd_cash","trade");
  add_action("choose_weapon","choose");
}
cmd_cash(str) {
  if(!str || str!="hoof") {
    notify_fail("Trade what?\n");
    return 0;
  }
  if(!present("trader",environment(this_player()))) {
  notify_fail("There is nobody here who wants to trade that.\n");
  return 0;
  }

write("The merchant looks over your item, then trades you "+(value+1750)+"\n"+
      "coins which is a fair price.\n");
  this_player()->add_money(value+1750);
  destruct(this_object());
  this_player()->recalc_carry();
  return 1;
}

choose_weapon(str){
object item;
if(!str || str!="weapon") {
  notify_fail("What do you want to choose?\n");
  return 0;
}
if(!present("trader",environment(this_player()))){
  write("The merchant is not here.\n");
return 1; }
  write("The merchant takes the hoof, looks it over, cackles demonically,\n"+
        "then hands you a boomerang.\n");
item = clone_object("/players/brittany/kadath/OBJ/boomerang.c");
move_object(item,this_player()); destruct(this_object());           
return 1; }
