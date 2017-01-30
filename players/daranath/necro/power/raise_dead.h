raise_dead(str) {
object ob;
object deadguy;

ob = present("necro_ob",tp);
deadguy = present("ghost of "+str, environment(tp));

if(tp->query_sp() < 100) {
write("You do not have the spell points to raise the dead.\n");
return 1; }
if((ob->query_soul() < 1) || (ob->query_blood() < 3)) {
write("You do not have the components available for this spell.\n");
return 1; }

if(!str) {write("Who do you want to bring back from the Realm of Death?\n");
   return 1; }
if(!living(deadguy) || deadguy->query_npc()) {
  write("That is not something you can raise from the dead.\n");
  return 1; }
if(!deadguy) {write("The ghost of that person is not present.\n");
  return 1; }
if(deadguy == this_player()) {
  write("You cannot raise yourself from the dead.\n");
  return 1; }
if(!deadguy->query_ghost()) {
  write("You cannot cast this spell on someone who is still alive.\n"+
        "Perhaps you could show them to the Realm of Death first.\n");
  return 1; }

write("Drawing a circle of power upon the ground in blood, you contact\n"+
      "the Realm of Death looking for the soul of the ghost.\n");
write("You have brought the ghost back from the Realm of Death.\n");
say(tp->query_name() +" draws a circle of power upon the ground in blood.\n"+
    "A chill runs through the area as the ghost is brought back to life.\n");
call_other(deadguy, "remove_ghost", 0);

tp->add_spell_points(-100);
ob->add_val(3);
ob->add_soul(-1);
ob->add_blood(-3);
ob->save_me();
return 1; 
}

