#include "../defs.h"

static string *armor_types;
static string *blocked_names;
static string *blocked_files;

void reset(int arg){
  if(arg) return;
  
  armor_types = ({ "armor", "shield", "helmet",
                   "boots", "ring", "amulet",
                   "misc" });
}

int main(string str){
  object obj, sh;
  string what, nm;
  if(!str || sscanf(str, "%s %s", what, nm) < 2){
    write("\
You must choose a weapon/armor to dub and the name\n\
you choose for it.\n\
For example, 'dub sword Godslayer'.\n"); 
    return 1;
  }
  if(!(obj = present(what, this_player()))){
    write("You do not have \""+what+"\".\n");
    return 1;
  }
  if(!obj->is_armor() && !obj->is_weapon()){
    write((string)obj->short()+" is neither an armor, nor a weapon.\n");
    return 1;
  }
  if(obj->is_armor() &&
    member_array((string)obj->query_type(), armor_types) == -1){
    write((string)obj->short()+" is not a \"normal\" armor.\n"+
          "It may not be dubbed.\n");
    return 1;
  }
  if(obj->query_wielded()){
    write((string)obj->short()+" must be unwielded to be dubbed.\n");
    return 1;
  }
  if(obj->query_worn()){
    write((string)obj->short()+" must be removed to be dubbed.\n");
    return 1;
  }
  if(obj->query_knight_named()){
    write((string)obj->short()+" already has a name.\n");
    return 1;
  }
  write("\n\
You place the "+(string)obj->query_name()+" on the ground.\n");
  say((string)this_player()->query_name()+" places "+
   (string)obj->query_name()+" on the ground.\n");
  
  write("You whisper a few words, rubbing the "+
   (string)obj->query_name()+" gently.\n");
  say((string)this_player()->query_name()+" whispers "+
  "a few words, rubbing the "+(string)obj->query_name()
  +" gently.\n");
  
  tell_room(environment(this_player()),
    (string)obj->short()+" "+HIY+"FLASHES"+NORM+"!\n");
  
  if(obj->is_weapon()) {
    obj->set_wep_light(1);
  }
  else {
    obj->set_arm_light(1);
  }
  nm = capitalize(nm);
  obj->add_enchantment("knight dub",
    "named \""+nm+"\"",
    "\nIt has been named \""+nm+"\".\n",
    1,
    "physical",
    10000000,
    10000000,
    "do_special",
    this_object());
  
  obj->SetMultipleIds((string*)obj->QueryMultipleIds() + ({lower_case(nm)}));
  write("You take the "+(string)obj->query_name()+" from the ground.\n");
  say((string)this_player()->query_name()+" picks up "+
   (string)obj->query_name()+" from the ground.\n");
   
  return 1;
}

int do_special(string str){
 if(!random(10))
  tell_room(environment(environment(previous_object())),
    previous_object()->short()+" "+HIY+"FLASHES"+NORM+"!\n");
  return 1;
}
