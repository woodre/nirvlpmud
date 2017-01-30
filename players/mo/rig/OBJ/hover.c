int engine;
int key;
int headlights;
int elevation;
string items;
#include <ansi.h>;
reset(){
   engine = 1;
   key = 0;
   elevation = 1;
   items =
   ({ 
         "buttons","Several buttons.  One is labelled 'Ignition'.  Push it maybe?",
         "wheel","A wheel attached to a long stick.  It is used to fly the Helicopter.",
         "seats","Two leather seats.",
         "armrest","An armrest",
         "instructions"," Instructions:\n"+
         "Push button | Begins the Ignition sequence\n"+
         "Start | Lifts helicopter off the ground\n"+
         "Land | Lands the helicopter on a landing pad\n"+
         "Pitch | Drives the Helicopter (e.g., pitch north, east, etc)\n"+
         "Lookout | Look out the window to see what's below.\n"+
         "Take off - Lift the helicopter off the ground.",
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
   return str == "hover";
}
catch_tell (string str){
   if(this_player() != this_object()){
      if(!this_player() || !present(this_player(), this_object()))
         tell_room(this_object(), "Outside the helicopter: "+str);
      return 1;
   }
   return 1;
}
short(){
   return "A Bell-419 Helicopter "+BOLD+"[hovering above]"+NORM+"";
}
long(str){
   int i;
   if(present(this_player(),this_object())){
      if(!str){
         write(
            "You are sitting inside of a Bell 419 Helicopter.  There are several buttons\n"+
            "in front of you.  An instruction manual sits down to your right.  A wheel\n"+
            "is directly in front of you, and is used to fly the Helicopter.  The seats\n"+
            "have nice armrests and are very comfortable.\n");
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
   write("A large, red helicopter used to fly to the Chinle Oil Platform.\n"+
      "There is a small ladder that you could 'climb' to enter the cockpit.\n");
   return 1;
}
init(){
   if(present(this_player(),this_object())){
      add_action("lower","push");
      add_action("start","start");
      add_action("drive","pitch");
      add_action("lookout","lookout");
      add_action("land","land");
      add_action("takeoff","takeoff");
   }
   add_action("climb","climb");
   add_action("fly_away_3","fly_away_3");
   add_action("fly_away_4","fly_away_4");
}
fly_away_3() {
   call_out("fly_away_4", 5);
   return 1; }
fly_away_4() {
   if(environment()->query_hirandea()) {
      say("a Pilot walks in as the Helicopter flies off into the distance...\n");
      move_object(clone_object("/players/mo/rig/MON/pilot.c"),environment(this_object()));
      destruct(this_object());
      return 1; }
   if(!environment()->query_hirandea()) {
      say("the Helicopter flies off into the distance...\n");
      destruct(this_object());
      return 1; }
}
climb(arg){
   if(!arg){ write("What do you want to climb?\n"); return 1; }
   if(elevation == 1) {
      write("You need to wait for the Helicopter to land!\n");
      return 1;
   }
   if(present(this_player(),this_object())){
      if(engine == 1){
         write("You are still flying!\n");
         return 1;
      }
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
      say(capitalize(this_player()->query_real_name())+" climbs the ladder into the Helicopter.\n");
      return 1;
   }
   write("You may only climb the ladder of the Helicopter.\n");
   return 1;
}
start(){
   if(engine == 1){
      write("The props are already turning at full velocity.\n");
      return 1;
   }
   if(key == 0){
      write("You need to push the button to begin the ignition sequence.\n");
      return 1;
   }
   write("Ignition Complete.  Propellers at full velocity!\n");
   engine = 1;
   elevation = 1;
   this_object()->short("A Helicopter [hovering]");
   return 1;
}
land(){
   if(!environment()->query_launch_pad()) {
      write("You need to land on a landing platform.\n");
      return 1;
   }
   write("You land the Helicopter and turn off the engine.\n");
   engine = 0;
   elevation = 0;
   return 1;
}
takeoff() {
   if(!environment()->query_launch_pad()) {
      write("You can only take off on a launchpad.\n");
      return 1;
   }
   write("You slowly pull back on the wheel.  The helicopter lifts off the ground.\n");
   elevation = 1;
   return 1;
}
drive(str){
   object ob;
   string directions;
   directions = ({"east","west","southeast","southwest","northeast","northwest","north","south",});
   if(engine == 0){
      write("No ignition sequence detected.\n");
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
   if(!str){ write("What do you want to push?\n"); return 1; }
   if(str == "button") {
      write("You push the button to start the ignition sequence.  Now 'start'\n"+
         "the engine.\n");
      key = 1;
      return 1;
   }
   write("You can only push the button.\n");
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
query_launcher() { return 1; }

query_copter() { return 1; }
