main(arg) {
   object what;
   string func, str, name;
   int tmp;
   
   if(!arg || sscanf(arg,"%s %s %s",name,func,str) != 3)
      {
      write("Syntax: mpatch <player || object> <function> <argument>\n");
      return 1;
   }
   
   if(sscanf(str,"%d",tmp));
   what = find_player(name);
   if(!what) what = present(name,this_player());
   if(!what) what = present(name,environment(this_player()));
   if(!what)
      {
      write("No such player or object.\n");
      return 1;
   }
   if(str == "0") call_other(what,func,0);
   if(!tmp && str && str != "0") call_other(what,func,str);
   if(tmp) call_other(what,func,tmp);
   write("Done.\n");
   return 1; }
