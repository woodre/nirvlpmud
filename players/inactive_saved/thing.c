int level;
string name;
void reset(int x) {
  string *nms;
  int s;
  if(x) return;
  nms=get_dir("/players/inactive_saved/");
  s=sizeof(nms);
  while(s--) {
   if(sscanf(nms[s],"%s.o",nms[s]))
   {
    level=0; name=0;
    restore_object("players/inactive_saved/"+nms[s]);
   if(level > 20)
    write("\""+nms[s]+"\",");
    }
  }
}
