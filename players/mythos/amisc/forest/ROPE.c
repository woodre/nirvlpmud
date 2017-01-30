#define tp this_player()->query_name()
#define ep environment(this_player())
#define eo environment(this_object())

inherit "obj/treasure";
string place, who;

reset(arg) {
  if(arg) return;

  set_id("rope");
  set_short("Rope of Binding");
  set_long("Fudo's Rope of Binding.  It is a rope of great toughness.\n"+
              "Fudo used it to 'capture' evil doers to a set area.\n");
  set_weight(2);
  set_value(2000);
}

init() {
  ::init();
  add_action("bbind","capture");
  }
  
bbind(str) {
object victim;
if(!str) {write("You wish to capture who?\n"); return 1;}
  sscanf(str,"%s",who);
  victim=find_living(lower_case(who));
  if(!present(who,ep)) {write("Not here to capture...\n"); return 1;}
  if(victim->query_npc()) {
  write("You have binded "+capitalize(who)+".\n");
  who=victim->query_name();
  place=(this_player()->query_current_room());
  move_object(this_object(),victim);
  call_out("bonded",3);
  return 1;}
  else {
  write("You may not use this against another player!\n");
  return 1;}
  return 1;}
  
bonded() {
  if(0 == random(20)) {tell_room(environment(eo),capitalize(eo->query_name())+" breaks free!\n");
  return 1;}
  if(eo->query_name() != who) {return 1;}
  else {
  if((eo->query_current_room()) != place) {
    move_object(eo,place);
    call_out("bonded",3);
  return 1;}
  call_out("bonded",3);
  return 1;} 
return 1;}
