#include "/players/coldwind/define.h"
inherit "obj/monster.c";
#define attacked (this_object()->query_attack())
#define atn capitalize(attacked->query_name())

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("giant");
set_alt_name("yellow giant");
set_race("giant");
set_short(HIY+"A Yel"+NORM+YEL+"low gi"+HIY+"ant"+NORM);
set_long(
"  The giant's skin started turning yellow, while his big eyes, hair\n"+
"and short beard are turning to a light brown color. He doesn't seem\n"+
"to be equiped for fighting, yet he looks like he is trying to resist \n"+
"the evil inside him. It was said that a witch was able to control \n"+
"some giants by allowing the evil souls to take over their bodies\n"+
"and minds.\n"+NORM);
set_level(18);
set_hp(400);
set_al(0);
set_gender("male");
set_wc(26);
set_dead_ob(this_object());
set_ac(15);
set_wc_bonus(12);
set_aggressive(0);
set_chat_chance(5);
  load_chat("The giant screams madly...\n"+
  "          GUAARAAAAHH\n");
  load_chat("You take a step back.\n");
  load_chat("A pair of brown eyes stares at you.\n");
set_a_chat_chance(15);
  load_a_chat(HIR+"The giant glares at you.\n"+NORM);
  load_a_chat("The giant throws you into the ground\n");
  load_a_chat("Your ribs screams in pain.\n");

}


monster_died() {
  object corpse;
  corpse = present("corpse", environment()); 
  move_object(clone_object("/players/coldwind/desert/items/soul_1.c"),
      environment(this_object()));
if(corpse)
return 1; }

heart_beat(){
 int blah;
 blah = random(100);
  :: heart_beat();
    if(!environment()) return;
    if(!attacked) return;
     if(blah > 60){
       woo(); }
  }

woo(){
  tell_room(environment(attacked),
        "The yellow giant lifts "+atn+" up with one arm\n"+ 
		" \n"+         
 ""+HIY+"                S M A C K"+NORM+"               \n"+
        " \n"+
		"Giant "+YEL+"slams"+NORM+" "+atn+" into the ground\n");
        attacked->add_hit_point(-30);
  }