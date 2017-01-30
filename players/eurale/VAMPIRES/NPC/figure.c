/* Rainbow Inn Souvenir Shop clerk */

#include "/players/eurale/closed/ansi.h"
#define TP this_player()
#define TPRN this_player()->query_real_name()
inherit "obj/monster";
object item;
int value,m;
int TS;
int ROPE,STONES;

reset(arg) {
object buyer;
  ::reset(arg);
  if(arg) return;
TS = 5;  /*  Only 5 vamp t-shirts per reset  */
ROPE = 1;
STONES = 5;
set_name("vampire");
set_alias("figure");
set_race("undead");
set_short(GRY+"Shrouded figure"+NORM);
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
  load_chat("The shrouded figure asks: Can I get something for you?\n");

}

init() {
add_action("ask","ask");
add_action("buy_item","buy");
}

ask(str) {
if( (!str) || str == "figure" || str == "vampire" ) {
  write("The figure looks out from under his shroud and whispers..\n"+
        "'We have some interesting items here and I'd be glad to\n"+
        "get you whatever you desire.  All you have to do is tell\n"+
        "me which items you'd like to 'buy' and I'll go fetch them.'\n");
  return 1; }
}

buy_item(str) {
m = 0;

if(str == "maalox" || str == "tablets") {
  item = clone_object("/players/eurale/VAMPIRES/OBJ/maalox.c");
/* Changed cost by 2*, per new detox rules. [jan 4 '04] - Jaraxle
  value = 1400;
*/
value = 2800;
  m = 1; }

if(str == "stone" || str == "honing stone") {
  if(STONES == 0) {
    write("The figure whispers, 'All out but more coming.'\n");
    return 1; }
  item = clone_object("players/eurale/OBJ/honing_stone.c");
  value = 1000;
  STONES = STONES -1;
  m = 1; }

if(str == "rope") {
  if(ROPE == 0) {
    write("The vampire hisses, 'I have no ropes at the moment.'\n");
    return 1; }
  item = clone_object("/obj/rope.c");
  value = 40;
  ROPE = 0;
  m = 1; }

if(str == "cookie" || str == "fortune cookie") {
  item = clone_object("/players/eurale/VAMPIRES/OBJ/fortune_cookie.c");
  value = 50;
  m = 1; }

if(str == "ring" || str == "moonstone ring" || str == "moonstone") {
  item = clone_object("players/eurale/VAMPIRES/OBJ/moonstone.c");
  value = 450;
  m = 1; }

if(str == "shirt" || str == "t-shirt") {
  if(TS == 0) {
    write("The figure says, 'Sorry, just sold my last one but I might\n"+
	"have more later.... check back.\n");
    return 1; }
  if(present("t-shirt",this_player())) {
    write("The vampire pokes you and says, 'You're a greedy little\n"+
	"feller but I only sell one to a customer. *wink*\n");
    return 1; }
  item = clone_object("/players/eurale/VAMPIRES/OBJ/t_shirt.c");
  value = 325;
  TS = TS - 1;
  m = 1; }

if(str == "ru784" || str == "pill" || str == "abortion pill") {
  item = clone_object("/players/eurale/VAMPIRES/OBJ/ru784.c");
  value = 1250;
  m = 1; }

if(str == "hamsters" || str == "hamster cage" || str == "cage") {
  item = clone_object("/players/eurale/VAMPIRES/OBJ/hamster_cage.c");
  value = 600;
  m = 1; }

if(m) {
if(this_player()->query_money() <value) {
  write("The shrouded figure shakes his head and whispers, 'You\n"+
        "do not have enough gold to purchase that.\n");
return 1; }

if(!call_other(TP,"add_weight",call_other(item,"query_weight"))) {
  write("The hooded vampire tells you, 'You'll have to reduce\n"+
        "your load before you can carry that.\n");
  return 1; }

this_player()->add_money(-value);  /* take coins from player  */
/*  The following line adds coins to this object from the sale.
this_object()->add_money(value);
*/

move_object(item,this_player());

say("The shrouded figure drifts off and returns with a "+str+" for "+
    capitalize(TPRN)+".\n");
write("You watch a small bat fly away with your coins to the vampire vault.\n");
return 1; }
else {
  write("The figure hisses, 'That item cannot be bought here.'\n");
  return 1; }
}
