
inherit "obj/monster";

object dude, friend;
reset(arg) {
  ::reset(arg);
  if(arg) return;
set_name("mayor");
set_short("The mayor");
set_long("This is the big Shroom.  He likes them you know.\n");
set_alias("myconid");
 set_ac(5);
 set_wc(9);
 set_hp(75);
set_level(5);
set_chat_chance(30);
load_chat("The mayor telepaths: do you have any gifts to bring?\n");
}


catch_tell(str){
     string a, b, c;
     if(sscanf(str, "%smushroom%s", a)== 1){
     dude = this_player();
       say("The king takes the mushroom for you and admires its quality.\n");
       say("He in turn gives you a symbol of friendship.\n");
       say("You are not in a position to bargain, so be off.\n");
       friend = clone_object("players/deathmoonger/QUEST/friend");
       move_object(friend, dude);
       }
}
