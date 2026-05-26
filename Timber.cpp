// including important libraries here
#include <SFML/Graphics.hpp>

// Make code easier to type with "using namespace" using namespace sf;
using namespace sf;

// this is where the game starts from int main()
int main() {

  // SFML 3 changes remember to add curly brackets for sf::vector2
  VideoMode vm({1920, 1080});

  // Create and open a window for the game
  RenderWindow window(vm, "Timber!!!", State::Fullscreen);

  // Create a texture to hold a graphic on the GPU Texture textureBackground;
  // note change in SMFL3 requires sf::
  sf::Texture textureBackground;

  // Load a graphic into the texture textureBackground.
  // you added the if statement otherwise the compiler gives you a warning
  // without it if the background load it will return std out 1 error
  if (!textureBackground.loadFromFile("graphics/background.png")) {
    return 1;
  }

  // Create a sprite Sprite spriteBackground.  once again different to original
  // code to meet new SFML standards
  sf::Sprite spriteBackground(textureBackground);

  //  Set the SpriteBackground to cover the screen
  spriteBackground.setPosition({0, 0});

  //  Make a tree sprite
  sf::Texture textureTree;

  if (!textureTree.loadFromFile("graphics/tree.png")) {
    return 1;
  }

  sf::Sprite spriteTree(textureTree);
  spriteTree.setPosition({810, 0});

  // Prepare the bee
  sf::Texture textureBee;

  if (!textureBee.loadFromFile("graphics/bee.png")) {
    return 1;
  }

  sf::Sprite spriteBee(textureBee);
  spriteBee.setPosition({0, 800});

  // Is the bee currently moving?
  bool beeActive = false;

  // How fast can the bee fly
  float beeSpeed = 0.0f;

  while (window.isOpen()) {
    /*
     ********************************* Handle the players input**********
     */

    // SFML 3 keyboard handling keys are now found inside sf::Keyboard::Key
    if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
      window.close();
    }

    /*
     * *************** Update the screen **************************
     */

    /*
     * ***************** Draw the scene********************
     * ****************************************************
     */

    // Clear everything from the last frame window.clear();
    window.clear();

    // Draw the scene here
    window.draw(spriteBackground);

    // Show everything we just drew window.display();
    window.display();
  }
  return 0;
}
