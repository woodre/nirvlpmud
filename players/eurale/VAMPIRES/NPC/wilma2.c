/* Rainbow Inn Souvenir Shop clerk */

#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";
object item;
int value,m;

reset(arg) {
object buyer;
  ::reset(arg);
  if(arg) return;
set_name("vampire");
set_alias("wilma");
set_race("undead");
set_short(GRY+"Wilma"+NORM);
set_long(
  "This shrouded figure is one of the many vampires employed by the\n"+
  "vampire guild.  From underneath his shroud, red glowing eyes peer\n"+
  "out at the patrons of the Rainbow Inn Souvenir Shop. His palid\n"+
  "and bony hands extend from the arms of his cloak and he moves\n"+
  "about the shop with an eerie quiet, disturbing nothing... not\n"+
  "even the dust on the floor.\n");

set_level(14);
set_hp(300);
set_al(0);
set_wc(52);
set_ac(11);
set_heal(5,2);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(2);
  load_chat("Wilma asks: Can I get something for you?\n");

}

init() {
add_action("buy_item","buy");
}

buy_item(str) {
m = 0;

if(str == "cookie" || str == "fortune cookie") {
  item = clone_object("/players/eurale/VAMPIRES/OBJ/fortune_cookie.c");
  value = 50;
  m = 1; }


if(m) {
if(this_player()->query_money() <value) {
  write("Wilma smiles and says, 'You don't have the cash, begone.'\n");
return 1; }

if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
  write("Wilma whispers, 'You're carrying too much, sorry.'\n");
  return 1; }

this_player()->add_money(-value);  /* take coins from player  */
move_object(item,this_player());

write("Wilma takes your coins and hands you a "+BOLD+str+NORM+".\n");
return 1; }
else {
  write("Wilma says, 'Sorry, I don't sell that here.'\n");
  return 1; }
}
