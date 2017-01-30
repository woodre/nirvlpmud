string area_path;
string area_name;
string *rooms;

void reset(status arg) {
  if(arg) return;

}

void set_area_name(string aname) {
  area_name = aname;
}

string query_area_name() {
  return area_name;
}

void load_area() {
  int s;
  string *fs;
  if(!area_path) return;

  fs = get_dir(area_path);
  rooms=({});
  for(s=0;s<sizeof(fs);s++) {
    if(sscanf(fs[s], "%s.c")) {
      catch(call_other(area_path+fs[s], "???"));
      rooms += ({ area_path+fs[s] });
    }
  }
}


void set_area_path(string str) {
  area_path=str;
}

string query_area_path() {
  return area_path;
}
