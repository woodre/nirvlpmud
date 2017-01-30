/* A diamond hair clip, Created <5/12/00> by Jara */

inherit "obj/treasure";

reset(arg)  {
  if(arg) return;

  set_id("clip");
  set_short("A diamond hair clip");
  set_long("The hair clip is made of a gold material, inlaid with precious diamonds.\n");
  set_weight(1);
  set_value(500);
}
