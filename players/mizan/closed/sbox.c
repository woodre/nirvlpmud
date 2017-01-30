inherit "/obj/clean";
#define MAX_WEIGTH 100000
object ob, ob2;
string what;

add_weight(w) { return 1; }
id(str)
{
  return str == "box" || str == "army_box" || str == "army box"; 
}
short() { return "A Salvation Army Box"; }
long() {
  write("This is a large greenish bin that you can dump things that you\n"+
  "don't need anymore into. It is designed for anyone, newbies can take\n"+
  "from it, as well as high-level players down on their luck. \n\n"+
  "If you don't need anything from this box please don't take from it!!\n"+
  "Be generous and understanding...\n"+
  "You can donate things by typing 'stash <object>'.\n"+
  "A command 'stash all' will allow you to put all of your things into the box.\n\n"+
  "Please mail any comments/suggestions/flames to Mizan.\n");
}

can_put_and_get() { return 1; }

reset(arg) 
{
    if(arg) return;
    set_no_clean(1);
}

init()
{
    add_action("stash","stash");
    add_action("put","put");
}

stash(str) 
{
    if(!str) return 0;
    
    if(str == "all") 
    {
        /*write_file("/players/mizan/logs/box.log", (this_player()->query_name())+" stashed all.\n");*/
        /* Added for nonsave/no value donated items.  Fred [7.28.06] */
        move_object(this_player(), this_object());
        ob = first_inventory(this_player());
        while(ob)
        {
          ob2 = next_inventory(ob);
          if(ob->is_weapon() || ob->is_armor() || ob->is_heal() || ob->is_treasure())
          {
/* Added queryKept() - Rumplemintz 17-Dec-2010 */
            if (ob->queryKept()) {
              write("You cannot donate a kept item.\n");
            } else {
            ob->set_donated_item(1);
            write("You donate: "+ob->query_short()+".\n");
            command("drop "+(string)ob->query_name()+"", this_player());
            }
          }
          ob = ob2;
        }  
        write("So kind of you to donate all of your equips... what comes around goes around :)\n");
        tell_room(environment(), this_player()->query_name()+" donates some items.\n");
        move_object(this_player(), environment(this_object()));
        return 1;
    }
    if(!(ob = present(str, this_player()))) return 0;
    move_object(this_player(), this_object());
/* Added queryKept() - Rumplemintz 17-Dec-2010 */
    if (ob->queryKept()) {
      write("You cannot donate a kept item.\n");
    } else {
    ob->set_donated_item(1);
    write("You donate: "+ob->short()+".\n");
    tell_room(environment(), this_player()->query_name()+" donates something.\n");
    command("drop "+str+"", this_player());
    move_object(this_player(), environment(this_object()));
    }
    return 1;
}

put(str)
{
  if(sscanf(str, "%s in box", what))
  {
    write("Please use the 'stash' command if you wish to donate items.\n");
    return 1;
  }
  return 0;
} 

catch_tell(str)
{
    object from;
    string a,b,c;
    object next_dest;
    string next_out;

    log_file("mizan.villagegreen", str);
    
    from = this_player();
    if(!from) return 1;
    
    if(sscanf(str, "%s gets %s from box",a,b) == 2) 
    {
        /*write_file("players/mizan/logs/box.log", (this_player()->query_name()) + " took '" + b + " ' out of the box.\n");*/
        return 1;
    }
}
