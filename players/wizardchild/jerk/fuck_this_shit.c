reset() { call_out("check_users",5); }
check_users() {
object ob; int i,so;
remove_call_out("check_users");
for(ob=users(),i=0,so=sizeof(ob); i < so; i++) {
if(ob[i]->query_age() > 0 && ob->query_age() < 1800)
{ tell_object(ob[i],"Sorry, we cannot let you log in.\n");
    destruct(ob[i]);
}
}
call_out("check_users",5);
}
