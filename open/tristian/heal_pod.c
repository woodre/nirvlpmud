#include "../DEFS.h"
inherit "room/room";


init()
{
  ::init();
  add_action("do_nothing"); add_xverb("");
  write("Available commands: \n"+
        "  cyber/fax/help\n"+
        "  cyberware/access\n"+
        "  net/nem/onet/onem\n"+
        "  progress\n"+
        "  stop\n");
}


reset(arg)
{
  if(!arg)
  {
    set_light(1);
    short_desc=FUNKYNAME+" Heal Pod";
    long_desc=
"    You are surrounded by the liquid machines of the heal pod.\n";

    call_out("heal_players", 2);
  }
}


realm() { return "NT"; }


do_nothing(str)
{
  object convert_room;
  string mess;

  if (sscanf(str, "cyberware%s",   mess)==1) return;
  if (sscanf(str, "access%s",   mess)==1) return;
  if (sscanf(str, "fax%s",   mess)==1) return;
  if (sscanf(str, "net%s",   mess)==1) return;
  if (sscanf(str, "nem%s",   mess)==1) return;
  if (sscanf(str, "onet%s",   mess)==1) return;
  if (sscanf(str, "onem%s",   mess)==1) return;
  if (sscanf(str, "cyber%s", mess)==1) return;
  if (sscanf(str, "help%s",  mess)==1) return;

  if (lower_case(str)=="progress")
  {
    write("  HP: "+TP->query_hp()+"  SP: "+TP->query_sp()+"\n");
    return 1; 
  }

  if (lower_case(str)=="stop")
  {
    write("You mentally signal the nurse droids to release\n"+
          "you from the healing pod...\n");
    convert_room = ROOMDIR + "/convert";
    move_object(TP, convert_room);
    say(TPN+" leaves the healing pod.\n");
    call_other(TP, "glance");
    return 1; 
  }

  if(TP->query_level() >= 20) return;
  write("While you are in the healing pod you may\n"+
        "only perform thinking functions. That is, you\n"+
        "may peruse the cyber/fax/mud help files, see your\n"+
        "healing 'progress', or 'stop' healing.\n");
  return 1;
}


heal_players()
{
  object ob;
  ob = first_inventory(this_object());
  while(ob) {
    if(ob->is_player()) ob->heal_self(2);
    ob = next_inventory(ob);
  }
  call_out("heal_players", 2);
  return 1;
}

feel() { return "no"; }
