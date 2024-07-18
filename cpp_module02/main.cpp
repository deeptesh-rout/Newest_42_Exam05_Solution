#include "Warlock.hpp"
#include "Fwoosh.hpp"
#include "Dummy.hpp"
#include "BrickWall.hpp"
#include "Polymorph.hpp"
#include "TargetGenerator.hpp"
#include "Fireball.hpp"
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  ATarget* paper = tarGen.createTarget("Paper Target"); // Example of the new test case :
                                                        // A type that wouldn't exist by default
                                                        // but specified.

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);
  richard.launchSpell("Fireball", *paper);  // Since the lauch fucntion can't directly check for NULL
                                            // on a const &, then it must exist, if not there will be
                                            // a segmentation fault.

}
