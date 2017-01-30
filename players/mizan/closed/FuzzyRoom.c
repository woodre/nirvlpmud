/*
 * FuzzyRoom.c Version 1.0
 */

string dest_dir;     /* Array form */
string short_desc;   /* Array form */
string long_desc;    /* Array form */
string object_names; /* Array form */
string numbers;
int long_num;
int short_num;
object ob;

reset() {
  extra_reset();
}

extra_reset() {
  int i;
  if(!object_names) return;
  if(!ob) {
    ob=allocate(sizeof(object_names));
  }
  i = 0;
  while(i < sizeof(object_names)) {
    if(!ob[i]) {
      ob[i]=clone_object(object_names[i]);
      move_object(ob[i], this_object());
    }
  i += 1;
  }
 if(long_desc || short_desc) {
  long_num=random(sizeof(long_desc));
  short_num=random(sizeof(short_desc));
 }
}

init() {
    int i;
    if (!dest_dir)
        return;
    i = 1;
    while(i < sizeof(dest_dir)) {
        add_action("move", dest_dir[i]);
        i += 2;
    }
}

id(str) { return str == "Fuzzyroom"; }

long() {
  int i;
  if(set_light(0) == 0) {
    write("It is dark.\n");
    return;
  }
  write(long_desc[long_num]);
  if(!dest_dir) write("    No obvious exits.\n");
  else {
    i = 1;
    if(sizeof(dest_dir) == 2) write("    There is one obvious exit:");
    else
      write("    There are " + convert_number(sizeof(dest_dir)/2) + " obvious exits:");
      while(i < sizeof(dest_dir)) {
        write(" " + dest_dir[i]);
        i += 2;
        if(i == sizeof(dest_dir) - 1)
        write(" and");
        else if (i < sizeof(dest_dir))
        write(",");
      }
      write("\n");
    }
  return;
}

move(str) {
  int i;
  i = 1;
  while(i < sizeof(dest_dir)) {
    if (query_verb() == dest_dir[i]) {
      this_player()->move_player(dest_dir[i] + "#" + dest_dir[i-1]);
      return 1;
    }
  i += 2;
  }
}

short() {
  int i;
  string temp;
/*
  if(set_light(0)) return "A dark room";
  else
 */
    temp = short_desc[short_num] + " [";
    if(!dest_dir) temp += "no exits";
      else
      for(i=1;i<sizeof(dest_dir);i+=2) {
      temp += call_other("room/room", "translate_exit", dest_dir[i]);
      if(i < sizeof(dest_dir)-2) temp += ",";
    }
    temp += "]";
    return temp;
}

convert_number(n) {
  if(!pointerp(numbers)) numbers = call_other("room/room", "query_numbers");
  if(n > 9) return "lot of";
  return numbers[n];
}


