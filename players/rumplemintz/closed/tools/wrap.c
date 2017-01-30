#define ctpqn capitalize(this_player()->query_name())

static object owner;
int rows;  /* word wrap */

start(me) {
  owner=me;
  rows=75;
  shadow (owner,1);
  add_action("set_rows","rows");
  return 1;
}

set_rows(arg) {
  int tmp;

  if(!arg || sscanf(arg,"%d",tmp)!=1)
    return write("Usage: rows <int> (0 for word wrap off)\n");
  rows=tmp;
  if(rows) write("Word wrap rows set to: "+rows+"\n");
  else write("Word wrap turned off\n");
  return 1;
}

/* assumes \n ONLY at strlen-1 */
catch_tell(str) {
  string tmp;
  int i,j,len;

  if(!rows) return write(str);
  i=0;
  str=implode(explode(str,"\n")," ");
  len=strlen(str)-1;
  while(len-i>rows) {
    j=i+rows;
    while(str[j]!=' ' && j>i) j--;
    if(j==i) j=i+rows;
    write(extract(str,i,j)+"\n");
    i=j;
  }
  write(extract(str,i));
}

