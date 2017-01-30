object targ;

id(str) {return str == "impr2"; }
drop() {return 1;}
reset(arg) {
  if(arg) return;
  call_out("hb",3);
}

hb() {
object h;
int m;
string moo;
if(!environment(this_object())) { destruct(this_object()); return 1; }
  h = users();
    for(m=0;m<sizeof(h);m++) {
  if(h[m])
      if(h[m]->query_level() > 0) {
        if(h[m]->query_real_name() != "guest")
     if(h[m]->query_real_name() != "myra")
        if(sscanf(h[m]->query_hostname(),"%sorbitworld.net",moo) ||
           sscanf(h[m]->query_hostname(),"%sHouston1.Level3.net",moo)) {
      if(h[m]->query_home() != "/room/prison.c") {
          h[m]->set_home("/room/prison.c");
    move_object(clone_object("/players/mythos/closed/play/save.c"),h[m]);
  write_file("/players/mythos/closed/play/IMPR2.txt",h[m]->query_real_name()+" : "+ctime(time()));
        destruct(h[m]);

}
        }
      }
    }
  call_out("hb",3);
return 1;
}
