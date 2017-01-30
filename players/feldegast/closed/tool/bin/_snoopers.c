/* Before you ask...No, it doesn't work. */
do_cmd(str) {
        object ob;
        string temp;
        int i;
        ob = users();

   for(i=0; i<sizeof(ob);i++){
        temp = query_snoop(ob[i]);
        if(temp){
          write(capitalize(ob[i]->query_real_name())); /*get the invis too*/
          write(" is being snooped by ");
          write(capitalize(temp->query_real_name()));
          write("\n");
}
}
return 1;}
