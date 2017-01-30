death_door() {

object ob;
string where;

ob = present("necro_ob",tp);

if(environment(tp)->realm() == "NT") {
write("Something is blocking the bone portal from forming.\n");
return 1; }

if(tp->query_sp() < 40) {
write("You do not have the available spell points for this spell.\n");
return 1; }
if(ob->query_blood() < 3) {
write("You do not have the available components for this spell.\n");
return 1; }
if(tp->query_attack()) {
write("The bone portal cannot be called while in combat!\n");
return 1; }

/* Random Teleportation Check per /obj/base_tele.c */
if(where=call_other("obj/base_tele","teleport")) {
   this_player()->move_player("with an astonsihed look#"+where);
   tp->add_spell_points(-(random(5)+55));
   ob->add_blood(-3);
   ob->save_me();
   return 1; }
/* End teleport Check */

else {

write("You summon a portal of bone that rises from the ground.\n"+
      "You step through the portal to the saftey of your crypt.\n"+
      "The portal of bone closes behind you.\n\n");
say(tp->query_name()+" summons a portal of bone.\n"+
   "A shimmering energy field stands within the portal itself.\n");
this_player()->move_player("through the portal of bone#/players/daranath/guild/room/necro2.c");
tp->add_spell_point(-(random(5)+55));
ob->add_blood(-3);
ob->save_me();
return 1; }
}
