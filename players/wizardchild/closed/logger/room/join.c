/* join.c: guild joining/leaving/object saving room */
 
/* remove the following line to allow guild entry   */
#define LOCKEDOUT 1
#define ROOT_DIR "/players/wizardchild/closed/logger/"
#define MASTEROB "/players/wizardchild/closed/logger/masterob.c"
 
inherit "room/room";
reset(arg) {
  if(arg) 
    return 0;
  set_light(1);
  short_desc = "A grassy meadow";
  long_desc  = "In the middle of the forest, you find a large grassy meadow.\n"
              +"By the looks of the vegetation, this land was logged not too long ago. Today,\n"
              +"however, it is a lush landscape. Just up the road, you can see a few logging\n"
              +"trucks, but according to a nearby sign, that is private property.\n"
              +"If you wish to join the logger's guild, type \"join_guild\". Read the sign for\n"
              +"more information.\n";
  dest_dir   =
  ({
    "room/plane12", "back"
  });
  move_object(clone_object(ROOT_DIR+"room/jsign.c"), this_object());
}
init() {
  if(present("logger pack", this_player())) {
    add_action("quit_guild", "leave_guild");
    add_action("enter", "enter");
  } else {
    add_action("get_obj", "get");
    add_action("join_guild", "join_guild");
    add_action("guild_info", "info");
  }
  ::init();
}
static quit_guild() {
  input_to("check_quit");
  write("Are you SURE you want to leave the logger's guild and loose ALL of your\n");
  write("guild experience (y/N)? ");
  return 1;
}
static check_quit(str) {
  string s;
  if(!str || str != "y") 
    write("Ok.\n");
  else {
    s = capitalize(this_player()->query_real_name());
    MASTEROB->lmaster(s+" has left the loggers guild!\n");
    write("The master logger tells you: FOOL! You shall pay for your mistake!\n");
    this_player()->raise_strength(-2);
    present("logger pack", this_player())->unjoin_player();
    write("The master logger tells you: Get out of my guild!\n");
    this_player()->move_player("church#room/church");
  }
  return 1;
}      
enter() {
  if(!present("logger pack", this_player())) {
    write("You try to enter, when a guard dog comes running in your direction.\n");
    write("You decide to hold off on that one.\n");
  } else 
    this_player()->move_player("the meadow#players/wizardchild/closed/logger/room/g_hall");
  return 1;
}
get_obj(str) {
  if(str != "pack") return 0;
  if(this_player()->query_guild_name() == "logger" &&
     file_size(ROOT_DIR+"users/"+this_player()->query_real_name()+".o") > 0) {
    write("You have been confirmed as a logger.\n");
    move_object(clone_object(ROOT_DIR+"guild_ob.c"), this_player());
  } else 
    write("You are not a member of this guild!\n");
  return 1;
}
join_guild() {
#ifdef LOCKEDOUT
  return 0;   /* don't allow premature joining! */
#endif
  if(this_player()->query_real_name() == "guest") {
    write("Guest cannot join a guild.\n");
    return 1;
  }
  if(present("logger pack", this_player()) ||
     file_size(ROOT_DIR+"users/"+this_player()->query_real_name()+".o") > 0)
    write("You are already a member of this guild!\n");
  else if(present("GI", this_player()) || this_player()->query_guild_name()) 
    write("You cannot join this guild without first quitting your current guild.\n");
  else {
    if(this_player()->query_level() < 5) {
      write("You must be of a higher level before joining this guild.\n");
      return 1;
    }
    if(this_player()->query_attrib("str") < 12) {
      write("You must be stronger before joining this guild.\n");
      return 1;
    }
    move_object(clone_object(ROOT_DIR+"guild_ob.c"), this_player());  
    MASTEROB->lmaster(this_player()->query_name()+" has joined the logger's guild!\n");
    present("logger pack", this_player())->save_me();
    this_player()->move_player("the meadow#players/wizardchild/closed/logger/room/g_hall.c");
  }
  return 1;                         
}
guild_info() {
  write("The loggers guild consists of 8 ranks. You attain a higher rank by donating\n");
  write("experience. The theme is directed towards strength, something that a logger\n");
  write("can definitely brag about. If you are unsure about joining, then please feel\n");
  write("free to ask me or any other guild member for help.\n");
  write("-Wizardchild-\n");
  return 1;
}
