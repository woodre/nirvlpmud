/************************************************************/
/* mapping.c                                                */
/* functions to handle 'saveable' mappings in string format */
/* functions in this file:                                  */
/*  string store_mapping(mapping map)                       */
/*  map extract_mapping(string str)                         */
/* functions for internal use only:                         */
/*  string mixed_to_string(mixed m)                         */
/*  mixed string_to_mixed(string str)                       */
/*  string *mapping_sscanf(string src)                      */
/* an example of a string returned by store_mapping():      */
/* (["str":1,4:"xyz","player.c":"[OBJ]obj/player"])         */
/* type status will be converted to type int on restore     */
/* mapping_sscanf won't fuckup if ':' is in a string, and is*/
/* far from innefficient because of it                      */
/************************************************************/
 
/* convert type mixed to string */
string mixed_to_string(mixed m) {
  string out,tmp,foo;
  int n;
  if(objectp(m)) {
    foo = file_name(m);
    if(sscanf(foo, "%s#%d", tmp, n) != 2)
      tmp = "[NC]"+foo; /* so we don't clone rooms, etc */
    out = "[OBJ]"+tmp; /* distinctive header */
  } else if(stringp(m)) 
    out = "\""+m+"\"";
  else {
    tmp = ":"+m;
    sscanf(tmp, ":%s", out);
  }
  return out;
}
/* convert type string to mixed */
mixed string_to_mixed(string str) {
  mixed m;
  status nc;
  string tmp,fn;
  int i;
  object ob;
  if(sscanf(str, "%d", i))
    m = i;
  else if(sscanf(str, "[OBJ]%s", tmp)) {
    if(sscanf(tmp,"[NC]%s", fn))
      nc = 1;
    else
      fn = tmp;
    if(nc) {
      call_other(fn, "??");
      ob = find_object(fn);
    } else
      ob = clone_object(fn);
    if(ob) m = ob;
  } else {
    sscanf(str, "\"%s\"", tmp);
    m = tmp;
  }
  return m;
}
/* scan the mapping string and dump keys & members into string * */
string *mapping_sscanf(string src) {
  status in_string;
  string *out,tmp;
  int x,y,z,n,so;
  y = 0;
  in_string = 0;
  so = strlen(src);
  tmp = " ";
  for(x = 0; x < so; x++) {
    if(src[x] == '\"') in_string = !in_string;
    if((!in_string && src[x] == ':') || x == (so-1)) {
      if(!sizeof(out)) out = ({tmp});
      else out += ({tmp});
      tmp = 0;
      y = 0;
    } else {
/*      tmp += " \b"; */
      tmp[y++] = src[x];
      write("pass "+x+": "+tmp+", "+src[x]+"\n");
    }
    if(y==2) sscanf(tmp,"0%s",tmp);
  }
  return out;
}    
/* store a mapping in a string */
string store_mapping(mapping map) {
  string out,p1,p2;
  mixed *key, *to;
  int x,so;
  key = keys(map);
  if(!key)
    return "";
  for(x=0,so=sizeof(key); x < so; x++) {
    if(x) to += ({ map[(key[x])] });
    else to = ({ map[(key[x])] });
  }
  out = "([";
  for(x = 0; x < so; x++) {
    p1 = mixed_to_string(key[x]);
    p2 = mixed_to_string(to[x]);
    out += p1+":"+p2+(x == (so-1) ? "])" : ",");
  }
  return out;
}
/* turn the string back into a mapping */
mapping extract_mapping(string str) {
  mapping map;
  mixed m1,m2;
  string tmp,*arr;
  int so,x,y;
  if(!sscanf(str, "([%s])", tmp)) 
    return ([]);
  /* muhahahahahahahahaha */
  arr = mapping_sscanf(tmp);
  for(x=0,y=1,so=sizeof(arr); x < so && y < so; x+=2,y+=2) {
    write(x+": "+arr[x]+", "+arr[y]+"\n");
    if(arr[x] == "" || arr[y] == "" || arr[x] == 0 || arr[y] == 0) continue;
    m1 = string_to_mixed(arr[x]);
    m2 = string_to_mixed(arr[y]);
    if(!x) map  = ([m1:m2]);
    else   map += ([m1:m2]);  
  }
  return map;
}
