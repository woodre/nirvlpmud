#include "/players/fred/mages/defs.h"

inherit "obj/monster";
int st,stalk, follow;
object stalkee, owner;

set_follow(n) { follow = n; }

query_follow(n) { return follow; }

set_owner(o){ owner = o; }

init(){
 ::init();
  add_action("follow","stalk");
  add_action("dismiss","dismiss");
}

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("dark stalker");
  set_alias("dark_stalker_bug");
  set_race("stalker");
  set_short("Dark Stalker the Adept's Minion (opaque)");
  set_aggressive(0);
  set_level(5);
  set_hp(10);
  set_al(-1000);
  set_wc(5);
  set_ac(2);
  }

long(){
  write("Dark Stalkers have long Served Black Circle Adepts.\n");
  if(TP == owner){
    write("You can command it to 'stalk <name>' or you can 'dismiss' it.\n");
  }
  return 1;
 }

follow(str){     
  if(!str) { write("Who would you like to stalk?\n"); return 1; }
  if(present("dark_circle", TP)){
   owner = this_player();
   stalkee = find_player(str);     
     if(!stalkee){
       write("That player isn't on.\n"); return 1;}
     if(stalkee->query_level() > 20){
       write("Your Dark Stalker cannot stalk wizzes.\n"); return 1;}
     if(owner->query_level() < stalkee->query_level()){
       write("Your Dark Stalker cannot stalk those more powerful than it's master.\n"); return 1;}
     say("Dark Stalker stalks off after his victim.\n");
   show_me(stalkee);
   return 1;}
 return 0; }
      
dismiss(){
  if(owner == this_player()){         
    say("Dark Stalker says: I return to the Plane of Shadows.\n");
    say("Dark Stalker leaves this dimension.\n");
    destruct(TO);
    return 1;}        
   return 0;}                                                                                                                                        

show_me(stalkee){
  object ob, special;
  stalkee->long();
  special=first_inventory(stalkee);
  while(special) {
    string extra_str;
    extra_str=special->extra_look();
    if(extra_str)
       write(extra_str+".\n");
    special=next_inventory(special);
    }
  write(capitalize(stalkee->query_pronoun())+" is carrying: \n");
  ob = first_inventory(stalkee);
   while (ob) {
    string sh;
    sh = call_other(ob, "short");
    if (sh)
    write(sh + ".\n");
    ob = next_inventory(ob);
  }
  return 1;
}


