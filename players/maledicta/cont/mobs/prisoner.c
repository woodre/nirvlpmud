#define WAR "/players/maledicta/cont/daemon"
#include "/players/maledicta/ansi.h"
inherit "obj/monster.c";

int bdelay;

reset(arg)  {

  ::reset(arg);
  if(arg) return;
bdelay = 0;
set_name("prisoner");
set_alt_name("elven prisoner");
set_race("elf");
set_short("an elven prisoner");
set_long(
"  The elf before you is thin and wasted, barely a shadow\n"+
"of his former self. Long bloody cuts cover his entire\n"+
"frame from head to toe. He looks weary and sad, as if\n"+
"completely defeated in body and mind.\n");
set_level(1);
set_hp(20);
set_al(-1000);
set_wc(3);
set_ac(1);
set_chat_chance(35);
load_chat("The elven slave calls out for you to 'free' him!\n");
load_chat("The elven slave says,'Please, please don't leave me here!'\n");
}

init(){
::init();
add_action("free_me", "free");
}

free_me(str){
object tester;
if(!str){
write("Free who?\n");
return 1;
}
if(str == "prisoner" || str == "elf"){
if(present("undead dragon", environment(this_player()))){
  write("The undead dragon moves to intercept you, keeping you from the prisoner.\n");
  return 1;
  }
  write("\n\nYou reach out and release the Elf prisoner from his chains.\n"+
        "He almost seems to smile at you, but instead just nods his\n"+
        "head and slumps to the ground.\n"+
        "After a moment he speaks, 'Thank you, I have been here for many\n"+
        "months. I cannot thank you enough except to say that I am able\n"+
        "to reward you for your bravery.'  He then smiles, slightly.\n"+
        "'Oh yes, even a pathetic prisoner such as myself has something to\n"+
        "give.'  He then leans closer and says,'west from the tower of hope\n"+
        "and then up and over the mountain. Continue south until you find a\n"+
        "pool of water. At its edge search.' He nods sadly and continues, 'On\n"+
        "my honor, I would give you more. Thank you again, now I may go and be\n"+
        "with my family once again.'  He then stands, bowing low to you, and\n"+
        "leaves.\n\n"+  
        "All you need do now is 'search' at this location. You only hope he\n"+
        "was telling you the truth.\n\n\n");
  this_player()->add_alignment(1000);
  tester = clone_object("obj/treasure");
tester->set_alias("rescued_elf_dood_mal");
  tester->set_short(0);
  tester->set_long(0);
  tester->set_value(0);
  tester->set_save_flag(1);
  tester->set_weight(0);
  move_object(tester, this_player());

  destruct(this_object());
  return 1;
  }
write("free who?\n");
return 1;
} 
          
