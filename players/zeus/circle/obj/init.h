
init(){

if(!environment()) return;
  environment()->set_guild_file(basename(this_object()));
if(!file_size("/"+SAVE_PATH+this_player()->query_real_name()+".o")) return;
if(!this_player()->is_player()) return;

  /* 03/24/06 Earwax: Added this: */
  /* 12/22/06 Rumplemintz: Changed this: */
  this_player()->set_guild_file("/players/guilds/fallen/circle.c");
  move_object(clone_object("/players/guilds/fallen/circle.c"), this_player());
  destruct(this_object());
  return;
  history = allocate(MAX);

  if(!random(300))
    call_out("nightmare", 1800+random(1800), environment()); 

  Skills = ({ });
  posendcol = WHT;
  negendcol = HIR;
  restore_circle();
  norm = NORM;
  casting = 0;

  if(environment()->query_level() < 21)
    call_other("/players/zeus/circle/daemon/daemon","XXX");

     /****--  spells  --****/
  add_action("wither_spell", "wither");
  add_action("shadowblast", "blast");
  add_action("drain_spell", "drain");
  add_action("teleport", "teleport");
  add_action("dark_prayer", "dark");
  add_action("repulsion", "repulsion");
  add_action("dark_assistance", "assistance");
  add_action("empower", "empower");
  add_action("shadowring", "web");
  add_action("shadowweave", "weave");
  add_action("deweave", "deweave");
  add_action("shadowform", "shadowform");
  add_action("shadowrage", "rage");
  add_action("vanish", "vanish");
  add_action("shadowcloak", "shadowcloak");
  add_action("siphon", "siphon");
  add_action("weaken", "weaken");
  add_action("mud_spell", "mi");
  add_action("mud_spell", "missle");
  add_action("mud_spell", "sh");
  add_action("mud_spell", "shock");
  add_action("mud_spell", "fi");
  add_action("mud_spell", "fireball");
  add_action("mud_spell", "so");
  add_action("mud_spell", "sonic");
  add_action("focus", "focus");
  add_action("descend", "descend");
  add_action("descend", "dscnd");
  add_action("meditate", "meditate");
  add_action("new_invis", "invisible");
  add_action("see", "see");
  add_action("sshield", "shield");
  add_action("know", "know");
  add_action("vigor", "vigor");
  add_action("beckon", "beckon");
  add_action("summon", "summon");
  add_action("embrace", "embrace");
     /****--  commands  --****/
  add_action("quit_out", "quit");
  add_action("score_cmd", "sc");
  add_action("set_percent", "set_percent");
  add_action("endurance_mon", "toggle_endurance");
  add_action("set_ecolor", "ecolor");
/*
  add_action("who2_new", "who2");
*/
  add_action("remove_all", "remove");
  add_action("emote_cmd", "emote");
  add_action("guild_cmd", "guild");
  add_action("chelp_cmd", "chelp");
  add_action("update_obj", "cupdate");
  add_action("save_circle", "csave");
  add_action("restore_circle", "crestore");
  add_action("back_me_up", "cbackup");
  add_action("upistrfrsf", "upistrfrsfdpfor");
  add_action("set_title", "set_title");
  add_action("speak_cmd", "speak");
  add_action("speak_cmd", "sp");
  add_action("meditate", "meditate");
  add_action("drift", "drift");
  add_action("c_monitor", "mon");
  add_action("c_setmon", "setmon");
  add_action("stop_casting", "stop");
     /****--  emotes  --****/
  add_action("shadow_wave", "swave");
  add_action("stand", "stand");
  add_action("battle_cry", "bcry");
  add_action("fdraw", "fdraw");
  add_action("scoff_cmd", "scoff");
  add_action("wait_cmd", "wait");

  call_other(this_player(), "wear", this_object(), 1, "shield",
    ({"physical",0,0,"shield_bonus"}));
/*
  call_other(this_player(), "wear", this_object());
  set_type("shield");
  set_ac(0);            
  worn_by = this_player();
  worn = 1;
*/
  set_class(3);
  wielded_by = environment();
  call_other(environment(), "wield", this_object(), 1);
  wielded = 1;
  set_hit_func(this_object());
  message_hit=({
    "massacre"," to small fragments",
    "massacre"," to small fragments",
    "smashed"," with a bone crushing sound",
    "hit"," very hard",
    "hit"," hard",
    "hit","",
    "grazed","",
    "tickled"," in the stomach",
  });
   if(!custom_monitor && (string)this_player()->query_monitor_string())
   {
      custom_monitor = (string)environment()->query_monitor_string();
      environment()->set_monitor_string(0);
   }
}

