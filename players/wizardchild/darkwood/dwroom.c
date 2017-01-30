/* dwroom.c: darkwood room driver */
#include "/room/clean.c"
string *dest_dir;
string short_desc;
string long_desc;
string *dirs;
object *objects;
string *check_dirs;
status loaded;

short() {
  string sh;
  int i;
  if(!set_light(0))
    sh = "Dark room";
  else {
    sh = short_desc+" [<";
    if(!dirs)
      sh += "no exits";
    else {
      for(i = 0; i < sizeof(dirs)-1; i++)
        sh += dirs[i]+",";
      sh += dirs[i];
    }
    sh += ">]";
  }
  return sh;
}
long(flag) {
  string *names; 
  object ob;
  int x;
  int i;
  i = 100; /* chance that you won't see something */
  names = ({"no","one","two","three","four","five","six","seven"});
  if(!present("darkwood_torch", this_player()))
    i = 40;
  if(long_desc)
    write(long_desc);
  x = sizeof(dest_dir)/2;
  if(!x)
    write("    There are no possible exits.\n");
  else if(x == 1)
    write("    There is one possible exit: ");
  else
    write("    There are "+names[x]+" possible exits: ");
  for(x = 1; x < sizeof(dest_dir)-1; x += 2)
    write(dest_dir[x]+", ");
  if(sizeof(dest_dir)) write(dest_dir[x]+".\n");
  if(!flag) return 1;
  ob = first_inventory(this_object());
  while(ob) {
    if(ob->short() && ob != this_player() && (random(100) >= 5))
      write(ob->short()+".\n");
    ob = next_inventory(ob);
  }
  return 1;
}
/* don't allow anybody out */
realm() {
  return "NT";
}
static common_exit(str) {
  if(str == "north" || str == "south" || str == "west" || str == "east")
    return extract(str,0,0);
  if(str == "northwest" || str == "northeast" || str == "southwest" || str == "southeast")
    return (extract(str,0,0)+extract(str,5,5));
  return str;
}
/* called at the END of reset() */
static load_room() {
  int i, n;
  if(loaded)
    return ;
  set_light(1);
  for(i = 0; i < sizeof(objects); i++)
    move_object(clone_object(objects[i]), this_object());
  for(n = 0, i = 1; i < sizeof(dest_dir); n++, i += 2) {
    if(!sizeof(dirs)) dirs  = ({common_exit(dest_dir[i])});
    else              dirs += ({common_exit(dest_dir[i])});
  }
  loaded = 1;
}
look_at(str) {
  return (str ? 0 : long(1));
}
init() {
  int i;
  add_action("look_at","look",1);
  for(i = 1; i < sizeof(dest_dir); i += 2) 
    add_action("moveme", dest_dir[i]);
}
moveme() {
  string dir; 
  int i,n;
  dir = query_verb();
  if(!dir)
    return ;
  for(n = 0,i = 1; i < sizeof(dest_dir); i += 2,n++) {
    if(n < sizeof(check_dirs) && (dir == check_dirs[n] || dir == common_exit(check_dirs[n])) && checkok())
      return 1;
    if(dir == common_exit(dest_dir[i]) || dir == dest_dir[i]) {
      this_player()->move_player(dest_dir[i]+"#"+dest_dir[i-1]);
      return 1;
    }
  }
  return 0;
}
query_dest_dir()    { return dest_dir;  }
query_long()        { return long_desc; }
query_drop_castle() { return 1;         }

