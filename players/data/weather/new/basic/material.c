#pragma strong_types

private int    hardness;    // 0..100 (Mohs-scale * 10)
private int    volume;      // volume in ccm
private int    elasticity;  // 0..100 ... BUT MEASURED IN ????
private string material;    // e.g. wood, iron, stone

void set_hardness(int h) {
  if (h <= 100 && h >= 0)
    hardness = h;
}

int query_hardness() { return hardness;}

void set_volume(int v) {
  if (v > 0)
    volume = v;
}

int query_volume() { return volume; }

void set_elasticity(int e) {
  if (e <= 100 && e >= 0)
    elasticity = e;
}

int query_elasticity() { return elasticity; }

void set_material(string m) { material = m; }
string query_material() { return material; }

static string* query_persistent_variables() {
  return ({ "material", "hardness", "volume", "elasticity" });
}

////////////////////////////////////////
// ingredient producer functionality

string *ingredient_production_method;  // list of ING_PROD_*

void set_ingredient_production_method(mixed method) {
  if (stringp(method))
    method = ({ method });
  ingredient_production_method = method;
}

string *query_ingredient_production_method() {
  return ingredient_production_method || ({});
}

status is_ingredient_production_method(string method) {
  return (ingredient_production_method &&
          member(ingredient_production_method, method) >= 0);
}
