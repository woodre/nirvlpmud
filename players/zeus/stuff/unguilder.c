inherit "obj/treasure";

reset(arg) {
  if(arg) return;
  set_id("tool");
  set_alias("unguilder");
  set_short("Unguilderer tool <twitch>");
  set_long("Usage:  'unguild <fucker>'\n");
  set_weight(0);
  set_value(0);
}
init() {
  if((int)this_player()->query_level() > 39)
    add_action("unguild","unguild");
}

unguild(str) {
  object target;
  int glev, gxp;
  target=find_player(str);
  if(!str) return 0;
  if(!target) return 0;
  target->set_home(0);
  target->set_guild_name(0);
  gxp=target->query_guild_exp();
  glev=target->query_guild_rank();
  target->add_guild_rank(-glev);
  target->add_guild_exp(-gxp);
  target->add_exp(gxp);
  write("You have unguilded "+target->query_name()+".\n");
  command("save",target);
  tell_object(target, 
	  "A sense of panic fills you...\n"+
	  "You suddenly feel empty.\n");
  return 1;
}

