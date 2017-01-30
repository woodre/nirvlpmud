object myself;
reset(arg) {
        if(arg) return;
    myself=this_object();
}

id( str ) {
        if(str=="flyer"||str=="undead-flyer") return 1;
        return 0;
}

long() {
        write(  "This is a flyer about Undead guild, a rather new but kicking-ass guild.\n"+
	        "To get the list of the commands type:\n"+
	        "'com1' for level 1 command list.\n"+
    	        "'com2' for levels 2-3 command list.\n"+
    		"'com3' for levels 4-5 command list.\n"+
    		"'com4' for levels 6-7 command list.\n"+
                   "'com5' for levels 8 command list.\n"+
		"To reach the guild entrance from church:\n"+
           "south,2 east,south,southeast,east.\n");
}

short()
  { return "A flyer about Undead guild"; }
init()
{
  add_action( "com1","com1");
  add_action( "com2","com2");
  add_action( "com3","com3");
  add_action( "com4","com4");
   add_action("com5","com5");
}
com1(str) {
  if(str)  return;
  cat("/players/hurtbrain/closed/guild/helpdir/pent1.com");
  return 1;
}
com2(str) {
  if(str)  return;
  write("Spell                                                 Cost(sp) Level\n\n");
  cat("/players/hurtbrain/closed/guild/helpdir/pent2.com");
  return 1;
}
com3(str) {
  if(str)  return;
  write("Spell                                                 Cost(sp) Level\n\n");
  cat("/players/hurtbrain/closed/guild/helpdir/pent3.com");
  return 1;
}
com4(str) {
  if(str)  return;
  write("Spell                                                 Cost(sp) Level\n\n");
  cat("/players/hurtbrain/closed/guild/helpdir/pent4.com");
  return 1;
}
com5(str) {
  if(str)  return;
  write("Spell                                                 Cost(sp) Level\n\n");
  cat("/players/hurtbrain/closed/guild/helpdir/pent5.com");
  return 1;
}

