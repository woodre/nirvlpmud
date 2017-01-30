/*
 * v_thief2.c
 * small thief in vault
 */

inherit "obj/monster";

object gstone, vjewel, vpainting, vcrown, vsword, vkey;

void
reset(status arg)
{
  monster::reset(arg);
  if (arg)
    return;
  set_name("small thief");
  set_alias("thief");
  set_gender("male");
  set_level(5);
#if 0 /* Adjusting for Nirvana monster.guide -- Rumplemintz */
  set_hp(50);
  set_ac(15);
#else
  set_hp(75);
  set_wc(9);
  set_ac(5);
#endif
  set_al(-150);
  set_short("A small thief");
  set_long("This thief is small, weak and ugly, but very greedy and devious.\n"+
           "He has taken almost all the valuables in the vault.\n");
  set_aggressive(1);

  /* Spell setup */
  set_chance(20);
  set_spell_dam(10);
  set_spell_mess1("The small thief throws a knife.");
  set_spell_mess2("The small thief throws a knife at you.");

  /* Gear - long list */
  move_object(clone_object("/players/padrone/tower/npc/obj/frostsword"),
              this_object());
  init_command("wield sword");
  gstone = clone_object("/players/padrone/obj/gravstone");
  gstone->set_weight(-2);
  move_object(gstone, this_object());
  vjewel = clone_object("obj/treasure");
  vjewel->set_id("jewel");
  vjewel->set_alias("gem");
  vjewel->set_short("A jewel");
  vjewel->set_long("A beautiful, glittering jewel.\n");
  vjewel->set_weight(3);
  vjewel->set_value(1000);
  move_object(vjewel, this_object());

  vpainting = clone_object("obj/treasure");
  vpainting->set_id("painting");
  vpainting->set_alias("picture");
  vpainting->set_short("A painting");
  vpainting->set_long("This painting shows a landscape.\n"+
                      "It is signed 'Picasso', and on the backside it says 'Made in Taiwan'.\n");
  vpainting->set_weight(3);
  vpainting->set_value(100);
  move_object(vpainting, this_object());

  vcrown = clone_object("obj/armor");
  vcrown->set_name("golden crown");
  vcrown->set_alias("crown");
  vcrown->set_short("A golden crown");
  vcrown->set_long("This is a goldne crown. It is probably very expensive,\n"+
                   "and has possibly once belonged to a great king.\n"+
                   "As a helmet, however, it would be worse than nothing.\n");
  vcrown->set_weight(3);
  vcrown->set_ac(-1);
  vcrown->set_type("helmet");
  vcrown->set_value(5000);
  move_object(vcrown, this_object());

  vsword = clone_object("obj/weapon");
  vsword->set_name("golden sword");
  vsword->set_alias("sword");
  vsword->set_short("A golden sword");
  vsword->set_long("This is a sword made of gold\n"+
                   "It is not very useful as a weapon, but hideously expensive.\n");
  vsword->set_class(5);
  vsword->set_weight(5);
  vsword->set_value(3000);
  move_object(vsword, this_object());

  vkey = clone_object("obj/key");
  vkey->set_type("panzer");
  vkey->set_code("walkercell");
  move_object(vkey, this_object());
}
