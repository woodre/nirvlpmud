string *lyrics;




void reset(status arg) {
  if(arg) return;
  lyrics=
        ({"Night-time sharpens, heightens each sensation ...",
        "Darkness stirs and wakes imagination ...",
        "Silently the senses abandon thier defences ...",
        "Slowly, gently night unfurls its splendour ...",
        "Grasp it, sense it - tremulous and tender ...",
        "Turn your face away from the garish light of day,",
        "Turn your thoughts away from cold, unfeeling light -",
        "And listen to the music of the night ...",
        "Close your eyes and surrender to your darkest dreams!",
        "Purge your thoughts of the life you knew before!",
        "Close your eyes, let your spirit start to soar!",
        "And you'll live as you've never lived before ...",
        "Softly, deftly, music shall surround you ...",
        "Feel it, hear it, closing in around you ...",
        "Open up your mind, let your fantasies unwind,",
        "In this darkness which you know you cannot fight -",
        "The darkness of the music of the night.",
        "Let your mind  start a journey through a strange, new world!",
        "Leave all thoughts of the world you knew before!",
        "Let your soul take you where you long to be!",
        "Only then can you belong to me ...",
        "Floating, falling, sweet intoxication!",
        "Touch me, trust me, savour each sensation!",
        "Let the dream begin, let your darker side give in",
        "To the power of the music that I write -",
        "The power of the music of the night ...",
        "You alone can make my song take flight -",
        "Help me make the music of the night ..."});
}
status id(string str) {
  return str=="mask";
}
string short() {
  return "An ivory white mask";
}
void long() {
  write("A perfect replica of the Phantom of the Opera's mask.  It\n"+
        "radiates a certain power and mystery, as if tapping into the\n"+
        "power of the owner of the original.\n");
}
void init() {
  add_action("cmd_lyrics","lyrics");
}
status cmd_lyrics() {
  tell_room(environment(environment()),
"Haunting organ music begins to drift through the air, seeming to come from\n"+
"all around.  An equally haunting voice begins to sing...\n");
  call_out("sing_lyrics",3,0);
  return 1;
}
void sing_lyrics(int index) {
  if(index >= sizeof(lyrics))
    return;
  tell_room(environment(environment()),lyrics[index]+"\n");
  call_out("sing_lyrics",3,index+1);
}
status get() { return 1; }
