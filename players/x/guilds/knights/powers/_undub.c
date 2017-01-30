#include <ansi.h>

int main(string str){
  string dubbed;
  object obj;
  mapping ench;
  if(!str){
    write("\
You must choose a weapon/armor to undub.\n");
    return 1;
  }
  if(!(obj = present(str, this_player()))){
    write("You do not have \""+str+"\".\n");
    return 1;
  }
  if(!(ench = (mapping)obj->query_enchantment("knight dub"))){
    write((string)obj->short()+" hath naught been dubbed.\n");
    return 1;
  }

  if(obj->query_worn()) {
    write((string)obj->query_name()+" must be removed first.\n");
    return 1;
  }
  if(obj->query_wielded()) {
    write((string)obj->query_name()+" must be unwielded first.\n");
    return 1;
  }
  write("\n\
You place the "+(string)obj->query_name()+" on the ground.\n");
  say((string)this_player()->query_name()+" places "+
    (string)obj->query_name()+" gently.\n");
  write("You whisper a few words, rubbing the "+
    (string)obj->query_name()+" gently.\n");
  say((string)this_player()->query_name()+" whispers "+
  "a few words, rubbing the "+(string)obj->query_name()
  +" gently.\n");

  tell_room(environment(this_player()),
    (string)obj->short()+" "+HIB+"FLASHES"+NORM+"!\n");

  dubbed = ench[0];
  sscanf(dubbed, "named \"%s\"", dubbed);
  dubbed = lower_case(dubbed);
  obj->SetMultipleIds((string*)obj->QueryMultipleIds() - ({ dubbed }));
  obj->remove_enchantment("knight dub");

  write("You take the "+(string)obj->query_name()+" from the ground.\n");
  say((string)this_player()->query_name()+" picks up "+
   (string)obj->query_name()+" from the ground.\n");

  return 1;
}
