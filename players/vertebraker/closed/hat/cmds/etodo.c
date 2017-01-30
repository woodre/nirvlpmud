main() {
  string *f, x, y;
  int    i,s;
  object  u;
  s=sizeof(f=get_dir("/bin/soul/"));
  for(i=0;i<s;i++)
  {
    x="/bin/soul/"+f[i];
    if(!sscanf(x,"_%s.c",y))
      continue;
    if(!(u=find_object(x)))
    {
      x->load_me();
      u=find_object(x);
    }
    if(u->query_code_word()!="verbal_kint")
      write(y+"\n");
  }
  return 1;
}
