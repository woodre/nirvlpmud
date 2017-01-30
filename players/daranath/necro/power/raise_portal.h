raise_portal() {

object ob;

write("The guild is not open yet.\n");
return 1; 
if(tp->query_sp() < 25) {
write("You do not have the spell points to raise a bone portal\n");
return 1; }
if(present("boneportal",environment(tp))) {
write("There is already a portal of bone within the area.\n");
return 1; }

write("You gather your powers of darkness and raise a bone portal.\n");
say(tp->query_name()+" casts a dark spell and a portal of bone rises from the ground.\n");
ob = clone_object("/players/daranath/guild/obj/misc/portal.c");
move_object(ob,environment(tp));

tp->add_spell_points(-25);
return 1; }
