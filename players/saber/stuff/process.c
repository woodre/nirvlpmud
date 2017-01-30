#define tp this_player()->query_name()
inherit "obj/treasure";
string da_type;
reset(arg)
{   if (arg) return;
   da_type="heal";
   set_id("processor");
   set_alias("rod");
   set_short("A rod of corpse processing");
   set_long("A magical rod of corpse processing.\n"+
    "To use type <process> and the corpse will be processed.\n"+
    "To change the type of healing, type <toggle_rod> to select\n"+
    "a certain type of healing.\n"+
   "This process drains the essence from the corpse.\n");
   set_weight(1);
   set_value(250);
}
init()
{
  add_action("process_corpse", "process");
  add_action("toggle_rod", "toggle_rod");
}


process_corpse()  {
  string da_func;
object corpse;
int heal;
heal = 0;
corpse = present("corpse",environment(this_player()));
if(!corpse)  {
 corpse = present("corpse",this_player());
   }
if(!corpse)  {
  write("There is no corpse here to process.\n");
  return 1;
   }
if(this_player()->query_guild_name() == "healer") {
  write("As a healer you have nothing to do with corpses.\n");
return 1; }
heal=corpse->heal_value();
  if(da_type=="SP") { heal *= 2; da_func = "add_sp"; }
  else if(da_type=="HP") { heal *= 2; da_func = "add_hp"; }
  else da_func = "heal_self";
  call_other(this_player(),da_func, heal);
write("You drain the essence of the corpse into your body.\n"+
  "You feel stronger.\n");
say(tp+" touches the corpse with a strange rod.\n"+
   tp+" looks stronger.\n");
  this_player()->print_monitor();
   destruct(corpse);
    return 1;   }

toggle_rod(string str)
{
  if(str) {
    if(str=="HP" || str == "hp") {
      write(short()+" set to healing HPs.\n");
      da_type="HP";
    }
    else if(str=="SP" || str=="sp") {
      write(short()+" set to healing SPs.\n");
      da_type="SP";
    }
    else if(str=="heal" || str == "both" || str == "BOTH") {
     write(short()+" set to healing BOTH HPs AND SPs.\n");
     da_type="BOTH";
    }
    else {
    write("Settings: 'toggle_rod <hp/sp/both>'\n");
    return 1;
  }
  }
  else {
    write("Settings: 'toggle_rod <hp/sp/both>'\n");
  return 1;
  }
  return 1;
}
