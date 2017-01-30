dis_burial() {

object ob,ob2,ob3;

ob2 = (present("necro_ob",tp));
ob3 = (present("gsite_ob",environment(tp)));

/* Checks put in by Snow 2/00 */
if(!ob2 || !ob3) { write("Spell failure.\n"); return 1; }
if(!creator(environment(tp))) { write("You cannot use this ability here.\n"); return 1; }
if(tp->query_sp() < 20) {
write("You do not have the spell points for this.\n");
return 1; }
if(ob2->query_blood() < 1) {
write("You do not have the spell components available for this spell.\n");
return 1; }
if(ob3->query_burial_check() == 0) {
write("The corpse has already been dug up here, perhaps you could\n"+
      "try again in another gravesite.\n");
say(tp->query_name()+" examines the gravesite and decides to dig somewhere else.\n");
return 1; }

if(present("gsite_ob",environment(tp))){
tp->add_spell_points(-20);
ob2->add_blood(-1);
ob2->save_me();
ob2->add_val(2);

if(random(4) > 5) {
  write("You dig up a nice, fresh corpse....\n"+
        "But it seems a bit upset...\n");
  ob = clone_object("/players/daranath/guild/mon/upset_spirit.c");
  move_object(ob,environment(tp));
  ob->attack_object(tp);
return 1;
} else {
  ob = clone_object("obj/corpse.c");
  ob->set_name("an unknown person");
  ob->set_corpse_level(12);
  ob3->set_burial_check(0);
  move_object(ob,environment(tp));
  write("You dig up a nice, fresh corpse.\n");
 return 1; }
} else {
write("This needs to be done in a gravesite.\n");
return 1; 
}
}
