inherit "/players/mizan/core/monster.c";
/* There is a reason why Kero carries all of this weird shit :)
   All I can say otherwise is 'Annie Park the muffin->see Keroleen' [grin]
*/

reset(arg) 
{
    object thing1, thing2, thing3, treasure;
    ::reset(arg);
    if(arg) return;
    set_name("kerokerokeroppi");
    set_race("frog");
    set_alias("kero");
    set_short("Kerokerokeroppi");
    set_long("This thing is a big, green frog. He is floating here and the first\n"+
    "thing that you notice about him are his eyeballs. They're HUGE!!\n"+
    "You even see your complete reflection in his huge eyeballs. No kidding!\n");
    set_level(8);
    set_hp(120);
    set_al(10);
    set_ac(6);
    set_wc(12);
    set_chance(25);
    set_spell_dam(12);
    set_spell_mess1("Kerokerokeroppi goes: Hey! You're a meanie!");
    set_spell_mess2("Kerokerokeroppi goes: Ribbit!");
    set_chat_chance(12);
    load_chat("Kerokerokeroppi licks himself.\n");
    load_chat("Kerokerokeroppi smiles idiotly.\n");
    load_chat("Kerokerokeroppi goes: Where the hell am I?\n");
    load_chat("Kerokerokeroppi cheers: At least I'm not shopping with Keroleen anymore!\n");
    load_chat("Kerokerokeroppi says: I hate it when she drags me around, looking for clothes.\n");
    thing1=clone_object("players/mizan/etheriel/items/ssteel-stick.c");
    move_object(thing1, this_object());
    thing2=clone_object("players/mizan/etheriel/items/kylie.c");
    move_object(thing2, this_object());
    thing3=clone_object("players/mizan/etheriel/items/bone.c");
    move_object(thing3, this_object());
    treasure=clone_object("obj/money");
    treasure->set_money(250);
    move_object(treasure, this_object());
}
