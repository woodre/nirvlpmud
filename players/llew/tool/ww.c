
ww() {
   object peep,wizzy;
   int x;
   write("\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   write("          Wizards\n");
   write("---------------------------\n");
   write("Name............Level.Invis\n");
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   for(peep=users(),x=0;x<sizeof(peep);x++) {
      if(peep[x]->query_level() > 19) {
         wizzy += ({peep[x]});
      }
   }
   for(x=1;x<sizeof(wizzy);x++) {
      write(pad(capitalize(wizzy[x]->query_real_name()),15));
      write(pad(wizzy[x]->query_level(),-6));
      write(pad(wizzy[x]->query_invis(),-6)+"\n");
   }
   write("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   return 1;
}
