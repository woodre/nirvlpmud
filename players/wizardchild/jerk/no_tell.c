id(str) { return str == "no_tell"; }
init() { add_action("no_tell","tell"); }
drop() { return 1; }
no_tell(str) {
  string s1,s2; if(!str || sscanf(str, "%s %s", s1, s2) < 2) return 0;
  if(lower_case(s1) != "jezebel") return 0;
  write("You have lost this ability because you are not mature enough to handle it.\n");
  return 1;
}
query_auto_load() { return "/players/wizardchild/jerk/no_tell:";
}
