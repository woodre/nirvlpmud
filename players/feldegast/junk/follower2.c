inherit "/obj/monster";

string follow;
reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("mons");
  set_alt_name("mons");
  set_alias("mons");
  set_short("mons");
  set_long("follower\n");
  set_race("stranger");
  set_level(10);
  set_wc(15);
  set_ac(10);
  set_hp(145);
  set_al(-500);
  set_aggressive(0);
   follow = "";
  call_out("follow_it",3);
}
follow_it() {
 string blah,junk;
    if( attacker_ob ) {
        follow = attacker_ob->query_real_name();
    }
    if(follow == "" ) {
      call_out("follow_it",10);
      return 0;
   }
   if(environment(this_object()) != environment(find_player(follow))) {
    move_object(this_object(),environment(find_player(follow)));
    }
    call_out("follow_it",3);
}
