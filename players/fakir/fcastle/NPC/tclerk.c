inherit "obj/monster";
#include "/players/fakir/color.h"
reset(arg) {

object gold;
object buyer;

::reset(arg);
if(arg) return;

set_name("quagmire");
set_alias("squint");
set_race("darkfriend");
set_short("Quagmire Squint");

set_long(
        "  Quagmire has shifty eyes that flit back and forth, searching\n"+
        "the shadows within the shop.  His face is pale, and cold beads\n"+
        "of sweat stand out on his wrinkled brow like small pearls.  He\n"+
        "oft-times deals in contraband, and if one but speaks the pass-\n"+
        "word...he will show you his illicit wears.\n");
set_level(20);
set_hp(2000);
set_al(-1000);
set_wc(35);
set_ac(25);
set_heal(5,5);
set_no_clean(1);
set_aggressive(0);
set_dead_ob(this_object());

set_chat_chance(10);
  load_chat("Quagmire whispers: 'Quiet fool, the streets are full of guards!'\n");
  load_chat("Quagmire walks to the door and checks the street for guards...\n");
  load_chat("Quagmire whispers: 'Some there is that calls me squint...but not many.\n");
  load_chat(CYAN+"You hear voices whispering in the back room.\n"+OFF);
  load_chat(CYAN+"Footsteps falling outside the doorway catch your attention.\n"+OFF);
  load_chat("Quagmire rummages under the counter and checks the door.\n");
  load_chat("Quagmire points toward the backroom and puts a finger to his lips.\n");
  load_chat(CYAN+"Muffled sounds of someone in agony and pain filter from the backroom.\n"+OFF);
set_chance(8);
set_spell_dam(50);
set_spell_mess1(
  "Quagmire sticks you in the belly with his dagger, then slashes your arm!\n");
set_spell_mess2(
  "Quagmire quickly side-steps your attack and stabs you in the thigh...\n");

gold = clone_object("obj/money");
gold->set_money(random(1000)+4000);
move_object(gold,this_object());
}

init() {
::init();
add_action("contraband","contraband");
add_action("buy","buy");
}

contraband() {
  write("Quagmire says: 'Ah...you know the pass-word. \n\n"+
        "Ok then, you can 'buy' what I got under the counter.\n"+
        "I get most of my stuff from those who don't want no\n"+
        "names used...so I can't guarentee this stuff...but\n"+
        "it should do as its designed...here is what I got.\n"+
        "  \n"+
        "     Aged goose liver          2700 coins\n"+
        "     Enchanted gizzard broth   2700 coins\n"+
        "     Raw oysters               3000 coins\n"+
        "\n");
  return 1; }

buy(str) {
object item;
int value, m, heavey;
m = 0;

if(str == "liver") {
  item = clone_object("players/fakir/fcastle/OBJ/liver.c");
  value = 2700;
  m = 1; }

if(str == "broth") {
  item = clone_object("players/fakir/fcastle/OBJ/broth.c");
  value = 2700;
  m = 1; }

if(str == "oysters") {
  item = clone_object("players/fakir/fcastle/OBJ/oysters.c");
  value = 3000;
  m = 1; }

if (m) {
if(this_player()->query_money() <value) {
  write("You do not have enough to purchase this item! \n");
return 1; }

if(!call_other(this_player(),"add_weight",call_other(item,"query_weight"))) {
write("Quagmire says: 'Lighten yer load, kid!'\n");
return 1; }

this_player()->add_money(-value);

move_object(item,this_player());
say(capitalize(this_player()->query_real_name())+" purchases a "+str+" \n"); }
else {
  write("Quagmire smirks: 'I don't got that kind of stuff here, fool!' \n"); }
return 1;
}

monster_died() {
  tell_room(environment(this_object()),
  "\n\nQuagmire drops his dagger and falls in a bloody heap. \n\n");
  return 0; }
