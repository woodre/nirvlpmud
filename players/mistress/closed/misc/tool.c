
id(str) {
   return str == "tool" || str == "wand";
       }

short() {
         return "A comfortable looking chair";
        }

init() {
add_action("adm");add_verb("p");
add_action("sit","sit");
      }

sit(a) {
   if(a == "on chair" || a == "in chair") {
   write("\nYou feel a slight shock and you jump to your feet!\n");
   say(this_player()->query_name()+" tries to sit in the chair but fails.\n");
   return 1; }
   }

adm() {
    object list;
     int i, z, x;
   list=users();
    while(i < sizeof(list)) {
      string sn, ip, sd, sh;
      object obply, plob;
      sn = list[i]->query_real_name();
      if(call_other(list[i], "query_ghost", 0) == 1) {
           sn = "ghost of " + sn;
}
       plob = find_player(sn);
       ip = call_other(list[i], "query_hostname", 0);
   while(x < 13) {
    ip += " ";
    x += 1;
   }
   x = 0;
   write(extract(ip, 0, 16));
   while(x < 15){
   sn += " ";
 x += 1;
   }
 if(call_other(list[i], "query_ghost", 0) == 1) {
    sh = extract(sn, 9, 21);
  } else
   sh = extract(sn, 0, 12);
   write(sh);
   z = list[i]->query_level();
    if (z >999999) {
   write(z + "   ");
   } else
   write(z + "     ");
    if(z < 10000 && z > 999) {
    write(" ");
}
   if(z < 10000 && z > 99) {
     write("  ");
   }
   if(z < 90 && z > 9) {
      write("   ");
   }
   if(z < 10) {
    write("    ");
   }
  obply = environment(list[i]);
   if (!obply) {
     write("location unknown.\n");
     }
   if (obply) {
   write(file_name(obply));
 write("\n");
  }
       i += 1;
       x = 0;
     }
    return 1;
    }
