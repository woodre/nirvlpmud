#include <ansi.h>

mapping wiz_status;

void reset(int arg){ if(!wiz_status) wiz_status=([]); }
void set_wiz_status(string name, string wstatus){
   if(!name) return;
   wiz_status[name]=wstatus;
}

int rwhoall(){
   object *ob;
   int h, s;
   int hr, min, sec, tm;
   string output;
   string wstatus;
   string location;
   string time_string;
   ob = users();
   s = sizeof(ob);
   output = "\n";
   output += HIR+"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" +
                 "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+NORM+"\n";
   for(h=0; h<s; h++){
    output += pad((int)ob[h]->query_level(), 6);
    output += " (" + pad((int)ob[h]->query_extra_level(), 3) +")";
#if 0
      output += " ("+(int)ob[h]->query_extra_level()+")";
      if ((int)ob[h]->query_extra_level() < 10 &&
          (int)ob[h]->query_level() < 100) output += "\t";
      if ((int)ob[h]->query_level() < 1000000) output += "\t";
#endif
      output += " "+pad(capitalize((string)ob[h]->query_real_name()), 13);
      tm = query_idle(ob[h]);
      time_string="";
      if(hr = (tm / 3600)){
         time_string += hr+"h ";
         tm -= (hr * 3600);
       }
      if(min = (tm / 60)){
         time_string += min+"m ";
         tm -= (min * 60);
       }
      output += pad(time_string,6);
      if (environment(ob[h]))
        location = file_name(environment(ob[h]));
      else
        location = "Unknown";
      if (location[0..6] == "players")
        location = location[7..strlen(location)-1];
      if (location[0..3] == "room")
        location = location[4..strlen(location)-1];
      output += pad(location, 30);
      wstatus=wiz_status[ob[h]->query_real_name()];
      if(wstatus) output += " "+pad(wstatus,13);
      else if(in_editor(ob[h])) output += " "+pad("E", 2);
      else if(query_idle(ob[h]) > 3000) output += " "+pad("I", 2);
      else output += " "+pad("A", 2);
      if((int)ob[h]->query_invis()) output += "  Invis ("+ob[h]->query_invis()+")";
      output += "\n";
   }
   output += HIR+"=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" +
                 "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-="+NORM+"\n";
   write(output+"\n");
   return 1;
}
