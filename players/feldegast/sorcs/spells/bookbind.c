#include "/players/wocket/closed/ansi.h"
inherit "/players/wocket/mages/obj/page.c";

object target;

reset(){
  spell = "bookbind";
  spell_short = HIY+"Bookbind"+NORM;
  time = 10;
  spcost = 290;
  hpcost = 0;
  type = "enchant";
  size = 7;
}


check_spell(object mage,str){
target = previous_object()->get_target(str);
if(!target){
  tell_object(mage,"Your spell fizzles.\n");
  return;
}
if(!target->is_player()){
  tell_object(mage,"Your spell fizzles.\n");
  tell_object(mage,target->short()+" is not a player.\n");
  return;
}
if(target->query_guild_exp()){
  tell_object(mage,"Your spell fizzles.\n");
  tell_object(mage,target->query_name()+" is in another guild.\n");
  return;
}
if(!present("wocketbook",target)){
  tell_object(mage,"Your spell fizzles.\n");
  tell_object(mage,target->query_name()+" does not have a book to be bound.\n");
  return;
}
if(present("wocketbook",target)->query_pagenumber() != 0){
  tell_object(mage,"Your spell fizzles.\n");
  tell_object(mage,target->query_name()+"'s book does not have the correct number of pages.\n");
  return;
}
if(target->query_level() < 3){
  tell_object(mage,"Your spell fizzles.\n");
  tell_object(mage,target->query_name()+" does not have the knowledge to possess a magic book.\n");
  return;
}
return 1;
}

cast_spell(mage){
tell_object(mage,"Arcane magic flares from your finger tips.\nLightning crackles as the book begins to bind.\n");
tell_object(mage,"You cast "+HIY+"BOOKBIND"+NORM+" upon the book.\n");
mage->remote_say("Lightning crackles as the book begings to bind.\n");
mage->chan_msg(HIY+"Lightning strikes and magic binds itself to paper and leather.\n"+NORM,"junk");
tell_object(mage,"The book is bound.\n");
tell_object(target,"Your book is bound.\n");
tell_object(target,"\nWelcome to the New Order of Mages.\n");
tell_object(target,HIR+"Setting guild stats...\n"+NORM);
destruct(present("wocketbook",target));
move_object(clone_object("/players/wocket/mages/mageautoload.c"),target);
target->add_guild_exp(1);
target->set_guild_name("mages");
command("wimpy off",target);
command("pretitle |",target);
return 1;
}
