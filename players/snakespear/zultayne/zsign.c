inherit "obj/clean";
#include "/players/snakespear/closed/ansi.h"

id(str) {
  return str == "sign";
}

short() { return BOLD+"A Sign for Visitors"+NORM; }
long()  {
    write("  This is a moss covered sign made of a rare blue stone called\n"+
          "spinel.  The sign looks very heavy and one can only assume that\n"+
          "this sign was created where it stands and won't move for quite\n"+
          "some time.  There is something written on the sign and might be\n"+
          "able be read, if someone tried.\n");
}

get()  { return 0;  }

query_weight()  { return 1; }

query_value()  { return 1;  }

init() {
    add_action("read_sign", "read");
}

read_sign(str) {
     write("  This is a new fully interactive area for low to midlevel players.\n"+
           "Be warned that you will need a light source in most of Zultayne.\n"+
           "You should take the time to read each description and look at items\n"+
           "in the description.  You could also try using your senses, ie:\n"+
           "listening, smelling.  Have fun and I hope you enjoy this area!!\n"+
           "If you have any comments or suggestions, please mail me with them.\n\n"+
       HIW+"            Snakespear the Dark Gentleman\n"+NORM);

return 1;
}
