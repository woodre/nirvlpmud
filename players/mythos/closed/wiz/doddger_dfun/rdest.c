rdest(str) {
   object destme, place;
   string dest_me1, loc1;

   if ((!str)||(sscanf(str,"%s from %s",dest_me1,loc1)!=2)) {
      write("Usage: rdest <item> from <creature>.\n");
      return 1;}
   place = find_living(loc1);
   if (!place) {
      write(
      capitalize(loc1)+" is not currently active.\n"
      );
      return 1;
      }
   destme = present(dest_me1,place);
   if (!destme) { write(capitalize(loc1)+" does not have "+dest_me1+".\n");
return 1;}
   write(
"You destruct from "+place->query_name()+"'s inventory: "+destme->short()+"\n"
   );
             destruct(destme);
             return 1;
           }
