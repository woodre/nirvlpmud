#define WHO this_player()->query_real_name()
inherit "obj/treasure";
  reset(arg) {
  if(arg) return;
  set_short("A small glowing gem");
  set_long("A small glowing gem.  This gem can be used to transport\n"+
         "one person to several different places."+
     "To use the Gems powers type: 'GO <church>, <shop>, or <hotel>'\n"+
    "however, beware, the gems powers are not always reliable!\n");
  set_weight(1);
   set_value(1750);
}
id(str) { return str == "gem" || str == "trans gem"; }
  init() {
  ::init();
      add_action("go", "GO");
}

get() {
    return 1;
}


go(str) {
  object ob;
  string here, there;
  int i;

  ob = this_player();
there = environment(ob);

 if (!str) {
  write("GO where?\n");
    return 1;
}

if(this_player()->query_sp()<35) {
 write("You are too low on power.\n");
  return 1;
  }
 if(environment(ob)->realm()=="NT") {
write("The Gem doesn't seem to function properly from this location.\n");
  return 1;
}
 i=random(100);
 if(90<i) {
 tell_room(there, WHO + " loses control of the magic and is swept away!\n");
tell_object(ob, "You close your eyes and try and concentrate on the "+str+"\n"+
"but you fail to focus the magic and it turns on you!  You feel yourself\n"+
"swept away.  When you open your eyes it is in a new place.\n");
   move_object(ob, "room/forest9");
  call_other(ob, "add_spell_point", -35);
  return 1;
}
 if(5>i) {
tell_room(there, WHO + " loses control of the magic and is swept away!\n");
tell_object(ob, "You close your eyes tightly and try and picture the "+str+"\n"+
"but you concentration faulters and the magic spins out of your control!\n"+
"You open your eyes to a strange place.\n");
    move_object(ob, "room/inn");
  call_other(ob, "add_spell_point", -35);
   return 1;
}
 if(i<2) {
tell_room(there, WHO + " losed control of the magic and is swept away!\n");
 tell_object(ob, "You close your eyes and try and concentrate on "+str+"\n"+
"but you fail to keep your focus.  You realize that you have lost control"+
"of the magic and forces out of your control deposit you in a place unknown.\n");
  move_object(ob, "room/prison.c");
  call_other(ob, "add_spell_point", -35);
  return 1;
}
 if(str == "shop") {
tell_room(there, WHO + " vanishes in a flash of bright light!\n");
tell_object(ob, "You hold the gem tightly in your hand and picture\n"+
"yourself in the main shop. When you open your eyes you are there!\n");
move_object(ob, "room/shop");
  call_other(ob, "add_spell_point", -35);
  return 1;
}
 if(str == "hotel") {
tell_room(there, WHO + " vanishes in a flash of bright light!\n");
tell_object(ob, "You old the gem tightly in your hands and picture\n"+
"yourself in the hotel lobby.  When you open your eyes you are there!\n");
move_object(ob, "players/boltar/hotel/hotel.c");
 call_other(ob, "add_spell_point", -35);
  return 1;
}
 if(str == "church") {
tell_room(there, WHO + " vanishes in a flash of bright light!\n");
tell_object(ob, "You hold the gem tightly in you hands and picture\n"+
"yourself in the church.  When you open your eyes you are there!\n");
  move_object(ob, "room/church");
  call_other(ob, "add_spell_point", -35);
  return 1;
}
}




