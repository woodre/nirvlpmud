/* approved by Mythos <8-12-1999> */
#include "/players/wocket/closed/ansi.h"
#define PRIEST BOLD+"Priest"+OFF
inherit "/obj/monster.c";
object sucker1,sucker2;
int accept;

reset(arg){
  ::reset(arg);
  if(arg) return;
move_object(clone_object("/players/wocket/turtleville/OBJ/cross.c"),this_object());
set_name("johnothan");
set_alias("priest");
set_short(BOLD+"Johnothan"+NORM+", the Priest");
set_long("He is wearing long black robes with a cross hangning around his neck\n"+
         "made of silver.  He has a funny hat with three stiff pieces of fabric\n"+
         "that curve and twist around his head.  Tassles surround the cuffs of his\n"+
         "robes making him brush them back whenever he moves his arms.  All in all\n"+
         "he looks comfortable and happy to be where he is.  Perhaps if you 'pray'\n"+
         "you will be revived or if you wish he will 'marry' you to someone.\n");
set_level(20);
set_hp(500);
set_wc(30);
set_ac(17);
set_al(1000);
}

init(){
  ::init();
  add_action("praying","pray");
  add_action("marry","marry");
  add_action("forcesecondinput","forcesecondinput");
}

praying(){
if(this_player()->query_ghost()){
tell_room(environment(this_object()),"Johnothan chants some magikal words.\n");
return call_other(this_player(),"remove_ghost",0);
}
else{
tell_room(environment(this_object()),"Johnothan says: But your not dead silly.\n");
return 1;
}
}

marry(str){
object SO;
  if(!str){
    notify_fail(PRIEST+" says: Who do you wish to marry?\n");
    return 0;
  }
  sucker1 = this_player();
  sucker2 = find_player(str);
  if(str == "guest"){
    notify_fail(PREIST+" says: You are not allowed to marry Guest.\n")
    return 0
  }
  if(!sucker2 || environment(sucker2) != environment(sucker1)){
    notify_fail(PRIEST+" says: That person is not here to be married to.\n");
    return 0;
  }
  if(sucker1 == sucker2){
    notify_fail(PRIEST+" says: You can not marry yourself.\n");
    return 0;
  }
  if(present("wedding ring",sucker1)){
    notify_fail(PRIEST+" says: You are already married.\n");
    return 0;
  }
  if(present("wedding ring",sucker2)){
    notify_fail(PRIEST+" says: "+sucker2->query_name()+" is already married.\n");
    return 0;
  }
  if(sucker1->query_money() < 1000){
    notify_fail(PRIEST+" says: You do not have enough money to pay for the ceremony.\n");
    return 0;
  }
  sucker1->add_money(-1000);
  say(PRIEST+" says: We are gathered here today to marry "+sucker1->query_name()+" and "+sucker2->query_name()+"\n"+
      "in holy matrimony.  To have them devote their mud lives together\n"+
      "in sickness and in health, for richer or for poorer, through thick and\n"+
      "thin, for as long as they both shall live.\n\n");
  say(PRIEST+" says: If any one here has any reason why these two should not be\n"+
      "married speak now or forever hold your peace.\n\n");
  say(PRIEST+" says: Since noone has objected we shall continue.\n\n");    
  say(PRIEST+" says: Do you, "+sucker1->query_name()+", wish to marry "+sucker2->query_name()+"?\n");
  tell_object(sucker1,HIR+"Type '"+OFF+"i do"+HIR+"' to accept: "+OFF);
  input_to("check_ido");
  return 1;
}

check_ido(str){
  if(str == "i do"){
    command("say I do",sucker1);
    say("\n"+PRIEST+" says: And do you, "+sucker2->query_name()+", wish to marry "+sucker1->query_name()+"?\n");
    tell_object(sucker2,HIR+"Type '"+OFF+"i do"+HIR+"' to accept: "+OFF);
    command("forcesecondinput",sucker2);
  }
  else{
    command("emote shakes "+sucker1->query_possessive()+" head no.\n",sucker1);
    say(PRIEST+" says: Then the wedding is off.\n");
  }
  return 1;
}

forcesecondinput(){
  input_to("check_ido2");
  return 1;
}

check_ido2(str){
  if(str == "i do"){
   command("say I do",sucker2);
   marry_us();
  }
  else{
    command("emote shakes "+sucker2->query_possessive()+" head no.\n",sucker2);
    say(PRIEST+" says: Then the wedding is off.\n");
  }
  return 1;
}
 
marry_us(){
object ring1,ring2;
  say("\n"+PRIEST+" says: I now pronouce you husband and wife.\n");
  say("\n"+PRIEST+" says: You may kiss the bride.\n");
  ring1 = clone_object("/players/wocket/wedding/ring.c");
  ring2 = clone_object("/players/wocket/wedding/ring.c");
  ring1->set_spouse(sucker2->query_real_name());
  ring2->set_spouse(sucker1->query_real_name());
  move_object(ring1,sucker1);
  move_object(ring2,sucker2);
  sucker1->chan_msg(RED+"   @"+GRN+"}-,-`---"+OFF+BOLD+
           "   "+sucker1->query_name()+" and "+sucker2->query_name()+" have just been married   "+OFF+GRN+
          "---,-`-{"+RED+"@\n"+OFF,"gossip");
}
 
