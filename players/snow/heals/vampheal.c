/* This is a magical item that transfers hit points to spell points.
Unlike guild spells, it does this at a ratio of 5 to 3. */
 
#define TP this_player()
 
id(str) { return  str == "vampiric healer" || str == "healer" ||
                  str == "vampheal" || str == "thorny orb" ||
                  str == "orb"; }
short() { return "A thorny orb"; }
long () {
  write(
"As you peer closely at the orb, you notice the thorns are stained red with \n"+
"blood. There seem to be thin veins running into the orb from the thorns. As\n"+
"you touch one of these thorns lightly, you can feel a draw on your blood. The\n"+
"thorn seems to throb in time with your pulse...\n"+
"You realize that this orb is a vampiric healer. It will give you energy in \n"+
"exchange for your nourishing blood. To use it, you will type 'vamp <number>'.\n"+
"Of course the orb keeps more blood for itself than energy it gives...\n");
  }
weight() { return 1; }
take() { return 0; }
can_put_and_get() { return 1; }
drop() { return 0; }
value() { return 5000; }
 
init() {
  add_action("vampheal","vamp");
}
 
vampheal(arg) {
  int num;
num = arg;
  if(!num) {
    write("Usage: vamp <number>.");
return 1; 
  }
  if(num > TP->query_hp()) {
    write("You do not have that much blood to spare.\n");
return 1;
  }
  if(num < 0) { write("The orb will not return your blood!\n"); return 1; }
else
  write("You grab the orb and let the thorns dig into your flesh.\n");
  say(TP->query_name()+" grabs a thorny orb and grimaces in pain!\n");
call_other(TP,"add_hit_point",-num);
call_other(TP,"add_spell_point",num*(3/5));
return 1;
}
