#define tp this_player()
#define tpname this_player()->query_real_name()
#define throwout_room "/room/church"
#defint owner "pathfinder"
 
inherit "room/room";
 
int shields;
 
 
reset(arg) {
if(!arg) {
  set_light(1);
     short_desc = "Pathfinder Retreat";
     long_desc = "You notice an organized mess as you enter Pathfinder's\n"+
                 "Workroom, he has piles of papers laying everywhere,\n"+
                 "serving some purpose unknown to you.\n";
  dest_dir = ( {
                "room/church",       "church",
                "room/post",         "post",
} );
  items = ({
  "workroom","It hasn't been crafted into much yet, but its getting done...",
} );
}
 
 
init() {
 
  object me;
 
  ::init();
    add_action("wizzes",            "wizzes");
    add_action("trans",             "trans");
    add_action("Shout_invis",       "Shout");
    add_action("force",             "force");
    add_action("toggle_shield",     "shields");
    if(shields)
      if (tpname != owner)
      {
      write("You tug and tug but the door is too well sealed for you\n"+
            "to open.  Its best to try back at a later time.\n");
      move_object(tp,throwout_room);
      if(me=find_player(ownder))
         tell_object(me,capitalize(tpname)+" tried to break in.\n");
}
}
 
wizzes() {
  object list;
  int i, level, invis;
  string name, ed, tab;
  list = users();
  write("Name"+"\t\t"+"Level"+"\t"+"Invis"+"\t"+"Edit\n");
  write("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n
");
  for(i = 0; i <sizeof(list); i++)
{
  name = capitalize(call_other(list[i],"query_real_name"));
  level = list[i]->query_level();
  invis = list[i]->query_invis();
  if(invis>999){invis=999;
}
  ed = "  ";
  if(in_editor(list[i]))
    {
       ed = "Ed";
    }
  tab = "\t";
  if(strlen(name) < 8){tab = "\t\t";
}
  if(level > 19)
    {
write(name+tab+level+"\t"+invis+"\t"+ed+"\n");
    }
}
    return 1;
}
 
trans(str) {
  object ob;
  string bye, there;
    if(!str)
return 0;
  ob=find_player(str);
  if(!ob) ob=find_living(str);
  if(!ob) {
write (capitalize(str) + " isn't logged on you dimwit.\n");
return 1;
        }
  there=environment(ob);
  tell_object(ob,"You have been summoned by a greater force!\n");
  move_object(ob, environment(this_player()));
  write(capitalize(str)+" has arrived from your summoning.\n");
  return 1;
}
 
force(str) {
  object whoo;
  string who,what;
  if (!str) return;
  if (sscanf(str, "%s %s", who, what) !=2)
    return;
  whoo = find_player(who);
  if (!whoo)
    {
      write("Can't find "+who+"\n");
      return;
    }
  command(what,whoo);
  return 1;
 
 
Shout_invis(str) {
if(!str) {
  write("Usage: Shout <str>\n");
  return 1;
}
     shout("Someone shouts: "+str+".\n");
     write("You just shouted: "+str+".\n");
     return 1;
}
 
toggle_shield(str) {
  if (str == "on") shields = 1;
  else if (str == "off") shields = 0;
  else if (str == "stat")
    if (shields) write ("The shields are up.\n");
    else write("The shields are down.\n");
    else write("The syntax is: shields <on|off|stat>\n");
  return 1;
}
