inherit "/players/vertebraker/misc/language/language";

void reset(status x)
{
 if(x) return;
 setDictionaryFreq(100);
 setDictionary(([
  "hello" : "hi",
  "goodbye" : "bye" ]));
}
