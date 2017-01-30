#define REP "/players/forbin/closed/neo/obj/report_tool"

int main(string str, object gob, object player)
{
  object rep;
  if((int)this_player()->query_level() < 100) {
    return 0;
  }
  if(rep = present("report_tool", this_player())) {
    return (int)rep->start_report("idea");
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
  rep->start_report("idea");
  return 1;
}
