/* my little who command
*/
#define YA tell_object(environment()
#define IDLE query_idle(a[i])

status who_cmd() {
  int i, s, level, elvl, lvl;
  object *a;
  a = users();
  s = sizeof(a);
  YA,RED+"      -- ---- -------- -------- ---- --\n"+NORM);
  for(i = 0; i < s; i++)
  {
    lvl = (int)a[i]->query_level();
    elvl = (int)a[i]->query_extra_level();
    level = lvl + elvl;
    if(a[i]->query_level() >= 20)
      YA,"["+a[i]->query_level()+"] ");
    if(a[i]->query_level() < 20)
      YA,"["+level+"] ");
    if(a[i]->query_level() >= 20 && !a[i]->query_invis())
      YA,HIG);
    if(a[i]->query_level() >= 20 && a[i]->query_invis())
      YA,HIR);
    if(a[i]->query_level() < 20)
      YA,HIW);
    YA,a[i]->query_real_name() +" ");
    YA,NORM);
    if(environment(a[i]))
      YA,file_name(environment(a[i]))+" ");
    if(IDLE >= 60)
      YA,MAG+"<"+IDLE / 60+"m & "+IDLE % 60+"s>"+NORM);
    YA,"\n");
  }
  YA,RED+"      -- ---- -------- -------- ---- --\n"+NORM);
  return 1; 
}
