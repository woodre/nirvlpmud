#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

reset(){
set_short(HIR+"Illuza the Sorcerer"+NORM);
set_name("illuza");
set_level(30);
set_hp(500);
set_wc(50);
set_ac(30);
}

init(){
  if(present("mageguildob",this_player())){
  add_action("ask_mage","ask");
  add_action("study_spell","study");
}
}

ask_mage(){
write("Illuza says, \"I can help you study many things in the art of sorcery.\"\n");
write("Illuza says, \"What would you like help with:\n"+
      "                  firebolt,\n"+
      "                  lifedrain,\n"+
      "                  darkness,\n"+
      "                  or light?\"\n");
say("Illuza speaks privately with "+this_player()->query_name()+".\n");
return 1;
}

study_spell(str){
int xexp,exp,chance;
if(!str){
  notify_fail("Illuza says, \"What would you like help studing?\"\n");
  return 0;
}
switch(str){
case "firebolt":  exp = 30000; chance = 66; break;
case "lifedrain": exp = 40000; chance = 40; break;
case "darkness":  exp = 20000; chance = 80; break;
case "light":     exp = 10000; chance = 90; break;
default: notify_fail("Illuza says, \"I'm sorry, but I can not help you with that.\"\n");
        return 0; break;
}
if(this_player()->query_extra_level() < 1)
  xexp = this_player()->query_exp() - "room/adv_guild"->get_next_exp(this_player()->query_level()-1);
else
  xexp = this_player()->query_exp() - "room/exlv_guild"->get_next_exp(this_player()->query_extra_level()-1);
if(xexp < exp){
  write("Illuza says, \"You don't have enought knowldege.  To train you would be \n"+
        "a waste of my time.\"\n");
  return 1;
}
write("Illuza shows and explain the spell to you then leaves you to study\n"+
      "in peace.  You begin to concentrate, seeping your knowledge into\n"+
      "the pen you scribe with.  ");
say(this_player()->query_name()+" studies quietly.\n");
this_player()->add_exp(-exp);
if(random(100) < chance){
write(HIR+"The ink glows a red and the spell takes form.\n"+NORM);
move_object(clone_object("/players/wocket/mages/spells/"+str+".c"),this_player());
return 1;
}
else
get_fail();
return 1;
}

get_fail(){
string msg;
switch(random(7)){
case 0:  msg = "Your page ignites destroying all your work.\n"; break;
case 1:  msg = "Your page tears, letting the magic seep out.\n"; break;
case 2:  msg = "You faint destroying your concentration.\n"; break;
case 3:  msg = "You sneeze destroying your concentration.\n"; break;
case 4:  msg = "The ink fades leaving your page blank.\n"; break;
case 5:  msg = "Jibberish fills your minDA LAsL iDL Tles.\n"; break;
case 6:  msg = "Illuza tears up your paper and curses at you.\n"; break;
case 7:  msg = "The page fades from this reality leaving you\nbewildered.\n"; break;
}
write(msg);
}