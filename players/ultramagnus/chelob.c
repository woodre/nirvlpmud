inherit "obj/monster.c";

reset(arg)
{
    set_heart_beat(1);
set_name("chelob");
/* Added by Snow 3/00 */
set_alt_name("spider");
set_wc(26);
set_ac(20);
set_level(20);
set_al(-300);
set_hp(950);
set_aggressive(1);
set_short("Chelob");
set_long("A Gigantic Spider with Thousands of Red Eyes!!!\n" +
       "Venom oozes from its Hideous mouth to the webbing below...!!!\n" +
       "It looks hungry for Living Meat...!!!...\n");
set_chance(30);
set_spell_dam(35);
set_spell_mess1("Chelob sinks her fangs into her foe!\n");
set_spell_mess2("Chelob sinks her fangs into you!\n");
::reset(0);
}
