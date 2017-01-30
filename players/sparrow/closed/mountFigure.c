#include <ansi.h>
inherit "obj/monster";

object mount;

reset(arg) {
  ::reset();
  if(arg) return;
  set_name("cat");
  set_aggressive(0);
  set_alias("shadowcat");
  set_short(HIC+"S"+HIK+"hadow"+HIC+"C"+HIK+"at "+HIC+"[" +HIK+this_player()->query_real_name()+HIC+"]"+NORM);
  set_long("A ShadowCat mount.\n" +
           this_player()->query_name() + " is mounted on top.\n");
  set_level(19);
  set_hp(250);
  set_wc(100);
  set_ac(100);
  set_chance(0);
  set_spell_dam( );
  set_spell_mess1(" \n");
  set_spell_mess2(" \n");
  set_aggressive(0);
}

init() {
  add_action("Mount","mount");
  add_action("dismount","dismount");
  if (this_player()==mount) {
    add_action("look","l");
    add_action("look","look");
  }
  ::init();
}

look() {
write("not yet\n");
}
query_real_name() { return "ShadowCat"; }

Mount() {
string tpname;

  tpname=this_player()->query_name();
  if (tpname != "Sparrow") {
    write("Sparrow's ShadowCat bucks you to the ground!\n");
    say("Sparrow's ShadowCat throws " + tpname + !"\n",this_player());
    return 1;
  }
  write("You mount the powerful beast\n");
  say(tpname + " mounts Sparrow's ShadowCat.\n",this_player());
  if (environment(this_object())==this_player())  {
    write("(You set the beast down first.)\n");
    move_object(this_object(),environment(this_player()));
  }
  move_object(this_player(),this_object());
  mount=this_player();
  set_long("A ShadowCat mount.\n" +
           this_player()->query_name() + " is mounted on top.\n");
  return 1;
}

dismount() {

  if (environment(this_player()) != this_object()) {
    write("You aren't mounted on the beast!\n");
    return 1;
  }
  write("You carefully dismount the ShadowCat.\n");
  say(this_player()->query_name() + " steps down from atop Sparrow's ShadowCat.\n",this_player());
  move_object(this_player(),environment(this_object()));
  if(this_player()==mount) mount=0;
  set_long("A ShadowCat mount.\n" +
           "No one is mounted on top.\n");
  return 1;
}


query_auto_load() { return "/players/sparrow/closed/mountFigure:"; }

get() { return 1; }

drop() {
  write("You can't drop this steed.\n");
  return 1;
}