/*
 *
 */
 
inherit "/room/room";

#define CANCEL_TIME          10

#define BUY_ERR_NOARGS       "What would you like to buy?\n"
#define BUY_ERR_NOITEM(str)  "Sorry, "+str+" is not sold here!\n"
#define BUY_ERR_COST(str,x)  "Sorry, "+str+" costs "+x+" coins!\n"
#define BUY_ERR_WEIGHT(str)  "Sorry, you can't carry "+str+"!\n"
#define BUY_ERR_NOMO(str)    "Sorry, there aren't any more items named "+str+" in "+short_desc+".\n"

#define BUY_MSG(str,x)       "You bought "+str+" for "+x+" coins.\n"
#define BUY_ROOM_MSG(str)    " buys "+str+".\n"

#define ERR_NOVALUE(str)     "Sorry, "+str+" has no value!\n"

#define SELL_ERR_NOARGS      "What would you like to sell?\n"
#define SELL_ERR_NOITEM(str) "Sorry, "+str+" is not here!\n"
#define SELL_ERR_NODROP(str) "Sorry, "+str+" may not be sold!\n"

#define SELL_MSG(str,x)      "You sold "+str+" for "+x+" coins.\n"
#define SELL_ROOM_MSG(str)   " sells "+str+".\n"
#define SELL_MSG_VALUABLE    short_desc+" is low on money...\n"
#define SELL_VALUABLE_DESTROY_MSG(str) str+" is too valuable.\nIt is hidden away...\n"

#define BUSY_MSG(play)   "Sorry, "+(string)play->query_name()+" is currently doing business here.\nPlease wait your turn.\n"
#define PROMPT(obj)      "Did you mean "+(string)obj->short()+"? <y/n/q>: "

#define VALUE_MARKUP         11 / 5

static mapping  objQty;
static mapping  objValues;
static mapping  objFiles;
static object   stock_room;
static string  *shorts;
static object   promptee;
static object   promptObj;
static string   promptStr;

void reset(status x)
{
  if(x) return;
  
  stock_room = clone_object("/room/room");
  stock_room->set_no_clean(1);
  
  shorts    = ({ });
  objQty    = ([ ]);
  objValues = ([ ]);
  objFiles  = ([ ]);
}

void init()
{
  add_action("cmd_buy",   "buy");
  add_action("cmd_sell",  "sell");
  add_action("cmd_value", "value");
  add_action("cmd_list",  "list");
}

int cmd_buy(string str)
{
  object obj;
  
  if(!str)
    write(BUY_ERR_NOARGS);
 
  else if(promptee)
    write(BUSY_MSG(promptee));
    
  else if(!(obj=present(str, stock_room)))
    write(BUY_ERR_NOITEM(str));
 
  else
    this_object()->load_confirm(this_player(), obj, str, "buy");
  
  return 1;
}

void load_confirm(object play, object obj, string str, string action)
{
  promptee  = this_player();
  promptObj = obj;
  promptStr = str;
  
  write(PROMPT(obj));
  
  input_to((action=="buy")?"confirm_buy":"confirm_sell");
 
  call_out("cancel_prompt", CANCEL_TIME);
}

void clear_prompts()
{
  promptee  = 0;
  promptObj = 0;
  promptStr = 0;
}

void cancel_prompt()
{
  if(promptee)
    tell_object(promptee, "\nTransaction cancelled.\n");
  clear_prompts();
}

void purge_null_shorts(string sh)
{
  int i;
  if((i = member_array(sh, shorts)) > -1 && (--objQty[sh] <= 0))
  {
    objQty    = m_delete(objQty,    sh);
    objFiles  = m_delete(objFiles,  sh);
    objValues = m_delete(objValues, sh);
    shorts   -= ({ shorts[i] });
    shorts    = sort_array(shorts, "greater_fun", this_object());   
  }
}

int confirm_buy(string str)
{
  object obj;

  obj = promptObj;
    
  if(str == "y")
  {
    int value;
    string sh;
    
    if(!obj->query_value(2))
      value = (int)obj->query_value();
    
    sh = (string)obj->short();
    
    if(!value)
    {
      write(ERR_NOVALUE(sh));
      move_object(obj, "/room/void");
      destruct(obj);
    }
      
    else
    {
      value *= VALUE_MARKUP;
      
      if((int)this_player()->query_money() < value)
       write(BUY_ERR_COST(sh,value));

      if(!this_player()->add_weight((int)obj->query_weight()))
        write(BUY_ERR_WEIGHT(sh));
        
      this_player()->add_money(-value);

      purge_null_shorts(sh);
    
      move_object(obj, this_player());
  
      sh = (string)obj->short();
  
      write(BUY_MSG(sh, value));
      
      say((string)this_player()->query_name() + " "+BUY_ROOM_MSG(sh));
    }
  }
  else if(str == "n")
  {
    object ocj;
    
    obj = next_inventory(obj);
    while(obj)
    {
      ocj = next_inventory(obj);
      if(obj->id(promptStr))
      {
        load_confirm(this_player(), obj, promptStr, "buy");
        return 1;
      }
      obj = ocj;
    }
    write(BUY_ERR_NOMO(promptStr));
  }
  
  else if(str == "q")
    cancel_prompt();
    
  return 1;
} 

int greater_fun(string x, string y)
{
  return (x > y);
}

int cmd_sell(string str)
{
  object obj;
  int    value, do_destroy;
  string sh;
  
  if(!str)
    return (write(SELL_ERR_NOARGS), 1);
  
  else if(!(obj = present(str, this_player())) &&
     !(obj = present(str, this_object())))
    return (write(SELL_ERR_NOITEM(str)), 1);
  
  else
  {
    if(!(value = (int)obj->query_value(1)))
      value = (int)obj->query_value();
  
    sh = (string)obj->short();
    
    if(!value)
      return (write(ERR_NOVALUE(sh)), 1);
  
    else if(environment(obj) == this_player())
    {
      if(!obj->drop())
        return (write(SELL_ERR_NODROP(sh)), 1);
      
      this_player()->add_weight(-((int)obj->query_weight()));
      sh = (string)obj->short();
    }

    if(value > 600000 || obj->query_dest_flag())
      do_destroy = 1;
  
    if(value > 1000)
    {
      write(SELL_MSG_VALUABLE);
    
      if(value < 1500)
        value = 1000;
      else
        value = 1000 + random(501);
    }
  
    write(SELL_MSG(sh,value));
    say((string)this_player()->query_name()+" "+SELL_ROOM_MSG(sh));
  
    this_player()->add_money(value);
    add_worth(value, obj);
  
    if(!(sh = (string)obj->short()))
      return (destruct(obj), 1);
  
    if(do_destroy)
    {
      write(SELL_VALUABLE_DESTROY_MSG(sh));
      return (destruct(obj), 1);
    }
  
    if(member_array(sh, shorts) == -1)
     shorts += ({ sh });
    
    shorts = sort_array(shorts, "greater_fun", this_object());
  
    objQty[sh] ++;
    objValues[sh] = value;
    objFiles[sh]  = basename(obj);
  }
  return 1;
}

int cmd_list(string str)
{
  int i, j;
  /* need to add "list weapons", etc. */
  j = sizeof(shorts);
  for(i = 0; i < j; i ++)
    write(shorts[i]+" "+objQty[shorts[i]]+" "+objValues[shorts[i]]+"\n");
  return 1;
}