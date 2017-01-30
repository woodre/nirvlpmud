buried_alive() {
object ob;

ob = present("necro_ob",tp);

if(tp->query_sp() < 35) {
write("You do not have the spell points available for the burial.\n");
return 1; }
if(ob->query_blood() < 2) {
write("You do not have the components available for this spell.\n");
return 1; }
if(!present("corpse dust",tp)) {
write("You do not have the corpse dust neccessary for this spell.\n");
return 1; }

if((!present("gsite_ob",environment(tp))) && (!(environment(tp)->gravesite()))) {
  write("This needs to be done at a consecrated gravesite.\n");
return 1; }

if(!present("grave_heal",environment(tp))) {
  move_object(clone_object("/players/daranath/guild/obj/misc/grave_heal.c"),environment(tp));
write("You sprinkle the corpse dust across the ground, infusing power from\n"+
      "the Realm of Death into the grave.\n");
write("You open a grave that has not seen the light of day for years.\n"+
      "Only a necromancer can appriciate the irony.\n");

tp->add_spell_points(-35);
destruct(present("corpse dust",this_player()));
ob->add_blood(-2);
ob->save_me();
return 1; 
} else {
write("There is already an open gravesite here.\n"+
      "Perhaps another site would be better.\n");
return 1; }
}

