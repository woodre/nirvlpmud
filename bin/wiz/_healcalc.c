int cmd_healcalc()
{
   object ob;
   if(!(ob=present("heal_calculator", this_player()))) {
      ob = clone_object("/bin/soul/healcalc");
      move_object(ob, this_player());
   }
  if(ob)
  ob->main();
  if(!ob) { write("Something is wrong.  Contact Fred.\nSorry.\n"); return 1; }
   return 1;
}
