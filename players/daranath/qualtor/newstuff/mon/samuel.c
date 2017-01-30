#define ROOT "/players/daranath/qualtor/newstuff/"
inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object(ROOT+"obj/work_boots.c"),this_object());
move_object(clone_object(ROOT+"obj/leathers.c"),this_object());

set_name("Samuel the shopkeeper");
set_short("Samuel the shop owner");
set_alias("samuel");
set_alt_name("shopowner");
set_race("human");
set_gender("male");
set_long("A former thief long since set straight by Qual'tors Paladin corp, Samuel\n"+
     "has run the East Road shop for a good number of years now. Samuel \n"+
     "bought the store from its previous owner, and is a respected member\n"+
     "of City Ward. Years have taken its toll on him, but he still smiles\n"+
     "at every customer walking through the door.\n");
set_level(12);

init_command("wear boots");
init_command("wear armor");

set_ac(9);
set_wc(15 + random(4));
set_hp(180 + random(20));
set_al(700);
set_aggressive(0);
set_chat_chance(4);
set_a_chat_chance(25);
load_chat("Samuel greets you as you browse through his store.\n");
load_chat("Samuel takes an inventory from the items left in his shop.\n");
load_a_chat("Samuel strikes you with a large fist.\n");
load_a_chat("Samuel screams for the local guard!\n");

   }
}
