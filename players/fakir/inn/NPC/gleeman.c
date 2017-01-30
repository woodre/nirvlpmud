#include "/players/fakir/color.h"
inherit "obj/monster.c";

reset(arg)  {
  ::reset(arg);
  if(arg) return;
set_name("gleeman");
set_alias("Thom");
add_money(2000+random(1000));
set_race("human");
set_short("A Gleeman");
set_long(
  "With wispy"+WHITE+" white "+OFF+"hair, bushy eyebrows and mustache to match, the cold"+CYAN+" blue"+OFF+"\n"+
"eyes peer out of a wrinkled face that seems to belong more to a gnarled\n"+
"tree that had seen hard times.  The"+CYAN+" eyes "+OFF+"are piercing, and look deep into\n"+
"your soul.  The "+RED+"P"+CYAN+"a"+BROWN+"t"+WHITE+"c"+YELLOW+"h"+GREEN+"w"+BLUE+"o"+RED+"r"+MAGENTA+"k"+OFF+" cloak he wears has odd baggy sleeves and big\n"+
"pockets inside and out.  Though he has assumed the look and dress of a\n"+
"gleeman, Thom Merrilin was once Captain of the Kings Guard, but left his\n"+
"position and went into hiding after falling in love with the Kings wife.\n");

move_object(clone_object("/players/fakir/inn/ARM/patchcloak.c"),
(this_object()));
init_command("wear cloak");

set_level(20);
set_hp(500);
set_al(0);
set_wc(40);
set_ac(20);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(5);
  load_chat("The Gleeman shouts: Behold the"+YELLOW+" magic "+OFF+"and"+CYAN+" story telling "+OFF+"of a gleeman!\n");
set_a_chat_chance(15);
  load_a_chat("The Gleeman says: You will now"+CYAN+" taste "+OFF+"of my"+YELLOW+" magic powers,"+OFF+" backstabber.\n");

set_chance(20);
set_spell_dam(60);

set_spell_mess1(
  "The gleeman gestures and shimmers brightly \n");
set_spell_mess2(
  "The gleeman"+YELLOW+" gestures "+OFF+"and"+CYAN+" shimmers."+OFF+" You feel lightheaded.  \n");


}

monster_died() {
  
  tell_room(environment(this_object()),
	"The gleeman commends his spirit to the Gods of Abinithar\n");
return 0; }
