  object ob;
  ob=present("critter");
  if(!ob) {write("No critters here!\n"); return 1;}
  command("north",ob);
  say("An animal leaves through the trees.\n");
  write("An animal leaves through the trees.\n");
  return 1; }
