/*
 t_shirt.c
*/

inherit "obj/armor";

string str;
int test_ac;
object tuxedo, item_obj;

int new_ac;

reset(arg) {
  ::reset(arg);

  set_name("t-shirt");
  set_alias("shirt");
  set_short("A t-shirt for the Vamps.\n\n"+
            "                 **  | |  **\n"+
            "               ***   ***   ***\n"+
            "              *****************\n"+
            "              ** **  ***  ** **\n"+
            "              **   *  *  *   **\n"+
            "               *             *\n"+
            "\n\n");
  set_value(25);
  set_weight(1);
  set_ac(1);
  set_type("misc");
}
