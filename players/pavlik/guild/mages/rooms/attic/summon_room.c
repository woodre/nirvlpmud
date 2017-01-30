#include "/players/pavlik/guild/mages/rooms/ROOMS"
#define ME capitalize(this_player()->query_real_name())
inherit "room/room";
  string summoner;
  int heart_count;
reset(arg) {
  if(!arg) {
set_light(1);
short_desc="The Summoning Chamber";
long_desc=
"You are deep within the Earth, under the Tower of Mages.  Flickering\n"+
"torches cast evil shadows across this cavernous chamber.  This is the\n"+
"Summoning Chamber where powerful magic-users evoke mystic forces to\n"+
"thier aid.  Runes of summoning are drawn carefully on the ground.\n"+
"There is a shimmering portal before the south wall.\n";

dest_dir=({
  "players/pavlik/guild/mages/rooms/dragon_room", "west",
});

summoner = "none";
heart_count = 0;
   }
}
realm(){ return "NT"; }

init(){
  ::init();
  add_action("guild_move","gm");
  add_action("enter_portal","portal");
  add_action("summon_dragon","summon");
  add_action("drop_stone","drop");
  add_action("cmd_enter", "enter");
  mage_check();
}

enter_portal(){
  write("You step into the portal.\n");
  write("You are magically teleported back up into the Mage's Tower.\n");
  say(capitalize(this_player()->query_name())+" steps into the portal "+
  "and disappears.\n");
  move_object(this_player(), "players/pavlik/guild/mages/rooms/library");
  write(environment(this_player())->short()+"\n");
  say(capitalize(this_player()->query_name())+" steps out of the "+
  "shimmering portal.\n");
  return 1;
}

summon_dragon(str){
  object ob, obj;
  if(str == "dragon"){
    if(!present("heartstone", environment(this_player()))){
      if(present("heartstone", this_player())){
        write("You must place the heartstone on the ground first.\n");
        return 1;
        }
    write("You don't have the proper spell components to try this.\n");
    return 1;
    }
  if(find_living(this_player()->query_real_name()+"'s dragon")){
    write("You already have a dragon.\n");
    return 1;
    }
  if(this_player()->query_spell_point() < 100){
    write("You are too tired to attempt this right now.\n");
    return 1;
    }
  if(present("heartstone", this_object())->query_summon()!="none"){
    write("Someone else is casting a summoning spell right now.\n");
    write("You shudder at the thought of disrupting his spell.\n");
    return 1;
  }

  write(
  "You begin to trace the runes of summoning around the mystic Heartstone.\n");
  say(ME+" begins to trace runes of summoning around the mystic Heartstone.\n");
  present("heartstone", this_object())->set_summon(this_player()->query_real_name());
  summoner = this_player()->query_real_name();
  heart_count = 0;
  set_heart_beat(1);
  return 1;
  }
}

finish_summon(who){
  object obj;
  tell_room(this_object(), "\n"+
  "The Summoning Chamber glows hotly with awesome power!\n"+
  "Out of a swirling mist a Magnificent Dragon appears.\n"+
  "The Dragon bends and swallows the huge heartstone in a single bite.\n");
  obj = clone_object("players/pavlik/guild/mages/obj/dragon");
  destruct(present("heartstone", this_object()));
  present("mageobj", find_player(who))->set_dragon(obj);
  obj->set_owner(who);
  obj->configure_dragon();
  find_player(who)->add_spell_point(-100);
  move_object(obj, this_object());
  tell_room(this_object(), capitalize(obj->query_nme())+
  " bows before "+capitalize(summoner)+".\n");
  return 1;
}

heart_beat(){
  if(!present(find_player(summoner), this_object())){
    tell_room(this_object(), "The heartstone disappears.\n");
    if(present("heartstone", this_object()))
      destruct(present("heartstone", this_object()));
    set_heart_beat(0);
    heart_count = 0;
    return 1;
  }
  if(heart_count == 8) {
    finish_summon(summoner);
    set_heart_beat(0);
  }
  else if(heart_count == 6) {
  tell_room(this_object(), "\n");
  tell_room(this_object(), capitalize(summoner)+
  " clenches his fists and raises his arms toward the ceiling.\n"+
  "The Heartstone begins to spin faster and faster within the circle.\n"+
  "The stone begins to grow and change shape ...\n");
  }
  else if(heart_count == 4) {
  tell_room(this_object(), "\n");
  tell_room(this_object(), capitalize(summoner)+
  " completes the runes and begins to chant.\n"+
  "The chamber darkens and the air around you crackles with magic.\n");
  }
  else if(heart_count == 2) {
  tell_room(this_object(), "\n");
  tell_room(this_object(), capitalize(summoner)+
  " continues to carefully trace the runes around the stone.\n");
  }
  heart_count++;
}


drop_stone(str){
  if(str == "stone" || str == "heartstone") {
    if(!present("heartstone", this_player())) return 0;
    if(present("heartstone", this_object())){
      write("There is already a heartstone in the circle.\n");
      return 1;
    }
    write("You place the Heartstone in the middle of the Summoning Circle.\n");
    say(capitalize(this_player()->query_name())+" places a Heartone "+
    "in the Summoning Circle.\n");
    transfer(present("heartstone", this_player()), this_object());
    return 1;
  }
}

cmd_enter(str)
{
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "portal") {
    notify_fail("You may only \"enter portal\".\n");
    return 0;
  }
  return enter_portal();
}
