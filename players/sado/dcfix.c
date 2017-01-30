id(str) { return str == "dcfix"; }
init()
{
   add_action("fix","dcfix");
}
fix(str)
{
   object u;
   int i;
   int n;
   u = users();
   n = sizeof(u);
   destruct(find_player(to_lower(str)));
   for(i=0; i<n; i++) if(u[i]->query_real_name() == to_lower(str)){tell_object(u[i], "You are being destructed to fix you.  Log back in and you should be OK.\n");destruct(u[i]);}
   return 1;
}
