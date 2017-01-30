cons_corp(str) {
string name;
object ob,ob2,dust;

  if(!str) {
write("What would you like to consume?\n");
return 1; }
  if(str == "corpse") {
ob = present("corpse",environment(this_player()));
ob2 = present("necro_ob",tp);

if(!ob) {write("There is no corpse here.\n"); return 1; }
if(tp->query_sp() < 20) {
write("You do not have enough spell points for this ability.\n");
return 1; }
if(ob2->query_blood() < 1) {
write("You do not have the material componets for this spell.\n");
return 1; }
if(sscanf(ob->short(),"corpse of %s",name)) {
write("You whisper a silent prayer to the realm of death.\n"+
      "A pillar of flame descends from the sky and consumes the corpse.\n");
say("A pillar of fire descends from the sky and consumes the corpse.\n");
dust = clone_object("/players/daranath/guild/obj/misc/cdust.c");
dust->set_name(name);
move_object(dust,environment(this_player()));
destruct(ob);
tp->add_spell_points(-20);
ob2->add_blood(-1);
ob2->save_me();
return 1; }
}
  else {
write("That is not something you can consume.\n");
return 1; }
}
