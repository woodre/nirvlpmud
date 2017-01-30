#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/players/daranath/closed/monster1.c";
object ob, ob1, ob2;

reset(arg) {
   ::reset(arg);
   if (!arg) {

 ob = clone_object("obj/money.c");
  ob->set_money(1500+random(4000));
  move_object(ob, this_object());
 ob1 = clone_object(ROOT+"obj/geo_robes.c");
  move_object(ob1, this_object());
/* Gonna take a while to get spellbook right, will add later
 ob2 = clone_object("/players/daranath/closed/obj/spellbook_earth.c");
  move_object(ob2, this_object());
*/

set_name("Ragnok the Geomancer");
set_short("A small human carrying a large book");
set_alias("ragnok");
set_alt_name("geomancer");
set_race("human");
set_gender("male");
set_long("A balding man, Ragnok was one of the Geomancers that used to call\n"+
         "this cave home. He has come back, leaving an Earth Elemental\n"+
         "to guard the entrance, and see if anything is left.\n");
set_level(19);

init_command("wield spellbook");
init_command("wear robes");

set_ac(16);
set_wc(25 + random(9));
set_hp(400 + random(100));
set_al(0);
set_aggressive(0);
set_chat_chance(4);
load_chat("Ragnok digs through the shelves, looking to see if anythings left.\n");
load_chat("Ragnok runs his hand through what's left of his hair.\n");
load_chat("Ragnok eyes you and grasps his book tightly.\n");
load_chat("Ragnok looks wistfully at the old guild hall.\n");

   }
}
