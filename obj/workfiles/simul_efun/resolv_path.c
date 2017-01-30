/*
// resolv_path.c
//
// Resolv_path will determine the full pathname of a file when given 
// a current directory and a pathname.
// Thanks to Huthar for this!  Buddha snarfs it and makes it work!
// Snagged from TMI for use in Nirvana by Shadowhawk the NUISANCE.
// Will change default (of wiz_soul) by requiring leading (and trailing)
// slashes on the filename.
*/

string user_path(string name);
static string eliminate_ellipsis(string path);

#pragma strict_types
#pragma save_types

/*
// eliminate_ellipsis removes any occurences of .. from a path.
*/
static string
eliminate_ellipsis(string path) {
  int i;
  string *tmp;

  if(!path) return 0; /* verte */
  tmp = explode(path,"/");
  if (!tmp)
    return "/";
  for (i = 0; i < sizeof(tmp); i++) {
    if (tmp[i] == "..") {
      if (sizeof(tmp) > 2) {
	tmp = tmp[0..(i-2)] + tmp[(i+1)..(sizeof(tmp)-1)];
	i -= 2;
      } else {
	tmp = tmp[2 ..(sizeof(tmp)-1)];
	i = 0;
      }
    }
    if (tmp[i] == ".") {
      tmp = tmp[0..(i - 1)] + tmp[(i + 1)..(sizeof(tmp) - 1)];
      i -= 1;
    }
  }
  path = "/" + implode(tmp, "/");
  if (path == "//")
    path = "/";
/* ok, this is working odd on ld... let's just brute fix -Bp */
  if(path) {
    string haldo;
    if (sscanf(path, "//%s", haldo) == 1)
       path = "/"+haldo;
  }
  return path;
}
string
user_path(string name) {
  if (!name)
    return "";
  return eliminate_ellipsis("/players/" + name);
}

varargs string
resolv_path(string curr, string new) {
  string t1;
/* No - Rumplemintz 
#ifdef __LDMUD__
write_file("/log/earwax.resolv_path", ctime()+": resolv_path called by: "+object_name(previous_object())+" curr: "+curr+" new: "+new+"\n\t (tp: "+(this_player() ? (string)this_player()->query_real_name() : "none")+"/"+(query_verb() ? query_verb() : "no verb")+"\n");
#endif
*/
  if(!stringp(curr)) return "";
  if(this_player() && (int)this_player()->query_level() < 21)
  {
    write("curr: "+curr+"\n");
    return curr;
 }
  if (curr[strlen(curr) - 1] == '/')
    curr = curr[0..strlen(curr) - 2];
  if (!new || new == ".")
    return eliminate_ellipsis(curr);
  if (new == "here") {
#ifndef __LDMUD__ /* Rumplemintz */
    return "/" + file_name(environment(this_player())) + ".c";
#else
    return "/" + object_name(environment(this_player())) + ".c";
#endif
  }
  if (new == "~" || new == "~/" )
    return user_path((string)this_player()->query_real_name());
  if (sscanf(new,"~/%s",t1))
    return user_path((string)this_player()->query_real_name() +
      "/" + t1);
  else if (sscanf(new,"~%s",t1))
    return user_path(t1); 
  else if (new[0] != '/')
    new = curr + "/" + new;
  return eliminate_ellipsis(new);
}

