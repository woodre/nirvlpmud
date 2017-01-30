inherit "obj/monster";
reset(arg){
  if (!arg) {
    set_name("gargoyle");
    set_alt_name("al");
    set_alias("statue");
    set_short("A stone gargoyle");
    set_long("This is a stone gargoyle.  It looks very heavy.\n"+
             "Before your very eyes, it comes to life!\n");
    set_wc(17);
    set_ac(8);
    set_level(13);
    set_hp(1200);
    set_al(-400);
    set_aggressive(1);
    set_chance(10);
    set_spell_mess2("The gargoyle lashes out and hits you with it's "+
                    "rock talons!\n\n");
    set_spell_mess1("The gargoule hits " + call_other(this_player(),
                    "query_name", 0) + "\n"+"with it's rock talons! \n");
    set_spell_dam(9);
    }
  ::reset(arg);
}
