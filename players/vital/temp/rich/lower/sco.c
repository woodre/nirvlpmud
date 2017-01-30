/*
 * This is a scotty down deamon, that will take care of scottyting down
 * the game.
 * Call the function "scotty" with a number of seconds as an
 * argument.
 * Don't clone this object.
 */

inherit "obj/monster.c";

reset(arg) {
    ::reset(arg);
    if (arg)
	return;
    set_name("scotty");
    set_level(19);
    set_hp(599);
    set_wc(35);
    set_ac(21);
   set_no_clean(3);
    set_short("Scotty the miracle worker");
    set_long("He looks like he enjoys to fix his ship.\n");
    set_alias("scotty");
    set_chat_chance(40);
     load_chat("Scotty says: Oh me poor bairns!!!!\n");
     load_chat("Scotty says: She'll not take much more of this Captain!!!!\n");
     load_chat("Scotty says: I estimate that it will take\n" +
                "8 days to fix the problem, but I'll do it in 2!!!!\n");
}

init() {
  ::init();
  add_action("No_way","insanity");
  add_action("No_way","symbol");
}

No_way() {
  write("Scotty dodges your spell deftly.\n");
  return 1; }

catch_tell(str) {
    string who, what,why;
    string where;
    object ob;

    if (sscanf(str, "%s beam %s", who, what) != 2)
	return;
/* Added by Mizan (to counter age-old bug) */
  if(this_player()->query_attack()) {
    tell_object(this_player(),"Scotty tells you: I can't get a lock on ya!!!\n");
    return 1;
  }
  if(environment(this_player())->realm() == "NT") {
    tell_object(this_player(),"Scotty tells you: There's too much interference near ya.. I canna do it!!!\n");
    return 1;
  }

/* END addition */
     if(this_player()->query_sp() < 80){ write("You do not have the power.\n");
     return 1; } this_player()->add_spell_point(-80); 
     if(where = call_other("obj/base_tele","teleport"))
               this_player()->move_player("with an astonished look#"+where);
    else {
    tell_object(this_player(),"Scotty tells you: Aye beaming you up now!!!!\n");
    write("You have a strange feeling.\n");
    write("You see your see your own body from above.\n");
    write("You`re not dead.\n");
    write("You are in a transporter beam.\n");
    write("You rematerialize.\n");
    write("\n");
    write("To get healed either go all the way n to pub,\n");
    write("or go to upper level all the way s in main hallway.\n");
    write("To sell something go to the quartermasters[n,n,w,n].\n");
    write("\n");
    write("also if you have any characters related to sci-fi you would like\n");
    write("to kill,send me(rich) a mail message and i`ll see what i can do.\n");
if(environment(this_player())->realm() == "NT") {
    write("However, You suddenly feel a pull on your body and you are yanked back to where you were.\n");
    command("look",this_player());
    return 1;
    }
    this_player()->move_player("Vanishes in a transporter beam#players/rich/trans_room");
    tell_object(this_player(),"Scotty tells you: Welcome to the Enterprise!!!!\n");
   }
return;
}
