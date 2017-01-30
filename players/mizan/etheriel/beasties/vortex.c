inherit "/players/mizan/core/monster.c";
#include "/players/mizan/closed/NewbieGuard.c"

reset(arg)
{
    object gold,armor,weapon;
    ::reset(arg);
    if(arg) return;
    set_name("vortex");
    set_race("vortex");
    set_alias("vortex");
    set_short("A shimmering blue vortex");
    set_long("  This is a shimmering blue vortex, shifting and changing size before\n"+
    "  your very eyes. As you gaze into it, you feel enchanted by the singing that\n"+
    "  is coming from inside... It seems that a million tingling sensations cross\n"+
    "  your spine, and you have the intense urge to 'dive vortex'. However, you\n"+
    "  are not sure if it is truly a good idea to do so...\n");
    set_level(17);
    set_hp(520);
    set_al(-1000);
    set_wc(27);
    set_ac(16);
    set_chance(60);
    set_spell_dam(34);
    set_spell_mess1("You are blinded with a dizzying flash.");
    set_spell_mess2("You hear a voice cry out: No! No.... no....");
    set_chat_chance(20);
    load_chat("You hear a voice say: ..come.. with me... into a deep... blue.. sea..\n");
    load_chat("You hear a voice say: ..deeper inside.. i'll make you mine...\n");
    load_chat("The vortex swirls and dilates.\n");
    load_chat("The vortex glows brightly for a moment, and turns into a rich navy blue.\n");
    load_chat("You hear swirling and slushing sounds coming from the vortex.\n");
    gold=clone_object("obj/money");
    gold->set_money(random(100)+5000);
    move_object(gold,this_object());
}

init() {
  ::init();
  add_action("dive","dive");
}

dive(str) {
    if(!str || str !="vortex") return 0;
    if(this_player()->query_level() < 12) 
    {
        write("You don't think that would be a good idea...\n");
        return 1;
    }
    write_file("/players/mizan/logs/SUBREALM_WATCHLAR", (this_player()->query_real_name()) + " found the vortex at " + ctime() + "\n");
    write("You dive into the vortex and appear somewhere else...\n\n");
    this_player()->move_player("into the vortex#players/mizan/w/w1");
    return 1;
}

query_permanency() { return 1; }
