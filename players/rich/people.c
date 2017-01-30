new_people() {
   string who,name,location;
   int level,invis,counter,spacing,scounter,iidle;
   string slevel,sinvis,sidle;
   write("Name           level   invis    idle      location\n");
   write("----------     -----   -----    ----      ------------\n");
   who=users();
   counter=0;
   while (counter < sizeof(who)) {
      name=who[counter]->query_real_name();
      name=capitalize(name);
      if (in_editor(who[counter]))
         name="->" + name;
      while (strlen(name) < 15)
         name+=" ";
      level=who[counter]->query_level();
      spacing=level;
      slevel=" ";
      scounter=0;
      while (spacing > 9) {
         scounter+=1;
         spacing/=10;
      }
      scounter=7-scounter;
      while (scounter > 0) {
         slevel+=" ";
         scounter-=1;
      }
      invis=who[counter]->query_invis();
      spacing=invis;
      scounter=0;
      while (spacing > 9) {
         scounter+=1;
         spacing/=10;
      }
      sinvis=" ";
      scounter=7-scounter;
      while (scounter > 0) {
         sinvis+=" ";
         scounter-=1;
      }
      iidle=query_idle(who[counter]);
      spacing=iidle;
      sidle=" ";
      scounter=0;
      while (spacing > 9) {
         scounter+=1;
         spacing/=10;
      }
      scounter=7-scounter;
      while (scounter > 0) {
         sidle+=" ";

         scounter-=1;
      }
      if (environment(who[counter]))
         location=file_name(environment(who[counter]));
      else
         location="Nowhere";
      if (!location)
         location="";
      write(name + level + slevel + invis + sinvis + iidle + sidle +
         location + "\n");
      counter+=1;
   }
   return 1;
}
