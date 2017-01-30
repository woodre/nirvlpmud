#include "/players/dusan/ansi.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())

reset(arg)  {
object gold;
  ::reset(arg);
  if(arg) return;


set_name("zed");
set_alias("mage");
set_alt_name("wizard");
set_race("human");
set_short("An old hedge mage");
set_long(
  "   A white haired, frazzled old man. He wears seemingly shoddy \n"+
  "robes. His hair is unkept and in disarray, he would seem genuinely\n"+
  "lost and confused was it not for the clarity that shines deeply in his\n"+
  "eyes. There you see a deep dwelling power.\n" );

set_level(20);
set_hp(700+random(600));
set_al(400);
set_wc(40);
set_ac(20);
set_heal(4,1);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(15);
  load_chat("The Zed says 'What can I do for you'? \n");
set_a_chat_chance(15);
  load_a_chat("Zed chants 'Ulan no em ba um BRAE!' \n");

gold = clone_object("obj/money");
gold->set_money(5000);
move_object(gold,this_object());
/* staff =clone_object("/players/dusan/town/weapons/mstaff.c");
move_object(staff,this_object()); */
}

heart_beat(){
 int blah;
 blah = random(100);
  :: heart_beat();
    if(!environment()) return;
    if(!attacked) return;
     if(blah > 25){
       woo(); }
  }

woo(){
  if(!query_attack()) return;
  if(!present(query_attack(), environment())) return 1;
  if(query_attack()->query_ghost()) return 1;
  query_attack()->hit_player(random(90)+50);
  tell_room(environment(attacked),
  "Zed finishes a spell...\n"+
  "             "+BOLD+""+BLK+" `--- `__'   `--'\n"+
  "                `--'"+NORM+""+HIY+" \\"+NORM+""+BOLD+""+BLK+" `---'  \n"+
  "                   `--"+NORM+""+HIY+"\\"+NORM+""+BOLD+""+BLK+"-'"+NORM+"     \n"+  
  "                   "+HIY+"   /       \n");
 tell_room(environment(attacked),
  "                     /        \n"+
  "                    / \\      \n"+
  "                    \\  \\      \n"+
  "                    /   \\     \n"+
  "                   /   / \\  "+NORM+"  \n"+
  "                  Lightning strikes searing the area. \n"); 
    }


monster_died() {
return 1; }