#include <grammar.h>   // for parser macros
#include <message.h>   // for message macros

inherit "basic/list";    // make_list for listing colour-array
inherit "basic/parser";  // add_rule
inherit "basic/message"; // message
inherit "complex/item";  // standard object

string *colors;

void create() {
  if (!clonep())
    return;   // stop possible calls in the blueprint
  ::create();
  colors=({"white","blue","red","green","yellow","pink","indigo","violet",
           "lilac","orange","brown","black","grey","purple","magenta",
           "periwinkle","cornflower","midnight blue","cerulean","teal blue",
           "blue green","turquoise blue","blue violet","dandelion",
           "jungle green","spring green","green yellow","yellow green",
           "sea green","pine green","olive green","bittersweet","mahogany",
           "burnt sienna","peach","melon","apricot","vivid tangerine",
           "red orange","yellow orange","salmon","brick red","red violet",
           "carnation pink","violet red","maroon","fuchsia","orchid","thistle",
           "gold","silver" });
  set_short("a brush");
  set_long("This is really a nice looking brush. You can paint someone\n"
   "with it in several colours. It looks well used for body-painting.\n"
   "Commands are 'show colours' and 'paint <whom> with <colour>'.\n");
  set_name("brush");
  set_encumbrance(1000);
  set_value(10);

  add_rule("paint <living> with <text>","paint");  // set action for paint
  add_rule("show <text>","show"); // set_action for show
  add_error_message("paint","paint whom with which colour?\n"); // paint failed?
/* show is a standard soul command, so we don't need an error message */
}

void init() {
  add_actions(); // without this call nothing will work
}

status do_action(string verb, mapping args) {
  object farbe;
  string str1,str2;

  if (verb=="paint" && member_array(args[G_TEXT],colors)>=0) {
    message(({({ M_PLAYER," ",M_PL_VERB,"paint"," ",args[G_LIVING]," with ",
                 args[G_TEXT]+" colours."})}));
    if (farbe=present_clone("players/thekara/items/farbe",args[G_LIVING])) {
      if (sscanf(farbe->query_color(),"%s"+args[G_TEXT]+"%s",str1,str2) ||
          strlen(farbe->query_color())>35) {
        message(({({ "It seems, that ",args[G_LIVING]," got too much coloured." })}));
	return 1;
      }
      farbe->set_color(farbe->query_color()+"-"+args[G_TEXT]);
      if (sscanf(farbe->query_painter(),"%s"+this_player()->query_vis_name()+"%s",str1,str2)
	  || strlen(farbe->query_painter())>35) return 1;
      farbe->set_painter(farbe->query_painter()+"/"+this_player()->query_vis_name());
      return 1;
    }
    farbe=clone_object("players/thekara/items/farbe");
    farbe->set_color(args[G_TEXT]);
    farbe->set_painter(this_player()->query_vis_name());
    move_object(farbe,args[G_LIVING]);
    return 1;
  }
  if (verb=="show" && args[G_TEXT]=="colours") {
    message(({({ M_WRITE,"There are the following colours possible: ",
                 make_list(colors),"." })}));
    return 1;
  }
  return ::do_action(verb,args);
}

