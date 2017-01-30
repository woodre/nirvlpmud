/*
 *  Guild emote master object. All emotes inherit from this.
 */
inherit "obj/clean";
#include "../DEFS.h"

string emoteName, myMsgU, myMsgD, roomMsgU, roomMsgD, tellMsg, farMsg, owner;
static status loaded;


string getSavePath()
{
  string path;
  string *fileParts;
  fileParts = explode(file_name(this_object()), "/");
  /* get only the name of the file */
  path = EMOTESAVEDIR +"/"+ fileParts[sizeof(fileParts)-1];
  return path;
}


void saveData()
{
  save_object(getSavePath());
}


status loadData()
{
  int success;
  success = restore_object(getSavePath());
  loaded = 1;
  return success;
}


void set_emote_name(string x)          { emoteName = x; }
void set_my_msg_undirected(string x)   { myMsgU    = x; }
void set_my_msg_directed(string x)     { myMsgD    = x; }
void set_room_msg_undirected(string x) { roomMsgU  = x; }
void set_room_msg_directed(string x)   { roomMsgD  = x; }
void set_tell_msg(string x)            { tellMsg   = x; }
void set_far_msg(string x)             { farMsg    = x; }
void set_owner(string x)               { owner     = x; }


string replace_key(
string word,
string srcKey,
string trgKey,
string srcPos,
string trgPos,
string srcObj,
string trgObj)
{
  /* taken from Vertebraker's color helpers */
  string z;
  if (!word) return word;
  switch(word)
  {
    case "SRC":     z = srcKey; break;
    case "TRG":     z = trgKey; break;
    case "SRCPOS":  z = srcPos; break;
    case "TRGPOS":  z = trgPos; break;
    case "SRCOBJ":  z = srcObj; break;
    case "TRGOBJ":  z = trgObj; break;
  }
  if (!z) return word;
  return z;
}


string filterMsg(
string str, 
string srcKey, 
string trgKey, 
string srcPos, 
string trgPos,
string srcObj,
string trgObj)
{
  string filt;
  int s;
  string *words;

  if (!str) return 0;

  filt = (string)call_other(VERTE_COLOR, "filter_msg", str);

  s = sizeof(words = explode(filt, "%"));
  while(s--)
    if (replace_key(words[s], srcKey, trgKey, srcPos, trgPos, srcObj, trgObj))
      words[s] = replace_key(words[s], srcKey, trgKey, srcPos, trgPos, srcObj, trgObj);
  filt = (implode(words, ""));

  return filt;
}


status main(string str)
{
  object ob;
  string filteredStr, srcName, trgName, srcPos, trgPos, srcObj, trgObj;
  int i;

  if (!loaded)
  {
    if (!loadData())
    {
      write("Emote load error.\n");
      return 1;
    }
  }

  srcName = capitalize((string)TP->query_real_name());
  trgName = str;
  if (trgName) trgName = capitalize(trgName);
  srcPos  = (string)TP->query_possessive();
  srcObj  = (string)TP->query_objective();
  trgPos  = 0;
  trgObj  = 0;

  if (!str)
  {
    if (!myMsgU || !roomMsgU)
    {
      write("This emote is incomplete.\n");
      return 1;
    }
    write(filterMsg(myMsgU, srcName, trgName, srcPos, trgPos, srcObj, trgObj)+"\n");
    say(filterMsg(roomMsgU, srcName, trgName, srcPos, trgPos, srcObj, trgObj)+"\n");
    return 1;
  }

  ob = find_player(str);
  if (!ob)
  {
    write(capitalize(str)+" is not online.\n");
    return 1;
  }

  if ( ((int)ob->query_level() >= 21 && !(IPOB && IPOB->guild_wiz())) ||
       ((string)ob->query_real_name() == "boltar") )
  {
    write("You cannot use custom guild emotes on this wizard.\n");
    return 1;
  }

  trgPos = (string)ob->query_possessive();
  trgObj = (string)ob->query_objective();

  if (myMsgD)
    write(filterMsg(myMsgD, srcName, trgName, srcPos, trgPos, srcObj, trgObj)+"\n");
  else
    write(filterMsg(myMsgU, srcName, trgName, srcPos, trgPos, srcObj, trgObj)+"\n");

  if (!tellMsg)
  {
    return 1;
  }

  if (present(ob, environment(TP)) || !farMsg)
    tell_object(ob, filterMsg(tellMsg, srcName, trgName, srcPos, trgPos, srcObj, trgObj)+"\n");
  else
    tell_object(ob, filterMsg(farMsg, srcName, trgName, srcPos, trgPos, srcObj, trgObj)+"\n");

  if (present(ob, environment(TP)))
  {
    string roomMsg, invName;
    object *room;
    object inv;
    /* let others in the room see the emote */
    if (roomMsgD)
      roomMsg = filterMsg(roomMsgD, srcName, trgName, srcPos, trgPos, srcObj, trgObj);
    else
      roomMsg = filterMsg(roomMsgU, srcName, trgName, srcPos, trgPos, srcObj, trgObj);
    room = all_inventory(environment(TP));
    for (i=0; i < sizeof(room); i++)
    {
      inv = room[i];
      if (inv->is_player())
      {
        invName = capitalize((string)inv->query_real_name());
        if (invName != srcName && invName != trgName)
        {
          tell_object(room[i], roomMsg+"\n");
        }
      }
    }
  }

  return 1;
}

