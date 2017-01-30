/* droom.c
* 1/15/2007 - Rumplemintz@Nirvana
* Inherit room/room and add some color
* long() code taken from room/room and modified to add color
* use set_short(ansi_color, short_desc);  and set_long(ansi_color, long_desc);
* you can also set_exit_color(ansi_color);
   */

inherit "room/room";

#include "../DEFS"

mixed E_COLOR;

void reset(int arg){
   if(arg) return;
   room::reset(arg);
   set_light(1);
}

void init(){ room::init(); }

void set_exit_color(mixed s){ E_COLOR = s; }

string set_short(mixed color, string s){
   if(!color) color = GRN;
   if(!s)
      short_desc = color+"Druid Guild Area"+NORM;
   else
      short_desc = color + s + NORM;
}

string set_long(mixed color, string s){
  if(!color) color = GRN;
   if(!s)
      long_desc = color + short_desc + ".\n" + NORM;
   else
      long_desc = color + s + NORM;
}

varargs void long(string str){
   int i;
   string dark_msg;
   if ((set_light(0) <= 0) && !present("dark_sight_object", this_player())){
      i = random(4);
      switch(i){
         case 3: dark_msg = "You are engulfed in darkness."; break;
         case 2: dark_msg = "You fumble around in the dark."; break;
         case 1: dark_msg = "It is pitch "+HIB+"black"+NORM+"."; break;
         default: dark_msg = "It is dark"; break;
       }
      write(dark_msg+"\n");
      return;
   }
   if(!str){
      write(long_desc);
      if(custom_exits) return;
      if(!dest_dir || no_exits) write(E_COLOR+"    No obvious exits.\n");
      else {
         int s;
         i = 1;
         if ((s=sizeof(dest_dir))==2) write(E_COLOR+"There is one obvious exit:"+NORM);
         else write(E_COLOR+"There are "+(string)this_object()->convert_number(s/2)+
               " obvious exits:"+NORM);
         while(i < s){
            write(" "+E_COLOR+dest_dir[i]+NORM);
            i += 2;
            if (i == s-1) write(E_COLOR+" and"+NORM);
            else if (i < s) write(E_COLOR+","+NORM);
         }
         write("\n");
      }
      return;
   }
   if(items && (i = member_array(str, items)) > -1) write(items[i+1]+".\n");
   else {
      int a, x;
      object room;
      string file;
      object *inv;
      str=convert_dir(str);
      if(!str || (a= member_array(str, dest_dir)) == -1) {
         return 0;
      }
      room=find_object(dest_dir[a-1]);
      if(!room) {
         file=dest_dir[a-1];
         if(file[0..0]!="/") file="/"+file;
#ifndef __LDMUD__
         if(file[-2..-1]!=".c")
#else
         if (file[<2..<1] != ".c")
#endif
           file = file + ".c";
         if(file_size(file) < 0) {
            write("A warping of space prevents you from looking "+str+".\n");
            return;
         }
      }
      write("\t\t\tYou look "+str+"...\n\n");
      say((string)this_player()->query_name()+" looks to the "+str+"...\n");
      if(dest_dir[a-1]->check_light()+set_light(0) <= 0 &&
            !present("dark_sight_object",this_player())) {
         write("It is dark.\n");
         return;
      }
      dest_dir[a-1]->long();
      inv = all_inventory(find_object(dest_dir[a-1]));
      for(x = 0; x < sizeof( inv ); x ++)
      if(inv[x]->short()) write(inv[x]->short() + ".\n");
   }
}
