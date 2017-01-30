/*
  illusion.c - temporarily put an illusion here
*/

inherit "obj/treasure";

int WIZARD_LEVEL, expiration_time;
string owner_name, illusion_str;

query_save_flag() { return 1; }

reset(arg) {
  set_id("illusion");
  set_alias("vampire illusion");
  set_weight(999);
  set_value(0);
  WIZARD_LEVEL=32;
  illusion_str=0;
}

short() {
  string return_str;
  int ticks;
  return_str=illusion_str;
  if (this_player()->query_level() >= WIZARD_LEVEL ||
      present("vampire fangs", this_player()))
    return_str=return_str+"\n<<< This is a vampire's illusion. >>>\n";
  if (lower_case(this_player()->query_real_name())==owner_name)
    return_str=return_str+
               "\nAs the owner, you can dispel it with 'dispel illusion'\n";
  if (this_player()->query_level() >= WIZARD_LEVEL) {
    ticks=expiration_time - time();
    return_str=return_str+
      "<<< It is "+capitalize(owner_name)+
      "'s and is due to expire in "+ticks+" heartbeats. >>>\n"+
             "<<< As a wizard, you can get rid of it with 'dest illusion' >>>";
  }
  return return_str;
}

long() { write(short()+"\n"); }

init() {
  ::init();

  add_action("dispel_illusion", "dispel");
}


dispel_illusion(str) {
  if (!str || str != "illusion") return 0;
  destruct_this();
  return 1;
}

start_illusion(vampire_level) {
  int illusion_timer;
  if (vampire_level <= 0)
    illusion_timer=5;
  else
    illusion_timer=(vampire_level*60)+300; /* minimum of 5 minutes duration */
  /* don't want it there forever */
  if (illusion_timer > 600) illusion_timer=600;
  expiration_time=time()+illusion_timer;
  call_out("destruct_this", illusion_timer);
}

destruct_this() {
  if (find_player(owner_name))
    tell_object(find_player(owner_name),
      "Your illusion of \n'"+illusion_str+"'\n fades away.\n");
  tell_room(environment(this_object()),
    "You see a shimmering start.  Your vision seems unsteady for a moment.\n"+
    "When it clears, you see that something is different here.\n");
  destruct(this_object());
}

set_illusion(str) { illusion_str=str; }

set_owner(str) { owner_name=lower_case(str); }
query_owner() { return owner_name; }
