#include "/players/syn/ansi.h"
inherit "obj/monster.c";

object bah;
int doof;

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;

set_name("gremlin");
set_race("mogai");
set_short(HIY+"Grem"+NORM+GRN+"lin"+NORM);
set_long(
  "A short little green creature with faint yellow spots that cover its\n"+
  "body. He has long pointy ears and razor sharp teeth. His eyes are wild\n"+
  "and he looks like he is constantly smiling. He isnt very nice.\n");

set_level(20);
set_hp(random(100)+320);
set_al(-800);
set_wc(38);
set_ac(19);
set_heal(5,10);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("Gremlin runs around the store causing choas.\n");
  load_chat("Gremlin finds a pack of smokes and a ligher. He fires one up.\n");
  load_chat("Gremlin laughs manically.\n"); 


set_a_chat_chance(17);
  load_a_chat("Gremlin ducks and dodges, making you miss.\n");
  load_a_chat("Gremlin jumps around quickly dodging your attacks.\n"); 
set_chance(12);
set_spell_dam(random(30)+30);

set_spell_mess1(
   HIR+" /      /        /          /       /       /   \n"+
      " /      /        /          /       /       /    \n"+
     " /      /        /          /       /       /     \n"+ 
     "/      /        /          /       /       /      \n"+NORM
   +"The Gremlin scatches "+this_player()->query_name()+" fiercly!!!\n");
set_spell_mess2(
   YEL+"         /     /        /        /       /       / \n"+
       "   /    /     /        /        /       /       /  \n"+
      "   /    /     /        /        /       /       /   \n"+
      "  /    /     /        /        /       /       /    \n"+NORM+
       HIG+"The gremlin scatches you, and "+RED+" blood "+NORM+HIG+" pours form your wound.\n"+NORM);

}


init(){
  ::init();
    add_action("block_dir","east",1);
    }

heart_beat(){
 ::heart_beat();
    if (!random(5) && this_object()->query_hp() < 160 && doof <= 1) copy();
    }

block_dir(){
  if(present("gremlin", environment(this_player()))){
   write("Gremlin jumps in your way so you can't leave.\n");
   say(this_player()->query_name()+" tries to run, but the Gremlin jumps in the way.\n");
   return 1; }
} 

copy(){

   if (doof == 0) {
   bah = clone_object("/players/syn/shrine/mobs/gremlin2.c");
   move_object(bah, environment(this_object()));
   doof == 1;
   return 1; }
}


