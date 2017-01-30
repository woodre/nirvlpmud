/* 03/06/06 Earwax: Closed templar entrance off, too many issues with ghall right now. */

#include "/obj/ansi.h"

id(str){ return str == "castle" || str == "city_object" || str == "tower"; }

short(){ return HIY+"The Tower of Hope"+NORM+".\n"+
                "Templar Castle [enter castle]"; }


long(str){
if(str == "tower"){
write(
"Before you stands the Tower of Hope. It was constructed by the Knights\n"+
"Templar in support of its allies.\n");
return 1;
}
else{
write("This is the home of the Templars.\n");
return 1;
}
}
        
get(){ return 0; } 
query_weight(){ return 100000; }
query_value(){ return 0; }

init(){
   add_action("enter_tower","enter");
/*
add_action("cmd_restore","restore");
*/
   }

enter_tower(str){
if(!str){
write("Enter what?\n");
return 1;
}
if(str == "castle"){
  /* 03/06/06 Earwax: Closed this off, too many issues with ghall right now. */
  if (this_player()->query_guild_name() != "Knights Templar" && !present("KnightInvite", this_player())) {
    write("\
Only Knights and those invited to the castle may enter.  Sorry for\n\
any inconvenience, but maintenance must occur before it will reopen.\n");
    return 1;
  }
  tell_room(environment(this_player()),
  this_player()->query_name()+" enters the castle.\n", ({ this_player() }));
  tell_object(this_player(),
  "You enter the castle.\n");
    move_object(this_player(), "/players/jaraxle/templar/rooms/path.c");
  command("look", this_player());
  tell_room(environment(this_player()),
  this_player()->query_name()+" arrives.\n", ({ this_player() }));
  return 1;
  }
if(str == "tower"){
  tell_room(environment(this_player()),
  this_player()->query_name()+" enters the Tower of Hope.\n", ({ this_player() }));
  tell_object(this_player(),
  "You enter the Tower of Hope.\n");
    move_object(this_player(), "/players/jaraxle/hope/rooms/hmain.c");
  command("look", this_player());
  tell_room(environment(this_player()),
  this_player()->query_name()+" arrives.\n", ({ this_player() }));
  return 1;
  }
write("Enter what?\n");
return 1;
}



cmd_restore(arg) {
object jj;
object ob;

if(present("KnightTemplar"),this_player()){
   write("You already have your cross!\n");
return 1; }

if(this_player()->query_guild_name() != "Knights Templar"){
write("You do not need a cross.\n");
return 1; }

if(!arg || arg != 786) {
  save_ob();
  jj=clone_object("/players/boltar/templar/templar.c");
  move_object(jj,environment(this_player()));
  jj->refresh(786);
  destruct(this_object());
  return 1;
  }
}

