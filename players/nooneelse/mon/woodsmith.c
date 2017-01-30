/*
  woodsmith.c
*/

inherit "obj/monster";

int got_hide, got_branch;

reset(arg) {
  object obj;
 ::reset(arg);
  if(arg) return;
  set_name("fred");
  set_level(15);
  set_alias("woodsmith");
  set_race("human");
  set_hp(500);
  set_al(0);
  set_short("An old woodsmith");
  set_long("An old man, who looks like he's experienced with "+
           "woodworking tools.\n");
  set_wc(16);
  set_ac(6);
  set_aggressive(0);
  set_chat_chance(25);
  load_chat("The Woodsmith says: I'm sure gonna need a bear hide"+
            " this winter.\n");
  load_chat("The Woodsmith says: It's gonna be a really cold winter.\n");
  load_chat("The Woodsmith says: I'll trade some woodworking for a hide.\n");
  set_gender("male");
  set_alt_name("smith");
  obj=clone_object("obj/money");
  obj->set_money(100);
  move_object(obj, this_object());
}

init() {
  ::init();

  add_action("say",       "say");
  add_action("get_hide",  "give");
  add_action("get_hide",  "hand");
}

say(str) {
  string a, b, c, message;
   if(!str) return 0;
  a="x"+str+"x";
  if (sscanf(a, "stake%s", b)==1 ||
      sscanf(a, "%sstake", b)==1 ||
      sscanf(a, "%sstake%s", b, c)==2) {
    tell_my_room(str);
    write("You say: "+str+"\n");
    tell_room(environment(),
              "The Woodsmith says: Stake?  I'll trade you "+
              "one for a bear hide.\n");
    return 1;
  }
  if (sscanf(a, "branch%s", b)==1 ||
      sscanf(a, "%sbranch", b)==1 ||
      sscanf(a, "%sbranch%s", b, c)==2) {
    tell_my_room(str);
    write("You say: "+str+"\n");
    tell_room(environment(),
              "The Woodsmith says: Branch?  I'll carve one "+
              "into a stake for you\n"+
              "if you give me a bear hide.\n");
    return 1;
  }
  if (sscanf(a, "woodwork%s", b)==1 ||
      sscanf(a, "%swoodwork", b)==1 ||
      sscanf(a, "%swoodwork%s", b, c)==2) {
    tell_my_room(str);
    write("You say: "+str+"\n");
    tell_room(environment(),
              "The Woodsmith says: Woodworking?  I'll carve a branch "+
              "into a\n"+
              "stake for you if you give me a bear hide.\n");
    return 1;
  }
  if (sscanf(a, "hide%s", b)==1 ||
      sscanf(a, "%shide", b)==1 ||
      sscanf(a, "%shide%s", b, c)==2) {
    tell_my_room(str);
    write("You say: "+str+"\n");
    tell_room(environment(),
              "The Woodsmith says: Hide?  You have one?  I'll trade "+
              "you a stake\n"+
              "                    for a bear hide.\n");
    return 1;
  }
  return 0;
}

/* tell my room, but not me (need this instead of say for this critter) */
tell_my_room(str) {
  object w_here;
  w_here = first_inventory(environment());
  while (w_here) {
    if (living(w_here) &&
        !w_here->query_npc() &&
        w_here != this_player()) {
      tell_object(w_here, this_player()->query_name()+" says: "+str+"\n");
    }
    w_here=next_inventory(w_here);
  }
  return 1;
}

get_hide(str) {
  object skin_obj, hide_obj, branch_obj;
  string str2;
  if (!str) return 0;
  str2=0;

  /* hide & skin stuff */
  skin_obj=present("nooneelsebearskin", this_player());
  hide_obj=present("nooneelsebearhide", this_player());
  sscanf(str, "skin to %s", str2);
  if (str2=="woodsmith" || str2=="man" || str2=="smith") {
    if (!skin_obj) {
      say("What?  You don't have a bear skin!\n");
      return 1;
    }
    say("What?  That's not what I wanted!  I need a whole bear hide!\n");
    return 1;
  }
  sscanf(str, "hide to %s", str2);
  if (str2=="woodsmith" || str2=="man" || str2=="smith") {
    if (skin_obj && !hide_obj) {
      say("What?  You don't have a bear hide!  That's just a torn up\n"+
          "old bear skin!\n");
      return 1;
    }
    if (!hide_obj) {
      say("What?  You don't have a bear hide!\n");
      return 1;
    }
    got_hide=1;
    destruct(hide_obj);
    say("The Woodsmith says: Thank you.\n");
    if (!got_branch)
      say("                    Now I need an oak branch.\n");
    if (got_branch && got_hide) swap_hide();
    return 1;
  }

  /* branch stuff */
  sscanf(str, "branch to %s", str2);
  if (str2=="woodsmith" || str2=="man" || str2=="smith") {
    branch_obj=present("nooneelseoakbranch", this_player());
    if (!branch_obj) {
      say("What?  You don't have an oak branch!\n");
      return 1;
    }
    got_branch=1;
    destruct(branch_obj);
    say("The Woodsmith says: Thank you.\n");
    if (!got_hide)
      say("                    Now I need a bear hide.\n");
    if (got_branch && got_hide) swap_hide();
    return 1;
  }
}

swap_hide() {
  object obj;
  obj=clone_object("players/nooneelse/obj/stake2");
  move_object(obj, environment(this_object()));
  say("The Woodsmith says:  Alright!  That's what I wanted!  Thank you.\n"+
      "He drops a stout oak stake.\n");
  got_hide=0;
  got_branch=0;
  return 1;
}
