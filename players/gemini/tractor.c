int engine;
int key;
int headlights;
string items;
reset(){
   engine = 0;
   key = 0;
   items =
   ({ 
         "radio","A CB radio used to communicate.  Refer to the instruction manual",
         "box","A box for storing important items.  Try and open it",
         "visor","You can lower it to block your eyes from the sun",
    });
   enable_commands();
}
id(str){
   int i;
  if(this_player()) {
   if(present(this_player(),this_object())){
      while(i<sizeof(items)){
         if(items[i] == str){
            return 1;
            }
         i +=2;
      }
      return 0;
   }
  }
   return str == "tractor" || str == "deere" || str == "john deere";
}
catch_tell (string str){
   if(this_player() != this_object()){
      if(!this_player() || !present(this_player(), this_object()))
         tell_room(this_object(), "Outside the tractor: "+str);
      return 1;
   }
   return 1;
}
short(){
   return "A John Deere Tractor";
}
long(str){
   int i;
   if(present(this_player(),this_object())){
      if(!str){
         write("You are inside the John Deere tractor.\n"+
            "In front of you is a computer control panel.  It seems very complex.\n"+
            "The entire interior is made of leather.  Even the sun visor.\n"+
            "Other features of interest are the CB radio, and the storage box.\n"+
            "");
         return 1;
      }
      i = 0;
      while(i<sizeof(items)){
         if(items[i] == str){
            write(items[i+1]+ ".\n");
            return;
            }
         i +=2;
      }
   }
   write("A giant tractor used for heavy farm work.  The tires are almost five\n"+
      "feet in diameter.  There is a small ladder for climbing up into\n"+
      "the drivers seat.\n"+
      "");
   return 1;
}
init(){
   if(present(this_player(),this_object())){
      add_action("lower","lower");
      add_action("start","start");
      add_action("headlights","headlights");
      add_action("drive","drive");
      add_action("plow","plow");
      add_action("lookout","lookout");
      add_action("mow","mow");
      add_action("intercom","intercom");
      add_action("dt","dt");
      add_action("open","open");
   }
   add_action("climb","climb");
}
climb(arg){
   if(!arg){ write("What do you want to climb?\n"); return 1; }
   if(present(this_player(),this_object())){
      if(arg == "down"){
         move_object(this_player(),environment(this_object()));
         command("look",this_player());
         return 1;
      }
      write("You can only climb down from here.\n");
      return 1;
   }
   if(arg == "ladder"){
      move_object(this_player(),this_object());
      long();
      say(capitalize(this_player()->query_real_name())+" climbs the ladder up into the tractor.\n");
      return 1;
   }
   write("You may only climb the ladder of the tractor.\n");
   return 1;
}
start(){
   if(engine == 1){
      write("The engine is already started");
      return 1;
   }
   if(key == 0){
      write("You need a key to start the engine");
      return 1;
   }
   write("You put the key in the ignition and start the engine.\n");
   engine = 1;
   return 1;
}
drive(str){
   object ob;
   string directions;
   directions = ({"east","west","southeast","southwest","northeast","northwest","north","south",});
   if(engine == 0){
      write("You have to start the engine first.\n");
      return 1;
   }
   if(member_array(str,directions) !=-1){
      command(str, this_object());
      environment(this_object())->long();
      for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
         if(ob != this_object()){
            write(ob->short());
            write("\n");
          }
      }
      return 1;
   }
   write("That is not a place you can drive.\n");
   return 1;
}
lower(str){
   if(!str){ write("What do you want to lower.\n"); return 1; }
   if(str == "visor"){
      write("You lower the visor to block the sun.  As you do a set of\n"+
         "keys fall out, which you catch in your hand.\n"+
         "");
      items += ({"keys","A set of keys which start the engine",});
      key = 1;
      return 1;
   }
   write("You can only lower the visor.\n");
   return 1;
}


/*
* This routine is called from objects that moves the player.
* Special: direction "X" means teleport.
*/
move_player(dir_dest)
{
   string msgout, msgin;
   string dir, dest;
   object ob;
   int is_light;
   
   if(!dir_dest)
      return 0;
   
   if (sscanf(dir_dest, "%s#%s", dir, dest) != 2) {
      tell_object(this_object(), "Move to bad dir/dest\n");
      return;
   }
   if (!msgout)
      msgout = "leaves";
   is_light = set_light(0);
   if (is_light < 0)
      is_light = 0;
   move_object(this_object(), dest);
   is_light = set_light(0);
   if (is_light < 0)
      is_light = 0;
   if (!msgin)
      msgin = "arrives";
   if (!is_light) {
      write("A dark room.\n");
      return;
   }
   ob = environment(this_object());
   call_other(ob, "long", 0);
   ob = first_inventory(ob);
   while(ob) {
      if (ob != this_object()) {
         string short_str;
         short_str = call_other(ob, "short");
         if (short_str)
            write(short_str + ".\n");
         }
      ob = next_inventory(ob);
   }
}
headlights(){
   if(headlights == 0){
      write("You turn the headlights on.\n");
      headlights = 1;
      set_light(1);
      return 1;
   }
   if(headlights == 1){
      headlights = 0;
      write("You turn the headlights off.\n");
      set_light(0);
      return 1;
   }
   return 1;
}
open(arg){
   if(!arg) { return; }
   if(arg == "box"){
      write("You open up the box and notice the instructions for the tractor are inside.\n");
      items += ({"instructions","These are the things you can do with the tractor\n"+
            "start...starts the engine (key required)\n"+
            "headlights...turns on or off the headlights.\n"+
            "drive [direction]...allows you to drive the tractor in standard directions.\n"+
            "intercom <msg>...Tells the room outside the tractor your message.\n"+
            "dt <msg>...Tells you message over the gossip channel.\n"+
            "lookout...looks to see what is outside.\n"+
            "MORE Features are coming...Mail suggestions to Beck.\n"+
            "",});
      return 1;
   }
   return;
}
intercom(str){
   if(!str){ write("Say something.\n"); return 1; }
   tell_room(environment(this_object()),"The tractor's intercom says: "+str+"\n");
   write("You say over the intercom: "+str+"\n");
   return 1;
}
dt(str){
   string msg;
   if(!str) return 0;
  if(this_player()->query_sp() < 20) return 0;
  this_player()->add_spell_point(-20);
   msg = "[From a John Deere Tractor] "+capitalize(this_player()->query_real_name())+" gossips: "+str+
   "\n";
   if(!str){ write("Say something.\n"); return 1; }
   "obj/user/one_chan.c"->chan_msg(msg,"gossip");
   return 1;
}
lookout(){
   object ob;
   environment(this_object())->long();
   for(ob = first_inventory(environment(this_object())); ob; ob = next_inventory(ob)){
      if(ob != this_object() && ob->short()) {
         write(ob->short());
         write("\n");
       }
   }
   return 1;
}
