inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg)
        return;
    set_name("scotty");
    set_level(19);
    set_hp(99999);
    set_wc(28);
    set_ac(16);
    set_short("Scotty the miracle worker");
    set_long("He looks like he enjoys to fix his ship.\n");
    set_alias("scotty");
    mmsgin = "beams in" ;
}
catch_tell(str) {
    string who, what,why;
    object ob;
 
    if (sscanf(str, "%s tells you: %s", who, what,why) != 3)
        return;
    tell_object(this_player(),"OK.");
    this_player()->move_player("X#players/rich/trans");
}

