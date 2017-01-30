#include <ansi.h>
int time_started;
#define MUFFLE_TIME 60000000
#define BASE_DIR "/open/star/muffler"
inherit "obj/treasure";

reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name ("");
  set_long(".\n");
  set_weight(0);
  set_value(0);
}

int restore_me()
{
  string tmp, tmp2, saveFile;
  int timeSave;
  object me;
  
  me = environment(this_object());
  
  if(!me || !me->is_player())
    return -1;
    
  if(file_size(BASE_DIR + "/muffled/" + me->query_real_name()) < 1)
    return 0;
    
  saveFile = read_file(BASE_DIR + "/muffled/" + me->query_real_name());
  if(sscanf(saveFile,"started: %d\n",timeSave));
  
  return timeSave;
}

int save_me()
{
  object me;
  
  me = environment(this_object());
  
  if(!me || !me->is_player())
    return 0;

  if(file_size(BASE_DIR + "/muffled/" + me->query_real_name()) > 0)
    rm(BASE_DIR + "/muffled/" + me->query_real_name());
    
  write_file(BASE_DIR + "/muffled/" + me->query_real_name(),"started: " + time_started + "\n");
  
  return 1;
}

void timeCheck()
{
  object obj;

  if(time_started + MUFFLE_TIME <= time())
  {
    obj = environment(this_object());
    if(obj && obj->is_player())
      tell_object(obj,"You can talk now.\n");
tell_object(obj,"TRYING TO REMOVE: " + BASE_DIR + "/muffled/" + obj->query_real_name() + "\n");
"/bin/wiz/_rm"->cmd_rm(BASE_DIR + "/muffled/" + obj->query_real_name());
rm("/open/star/muffler/muffled/bittystar");
rm("/open/star/blah");
    destruct(this_object());
      return;
  }
    
  call_out("timeCheck",2);
   
return;
}

init()
{
  int restoreTime;
  object me;

  ::init();
  
  me = environment(this_object());

  if(me && me->is_player())
  {
    restoreTime = restore_me(BASE_DIR + "/muffled/" +this_player()->query_real_name());

    if(restoreTime < 1)
    {
      time_started = time();
      save_me(BASE_DIR + "/muffled/" +this_player()->query_real_name());
    }
    else
      time_started = restoreTime;

    timeCheck();
  
    add_action("block", "gossip");
    add_action("block", "star");
    add_action("block", "shout");
    add_action("block", "babble");
    add_action("block", "risque");
    add_action("block", "tell");
    add_action("block", "say");
    add_action("block", "net");
    add_action("block", "onet");
    add_action("block", "id");
    add_action("block", "te");
    add_action("block", "tt");
    add_action("block", "gt");
    add_action("block", "gpt");
    add_action("block", "rt");
    add_action("block", "rte");
    add_action("block", "att");
    add_action("block", "at");
    add_action("block", "newbie");
    add_action("block", "wiz");
    add_action("block", "dest");
    add_action("block", "idest");
    add_action("block", "emote");
    add_action("block", "tc");
    add_action("block", "tl");
    add_action("block", "force");
    add_action("block", "vibe");
    add_action("block", "whisper");
    add_action("block", "farem");
    add_action("block", "mail");
    add_action("block", "echo");
    add_action("block", "echoto");
    add_action("block", "echoall");
    add_action("block", "quit");
    add_action("block", "page");
    add_action("block", "emotestar");
    add_action("block", "echostar");
    add_action("block", "i");
    add_action("block", "I");
    add_action("block", "IR");
    add_action("block", "htell");
    add_action("block", "stell");
    add_action("block", "ed");
    
    
  }
}

int block(string str)
{
  object me;
  
  me = environment(this_object());
  if(restore_me() > 0 && me && me->is_player())
  {
    tell_object(me,"You can not do that. You may talk again at " + ctime(time_started + MUFFLE_TIME) + ".\n");
    return 1;
  }
  
  return 0;
}

drop() { return 1; }
query_auto_load() { return "/players/star/toys/muffler.c:"; }
status id(string arg) { return ( arg == "myshitbitch" || arg == "catgotyourtongue" || arg == "shutthefuckup" ); }