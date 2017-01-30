
#define HELPDIR "/players/molasar/sunndi/help/"
#define WIZ_LVL 100 /* Min level for wizard commands */
#define SUNNDI_MASTER "/players/molasar/sunndi/sunndi_master"


void global_init();
int sunndi_align(string str);
int sunndi_help(string str);
int sunndi_player_align(string str);
void sunndi_list_players();
int id(string str);
int get();
int drop();
string short();
void long();

int id(string str) {
   return str == "rock";
}

int get() {

   if (this_player()->query_level() < WIZ_LVL) {
      write("The rock disappears just as your fingers touch its smooth surface.\n");
      destruct(this_object());
      return 0;
   }

   return 1;

}

int drop() {

   write("As soon as the rock falls from your grasp it disappears in a flash of light.\n");
   destruct(this_object());
   return 1;

}

string short() {
   return "A small, round smooth rock";
}

void long() {

   if (this_player()->query_level() < WIZ_LVL) {
      write("A small, round smooth rock.\n");
      return;
   }

   write("\n");
   write("Sunndi Control Object\n");
   write("=======================================================================\n");
   write("salign <align>              Set or view the current Sunndi alignment\n");
   write("spalign <player> [align]    Set or view a player's Sunndi alignment\n");
   write("=======================================================================\n");
   write("\n");

}

void init() {

   if (this_player() && this_player()->query_level() < WIZ_LVL) 
      return;

   add_action("sunndi_align", "salign");
   add_action("sunndi_player_align", "spalign");

}

int sunndi_align(string str) {
   int alignment;

   if (!str || !sscanf(str, "%d", alignment)) {
      alignment = (int)call_other(SUNNDI_MASTER, "query_alignment", 0); 
   } else {
      call_other(SUNNDI_MASTER, "set_alignment", alignment);                           
      alignment = (int)call_other(SUNNDI_MASTER, "query_alignment", 0); 
   }

   write("Sunndi Alignment: " + alignment + "\n");
   return 1;
}

int sunndi_player_align(string str) {
   string player;
   int alignment;

   if (!str) {
      write("Usage: spalign <player> [alignment]\n");
   } else if (sscanf(str, "%s %d", player, alignment)) {
      call_other(SUNNDI_MASTER, "set_player_alignment", player, alignment); 
      alignment = (int)call_other(SUNNDI_MASTER, "query_player_alignment", player); 
      write("Sunndi Alignment for " + player + ": " + alignment + "\n");
   } else if (sscanf(str, "%s", player)) {
      alignment = (int)call_other(SUNNDI_MASTER, "query_player_alignment", player); 
      write("Sunndi Alignment for " + player + ": " + alignment + "\n");
   }

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



