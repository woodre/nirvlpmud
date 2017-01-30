#include "def.h"
#define BLOOD 80

inherit ROOM;

int in_use;

query_spar_area() { return 1; }
query_no_fight() {return 1;}
is_inner() { return 1;}

reset(arg) {
  if (arg) return;
  set_light(1);
  short_desc="The Coliseum's Inner Chamber";
  long_desc=
"     This is a large circular chamber of stone with several gates\n"+
"leading to various arenas.  This is where warriors come to challenge\n"+
"each other and to negotiate fights.  There is a sign here.\n";

  dest_dir=({
    "/players/feldegast/arena/rooms/feld_entrance","east",
    "/players/feldegast/arena/rooms/foyer.c","south",
  });
}

init() {
  ::init();
  
  add_action("arena_help","read");
  add_action("challenge","challenge");
}

cmd_move() {
  if(query_verb()!="south")
    return ::cmd_move();
  this_player()->move_player("south#/players/feldegast/arena/rooms/foyer");
  this_player()->rm_spar();
  return 1;
}

arena_help(str) {
  if(!str) return 0;
  if(str=="sign")
    cat("/players/feldegast/arena/rooms/arena_msg.txt");
  if(str=="parameters")  {cat("/players/feldegast/arena/rooms/param_msg.txt");
  return 1;
  }
  return 1;
}

challenge(arg) {
  object cob;
  object target;
  int *options;
  int i;
  string who, ps;
  string *x;

  options=allocate(5);
  notify_fail("Usage: challenge <player> [-m1|-m2] [-h] [-d] [-b] [-n]\nType 'arena_help' for more information.\n");
  if(!arg) return 0;
  x=explode(arg," ");
  options=({0,0,0,1,0});
  for(i=0;i<sizeof(x);i++) {
    if(x[i]=="-m1" || x[i]=="pit") {write("You will be fighting in The Pit.\n"); options[0]=0;}
    else if(x[i]=="-m2" || x[i]=="feldaria") { write("You will be fighting in Feldaria.\n"); options[0]=1;} 
    else if(x[i]=="-h"){write("Healing enabled.\n"); options[1]=1;}
    else if(x[i]=="-e"){write("Weapons only enabled.\n"); options[2]=1;} 
    else if(x[i]=="-d"){write("It will be to the death.\n"); options[3]=0;} 
    else if(x[i]=="-b"){write("Blood match enabled.\n"); options[3]=1;} 
    else if(x[i]=="-n"){write("Null magic enabled.\n"); options[4]=1;}
    else who=x[i];
  }
  if(!who) {
    write("Who would you like to challenge?\n");
    return 1;
  }

  target=present(who);

  if(!target) {
    write("That person is not here.\n");
    return 1;
  }

  if(target==this_player()) {
    write("You can't challenge yourself!\n");
    return 1;
  }

  if(target->is_player()) {
    write("You've challenged "+target->query_name()+" to enter the arena.\n");
    tell_object(target,
      TPN+" has challenged you to enter the arena.\n"+
      "Type 'accept_challenge "+this_player()->query_name()+"' to fight them.\n"+
      "Type 'refuse' to refuse the challenge.\n"
    );
    if (options[0]==2)
      tell_object(target,"The fight will take place in Feldaria.\n");
    if (options[1])
      tell_object(target,"Arena heals will be used to even the match.\n");

    if(options[3])
      tell_object(target,"It will be a bloodmatch(no experience loss if you die).\n");
    else
      tell_object(target,HIR+"The match will be TO THE DEATH.\n"+NORM);

    if(options[4])
      tell_object(present(who),"No spell casting will be allowed.\n");

    cob=clone_object("/players/feldegast/arena/misc/chall_ob");
    move_object(cob,present(who));
    cob->set_opponent(this_player());
    cob->set_options(options);

    return 1;
  }
}

exit() {
  if(!this_player()) return 1;
  if(present("challenge_ob",this_player())) {
    write("Destroying challenge object.\n");
    destruct(present("challenge_ob",this_player()));
  }
  if(query_verb() != "accept_challenge" && this_player()->query_pl_k() > 1) {
    write("Sparring flag removed.\n");
    this_player()->rm_spar();
    command("save",this_player());
  }
  return 1;
}

query_in_use() { return in_use; }
set_in_use(arg) { in_use=arg; }

