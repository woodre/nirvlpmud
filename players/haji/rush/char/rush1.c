inherit "obj/monster.c";

reset(arg) {
    ::reset(arg);
    if (arg)
	return;
    set_name("rush");
    set_level(19);
    set_hp(99999);
    set_wc(10);
    set_ac(2000000);
   set_no_clean(3);
    set_short("Rush Limbaugh");
 set_long("He looks as if he is America's last hope against liberals.\n");
    set_alias("rush");
    set_function("gives");
    set_type("gives");
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
gives(str) {
  string who,what,whom;
  object obj, next_obj,dude;
  int found;

  if(sscanf(str,"%s gives %s to %s.\n",who,what,whom) != 3)
    return;
  if(whom != "Rush")
    return;
  if(what == "diary") {
    obj = first_inventory(this_object());
    if(!call_other(obj,"id","diary")) {
      notify("Rush says: This isn't what I want!!!!.\n");
      notify("Rush gives "+what+" to "+who+".\n");
      move_object(obj,find_living(lower_case(who)));
      return;
    }
    if(call_other(obj,"query_value") != 47) {
      notify("Rush says: This isn't the right diary.\n");
      notify("Rush says: You shoudn't try to fool me "+who+".\n");
      destruct(obj);
      return;
    }
    notify("Rush says: Well done you have brought me the diary.\n");
    notify("Rush says: You may now continue on with the quest.\n");
    notify("Rush signs the diary and drops it.\n");
destruct(obj);
    dude=clone_object("players/haji/quest/diarysub");
    say("pick up the diary so you may continue your quest.\n");
    write("pick up the diary so you may proceed.\n");
    move_object(dude,this_object());
    return 1;
   }
}

notify(str) {
   write(str);
   say(str);
}
