inherit "obj/monster";
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
  set_chat_chance(8);
  load_chat("A wave rolls up against the beach.\n");
  load_chat("A seagull cries as it flies overhead.\n");
}
