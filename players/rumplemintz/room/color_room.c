/* ========================================================================== */
/*   color_room.c                                                             */
/*   (c) 2007 Rumplemintz@Nirvana                                             */
/*                                                                            */
/*   room/room with added support for color in short(),                       */
/*             long(), and exits                                              */
/*   inherit this and use set_short(COLOR, short_desc)                        */
/*                        set_long(COLOR, long_desc)                          */
/*                        set_exit_color(COLOR)                               */
/* ========================================================================== */

inherit "room/room";

#include <ansi.h>

mixed E_COLOR;    /* Exits color */

void reset(int arg){
   if(arg) return;
   room::reset(arg);  /* Make passes to ::reset() work */
   set_light(1);      /* No use using color if they can't see */
}

void init(){ room::init(); }    /* Make passes to ::init work */

void set_exit_color(mixed s){ E_COLOR = s; }  /* Set the exit color */

string set_short(mixed color, string s){  /* Set the short_desc color */
   if(!color) color = NORM;
   if(!s)
      short_desc = color+"Non-descript Room"+NORM;
   else
      short_desc = color + s + NORM;
  return short_desc;
}

string set_long(mixed color, string s){   /* Set the long_desc color */
   if(!color) color = NORM;
   if(!s)
      long_desc = color + short_desc + ".\n" + NORM;
   else
      long_desc = color + s + NORM;
  return long_desc;
}

varargs void long(string str){  /* long() code from room/room - changed
   how the exits are reported back to add
   the exit color - Rumplemintz */
   int i;
   string dark_msg;  /* Return a string if dark rooms ever return anything
      again instead of nothing */
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
      if(!E_COLOR) E_COLOR = NORM;
      if(!dest_dir || no_exits)
         write(E_COLOR+"Obvious exits: None"+NORM+"\n");
      else {
         int s;
         i = 1;
         if ((s=sizeof(dest_dir))==2)
            write(E_COLOR+"Obvious exit:"+NORM);
         else write(E_COLOR+"Obvious exits:"+NORM);
         while(i < s){
            write(" "+E_COLOR+dest_dir[i]+NORM);
            i += 2;
            if(i == s-1) write(E_COLOR+" and"+NORM);
            else if (i < s) write(E_COLOR+","+NORM);
         }
         write("\n");
      }
      return;
   }
   if(items && (i = member_array(str, items)) > -1) write(items[i+1]+".\n");
   else { /* converted from Vertebraker's look <dir> code by Illarion */
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
      dest_dir[a-1]->long();
      inv = all_inventory(find_object(dest_dir[a-1]));
      for(x = 0; x < sizeof( inv ); x ++)
      if(inv[x]->short()) write(inv[x]->short() + ".\n");
   }
}