/* NOT IN THE GAME */
inherit "obj/monster.talk";
string target, caller;

reset(arg) {
  if(arg) return;
  set_name("Alien");
  set_alias("alien");
  set_level(15);
  set_hp(600);
  set_al(-1000);
  set_ac(8);
  set_wc(20);
  set_short("An Alien.");
  set_long("One of Grimm's Aliens that has come to get someone for"+
           " impregnation.\n");
  set_aggressive(0);
  enable_commands();
}

init() {
  add_action("capture","capture");
  ::init(); }

capture(str) {
  caller = file_name(environment(this_player()));
  target = file_name(environment(find_player(str)));
  if (call_other(this_player(),"query_level") < 21) {
     write("You are unable to control this beast.\n");
     return; }

  say("Grimm uses his powers to summon "+str+".\n");
    move_object(this_object(),target);
say("Grimm reaches into a void and grabs "+str+".\n"+capitalize(str)+
  " kicks and screams as they are dragged off into the unknown.\n");
tell_object(find_player(str),"A hand materializes in front of"+
  " you.\nBefore you have a chance to run, it grabs you and drags you" +
  " into a void\nof unknown origin.  You then materialize in front of "+
    call_other(this_player(),"query_name")+".\n");
  move_object(this_object(),caller);
  move_object(find_player(str),caller);
say("The alien disappears until needed again.\n");
  destruct(this_object());
  return 1;
}
