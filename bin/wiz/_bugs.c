#define REP "/obj/user/reports/report_tool"

int cmd_bugs(string str)
{
  object rep;
  if((int)this_player()->query_level() < 100) {
    return 0;
  }
  if(rep = present("report_tool", this_player())) {
    return (int)rep->start_report("bug");
  }
  if((rep = find_object(REP)) && environment(rep) && 
     environment(rep)->is_player()) {
    write((string)environment(rep)->query_real_name()+
      " already has the reporter.\n");
    return 1;
  }
  call_other(REP, "???");
  rep = find_object(REP);

  move_object(rep, this_player());
  rep->start_report("bug");
  return 1;
}
