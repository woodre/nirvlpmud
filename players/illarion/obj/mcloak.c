/* An object to make other objects for show.
   The inspiration came from Saber's chaos code for the Bards.
 */
inherit "players/illarion/obj/clothes";
#include "/players/illarion/dfns.h"
#define GETCOLOR(x) call_other("/players/illarion/obj/addcolor","addcolor",x);

mapping chaos;

void reset_strand();

reset(arg) {
  if(arg) return;
  if(!chaos) {
    chaos=([]);
    reset_strand();
  }
  set_id("cloak");
  set_short("A Maker's cloak");
  set_long("This cloak seems to shimmer from one color to all colors to\n"+
           "no color at all, defying any attempt to define its looks at\n"+
           "all.  It is a symbol of the power to "+BLD("Make")+" things\n"+
           "from chaos.\n");
  set_weight(1);
  set_value(0);
}
drop(int s) {
  if(s) write("You may not drop this.\n");
  return 1;
}
void init() {
  ::init();
  add_action("cmd_Make","Make");
}
reset_strand() {
chaos = (["name":"thing","alias":0,"read":0,"short":"A thing of chaos",
  "long":"Things of chaos have no form.","weight":0, "light":0,
  "wear":"no","comm":0,"comm_play":0,"comm_room":0 ]);
}
colorscan(string str) {
  return GETCOLOR(str);
}
cmd_Make(string str) {
  string option,arg;
  int tmp;
  object ob;
  string *valid_options;
  valid_options=
    ({"name","alias","read","short","long","weight","light","wear",
      "comm","comm_room","comm_play"});
  if(!str) {
    write("This command can be used to create an object. The syntax is:\n");
    write("Make <option> [argument]");
    write("The possible options are as follows:\n");
    write("name [name]      --  set the object's id\n");
    write("alias [alias]    --  set an alternate id\n");
    write("short [short]    --  set the object's short.\n");
    write("long [long]      --  set the alternate's long desc\n");
    write("read [read]      --  set a string to 'read' from the object.\n");
    write("weight [#weight] --  how heavy (or light) the object is\n");
    write("light [#light]   --  how light (or dark) the object is\n");
    write("wear [yes/no]    --  make the object wearable (but not armor)\n");
    write("comm [comm]      -- set a special command for the object\n");
    write("comm_play  [str] -- set the message displayed by comm\n");
    write("comm_room  [str] -- set the message displayed to the room\n");
    write("                    if &NAME& is used, the name of the person\n");
    write("                    executing the command will be substituted.\n");
    write("reset            --  object reverts to base values\n");
    write("display           --  show the object's entire status\n");
    write("create           --  spins the object out (unsavable)\n");
    write("No argument will show the current value.\n");
    return 1;
  }
  if(sscanf(str,"%s %s",option,arg)==2) switch(option) {
    case "name": case "alias": case "short": case "long": case "read":
    case "wear": case "comm": case "comm_play": case "comm_room":
      chaos[option]=(option=="short")?colorscan(arg):arg;
      write("You have set the object's "+option+" to:\n");
      write(chaos[option]+"\n");
      return 1;
    case "weight":
      sscanf(arg,"%d",tmp);
      chaos[option]=tmp;
      write("You have set the object's "+option+" to:\n");
      write(chaos[option]+"\n");
      return 1;
    default:
      write("That is not a valid option.\n");
      return 1;  
  }
  else switch(str) {
    case "reset":
      write("Resetting object.\n");
      reset_strand();
      return 1;
    case "display": {
      int n,size;
      size=sizeof(valid_options);
      for(n=0;n<size;n++)
        write((chaos[valid_options[n]]?valid_options[n]+
          ": "+chaos[valid_options[n]]:"No "+valid_options[n])+"\n");
      return 1; }
    case "create":
      ob=clone_object("/players/illarion/obj/chaos_base.c");
      ob->set_id(chaos["name"]);
      if(chaos["alias"]) ob->set_alias(chaos["alias"]);
      ob->set_short(chaos["short"]);
      ob->set_long(format(chaos["long"]+"\n"));
      ob->set_weight(chaos["weight"]);
      if(chaos["read"]) ob->set_read(format(chaos["read"]+"\n"));
      if(chaos["wear"]=="yes") ob->set_clothes(1);
      if(chaos["comm"]) 
        ob->set_comm(chaos["comm"],chaos["comm_play"],chaos["comm_room"]);
      ob->make_light(chaos["light"]);
      transfer(ob,this_player());
      say(TPN+" reaches THROUGH his cloak and pulls out. "+chaos["name"]+".\n");
      write("You reach through your cloak into chaos and produce "+chaos["name"]+".\n");
      return 1;
    default:
      if(member_array(str,valid_options) == -1) {
        write("That is not a valid option.\n");
        return 1;
      } else if(!chaos[str]) {
        write("You have not yet set the "+str+".\n");
        return 1;
      } else {
        write("The object's "+str+" is set to:\n");
        write(chaos[str]+"\n");
        return 1;
      }
  }
}
