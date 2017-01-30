/*
  trapper.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  if (arg) return 0;
::reset();

  set_name("trapper");
  set_level(15);
  set_alias("nooneelsetrapper");
  set_race("human");
  set_hp(325);
  set_al(0);
  set_short("A trapper");
  set_long("A fairly dirty man, who looks like he lives in the forest.\n");
  set_wc(16);
  set_ac(7);
  set_aggressive(0);
  set_chat_chance(50);
  load_chat("The Trapper says: Have you seen the bear?  Which way is she?\n");
  load_chat("The Trapper says: Tell me where the cubs are!  "+
            "I'll trap that bear!\n");
  load_chat("The Trapper says: Lead me to the bear!  You can have the hide!\n");
  load_chat("The Trapper says: Come on!  Say which direction she's in.  You\n"+
             "can have the hide!\n");
  set_gender("male");
  obj=clone_object("obj/money");
  obj->set_money(1500);
  move_object(obj, this_object());
}

init() {
  ::init();

  add_action("say", "say");
}

say(str) {
  object obj;
  string a, b, c, message, str1, str2, str3;
  str1=file_name(environment(this_object()));
  sscanf(str1, "%s.c", str2);
  if (!str2) str2=str1;
  if (str=="n") str="north";
  if (str=="s") str="south";
  if (str=="e") str="east";
  if (str=="w") str="west";
  a="x"+str+"x";
  if (sscanf(a, "north%s", b)==1 ||
      sscanf(a, "%snorth", b)==1 ||
      sscanf(a, "%snorth%s", b, c)==2) {
    command("north", this_object());
    return 1;
  }
  if (sscanf(a, "south%s", b)==1 ||
      sscanf(a, "%ssouth", b)==1 ||
      sscanf(a, "%ssouth%s", b, c)==2) {
    if (str2=="players/nooneelse/mazeforest/m_forest0") {
      tell_room(environment(this_object()),
                "The trapper looks at you and laughs.\n"+
                "He says:  You don't know where the hell "+
                "you're going, do you?\n"+
                "The trapper shakes his head and leaves.\n");
      move_object(this_object(), "players/nooneelse/mazeforest/m_forest27");
      return 1;
    }
    command("south", this_object());
    return 1;
  }
  if (sscanf(a, "east%s", b)==1 ||
      sscanf(a, "%seast", b)==1 ||
      sscanf(a, "%seast%s", b, c)==2) {
    if (str2=="players/nooneelse/mazeforest/m_forest9") {
      tell_room(environment(this_object()),
                "The trapper looks east and breaks into a big grin.\n"+
                "He says:  Thanks pal!  I'll get her now!  Here, take this.\n"+
                "The trapper hands "+this_player()->query_name()+" a large"+
                " bear hide and leaves to get his traps.\n");
      obj=clone_object("players/nooneelse/obj/bear_hide");
      move_object(obj, this_player());
      destruct(this_object());
      return 1;
    }
    if (str2=="players/nooneelse/mazeforest/m_forest0") {
      tell_room(environment(this_object()),
                "The trapper looks at you and laughs.\n"+
                "He says:  You don't know where the hell "+
                "you're going, do you?\n"+
                "The trapper shakes his head and leaves.\n");
      move_object(this_object(), "players/nooneelse/mazeforest/m_forest27");
      return 1;
    }
    command("east", this_object());
    return 1;
  }
  if (sscanf(a, "west%s", b)==1 ||
      sscanf(a, "%swest", b)==1 ||
      sscanf(a, "%swest%s", b, c)==2) {
    if (str2=="players/nooneelse/mazeforest/m_forest0") {
      tell_room(environment(this_object()),
                "The trapper looks at you and laughs.\n"+
                "He says:  You don't know where the hell "+
                "you're going, do you?\n"+
                "The trapper shakes his head and leaves.\n");
      move_object(this_object(), "players/nooneelse/mazeforest/m_forest27");
      return 1;
    }
    command("west", this_object());
    return 1;
  }
}
