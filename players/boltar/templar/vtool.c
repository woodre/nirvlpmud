/* 
 * templar tool
 * for Jara/Larisa (c) verte
 * log viewin' purposes; go T 
 */

id(str) {
    return (str == "templar_tool" || str == "tool" || str == "templar tool" || str == "log tool");
}

short() {
    if(this_player() == environment())
      return "Templar Tool";
}

init() {
    object x;
    if((x = this_player()) && ( ((int)x->query_level() < 40) && (string)x->query_real_name() != "jara" &&
                                (string)x->query_real_name() != "larisa"))
      return destruct(this_object());
    else
    {
      add_action("cmd_ally",    "ally_log");
      add_action("good_kill", "good_kill");
      add_action("veto_log", "veto_log");
      add_action("cmd_sponsor", "sponsor_log");
      add_action("cmd_awards",  "award_log");
      add_action("cmd_pardon",  "pardon_log");
      add_action("cmd_record",  "record_log");
    }
}

cmd_ally(str)
{
    if(str) return 0;

    write("Refreshing log... ");
    rm("/open/jara/Templar/ally");
    cp("/players/boltar/templar/log/Ally", "/open/jara/Templar/ally");
    write("Okay.\n");
    return 1;
}

cmd_sponsor(str)
{
    if(str) return 0;

    write("Refreshing log... ");
    rm("/open/jara/Templar/sponsor");
    cp("/players/boltar/templar/SPONSOR", "/open/jara/Templar/sponsor");
    write("Okay.\n");
    return 1;
}

cmd_awards(str)
{
    if(str) return 0;

    write("Refreshing log... ");
    rm("/open/jara/Templar/awards");
    cp("/players/boltar/templar/log/awards", "/open/jara/Templar/awards");
    write("Okay.\n");
    return 1;
}

cmd_pardon(str)
{
    if(str) return 0;
    write("Refreshing log... ");
    rm("/open/jara/Templar/pardon");
    cp("/players/boltar/templar/log/pardon", "/open/jara/Templar/pardon");
    write("Okay.\n");
    return 1;
}

cmd_record(str)
{
    if(str) return 0;
    write("Refreshing log... ");
    rm("/open/jara/Templar/record");
    cp("/players/boltar/templar/log/record", "/open/jara/Templar/record");
    write("Okay.\n");
    return 1;
}

long()
{
    write("\
Sweet! This is the Templar Tool that Verte wrote for Jara.\n\
It generates log files used for the Knights Templar website.\n\n\
  *Commands:\n\
\tally_log, sponsor_log, award_log, pardon_log, record_log,\n\
\tgood_kill, veto_log.\n\n");
}

drop() { return 1; }
get() { return 1; }

query_auto_load() { return "/players/boltar/templar/vtool:"; }

good_kill(str)
{
    if(str) return 0;
    write("Refreshing log... ");
    rm("/open/jara/Templar/goodkill");
    cp("/players/boltar/templar/log/good_kill", "/open/jara/Templar/goodkill");
    write("Okay.\n");
    return 1;
}

veto_log(str)
{
    if(str) return 0;
    write("Refreshing log... ");
    rm("/open/jara/Templar/veto");
    cp("/players/boltar/templar/VETO", "/open/jara/Templar/veto");
    write("Okay.\n");
    return 1;
}
