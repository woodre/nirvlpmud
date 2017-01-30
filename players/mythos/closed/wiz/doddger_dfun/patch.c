find_ob(str) {
            object ob;
   string name_of_file,junk;
               ob = find_player(str);
            if (!ob) ob = find_living(str);
if (!ob) {
if (str=="here") ob = environment(this_player());
}
            return ob;
          }
shit(str) {
object ob, last_arg;
string who, do_str, arg, cap_name;
int iarg, count, check;

	if (!str) {
 write ("Syntax: patch [object] [function] [argument]\n");
 return 1;
      }
 if (sscanf(str,"%s %s %s",who,do_str,arg) == 3) {
  if (sscanf(arg,"%d",iarg) == 1) check = 1;
  }
else
if (sscanf(str,"%s %s",who,do_str) == 2) check = 1;
else {
  write ("Error in patch.\n");
  return 1;
}
ob = find_ob(who);
  if (!ob) {
  write ("No such object: "+who+".\n");
  return 1;
  }
if (!function_exists(do_str,ob)) {
write ("That function does not exist in "+object_name(ob)+"!\n");
return 1;
}
if (check) last_arg = call_other(ob,do_str,iarg);
  else {
    string x1,x2,x3,x4,x5;
  if (sscanf(arg,"%s,%s",x1,x2) != 2)
   last_arg = call_other(ob,do_str,arg);
  else if (sscanf(arg,"%s,%s,%s,%s,%s",x1,x2,x3,x4,x5) == 5)
   last_arg = call_other(ob,do_str,x1,x2,x3,x4,x5);
else if (sscanf(arg,"%s,%s,%s,%s",x1,x2,x3,x4) == 4)
  last_arg = call_other(ob,do_str,x1,x2,x3,x4);
else if (sscanf(arg,"%s,%s,%s,%s",x1,x2,x3) == 3)
  last_arg = call_other(ob,do_str,x1,x2,x3);
else if (sscanf(arg,"%s,%s,%s,%s",x1,x2) == 2)
  last_arg = call_other(ob,do_str,x1,x2);
else
  { write ("Too many arguments.\n");
    return 1;
}
}
write (object_name(ob)+"\n");
write ("Result: "+last_arg);
write ("\n");
   while(count) {
 if (check) call_other(ob,do_str,iarg);
  else call_other(ob,do_str,arg);
   count -= 1;
}
  return 1;
}
