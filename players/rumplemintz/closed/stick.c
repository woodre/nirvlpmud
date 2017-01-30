inherit "obj/treasure";

#define binpath ({"/players/rumplemintz/closed/bin","/players/rumplemintz/tools/bin"})
#define ALLOWED ({"rumplemintz","rumpsen"})
#define USEBIN 1 /* def this to 0 if you just want a stick */
#define SHOWHACK ({"l","exa","examine","la","x"})

init() {
  ::init();
  if (member(ALLOWED, this_player()->query_real_name()) == -1)
    return;
  if(USEBIN)
#ifndef __LDMUD__
    add_action("chk_bin");
  if(USEBIN)
    add_xverb("");
#else
    add_action("chk_bin", "", 3);
#endif
}

query_binpath() { return binpath; }

query_prevent_shadow() { return 1; }

chk_bin(str) {
  string file, verb, firstverb;
  string pre, rest;
  mixed args;
  int i;

  if (sscanf(str, "%s %s", firstverb, args) != 2)
    firstverb = str;
  if (!(str = replacements(str)))
    return 0;

  args = 0;
  if (sscanf(str, "%s %s", verb, args) != 2)
    verb = str;

  for (i=0; i<sizeof(binpath); i++) {
    file = binpath[i] + "/_" + verb;
    if (file_size(file + ".c") > 0) {
      if (file->main(args, firstverb)) /* can ignore verb if desired */
        return 1;
    }
  }
  return 0;
}

replacements(str) {
  string pre, rest, tmp;

  if (!str)
    return 0;
  if (str[0]=='\'')
    return "say " + extract(str,1);
  if (str[0]==':')
    return "emote " + extract(str,1);

  if (sscanf(str, "%s %s", pre, rest) != 2) {
    pre = str;
    rest = "";
  } else
    rest = " " + rest;
  if (pre == ".")
    return "ss" + rest;
  if (pre == "..")
    return "exp" + rest;
  if (pre == "p")
    return "people" + rest;
  if (pre == "l")
    return "look" + rest;
  if (pre == "exa" || pre == "examine")
    return "look at" + rest;
  if (pre == "take")
    return "get" + rest;
  if (pre == "destruct")
    return "dest" + rest;

  /* to avoid bad filenames */
  if (sscanf(pre, "%s.%s", tmp, rest) == 2)
    return 0;

  return str;
}

id(string str) { return str == "stick"; }

short() {
  if (member(ALLOWED, environment()->query_real_name()) == -1)
    return "Dog shit";
  if (this_player()->query_real_name() != "rumplemintz")
    tell_object(environment(this_object()),
                capitalize(this_player()->query_real_name())
                + " just looked at your inventory [" + query_verb() + "]\n");
  if (member(SHOWHACK, query_verb()) == -1)
    return "Rumplemintz's stick";
  return "Rumplemintz's stick.\nA Hacking Tool";
}

long() {
  short();
  write("Rumplemintz's stick.\n");
}

drop() { return 1; }
query_auto_load() { return "/players/rumplemintz/closed/stick:"; }

