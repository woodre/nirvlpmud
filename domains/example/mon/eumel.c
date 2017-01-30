/* Example like cat.c
 * Eumel will react on key and ask whether you want it and will
 * react on your reaction... a chain with four parts
 */

#include <message.h>

inherit "complex/npc";

object offered;

void offered_key() {
  offered = this_player();  // save the player for yes_chat
}

mixed yes_chat() {
  object key;

  if (offered != this_player())
    return ({ ({M_SAYS, "I don't understand, what do you want?" }) });
  if (!present_clone("/domains/example/keys/key_example", this_object()))
    return ({ ({M_SAYS, "Sorry, I do not have the key anymore." }) });
  key = move_object(clone_object("/domains/example/keys/key_example"),
                    this_object());
  if (transfer(key, this_player()))
    move_object(key, environment());
  offered = 0;
  return ({ ({M_ME, " gives a key to ", M_PLAYER, "."}), 1,
            ({M_SAYS, "Of course, have the key." }) });
}

void reset(status arg) {
  ::reset(arg);
  if (!present_clone("/domains/example/keys/key_example", this_object()))
    move_object(clone_object("/domains/example/keys/key_example"),
                this_object());
  if (arg)
    return;
  set_name("eumel");
  set_short("Eumel");
  set_long("Oh, how cute, this is Eumel. It is a nice little creature\n"
           "with soft fur and sharp claws. It look quite peaceful.\n");
  set_id(({"eumel", "creature"}));
  set_level(15);
  set_dex(15);
  set_int(15);
  set_con(15);
  set_str(15);
  set_hp(162);
  set_sp(162);
  set_wc(15);
  set_ac(5);
  set_ep(10000);
  set_aggressive(0);
  set_al(250);
  set_chat_reactions(({
    ({ ({ "key" }),
       ({ ({ M_SAYS, "Oh, yes, I have a key, do you want it?" }), 1,
           ({ M_ME, M_ME_VERB, " look", " questioningly at ", M_PLAYER,
              ".", #'offered_key }) }), ({ "say", "ask_for", "ask_about" }) }),
    ({ ({ "yes", "yeah", "sure", "of course" }), #'yes_chat })
  }));
  set_feeling_reaction(
    ({ "cuddle", "hug", "kiss", "ruffle", "caress", "stroke"}),
    ({ ({ "Eumel smiles thankfully at ", M_PLAYER, "." }) })
  );
  set_feeling_reaction(
    ({ "kick", "slap", "hit", "knee", "strangle" }),
    ({ ({ "Eumel sniffs desperatedly and grrs sadly at ", M_PLAYER, "." }) })
  );
  set_feeling_reaction("nod", #'yes_chat, 1);
}

