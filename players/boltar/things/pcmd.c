 /*
       This people command was created by boltar for use on
       terminals such as the adm that do not believe in tabs
 */


query_value()
{
        return 0;
}

  query_weight() {   return 1; }
long()
{
     write(" just type 'p' to use\n");
}

init() {
     add_action("adm", "p");
     add_action("escape", "escape");
}

id(str) {
    return str == "ND" || str == "cmd" || str == "people cmd";
}


get() {
     write("You now have a nice people command");
     write("\n");
    return 1;
}
adm_old() {
    object list;
     int i, z, x;
     int a,t;
   list=users();
      t = sizeof(list);
   /*
    for(i=0; i<sizeof(list); i++) {
    if(list[i]->query_invis() > 99)
           t -=1;
    }
     */
   write("There are now " + t + " players");
    for (i=0, a=0; i < sizeof(list); i++)
	if (query_idle(list[i]) >= 5 * 60)
	    a++;
    if (a)
	write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    i = 0;
write("   Address        Name        Level        Location  \n");
write("........................................................................");
write("\n");
    while(i < sizeof(list)) {
      string sn, ip, sd, sh;
      object obply, plob;
      sn = list[i]->query_real_name();
      if(call_other(list[i], "query_ghost", 0) == 1) {
           sn = "ghost of " + sn;
}
       plob = find_player(sn);
   if (in_editor(list[i])) sn = sn + "{ed}";
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
query_auto_load() {
  return "players/boltar/things/pcmd.c:";
 }
drop(str) {
  return 1;
  }
escape() {
   move_object(this_player(), "room/church.c");
   return 1;
   }
adm(str) {
    object list;
     int age_n,age_n2, i, z, x;
     int id_t,a,t;
   if(!str)
     str = "a";
   list=users();
      t = sizeof(list);
    for(i=0; i<sizeof(list); i++) {
   if(list[i]->query_invis() > 55 && this_player()->query_level() < list[i]->query_level())
           t -=1;
    }
   write("There are now " + t + " players");
    for (i=0, a=0; i < sizeof(list); i++)
	if (query_idle(list[i]) >= 5 * 60)
	    a++;
    if (a)
	write(" (" + (sizeof(list) - a) + " active)");
    write(". " + query_load_average() + "\n");
    i = 0;
if(str!="i" && str !="a")
write("   Address        Name             Level      Location  \n");
if(str == "a")
write("   Address        Name       Age   Level      Location  \n");
if(str == "i")
write("   Address        Name      Idle   Level      Location  \n");
write("........................................................................");
write("\n");
    while(i < sizeof(list)) {
      string sn, ip, sd, sh;
      object obply, plob;
if(list[i]->query_invis() < 55 || (list[i]->query_invis() > 55 && this_player()->query_level() >= list[i]->query_level()))
{
      sn = list[i]->query_real_name();
      if(call_other(list[i], "query_ghost", 0) == 1) {
           sn = "ghost of " + sn;
}
       plob = find_player(sn);
   if (in_editor(list[i])) sn = "*"+sn;
       ip = call_other(list[i], "query_hostname", 0);
   while(x < 13) {
    ip += " ";
    x += 1;
   }
   x = 0;
   write(extract(ip, 0, 15));
   while(x < 15){
   sn += " ";
 x += 1;
   }
 if(call_other(list[i], "query_ghost", 0) == 1) {
    sh = extract(sn, 9, 20);
    sh = "@"+ sh;
  } else
   sh = extract(sn, 0, 12);
   write(sh);
if (str == "i") {
    id_t = query_idle(list[i]);
    if (id_t/60 > 0) {
    if (id_t/60 < 10)
    write(" " + id_t/60 + "m ");
    if (id_t/60 > 9)
	    write(query_idle(list[i]) / 60 + "m ");
    }
   if (id_t < 10 && id_t && id_t != 0)
    write(" " + id_t + "s ");
   if (id_t > 9 && id_t < 60)
   write(id_t + "s ");
   if (id_t == 0 || !id_t)
   write ("    ");
 }
if (str == "a"){
   age_n = list[i]->query_age();
   age_n2 = 0;
   if (age_n < 1800)
   {
      age_n = age_n/30;
     if (age_n > 9)
       write(age_n + "m ");
     if (age_n < 10)
       write(" " + age_n + "m ");
    }
   if (age_n > 1800)
   age_n2 = age_n/1800;
   if (age_n2 > 9 && age_n2 < 24)
     write(age_n2 +"h ");
   if (age_n2 < 10 && age_n2 > 0)
     write(" " + age_n2 + "h ");
    if (age_n2 >= 24)
   {
      age_n2 = age_n2/24;
    if (age_n2 > 9)
      write(age_n2 +"d ");
    if (age_n2 < 10)
      write(" " + age_n2 + "d ");
    }
    }
if (str !="i" && str !="a")
  write("    ");
   z = list[i]->query_level();
    if (z <99999) 
   write(" ");
    if(z < 10000 && z > 999) {
    write(" ");
}
   if(z < 10000 && z > 99) {
     write("  ");
   }
   if(z < 100 && z > 9) {
      write("   ");
   }
   if(z < 10) {
    write("    ");
   }
   write(z);
   write("  ");
  obply = environment(list[i]);
   if (!obply) {
     write("location unknown.\n");
     }
   if (obply) {
   write(file_name(obply));
 write("\n");
  }
 }
       i += 1;
       x = 0;
     }
    return 1;
    }
