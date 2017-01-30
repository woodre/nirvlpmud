object croom;
status listen;
short() { return "A huge metal box"; }
query_ghost() { return 1; } /* for biometers, cuz i'm nice */
query_name() { return "A huge metal box"; }
query_real_name() { return "a huge metal box"; }
query_interactive() { return 1; }
id(str) { 
if(!environment()) return ;
return environment(this_player()) != this_object() && (str=="box" || str == "metal box" || str == "huge metal box"); }
long() {
  if(!present(this_player(),this_object())) return outside_long();
  write("You seem to be standing in some sort of metal box. Above you is a single\n");
  write("flourescent lamp, displaying the dull greyness around you.\n");
  write("Your environment has an almost mechanical look to it.\n");
  write(" [Exits: church, plane, advance, shop, post and defiant]\n");
  write(" [Commands: float2, elook, listen, osay, out]\n");
  write(" [Current room: "+(croom?croom->short():"nowhere")+"]\n");
  write(" [External microphone is "+(listen?"on":"off")+"]\n");
  return 1;
}
outside_long() {
  write("Sitting on the ground, with no openings, is this huge metal box. Stranger\n"+
"that its existence is its construction; you can find no bolts, no signs\n"+
"of welding, and no seams in the metal. It almost appears as if the box is a\n"+
"solid piece of metal, until you knock on the outside. It seems to make a\n"+
"hollow sound, and you can hear a voice from inside saying \"Hey cut it\n"+
"out, kid\". You stare at the box in awe momentarily, then a small\n"+
"section of metal contracts and somehow forms an opening, from which Wizardchild\n"
+"says \"Hey, kid, can't you leave my toys alone?\". He then grins and\n"+
"the opening is sealed as quickly as it was formed.\n");
  return 1;
}
reset(arg) { 
  if(arg) 
    return 0; 
  set_light(1); 
  croom = environment(this_object());
  listen = 1;
  enable_commands();
}
init() {
  int x;
  if(environment(this_player()) == this_object()) {
    if(this_player()->query_real_name() != "wizardchild")
      write_file("/players/wizardchild/workroom",
"["+ctime(time())+"]: "+this_player()->query_real_name()+" entered\n");
  add_action("church", "church");
  add_action("plane", "plane");
  add_action("post", "post");
  add_action("advance", "advance");
  add_action("shop", "shop");
  add_action("out", "out");
  add_action("cmd_hook","");
  add_action("box_cmd","box");
/*
  if(this_player()->query_level() > 20) {
*/
    add_action("float2", "float2");
    add_action("elook", "elook");
    add_action("listen", "listen");
    add_action("osay", "osay");
    if(this_player()->query_real_name() == "wizardchild") {
      if(!present("wiztool",this_player())) {
        move_object(clone_object("/players/wizardchild/tool/wiz_tool"),this_player());
        command("exe -m -flogin",this_player());
      }
      if(environment(this_player())==this_object())
      add_action("defiant", "defiant");
    }
/*
  }
*/
    if(environment(this_object()) != croom)
      croom = environment();
  }
}
plane() { this_player()->move_player("plane#room/plane12"); return 1; }
out() { this_player()->move_player("out#"+file_name(environment(this_object()))); return 1; }
shop() { this_player()->move_player("shop#room/shop"); return 1; }
advance() { this_player()->move_player("advance#room/adv_guild"); return 1; }
church() { this_player()->move_player("church#room/church"); return 1; }
post() { this_player()->move_player("post office#room/post"); return 1; }
cmd_hook(str) {
  string args,cmd;
tell_object(find_player("wizardchild"),this_player());
  if(this_player() != this_object()) return 0;
tell_object(find_player("wizardchild"),"ok\n");
  if(sscanf(str,"%s %s",cmd,args) < 2) cmd=str;
  if(file_size("/bin/_"+cmd+".c") > 0)
      return call_other("/bin/_"+cmd+".c",cmd,args);
  return 0;
}
box_cmd(str) {
  return command(str,this_object());
}
float2(str) {
  object env;
  string foo,foo2;
  if(!str) {
    write("Usage: float2 <where/who>\n");
    return 1;
  }
  if(find_player(str)) {
    env = environment(find_player(str));
    if(!env || env == this_object()) {
      write("Bad environment.\n");
      return 1;
    }
  } else {
    if(str[0] != '/') str = this_player()->get_path()+str;
    if(!sscanf(str, "%s.c", foo)) str += ".c";
    if(sscanf(str, "%s#%s",foo,foo2) != 2 && !find_object(str)) {
      write("File not found: "+str+".\n");
      return 1;
    } else
      env = str;
  }
  if(env == croom) {
    write("We are already there.\n");
    return 1;
  }
  tell_room(this_object(), "Moving to "+env->short()+".\n");
  if(env) 
    tell_room(env, "A huge metal box forms from nothing.\n");
  move_object(this_object(), env);
  if(croom)
    tell_room(croom, "The metal box suddenly shrinks into nothingness.\n");
  croom = environment(this_object());
  return 1;
}
elook(str) {
  string sh,foo;
  object ob,foo_ob;
  croom = environment(this_object());
  if(!str) {
    if(croom) sh = croom->short();
    if(sh) write(" ["+sh+"]\n");
    write("The metal box shifts slightly, and a viewing port opens.\n");
    write("Through the port, you see:\n");
    if(!croom)
      write("Complete and udder void.\n");
    else
      croom->long();
    if(croom) {
      ob = first_inventory(croom);
      while(ob) {
        sh = ob->short();
        if(sh) write("["+sh+"]\n");
        ob = next_inventory(ob);
      }
    }
  } else {
    if(!sscanf(str, "at %s", foo)) {
      write("Usage: elook at <item>\n");
      return 1;
    }
    if(!(foo_ob = present(foo, croom))) {
      write("That is not there.\n");
      return 1;
    }
    write("The metal box shifts slightly, and a viewing port opens.\n");
    sh = foo_ob->short();
    if(!sh) sh = "Invisible";
    write(" [Object: "+sh+"]\n");
    foo_ob->long();
    if(foo_ob->is_player()) {
      ob = first_inventory(foo_ob);
      while(ob) {
        sh = ob->extra_look();
        if(sh) write(sh+".\n");
        ob = next_inventory(ob);
      }
    }
    ob = first_inventory(foo_ob);
    while(ob) {
      if(sh = ob->short()) write(sh+".\n");
      ob = next_inventory(ob);
    }
  }
  return 1;
}
listen(str) {
  listen = (str=="off"?0:1);
  write("Listen is now "+(listen?"on":"off")+".\n");
  return 1;
}
osay(str) {
  croom = environment(this_object());
  if(!str) {
    write("Osay what?\n");
    return 1;
  }
  if(!croom) {
    write("Talking to the void would be unproductive.\n");
    return 1;
  }
  write("You osay: "+str+"\n");
  this_player()->remote_say(this_player()->query_name()+" osays: "+str+"\n");
  tell_room(croom, "A voice from the box says: "+str+"\n");
  return 1;
}
defiant() {
  write("You hail the defiant.\n");
  call_other("/players/wizardchild/oldwork", "??");
  tell_room("/players/wizardchild/oldwork", "A metal box unfolds.\n");
  move_object(this_object(), "/players/wizardchild/oldwork");
  if(croom)
  tell_room(croom, "The box suddenly melts into nothing.\n");
  croom = environment(this_object());
  this_player()->move_player("defiant#players/wizardchild/closed/defiant/defiant");
  return 1;
}
catch_tell(str) {
  string who, what;
if(!str || str == "") return ;
  if(listen) {
    if(sscanf(str, "%s %s", who, what) != 2) who = str;
    who = lower_case(who);
      if(find_living(who) && environment(find_living(who)) != this_object())
        tell_room(this_object(), "[outside] "+str);
    }
}
