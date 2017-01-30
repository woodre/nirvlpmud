dark_intr() {
object ob;

ob = present("necro_ob",tp);

write("spell disabled\n");
return 1;
if(tp->query_sp() < 100) {
write("The Dark Intrusion requires more spell points.\n");
return 1; }
if((ob->query_blood() < 5) || (ob->query_eye() < 2) || (ob->query_heart() < 1)) {
write("You do not have the components available for this spell.\n");
return 1; }
if(!present("cdust",this_player())) {
write("You must have some Corpse Dust to cast this spell.\n");
return 1; }

if(present("badmoon",environment(tp))){
  write("You can only have 1 Bad Moon in effect at any given time.\n");
return 1; } else {
  move_object(clone_object("/players/daranath/guild/obj/misc/badmoon.c"),environment(tp));
  write("You summon a badmoon.\n");

tp->add_spell_points(-20);
ob->add_blood(-2);
ob->save_me();
return 1; }
}
