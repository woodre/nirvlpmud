/* A stand-in for Moogle until I can figgur out a way to make it less
  resource-demanding! */
inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("fungoid");
    set_race("fungoid");
    set_alias("fungoid");
    set_ep(37000);
    set_short("A Fungoid");
    set_long("  This is a squat, solid-looking creature that resembles a \n"+
    "  mushroom. It seems to scowl at you silently, and you have the blessed\n"+
    "  urge to kill it, and satisfy the cruel and ruthless side of your spirit.\n");
    set_level(7);
    set_hp(100+ random(45));
    set_al(-1000);
    set_wc(12);
    set_ac(8);
    set_chance(20);
    set_spell_dam(11);
    set_spell_mess1("Fungoid blasts you with a cloud of spores!");
    set_spell_mess2("Fungoid emits a foul odor in your general direction.");
    set_chat_chance(2);
    load_chat("Fungoid makes chirping noises.\n");
    load_chat("Fungoid shakes nervously.\n");
    load_chat("Fungoid tells you: eh?\n");
    gold=clone_object("obj/money");
    gold->set_money(random(300)+400);
    move_object(gold,this_object());
}
