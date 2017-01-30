// these are positions that make sense:
// right, left, front, rear, upper, lower, middle, side 
private mapping position;

status has_position(string p) { return position && member(position,p); }
mapping query_position() { return copy(position); }

varargs void add_position(string pos, status explicit) {
  if (!position)
    position = ([]);
  position += ([ pos : explicit ]); 
  if ((pos == "right" || pos == "left") && !has_position("side"))
    add_position("side");
}

void set_position(mapping p) 
{ 
  position = 0;
  walk_mapping(p,#'add_position);
}

string query_position_description() {
  mapping pos;
  string result;

  result = "";
  if (position) {
    // filter all explicit positions
    pos = filter_indices(position,sort_args(#'[),position);
    if (member(pos,"right"))
      result += "right ";
    else if (member(pos,"left"))
      result += "left ";
    if (member(pos,"lower"))
      result += "lower ";
    else if (member(pos,"upper"))
      result += "upper ";
    if (member(pos,"front"))
      result += "front ";
    else if (member(pos,"rear"))
      result += "rear ";
    if (member(pos,"middle"))
      result += "middle ";
  }
  return result;
}

string query_position_state_description(status output) {
  string *result;

  if (output || !position)
    return 0;
  result = ({});
  if (member(position,"right"))
    result += ({"right\\>|\\<not left"});
  else if (member(position,"left"))
    result += ({"left|not right"});
  if (member(position,"side"))
    result += ({"side"});
  if (member(position,"front"))
    result += ({"front\\>|\\<fore(-||\\>)|\\<not rear"});
  if (member(position,"rear"))
    result += ({"rear\\>|\\<hind(-||\\>)|\\<not front"});
  if (member(position,"upper")) {
    result += ({"upper"});
    if (!member(position,"middle"))
      result += ({"not middle"});
    if (!member(position,"lower"))
      result += ({"not lower"});
  } 
  if (member(position,"lower")) {
    result += ({"lower"});
    if (!member(position,"middle"))
      result += ({"not middle"});
    if (!member(position,"upper"))
      result += ({"not upper"});
  } 
  if (member(position,"middle")) {
    result += ({"middle"});
    if (!member(position,"upper"))
      result += ({"not upper"});
    if (!member(position,"lower"))
      result += ({"not lower"});
  }
  return implode(result,"\\>|\\<");
}

string
cut_off_position(string str)
{
  int i;
  string *h;

  h = regexplode(str,"-| ");
  for (i = sizeof(h); i>0; i-=2)
    if (!has_position(h[<i]))
      break;
  return implode(h[<i..],"");
}
