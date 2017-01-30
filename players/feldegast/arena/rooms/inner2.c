#include "/players/feldegast/closed/shortcut.h"
#define BLOOD 60
inherit "room/room";
int *npc=({1,1,1,1});
int in_use;
reset(arg) {
  npc=allocate(4);
  npc=({1,1,1,1});
  if (arg) return;
  set_light(1);
  short_desc="The Coliseum's Inner Chamber";
  long_desc=
"     This is a large circular chamber of stone with several gates\n"+
"leading to various arenas.  This is where warriors come to challenge\n"+
"each other and to negotiate fights.  Type 'arena_help' for more\n"+
"information.\n";
  dest_dir=({"/players/feldegast/arena/rooms/foyer","south"});}
init() {
  add_action("arena_help","arena_help");
  add_action("challenge","challenge");
  add_action("south","south");}
south() {
  this_player()->move_player("south#/players/feldegast/arena/rooms/foyer");
  return 1;}
query_no_fight() {return 1;}
arena_help(str) {
  if(!str) cat("/players/feldegast/arena/rooms/arena_msg.txt");
  if(str=="parameters") cat("/players/feldegast/arena/rooms/param_msg.txt");
  if(str=="npc") cat("/players/feldegast/arena/rooms/npc.txt");
  return 1;
}
set_npc(int arg) {
  npc[arg]=0;
}
int challenge_npc(int which) {
  object mon, arena;
  if(npc[which]==0)
    write("That person is still recovering from a previous battle.\n");
  else {
    arena=clone_object("/players/feldegast/arena/rooms/npc_arena");
    switch(which) {
      case 1: mon=clone_object("/players/feldegast/arena/npc/lupus");break;
      case 2: mon=clone_object("/players/feldegast/arena/npc/dana");break;
      case 3: mon=clone_object("/players/feldegast/arena/npc/jikhal");break;
    }
    move_object(mon,arena);
    write("You are led to the arena.\n");
    say(TPN+" leaves north.\n");
    move_object(TP,arena);
  }
  return 1;
}
challenge(arg) {
  object cob;
  int *options;
  int i;  string who, ps;  string *x;
  options=allocate(5);
  if(!arg) { write("Challenge who?\n"); return 1; }
  x=explode(arg," ");
  options=({0,0,0,0,0});
  for(i=0;i<sizeof(x);i++) {
    if(x[i]=="-h"){write("Healing enabled.\n"); options[1]=1;} else
    if(x[i]=="-e"){write("Weapons only enabled.\n"); options[2]=1;} else
    if(x[i]=="-b"){write("Blood match enabled.\n"); options[3]=BLOOD;}
    else who=x[i];
  }
  if(!who) {
    write("Who would you like to challenge?\n");
    return 1;  }
  switch(who) {
    case "lupus": return challenge_npc(1);break;
    case "dana": return challenge_npc(2); break;
    case "jikhal": return challenge_npc(3); break;
  }
  if(!present(who)) {
    write("That person is not here.\n");
    return 1;  }
  if(present(who)==this_player()) {
    write("You can't challenge yourself!\n");
    return 1;  }
  if(present(who)->is_player()) {
    write("You've challenged "+present(who)->query_name()+
    " to enter the arena.\n");
    tell_object(present(who),
      TPN+" has challenged you to enter the arena.\n"+
      "Type 'accept_challenge "+
       this_player()->query_name()+
      "' to fight him.\n"+
      "Type 'refuse' to refuse the challenge.\n"
    );
    if (options[1])
    tell_object(present(who),"Arena heals will be used to even the match.\n");
    if(options[3]) tell_object(present(who),
"It will be a bloodmatch to "+options[3]+" hps.\n");
    cob=clone_object("/players/feldegast/arena/misc/chall_ob");
    move_object(cob,present(who));
    cob->set_opponent(this_player());
    cob->set_options(options);
    return 1;
  }
  write("That player isn't here.\n");
  return 1;
}

exit() {
  if(!this_player()) return 1;
  if(present("challenge_ob",this_player())) {
    write("Destroying challenge object.\n");
    destruct(present("challenge_ob",this_player()));
  }
  return 1;
}
query_in_use() {return in_use;}
set_in_use(arg) { in_use=arg; }
