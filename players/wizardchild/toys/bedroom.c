string *items;
short() {
  if(environment(this_player()) != this_object())
    return "The home of the big froggy";
  else
    return "A luxurious bedroom";
}
reset(arg) {
  if(arg) return ;
  set_light(1);
  items = ({
    "whirlpool","The warm circulating water looks enticing to you",
    "waterbed","Lined only with silk sheets, this waterbed is easily the largest you have ever\nseen",
    "doorway","The doorway opens to a beautiful stone balcony, overlooking Nirvana",
long() {
  write("You are standing in an elaborately decorated bedroom, much larger than\n");
  write("any you have seen before. In one corner is a whirlpool, quietly\n");
  write("circulating water, while against the far wall is a huge waterbed,\n");
  write("with more than enough space. Near the bed is a glass doorway, leading\n");
  write("to a balcony, with a beautiful view of Nirvana. Near the whirpool is\n");
  write("a wood burning fireplace with a huge opening and marble tiling, with\n");
  write("pictures of what appears to be a happy couple on the mantle.\n");
  write("Besides the fireplace, the room is lit only by the sun shining in from\n");
  write("the outside, casting deep shadows. A comfortable looking sofa sits in front\n");
  write("of the fireplace, with a fur rug between them.\n");
}
init() {
  add_action("look","look",1);
  add_action("leave","leave");
}
