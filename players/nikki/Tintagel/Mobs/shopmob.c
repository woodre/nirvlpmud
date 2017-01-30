/*  The heal seller  */
#include "/players/nikki/ansi.h"
#define TP this_player()
inherit "obj/monster";
reset(arg) {

object gold;
object nug;
object buyer;

::reset(arg);
if(arg) return;
set_name("athanasius");
set_race("human");
set_short(RED+"Athanasius"+NORM);
set_alias("keeper");
set_long(
	"  A portly man with skin that has been leathered by long days out\n"+
	"in the sun.  He looks rather grumpy and rough natured.  For the right\n"+
	"price he will fill your belly with grog and food.  Just ask for a\n"+
	HIM+"menu"+NORM+" and you can "+HIM+"order"+NORM+" what you need.\n");

set_level(20);
set_hp(1500);
set_al(0);
set_wc(35);
set_ac(20);
set_heal(5,5);
set_no_clean(1);
set_aggressive(0);
set_dead_ob(this_object());


set_chat_chance(2);
  load_chat(RED+"Athanasius says,"+NORM+" 'Watch yeself, we don't get on wit strangers here.'\n");

set_chance(10);
set_spell_dam(100);
set_spell_mess1(HIG+
  "Athanasius draws his fist back and begins pummeling his assailant in the face!\n"+NORM);
set_spell_mess2(HIG+
  "Athanasius draws his fist back and begins pummeling you in the face!\n"+NORM);

gold = clone_object("obj/money");
gold->set_money(random(10)+10);
move_object(gold,this_object());
}

init() {
add_action("menu","menu");
add_action("order","order");
}

menu() {
  write("Athanasius looks you up and down.... \n"+
	"  Me ol'lady makes her own brew and it sells pretty fair.  The\n"+
	"mutton ain't half bad neither so if ye got gold ya can warm yer\n"+
	"gut on what we have to offer.\n"+
	"  \n"+
        "He shows you the menu:\n"+
	HIB+"           Mead                1450 coins\n"+
	"           Mutton              1450 coins\n"+
	"           Goats Milk          1450 coins\n"+NORM+
	"\n");
  return 1; }

order(str) {
object item;
int value, m, heavey;
m = 0;

if(str == "mead") {
  item = clone_object("/players/nikki/Tintagel/Obj/mead.c");
  value = 1450;
  m = 1; }

if(str == "mutton") {
  item = clone_object("/players/nikki/Tintagel/Obj/mutton.c");
  value = 1450;
  m = 1; }

if(str == "milk") {
  item = clone_object("/players/nikki/Tintagel/Obj/milk.c");
  value = 1450;
  m = 1; }



if(m) {
if(this_player()->query_money() <value) {
  write(RED+"Athanasius"+NORM+" yells, 'What are you trying to pull here?! If you\n");
  write("                   don't have the gold get out!'\n");
  say(RED+"Athanasius"+NORM+" yells at "+capitalize(this_player()->query_real_name())+", 'What are you trying to pull here?! If you\n");
  say("                   don't have the gold get out!'\n");
    
return 1; }

if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
write(RED+"Athanasius"+NORM+" yells, 'Yura greedy bastard aren't ye, ya got too many as it is, GO AWAY NOW!'\n");
say(RED+"Athanasius"+NORM+" yells at "+capitalize(this_player()->query_real_name())+", 'Yura greedy bastard aren't ye, ya got too many as it is, GO AWAY NOW!'\n");
return 1; }

/*  take the coins from the player  */
this_player()->add_money(-value);

move_object(item,this_player());
say(capitalize(this_player()->query_real_name())+" orders a "+str+" \n"); }
else {
  write("That item cannot be ordered here. \n"); }
return 1;
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nAthanasius cries, 'Me poor sweet bairns, who will take care of'em now?'\n");
  return 0; }
