/* masterlg.c: master logger, he evaluates and advances */
#define ME this_player()
#define THERE() present("logger pack", ME)
object ob;
inherit "obj/monster";
reset(arg) {
  if(arg) return 0;
  ::reset(arg);
  set_name("logger");
  set_alias("master logger");
  set_short("The Master Logger");
  set_long("An evidentally old, and very wise, man. Compared to you, he is a giant in\n"
          +"size. Only he can tell whether you are capable of handling your abilities.\n"
          +"Commands are: guild_xp <amt>, advance.\n");
  set_wc(50);
  set_ac(50);
  set_hp(50);
  set_ep(5);
  set_level(10);
  ob = clone_object("/players/wizardchild/closed/logger/room/fake_ob.c");
  move_object(ob, this_object());
}
id(str) { return str == "logger" || str == "master logger"; }
init() {
  if(!THERE()) {
    move_object(ME, "room/plane12");
    write_file("/players/wizardchild/closed/logger/room/ILLEGAL_ENTRY", "<"+ctime(time())+"> "+ME->query_real_name()+" | advance\n");
  } else {
    add_action("guild_xp", "guild_xp");
    add_action("advance", "advance");
    add_action("kill", "kill");
  }
  ::init();
}
has_xp(rank) {
  int *xp_arr;
  xp_arr = allocate(9);
  xp_arr = ({0,100,25000,90000,150000,245000,350000,450000,650000});
  if(rank >= 8) {
    write("You cannot advance any higher.\n");
    return 0;
  }
  if(THERE()->query_gxp() >= xp_arr[rank])
    return 1;
  return 0;
}
guild_xp(str) {
  int amt;
  if(!str || sscanf(str, "%d", amt) != 1) {
    write("That is not a valid option.\n");
    return 1;
  }
  if(amt <= 0) {
    write("You cannot get your experience back.\n");
    return 1;
  }
  if(ME->query_exp() < amt || (ME->query_exp()-amt) < 
     "room/adv_guild"->get_next_exp(ME->query_level()-1) ||
     (ME->query_extra_level() && (ME->query_exp()-amt) < 
     "room/exlv_guild"->get_next_exp(ME->query_extra_level()-1))) {
    write("You do not have enough experience.\n");
    return 1;
  }
  write("You swap "+amt+" xp's for guild xp's.\n");
  ME->add_exp(-amt);
  THERE()->add_gxp(amt);
  THERE()->save_me();
  say(ME->query_name()+" exchanges some experience.\n");
  return 1;
}
advance() {
  int i;
  i = THERE()->query_grank()+1;
  if(!has_xp(i)) 
    write("You do not have enough experience to advance to rank "+i+".\n");
  else {
    "/players/wizardchild/closed/logger/masterob"->lmaster(ME->query_name()+" is now rank "+i+"!\n");
    write("Congratulations! You have advanced in the guild!\n");
    write("Review the guild help for info on your new abilities!\n");
    THERE()->set_grank(i);
    THERE()->save_me();
  }
  return 1;
}      
kill(str) {
  if(!id(str)) return 0;
  write("The Master Logger shouts: YOU DARE TO CHALLENGE ME?!?!?\n");
  write("The Master Logger shouts: You do not stand a chance, fool.\n");
  write("Suddenly, the Master Logger waves a hand, and you are elsewhere.\n");
  say(ME->query_name()+" foolishly attacked Master Logger.\n");
  move_object(ME, "room/plane12");
  add_hp(50);
  return 1;
}
