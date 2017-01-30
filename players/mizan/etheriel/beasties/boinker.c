inherit "/players/mizan/core/monster.c";

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("boinker");
    set_alias("box");
    set_short("A Boinker box");
    set_long("  The boinker is basically a small, squishy box with a big hole\n"+
    "  on one side. There are all sorts of noises coming out of it.\n");
    set_level(6);
    set_hp(100);
    set_al(40);
    set_wc(12);
    set_ac(3);
    set_chance(20);
    set_spell_dam(10);
    set_spell_mess1("Boinker zaps you with a dose of static electricity!");
    set_spell_mess2("Boinker blasts you with a hundred billion screaming electrons!");
    set_chat_chance(14);
    load_chat("Boinker emits: [Announcer] ooooh! And the Beanos recover with a quick flug!!\n");
    load_chat("Boinker emits: [Announcer] Well, we know that a fast replay flug would hurt\n"+
    "the Spucks quite a bit. At least they have their defensive plays down pat.\n");
    load_chat("Boinker emits: [Announcer 2] Wow! the Beanos come through with a sprog!\n");
    load_chat("Boinker emits: [Announcer] The score is tied! What a game!\n");
    load_chat("Boinker emits: [Announcer 2] A quick recovery, that was good.. very good...\n");
    load_chat("Boinker emits: [Announcer] This is a very close game, folks!\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+150);
    move_object(gold,this_object());
}
