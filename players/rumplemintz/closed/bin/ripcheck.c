int ripcheck(){
   object *usr;
   int i;
   usr=users();
   for (i=0;i<sizeof(usr);i++)
    write(usr[i]->query_name()+"\t"+query_ip_number(usr[i])+"\n");
   return 1;
}
