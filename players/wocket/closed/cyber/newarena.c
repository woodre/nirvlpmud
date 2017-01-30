#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/std/tvroom.c";

reset(arg){
  if(arg) return;
short_desc = HIY+"CyberNinja Arena"+NORM;
long_desc = "   "+
"This is the CyberNinja Arena.  A large white mat lines\n"+
"the floor leading to the east and west.  Red lines mark\n"+
"boundries upon the mat.  Beyond that pads for the kneeling\n"+
"judges lay.  Above are balcony sitting for those who wish\n"+
"to spectate the events.  Two short red lines mark the center\n"+
"of the mat.\n";
items = ({
"lines","They are red and mark the boundries of the mat",
"mat","This is a large white padded mat for combat",
"pads","They are soft cushions that line the mat",
"balcony","A well crafted balcony that overhangs the arena",
"sitting","A well crafted balcon that overhangs the arena",
});
listens = ({
"default","The sounds of cheering and betting can be heard",
});
smells = ({
"default","You smell sweat and blood",
});
dest_dir = ({
"/players/wocket/closed/cyber/newarenab.c","east",
"/players/wocket/closed/cyber/newarenac.c","west",
"to/get/exit/listing/blah","leave",
});
set_light(1);
enable_commands();
}

catch_tell(str){
string who,period;
object ob,next;
object corpse;
tell_room("/players/wocket/closed/cyber/a_balcony",HIR+"In the arena "+NORM+str);
if(sscanf(str,"%s died%s",who,period)==2){
call_out("revive_player",1);
}
}

revive_player(){
object ob,next,corpse;
  ob = first_inventory(this_object());
while(ob){
next = next_inventory(ob);
  if(ob->query_ghost()){
say(HIR+"*~*  "+capitalize(ob->query_real_name())+" has been defeated.\n"+NORM);
tell_object(this_object(),HIR+capitalize(ob->query_real_name())+" has been defeated.\n"+NORM);
say(ob->query_name()+" blows to recovery.\n");
tell_object(this_object(),ob->query_name()+" blows to recovery.\n");
move_object(ob,"/players/wocket/closed/cyber/arenastasis.c");
command("glance",ob);
    if(present("corpse",this_object())){
      corpse = present("corpse",this_object());
      move_object(corpse,"/players/wocket/closed/cyber/arenastasis.c");
      command("get all from corpse",ob);
      destruct(corpse);
    }
  }
ob = next;
}
}

init(){
  ::init();
add_action("leave","leave");
add_action("newquit","quit");
if(this_player()->is_player()){

   if(!(this_player()->query_pl_k() >= 2)){
move_object(this_player(),"/players/wocket/closed/cyber/a_entrance.c");
write(HIR+"*~*  You do not have your 'kill_players spar' set.\n"+NORM);
write(HIR+"*~*  You have been moved to the lounge.\n\n"+NORM);
}
}
}

exit(){
if(this_player()->is_player()){
if(query_verb() && (query_verb() == "east" || query_verb () == "west"))
return 1;  
this_player()->rm_spar();
}
return 1;
}

leave(){
  if(this_player()->query_attack()){
    notify_fail(HIR+"*~*  You can not leave while in combat.\n"+NORM);
    return 0;
  }
this_player()->move_player("the CyberNinja Arena#/players/wocket/closed/cyber/a_entrance");
return 1;
}

newquit(){
write(HIR+"*~*  You may not quit from this room.\n"+NORM);
return 1;
}

query_spar_area(){ return 1; }
CN_PK(){ return 1; }
