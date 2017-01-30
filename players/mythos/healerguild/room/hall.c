#include "/players/mythos/healerguild/def.h"
static int temp;
int lev;

id(str) { return str == "hall" || str == "guildhall" || str == "healerhall"; }

short() { return "Great Hall of Healing"; }

long() {
   write("You stand in a great marble hall.  The walls stretch high above and \n"+
         "come together as a dome.  People walk by unhurriedly but quietly.  \n"+
         "Those who speak, converse in whispers.  At the far wall a great globe\n"+
         "of light suspends in the air, illuminating the hall with its gentle light.\n"+
         "At the center of the hall lies a large jade tablet.\n"+
         "The obvious exists are: chamber, church, post, and study.\n");
}

reset(arg) {
  if(!present("healer_board")) move_object(clone_object("/"+root+"obj/board.c"),TO);
  if(!present("tophealerslist")) move_object(clone_object("/"+root+"obj/list.c"),TO);
  if(!present("refer")) move_object(clone_object("/"+root+"obj/recruit.c"),TO);
  if(arg) return;
  set_light(2);
  temp = 0;
}

init() {
    if(!this_player()->query_npc()){
        move_object(this_player(), "/players/guilds/healers/room/hall.c");
        return;
    }
  add_action("chamber","chamber");
  add_action("church","church");
  add_action("study","study");
  add_action("join","join");
  add_action("history","history_heal");
  add_action("members","members");
  add_action("help","help_heal");
  add_action("help","hhelp");
  add_action("post","post");
  add_action("look_at","look");
  add_action("look_at","l");
}

post() {
  tp->move_player("post#room/post.c");
return 1; }

look_at(str) {
  if(str) {
    if(str == "tablet" || str == "at tablet") {
      write("\n");
       cat("/"+root+"obj/tablet");
      write("\n");
    return 1; }
  }
}

history() {
  call_other(POWER,"history");
return 1; }

help(str) {
  call_other(POWER,"help",str);
return 1; }

chamber() {
  tp->move_player("chamber#players/mythos/enterance.c");
return 1; }

church() {
  tp->move_player("church#room/church.c");
return 1; }

study() {
object pstudy;
  if(!check(tp)) { write("Only a healer may enter her own private study.\n"); return 1;  }
  if(!tp->query_invis()) say(tp->query_name()+" leaves to "+tp->query_possessive()+ " study.\n");
  pstudy = clone_object(root+"room/study.c");
  pstudy->set_ownn(tpn);
  move_object(tp,pstudy);
  write("You open the door to your study and walk in.\n\n");
  command("look",tp);
return 1; }

join() {
  if(check(tp)) {
    study();
  return 1; }
    if(tl < 5) { write("You must be at least level 5 to join.\n"); return 1; }
     if(tp->query_guild_name() || tp->query_guild_rank() || tp->query_guild_file() || tp->query_guild_exp()) {
    write("I am sorry.  However, only someone who is unconnected to any other\n"+
          "guild may join the Healers.  If you are not in any guild, then your\n"+
          " player file may have an error.  Please speak with a guild wiz.\n");
  return 1; }
  if(tl + tx > 5) {
      write("If you wish to join the Healers, you must be willing to dedicate\n"+
            "your life to it.  To dedicate, one must be willing to start  from the\n"+
            "beginning.....\nHit 'Y' if you are willing to be reduced to level 5:  ");
      input_to("accept");
  return 1; }
   if(this_player()->query_exp() > 10000) {
     this_player()->add_exp(10000 - this_player()->query_exp());
     this_player()->set_level(5);
    tp->set_extra_level(0);
     command("save",tp);
   }
  say(tp->query_real_name()+" is led to the inner chambers by an acolyte.\n");
  write("An acolyte bows to you and leads you to the inner chambers.\n\n");
  move_object(tp,clone_object("/"+root+"room/inner.c"));
  command("look",tp);
return 1; }

accept(str) {
  if(!str) { write("Hit 'Y' if you are willing to be reduced to level 5 :  "); input_to("accept"); return 1; }
  if(str != "Y" && str != "y") {
  write("Thank you for considering the Healers.\n");
  return 1;
  }
     this_player()->add_exp(10000 - this_player()->query_exp());
     this_player()->set_level(5);
     command("save",tp);
  say(tp->query_real_name()+" is led to the inner chambers by an acolyte.\n");
  write("An acolyte bows to you and leads you to the inner chambers.\n\n");
  move_object(tp,clone_object("/"+root+"room/inner.c"));
  command("look",tp);
return 1; }


check(object ob) {
   if(restore_object(MEM+ob->query_real_name()) ) return 1;
   return 0;
}

members() {
  say(tp->query_name()+ " views the Members List.\n");
  write("\nOrder of Healers' Members:\n\n\t");
  more(tp);
return 1; }

more(object ob,arg) {
int h,start;
string meow, moo, space;
string who;
  if(!arg) start = 0; else start = arg;
  h = 0;
  meow = get_dir("/"+MEM);
  while(start < sizeof(meow)) {

    if(meow[start] != "left") {
      sscanf(meow[start],"%s.o",who);
      while(strlen(who) < 12) who = who+" ";;
      tell_object(ob,who); h = h+1; }

    if(h == 5) { tell_object(ob,"\n\t");   h = 0; }
    start = start + 1;
  }
  tell_object(ob,"\n");
  return 1;
}

oks(str) {
  if(!str) { more(tp,temp); return 1; }
  if(str == "y" || str == "Y") { more(tp,temp);  return 1; }
  temp = 0;
  tell_room(TO,tp->query_name()+" stops viewing the Members List.\n");
return 1;}

drop() { return 1; }
get() { return 0; }

realm() { return "NT"; }

query_no_fight() { return 1; }
