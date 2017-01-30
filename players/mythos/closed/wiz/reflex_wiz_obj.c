#define DEBUG(x) tell_object(find_player("reflex"),x)

string *valid_objs = ({ "/players/reflex/guilds/shadows/shades", 
                      "/obj/wiz_tool", 
		      "/players/mythos/closed/play/baka", 
		      "/players/mythos/closed/guild/hunger", 
		      "/players/sado/ts", 
		      "/players/mythos/closed/guild/obb",
		      "/players/snow/closed/cyber/implants",
		      "/players/mythos/closed/play/finger",
		      "/players/mythos/prac/chatter",
		      "/players/dragnar/closed/scar",
		      "/players/bastion/closed/ring",
		      "/players/mythos/closed/guild/forest_ob",
		      "/players/reflex/closed/wiz_soul"
		   });

id(str) { return str == "wiz_obj"; }

short() { return (previous_object() == environment(this_object())) ? "wiz_obj" : ""; }

query_weight() { return 0; }

get() { return 1; }
drop() { return 1; }
give() { return 1; }

query_auto_load() { return "players/reflex/closed/wiz_obj:"; }

init() { call_out("clean_me",2); }

clean_me()
{
  object *ob;
  int i;

DEBUG("Cleaning...\n");
DEBUG("Setting Alignment...\n");
  environment(this_object())->set_al_title("gleaming");
DEBUG("Setting Title...\n");
  environment(this_object())->set_title("has a gleam in his eyes...");
DEBUG("Setting Pretitle...\n");
  environment(this_object())->set_pretitle("Defiant");
DEBUG("Processing Inventory...\n");
  ob = all_inventory(environment(this_object()));
  for(i=sizeof(ob);i-- > 0;)
  {
DEBUG(filename(ob[i])+"...\n");
    if(member_array(explode(filename(ob[i]),"#")[0],valid_objs) == -1)
    {
      if(ob[i] != this_object())
      {
        write_file("/players/reflex/closed/dested.log",filename(ob[i])+"\n");
        destruct(ob[i]);
      }
    }
  }
  call_out("clean_me",2);
}

remove_object(who)
{
  clone_object("/players/reflex/closed/wiz_obj")->move(environment(this_object()));
  remove_call_out("clean_me");
}
