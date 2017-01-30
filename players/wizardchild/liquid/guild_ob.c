/* /players/wizardchild/liquid/guild_ob.c: Liquid Metal guild object */
/* Please don't look unless you have a good reason - this file is in */
/* an open dir for debugging and checking purposes only. Certain     */
/* files are not in this dir due to their content.                   */
/* defines */
#define MASTER "/players/wizardchild/liquid/masterob.c"
#define ROOT "/players/wizardchild/liquid/"
#define SAVE "players/wizardchild/liquid/users/"
#define ME this_player()
#define ENV(o) environment(o)
#define OB this_object()
#define VER "Liquid Metal PK Guild - Prototype"
/* vars */
int kills, targeted, died, pkmon;
status guild_status, chan;
status rank;  /* only 2 ranks */

static object *touched;
static object target, shape;
static string myname;
static status loaded, local_check;
/* visual */
query_auto_load() { return "/players/wizardchild/liquid/guild_ob:"; }
short() { return 0; }
get()   { return 1; }
drop()  { return 1; }
id(str) {
  return str == "skin" || str == "metallic" || str == "metallic skin"
  /* following is used for recording deaths */
  || (str == "guild_death_object" && !local_check) || str == "GI";
}
long()  {
  write("A somewhat odd coloring, tinting your skin. Someone would have to be very\n");
  write("close to notice it, and even then it could be passed on as normal.\n");
  write("Type \"lmhelp liquid\" for guild info.\n");
  return 1;
}
/* only let them see it occasionally...*/
extra_look() {
  if(!random(5) || ME == environment(this_object()))
    return capitalize(myname)+" has a somewhat metallic appearance";
  return 0;
}
/* utilities */
log_error(str) {
  write_file(ROOT+"ERROR", "["+ctime(time())+"]: "+str+"\n");
}
restore_me() {
  if(!restore_object(SAVE+myname)) {
    write("Error restoring guild status.\n");
    log_error("restore error, myname "+myname+", mename "+ME->query_real_name());
  } else
    write("Liquifying your skin...\n"); /* how theme-ish */
  if(guild_status < 0) {
    write("You have been removed from this guild. Mail Wizardchild if this is a\n");
    write("problem.\n");
    this_player()->set_title("the solid");
    destruct(this_object());
  }
  if(query_verb()) return 1;  /* handle external calls */
}
save_me() {
  if(!environment(this_object())) return ; /* bitch of autoloading */
  if(!save_object(SAVE+myname)) {
    write("Error saving guild status.\n");
    log_error("save error, myname "+myname);
  } else
    write("Saving...done.\n");
  if(query_verb()) return 1;
  else {
    while(remove_call_out("save_me") != -1) ;
    call_out("save_me", 1200);
  }
}
/* load up */
reset(arg) {
  if(arg)
    return ;
  kills = targeted = 0;
  pkmon = 1;
  chan = 1;
  touched = allocate(10); /* allow images of 10 items */
  myname = "nobody";
  local_check = 0;
  call_out("save_me", 1200);
  call_out("fake_hb", 2);
}
init() {
  if(loaded && myname && this_player() != find_player(myname)) {
    write("Object misplaced. Destructing.\n");
    log_error("misplaced object, init by "+ME->query_real_name()+", myname "+myname);
    destruct(this_object());
  } else {
    myname = ME->query_real_name();
    loaded = 1;
  }
  restore_me();
  add_action("cmd", "lmmon");          /* toggle pk mon   */
  add_action("cmd", "lmstats");        /* guild stats     */
  add_action("cmd", "lmhelp");         /* help manager    */
  add_action("cmd", "kill");           /* special kill    */
  add_action("save_me", "lmsave");     /* guild save      */
  add_action("restore_me","lmliquid"); /* quick restore   */
  add_action("end_game", "quit");      /* special quit    */
  add_action("cmd", "lmtarget");       /* target someone  */
  add_action("cmd", "lmblock");        /* block an exit   */
  add_action("cmd", "lmtouch");        /* touch 4 memory  */
  add_action("cmd", "lmhall");         /* guild hall cmd  */
  add_action("cmd", "lmlist");         /* list touched    */
  add_action("cmd", "lmmelt");         /* melt into touch */
  add_action("cmd", "lmmeltoff");      /* return to normal*/
  add_action("cmd", "lmwho");          /* guild who       */
  add_action("cmd", "lmudw");           /* mud who         */
  add_action("cmd", "lmt");            /* guild talk/emote*/
  if(rank) {
    add_action("cmd", "mblock");       /* mass-lmblock    */
    add_action("cmd", "lmuntouch");    /* forget a touch  */
  }
  if(ME->query_level() > 21) {
    add_action("cmd", "see_touched");
    add_action("cmd", "lmstat");
  }
  if(ME->query_real_name() == "wizardchild")
    add_action("cmd", "lmpatch");
}
cmd(str) { return call_other(MASTER, query_verb(), str); }
end_game() {
  if(shape) {
    write("You melt into your original form.\n");
    MASTER->remove_shape();
  }
  if(target) {
    write(target->query_name()+" was not killed.\n");
    MASTER->remove_target();
  }
  local_end();
  save_me();
  return 0;
}
local_end() {
  while(remove_call_out("save_me") != -1) ;
  while(remove_call_out("fake_hb") != -1) ;
}
/* for monitor, other */
fake_hb() {
  while(remove_call_out("fake_hb") != -1) ;
  if(!environment(this_object())) return ; /* avoid autoloading runtimes */
  if(!find_player(myname)) {
    log_error("owner not found, myname "+myname+", env "+
	      file_name(environment(this_object())));
    local_end();
    destruct(this_object());
  }
  if((pkmon == 1 && ENV(OB)->query_attack()) || pkmon == 2)
    display_pk_mon();
  /* should never happen */
  if(target && !present("liquid_combat_ob", target))
    command("lmtarget "+target->query_real_name(), ME);
  call_out("fake_hb", 2);
}
/* the following is called by a combat_ob */
/* we only hear about it if we killed them */
other_player_died(ob) {
  tell_object(ENV(OB), "Recording PK kill.\n");
  MASTER->handle_kill(ob, ENV(OB));
}
/* the following is called by player.c */
/* the id has been tweaked to allow it */
guild_death() {
  object ob, ob2;
  if(target) {
    ob = present("liquid_combat_ob", target);
    if(ob->query_kill() == ENV(OB)) {
      MASTER->handle_death(ENV(OB));
      destruct(ob);
    }
  }
  local_check = 1; /* toggle local_check to avoid id */
  ob2 = present("guild_death_object", ENV(OB));
  if(ob2 && ob2 != this_object())
    ob2->guild_death();
  else {
    "/room/adv_guild"->correct_level(ENV(OB));
    if(ENV(OB)->query_extra_level())
      "/room/exlv_guild"->correct_extra_level(ENV(OB));
  }
  local_check = 0;
}
/* externally called */
query_ver()      { return VER;      }
query_version()  { return VER;      }
query_kills()    { return kills;    }
query_died()     { return died;     }
query_chan()     { return chan;     }
query_pkmon()    { return pkmon;    }
query_rank()     { return rank;     }
query_touched()  { return touched;  }
query_target()   { return target;   }
query_shape()    { return shape;    }
query_targeted() { return targeted; }
query_guild_status() { return guild_status; }

add_kill(x)     { kills += (x?x:1); }
add_died(x)     { died += (x?x:1);  }
set_pkmon(x)    { pkmon = x;        }
set_chan(x)     { chan = (x?1:0);   }
set_rank(x)     { rank = (x?1:0);   }
set_touched(ob) { touched = ob;     }
set_target(ob)  { target = ob;      }
set_shape(ob)   { shape = ob;       }
add_targeted(x) { targeted += (x?x:1);  }
set_guild_status(x) { guild_status = x; }
