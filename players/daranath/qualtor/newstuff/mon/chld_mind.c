inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
     ob = clone_object("obj/money");
     ob->set_money(random(100) + 50);
     move_object(ob, this_object());
     ob2 = clone_object("/players/daranath/qualtor/newstuff/weps/mind_staff.c");
     move_object(ob2, this_object());

set_name("Child of Thought");
set_short("Children of the Crystal (thought)");
set_alias("children");
set_alt_name("child");
set_race("human");
set_gender("male");
set_long("The children of thought are the one sect of the seven that hasn't\n"+
         "made an appearance in Qual'tor until after City Ward was\n"+
         "rebuilt. Now, they want nothing more then to restore the\n"+
         "Psion back to thier former glory.\n");
set_level(9);

init_command("wear armor");
init_command("wield weapon");

set_ac(7);
set_wc(12 + random(4));
set_hp(110 + random(45));
set_al(1000);
set_aggressive(0);
set_chat_chance(2);
set_a_chat_chance(10);
load_chat("The child of thought moves about the area\n");
load_a_chat("The child of thought hits you with a mental strike.\n");

   }
}
