#include "/players/wocket/closed/ansi.h"
inherit "obj/monster.c";

reset(){
set_short(CYN+"Hatheo the Wizard"+NORM);
set_name("hatheo");
set_level(30);
set_hp(500);
set_wc(50);
set_ac(30);
}

init(){
  if(present("mageguildob",this_player())){
  add_action("ask_mage","ask");
  add_action("choose_path","choose");
}
}

ask_mage(){
write("Hatheo says, \"I can help you decide which descipline you can learn about.\"\n");
write("Hatheo, \"Please choose a decipline you would like to follow:\n"+
      "                  sorcery,\n"+
      "                  illusion,\n"+
      "                  summoning,\n"+
      "                  necromancy,\n"+
      "                  enchanting,\n"+
      "                  or general.\"\n");
say("Hatheo speaks privately with "+this_player()->query_name()+".\n");
return 1;
}

choose_path(str){
string sect,color,title;
if(present("mageguildob",this_player())->query_sect()){
write("Hatheo says, \"I am sorry but you have already choosen your descipline.\"\n");
return 1;
}
switch(str){
case "sorcery":    sect = "sorcery";  color = HIR;  title = "sorceror"; break;
case "illusion":   sect = "illusion"; color = HIC;  title = "illusionist"; break;
case "summoning":  sect = "summon";   color = HIB;  title = "warlock"; break;
case "necromancy": sect = "necro";    color = HIM;  title = "necromancer"; break;
case "enchanting": sect = "enchant";  color = HIY;  title = "enchanter"; break;
case "general":    sect = "general";  color = CYN;  title = "mage"; break;
default:  notify_fail("Hatheo says, \"That is not a descipline i can teach you.\"\n"); return; break;
}
write("Hatheo says, \"A very good choice in deed.\"\n");
write("Hatheo trains you to become a "+str+".\n");
say("Hatheo trains "+this_player()->query_name()+" to be a "+title+".\n");
write("You are now a "+color+title+NORM+".\n");
present("mageautoload",this_player())->set_sect(sect);
command("newbook",this_player());
return 1;

} 
