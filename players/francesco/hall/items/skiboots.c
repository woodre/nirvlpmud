#include "/players/francesco/univ/ansi.h"
inherit "obj/armor";

int delay;
int actual_time;

reset(arg) {
set_name("skiboots");
set_alias("boots");
set_short("Skiboots");
set_long(
   "These ski boots have been thouroghly tested by Alberto Tomba which \n"+
   "chose them when he won the Olympics in Albertville, 1992.  They provide\n"+
   "excellent protection even though their weight might cause troubles \n"+
   "in the movements.  And, sides, even though it is not their proper use,\n"+
   "why not use them to 'stomp' someone?  Something can be 'view'ed on\n"+
   "its 'sole'.\n");
set_ac(2);
set_type("boots");  /* armor,helmet,boots,ring,amulet,shield,misc  */
set_weight(2);
set_value(350);
}

query_save_flag() { return 1; }

init() {
:: init();
  add_action("trade","trade");
  add_action("stomp","stomp");
  add_action("read","read");
  add_action("view","view");
  return 1;
}

trade(str){
  if(!str) {
  notify_fail("What do you want to trade?\n");
  return 0; }
    if(str=="skiboots" || str=="boots" || str == "ski boots"){
       if(!present("narrator",environment(this_player()))){
         write("The "+(str)+" cannot be traded in this room.\n");
       return 1;}
      write("The narrator replies:  'Thank you, thank you, I always\n"+
            "wanted to have a reminder of the great Alberto Tomba\n"+
            "and now I am very happy that you brought this skiboots to\n"+
            "me.  Please, take these coins as a sincere mark of thanks.'\n");    
      call_other(this_player(),"add_money",(4550));
      destruct(this_object());
    return 1;}
  notify_fail("That is not something you can trade here.\n");
  return 0;
}

view(str) {       
if(environment() != this_player()) {notify_fail("You must get the skboots first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to view?\n"); return 0; }
   if(str=="sole")  {write("On the sole there are some engravings to read.\n"); return 1;}
   notify_fail("What do you want to view?\n"); return 0; 
return 1;
}

read(str) {       
if(environment() != this_player()) {notify_fail("You must get the snowhoe first.\n"); return 0;}
  if(!str) { notify_fail("What do you want to read?\n"); return 0; }
   if(str=="engravings")  {write("Return it to Runi, the narrator.  \nHe will appreciate.\n\nSincerely, \nAlberto Tomba\n"); return 1;}
   notify_fail("What do you want to read?\n"); return 0; 
return 1;
}

stomp() {
  object attacker;
  attacker=this_player()->query_attack();
  if(!worn) { write("Ah Ah,  wear those skiboots before stomping someone!\n"); 
  return 1; }
  if(this_player()->query_sp() < 20) { write("You are out of spell points, heal yourself!\n"); 
  return 1; }
  if(!attacker) { write("You aren't fighting anybody!\n"); 
  return 1; }
  actual_time = time();
  if(actual_time - delay <= 1)
  return 1;
  if(this_player()->query_spell_dam()) { 
    write("You are already using energy to power a spell.\n"); 
    return 1; }
   if(random(2))
   this_player()->spell_object(attacker,"skiboots stomping",random(30)+5,20,
        "You stomp "+attacker->query_name()+" into a puddle of slush.\n");
   else
   this_player()->spell_object(attacker,"skiboots stomping",random(6)+5,10,
        "You stomp "+attacker->query_name()+" into a puddle of slush.\n");
  delay = time();
  return 1; 
}


