#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";
object pie;
string pie_type;

reset(arg) {
object buyer;
  ::reset(arg);
  if(arg) return;
set_name("wilma");
set_alias("pie maker");
set_race("undead");
set_short(BOLD+"Wilma"+NORM+", the pie maker");
set_long(
  "Standing before you is a rotund lady wearing a white dress with\n"+
  "billowing sleeves.  She has a chef's hat on that is bent and\n"+
  "leaning to one side. A soiled white apron hangs from her neck and\n"+
  "ties behind her back. Flour speckles both her face and arms from\n"+
  "making the crust dough for all her pies. Her black hair is tied \n"+
  "in a bun and held in place with a tight hair net.\n");

set_level(14);
set_hp(300);
set_al(0);
set_wc(18);
set_ac(11);
set_heal(5,2);
set_no_clean(1);
set_aggressive(0);

set_chat_chance(2);
  load_chat("Wilma smiles and asks, 'Don't the pies smell delicious?\n");
  load_chat("Wilma whistles as she bustles about the shop.\n");
  load_chat("'Can I help you?', asks Wilma\n");

}

init() {
  add_action("order","order");
}

order(str) {
if(!str) {
  write("Wilma says: I'm sorry, dear, what did you want again?\n");
  return 1; }

if(this_player()->query_money() < 100) {
  write("Wilma sighs and says: You haven't enough money.\n");
return 1; }

sscanf(str, "%s pie", pie_type);
if(!pie_type) {
  write("'What kind of pie would you like?', asks Wilma\n");
  return 1; }
pie = clone_object("/players/eurale/VAMPIRES/OBJ/pie.c");
pie->set_pie_type(pie_type);

if(!call_other(TP,"add_weight",call_other(pie,"query_weight"))) {
  write("Wilma chuckles. She tells you: My pies are full of fruit\n"+
        "and too heavy for you to carry right now.\n");
  return 1; }

this_player()->add_money(-100);  /* take coins from player  */
this_object()->add_money(1);  /*  add coins to this object  */

move_object(pie,this_player());

say("Wilma goes behind the counter and returns with a deliciouos\n"+
    pie_type+" pie which she hands to "+
    capitalize(TPRN)+".\n");
return 1; }
