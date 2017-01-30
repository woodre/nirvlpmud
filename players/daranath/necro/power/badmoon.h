/* Guild Level 2 - Misc Spell
   Spell brings a badmoon into play, which can affect other 
   necro spells at far as increasing damage and other stats
   TotalCost - 24sp (20 sp, 2 blood)      */
badmoon() {
object ob;

ob = present("necro_ob",tp);

if(tp->query_sp() < 20) {
write("You do not have the spell points available for the Bad Moon.\n");
return 1; }
if(ob->query_blood() < 2) {
write("You do not have the components available for this spell.\n");
return 1; }

if(present("badmoon",environment(tp))){
write("<"+HIW+"RoD"+NORM+"> There is already a Badmoon within that area.\n");
return 1; } else {
  move_object(clone_object("/players/daranath/guild/obj/misc/badmoon.c"),environment(tp));
  write("A shadow falls across the area as you cast the dark spell.\n");
  write("You summon the evil known only as a badmoon.\n");
  say(tp->query_name()+" gathers magical energy and releases a dark spell.\n");
  say("A shadow of darkness engulfs the entire area.\n");

tp->add_spell_point(-20);
ob->add_blood(-2);
ob->save_me();
return 1; }
}
