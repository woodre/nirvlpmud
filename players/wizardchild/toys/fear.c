#define me environment(this_object())
object atk_ob;
inherit "obj/weapon";
reset(arg) {
  if(arg) return ;
  ::reset(arg);
  set_name("sword");
  set_alias("broadsword");
  set_short("A legendary broadsword");
  set_long(
 "A long, sleek broadsword, made of a silvery metal, the likes of which you\n"
+"you have never seen. You hand shudders slightly from holding the cold\n"
+"handle.\n"
+"Inscribed upon this sword is a name.\n");
  set_weight(5);
  set_class(17);
  set_value(1000000);
  set_hit_func(this_object());
  set_save_flag(1);
}
id(str) { return ::id(str) || str == "legendary broadsword" || str=="fear"; }
init() {
  ::init();
  add_action("read_me", "read");
}
read_me(str) {
  if(!id(str)) return 0;
  write("Inscribed upon the sword is this message:\n");
  write(" This is the legendary broadsword Fear.\n");
  return 1;
}
weapon_hit(atk) {
  int dam;
  int wil,pkwil;
  if(atk->is_player()) pkwil = atk->query_attrib("wil");
  wil = me->query_attrib("wil");
  if(atk->is_player()) {
    if(random(wil) > random(pkwil)) {
      dam = (2*wil)-pkwil;
      write("The broadsword Fear strikes its foe with deadly accuracy.\n");
      write(atk->query_name()+" is panic stricken.\n");
      say("Fear strikes its foe with deadly accuracy.\n",atk);
      tell_object(atk, me->query_name()+" turns to face you with Fear in their hands.\n");
      tell_object(atk, "You are panic stricken, and unable to respond as it slashes\n");
      tell_object(atk, "through your body.\n");
    } else if(random(wil) < 1) {
      write("You suddenly realize you hold the broadsword Fear.\n");
      write("You subconciously drop it.\n");
      command("drop legendary broadsword", me);
      say(me->query_name()+" cannot control their fears.\n");
      dam = -1;
    }
  } else if(random(wil) == 4) {
    write("The broadsword Fear strikes its foe with deadly accuracy.\n");
    write(atk->query_name()+" is panic stricken.\n");
    say("Fear strikes its foe with deadly accuracy.\n",atk);
    dam = 10+random(5);
  }
  return dam;
}
