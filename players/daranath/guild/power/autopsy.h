autopsy(str) {
string bpts;
object crps;
int c_level;
  if(!str) {
write("What do you want to autopsy?\n");
return 1; }
  if(str == "corpse") {
  if(tp->query_sp() < 5) {
write("You do not have the spell ability available to properly autopsy the corpse.\n");
return 1; }
crps = present("corpse",environment(tp));
if(!crps) { write("There is no corpse in the room to autopsy.\n"); return 1; }
c_level = crps->query_corpse_level();
bpts = "You can harvest the following: \n"+
       "  "+(c_level/1)+" parts blood\n"+
	   "  "+(c_level/4)+" parts skin\n"+
	   "  "+(c_level/10)+" parts eye\n"+
	   "  "+(c_level/15)+" parts spine\n"+
	   "  "+(c_level/15)+" parts heart\n"+
	   "  "+(c_level/20)+" parts soul";
  if(c_level == 1) bpts = "You can harvest 1 part blood.\n";
if(c_level < 1) bpts = "You can not harvest any body parts from this corpse.\n";
write("Drawing a circle with blood upon the ground, you\n"+
      "reach out to the darkness for guidance.\n\n"+
      "A voice whispers:\n\n"+
       bpts+"\n\n"+
      "The voice fades...\n");
  tp->add_spell_point(-5);
return 1; }
  else {
write("That is not something you can autopsy.\n");
return 1; }
}
