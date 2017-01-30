#define ROOT "/players/daranath/qualtor/newstuff/"

inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, ob3, ob4;

 ob = clone_object("obj/money");
 ob->set_money(random(200) + 120);
  move_object(ob, this_object());
 ob2 = clone_object(ROOT+"weps/elf_bow.c");
  move_object(ob2, this_object());
 ob3 = clone_object(ROOT+"obj/mithril.c");
  move_object(ob3, this_object());
 ob4 = clone_object(ROOT+"obj/soft_boots.c");
  move_object(ob4, this_object());

set_name("Elven barricade guard");
set_short("Barricade Guard <elf>");
set_alias("guard");
set_alt_name("citymon");
set_race("elf");
set_gender("male");
set_long("Tall and slender, the Elves are made for running and hiding within woodland\n"+
         "areas. However, once word got out that the dwarves were helping to\n"+
         "protect Qual'tor, the elves send a few fighters to claim some\n"+
         "of the credit for themselves.\n");
set_level(16);

init_command("wear armor");
init_command("wear boots");
init_command("wield bow");

set_ac(13);
set_wc(20 + random(6));
set_hp(250 + random(120));
set_al(500);

   }
}
