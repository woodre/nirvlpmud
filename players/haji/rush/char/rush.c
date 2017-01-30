inherit "obj/monster.c";

reset(arg) {
    ::reset(arg);
    if (arg)
	return;
    set_name("rush");
    set_level(19);
    set_hp(99999);
/* NEW CODE TO MODIFY POTENTIAL EXP PROBLEM -Snow 5/00 */
set_hp_bonus(-99000);
    set_wc(10);
    set_ac(2000000);
set_ac_bonus(-1999000);
   set_no_clean(3);
    set_short("Rush Limbaugh");
 set_long("He looks as if he is America's last hope against liberals.\n");
    set_alias("rush");
    set_match(" ");
    set_chat_chance(40);
     load_chat("Rush says: Oh my poor country!!!!\n");
     load_chat("Rush says: America will not take much more of this Mr. President!!!!\n");
        load_chat("Rush says: Billary's motto 'Symbolism over Substance!!!\n");
     load_chat("Rush says: Join the R.U.S.H. club!!!\n");
}
catch_tell(str) {
    string who, what,why;
    object ob,ob1;

    if (sscanf(str, "%s save %s", who, what) != 2)
	return;
    if(call_other(environment(this_player()),"realm")=="NT") {
    write("However, You suddenly feel a pull on your body and you are yanked back to where you were.\n");
    command("look",this_player());
    return 1;
    }
    this_player()->move_player("Vanishes in a golden ray of light#players/haji/rush/ny/gcsta");
    tell_object(this_player(),"Rush tells you: Welcome to New York, enjoy your stay!!!!\n");
return;
}
