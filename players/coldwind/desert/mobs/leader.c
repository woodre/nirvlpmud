#include "/players/coldwind/define.h"
inherit "/players/vertebraker/closed/std/monster.c";
#define attacked (this_object()->query_attack())
#define atn capitalize(attacked->query_name())


reset(arg)  {
  ::reset(arg);
  if(arg) return;
  move_object(clone_object("/players/coldwind/desert/weapons/claws.c"),this_object());
init_command("wield claws");
move_object(clone_object("/players/coldwind/desert/armor/armor.c"),this_object());
init_command("wear armor");
set_name("winged ape");
set_alt_name("leader");
set_race("ape");
set_short(HIK+"Ape Leader"+NORM);
set_long(
"  The mighty ape is watching your moves curiously with its yellow\n"+
"eyes. It has featherless wings that looks like giant bat wings. \n"+
"You notice a few red tattoos on the left wing as a sign of leadership\n"+
"among their race. The ape is wearing dark suit of chainmail that only\n"+
"apes of the highest ranks are allowed to wear, while a thick dark\n"+
"hair covers most of its body.\n");
set_level(19);
set_hp(450);
set_al(-830);
set_gender("male");
set_wc(28);
set_ac(16);
set_ac_bonus(4);
set_wc_bonus(16);

set_chat_chance(5);
  load_chat("The leader takes an offensive stand...\n");
  load_chat("Yellow eyes watch your moves.\n");
  load_chat("The ape makes a threatening sound as it knocks on its chest.\n");

set_a_chat_chance(15);
  load_a_chat("The ape dodges your slow attack.\n");
  load_a_chat("The leader bites your arm!\n");
  load_a_chat("The winged ape flies back in agony...\n");
  set_aggro(1, 20, 70);


}


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
        BLU+""+atn+" feels powerless as the mighty ape calls upon \n"+          
	 "   "+HIY+"               \n"+
	 "   "+HIK+"               \n"+
	 ""+HIK+"             The Power Of The Apes\n"+
     "   "+HIK+"              \n"+NORM);
  attacked->add_hit_point(-40);
  }