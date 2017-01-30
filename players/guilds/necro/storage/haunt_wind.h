haunt_wind(str) {
object targ,ob,ob2;

ob = present("necro_ob",tp);

if(!str) {
write("Who do you want to sick the Haunting Wind upon?\n");
return 1; }

targ = present(str,environment(tp));

if(tp->query_sp() < 35) {
write("You do not have the spell points available for the spell.\n");
return 1; }
if((ob->query_blood() < 4) || (ob->query_eye() < 1)) {
write("You do not have the components available for this spell.\n");
return 1; }

if(present("windhaunt",targ)) {
  write(targ+" is already besieged by a Haunting Wind.\n"); return 1; }

write("You contact the Realm of Death and summon a spirit to aid you.\n"+
      "A Haunting Wind appears and attacks "+targ->query_name()+".\n");
say(tp->query_name()+" casts a dark spell.\n");
ob2 = clone_object("/players/daranath/guild/obj/misc/windhaunt.c");
move_object(ob2,targ);

tp->add_spell_points(-35);
ob->add_eye(-1);
ob->add_blood(-4);
ob->save_me();
return 1; 
}
