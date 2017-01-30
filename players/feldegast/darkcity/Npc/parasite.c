
inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("parasite");
  set_alt_name("spider");
  set_alias("stranger");
  set_short("Spider Parasite");
  set_long(
"This strange, insect-like creature is covered in blood and\n"+
"gore.  Although small, no larger than a basketball, it moves\n"+
"swiftly and gracefully.  It is also protected by a\n"+
"tough, chitinous carapace.\n"
);
  set_race("stranger");
  set_level(10);
  set_wc(15);
  set_ac(10);
  set_hp(145);
  set_al(-500);
  set_chat_chance(8);
  load_chat("The parasite skitters about franticly.\n");
  set_a_chat_chance(7);
  load_a_chat("The parasite deftly avoids your blows.\n");
  load_a_chat("The parasite nips at your flesh.\n");
  set_aggressive(1);
  call_out("follow_it",4);
}
follow_it() {
  string blah,junk;
  if(!attacker_ob) return;
  if(!present(attacker_ob,environment(this_object())) &&
     sscanf(file_name(environment(attacker_ob)),"%sdarkcity%s",blah,junk)>0)
    move_object(this_object(),environment(attacker_ob));
  call_out("follow_it",4);
}
init() {
  ::init();
  if(!attacker_ob && !this_player()->is_npc()) {
    attack_object(this_player());
    call_out("follow_it",4);
  }
}
