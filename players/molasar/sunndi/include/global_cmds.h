
#define HELPDIR "/players/molasar/sunndi/help/"
#define WIZ_CMDS 100 /* Min level for wizard commands */

void global_init();
int sunndi_help(string str);
int sunndi_admin();

void global_init() {

   /* Player commands */
   add_action("sunndi_help", "shelp");

   /* Wizard commands */
   if (this_player() && this_player()->query_level() >= WIZ_CMDS) {
      add_action("sunndi_admin", "sadmin");
   }

}

int sunndi_admin() {
   object ob;

   ob = clone_object("/players/molasar/sunndi/closed/rock.c");
   move_object(ob, this_player());

   write("A rock materializes in your hand.\n");
   return 1;
}

int sunndi_help(string str) {
   string helpfile;

   if (!str || !sscanf(str, "%s", helpfile)) {
      cat(HELPDIR + "help.txt");
   } else {
      write("No such file");
   }

   return 1;
}
  
void sunndi_list_players() {

}



