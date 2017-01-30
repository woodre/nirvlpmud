/* players/wizardchild/closed/logger/guild_ob.c: Logger's guild object     */
/* This is the first version of this object. If you are tinkering around in*/
/* here, you better be a God, or have a damn good excuse                   */

#define MASTER   "/players/wizardchild/closed/logger/masterob.c"
#define BACKUP   "/players/wizardchild/closed/logger/masterbak.c"
#define ROOT_DIR "/players/wizardchild/closed/logger/"
#define SAVE_DIR "players/wizardchild/closed/logger/users/"
#define ME   this_player()
#define OB   this_object()
#define NAME this_player()->query_name()
#define CP(s) capitalize(s)
#define ENV(s) environment(s)
#define SAVE_INTERVAL 600

/********PLAYER VARIABLES********/
int gmuffle, mon, grank, gxp, gpoints, stable_mode, max_gpoints;
int gstatus, swap_at, swap_amt;
status autoswap;
string *in_cabin, outside, cabin_long;
static string myname, following;
static object pet, truck, masterob;
static status has_loaded, ac_plus, freeze;
/******END PLAYER VARIABLES******/
/*********VISUAL ASPECTS*********/
short() { return CP(myname)+"'s logger pack"; }
long()  {
  object ob;
  ob = first_inventory(OB);
  write("A sturdy leather pack that is strapped around your back.\n");
  write("Type 'lhelp logger' for more info.\n");
  if(ob) write("    Inside your backpack, their lies:\n");
  while(ob) {
    if(ob->short()) write(ob->short()+"\n");
    ob = next_inventory(ob);
  }
  return 1;
}
id(str) { return str == "backpack" || str == "pack" || str == "logger pack" || str == "GI"; }
get()  { return 1; }
drop() { return 1; }
query_weight() { return 2; }
/*******END VISUAL ASPECTS********/
reset(arg) {
  if(arg) return 0;
  grank = gpoints = gxp = gmuffle = 0;
  stable_mode = mon = gstatus = max_gpoints = 1;
  following = myname = 0;
  in_cabin = allocate(10);
  ac_plus = has_loaded = autoswap = 0;
  swap_at = 30;
  swap_amt = 10;
  call_out("fake_hb", 2);
  call_out("save_me", SAVE_INTERVAL);
}
init() {
  if(has_loaded || (myname && myname != lower_case(NAME))) {
    write("You should not have this!\n");
    log_drop(ENV(OB)->short());
    destruct(OB);
  } else {
    myname = ME->query_real_name();
    has_loaded = 1;
  }
  load_master_object();
  restore_player(myname);
  heart_on();  /* for monitor */
  if(file_size(ROOT_DIR+"WELCOME") < 1)
    write("No guild news at this time.\n");
  else
    cat(ROOT_DIR+"WELCOME");
  masterob->lmaster(NAME+" steps in from the forest.");
  /* common commands     */
  add_action("look", "look", 1);
  add_action("save_me", "gsave");
  add_action("ncmd", "lhelp");
  add_action("ncmd", "lt");
  add_action("ncmd", "le");
  add_action("ncmd", "lchan");
  add_action("ncmd", "lw");
  add_action("ncmd", "nwho");
  add_action("end_game", "quit");
  add_action("which_ob", "which_ob");
  add_action("switch_bak","switch_bak");
  add_action("ncmd", "new_pack");
  add_action("acmd", "stable");
  add_action("acmd", "gs");
  add_action("ncmd", "store");
  add_action("ncmd", "retrieve");
  add_action("ncmd", "guild_bug");
  add_action("ncmd", "guild_typo");
  add_action("ncmd", "guild_comment");
  if(grank >=  1) {
    add_action("ncmd", "light");
    add_action("ncmd", "forge");
    add_action("acmd", "gp");
    add_action("acmd", "follow");
    add_action("acmd", "lmon");
  }
  if(grank >=  2) {
    add_action("ncmd", "chips");
    add_action("ncmd", "send");
    add_action("ncmd", "butcher");
    add_action("ncmd", "truck");
    add_action("ncmd", "splinter");
    add_action("ncmd", "autoswap");
  }
  if(grank >=  3) {
    add_action("acmd", "call");
    add_action("ncmd", "flannel");
    add_action("ncmd", "swap");
    add_action("ncmd", "lheal");
    add_action("ncmd", "hall");
    add_action("ncmd", "gdonate");
    add_action("ncmd", "gborrow");
  }
  if(grank >=  4) {
    add_action("end_fight", "end");
    add_action("ncmd", "camp_out");
    add_action("ncmd", "flame");
    add_action("ncmd", "set_swap");
  }
  if(grank >=  5) {
    add_action("acmd", "sharpen");
    add_action("acmd", "plant");
    add_action("acmd", "tlog");
  }
  if(grank >=  6) {
    add_action("ncmd", "branch");
    add_action("acmd", "bark");
  }
  if(grank >=  7) {
    add_action("ncmd", "snap");
    add_action("ncmd", "sizeup");
  }
  if(grank >= 8) {
    add_action("ncmd", "tree");
    add_action("acmd", "PAUL");
  }
  /* rank 15 && > (gc)   */
  if(grank >= 15) {
    add_action("ncmd", "lct");
    add_action("ncmd", "lce");
    add_action("ncmd", "gstat");
    add_action("ncmd", "npack");
    add_action("ncmd", "gprom");
  }
  /* rank 20 && > (gwiz) */
  if(grank >= 20) {
    add_action("acmd", "ban_logger");
    add_action("acmd", "gver");
  }
  /* give myself a neat-o command or two */
  if(myname == "wizardchild" || ME->query_level() >= 10000) {
    add_action("ncmd", "gob");
    add_action("ncmd", "slogo");
  }
}
/* commands */
ncmd(str) {
  return (masterob && call_other(masterob, query_verb(), str));
}
acmd(str) {
  return (masterob && call_other(masterob, "handle_odd", query_verb(), str));
}
end_fight(str) {
  return (str == "fight" && masterob->end_fight());
}
end_game()     { masterob->end_game(); }
look(str) {
  if(truck && ENV(truck) != ENV(ME))
    move_object(truck, ENV(ME));
  return 0;
}
/* end commands */
fake_hb() {
  while(remove_call_out("fake_hb") != -1) ;
  if(!ENV(OB)) return ;
  if(!living(ENV(OB))) destruct(OB);
  if(following && !find_player(following)) following = 0;
  if(!mon && !following)
    heart_off();
  if(mon == 2 || (mon == 1 && ENV(OB)->query_attack()))
    masterob->display_mon(ENV(OB));
  else if(mon == 1)
    heart_off();
  if(following && ENV(ENV(OB)) != ENV(find_player(following))) {
    ENV(OB)->move_player("leaves following "+CP(following)+"#"+file_name(ENV(find_player(following))));
    tell_object(ENV(OB),"You continue following "+CP(following)+".\n");
  }
  if(autoswap && gpoints < swap_at)
    auto_swap();
  call_out("fake_hb", 2);
}
heart_on()  { call_out("fake_hb", 2); }
heart_off() { while(remove_call_out("fake_hb") != -1) ; }
/******INTERNAL CHAR MANAGEMENT********/
save_me() {
  remove_call_out("save_me");
  if(!environment(this_object())) return 0;
  guild_maintenance();
  if(!save_object(SAVE_DIR+myname)) {
    write("Error saving guild stats.");
    log_err("error saving guild stats.");
  } else
    tell_object(environment(this_object()), "Saving guild status...done\n");
  if(query_verb()) return 1;
  call_out("save_me", SAVE_INTERVAL);
}
restore_player(name) {
  if(!name) name = myname;
  write("Restoring your guild stats...\n");
  restore_object(SAVE_DIR+name);
  if(masterob->checked_restore(gstatus))
    destruct(OB);
  guild_maintenance();
  return 1;
}
guild_maintenance() {
  if(!environment(this_object())) return 0;
  max_gpoints = (grank*30 > 300 ? 300 : grank*30);
  gpoints = (gpoints > max_gpoints ? max_gpoints : gpoints);
  if(autoswap && grank < 4) {
    swap_at = 30;
    swap_amt = 10;
  }
  if(!masterob) load_master_object();
  masterob->update_guild_stats(ENV(OB));
}
log_err(str) {
  write_file(ROOT_DIR+"ERROR", "<"+ctime(time())+"> ("+myname+") <-> "+str+"\n");
  return 1;
}
wait_func(fn, dl, arg) {
  call_out("execute", dl, fn+"////"+arg);
  return 1;
}
execute(str) {
  string fn, arg;
  sscanf(str, "%s////%s", fn, arg);
  call_other(masterob, fn, arg, find_player(myname));
  return 1;
}
load_master_object() {
  if(masterob) return ;
  if(find_object(MASTER))
    masterob = find_object(MASTER);
  else if(MASTER->lmaster("Guildmaster enters from the forests.\n"))
    masterob = find_object(MASTER);
  if(!masterob)
    switch_bak();
}
which_ob()   {
  write("You are currently on the ");
  write((masterob == find_object(MASTER) ? "core" : "backup")+" object.\n");
  return 1;
}
switch_bak() {
  if(!masterob && query_verb()) load_master_object();
  if(find_object(MASTER) && masterob == find_object(MASTER) || !masterob) {
    if(!find_object(BACKUP))
      BACKUP->lmaster("Guildmaster enters from the forest.\n");
    masterob = find_object(BACKUP);
  } else {
    if(!find_object(MASTER))
      MASTER->lmaster("Guildmaster enters from the forest.\n");
    masterob = find_object(MASTER);
  }
  if(query_verb()) {
    write("Loading object..."+(masterob?"done":"failed")+".\n");
    return 1;
  }
}
auto_swap() {
  int x;
  if((x=swap_amt) > ENV(OB)->query_sp())
    x = ENV(OB)->query_sp();
  tell_object(ENV(OB), "Auto-swapping "+x+" sp to gp.\n");
  ENV(OB)->add_spell_point(-x);
  gpoints += x;
}
/*****END INTERNAL CHAR MANAGEMENT*****/
/**********EXTERNALLY CALLED***********/
query_gmuffle()     { return gmuffle;     }
query_gpoints()     { return gpoints;     }
query_max_gpoints() { return max_gpoints; }
query_grank()       { return grank;       }
query_gxp()         { return gxp;         }
query_gstatus()     { return gstatus;     }
query_stable_mode() { return stable_mode; }
query_pet()         { return pet;         }
query_mon()         { return mon;         }
query_following()   { return following;   }
query_in_cabin()    { return in_cabin;    }
query_cabin_long()  { return cabin_long;  }
query_cabin_outside() { return outside;   }
query_ac_plus()     { return ac_plus;     }
query_freeze()      { return freeze;      }
query_has_truck()   { return truck;       }
query_autoswap()    { return autoswap;    }
query_swap_at()     { return swap_at;     }
query_swap_amt()    { return swap_amt;    }

add_gpoints(x) { gpoints = (gpoints+x>max_gpoints?max_gpoints:gpoints+x); }
add_gxp(x)          { gxp += x;        }

set_gmuffle(x)      { gmuffle = x;     }
set_in_cabin(blah)  { in_cabin = blah; }
set_cabin_long(st)  { cabin_long = st; }
set_cabin_outside(s){ outside = s;     }
set_following(str)  { following = lower_case(str); }
set_mon(i)          { mon = i;         }
set_pet(obj)        { pet = obj;       }
set_stable_mode(i)  { stable_mode = i; }
set_grank(x)        { grank = x;       }
set_gstatus(x)      { gstatus = x;     }
set_ac_plus()       { ac_plus = !ac_plus; }
set_freeze()        { freeze = !freeze; }
set_truck(obj)      { truck = obj;     }
set_autoswap(x)     { autoswap = x;    }
set_swap_at(x)      { swap_at = x;     }
set_swap_amt(x)     { swap_amt = x;    }

dest_pet()          { destruct(pet);   }
dest_truck()        { destruct(truck); }
lights()            { set_light(1);    }
/********END EXTERNALLY CALLED*********/
