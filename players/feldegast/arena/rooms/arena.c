#include "/players/feldegast/defines.h"
#define P1 player1
#define P2 player2
#define LOG_FILE "/players/feldegast/log/arena.log"
#include "std.h"

object player1,player2;

int *options;

int hp, hp2;

status gate;

reset(arg) {
  if(arg) return;
  set_light(1);
  enable_commands(); /* This is to enable the catch_tell */
}

init() {
  call_out("heart_beat",1);
  this_player()->set_fight_area();
  add_action("out","out");
  add_action("open","open");
  add_action("quit","quit");
  add_action("cmd_call","call");
  add_action("fix_hb","fix_hb");
  add_action("arena_help","arena_help");
  add_action("logme","logtgac");
  command("look",this_player());
}
short() {
  return "The Pit";
}
long() {
  write(
"     This is the central arena of the coliseum.  It is a huge open\n"+
"area covered in sand and with stone walls rising twenty feet above\n"+
"your head to where the viewing galleries are.  A huge gate is the only\n"+
"way out, and it can only be opened when only one warrior still stands.\n"+
"You may type 'arena_help' for more information.\n"+
"\tThere is one obvious exit: out\n"
  );
}
query_NM() {
  return options[4];
}
/* The gate cannot be opened */
open(arg) {
  if(arg=="gate") {
    write("The gate is barred shut on the other side.\n");
    return 1;
  }
}
arena_help() {
  cat("/players/feldegast/arena/rooms/arena_msg.txt");
  return 1;
}
cmd_call(str) {
  if(str=="tie") {
    tell_room(this_object(),this_player()->query_name()+" wishes to call a tie.\n");
    if(this_player()==player1) {
      move_object(clone_object("/players/feldegast/arena/misc/tie_ob"),player2);
      tell_object(player2,"Type 'accept' if you wish to call a tie.\n");
    }
    if(this_player()==player2) {
      move_object(clone_object("/players/feldegast/arena/misc/tie_ob"),player1);
      tell_object(player1,"Type 'accept' if you wish to call a tie.\n");
    }
    return 1;
  }
  notify_fail("Call what?  A tie?\n");
}
fix_hb() {
  TP->set_heart_beat(1);
  TP->heart_beat();
  call_other(this_player(),"reset",1);
  write("Attempting to fix heart_beat...\n");
  write_file("/players/feldegast/log/problem.log",ctime(time())+" "+"used fix_hb\n");
  return 1;
}
/* You may leave the arena if your opponent isn't present for some */
/* reason or if you've won your match.  When you leave, the arena */
/* object is destroyed, and the arena is destroyed after you leave. */
out(arg) {
  if(!player1 || !player2 ) gate=1;
  if (gate || arg=="snafu") {
    this_player()->clear_fight_area();
    this_player()->move_player("out#/players/feldegast/arena/rooms/inner");
    destruct(this_object());
    destruct(present("arena_ob",this_player()));
    return 1;
  }
  write("You may not leave the arena until your opponent has been defeated.\n");
  return 1;
}
/* Quitting is not allowed. */
quit() {
  if(find_living("armageddon")) { /* Duh! */
     return 0;
  }
  write("You can't quit now!  You're in the middle of a match!\n");
  return 1;
}
/* The arena is a no teleport area. */
realm() { return "NT"; }

/* These set the name of the two players */
set_p1(x) { player1=x; }
set_p2(x) { player2=x; }

query_p1() { return player1; }
query_p2() { return player2; }
/* These player determined options are set by the challenge object */
set_options(arg) {options=arg;}

/* This catches anything said inside the room and sends it to */
/* the stands. */
catch_tell(str) {
  tell_room("/players/feldegast/arena/rooms/stands1","*"+str);
}
open_gate() {
  gate=1;
  tell_room(this_object(),"The gate swings open.  You may leave 'out'.\n");
}

/* This is called in the event of a deathmatch victory. */
handle_death(ob) {
  object winner, loser;
  object corpse;
  if(!options[3]) {
    tell_room(this_object(),"\n\n"+capitalize(ob->query_real_name())+" HAS DIED!\n\n");
    tell_room(this_object(),"A pair of attendants come in and drag his corpse to the recovery room.\n");
  }
  else {
    tell_room(this_object(),"\n\n"+capitalize(ob->query_real_name())+" succumbs to "+ob->query_possessive()+" wounds and falls to the ground.\n");
    tell_room(this_object(),"\nA pair of attendants drag "+ob->query_objective()+" out of the arena.\n");
  }
  corpse=present("corpse");
  move_object(corpse,"/players/feldegast/arena/rooms/recovery");
  if(ob==player1) {
    winner=player2; loser=player1;
  } else {
    winner=player1; loser=player2;
  }
  if(options[3])
    command("logtgac "+ctime(time())+" "+winner->query_name()+" defeated "+capitalize(loser->query_real_name())+". [B]\n",winner);
  else
    command("logtgac "+ctime(time())+" "+winner->query_name()+" defeated "+capitalize(loser->query_real_name())+". [D]\n",winner);
  move_object(ob,"/players/feldegast/arena/rooms/recovery");
  command("regenerate",ob);
  command("get corpse",ob);
  open_gate();
}

heart_beat() {
  while(remove_call_out("heart_beat")!=-1) ;
/* Check if anybody has died. */
  if(player1->query_ghost()) handle_death(player1);
  if(player2->query_ghost()) handle_death(player2);

/* This is a hit point monitor that also checks for a bloodwin victory. */
  call_out("heart_beat",1);
}
stop_all_combat(ob) {
  ob->stop_fight();
  ob->stop_fight();
  ob->stop_hunter();
}
exit() {
  if(this_player()) this_player()->clear_fight_area();
  return 1;
}
int logme(string str) {
  write_file(LOG_FILE,str);
  return 1;
}
query_spar_area() {
  return options[3];
}
