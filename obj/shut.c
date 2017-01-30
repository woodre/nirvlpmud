/*
 * This is a shut down deamon, that will take care of shutting down
 * the game.
 * Call the function "shut" with a number of seconds as an
 * argument.
 * Don't clone this object.
 */

inherit "obj/monster";

int goingdown, update;

void reset(status arg) {
  ::reset(arg);
  if (arg) return;
  set_name("armageddon");
  set_level(19);
  set_hp(9999999);
  set_wc(50);
  set_ac(20000);
  set_short("Armageddon the game crasher");
  set_long("He looks like he enjoys to stop the game.\n");
  set_alias("shut");
  mmsgin = "Arrives in a puff of smoke";
  move_player("in a puff of smoke#room/church");
}

shut(int seconds) {
  int i;

#ifdef __LDMUD__
  object ack;

  ack = previous_object();
  log_file("LD_SHUT", ctime() + ": " + (ack ? object_name(ack) : "unknown") +
                      " called shut(" + seconds + ").\n");
#endif
#if 0
  if (!"obj/master"->valid_player_call(previous_object())) {
    write("Use: shutdown <reason>\n");
    return 1;
  }
#endif

  if(!this_player()) {
    object blah;
    blah = previous_object();
    if (blah)
      if (extract(object_name(blah),0,2) != "obj") {
        log_file("SHUTDOWN", "Bad shut call from: " + object_name(blah) + " " +
                 ctime(time()) + "\n");
        return;
      }
  }

  if (this_player()) {
    log_file("SHUTDOWN", "shut called by " + this_player()->query_real_name() +
             ctime(time()) + "\n");
    if (this_player()->query_level() < 1000) {
      write("You are of too low of level to shutdown the game.\n");
      return;
    }
  }
  if (!intp(seconds)) {
    write("Bad argument\n");
    return;
  }

  if (!seconds) {
    write("No time given\n");
    return;
  }
  set_long("He is firmly concentrated on counting.\n");
  i = remove_call_out("cont_shutting");
  if (i > 0) {
    i = (i + 10) * 4;
    if (i < seconds) {
      write("There was already a shutdown in process, " + i + " seconds.\n");
      seconds = i;
    }
  }
  call_out("cont_shutting", 0, seconds * 60);
}

int transport_offer;

static cont_shutting(seconds) {
  string delay;
  int new_delay;

  if (seconds <= 0) {
    shout(query_name() + " shouts: I will reboot now.\n");

    if(this_player())
      tell_object(this_player(),cap_name + " tells you: I will reboot now.\n");
/*
#ifdef __LDMUD__
    goingdown = 5;
    call_other("obj/master.c","shut_down_game",0);
#else
*/
    goingdown = 5;
    call_other("obj/master.c","shut_down_game",0);
/*
    shutdown();
#endif
*/
    return;
  }
  if (seconds <= 240 && !transport_offer && !update) {
    shout(query_name() + " shouts: Tell me if you want a trip to the shop !\n");
    "/players/cosmo/hslist/vds_new.c"->update_alltime();
    transport_offer = 1;
    update = 1;
  }
  new_delay = seconds * 3 / 4 - 10;

  /* 10/04/06 Earwax: added remove_call_out() */
  while(remove_call_out("cont_shutting") != -1)
       ;
  call_out("cont_shutting", seconds - new_delay, new_delay);
  delay = "";
  if (seconds > 59) {
    delay = seconds / 60 + " minutes ";
    seconds = seconds % 60;
  }
  if (seconds != 0)
    delay += seconds + " seconds ";
  shout(query_name() + " shouts: Game reboot in " + delay + ".\n");
  if(this_player())
    tell_object(this_player(), query_name() + " tells you: Game reboot in " +
                delay + ".\n");
}

catch_tell(str) {
  string who, what;
  object ob;

  if (!transport_offer)
    return;
  if (sscanf(str, "%smagedd%s", who, what) == 2) return;
  if (sscanf(str, "%s tells you: %s", who, what) != 2)
    return;
  this_player()->move_player("X#room/shop");
}

query_goingdown() { return goingdown; }

shouting(string str) {
  object obj;
  int j;

  obj = users();
  for (j = 0; j < sizeof(obj); j++) {
    if (!obj[j]->query_edit())
      tell_object(obj[j], str);
  }
}

heart_beat() { 
  ::heart_beat(); 
  heal_self(1000000);
}
