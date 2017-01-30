/* Guild Level 1 - basic healing spell
   TotalCost -> 12 spell points  */

cure_minor(str) {
int heal;
object ob, targ;

heal = 5 + random(5);
ob = present("druid_ob",this_player());
if(!str) {write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" Who did you want to heal?\n");
  return 1; }
else{ targ = present(str, environment(tp)); }

if(tp->query_spell_dam()) return 0;
if(tp->query_sp() < 12) {
write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" Not enough spell points to cast the Cure.\n");
return 1; }
if(!targ) {write(GRN+"<< "+HIG+"Druid"+NORM+GRN+" >>"+NORM+" "+targ+" is not here to Cure.\n");
  return 1; }
if(tp->query_spell_dam()) { notify_fail("BLAH");
  return 0; }

  tp->add_spell_point(-12);
  ob->add_touch(0);
  ob->save_me();
  tp->set_spell_dam(1);
heal = heal + ob->query_healskill();

write("You whisper a swift prayer to the Forest, and draw strength from Nature's embrace.\n");
say("heal msg check 2\n");

  targ->add_hit_point(heal);
return 1; }

