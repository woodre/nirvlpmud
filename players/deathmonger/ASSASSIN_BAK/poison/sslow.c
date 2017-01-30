
#define DELAY 10

inherit "players/deathmonger/poison/poison";
string my_player;
string cur_dir;
int release;

reset(arg){
   set_short("slowness");
   set_long("This poison really slows things down.\n");
}

init(){
   add_action("slow", "north");
   add_action("slow", "south");
   add_action("slow", "west");
   add_action("slow", "east");
}

slow(){
    if(!release){
      cur_dir = query_verb();
      my_player = this_player()->query_real_name();
      release = 1;
      call_out("slow", DELAY);
      return 1;
   }
   else {
      write(cur_dir+"\n");
      command(cur_dir, find_player(my_player));
      release = 0;
      return 1;
   }
}

