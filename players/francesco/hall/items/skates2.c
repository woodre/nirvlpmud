#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";
int worn;
object ob;

reset(arg) {
set_name("skates");
set_alias("skates");
set_short("A pair of women's skates");
set_long(
   "These skates are specially designed for figure skating.  They allow for\n"+
   "fast stops and turns, yet maintaining high directionality and speed.\n");
set_ac(2);
set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(1);
set_value(350);
}

init() {
::init();
  add_action("trade","trade");
  add_action("wear","wear1");
  return 1;
}
trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="skates"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  This is not exactly my business anymore\n"+
           "and therefore I can only give you 4600 coins for this "+(str)+".\n");
      call_other(this_player(),"add_money",(4600));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

wear(str) {
  if(!str) {notify_fail("Wear what?\n"); return 0;} 
   if(!id(str) || environment() != this_player() || worn) return 0;
   if(this_player()->query_gender()=="female"){
   ::wear(str);
   return 1; }
   else 
    {notify_fail("Ouch, they dont fit your foot.\n"); 
  return 0;}
return 0; }


query_save_flag() { return 1; }
