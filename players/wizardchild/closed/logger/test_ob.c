/* players/wizardchild/closed/logger/test_ob.c: Logger's guild object       */
/* This is the first version of this object. If you are tinkering around in */
/* here, you better be a God, or have a damn good excuse                    */
#define DEBUG 1
#define MASTER   "/players/wizardchild/closed/logger/testmob.c"
#define ROOT_DIR "/players/wizardchild/closed/logger/"
#define SAVE_DIR "players/wizardchild/closed/logger/users/"
#define ME   this_player()
#define OB   this_object()
#define NAME this_player()->query_name()
#define CP(s) capitalize(s)
#define ENV(s) environment(s)
#define SAVE_INTERVAL 600

/********PLAYER VARIABLES********/
int gmuffle, mon, grank, gxp, gpoints, stable_mode, max_gpoints, gstatus;
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
get()          { return 1;     }
drop()         { return 1;     }
query_weight() { return 2;     }
/*******END VISUAL ASPECTS********/
/*********LOAD FUNCTIONS**********/
reset(arg) {
  if(arg) return 0;
  following = myname = grank = gpoints = gxp = gmuffle = 0;
  gstatus = max_gpoints = stable_mode = mon = 1;
  has_loaded = ac_plus = freeze = 0;
  in_cabin = allocate(10);
  load_master_object();
}
load_master_object() {
  if(!(masterob = find_object(MASTER))) {
    MASTER->lmaster("Guildmaster steps in from the forest.\n");
    masterob = find_object(MASTER);
    if(!masterob) masterob = MASTER;
    if(!masterob) {
      MASTER->log_err("Unable to get masterobj loaded.\n");
      destruct(this_object());
    }
  }
}
init() {
  if(has_loaded || (myname && myname != lower_case(NAME))) {
    write("You should not have this!\n");
    log_drop(ENV(OB)->short(), myname);
    destruct(OB);
  } else {
    myname = ME->query_real_name();
    has_loaded = 1;
  }
  restore_player(myname);
  if(cat(ROOT_DIR+"WELCOME")) ;
  else write("No guild news at this time.\n");
  masterob->lmaster(NAME+" steps in from the forest.");
  add_action("check_cmd"); add_xverb("");
  add_action("look","look",1);
  add_action("save_me", "gsave");
  add_action("end_game", "quit");
  add_action("switch_bak","switch_bak");
  if(grank >= 4)
    add_action("end_fight", "end");     /* stop fighting */
  if(myname == "wizardchild" || ME->query_level() >= 10000) {
    add_action("gob", "gob");
    add_action("slogo", "slogo");
  }
  call_out("autosave", SAVE_INTERVAL);
}
/*******END LOAD FUNCTIONS*******/
/*********USER COMMANDS**********/
check_cmd(str) {
  string cmd, args, ocmd;
  sscanf(str, "%s %s", cmd, args);
#ifdef DEBUG
  if(cmd == "quit" && myname == "wizardchild") destruct(OB);
#endif
  if(!masterob) load_master_object();
  return masterob->is_command(cmd, args, grank);
}
end_game()  { masterob->end_game();             }
look(str) {
  if(truck && ENV(truck) != ENV(ME))
    move_object(truck, ENV(ME));
  return 0;
}
switch_bak() {
  if(!(masterob = find_object(ROOT_DIR+"masterbak")))
    write("Error switching to backup object.\n");
  else
    write("Switched.\n");
  return 1;
}
gob(str)     { return masterob->gob(str);      }
slogo(str)   { return masterob->slogo(str);    }
/*******END USER COMMANDS******/
/************HB STUFF**********/
/* heart_beat stuff */
heart_on()  { set_heart_beat(1); }
heart_off() { set_heart_beat(0); }
heart_beat() {
  if(!following || !find_player(following))
    following = 0;
  if(!mon && !following)
    set_heart_beat(0);
  if(mon == 2 || (ENV(OB)->query_attack() && mon))
    masterob->display_mon(ENV(OB));
  if(following && ENV(ENV(OB)) != ENV(find_player(following))) {
    ENV(OB)->move_player("leaves following "+CP(following)+"#"+file_name(ENV(find_player(following))));
    tell_object(ENV(OB),"You continue following "+CP(following)+".\n");
  }
}
/************END HB STUFF**************/
/******INTERNAL CHAR MANAGEMENT********/
autosave() {
  save_me();
  call_out("autosave", SAVE_INTERVAL);
}
save_me() {
  guild_maintenance();
  if(!save_object(SAVE_DIR+myname)) {
    write("Error saving guild stats.");
    masterob->log_err("error saving guild stats.", myname);
  } else
    write("Saving guild status...done.\n");
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
  max_gpoints = (grank*30 > 300 ? 300 : grank*30);
  gpoints = (gpoints > max_gpoints ? max_gpoints : gpoints);
  masterob->update_guild_stats(ME);
}
/* these functions allow a call_out for the master object */
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
/*****END INTERNAL CHAR MANAGEMENT*****/
/**********EXTERNALLY CALLED***********/
query_gmuffle()       { return gmuffle;     }
query_gpoints()       { return gpoints;     }
query_max_gpoints()   { return max_gpoints; }
query_grank()         { return grank;       }
query_gxp()           { return gxp;         }
query_gstatus()       { return gstatus;     }
query_stable_mode()   { return stable_mode; }
query_pet()           { return pet;         }
query_mon()           { return mon;         }
query_following()     { return following;   }
query_in_cabin()      { return in_cabin;    }
query_cabin_long()    { return cabin_long;  }
query_cabin_outside() { return outside;     }
query_ac_plus()       { return ac_plus;     }
query_freeze()        { return freeze;      }
query_has_truck()     { return truck;       }
query_masterob()      { return masterob;    }

add_gpoints(x) { gpoints += x; guild_maintenance(); }
add_gxp(x)     { gxp += x;     guild_maintenance(); }
set_grank(x)   { grank = x;    guild_maintenance(); }

set_gmuffle(x)      { gmuffle = x;     }
set_in_cabin(blah)  { in_cabin = blah; }
set_cabin_long(st)  { cabin_long = st; }
set_cabin_outside(s){ outside = s;     }
set_following(str)  { following = lower_case(str); }
set_mon(i)          { mon = i;         }
set_pet(obj)        { pet = obj;       }
set_stable_mode(i)  { stable_mode = i; }
set_gstatus(x)      { gstatus = x;     }
set_ac_plus()       { ac_plus = !ac_plus; }
set_freeze()        { freeze = !freeze; }
set_truck(obj)      { truck = obj;     }
set_masterob(obj)   { masterob = obj;  }

dest_pet()          { destruct(pet);   }
dest_truck()        { destruct(truck); }

lights()            { set_light(1);    }
/********END EXTERNALLY CALLED*********/
