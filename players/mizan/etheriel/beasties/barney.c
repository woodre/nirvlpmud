inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/RandomMove.c"

reset(arg)
{
    object gold;
    ::reset(arg);
    if(arg) return;
    set_name("barney");
    set_name("barney");
    set_alias("barney");
    set_short("Barney the purple dinosaur");
    set_long("This is Barney the ever-happy and ever-annoying dinosaur.\n"+
    "He prances about happily, jerking and twitching spasmodically,\n"+
    "and you have the intense, burning desire to sharpen your weapons\n"+
    "on his flesh.\n");
    set_level(6);
    set_hp(100);
    set_al(1000);
    set_wc(12);
    set_ac(3);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("Barney says: Hey! That's not very nice!");
    set_spell_mess2("Barney cries: That hurts!");
    set_chat_chance(20);
    load_chat("Barney sings: I love you, you love me...\n");
    load_chat("Barney says: Duhh! Hi kids! Duhh!\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
}
