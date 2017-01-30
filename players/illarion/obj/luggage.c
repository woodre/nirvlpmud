inherit "/players/illarion/high/mon/imm_mon";
#include "/players/illarion/dfns.h"
int follow;

reset(arg) {
  ::reset(arg);
  if(arg) return;

  follow=0;
  set_name("The Luggage");
  set_race("sapient pearwood");
  set_short("A large wooden chest with hundreds of legs");
  set_long(
"A perfectly normal looking wooden chest, except that it has hundreds of\n"+
"legs on the bottom, and scurries across the floor at a rapid pace. Depending\n"+
"on when it is opened, it may simply have clothes inside, or it may have\n"+
"an incredible set of teeth.  Some of the things it swallows tend\n"+
"to never be heard from again.  Although it has no eyes, it seems to be\n"+
"looking at you, warning you it would be a bad idea to mess with it.\n");
  set_level(50);
  set_hp(20000);
  set_wc(30);
  set_ac(100);
  add_chat_response("pats you on the head","$pat_response$");
  add_chat_response("kicks you","$kick_response$");
  add_chat_response("tackles you to the ground","$kick_response$");
}
init() {
  ::init();
  add_action("cmd_attend","attend");
}
cmd_attend() {
  if(TP->query_real_name() != "illarion") return 0;
  follow=!follow;
  write("The luggage "+(follow?"starts":"stops")+" following you.\n");
  return 1;
}
id(str) { return ::id(str) || str == "chest" || str == "luggage"; }
heart_beat() {
  object ob;
  if(attacker_ob && (ob=present(attacker_ob,environment(this_object())))) {
    do_swallow(ob);
    attacker_ob=0;
  }
  if(!environment()) {
    set_heart_beat(0);
    return;
  }
  if(follow)
    if(!present("illarion",environment(this_object()))) {
      if((ob=find_player("illarion")) && environment(ob) != this_object()) {
        tell_room(environment(),"The Luggage leaves looking for Illarion.\n");
        move_object(this_object(),environment(ob));
        tell_room(environment(),"The Luggage arrives.\n");
      } else {
        tell_room(environment(this_object()),
          "The Luggage trundles away, looking forlorn.\n");
        destruct(this_object());
      }
    }
  ::heart_beat();
}
pat_response(string str) {
  if(!str) return;
  if(lower_case(str)=="illarion")  
    tell_room(environment(),
        "The Luggage rubs "+capitalize(str)+"'s hand happily.\n");
  else
    tell_room(environment(),
      "The Luggage snaps at "+capitalize(str)+".\n");
}
do_swallow(object ob) {
  tell_object(ob,
    "The Luggage raises its lid...  wooden teeth loom in front of you,\n"+
    "and then with a SNAP you have been swallowed.\n");
  tell_room(environment(ob),
    "The Luggage raises its lid, and shows "+ob->query_name()+" its teeth.\n"+
    "Then, with a SNAP, "+ob->query_name()+" vanishes under the lid.\n",
    ({ob,this_object()}));
  move_object(ob,this_object());
}
kick_response(string str) {
  object ob;
  str=lower_case(str);
  if(member_array(str,({"illarion"})) > -1)
    tell_room(environment(),"The Luggage sulks.\n");
  else {
    if((ob=present(str,environment(this_object()))))
      do_swallow(ob);
  }
}
long() {
  if(environment(TP))
    if(environment(TP)==this_object()) {
      write(
"It's black here.  Not dark, just black.  There is no magic, no landmark,\n"+
"and no escape.\n");
      return;
    }
  ::long();
}
query_no_fight() { return 1; }
realm() { return "NT"; }
