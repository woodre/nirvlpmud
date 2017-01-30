#define ENV environment
#define TO this_object()
#define TR tell_room

id(str) { return str == "stun object" || str == "stun_obj"; }

reset() {
  call_out("shockwave",random(20));
}

shockwave() {
  TR(ENV(ENV(TO)),capitalize(ENV(TO)->query_name())+
                 " reels in shock!\n");
  call_other(ENV(TO),"hit_player",random(10)+10);
  ENV(TO)->stop_fight(); ENV(TO)->stop_fight(); ENV(TO)->stop_hunter();
  destruct(TO);
return 1;
}
