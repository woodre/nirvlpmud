/* Approved 6/15/2000 - Feldegast */

#include "/players/wocket/closed/ansi.h"
inherit "/obj/treasure.c";
int dropable;
drop(){ return dropable; }

static string NAME;
int drink,count;
reset(arg){
  if(arg) return;
set_id("potion");
set_alias("regen");
set_short(GRN+"A mysterious potion of regeneration"+NORM);
set_long("An elongated flask holding a mysterious potion.  The crystal sparkles as\n"+
"the fluid inside swirls its dark green tentacles.  You may wish\n"+
"to 'drink' the potion.\n");
set_value(10000);
set_weight(1);
count = drink = 0;
}
init(){
  add_action("drink","drink");
}

drink(string str){
if(drink == 1){
    return 0;
}
if(!str){
    notify_fail("What would you like to drink?\n");
    return 0;
  }
if(str != "potion" && str != "regen"){
  notify_fail("You do not have that to drink.\n");
    return 0;
  }

if(present("usedregen",this_player())){
  write("You are already healing from a regen potion.\n");
  return 1;
}
write("You drink the magical potion.\nThe fluid rushes through your veins refreshing you.\nYou smash the empty flask.\n");
say(this_player()->query_name()+" drinks a potion.\n");
NAME = this_player()->query_real_name();
call_out("combat_check",3);
set_weight(0);
dropable = 1;
set_short();
set_long();
drink = 1;
set_id("usedpotion");
set_alias("usedregen");
this_player()->recalc_carry();
return 1;
}

combat_check(){
if(count < 30){
  find_player(NAME)->add_hit_point(13);
  tell_object(find_player(NAME),"You body begins to regenerate from its wounds.\n");
  count++;
  call_out("combat_check",6);
}
else {
tell_object(find_player(NAME),"You lose the power to regenerate.\n");
NAME = "";
destruct(this_object());
}
}

/* Made unstorable 5/99 -Snow */
query_save_flag() { return 1; }
