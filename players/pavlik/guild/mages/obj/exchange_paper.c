#define XP 0
#define TS 1
#define guild present("mageobj", this_player())

string owner;
int amount, ex_type;
string book1, book2, book3;

reset(arg){
 if(arg)
   return;
 owner = "Noone";
 select_titles();
}
id(str){
  return str == "paper" || str == "exchange_paper";
}

short(){ return "A piece of paper"; }

long(){
  write("The small paper reads: \n"+
  "To aquire the knowledge you seek, you must do some research.  Here\n"+
  "are some texts that will guide you...\n"+
  "The is a small list of books listed here with titles such as:\n"+
  "  "+book1+"\n"+
  "  "+book2+"\n"+
  "  "+book3+"\n"+
  "Amount:     " +amount + "\n" +
  "Type 'research texts' to finsh your exchange.\n");
  return;
}

drop(){ return 1; }
get(){ return 1; }

set_amount(str){
  amount = str;
  if( ex_type != XP && ex_type != TS )
    set_type(XP);
  owner = environment(this_object())->query_real_name();
  return 1;
}

set_type(str) {
  ex_type = str;
  if( ex_type != XP && ex_type != TS )
    ex_type = XP;
  return 1;
}
init(){
  add_action("read","read");
  add_action("research_texts","research");
}

read(str){
  if(str == "paper"){
    command("look at paper", this_player());
    return 1;
    }
}

research_texts(str){
  object obj;
  string where;

  if(str == "texts"){
  if(this_player()->query_real_name() != owner){
    write("This is just meaningless jibberish to you.\n");
    obj = find_player(owner);
    if(!obj)
      destruct(this_object());
    else
      move_object(this_object(), obj);
    return 1;
    }

  where = object_name(environment(this_player()));
  if(where != "players/pavlik/guild/mages/room/library"){
    write("You must be in the library to find these books.\n");
    return 1;
    }

  write(
  "You find the books listed and pull them off the shelf.\n"+
  "After carefully studying these texts you feel enlightened.\n");
  if( ex_type == XP )
    this_player()->add_guild_exp(amount);
  if( ex_type == TS && guild )
    guild->add_new_spell_chances(amount);
  destruct(this_object());
  return 1;
  }
}

select_titles(){
  book1 = "The Age of Magic";
  book2 = "101 Uses for a Dead Rabbit";
  book3 = "Theory of Metro-Magiks (unabridged)";
  return 1;
}
