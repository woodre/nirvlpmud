
string followers;
string name;

id(str) { return str=="follow object" || str=="follow"; }

reset(arg) {
  if (arg) return 1;
  followers=allocate(1);
}

init() {
  name=capitalize(environment(this_object())->query_name());
}

add_follower(m) {
  int n;
  n=sizeof(followers);
  if (searcha(followers,m)!=-1) return 0;
  followers=reallocate(followers,n+1);
  followers[n]=m;
  return 1;
}

remove_follower(m) {
  int i,n;
  object ob;
  n=searcha(followers,m);
  if (n==-1) return 0;
  i=n;
  ob=find_living(followers[i]);
  if (ob) {
    tell_object(ob,"You stop following "+
      capitalize(environment(this_object())->query_name())+".\n");
    say(ob->query_name()+" stops following "+
      capitalize(environment(this_object())->query_name())+".\n",ob);
    }
  while (i<sizeof(followers)-1) {
    followers[i]=followers[i+1];
    i++;
    }
  followers=reallocate(followers,sizeof(followers)-1);
  return i;
}

remove_all_followers() {
  int i,n;
  object ob;
  n=sizeof(followers);
  for (i=1; i<n; i++) {
    ob=find_living(followers[i]);
    if (ob) {
/*      tell_object(ob,"You stop following "+
        capitalize(this_player()->query_name())+".\n"); */
      ob->follow();
      }
    }
  followers=reallocate(followers,1);
}

query_followers() {
  string ret;
  int i;
  if (sizeof(followers)==1) return 0;
  ret="";
  for(i=1; i<sizeof(followers); i++) 
    ret+=followers[i]+"#";
  return ret;
}

query_follower(m) {
  if (searcha(followers,m)!=-1) return 1;
  return 0;
}

query_empty() {
  if (sizeof(followers)==1) return 1;
  return 0;
}

pull_followers(str) {
  int i;
  object ob,env,fol,tp;
  string msgin,msgout;
  tp=environment(this_object());
  env=environment(tp);
  command(str, tp);
  for (i=1; i<sizeof(followers); i++) {
    ob=find_living(followers[i]);
    if (ob && present(ob, env)) {
      msgin=ob->query_msgin();
      msgout=ob->query_msgout();
      ob->setmout("leaves, following "+name);
      ob->setmin("arrives, following "+name);
      if (fol=present("follow object",ob))
       fol->pull_followers(str);
      else command(str, ob);
      ob->setmout(msgout);
      ob->setmin(msgin);
      }
    }
}

drop() { return 1; }

get()  { return 1; }

