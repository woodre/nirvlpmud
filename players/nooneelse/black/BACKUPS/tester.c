inherit "/obj/treasure";
string officers_list, levels_list, office_list;
int nbr_of_lieutenants;

init() {
  ::init();
  add_action("lookup_officer", "lookup");
}

reset(arg) {
  if (arg) return 0;
  set_id("tester");
  set_short("officer tester");
  set_long("officer tester\n");
  set_value(0);
  set_weight(1);
  officers_list = allocate(11);
  levels_list = allocate(11);
  office_list = allocate(11);
  load_officers_list();

}

lookup_officer(str) {
   write("return from find_officer '"+find_officer(str)+"'\n");
   if (find_officer(str)=="Lieutenant")
      write("it matches\n");
   else
      write("it doesn't match\n");
   return 1;
}

/* this is called from other objects to find out if someone is an officer */
find_officer(str) {
  int i, found_officer, level;
  found_officer = 0;
  level = 0;
  for (i=1; i<10; i++) {
    if (str==officers_list[i]) {
      found_officer = 1;
      level=i;
    }
  }
  return levels_list[level];
}


load_officers_list() {
  officers_list[0] = "vacant";
  levels_list[0] = "dummy office";
  office_list[0] = "dummy office";
  officers_list[1] = "nooneelse";
  levels_list[1] = "Master";
  office_list[1] = "GUILD_OFFICE_TN";
  officers_list[2] = "nancy";
  levels_list[2] = "Assistant";
  office_list[2] = "GUILD_OFFICE_TS";
  officers_list[3] = "saber";
  levels_list[3] = "Lieutenant";
  office_list[3] = "GUILD_OFFICE_2N";
  officers_list[4] = "sado";
  levels_list[4] = "Lieutenant";
  office_list[4] = "GUILD_OFFICE_2E";
  officers_list[5] = "maddog";
  levels_list[5] = "Lieutenant";
  office_list[5] = "GUILD_OFFICE_2S";
  officers_list[6] = "draven";
  levels_list[6] = "Lieutenant";
  office_list[6] = "GUILD_OFFICE_2W";
  officers_list[7] = "wamphyri";
  levels_list[7] = "Lieutenant";
  office_list[7] = "GUILD_OFFICE_1N";
  officers_list[8] = "magus";
  levels_list[8] = "Lieutenant";
  office_list[8] = "GUILD_OFFICE_1E";
  officers_list[9] = "vacant";
  levels_list[9] = "Lieutenant";
  office_list[9] = "GUILD_OFFICE_TN";
  officers_list[10] = "vacant";
  levels_list[10] = "Lieutenant";
  office_list[10] = "GUILD_OFFICE_1W";

}
