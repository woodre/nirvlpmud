#include "/players/maledicta/ansi.h"

int blocked;
string owner;

drop(){ return 1; }
get(){ return 0; }
is_castle(){ return 1; }
query_weight(){ return 10000000; }
query_value(){ return 0; }


reset(arg){
 if(arg) return;

call_out("dest_this", 300);
}

clean_up(){ return 1; }

dest_this(){
if(!owner) return;
remove_call_out("dest_this");
if(!find_living(owner)) { destruct(this_object()); return; }
call_out("dest_this", 300);
}


short(){
if(!this_player()) return "A NeoSymbiote Cave"; /* err... that was lame. [7.8.01] by verte */
if(this_player()->query_level() > 21) return owner ? owner + "'s NeoSymbiote Cave" : "Someone's NeoSymbiote Cave";  /* by verte [7.8.01] */
if(present("link_comm", this_player())){
 if(present("link_comm", this_player())->query_slave_master() == owner){
  return "A small crevice in the ground";
  }
}
   if(environment(this_player()) != environment()) return "A small crevice"; /* by verte [7.8.01] */
}

long(){
if(environment(this_player()) == this_object()){
  write(
  "  This is a large underground chamber.  The walls are\n"+
  "covered in living Dark Matter which glistens and shifts\n"+
  "in the light. A single exit leads out.\n");
  if(this_player()->query_real_name() == owner){
    write("As the owner of the cave you may do the following:\n"+
          "close crevice   - block the entrance and exit\n"+
          "open crevice    - unblock the entrance and exit\n");
          }
  write("    There is one obvious exit: out\n");
  return 1;
  }
  else{
   write("This is a small crevice that cuts through the ground. You feel\n"+
         "that you might be able to 'squeeze' into it.\n");
   return 1;
   }
return 0;
}

id(str){ return str == "cave" || str == "symbiote_cave" || str == "crevice"; }

init(){
 if(!environment()) return;
 add_action("enter_cave", "squeeze");
 add_action("block_cave", "close");
 add_action("unblock_cave", "open");
 add_action("leave_cave", "out");
if(this_player())
if(environment(this_player()) == this_object())
 this_player()->set_fight_area();
}


query_cave_owner(){ return owner; }
set_cave_owner(str){ owner = str; }

query_blocked(){ return blocked; }

leave_cave(){
if(environment(this_player()) != this_object()) return 0;
if(blocked){
 write("The crevice is closed!\n");
 return 1;
 }
tell_room(environment(this_player()),
this_player()->query_name()+" leaves out.\n");
move_object(this_player(), environment(this_object()));
command("look", this_player());
return 1;
}

exit(){    if(this_player()) this_player()->clear_fight_area();     }

block_cave(str){
 if(!str) return 0;
 if(!present("link_comm", this_player())) return 0;
 if(str != "crevice"){
   write("block what?\n");
   return 1;
   }
 tell_object(this_player(), 
 "You concentrate and will the cave to close its entrance...\n");
 blocked = 1;
 return 1; 
}

unblock_cave(str){
 if(!str) return 0;
 if(!present("link_comm", this_player())) return 0;
 if(str != "crevice"){
   write("unblock what?\n");
   return 1;
   }
 tell_object(this_player(), 
 "You concentrate and will the cave to open its entrance...\n");
 blocked = 0;
 return 1; 
}


enter_cave(str){
 if(!str) return 0;
 if(environment() != environment(this_player())) return 0;
 if(str != "into crevice"){
  write("squeeze into what?\n");
  return 1;
  }
 if(blocked && blocked != this_player()->query_real_name()){
   write("The crevice is closed...\n");
   return 1;
   }
 if(this_player()->query_attack()){ write("You can't while you are fighting!\n"); return 1; }
 
 tell_object(this_player(),
 "You squeeze into the crevice...\n");
 tell_room(environment(this_player()),
 this_player()->query_name()+" disappears from sight...\n", ({ this_player() }));
 move_object(this_player(), this_object());
 command("look", this_player());
 return 1;
 }

no_hunter(){ return 1; }
query_symb_cave(){ return 1; }
