/*-----------------------------------------------------------------------------

This is a configurable sign programmed by Dagobert on August 23, 1993.
It makes use of /complex/item and supports all functions from this object.
It is different from a normal item in some points:

- A sign is not getable (P_NOT_PORTABLE)
- A sign can be read and it has a setable message on it

The following example will show you how to  put it into a room:


object sign;        declare a variable at the start of
                    the function, usually create()
...

sign=clone_object("/complex/sign");
                    Create an instance of the sign. Use
                    the file name of the sign.c file as
                    the argument to clone_object()
sign->set_id(({"sign","my_name"}));
                    Setting a new id is useful if you changed the
                    short description of the item. If this call is
                    ommited the default id() will be just "sign".
sign->set_short("Short text");
                    If you obmit this line the default
                    will be "a sign". Note that there is no \n at the
                    end of the string - shorts do not need them.
sign->set_long("Long description.\n");
                    You can obmit this, too. Default is
                    "This is a sign. Read it!\n". Note the \n at the
                    end of the string.
sign->set_text("Your text.\n"); or
sign->set_text(({({"Your message."})}));
                    Sets the text the player will read.
                    Obmitting this is usually not very
                    sensible. This is the only new function needed to
                    configure the sign, the other functions are
                    inherited from /complex/item.c
move_object(sign,this_object());
                    Move the sign into the room....

------------------------------------------------------------------------*/

// modernized completely by Chameloid, 30-Nov-96

#include <prop/item.h>
#include <message.h>

inherit "basic/cloned";  // Alfe 97-Jan-3
inherit "complex/item";

private mixed text;

public void set_text(mixed msg) {
  text=msg;
}

public mixed query_text() {
  return text;
}

void configure() {
  item::configure();
  cloned();  // Alfe 97-Jan-3
  set_id(({"sign"}));
  set_short("a sign");
  set_long("This is a sign. Read it!\n");
  set_text("Funny, there is nothing written on it.\n");
  set_property(P_NOT_PORTABLE);
}

int apply_action(string type,int level,mapping args) {
  if (type=="read") {
    send_message(({M_PL_THE,M_PL_VERB,"read",M_ME_THE,"."}));
#if 0  // Alfe 97-Jan-3
    message(text=funcall(text));
#else
    message(funcall(text));
#endif
    return 1;
  }
  return item::apply_action(type,level,args);
}

