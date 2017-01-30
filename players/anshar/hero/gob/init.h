/* INIT */
  init() {
  if(!ENV(TO)) return 1;
  if(!ENV(TO)->is_player()) return 1;
  if(!TP->is_player()) return;
  setup(ENV(TO));
  add_action("hero_reset","sreset");
  add_action("shelp","shelp");
  add_action("shome","shome");
  add_action("stalk", "hero");
  add_action("semote", "heroe");
  add_action("stitle", "stitle");
  add_action("hero_score","score");
  add_action("hero_score","sc");
  add_action("quit_func","quit");
  add_action("no_missile","mi");
  add_action("no_missile","missile"); 
  add_action("no_shock","sh");
  add_action("no_shock","shock"); 
  add_action("no_fireball","fi");
  add_action("no_fireball","fireball"); 
  add_action("no_sonic","so");
  add_action("no_sonic","sonic");
  environment()->set_guild_name("hero");
  "/players/anshar/hero/objects/chatob.c"->resetchannel();
  if(!ingame) { loginmsg(TP); ingame = 1; }
  }

quit_func() { ingame = 0; logoutmsg(); save_me(); return 0; }

loginmsg(ob) {
  string mess, mess2, entermess;
  mess = BOLD+"*"+HIG+"HERO"+NORM+BOLD+"*";
  mess2 = ob->query_name()+" enters the game.";
  entermess = mess+" "+mess2+" "+mess+NORM+"\n";
  if(ob->query_level() < 20)
  CHATOB->send_msg(entermess); return 1; }

logoutmsg() {
  object me;
  string mess, mess2, leavemess;
  me = environment();
  if(!me) return;
  mess = BOLD+"*"+HIG+"HERO"+NORM+BOLD+"*";
  mess2 = me->query_name()+" leaves the game.";
  leavemess = mess+" "+mess2+" "+mess+NORM+"\n";
  if(me->query_level() < 20)
  CHATOB->send_msg(leavemess); return 1; }
