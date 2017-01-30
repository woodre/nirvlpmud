int cmd_ecreate()
{
   object ob;
   if(!(ob=present("e-creator", this_player()))) {
      ob = clone_object("/bin/soul/editor");
      move_object(ob, this_player());
   }
  if(ob)
  ob->main();
  if(!ob) { write("Ecreate only for L50+.\nSorry.\n"); return 1; }
   return 1;
}
